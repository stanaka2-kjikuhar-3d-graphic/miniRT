# 正準ローカル空間での交差判定

形状ごとに world 空間の判定を持つ代わりに、レイのほうを形状の正準形が住む空間へ引き込んで解く。
`calc_primitive_intersection` がその入口であり、`t_primitive` が持つ `to_local` 1本で世界を切り替える。

本ドキュメントでは、この変換で `t` がどう保たれるか、そして方向ベクトルを単位長に直さなければならない理由をまとめる。

## 1. レイをローカル空間に引き込む

`to_local`（[matrix.md](matrix.md) の `mat4_world_to_local`）はアフィン変換である。
アフィン変換は直線を直線に、パラメータ `t` の等分点を等分点に写す。

```
M⁻¹(o + t・d) = M⁻¹o + t・M⁻¹d
```

つまり world 空間の `t` と、ローカル空間で同じ点を指す `t` は同一である。
交差判定をローカルで済ませても、返す `t` を換算し直す必要はない。

```c
local.origin = mat4_transform_point(to_local, ray->origin);
local.dir    = mat4_transform_dir(to_local, ray->dir);
```

`mat4_transform_dir` は方向を平行移動の影響から外すだけで、長さは正規化しない。
`M⁻¹` にスケール成分が入っている以上、`|d_local|` は 1 にならない。

## 2. なぜ方向ベクトルを単位長に直すのか

上の等式は `d_local` の長さに関係なく成り立つ。
それでも実装では単位長に直す。
理由は数学ではなく、`solve_quadratic` の縮退判定にある。

`to_local` は方向ベクトルを `1 / scale` で縮める。
正準形の `Q`（[quadric.md](quadric.md)、`unit_quadric`）は成分が `{0, ±1, ±1/2}` の定数行列なので、二次の係数はスケールの2乗で小さくなる。

```
a = d_localᵀ Q d_local  ≒  1 / scale²
```

一方、`solve_quadratic` が「二次ではなく一次だ」と判断する閾値は絶対値である。

```c
if (fabsf(a) < EPSILON)          /* EPSILON = 1e-6 */
	return (solve_linear(b, c, roots));
```

この2つを突き合わせると、破綻する形状の大きさが決まる。

```
1 / scale² < 1e-6   ⟺   scale > 1000
```

半径 1000 を超えた形状では、本来2つの根を持つ二次方程式が直線として解かれる。
根が1本しか出ないので、当たるべき面をすり抜けたり、裏側の面に当たったりする。

実測でもこの境界どおりに壊れた。

| 形状の大きさ | `a` の目安 | 旧実装との一致 |
| --- | --- | --- |
| 100 | `1e-4` | 一致するが、`t` の相対誤差が `5e-2` まで悪化する |
| 1000 | `1e-6` | 閾値をまたぎ、当たり外れの食い違いが出はじめる |
| 10000 | `1e-8` | 大きく食い違う |

対処は、ローカルの方向ベクトルを単位長に直し、パラメータを置き換えることである。

```
d̂ = d_local / |d_local|
s = t・|d_local|
```

`|d̂| = 1` なので `a` は形状の大きさに依存しなくなり、`fabsf(a) < EPSILON` は本来の意味だけを拾う。
たとえばレイが円柱の軸と平行なとき、`a` は形状の大きさによらず 0 になる。
求めた `s` は最後に `|d_local|` で割れば world の `t` に戻る。

```c
len = vec3_length(local.dir);
local.dir = vec3_div(len, local.dir);
return (solve_unit_form(prim, &local) / len);
```

`len` が `EPSILON` を下回る入力は弾く。
`mat4_is_valid_scale` がスケールの下限しか見ていないため、大きさが `1e6` を超える形状ではここに落ちる。

## 3. plane と disc を正規化しない理由

`UNIT_PLANE` と `UNIT_DISC` は正規化せず、`calc_planar_intersection` にそのまま渡す。

この2つのスケールは `(s, s, 1)` であり、z 成分を触らない。
したがって `d_local.z` は `d_world.z` そのもの、すなわち法線と方向の内積に等しい。

```c
if (fabsf(local->dir.z) < EPSILON)
	return (NAN);
```

この比較は、world 空間で判定していた頃の `fabsf(vec3_dot(plane->normal, ray->dir)) < EPSILON` と同じ量を見ている。
ここで正規化すると、`|d_local|` に `pattern_size` が混ざり、平行とみなす角度が模様の大きさで変わってしまう。

そもそも平面と円盤は一次方程式なので、2節の縮退問題は起きない。

## 4. キャップ判定が1回の比較になる理由

どの正準形も、切り出しの範囲は z 軸方向だけで表せる（[quadric.md](quadric.md) の `h_min` と `h_max` に相当する）。
world 空間では軸との内積を取る必要があったが、ローカルでは z 成分がそのまま高さである。

```c
z = local->origin.z + t * local->dir.z;
return (prim->z_range.min <= z && z <= prim->z_range.max);
```

`z_range` の値は型ごとにほぼ定数で、球は `[-1, 1]`、円錐と放物面は `[0, 1]`、円柱は `[-1, 1]` になる。
一葉双曲面だけはオブジェクトごとに変わる。
くびれの半径と端の半径の比で正準形での上限が決まってしまい、`±1` に正規化する自由度が残らないからである（[hyperboloid.md](hyperboloid.md)）。

## 5. 旧実装が持っていた弱点

同じ `solve_quadratic` を使いながら、world 空間の旧実装が大きさに強かったのは、形状によって事情が違ったためである。

- **球と円柱と平面と円盤**：幾何的に解いており、`solve_quadratic` を通らない
- **円錐**：`Q_world` が `diag(1, 1, -k², 0)` の同次式で、半径が係数に入らない
- **放物面**：`Q_world` の `x² + y²` 部の係数が 1 である
- **一葉双曲面**：`Q_world` が `diag(1/r², 1/r², -1/c², -1)` であり、半径が係数に入る

最後の一葉双曲面は、ローカル空間へ移す前から同じ閾値問題を抱えていた。
`center_radius` が 1000 を超える双曲面では、旧実装のほうが誤った交差を返す。
2節の正規化を入れた新しい経路は、この場合も正しい根を返す。

---
参考: [matrix.md](matrix.md)（`to_local` と `to_world` の組み方）、[quadric.md](quadric.md)（二次曲面エンジン）、[hyperboloid.md](hyperboloid.md)（`z_range` が定数にならない理由）
