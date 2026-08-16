# UVを正準ローカル座標から求める

world 空間の点と ONB の内積で角度を出していた UV 計算を、正準ローカル座標の成分から求める形に変える。

交差判定（[primitive_intersection.md](primitive_intersection.md)）と法線（[primitive_normal.md](primitive_normal.md)）に続いて、形状ごとに分かれていた `calc_*_uv` 7本が1本に畳まれる。

## 1. 内積がそのまま座標成分になる

これまでの UV は、world 空間で方位角を組み立てていた。

```c
/* calc_sphere_uv.c */
phi = atan2f(vec3_dot(normal, sphere->onb.v), vec3_dot(normal, sphere->onb.u));
```

`onb.u` と `onb.v` はローカルの x 軸と y 軸を world に置いたものなので、これらとの内積はローカル座標の x 成分と y 成分そのものである。
点をローカルに引き戻せば、内積は消えて成分の取り出しになる。

```c
uv.u = (atan2f(p.y, p.x) + M_PI) / (2.0f * M_PI);
```

`t_onb` への依存がここで切れる。

## 2. 正準形ごとの v

`u` は側面を持つ5種すべてで方位角から求まる。
`v` は正準形ごとに z の正規化の仕方が違う。

| 正準形 | v |
| --- | --- |
| `UNIT_SPHERE` | `1 - (asin(z) + π/2) / π` |
| `UNIT_CYLINDER` | `0.5 - z / 2` |
| `UNIT_CONE` | `z` |
| `UNIT_HYPERBOLOID` | `0.5 - z / (2 z_max)` |
| `UNIT_PARABOLOID` | `z` |

円柱と一葉双曲面が上端で `v = 0` になる向きなのは、キャップの円盤（`add_cap_circle`）が
その向きを前提に `v_range` を割り当てているためである（[hyperboloid.md](hyperboloid.md) 5節）。
以前は `calc_hyperboloid_uv` が戻り値を反転して辻褄を合わせていたが、この式では符号がそのまま入っている。

一葉双曲面だけ `z_max` で割るのは、正準形の z 範囲がオブジェクトごとに変わるからである。
`t_primitive` が持つ `z_range` をそのまま使う。

平面と円盤は方位角を使わない。

- **平面**：`u = frac(x - 0.5)`、`v = frac(y - 0.5)`。`pattern_size` はスケールに吸収済みなので、割り算が式から消える
- **円盤**：`u` は方位角、`v` は `hypot(x, y)`。半径もスケールに吸収されている。`UV_LOWER_CAP` のときに `u` と `v` を反転する分岐は従来どおり

## 3. 円錐の u が鏡像になっている（既知の問題）

正準形の円錐は頂点が `z = 0` にあるので、フレームの z 軸は `-dir` を向く。
このとき x 軸と y 軸をどう取るかで `u` の継ぎ目の位置が決まる。

`create_cone.c` は `basis_from_dir(-dir)` でフレームを組んでいるが、`calc_onb()` は `dir` と `-dir` で `v` の符号が反転する。
そのため `atan2(p.y, p.x)` の符号が変わり、`u` が `1 - u` になる。

旧実装の `cone_quadric.c` は `w` だけ反転させ、`u` と `v` は `+dir` のものを残していた。
そちらが正しい組み方である。

この UV 化によって鏡像が表に出るが、修正は #89 で別に扱う。
交差判定と法線は正準形が z 軸まわりに回転対称なので影響を受けない。

## 4. 遠い交点での frac

平面の `u` と `v` は `frac()` を通すので、交点が原点から遠いと精度が落ちる。
無限平面をかすめるレイでは交点が数万単位まで飛ぶことがあり、`pattern_size` で割った商が float の有効桁を超える。

これは world 空間で計算していた頃と同じ性質で、この変更で悪化も改善もしない。
実測では、交点までの距離を100以下に絞ると差が `3e-2` から `3e-5` に落ちた。

---
参考: [primitive_intersection.md](primitive_intersection.md)（レイをローカルへ引き込む側）、[primitive_normal.md](primitive_normal.md)（法線を戻す側）、[hyperboloid.md](hyperboloid.md)（キャップと `v` の向き）
