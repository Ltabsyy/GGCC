# geometry.h 食用指北

----



## <u>0x00 关于</u>

本头文件由 **GGCC Studio** 出品，属于 **GGCC-SDK** 的数学部分，包含简单的几何相关功能，使用 C++编写，不依赖于第三方库，可直接食用。



## <u>0x10 配置方法</u>

与正常配置头文件方法相同



## <u>0x20 基本概念</u>



### 0x21 实数

实数`realn`等同于`long double`，用于储存精度较高的浮点数，`geometry.h`中均使用`realn`。

```cpp
realn a = 1, b = 1.3;
```



### 0x22 弧度制

`geometry.h`使用弧度制。



### 0x23 向量和点

与数学中的向量概念基本一致，向量可以运算。**点和向量完全一样**，也可以运算。

向量结构如下：

```cpp
struct point2d {
    realn x = 0;
    realn y = 0;
};
struct point3d {
    realn x = 0;
    realn y = 0;
    realn z = 0;
};
typedef point2d vector2d;
typedef point3d vector3d;
```

食用方法，需`using namespace ggcc;`：

```cpp
// 使用命名空间
using namespace ggcc;

// 二维向量和点
vector2d a(1, 2);
point2d b(3, 4);

// 三维向量和点
vector2d c(1, 2, 3);
point3d d(4, 5, 6);

// 向量运算，二维三维基本相同
realn k = 1.234;
a * k;    // 向量数乘
a / k;    // 向量缩小
a *= k;   // 累乘
a /= k;   // 累除
a + b;    // 向量加   
a - b;    // 向量减
a * b;    // 向量点乘
a ^ b;    // 向量叉乘
a >> b;   // 向量投影，a投影到b，返回投影向量
a += b;   // 累加
a -= b;   // 累减
a >>= b;  // a投影到b
a = b;    // 复制
-a;       // 取反

// 条件运算
a == b;
a != b;

// 常量
vector2d pg::axisX;    // x方向基向量
vector2d pg::axisY;    // y方向基向量
vector3d pg::axisZ;    // z方向基向量
realn A2R;             // 角度转弧度
realn R2A;             // 弧度转角度
realn PI;              // 圆周率

// 内置函数, 二维三维基本相同
Mod(a);    // a的模长
Mod2(a);   // a的模长的平方
Dis(a, b); // a,b两点间距离
VecUnit(a);// a方向的单位向量
VecUnit(PI / 2);// PI/2方向的单位向量
VecAngle(a, b); // a,b向量夹角，范围[-P,PI]
a.Rotate(PI);   // a旋转PI的结果，不改变a
c.Rotate(d, PI);// c以d为轴旋转PI的结果，不改变c
Shadow(a, b);   // a在b上的投影
ShadowV(a, b);  // a在b上的投影向量

// 其他功能
point2d rel2abs(point2d p, point2d rfrc, realn rotate); // 相对坐标转绝对坐标
point2d rel2abs(point2d p, point2d rfrc, point2d dir);  // 相对坐标转绝对坐标
point2d abs2rel(point2d p, point2d rfrc, realn rotate); // 相对坐标转相对坐标
point2d abs2rel(point2d p, point2d rfrc, point2d dir);  // 绝对坐标转相对坐标
point2d AxialSymmetry(point2d dir, point2d v);          // 轴对称
point2d CentralSymmetry(point2d o, point2d v);          // 中心对称
```



## <u>0x30 平面几何</u>



### 0x31 命名

平面几何位于命名空间`ggcc::pg`下，第一层一般使用`using namespace ggcc;`。

`pg`是`plane geometry`的缩写。



### 0x32 图形

`geometry.h`使用`pg::shape`表示图形，使用`pg::ShapeType`表示图形类型。

`pg::ShapeType`结构如下：

```cpp
// 图形类型
enum ShapeType {
    shapetype_empty = 0,        // 空白图形
    shapetype_point = 1,        // 点
    shapetype_segment = 2,    // 线段
    shapetype_circle = 3,        // 圆形
    shapetype_ellipse = 4,    // 椭圆形
    shapetype_polygon = 5,    // 多边形
    shapetype_roundpoly = 6,// 圆角多边形
    shapetype_capsule = 7        // 胶囊形
};
```

各种形状及继承关系：

