# Phong Reflection Modelにおけるスポットライト光の輪郭の減衰

### 0. スポットライトのモデル

スポットライトはポイントライトに「向き `dir`」と「円錐の開き角(コーン角)」を追加したもの。
光源位置 `pos` から `dir` 方向に開き角 `outer` の円錐状に光が届き、円錐の外は照らさない。

交点 P に対して、P から光源へ向かう単位ベクトルを `L` とすると、
P が円錐の内側にあるかは、`−dir` と `L` のなす角 θ で判定できる。

```
cosθ = L・(−dir)
```

θ が `outer/2` より小さければ円錐の内側。
`acos` を呼ぶ代わりに、コサインを事前計算して比較すれば逆三角関数が不要になる。

```
cos_half_outer = cos(outer/2)

cosθ > cos_half_outer  ⇔  円錐の内側
```

(cos は [0, π] で単調減少なので不等号が反転する)

### 1. ハードカットオフの問題

円錐の内側なら通常のポイントライトとして計算し、外側なら 0 にする…とすると、
輪郭で明るさが不連続にジャンプし、円のフチがくっきり出てしまう(ハードエッジ)。

現実のスポットライトはフチに向かって滑らかに暗くなるので、
輪郭付近で減衰係数を 1 → 0 へ補間する。

### 2. 内側コーンと外側コーンによる補間

円錐を二重にする。

- 内側コーン(半頂角 `inner/2`): この中では減衰なし(attenuation = 1)
- 外側コーン(半頂角 `outer/2`): この外では光ゼロ
- その間: 1 → 0 へ線形補間

```
cos_half_inner = cos(inner/2)
cos_half_outer = cos(outer/2)

                  cosθ − cos_half_outer
attenuation = ─────────────────────────────
              cos_half_inner − cos_half_outer
```

`cosθ = cos_half_inner` で 1、`cosθ = cos_half_outer` で 0 になる。
角度 θ ではなく cosθ のまま補間しているが、輪郭付近の狭い範囲では十分滑らか。

まとめると、

```
attenuation = 1                                       (cosθ ≥ cos_half_inner)
attenuation = (cosθ − cos_half_outer)
              / (cos_half_inner − cos_half_outer)     (cos_half_outer < cosθ < cos_half_inner)
attenuation = 0                                       (cosθ ≤ cos_half_outer)
```

### 3. falloff指数

減衰カーブの形を調整したい場合は、補間結果に指数をかける。

```
attenuation' = attenuation^falloff
```

- `falloff = 1` : 線形(デフォルト)
- `falloff > 1` : 中心付近から早めに暗くなる(柔らかいフチ)
- `falloff < 1` : フチ際まで明るさを保つ(硬めのフチ)

### 4. ライティングへの適用

求めた attenuation を diffuse・specular の両方に乗算する。

## 参考文献
- [減衰とスポットライト係数](https://learn.microsoft.com/ja-jp/windows/uwp/graphics-concepts/attenuation-and-spotlight-factor)
- [LearnOpenGL — Light casters (Spotlight / Smooth edges)](https://learnopengl.com/Lighting/Light-casters)
