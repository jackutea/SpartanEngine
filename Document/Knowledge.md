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