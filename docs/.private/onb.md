# 外積と三角関数を使わないONB(Orthonormal Basis・正規直交基底)の作り方

### 0. 使用する公式

単位クォータニオン `q = qw + qx·i + qy·j + qz·k` による、単位軸 u(ux,uy,uz) 周り角度θの回転は

```
q = cos(θ/2) + sin(θ/2)(ux·i + uy·j + uz·k)
```

より、

```
qw = cos(θ/2)
qx = sin(θ/2)・ux
qy = sin(θ/2)・uy
qz = sin(θ/2)・uz
```

単位クォータニオンから回転行列Rへの変換は、

```
      | 1−2(qy²+qz²)    2(qx·qy−qw·qz)  2(qx·qz+qw·qy) |
R  =  | 2(qx·qy+qw·qz)  1−2(qx²+qz²)    2(qy·qz−qw·qx) |
      | 2(qx·qz−qw·qy)  2(qy·qz+qw·qx)  1−2(qx²+qy²)   |
```

### 1. 回転軸の導出

Z軸(0,0,1)を `w=(x,y,z)`(単位ベクトル)へ回す回転を考える。

```
Z×w = (0,0,1)×(x,y,z) = (−y, x, 0)
|Z×w| = √(x²+y²) = √(1−z²) = sinθ
u = (−y, x, 0)/√(1−z²)
```

```
s = √(1−z²) = sinθ
```

とおく。

### 2. 回転軸をクォータニオンへ代入

```
qw = cos(θ/2)
qx = sin(θ/2)・(−y/s)
qy = sin(θ/2)・( x/s)
qz = 0
```

### 3. `qz = 0` を回転行列Rへ代入

```
      | 1−2qy²   2qx·qy   2qw·qy      |
R  =  | 2qx·qy   1−2qx²  −2qw·qx      |
      | −2qw·qy  2qw·qx   1−2(qx²+qy²)|
```

### 4. u, v を回転行列の列として取り出す

```
u = R×X軸(1,0,0) = 第1列 = (1−2qy²,  2qx·qy,  −2qw·qy)
v = R×Y軸(0,1,0) = 第2列 = (2qx·qy,  1−2qx²,   2qw·qx)
```

(第3列は w 自身になる)

### 5. 各項を成分で表す

倍角の公式 `sin(θ/2)cos(θ/2) = sinθ/2` と `s = sinθ` より、
```
qx² = sin²(θ/2)・(y²/s²)
qy² = sin²(θ/2)・(x²/s²)
qx·qy = sin²(θ/2)・(−xy/s²)
qw·qx = (sinθ/2)・(−y/s) = −y/2
qw·qy = (sinθ/2)・( x/s) =  x/2
```

半角公式と `Z・w = cosθ = z` より、

```
sin²(θ/2) = (1−cosθ)/2 = (1−z)/2
```

`s² = 1−z²` と組み合わせて、

```
a/2 = sin²(θ/2)/s² = ((1−z)/2)/(1−z²) = 1/(2(1+z))
a = 1/(1+z)
```

とおくと、

```
qx²   = y²・(a/2)
qy²   = x²・(a/2)
qx·qy = −xy・(a/2)
qw·qx = −y/2
qw·qy =  x/2
```

### 6. u, v へ代入

```
u = (1−2qy²,  2qx·qy,  −2qw·qy) = (1 − a·x²,  −a·xy,  −x)
v = (2qx·qy,  1−2qx²,   2qw·qx) = (−a·xy,  1 − a·y²,  −y)
```

## 結果

`w=(x,y,z)` に対し `a=1/(1+z)` として

```
u = (1 − a·x²,  −a·xy,  −x)
v = (−a·xy,  1 − a·y²,  −y)
```

これで外積や三角関数を計算することなく右手系のONB (u, v, w) が得られる

## 注意

`z = −1`(wがZ軸の真逆)で `a = 1/(1+z)` が発散する。
実装では `z<0` で符号を反転するか、`copysign`を使用したbranchless版を使うのが定石(全域で特異点なし・分岐なし)。

```
sign = copysign(1, z)
a = −1/(sign + z)
b = x·y·a
u = (1 + sign·x²·a,  sign·b,  −sign·x)
v = (b,  sign + y²·a,  −y)
```

## 参考文献

- [branchless onb (Duff et al. 2017, JCGT)](https://jcgt.org/published/0006/01/01/paper-lowres.pdf)
- [quaternion (Wikipedia)](https://ja.wikipedia.org/wiki/%E5%9B%9B%E5%85%83%E6%95%B0)
- [クォータニオン計算便利ノート](https://www.mesw.co.jp/business/report/pdf/mss_18_07.pdf)