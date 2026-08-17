# 放物面（paraboloid）の正準形

> **この文書は旧実装（`t_quadric` エンジン）を前提に書かれている。**
> 現在は形状を正準形と4x4行列で持ち、交差・法線・UV・接空間はすべて正準ローカル空間で解いている。
> 実装は [primitive_intersection.md](primitive_intersection.md)、[primitive_normal.md](primitive_normal.md)、[primitive_uv.md](primitive_uv.md)、[primitive_tbn.md](primitive_tbn.md) を参照。
> 正準形そのものの導出は今も有効だが、「スケールは不要」など持ち上げ方に関する記述はすでに当てはまらない。

放物面も [quadric.md](quadric.md) の二次曲面エンジンに、正準形 `Q_local` を1つ載せるだけで実装できる。
円錐（[cone.md](cone.md)）・双曲面（[hyperboloid.md](hyperboloid.md)）と異なり、放物面の正準形は**線形項**を持つ点が特徴である。

## 1. 正準形 x² + y² - a・z = 0

放物面は頂点をローカル原点に置き、軸をローカル+zに取ると、次の式で表せる。

```
x² + y² = a・z
```

円錐（`x²+y²=k²z²`、`z`の2乗）や双曲面（`x²/r²+y²/r²-z²/c²=1`）と違い、`z` の項が1次であることが放物面の特徴である。
`a` は開き係数で、大きいほど同じ高さでの断面が広くなる。

一般の二次曲面の式 `Ax²+By²+Cz²+2Dxy+2Exz+2Fyz+2Gx+2Hy+2Iz+J=0` と見比べると、`A=1, B=1`、線形項 `-a・z` は `2I・z` に対応するので `I=-a/2`、それ以外の係数はすべて0になる。

対称行列で表すと、`z` の行・列と `w` の行・列が交差する成分（[quadric.md](quadric.md) の `G, H, I` にあたる位置）だけに値が入る。

```
Q_local = | 1  0  0    0   |
          | 0  1  0    0   |
          | 0  0  0   -a/2 |
          | 0  0 -a/2  0   |
```

`z` の対角成分（`C`）も定数項（`J`）も0であることが、円錐・双曲面との違いである。
`z=0`（頂点）では `x²+y²=0` となり、原点だけを満たす。

## 2. パラメータ a はそのまま使える

円錐の `k`（`radius/height` から算出）や双曲面の `c`（`center_radius`・`cap_radius`・`half_height` から逆算）と異なり、放物面の `a` はユーザ入力の `quadratic_coefficient` をそのまま使う。
ユーザが直接「開き係数」を指定する仕様（[cone.md](cone.md) 2節、[hyperboloid.md](hyperboloid.md) 2節のような半径からの逆算は不要）だからである。

## 3. ワールド空間への持ち上げ

`local_to_world` は次のように組む。

- ローカル原点 → ワールド `center`（頂点）
- ローカル+z → ワールド `dir`（軸方向。issueのメモにある「開く向き」がそのままローカル+zに対応するため、円錐のような符号反転は不要）
- ローカルx, y → 既存の `onb.u`, `onb.v`

円錐・双曲面と同様に**スケールは不要**である。
`a` は既にワールド座標の値なので、`local_to_world` を回転と平行移動だけの剛体変換にしても、ローカル距離とワールド距離が一致する。

## 4. 交差・法線・有限化

`calc_paraboloid_intersection` / `calc_paraboloid_normal` は、`paraboloid_to_quadric` で組み立てた `t_quadric` を汎用エンジンにそのまま渡す。

```
axis   = dir
center = center   （頂点）
h_min  = 0
h_max  = height
```

放物面は頂点から片方向にしか伸びない曲面（`z<0` 側は数式上も解を持たない）なので、円錐のような「二葉のどちらを選ぶか」という問題は起きない。
`h_max` は単純に軸方向の切り出し高さを決めるだけである。

## 5. UV座標

側面のUVは円錐・双曲面（[cone.md](cone.md) 4節, [hyperboloid.md](hyperboloid.md) 5節）と同じ `calc_quadric_uv` に委譲する。
`h_min = 0`（頂点）, `h_max = height` なので、`v = (h - h_min) / (h_max - h_min) = h / height` になる。

```
h = dot(point - center, dir)
u = (atan2(radial・onb.v, radial・onb.u) + π) / (2π)
v = h / height
```

`u_per_v`（テクスチャのアスペクト比）には、頂点から離れた開口部（`z=height`）での半径 `√(a・height)` を代表値として使う。
放物面の母線は円錐と違って直線ではない（弧長を厳密に求めるには楕円積分が必要）ため、他形状と同じくあくまで簡易的な近似である。

放物面には現状キャップ（円柱・円錐・双曲面のような端の円）を追加していない。

---
参考: [quadric.md](quadric.md)（二次曲面エンジン全体）、[cone.md](cone.md) / [hyperboloid.md](hyperboloid.md)（同じ手法を使う別形状の例）
