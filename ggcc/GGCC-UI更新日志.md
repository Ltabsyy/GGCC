# GGCC-UI 更新日志

## V 2.3.4

- 新增：下拉菜单（Pulldown）

- 新增：上部菜单按钮（TopMenuButton）加入 withMenu() 函数指定下拉菜单

- 新增：彩色文本（ColorText）添加 click_enable成员设置是否可以被点击，并添加 click 成员判断是否被点击，可以用户自主定义点击后事件

- 新增：彩色文本（ColorText）可指定图标

- 新增：超链接（Hyperlink）提供 click 成员判断是否被点击，可以用户自主定义点击后事件，而不一定打开网址

- 修正：折叠面板（Collapse）收起动画绘制不正确

- 修正：超链接（Hyperlink）字符串长度计算有误

- 修正：开头动画卡顿

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
