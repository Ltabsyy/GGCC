# GGCC-UI 更新日志

## V 2.4.0

- 新增：全面支持 lambda 表达式

- 调整：取消图形调试器（GraphDebugger），改用场景（Scene）

- 调整：取消三维图形调试器（GraphDebugger3D），改用三维场景（Scene3D）

- <mark>场景（Scene）</mark>
  
  - 新增：全面兼容 **geometry.h**，可使用 `ui::plot->shape();` 直接绘制几何图形
  
  - 新增：绘制 raylib 字体 `ui::plot->raylib_text();`
  
  - 新增：可限制网格格范围 `ui::plot->set_mesh();`
  
  - 新增：可限制缩放范围
  
  - 新增：设置缩放和摄像机 `ui::plot->set_zoom() ui::plot->set_position();`
  
  - 新增：椭圆形、多边形、圆角多边形等 `ui::plot->ellipse(); ui::plot->polygon(); ui::plot->round_polygon();`
  
  - 新增：使用 **evaluate.h** ，可通过字符串生成函数 `ui::plot->function("sin(x)*cos(x)");`
  
  - 调整：取消 `g.draw` 系列函数，改用 `ui::plot->` 系列函数
  
  - 修正：鼠标检测问题

- 调整：取消界面（Interface），改用页面（Page）

- 调整：取消 add:: 系列函数，改用 create:: 系列函数

- <mark>修正：启动程序有概率崩溃</mark>

- 修正：部分函数无法链式调用

## V 2.3.4

- 新增：根据群友 <mark>**Ltabssy**</mark> 提供的算法和配色方案，优化代码高亮

- 新增：代码高亮配色方案："One Dark"，"VS Modern Dark"，"MoLo CodeBlack”，"Monokai Pro"，"Mariana"

- 新增：多行输入框（MultiInputBox）中增加 statebar_visible 选项设置是否显示状态栏

- 新增：多行输入框（MultiInputBox）中提供对<mark>【图标字体】</mark>和<mark>【Emoji】</mark>的初步支持

- 新增：多行输入框（MultiInputBox）小地图可显示当前行高亮

- 新增：多行输入框（MultiInputBox）增加彩虹缩进提示线

- 新增：下拉菜单（Pulldown）

- 新增：上部菜单按钮（TopMenuButton）加入 withMenu() 函数指定下拉菜单

- 新增：彩色文本（ColorText）添加 click_enable 成员设置是否可以被点击，并添加 click 成员判断是否被点击，可以用户自主定义点击后事件

- 新增：彩色文本（ColorText）可指定图标

- 新增：超链接（Hyperlink）提供 click 成员判断是否被点击，可以用户自主定义点击后事件，而不一定打开网址

- 新增：崩溃处理机制（Crash Processing），就已发现无法解决的崩溃情况进行编号，详见<mark><u>**《GGCC-UI 崩溃记录及原因》**</u></mark>

- 修正：折叠面板（Collapse）收起动画绘制不正确

- 修正：超链接（Hyperlink）字符串长度计算有误

- 修正：开头动画卡顿

- 修正："开"，"崀" 等个别汉字无法通过键盘输入

- 修正：输入 emoji 符号会崩溃（原因是没有考虑编码超过 65536 的字符，emoji 的编码却达到了6位数）

- 修正：多行输入框（MultiInputBox）内光标移动时，滚动条跟随不稳定

- 调整：统一多行输入框（MultiInputBox）内背景色

- 调整：多行输入框（MultiInputBox）中左右移动光标时，到达行首行尾时增加一定延时

- 调整：默认取消多行输入框（MultiInputBox）中行号栏和小地图的阴影，可以设置选项 shadow_visible 重新启用

- 调整：滚动条拖动手感小幅优化

## V 2.3.3

- 新增：【实验功能】提供 add:: 系列函数，支持动态自动添加控件，支持嵌套

- 新增：设置控件参数支持链式调用

- 新增：按钮（Button）可指定回调函数（Callback Function）

- 新增：窗口（Window）加入关闭按钮

- 新增：多行输入框（MultiInputBox）加入行文本裁剪，提高渲染效率

- 新增：如果程序意外调用了没有被重写的 Element 虚函数，会产生 :( 提示

- 新增：多行输入框（MultiInputBox）支持缩进，支持显示空白字符，支持显示缩进提示线

- 新增：多行输入框（MultiInputBox）/ 输入框（InputBox）可通过 .text 参数指定提示文本

- 新增：多行输入框（MultiInputBox）选择文本时，小地图中会显示选择的内容

- 新增：彩色文本（ColorText）

- 新增：复选框（CheckBox）增加勾选动画

- 修正：嵌套控件析构函数无法正常调用

- 修正：多行输入框（MultiInputBox）上下移动光标，编辑后产生乱码

- 修正：多行输入框（MultiInputBox）数据达到百万行后发生意外崩溃

- 修正：多行输入框（MultiInputBox）数据超过万行后撤销操作耗时过长

- 修正：界面（Interface）左右间距计算不正确

- 修正：调整窗口导致动画错乱

- 调整：使用新版 Logo、新的开头动画

- 调整：所有与动画有关的操作取消使用 clock() 计时，改用 ggcc::gclock() 计时

## V 2.3.2

- 新增：多标签页（MultiTab）

- 新增：超链接（Hyperlink）、窗口（Window）可指定图标

- 新增：多行输入框（MultiInputBox） 增加 Import() 和 Export() 函数，用于导入文件、导出文件

- 新增：动态分配的控件可以使用 auto_release() 函数自动释放

- 新增：自由页面（Free）、多标签页（MultiTab）、折叠面板（Collapse）提供【放大+淡入】动画

- 新增：多选框（CheckBox）、分割线（Line） 等控件支持【延迟+上浮+淡入】动画

- 修正：窗口（Window） 拖动和改变大小无效（实际是 raylib 5.0 的 bug，在5.1中已修复)

- 修正：多行输入框（MultiInputBox） 中滚动条上光标始终停留在起始位置

- 调整：字体导入使用动态大小

- 调整：取消 UseIcon() 函数，改为自动导入，手动导入改用 LoadIcon() 函数

- 调整：取消 TopMenuButton 中直接定义按钮，改用 AddButton() 函数添加按钮

- 调整：取消 AddSider() 函数，改用 sider.AddSider()

- 调整：取消 DrawLayout() 函数，改用 layout.Draw()

- 调整：取消下拉菜单（Dropdown），改用折叠面板（Collapse）

- 调整：取消窗口（Windows）调整大小时的回弹动画，改用经典动画

- 调整：取消折叠面板（Collapse）调整大小时的回弹动画，改用经典动画

## V 2.3.1

- 新增：输入框（InputBox）支持中文输入、选择等多行输入框（MultiInputBox）支持的若干功能

- 新增：输入框（InputBox）/ 多行输入框（MultiInputBox）执行撤销、重做操作时合并连续输入、连续删除

## V 2.3.0

- 调整：重构 GGCC-UI

- 新增：界面（Interface） 提供【延迟+上浮+淡入】动画和【放大+淡入】动画
