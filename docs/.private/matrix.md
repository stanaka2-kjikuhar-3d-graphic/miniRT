# 行列と同次座標

回転・平行移動・スケールを 4x4 行列 `t_mat4`（float, 行優先 `m[row][col]`）に集約し、
点・方向を同次座標 `t_vec4` で一括変換する。前半で行列演算とビルダを、後半で `t_vec4`
の「点」と「方向」の区別を扱う。

## 行列型

```c
typedef struct s_mat3            // 法線・接空間用の上位3x3
{
	union
	{
		float	m[3][3];         // 行優先の成分アクセス
		t_vec3	row[3];          // 行を1本のベクトルとして扱う
	};
}	t_mat3;

typedef struct s_mat4            // アフィン変換
{
	union
	{
		float	m[4][4];
		t_vec4	row[4];
	};
}	t_mat4;
```
`M · v` は列ベクトル規約で計算する（`mat4_mul_vec4`）。

### 行は連続、列は非連続

`row[i]` は `m[i]` と同じメモリを指すので、行と v の内積は `vec3_dot(m->row[i], v)` と
書ける（`mat3_mul_vec3`, `mat4_mul_vec4`）。一方、列はストライド付きの並びなので union
では名指しできない。列を組む・読む関数は `m[][]` を手書きする（`mat3_from_columns`,
`mat3_mul_transposed`, `calc_onb`）。

この重なりは `static_assert` で固定している。`sizeof(float[3][3]) == sizeof(t_vec3[3])`
が `t_vec3` にパディングの無いことを保証し（＝`row[i]` と `m[i]` の先頭が一致する）、
成分ごとの `row[i].x == m[i][0]` は `vector.h` 側の `offsetof` の static_assert が担保する。

### 基底ベクトルは列に入る

`t_mat3` を正規直交基底（ONB）として使うとき、u/v/w 軸はそれぞれ 0/1/2 列目にある。

```
              U列   V列   W列
           +-------------------+
    row[0] |  u.x   v.x   w.x  |
    row[1] |  u.y   v.y   w.y  |
    row[2] |  u.z   v.z   w.z  |
           +-------------------+

    local -> world :  M · p
    world -> local :  transpose(M) · p   （正規直交基底に限る）
```

## 基本演算

| 関数 | 内容 |
|------|------|
| `mat4_identity()` | 単位行列 |
| `mat4_mul(a, b)` | 積 `a · b`（`result[row][col] = Σ_k a[row][k]·b[k][col]`） |
| `mat4_transpose(m)` | 転置 |
| `mat4_inverse(m)` | 一般の逆行列（余因子＝随伴行列法）。非一様スケールにも対応 |
| `mat3_from_mat4(m)` | 上位3x3（線形部）を取り出す |

`mat4_inverse` は `inv[col][row] = cofactor(row, col) / det(m)`（随伴行列 ÷ 行列式）で求める。
回転のみなら転置が逆になるが、非一様スケールが混ざると転置は逆行列にならないため、一般の
逆行列を計算する。

余因子は `mat4_minor` / `mat4_cofactor` / `mat4_det` として公開している（`mat4_inverse`
の部品だが、単体でも呼べる）。

**API 規約**: `mat4_inverse` には可逆な行列（`det != 0`）のみを渡すこと。特異行列
（例: いずれかの軸のスケールが 0、退化した基底）を渡した場合の結果は未定義（0 除算）。
呼び出し側が可逆性を保証する（scale が 0 でない・基底が一次独立、といった検証は行列を組む前段で行う）。

## t_mat3 の演算（法線・接空間）

| 関数 | 内容 |
|------|------|
| `mat3_from_columns(u, v, w)` | 3本の基底ベクトルを**列**に並べて組む |
| `mat3_mul_vec3(m, v)` | `m · v`。各成分は m の**行**と v の内積 |
| `mat3_mul_transposed(m, v)` | `transpose(m) · v`。転置を組まず、各成分は m の**列**と v の内積 |

`mat3_from_columns` は ONB（`calc_onb`）や TBN（`calc_primitive_tbn`）を組むのに使う。
列に T, B, N を入れた行列に `mat3_mul_vec3` を掛けると接空間 → world の変換になり
（`calc_normal_mapping`, `calc_bump_mapping`）、`mat3_mul_transposed` は逆転置による
法線変換に使う（`calc_primitive_normal`。詳細は [primitive_normal.md](primitive_normal.md)）。

