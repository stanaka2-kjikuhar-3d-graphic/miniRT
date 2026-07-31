# 汎用二次曲面（Quadric）エンジン

球・円柱・円錐・双曲面・放物面はすべて `pᵀQp = 0` という1つの形で表せる。
個別の交差式を形状ごとに書く代わりに、対称行列 `Q` 1つに形・向き・位置・スケール
を畳み込み、交差・法線を `Q` だけから導く。`t_quadric`（`include/scene/object.h`）
と実装（`src/scene/object/quadric/`）がこのエンジンにあたる。

## 1. pᵀQp = 0 という表現

一般の二次曲面は次の10項の式で書ける。

```
Ax² + By² + Cz² + 2Dxy + 2Exz + 2Fyz + 2Gx + 2Hy + 2Iz + J = 0
```

点を同次座標 `p = (x, y, z, 1)` にすると、係数を対称行列 `Q` にまとめて
`pᵀQp = 0` の形にできる。

```
      | A  D  E  G |
Q  =  | D  B  F  H |     左上3x3 = 形・向き・スケール
      | E  F  C  I |     G,H,I = 位置、J = 定数
      | G  H  I  J |
```

`w = 1` を使う理由は [matrix.md](matrix.md) の「なぜ w で区別するか」と同じで、
`G,H,I`（位置の一次項）と `J`（定数項）は `w` を通じてのみ効く。

## 2. レイとの交差

レイ `p(t) = o + t·d` を `pᵀQp = 0` に代入する。

```
(o + td)ᵀQ(o + td) = 0
= oᵀQo + t·oᵀQd + t·dᵀQo + t²·dᵀQd = 0
```

`Q` は対称行列なので `oᵀQd = dᵀQo`（スカラーの転置は自分自身、`Qᵀ=Q` なので
`(oᵀQd)ᵀ = dᵀQᵀo = dᵀQo`）。よって交差クロス項が1つにまとまり、`t` の2次方程式になる。

```
a·t² + b·t + c = 0
a = dᵀQd   (d は方向。w=0 なので G,H,I,J は効かない)
b = 2·oᵀQd
c = oᵀQo   (o は点。w=1 なので位置・定数項が効く)
```

`solve_quadratic` で解く。`a ≈ 0` はレイの方向 `d` が二次形式の零方向（漸近錐の
母線と平行）にあたるケースで、式が1次 `b·t + c = 0` に縮退する。放物面の軸に
平行なレイや、円錐・双曲面の母線に沿うレイがこれにあたる。線形分岐がないと
0除算または偽陰性になる。

得られた解のうち `t ≥ 0` かつ有限化の範囲内（3節）にある最小の `t` を交点として
採用する。

## 3. 法線

曲面 `F(x,y,z) = pᵀQp` の勾配 `∇F` が法線方向になる。`Q` が対称であることから

```
∂F/∂x = 2(Ax + Dy + Ez + G)
∂F/∂y = 2(Dx + By + Fz + H)
∂F/∂z = 2(Ex + Fy + Cz + I)
```

これは `Q·p` の先頭3成分（4行目 = w 行を除く）そのものである。定数倍（2倍）は
正規化で消えるので、実装では `Q·p` の xyz を取り出して正規化するだけでよい。

```c
∇ = Q · p   // 先頭3成分を正規化
```

法線は交差計算に使ったレイ方向を見て、常にレイに向くよう符号を反転する
（他オブジェクトと同じ規約）。

## 4. ワールド空間への変換

`Q` はローカル空間（標準形、例: 原点中心・軸=z軸・半径1）で定義し、
`local_to_world` 行列 `M`（[matrix.md](matrix.md) の `mat4_basis` 等で組む）を
使ってワールド空間に持ち上げる。

ワールド点 `p_w` とローカル点 `p_l` の関係は `p_w = M·p_l`、つまり
`p_l = M⁻¹·p_w`。これをローカルの式に代入する。

```
p_lᵀ Q_local p_l = 0
(M⁻¹p_w)ᵀ Q_local (M⁻¹p_w) = 0
p_wᵀ (M⁻ᵀ Q_local M⁻¹) p_w = 0
```

よって `Q_world = M⁻ᵀ · Q_local · M⁻¹`。回転のみなら `M⁻ᵀ = M`（直交行列の逆は
転置）だが、位置やスケールが混ざると一致しないため、一般の逆行列・転置が必要
（[matrix.md](matrix.md) の `mat4_inverse` の注記と同じ理由）。

`Q_world` に向き（ONB）・位置・スケールがすべて畳み込まれるため、交差
（`a=dᵀQd, b=2oᵀQd, c=oᵀQo`）と法線（`∇=Q·p`）は `t_quadric.q`（ワールド空間の
`Q`）だけで完結し、`t_quadric` は別途 ONB を持たない。

## 5. 有限化（軸方向クランプ）

`Q` が表すのは無限に伸びる曲面（円柱・円錐・双曲面・放物面は本来無限）。
どこで切るかは `Q` の情報だけでは決まらないので、`t_quadric` に別途持たせる。

```c
t_vec3	axis;    // 有限化用の軸（world）。ONB の w（local +z の world 像）に相当
t_vec3	center;  // 有限化の基準点（world）
float	h_min;   // dot(p-center, axis) の下限
float	h_max;   // 上限
bool	finite;  // 軸方向クランプの有無
```

`quadric_in_bounds` は交点を軸に投影した高さ `h = dot(point - center, axis)` を
求め、`h_min ≤ h ≤ h_max` かどうかを返す。`finite = false` なら常に `true`
（円柱の `check_cylinder_height` と同じ役割を、汎用二次曲面向けに切り出したもの）。

キャップ（円柱の上下の円など）は `Q` の範囲外なので、平面（`OBJ_CIRCLE`）を
別オブジェクトとして重ねる既存の方式をそのまま使う。

## 付録: sphere / cylinder の Q

単位形状（ローカル空間）の `Q_local` は次の通り。実際のスケール・位置・向きは
`local_to_world` 側（`mat4_scale`, `mat4_basis` 等）で与え、`quadric_to_world`
で畳み込む。

**球**（半径1、原点中心）: `x² + y² + z² - 1 = 0`

```
Q_local = diag(1, 1, 1, -1)
```

**円柱**（半径1、軸 = ローカル z、無限長）: `x² + y² - 1 = 0`

```
Q_local = diag(1, 1, 0, -1)
```

円柱は z 項がないため `C = 0`。有限長にするには `t_quadric.finite = true` と
`axis = ローカル+zのworld像`, `h_min/h_max = ±half_height` を設定し、
`quadric_in_bounds` で軸方向をクランプする。

---
参考: [matrix.md](matrix.md)（`t_mat4` / 同次座標 w の区別）, [onb.md](onb.md)
