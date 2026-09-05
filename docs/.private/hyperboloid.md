# 一葉双曲面（hyperboloid）の正準形

> **この文書は旧実装（`t_quadric` エンジン）を前提に書かれている。**
> 現在は形状を正準形と4x4行列で持ち、交差・法線・UV・接空間はすべて正準ローカル空間で解いている。
> 実装は [primitive_intersection.md](primitive_intersection.md)、[primitive_normal.md](primitive_normal.md)、[primitive_uv.md](primitive_uv.md)、[primitive_tbn.md](primitive_tbn.md) を参照。
> 正準形そのものの導出は今も有効だが、「スケールは不要」など持ち上げ方に関する記述はすでに当てはまらない。

一葉双曲面も [quadric.md](quadric.md) の二次曲面エンジンに、正準形 `Q_local` を1つ載せるだけで実装できる。
本ドキュメントでは、円錐（[cone.md](cone.md)）との違いを中心に、正準形の導出とパラメータの決め方をまとめる。

## 1. 正準形 x²/a² + y²/b² - z²/c² - 1 = 0

一般の一葉双曲面は3つの半軸 `a, b, c` を持つが、本実装では回転体（断面が真円）に限定し、`a = b = r` とする。

```
x²/r² + y²/r² - z²/c² - 1 = 0
```

円錐との違いは定数項 `-1` を持つ点である。
円錐は頂点（原点）を通る同次な曲面だったが、双曲面は `z=0` でも `x²+y²=r²` という半径 `r` の円になり、原点を通らない。
このくびれの断面を**中心（waist）**と呼ぶ。

対称行列で表すと次のようになる。

```
Q_local = diag(1/r², 1/r², -1/c², -1)
```

## 2. パラメータ r, c の決め方

`t_hyperboloid` は `center_radius`（くびれの半径 `r`）と `cap_radius`（軸方向 `±half_height` での半径 `R`）をユーザ入力から直接受け取る。
`c` はこの2つの半径から逆算する必要がある。

正準形に `z = half_height` を代入すると、その高さでの半径が求まる。

```
R² = r²(1 + half_height²/c²)
```

これを `c` について解くと次のようになる。

```
c = half_height・r / √(R² - r²)
```

`R > r` でなければ `c` が実数にならない（一葉双曲面はくびれから離れるほど太る形なので、この制約は幾何的に妥当である）。
`R = r` は円柱、`R < r` は不正な形状になるため、パーサ側で `R > r` をエラーチェック済みである（`ERROR_HB_RADIUS`）。

## 3. ワールド空間への持ち上げ

`local_to_world` は次のように組む。

- ローカル原点 → ワールド `center`（くびれの中心）
- ローカル+z → ワールド `dir`（軸方向。円錐と異なり、この曲面は `z=0` を境に対称なので、円錐のような符号反転は不要）
- ローカルx, y → 既存の `onb.u`, `onb.v`

円錐と同様に**スケールは不要**である。
`r`, `c` は既にワールド座標の値を使って求めているため、`local_to_world` を回転と平行移動だけの剛体変換にしても、ローカル距離とワールド距離が一致する。
[matrix.md](matrix.md) の `mat4_basis` で基底と原点から行列を組み、`quadric_to_world` で `Q_world` を求める。

## 4. 交差・法線・有限化

`calc_hyperboloid_intersection` / `calc_hyperboloid_normal` は、`hyperboloid_to_quadric` で組み立てた `t_quadric` を汎用エンジンにそのまま渡す。

```
axis   = dir
center = center
h_min  = -half_height
h_max  = +half_height
```

一葉双曲面は本来 `z` 方向に無限に広がる連続した1枚の曲面なので、円錐のように「二葉のどちらを選ぶか」という問題はない。
`h_min`/`h_max` は単に軸方向の切り出し範囲を決めるだけである。

## 5. UV座標

側面のUVは円錐・放物面（[cone.md](cone.md) 4節）と同じ `calc_quadric_uv` に委譲するが、`v` の向きだけ `calc_hyperboloid_uv` 側で反転させている。

`calc_quadric_uv` 自体の `v = (h - h_min) / (h_max - h_min)` は `h_min = -half_height` のとき下端（`z=-half_height`）で0、上端（`z=+half_height`）で1になる。
しかし双曲面は円柱（`calc_cylinder_uv`）と同じく2枚のキャップ（`add_cap_circle`）を持ち、その `v_range` 割り当ては「上端で`v=0`、下端で`v=1`」という向き（円柱の `v = 0.5 - h/(2・half_height)` と同じ向き）を前提に組まれている。
`calc_quadric_uv` は円錐・放物面と共有しているため向きを変えられず、`calc_hyperboloid_uv` の戻り値だけを反転してこの前提に合わせている。

```
h = dot(point - center, dir)
u = (atan2(radial・onb.v, radial・onb.u) + π) / (2π)
v = 1 - (h + half_height) / (2・half_height)   # = 0.5 - h/(2・half_height) と等価
```

`u_per_v`（テクスチャのアスペクト比）には、半径が軸方向で変化するため `cap_radius`（軸の両端での半径）を代表値として使う。

上下の端（`z = ±half_height`）の円は、既存の `OBJ_CIRCLE` を2枚重ねる方式（`add_cap_circle`）でそのまま対応する。
向きを反転せずに `v_range` 側だけを組み替えて継ぎ目を合わせることもできるが、その場合キャップの中心が指す極（北極/南極）が上下で入れ替わってしまうため、`v` そのものを反転する方式にしている。

---
参考: [quadric.md](quadric.md)（二次曲面エンジン全体）、[cone.md](cone.md)（同じ手法を使う別形状の例）