## ビルダ（local→world の M を組む）

| 関数 | 内容 |
|------|------|
| `mat4_translate(t)` | 平行移動（右列に `t`） |
| `mat4_scale(s)` | 各軸スケール（対角に `s`） |
| `mat4_rotate(axis, degree)` | `axis` まわりに `degree` 度回転（Rodrigues。列＝回転後の基底ベクトル） |
| `mat4_basis(basis, origin)` | 上位3x3 に基底 `t_mat3`、右列に `origin` を置く |
| `mat4_local_to_world(basis, origin, scale)` | `translate(origin) · basis · scale(s)` を直接組む |
| `mat4_world_to_local(basis, origin, scale)` | その逆行列 `scale(1/s) · transpose(basis) · translate(-origin)` を閉形式で組む |
| `mat4_is_valid_scale(scale)` | 各軸の \|scale\| が `EPSILON` 以上かを検証する |

`mat4_basis` は正規直交基底（ONB）と中心から local→world の M を組む。基底を `t_mat3`
で受け取るため、`matrix` は上位レイヤ（scene）の型に依存しない。

```
      | bx by bz Ox |   b* = 基底ベクトル（列）
M  =  | ...         |   O* = origin（中心）
      | 0  0  0  1  |
```
合成は `M = translate · rotate · scale`（右から順に local に適用）の順で掛ける。

`mat4_world_to_local` は `mat4_inverse` を使わない。基底が正規直交なら逆行列は転置なので、
一般の逆行列を解く必要が無い。`mat4_inverse` でも同じ行列は得られるが精度が数桁落ち、その
誤差はレイが面をかすめるとき `1 / cos` で増幅されるため、閉形式を使う。

`mat4_local_to_world` / `mat4_world_to_local` を呼ぶ前に `mat4_is_valid_scale` を通すこと
（`build_primitive` が実施）。スケールが 0 に近いと M が特異になる。負のスケールは軸を反転
させるだけなので受け付ける。

## 変換関数

| 関数 | w | 用途 |
|------|---|------|
| `mat4_transform_point(m, p)` | 1 | 点。`w` 除算で射影して `t_vec3` に戻す |
| `mat4_transform_dir(m, v)` | 0 | 方向。平行移動を受けず、正規化もしない |

以降の同次座標の節が、この点/方向の区別（w=1 / w=0）の根拠を説明する。

## 同次座標 t_vec4

3次元の点・方向を 4x4 行列で一括変換するために、w 成分を加えた `(x, y, z, w)`
で表す。

- 点（位置）: w = 1 → `vec4_from_point`
- 方向（ベクトル）: w = 0 → `vec4_from_dir`

## なぜ w で区別するか

4x4 アフィン変換行列 M は、回転・スケール（左上 3x3 = R）と平行移動（右列 = T）
を持つ。
```
      | R R R Tx |
M  =  | R R R Ty |
      | R R R Tz |
      | 0 0 0 1  |
```
`M · (x, y, z, w)` を計算すると、平行移動成分は **T·w** の形で効く。

|              | w | 平行移動 T | 回転・スケール R |
|--------------|---|-----------|-----------------|
| 点 from_point | 1 | 効く      | 効く            |
| 方向 from_dir | 0 | 効かない  | 効く            |

点は空間上の位置なので、移動・回転・スケールをすべて受ける。方向は向きだけの量で
位置を持たないため、平行移動を受けてはならず、回転・スケールのみ受ける。

## レイ変換での使い分け

レイをオブジェクトのローカル空間へ変換する例：
```
local_origin = mat4_transform_point(M_inv, ray.origin);  // w = 1
local_dir    = mat4_transform_dir(M_inv, ray.dir);       // w = 0
```
- origin（点）は平行移動込みで動き、中心を原点とした正しい位置になる。
- dir（方向）は平行移動を無視して回転のみ受け、向きが保たれる。

## 取り違えると

- 方向に w = 1 を使う：方向に中心オフセットが足され、向きがずれる。
- 点に w = 0 を使う：点が平行移動を受けず、常に原点基準となり交差位置が壊れる。

二次曲面判定 `pᵀQp` でも、点を w = 1 で入れることで Q の一次項（位置）・定数項
（半径など）が正しく効く。
