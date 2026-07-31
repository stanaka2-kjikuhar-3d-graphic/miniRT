# 円錐（cone）の正準形

円錐は [quadric.md](quadric.md) の二次曲面エンジンの上に、正準形 `Q_local` を1つ載せるだけで実装できる。
本ドキュメントでは、その正準形の導出と、ワールド空間への持ち上げ方をまとめる。

## 1. 正準形 x² + y² - k²z² = 0

円錐の頂点をローカル原点に置き、軸をローカル+zに取ると、高さ `z` での断面は半径 `k·z` の円になる。

```
x² + y² = (k·z)²
```

`k` は頂点からの開き具合を表す係数で、底面半径を `r`、頂点から底面までの高さを `h` とすると `k = r/h` になる。
これは頂点の半頂角を `θ` としたときの `tan θ` に等しい（`tan θ = 対辺/隣辺 = r/h`）ため、issueのメモにある通り `k = tan(半頂角)` と一致する。

対称行列で表すと、`A=1, B=1, C=-k², J=0` で、その他の係数は0になる。

```
Q_local = diag(1, 1, -k², 0)
```

`z=0`（頂点）では `x²+y²=0` となり、原点だけを満たす。
`z` が正負どちらに動いても解を持つ（数式上は上下2つの円錐、いわゆる二葉になる）ため、実際に描画する片方の葉（頂点から底面まで）は5節の有限化で切り出す。

## 2. ワールド空間への持ち上げ

`t_cone` は既存のフィールド（`center`＝底面の円の中心、`dir`＝底面中心から頂点への単位ベクトル、`radius`＝底面半径、`height`＝底面から頂点までの距離）をそのまま使う。
`local_to_world` は次のように組む。

- ローカル原点 → ワールド頂点 `apex = center + dir · height`
- ローカル+z → ワールド `-dir`（頂点から底面へ向かう方向。`z` が増えるほど円錐が広がるため、頂点から離れる向きに一致させる）
- ローカルx, y → 既存の `onb.u`, `onb.v`（`dir` に直交する正規直交基底。`create_cone` で `calc_onb` により構築済み）

このとき **スケールは不要**である。
`k` は既にワールド座標の `radius/height` そのものを使って求めているため、`local_to_world` を回転と平行移動だけの剛体変換にしても、ローカル距離とワールド距離が一致する。
[matrix.md](matrix.md) の `mat4_basis` で基底と原点から行列を組み、[quadric.md](quadric.md) の `quadric_to_world` で `Q_world = M⁻ᵀQ_local M⁻¹` を求める。

## 3. 交差と法線

`calc_cone_intersection` / `calc_cone_normal` は、`t_cone` から上記の `Q_world` を含む `t_quadric` を組み立て、汎用エンジンの `calc_quadric_intersection` / `calc_quadric_normal` にそのまま委譲する。
円錐固有の交差式や法線式は持たない。

## 4. UV座標

側面のUVは円柱と同じ方式を使う。
`u` は軸まわりの角度、`v` は頂点からの軸方向距離を高さで正規化した値である。

```
u = (atan2(radial·onb.v, radial·onb.u) + π) / (2π)
v = h / height   (h = dot(point - center, dir))
```

底面の円は既存の `OBJ_CIRCLE` を別オブジェクトとして重ねる方式（`add_lower_cap_circle`）をそのまま使う。

## 5. 有限化

円錐は本来無限に伸びる二葉の曲面なので、片方の葉だけを軸方向でクランプして切り出す。

```
axis   = -dir   （頂点→底面の向き。2節のローカル+zと同じ）
center = apex   （頂点）
h_min  = 0      （頂点そのもの）
h_max  = height （底面の高さまで）
```

---
参考: [quadric.md](quadric.md)（二次曲面エンジン全体）、[matrix.md](matrix.md)（`mat4_basis` によるローカル→ワールド変換）