| 类名                  | 说明                       | 对应`ShapeType`       |
| ------------------- | ------------------------ | ------------------- |
| `pg::point`         | 点，继承于`pg::shape`         | shapetype_point     |
| `pg::segment`       | 线段，继承于`pg::shape`        | shapetype_segment   |
| `pg::circle`        | 圆形，继承于`pg::shape`        | shapetype_circle    |
| `pg::ellipse`       | 椭圆形，继承于`pg::shape`       | shapetype_ellipse   |
| `pg::capsule`       | 胶囊形，继承于`pg::shape`       | shapetype_capsule   |
| `pg::polygon`       | 多边形，继承于`pg::shape`       | shapetype_polygon   |
| `pg::roundpoly`     | 圆角多边形，继承于`pg::shape`     | shapetype_roundpoly |
| `pg::rectangle`     | 矩形，继承于`pg::polygon`      | shapetype_polygon   |
| `pg::triangle`      | 三角形，继承于`pg::polygon`     | shapetype_polygon   |
| `pg::roundrect`     | 圆角矩形，继承于`pg::roundpoly`  | shapetype_roundpoly |
| `pg::roundtriangle` | 圆角三角形，继承于`pg::roundpoly` | shapetype_roundpoly |

`pg::shape`可用成员如下：

```cpp
class shape {
public:
    vector2d pos = vector2d{0, 0};// 位置
    realn rotate = 0;             // 旋转弧度
    // 获取形状类型
    ShapeType GetShapeType();
    // 求支撑点
    virtual vector2d Support(vector2d u);
    // 计算AABB碰撞盒
    virtual aabb CalcAABB();
    // 计算面积
    virtual realn CalcArea();
    // 校准中心
    virtual void CheckCenter();
    // 绝对位置
    vector2d Abs(const vector2d& p);
    // 相对位置
    vector2d Rel(const vector2d& p);
    // 绘制（用户自行实现）
    virtual void Draw(unsigned color);
    virtual void DrawLines(unsigned color);
};
```

食用方法：

```cpp
// 使用命名空间
using namespace ggcc;

// 通过构造函数创建形状
pg::segment seg({0,0},{0,1});          // 两个端点
pg::circle cir({0, 0}, 1);             // 圆心和半径
pg::ellipse ell({-2, 0}, 1, 0.7);      // 椭圆中心、长轴、短轴
pg::polygon poly({2, 0}, 10, 1);       // 多边形中心、边数、半径
pg::rectangle rec({4, 0}, 2, 1);       // 矩形中心、长、宽
pg::roundrect rou({4, 4}, 2, 1, 0.3);  // 圆角矩形中心、长、宽、圆角程度
pg::capsule cap({4, 1}, {4, 2}, 0.5);  // 胶囊形两个圆心、半径
pg::roundpoly rpoly({6, 4}, 7, 1, 0.5);// 圆角多边形中心、边数、半径、圆角程度

// 也可以使用多态
std::vector <pg::shape*> body = {
    new pg::circle({0, 0}, 1),
    new pg::circle({0, 2}, 0.8),
    new pg::ellipse({-2, 0}, 1, 0.7),
    new pg::ellipse({-4, 0}, 1.1, 0.6),
    new pg::polygon({2, 0}, 10, 1),
    new pg::rectangle({4, 0}, 2, 1),
    new pg::roundrect({4, 4}, 2, 1, 0.3),
    new pg::capsule({4, 1}, {4, 2}, 0.5),
    new pg::roundpoly({6, 4}, 7, 1, 0.5)
};

// 还可以复制，这样可以便于重新构建形状
pg::circle body1 = pg::circle({0, 0}, 1);    
pg::rectangle body2 = pg::rectangle({2, 0}, 3, 2);

// 创建完毕记得要校准重心
for (auto i : body) i->CheckCenter();
seg.CheckCenter();
cir.CheckCenter();
    :
<此处省略>

// 重要的成员变量
rec.pos = {5, 6};    // 改变位置
rec.rotate = PI / 3; // 改变朝向
```



### 0x33 凸包

凸包函数接受点阵`std::vector <vector2d>`作为参数，返回点阵`std::vector <vector2d>`表示凸包：

```cpp
pg::polygon pg::ConvexHull(std::vector <vector2d> p);
```



### 0x34 包围盒AABB

**AABB包围盒** 通过构造水平竖直的矩形包围物体。在碰撞检测之前先检测**AABB**碰撞，可以提高速度。

AABB结构如下：

```cpp
struct aabb {
    realn x1;
    realn y1;
    realn x2;
    realn y2;
};
```

通过`pg::shape`中的 `CalcAABB()`方法可获得物体的`AABB`包围盒：

```cpp
pg::circle cir({0, 0}, 1);
pg::aabb box = cir.CalcAABB();
```

