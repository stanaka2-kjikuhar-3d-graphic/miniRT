# 汎用二次曲面（Quadric）エンジン

球、円柱、円錐、双曲面、放物面はすべて `pᵀQp = 0` という1つの形で表せる。
個別の交差判定の式を形状ごとに書く代わりに、対称行列 `Q` 1つに形、向き、位置、スケールを畳み込み、交差と法線を `Q` だけから導く。
この仕組みを**二次曲面エンジン**と呼んでいる。`t_quadric`（`include/scene/object.h`）と実装（`src/scene/object/quadric/`）がこれにあたる。

## 1. pᵀQp = 0 という表現

一般の二次曲面は次の10項の式で書ける。

```
Ax² + By² + Cz² + 2Dxy + 2Exz + 2Fyz + 2Gx + 2Hy + 2Iz + J = 0
```

点を**同次座標** `p = (x, y, z, 1)` にすると、この10個の係数を対称行列 `Q` にまとめて `pᵀQp = 0` の形にできる。

```
      | A  D  E  G |
Q  =  | D  B  F  H |     左上3x3：形、向き、スケール
      | E  F  C  I |     G, H, I：位置、J：定数
      | G  H  I  J |
```

`w = 1` を使う理由は [matrix.md](matrix.md) の「なぜ w で区別するか」と同じである。
`G, H, I`（位置の一次項）と `J`（定数項）は `w` を通じてのみ効くため、点と方向を `w` で区別しないと位置やスケールが正しく反映されない。

## 2. レイとの交差

レイ `p(t) = o + t·d` を `pᵀQp = 0` に代入する。

```
(o + td)ᵀQ(o + td) = 0
= oᵀQo + t·oᵀQd + t·dᵀQo + t²·dᵀQd = 0
```

`Q` は対称行列なので `oᵀQd = dᵀQo` が成り立つ（スカラーは転置をとっても変化しないので、`Qᵀ=Q`。これより、 `(oᵀQd)ᵀ = dᵀQᵀo = dᵀQo` が導ける）。
したがって2つの成分が1つにまとまり、`t` についての2次方程式になる。

```
a·t² + b·t + c = 0
a = dᵀQd   (d は方向。w=0 なので G, H, I, J は効かない)
b = 2·oᵀQd
c = oᵀQo   (o は点。w=1 なので位置・定数項が効く)
```

この方程式は `solve_quadratic` で解く。
`a ≈ 0` は、レイの方向 `d` と並行になるケースで、式が1次方程式 `b·t + c = 0` で計算したほうが精度が良い。
放物面の軸に平行なレイや、円錐・双曲面の母線に沿うレイがこれにあたる。
この分岐がないと、0除算になるか、本来交差するはずのレイを取りこぼす。

得られた解のうち、`t ≥ 0` かつ有限化の範囲内（5節）にある最小の `t` を交点として使用する。

## 3. 法線

曲面 `F(x,y,z) = pᵀQp` の勾配 `∇F` が法線方向になる。
`Q` が対称であることから、各偏微分は次のように書ける。

```
∂F/∂x = 2(Ax + Dy + Ez + G)
∂F/∂y = 2(Dx + By + Fz + H)
∂F/∂z = 2(Ex + Fy + Cz + I)
```

これは `Q·p` の先頭3成分（4行目、つまり `w` 行を除いたもの）そのものである。
定数倍（2倍）は正規化で消えるため、実装では `Q·p` の xyz を取り出して正規化するだけでよい。

```c
∇ = Q · p   // 先頭3成分を正規化
```

法線は、交差計算に使ったレイ方向を見て常にレイに向くよう符号を反転する（他オブジェクトと同じ規約）。

## 4. ワールド空間への変換

`Q` はローカル空間（標準形、たとえば原点中心、軸はz軸、半径1）で定義し、`local_to_world` 行列 `M`（[matrix.md](matrix.md) の `mat4_basis` などで組む）を使ってワールド空間に座標変換する。

ワールド点 `p_w` とローカル点 `p_l` の関係は `p_w = M·p_l`、つまり `p_l = M⁻¹·p_w` である。
これをローカルの式に代入する。

```
p_lᵀ Q_local p_l = 0
(M⁻¹p_w)ᵀ Q_local (M⁻¹p_w) = 0
p_wᵀ (M⁻ᵀ Q_local M⁻¹) p_w = 0
```

