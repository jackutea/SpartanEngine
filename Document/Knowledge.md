==== Mathematics ====
```
> 点乘
float value = Vector3.Dot(dir1, dir2)
- value == 0 意味着垂直
- value < 0 意味着方向相背(-1表示完全相反)
- value > 0 意味着方向相似(1表示完全相同)
因此Dot(负的光入射方向, 表面法线), 可以得到表面受光的强度

> 叉乘 3D
Vector3 value = Vector3.Cross(dir1, dir2)
- 注: dir1, dir2 不可交换
- 作用1: dir1和dir2会形成一个2维平面, value则是垂直于该平面
    - 参考: 如果是右手坐标系, 则中指为dir1, 拇指为dir2, value则是食指
- 作用2: 判断一个点p是否在三角形abc内
    - z1 = ap.cross(ab).z
    - z2 = bp.cross(bc).z
    - z3 = cp.cross(ca).z
    - z1 * z2 > 0 && z2 * z3 > 0 则在内部
```

==== Shading ====
```
> Lambert 光照模型
Diffuse 漫反射
Ambient 环境光(环境光本来是复杂的, 但Lambert当作只有一种色)

> Phong = Lambert + Specular
Specular 高光
当光线通过法线反射到观察坐标(相机)时, 呈现高光
r = reflect(-light, normal)
value = dot(r, viewDir)

> Blinn-Phong
不进行反射运算, 而是:
n = normalize(light, viewDir)
value = dot(n, normal)

> Gamma 校正
这是对人眼感受的校正, 比如0.5理应是一种灰色, 但人眼看到的是接近黑色
color = pow(color, vec4(1.0/2.2))

> Point Light
衰减计算
attenuation = 1 / (1 + k1 * dis + k2 * dis)
ambient *= attenuation
diffuse *= attenuation
specular *= attenuation

<系数k参考表, 来源:https://wiki.ogre3d.org/tiki-index.php?page=-Point+Light+Attenuation>
dis     k1(linear)  k2(quadratic)
7		0.7	        1.8
13		0.35	    0.44
20		0.22	    0.20
32		0.14	    0.07
50		0.09	    0.032
65		0.07	    0.017
100		0.045	    0.0075
160		0.027	    0.0028
200		0.022	    0.0019
325		0.014	    0.0007
600		0.007	    0.0002
3250	0.0014	    0.000007
```