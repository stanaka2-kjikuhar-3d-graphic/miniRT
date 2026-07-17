外積を使わないONB（Orthonormal Basis・正規直交基底）の作り方

導出

0. 使用する公式

単位クォータニオン（四元数）(p=w+xi+yj+zk)=(w,x,y,z)の単位軸u(ux,uy,uz)周りの回転は
```
q = cos(θ/2) + sin(θ/2)(ux*i + uy*j + uz*k)
```
より、
```
w = cos(θ/2)
x = sin(θ/2)・ux
y = sin(θ/2)・uy
z = sin(θ/2)・uz
```
と表す。

また、
単位クォータニオンから回転行列Rへの変換行列は、
```
      | 1−2(y²+z²)  2(xy−wz)    2(xz+wy)   |
R  =  | 2(xy+wz)    1−2(x²+z²)  2(yz−wx)   |
      | 2(xz−wy)    2(yz+wx)    1−2(x²+y²) |
```




https://ja.wikipedia.org/wiki/%E5%9B%9B%E5%85%83%E6%95%B0