よって `Q_world = M⁻ᵀ · Q_local · M⁻¹` が成り立つ。
回転のみであれば `M⁻ᵀ = M` になる（直交行列の逆は転置に等しい）が、位置やスケールが混ざると一致しないため、一般の逆行列と転置が必要になる（[matrix.md](matrix.md) の `mat4_inverse` の注記と同じ理由）。

`Q_world` には向き（ONB）、位置、スケールが全て含まれる。
そのため、交差（`a=dᵀQd, b=2oᵀQd, c=oᵀQo`）と法線（`∇=Q·p`）は `t_quadric.q`（ワールド空間の `Q`）だけで完結し、`t_quadric` は別途 ONB を持たない。

## 5. 有限化（軸方向で有限化）

`Q` が表すのは無限に伸びる曲面である（円柱、円錐、双曲面、放物面は本来無限に広がる）。
どこで切るかは `Q` の情報だけでは決まらないため、`t_quadric` に別途持たせる。

```c
t_vec3	axis;    // 有限化用の軸（world）。ONB の w（local +z の world 像）に相当
t_vec3	center;  // 有限化の基準点（world）
float	h_min;   // dot(p-center, axis) の下限
float	h_max;   // 上限
bool	finite;  // 軸方向クランプの有無
```

`quadric_in_bounds` は、交点を軸に投影した高さ `h = dot(point - center, axis)` を求め、`h_min ≤ h ≤ h_max` かどうかを返す。
`finite = false` のときは常に `true` を返す。
これは円柱の `check_cylinder_height` と同じ役割を、汎用二次曲面向けに切り出したものである。

キャップ（円柱の上下の円など）は `Q` の範囲外にある平面なので、`OBJ_CIRCLE` を別オブジェクトとして重ねる既存の方式をそのまま使う。

## 6. UV座標（円筒投影）

有限化に使う `axis`/`center`/`h_min`/`h_max` は、側面のUV座標を求める材料としてもそのまま使い回せる。
円錐・双曲面・放物面（[cone.md](cone.md), [hyperboloid.md](hyperboloid.md), [paraboloid.md](paraboloid.md)）はいずれも「軸まわりの角度が `u`、軸方向の位置が `v`」という同じ円筒投影の考え方でUVを求めるため、`calc_quadric_uv` に1つにまとめてある。

```c
t_vec2	calc_quadric_uv(t_quadric const *q, t_onb const *onb, t_vec3 point);
```

```
h      = dot(point - center, axis)
radial = normalize((point - center) - h・axis)   // 軸に垂直な半径方向
u      = (atan2(radial・onb->v, radial・onb->u) + π) / (2π)
v      = (h - h_min) / (h_max - h_min)
```

`t_quadric` 自体は ONB（`onb.u`, `onb.v`）を持たない（4節参照）ため、`onb` は呼び出し側（各形状の `t_cone`/`t_hyperboloid`/`t_paraboloid` が持つ ONB）から別引数で渡す。
`v` の正規化は `h_min`/`h_max` を使うため、`finite = false`（無限）な `Q` には使えない。
ただし現状の `.rt` パーサは全形状で高さ・半径系のフィールドを必須にしており、無限のまま二次曲面を定義する構文が存在しないため、実用上この制約は問題にならない。

## 例: sphere / cylinder の Q

単位形状（ローカル空間）の `Q_local` は次の通りである。
実際のスケール、位置、向きは `local_to_world` 側（`mat4_scale`, `mat4_basis` など）で与え、`quadric_to_world` でQを計算する。

**球**（半径1、原点中心）: `x² + y² + z² - 1 = 0`

```
Q_local = diag(1, 1, 1, -1)
```

**円柱**（半径1、軸はローカルz、無限長）: `x² + y² - 1 = 0`

```
Q_local = diag(1, 1, 0, -1)
```

円柱は z 項を持たないため、`C = 0` になる。
有限長にするには `t_quadric.finite = true` とし、`axis` にローカル+zのワールド像、`h_min`/`h_max` に `±half_height` を設定して、`quadric_in_bounds` で軸方向をクランプする。

---
参考: [matrix.md](matrix.md)（`t_mat4` と同次座標 `w` の区別）、[onb.md](onb.md)