**AABB**有一些基本的内置函数：

```cpp
pg::aabb pg::aabb::Merge(const aabb& a, const aabb& b); // 合并AABB包围盒
bool pg::aabb::Collide(const aabb& a, const aabb& b);   // 检测AABB碰撞
```



### 0x35 精细碰撞检测

精细碰撞检测使用函数`pg::collision::NarrowPhase()`实现，采用 GJK + EPA 算法

```cpp
CollisionData NarrowPhase(pg::shape &a, pg::shape &b);
```

碰撞检测的结果使用`pg::collision::CollisionData`储存，结构如下：

```cpp
// 详细碰撞数据
struct CollisionData {
    bool detect = false;          // 是否碰撞
    vector2d penetrate = {0, 0};  // 穿透向量
    MinkowskiLine line;           // 闵可夫斯基差
    vector2d p1, p2;              // 碰撞点对
    realn deep = 0;               // 穿透深度
};
```

食用方法：

```cpp
// 使用命名空间
using namespace ggcc;

// 创建物体
pg::circle body1({0, 0}, 1);    
pg::rectangle body2({2, 0}, 3, 2);
body2.rotate = PI / 3;
body1.CheckCenter();
body2.CheckCenter();

// 碰撞检测
auto result = pg::collision::NarrowPhase(body1, body2);

// 打印结果
std::cout << result.detect << std::endl;
std::cout << result.penetrate << std::endl;
std::cout << result.p1 << std::endl;
std::cout << result.p2 << std::endl;
```

输出结果：

```context
1
(0.232051,-0.133975)
(0.866025,-0.5)
(0.633975,-0.366025)
```

示意图：

注意，碰撞点对 $P1$, $P2$ 是两个图形碰撞的最近分离点，穿透深度 $\overrightarrow{penetrare} = P1 - P2$

<img title="" src="https://i-blog.csdnimg.cn/direct/4d48e7e97d9d44a88ec280373d72894f.png" alt="image" style="zoom:33%;">

## <u>0x40 使用 GGCC-UI </u>



### 0x41 效果

**GGCC-UI**内置的`ui::GraphDebugger`控件可用于演示**geometry.h**的内容

<img src="https://i-blog.csdnimg.cn/direct/2dec5ba4c5914e8e93cdc6e033e417b4.png" title="" alt="image" style="zoom:50%;">

### 0x42 示例程序

```cpp
#include <ggcc/ggccui.h>
using namespace ggcc;

std::vector <pg::shape*> body = {
    new pg::circle({0, 0}, 1),
    new pg::circle({0, 2}, 0.8),
    new pg::ellipse({-2, 0}, 1, 0.7),
    new pg::ellipse({-4, 0}, 1.1, 0.6),
    new pg::polygon({2, 0}, 10, 1),
    new pg::rectangle({4, 0}, 2, 1),
    new pg::roundrect({4, 4}, 2, 1, 0.3),
    new pg::capsule({4, 1}, {4, 2}, 0.5),
    new pg::roundpoly({6, 4}, 7, 1, 0.5)
};

int main() {
    for (auto i : body) {
        i->rotate = rand() % 1000 / 1000.0 * PI;
        i->CheckCenter();
    }
    ui::Init();
    create::GraphDebugger([&] {
        for (auto i : body) {
            bool detect = 0;
            vector2d move;
            for (auto j : body) 
                if (i != j) {
                    auto result = pg::collision::NarrowPhase(*i, *j);
                    move += result.penetrate;
                    detect |= result.detect;
                }
            ui::plot->shape_controlled_withAABB(*i, detect ? RED : GREEN);
            i->pos -= move;
        }
    });
    ui::Run();
}
```



## <u>0x50 后续步骤</u>

这些内容尚未实现，敬请期待：

- [ ] 简单的 **AABB** 碰撞检测优化 - **SAP**算法

- [ ] 相交测试加速结构 - **BVH** 与 **DBVH** 算法

- [ ] 射线碰撞检测

- [ ] 立体几何部分

- [ ] 四维向量

- [ ] 四元数

- [ ] 矩阵相关运算
  
  

## <u>更新日志</u>

### $2024.8.30$

- 修复：碰撞检测 **EPA** 部分的精度问题

- 修复：构造函数未定义

- 修复：线段（`pg::segment`）支撑点计算问题

- 新增：凸包求解函数（`pg::ConvexHull()`）

- 新增：图形-点（`pg::point`）
  
  

<mark>**欢迎大家反馈bug、提出建议 或者 参加 geometry.h 的开发！**</mark>
