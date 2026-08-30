#include <ggcc/ggccui.h>
using namespace ggcc;

void RunProgram(std::function <void()> fun) {
	auto& temp = create::Prepare_Page([&] {
		fun();
		create::sider::TopMenu().AddButton("[]返回").withCallback([&] {
			ui::mainwin.ShiftBack();
		});
	});
	ui::mainwin.ShiftTo(&temp);
}

int main() {

	tree_node <std::string> tr;
	tr.child(0).set("[]关于");
	tr.child(1).set("[]安装&配置");
	tr.child(2).set("[]我的第一个应用");
	tr.child(3).set("[]概述");
	tr.child(3).child(0).set("什么是控件");
	tr.child(3).child(1).set("控件结构体系");
	tr.child(3).child(2).set("如何创建控件");
	tr.child(4).set("[]普通控件目录");
	tr.child(4).child(0).set("标题（Head）");
	tr.child(4).child(1).set("文本（Text）");
	tr.child(4).child(2).set("按钮（Button）");
	tr.child(4).child(3).set("分割线（Line）");
	tr.child(4).child(4).set("空格（Space）");
	tr.child(4).child(5).set("开关（Switch）");
	tr.child(4).child(6).set("复选框（CheckBox）");
	tr.child(4).child(7).set("单选框（RadioBox）");
	tr.child(4).child(8).set("滚动条（Slider）");
	tr.child(4).child(8).child(0).set("实数滚动条");
	tr.child(4).child(8).child(1).set("整数滚动条");
	tr.child(4).child(9).set("输入框（InputBox）");
	tr.child(4).child(10).set("选择框（ChooseBox）");
	tr.child(4).child(11).set("警告框（Warning）");
	tr.child(4).child(12).set("错误框（Error）");
	tr.child(4).child(13).set("高级文本（ColorText）");
	tr.child(4).child(14).set("加载条（LoadingBar）");
	tr.child(4).child(15).set("超链接（Hyperlink）");
	tr.child(4).child(16).set("折叠面板（Collapse）");
	tr.child(4).child(17).set("文本框（TextBox）");
	tr.child(4).child(18).set("块（Box）");
	tr.child(5).set("[]扩展控件目录");
	tr.child(5).child(0).set("窗口（Window）");
	tr.child(5).child(1).set("页面（Page）");
	tr.child(5).child(2).set("场景（Scene）");
	tr.child(5).child(3).set("自由页面（Free）");
	tr.child(5).child(4).set("多行输入框（MultiInput）");
	tr.child(5).child(5).set("表格（Table）");
	tr.child(5).child(6).set("拆分布局（Layout）");
	tr.child(6).set("[]侧边栏控件目录");
	tr.child(6).child(0).set("顶栏（TopMenu）");
	tr.child(6).child(1).set("下拉菜单（Pulldown）");
	tr.child(6).child(2).set("底栏（BottomMenu）");
	tr.child(6).child(3).set("左侧栏（LeftMenu）");
	tr.child(6).child(4).set("导航（Navigation）");
	tr.child(6).child(5).set("标签页（MultiTab）");
	tr.child(6).child(6).set("滚动条（SliderBar）");
	tr.child(7).set("[]库函数目录");
	tr.child(7).child(0).set("环境相关函数");
	tr.child(7).child(1).set("颜色相关函数");
	tr.child(7).child(2).set("消息（Message）");
	tr.child(7).child(3).set("对话框（MessageBox）");
	tr.child(8).set("[]示例程序");
	tr.child(8).child(0).set("Markdown 编辑器");
	tr.child(8).child(1).set("简单扫雷");
	tr.child(8).child(2).set("红石模拟器");
	tr.child(9).set("[]支持&反馈");

	ui::MenuColor = ui::ColorF(34, 38, 42);
	ui::EnableRaylibLog = true;
	ui::Init();
	ui::highlight::SetColorTheme("Mariana");

	// todo 关于
	auto& about = create::Prepare_Page([&] {
		ui::this_page->SetInterval(ui::UnitHeight * 3);
		ui::this_page->SetUnitInterval(ui::SpaceSize * 2);
		create::Head("关于 GGCC-UI");
		create::Line();
		create::Head(2, "0x00 | GGCC-UI 是什么");
		create::Text("GGCC-UI 是一套基于 C++ 和 Raylib 的“所见即所得”的用户界面（GUI）系统，采用面向对象的编程理念，但是封装了一套类似 Dear ImGui 的控件创建方案，使得开发者可以通过一行代码创建一个控件。");
		create::Text("GGCC-UI 的设计初衷是数学可视化，并吸收了 Dear ImGui 的设计特点，因此早期的 GGCC-UI 采取了极为紧凑的控件布局。后经过向 WinUI 的学习借鉴，逐渐调整为较为宽松的设计，一定程度上提高了用户界面的可读性。");
		create::Head(2, "0x10 | 为什么选择 GGCC-UI");
		create::OrderedText(" 美观与流畅的设计：", "");
		create::Text("GGCC-UI 大量使用非线性动画，极大地提高了 GUI 运行的流畅程度，增进视觉体验。");
		create::OrderedText(" 简单的代码结构：", "");
		create::Text("在 GGCC-UI 中，用户可以通过一行代码创建一个控件，并利用 lambda 表达式表达嵌套关系，使代码的结构与界面设计结构相统一，使用贴近自然语言的方法进行编程。");
		create::Head(2, "0x20 | GGCC-UI 有什么局限性");
		create::OrderedText(" 高系统占用：", "");
		create::Text("GGCC-UI 基于 Raylib 视频游戏引擎，采用每帧全部重绘的方法，虽然这种方式在游戏开发中比较通用，但是对于动态效果较少的工具性应用程序而言，则大量占用了 CPU 和 GPU。");
		create::OrderedText(" 静态设计思路：", "");
		create::Text("GGCC-UI 采用静态控件，意味着你将不能随时更改控件的参数。");
	});
	// todo 安装&配置
	auto& package = create::Prepare_Page([&] {
		ui::this_page->SetInterval(ui::UnitHeight * 3);
		ui::this_page->SetUnitInterval(ui::SpaceSize * 2);
		create::Head("安装&配置");
		create::Line();
		create::Head(2, "0x00 | 获取 Raylib");
		create::Head(2, "0x10 | 下载安装包");
		create::Head(2, "0x20 | 配置 GGCC-UI");
	});
	// todo 我的第一个应用
	auto& first_app = create::Prepare_Page([&] {
		ui::this_page->SetInterval(ui::UnitHeight * 3);
		ui::this_page->SetUnitInterval(ui::SpaceSize * 2);
		create::Head("我的第一个应用");
		create::Line();
		create::Head(2, "0x00 | 创建窗口");
		create::TextBox("cpp",
		                std::string("#include <ggcc/ggccui.h>\n") +
		                std::string("using namespace ggcc;\n") +
		                std::string("\n") +
		                std::string("int main() {\n") +
		                std::string("	ui::Init();\n") +
		                std::string("	ui::Run();\n") +
		                std::string("}\n")
		               ).SetCodeDefaultMode();
		create::Head(2, "0x10 | 创建页面");
		create::TextBox("cpp",
		                std::string("#include <ggcc/ggccui.h>\n") +
		                std::string("using namespace ggcc;\n") +
		                std::string("\n") +
		                std::string("int main() {\n") +
		                std::string("	ui::Init();\n") +
		                std::string("	create::Page();\n") +
		                std::string("	ui::Run();\n") +
		                std::string("}\n")
		               ).SetCodeDefaultMode();
		create::Button("[]运行程序").withCallback([&] {
			RunProgram([&] {
			});
		}).SetColor(DARKBLUE);;
		create::Head(2, "0x20 | 添加控件");
		create::TextBox("cpp",
		                std::string("#include <ggcc/ggccui.h>\n") +
		                std::string("using namespace ggcc;\n") +
		                std::string("\n") +
		                std::string("int main() {\n") +
		                std::string("	ui::Init();\n") +
		                std::string("	create::Page([&] {\n") +
		                std::string("		create::Head(\"HELLO WORLD\");\n") +
		                std::string("	});\n") +
		                std::string("	ui::Run();\n") +
		                std::string("}\n")
		               ).SetCodeDefaultMode();
		create::Button("[]运行程序").withCallback([&] {
			RunProgram([&] {
				create::Head("HELLO WORLD");
			});
		}).SetColor(DARKBLUE);
	});
	// todo 概述
	auto& what_is_ele = create::Prepare_Page([&] {
		ui::this_page->SetInterval(ui::UnitHeight * 3);
		ui::this_page->SetUnitInterval(ui::SpaceSize * 2);
		create::Head("什么是控件");
		create::Line();
		create::Text("控件是 GGCC-UI 的基本单位，分为普通控件、扩展控件和侧边栏控件。");
		create::Head(2, "0x00 | 普通控件");
		create::Text("普通控件只占有一行空间");
		create::Head(2, "0x10 | 扩展控件");
		create::Text("扩展控件可以铺满整个空间");
		create::Head(2, "0x20 | 通用控件");
		create::Text("通用控件同时具有普通控件和通用控件的功能，使用 SetExtra() 函数可以切换控件类型。");
		create::Text("依据该控件默认采用的类型，通用控件被列举在“普通控件目录”和“扩展控件目录”中。");
		create::Head(2, "0x30 | 侧边栏控件");
		create::Text("侧边栏控件可以添加到窗口（ui::Window）、界面（ui::Page）、自由页面（ui::Free）的侧边栏管理器中。");
	});
	auto& ele_struct = create::Prepare_Page([&] {
		ui::this_page->SetInterval(ui::UnitHeight * 3);
		ui::this_page->SetUnitInterval(ui::SpaceSize * 2);
		create::Head("控件结构体系");
		create::Line();
		create::Head(2, "0x00 | GGCC-UI 基本控件体系");
		create::OrderedText("1. 系统：", "系统负责管理窗口等具有渲染和鼠标检测优先级别的控件，一般无需用户调整");
		create::OrderedText("2. 窗口：", "窗口（ui::Window）是 GGCC-UI 中模拟窗口用的特殊控件，不是真正的多窗口，属于扩展控件。窗口中可添加一个扩展控件（即可铺满整个窗口），可添加侧边栏，并管理窗口内控件的鼠标检测。主窗口（ui::mainwin）是主要使用的窗口对象，由 GUI 自动创建，一般无需调整，GGCC-UI 不推荐使用多个窗口对象，以减轻渲染负担");
		create::OrderedText("3. 页面：", "页面（ui::Page）是特殊的控件，属于扩展控件，可添加多个普通控件或一个扩展控件（即铺满整个页面），自动管理控件的布局，可添加侧边栏");
		create::OrderedText("4. 控件：", "如文本、按钮等，分为普通控件和扩展控件");
	});
	auto& create_ele = create::Prepare_Page([&] {
		ui::this_page->SetInterval(ui::UnitHeight * 3);
		ui::this_page->SetUnitInterval(ui::SpaceSize * 2);
		create::Head("如何创建控件");
		create::Line();
		create::Head(2, "0x00 | 创建控件并添加");
		create::Text("创建并添加控件是最为常用的方法，使用 create 系列函数即可创建控件。");
		create::Text("");
		create::Head(2, "0x10 | 预备控件而不添加");
		create::Head(2, "0x20 | 在循环中创建静态控件");
	});
	// todo 基本控件
	auto& head = create::Prepare_Page([&] {
		ui::this_page->SetInterval(ui::UnitHeight * 3);
		ui::this_page->SetUnitInterval(ui::SpaceSize * 2);
		create::Head("标题（ui::Head）");
		create::Line();
		create::Head(2, "0x00 | 多级标题");
		create::Text("使用 Head 可以创建一个大标题");
		create::TextBox("cpp", "create::Head(\"这是一个标题\");\n").SetCodeDefaultMode();
		create::Text("在字符串前添加一个整数参数，可以创建多级标题，一共有4级。");
		create::TextBox("cpp", "#include <ggcc/ggccui.h>\nusing namespace ggcc;\n\nint main() {\n	ui::Init();\n	create::Page([&] {\n		create::Head(1, \"这是一个一级标题\");\n		create::Head(2, \"这是一个二级标题\");\n		create::Head(3, \"这是一个三级标题\");\n		create::Head(4, \"这是一个四级标题\");\n	});\n	ui::Run();\n}\n").SetCodeDefaultMode();
		create::Button("[]运行程序").withCallback([&] {
			RunProgram([&] {
				create::Head(1, "这是一个一级标题");
				create::Head(2, "这是一个二级标题");
				create::Head(3, "这是一个三级标题");
				create::Head(4, "这是一个四级标题");
			});
		}).SetColor(DARKBLUE);
		create::Head(2, "0x10 | 成员函数");
		create::TextBox("cpp", "Head& SetSize(int size);\n").SetCodeDefaultMode();
		create::OrderedText(" 作用：", "设置标题级别大小");
		create::OrderedText(" 参数：", "");
		create::OrderedText("   size：", "表示标题的级别");
		create::OrderedText(" 返回值：", "该控件的引用");
	});
	auto& text = create::Prepare_Page([&] {
		ui::this_page->SetInterval(ui::UnitHeight * 3);
		ui::this_page->SetUnitInterval(ui::SpaceSize * 2);
		create::Head("文本（ui::Text）");
		create::Line();
		create::Head(2, "0x00 | 创建文本");
		create::TextBox("cpp", "#include <ggcc/ggccui.h>\nusing namespace ggcc;\n\nint main() {\n	ui::Init();\n	create::Page([&] {\n		create::Text(\"这是一行文本\");\n	});\n	ui::Run();\n}\n").SetCodeDefaultMode();
		create::Button("[]运行程序").withCallback([&] {
			RunProgram([&] {
				create::Text("这是一行文本");
			});
		}).SetColor(DARKBLUE);
	});
	auto& button = create::Prepare_Page([&] {
		ui::this_page->SetInterval(ui::UnitHeight * 3);
		ui::this_page->SetUnitInterval(ui::SpaceSize * 2);
		create::Head("按钮（ui::Button）");
		create::Line();
		create::Head(2, "0x00 | 创建按钮");
		create::Text("使用一个字符串表示按钮上的文本，在字符串前加上方括号可以设置按钮的图标。");
		create::TextBox("cpp", "#include <ggcc/ggccui.h>\nusing namespace ggcc;\n\nint main() {\n	ui::Init();\n	create::Page([&] {\n		create::Button(\"这是一个按钮\");\n		create::Button(\"[]这是一个带有图标的按钮\");\n	});\n	ui::Run();\n}\n").SetCodeDefaultMode();
		create::Button("[]运行程序").withCallback([&] {
			RunProgram([&] {
				create::Button("这是一个按钮");
				create::Button("[]这是一个带有图标的按钮");
			});
		}).SetColor(DARKBLUE);
		create::Head(2, "0x10 | 设置回调函数");
		create::Text("回调函数可以使用成员函数 withCallback() 设置，需要一个函数作为参数，可以使用 lambda 生成一个匿名函数。");
		create::Text("回调函数将在按钮被点击时调用。");
		create::TextBox("cpp", "#include <ggcc/ggccui.h>\nusing namespace ggcc;\n\nint main() {\n	ui::Init();\n	create::Page([&] {\n		create::Button(\"这是一个按钮\").withCallback([&] {\n			ui::message::Send(\"HELLO\");\n		});\n	});\n	ui::Run();\n}\n").SetCodeDefaultMode();
		create::Button("[]运行程序").withCallback([&] {
			RunProgram([&] {
				create::Button("这是一个按钮").withCallback([&] {
					ui::message::Send("HELLO");
				});
			});
		}).SetColor(DARKBLUE);
		create::Head(2, "0x20 | 设置按钮样式");
		create::Text("按钮可以设置高度、颜色，使用链式调用可以很方便地进行设置。");
		create::TextBox("cpp", "#include <ggcc/ggccui.h>\nusing namespace ggcc;\n\nint main() {\n	ui::Init();\n	create::Page([&] {\n		create::Button(\"这是一个按钮\")\n		.SetColor(DARKBLUE)\n		.SetButtonHeight(ui::UnitHeight * 3)\n		.withCallback([&] {\n			ui::message::Send(\"HELLO\");\n		});\n	});\n	ui::Run();\n}\n").SetCodeDefaultMode();
		create::Button("[]运行程序").withCallback([&] {
			RunProgram([&] {
				create::Button("这是一个按钮")
				.SetColor(DARKBLUE)
				.SetButtonHeight(ui::UnitHeight * 3)
				.withCallback([&] {
					ui::message::Send("HELLO");
				});
			});
		}).SetColor(DARKBLUE);
		create::Text("可以使用 SetDrawBackground() 函数取消按钮背景。");
		create::TextBox("cpp", "#include <ggcc/ggccui.h>\nusing namespace ggcc;\n\nint main() {\n	ui::Init();\n	create::Page([&] {\n		create::Button(\"这是一个按钮\")\n		.SetDrawBackground(false)\n		.withCallback([&] {\n			ui::message::Send(\"HELLO\");\n		});\n	});\n	ui::Run();\n}\n").SetCodeDefaultMode();
		create::Button("[]运行程序").withCallback([&] {
			RunProgram([&] {
				create::Button("这是一个按钮")
				.SetDrawBackground(false)
				.withCallback([&] {
					ui::message::Send("HELLO");
				});
			});
		}).SetColor(DARKBLUE);
		create::Head(2, "0x30 | 通过矩形绘制按钮");
	});
	auto& line = create::Prepare_Page([&] {
		ui::this_page->SetInterval(ui::UnitHeight * 3);
		ui::this_page->SetUnitInterval(ui::SpaceSize * 2);
		create::Head("分割线（ui::Line）");
		create::Line();
		create::Head(2, "0x00 | 创建分割线");
		create::Text("分割线是 GGCC-UI 中最简单的控件");
		create::TextBox("cpp", "#include <ggcc/ggccui.h>\nusing namespace ggcc;\n\nint main() {\n	ui::Init();\n	create::Page([&] {\n		create::Line();\n	});\n	ui::Run();\n}\n").SetCodeDefaultMode();
		create::Button("[]运行程序").withCallback([&] {
			RunProgram([&] {
				create::Line();
			});
		}).SetColor(DARKBLUE);
	});
	auto& space = create::Prepare_Page([&] {
		ui::this_page->SetInterval(ui::UnitHeight * 3);
		ui::this_page->SetUnitInterval(ui::SpaceSize * 2);
		create::Head("空格（ui::Space）");
		create::Line();
		create::Head(2, "0x00 | 创建空格");
		create::Text("空格默认占有 5 个像素（根据系统 DPI 会进行缩放）。");
		create::TextBox("cpp", "create::Space();\n").SetCodeDefaultMode();
		create::Text("增加一个整数参数，选择添加几个空格。");
		create::TextBox("cpp", "#include <ggcc/ggccui.h>\nusing namespace ggcc;\n\nint main() {\n	ui::Init();\n	create::Page([&] {\n		create::Space();\n		create::Text(\"一个空格\");\n		create::Space(2);\n		create::Text(\"二个空格\");\n		create::Space(3);\n		create::Text(\"三个空格\");\n		create::Space(4);\n		create::Text(\"四个空格\");\n		create::Space(10);\n		create::Text(\"十个空格\");\n	});\n	ui::Run();\n}\n").SetCodeDefaultMode();
		create::Button("[]运行程序").withCallback([&] {
			RunProgram([&] {
				create::Space();
				create::Text("一个空格");
				create::Space(2);
				create::Text("二个空格");
				create::Space(3);
				create::Text("三个空格");
				create::Space(4);
				create::Text("四个空格");
				create::Space(10);
				create::Text("十个空格");
			});
		}).SetColor(DARKBLUE);
	});
	bool on__;
	ui::Text text__("当前状态");
	int choose__;
	realn num;
	std::string str;
	auto& switch_ = create::Prepare_Page([&] {
		ui::this_page->SetInterval(ui::UnitHeight * 3);
		ui::this_page->SetUnitInterval(ui::SpaceSize * 2);
		create::Head("开关（ui::Switch）");
		create::Line();
		create::Head(2, "0x00 | 创建开关");
		create::Text("开关有三个参数，第一个是提示文字，第二个是初始状态，第三个是一个 bool 类型的指针，指向要更改的对象。");
		create::TextBox("cpp", "ui::Switch &Switch(std::string content, bool on = false, bool* on_ptr = nullptr)\n").SetCodeDefaultMode();
		create::Text("点击开关后，指针指向对象会改变布尔值。");
		create::TextBox("cpp", "#include <ggcc/ggccui.h>\nusing namespace ggcc;\n\nint main() {\n	ui::Init();\n	bool on;\n	ui::Text text(\"当前状态\");\n	create::Page([&] {\n		create::Switch(\"这是一个开关\", false, &on);\n		create::AddElement(&text);\n	});\n	ui::Run([&] {\n		if (on) text.content = \"当前状态：True\";\n		else text.content = \"当前状态：False\";\n	});\n}\n").SetCodeDefaultMode();
		create::Button("[]运行程序").withCallback([&] {
			RunProgram([&] {
				create::Switch("这是一个开关", false, &on__);
				create::AddElement(&text__);
				ui::this_page->withCallback([&] {
					if (on__) text__.content = "当前状态：True";
					else text__.content = "当前状态：False";
				});
			});
		}).SetColor(DARKBLUE);
	});
	auto& checkbox = create::Prepare_Page([&] {
		ui::this_page->SetInterval(ui::UnitHeight * 3);
		ui::this_page->SetUnitInterval(ui::SpaceSize * 2);
		create::Head("复选框（ui::CheckBox）");
		create::Line();
		create::Head(2, "0x00 | 创建复选框");
		create::Text("复选框与开关类似，有三个参数，第一个是提示文字，第二个是初始状态，第三个是一个 bool 类型的指针，指向要更改的对象。");
		create::TextBox("cpp", "ui::CheckBox &CheckBox(std::string content, bool on = false, bool* ptr = nullptr)\n").SetCodeDefaultMode();
		create::Text("点击勾选后，指针指向对象会改变布尔值。");
		create::TextBox("cpp", "#include <ggcc/ggccui.h>\nusing namespace ggcc;\n\nint main() {\n	ui::Init();\n	bool on;\n	ui::Text text(\"当前状态\");\n	create::Page([&] {\n		create::CheckBox(\"这是一个复选框\", false, &on);\n		create::AddElement(&text);\n	});\n	ui::Run([&] {\n		if (on) text.content = \"当前状态：True\";\n		else text.content = \"当前状态：False\";\n	});\n}\n").SetCodeDefaultMode();
		create::Button("[]运行程序").withCallback([&] {
			RunProgram([&] {
				create::CheckBox("这是一个复选框", false, &on__);
				create::AddElement(&text__);
				ui::this_page->withCallback([&] {
					if (on__) text__.content = "当前状态：True";
					else text__.content = "当前状态：False";
				});
			});
		}).SetColor(DARKBLUE);
	});
	auto& radiobox = create::Prepare_Page([&] {
		ui::this_page->SetInterval(ui::UnitHeight * 3);
		ui::this_page->SetUnitInterval(ui::SpaceSize * 2);
		create::Head("单选框（ui::RadioBox）");
		create::Line();
		create::Head(2, "0x00 | 创建单选框");
		create::Text("单选框有三个参数，第一个是字符串数组，表示选项，第二个是初始的选项编号，（编号从 0 开始），第三个是一个 int 类型的指针，指向要更改的对象，值为当前选项的编号，。");
		create::TextBox("cpp", "ui::RadioBox &RadioBox(std::vector<std::string> content, int choose = -1, int* ptr = nullptr)\n").SetCodeDefaultMode();
		create::Text("当第二个参数 choose 为 -1 时，则表示没有选择。");
		create::TextBox("cpp", "#include <ggcc/ggccui.h>\nusing namespace ggcc;\n\nint main() {\n	ui::Init();\n	int choose;\n	ui::Text text(\"当前选择\");\n	create::Page([&] {\n		create::RadioBox(\n			{\n				\"选项1\",\n				\"选项2\",\n				\"选项3\",\n			},\n			-1,	&choose\n		);\n		create::AddElement(&text);\n	});\n	ui::Run([&] {\n		text.content = \"当前选择：\" + std::to_string(choose);\n	});\n}\n").SetCodeDefaultMode();
		create::Button("[]运行程序").withCallback([&] {
			RunProgram([&] {
				create::RadioBox(
				{
					"选项1",
					"选项2",
					"选项3",
				},
				-1,	&choose__
				);
				create::AddElement(&text__);
				ui::this_page->withCallback([&] {
					text__.content = "当前选择：" + std::to_string(choose__);
				});
			});
		}).SetColor(DARKBLUE);
	});
	auto& slider_real = create::Prepare_Page([&] {
		ui::this_page->SetInterval(ui::UnitHeight * 3);
		ui::this_page->SetUnitInterval(ui::SpaceSize * 2);
		create::Head("实数滚动条（ui::Slider）");
		create::Line();
		create::Head(2, "0x00 | 创建实数滚动条");
		create::Text("滚动条有 5 个参数。");
		create::OrderedText(" content    ", "提示文本");
		create::OrderedText(" minn       ", "滚动范围的最小值");
		create::OrderedText(" maxn       ", "滚动范围的最大值");
		create::OrderedText(" now        ", "初始值");
		create::OrderedText(" *num       ", "指针，表示滚动条数值");
		create::TextBox("cpp", "ui::Slider &Slider(std::string content, realn minn, realn maxn, realn now, realn* num);\n").SetCodeDefaultMode();
		create::TextBox("cpp", "#include <ggcc/ggccui.h>\nusing namespace ggcc;\n\nint main() {\n	ui::Init();\n	realn num;\n	ui::Text text(\"当前数值\");\n	create::Page([&] {\n		create::Slider(-5, 10, 1, &num);\n		create::AddElement(&text);\n	});\n	ui::Run([&] {\n		text.content = \"当前数值：\" + std::to_string(num);\n	});\n}\n").SetCodeDefaultMode();
		create::Button("[]运行程序").withCallback([&] {
			RunProgram([&] {
				create::Slider(-5, 10, 1, &num);
				create::AddElement(&text__);
				ui::this_page->withCallback([&] {
					text__.content = "当前数值：" + std::to_string(num);
				});
			});
		}).SetColor(DARKBLUE);
	});
	auto& slider_int = create::Prepare_Page([&] {
		ui::this_page->SetInterval(ui::UnitHeight * 3);
		ui::this_page->SetUnitInterval(ui::SpaceSize * 2);
		create::Head("整数滚动条（ui::Slider_Int）");
		create::Line();
		create::Head(2, "0x00 | 创建整数滚动条");
		create::Text("滚动条有 5 个参数。");
		create::OrderedText(" content    ", "提示文本");
		create::OrderedText(" minn       ", "滚动范围的最小值");
		create::OrderedText(" maxn       ", "滚动范围的最大值");
		create::OrderedText(" now        ", "初始值");
		create::OrderedText(" *num       ", "指针，表示滚动条数值");
		create::TextBox("cpp", "ui::Slider &Slider(std::string content, realn minn, realn maxn, realn now, realn* num);\n").SetCodeDefaultMode();
		create::TextBox("cpp", "#include <ggcc/ggccui.h>\nusing namespace ggcc;\n\nint main() {\n	ui::Init();\n	realn num;\n	ui::Text text(\"当前数值\");\n	create::Page([&] {\n		create::Slider(-5, 10, 1, &num);\n		create::AddElement(&text);\n	});\n	ui::Run([&] {\n		text.content = \"当前数值：\" + std::to_string(num);\n	});\n}\n").SetCodeDefaultMode();
		create::Button("[]运行程序").withCallback([&] {
			RunProgram([&] {
				create::Slider_Int(-5, 10, 1, &choose__);
				create::AddElement(&text__);
				ui::this_page->withCallback([&] {
					text__.content = "当前数值：" + std::to_string(choose__);
				});
			});
		}).SetColor(DARKBLUE);
	});
	auto& inputbox = create::Prepare_Page([&] {
		ui::this_page->SetInterval(ui::UnitHeight * 3);
		ui::this_page->SetUnitInterval(ui::SpaceSize * 2);
		create::Head("输入框（ui::InputBox）");
		create::Line();
		create::Head(2, "0x00 | 创建输入框");
		create::Text("创建输入框只需要一个提示文本和一个目标字符串的指针。");
		create::TextBox("cpp", "#include <ggcc/ggccui.h>\nusing namespace ggcc;\n\nint main() {\n	ui::Init();\n	std::string str;\n	ui::Text text(\"你输入了\");\n	create::Page([&] {\n		create::InputBox(\"这是一个输入框，点击输入文本\", &str);\n		create::AddElement(&text);\n	});\n	ui::Run([&] {\n		text.content = \"你输入了：\" + str;\n	});\n}\n").SetCodeDefaultMode();
		create::Button("[]运行程序").withCallback([&] {
			RunProgram([&] {
				create::InputBox("这是一个输入框，点击输入文本", &str);
				create::AddElement(&text__);
				ui::this_page->withCallback([&] {
					text__.content = "你输入了：" + str;
				});
			});
		}).SetColor(DARKBLUE);
	});
	auto& choosebox = create::Prepare_Page([&] {
		ui::this_page->SetInterval(ui::UnitHeight * 3);
		ui::this_page->SetUnitInterval(ui::SpaceSize * 2);
		create::Head("选择框（ui::ChooseBox）");
		create::Line();
		create::Error("该控件尚未实现（）");
	});
	auto& warning = create::Prepare_Page([&] {
		ui::this_page->SetInterval(ui::UnitHeight * 3);
		ui::this_page->SetUnitInterval(ui::SpaceSize * 2);
		create::Head("警告框（ui::Warning）");
		create::Line();
		create::Head(2, "0x00 | 创建警告框");
		create::Text("与创建文本类似，只需提供警告内容。");
		create::TextBox("cpp", "#include <ggcc/ggccui.h>\nusing namespace ggcc;\n\nint main() {\n	ui::Init();\n	create::Page([&] {\n		create::Warning(\"这是一个警告\");\n	});\n	ui::Run();\n}\n").SetCodeDefaultMode();
		create::Button("[]运行程序").withCallback([&] {
			RunProgram([&] {
				create::Warning("这是一个警告");
			});
		}).SetColor(DARKBLUE);
	});
	auto& error = create::Prepare_Page([&] {
		ui::this_page->SetInterval(ui::UnitHeight * 3);
		ui::this_page->SetUnitInterval(ui::SpaceSize * 2);
		create::Head("错误框（ui::Error）");
		create::Line();
		create::Head(2, "0x00 | 创建错误框");
		create::Text("与创建文本类似，只需提供错误内容。");
		create::TextBox("cpp", "#include <ggcc/ggccui.h>\nusing namespace ggcc;\n\nint main() {\n	ui::Init();\n	create::Page([&] {\n		create::Error(\"这是一个警告\");\n	});\n	ui::Run();\n}\n").SetCodeDefaultMode();
		create::Button("[]运行程序").withCallback([&] {
			RunProgram([&] {
				create::Error("这是一个错误");
			});
		}).SetColor(DARKBLUE);
	});
	auto& colortext = create::Prepare_Page([&] {
		ui::this_page->SetInterval(ui::UnitHeight * 3);
		ui::this_page->SetUnitInterval(ui::SpaceSize * 2);
		create::Head("高级文本（ui::ColorText）");
		create::Line();
		create::Head(2, "0x00 | 高级文本");
		create::Text("高级文本是对普通文本功能的扩展，可以改变颜色、设置样式、检测鼠标点击等。");
		create::TextBox("cpp","#include <ggcc/ggccui.h>\nusing namespace ggcc;\n\nint main() {\n	ui::Init();\n	create::Page([&] {\n		create::ColorText(\"[]ColorTextColorTextColorTextColorTextColorTextColorTextColorTextColorTextColorTextColorTextColorTextColorText\", WHITE, BLUE)\n		.SetStrikeoutlineVisible(true)\n		.SetUnderlineVisible(true)\n		.SetSparkleEnable(true)\n		.SetClickEnable(true)\n		.SetInterval(ui::SpaceSize)\n		.withCallback([&] {\n			ui::message::Send(\"HELLO\");\n		});\n	});\n	ui::Run();\n}\n").SetCodeDefaultMode();
		create::Button("[]运行程序").withCallback([&] {
			RunProgram([&] {
				create::ColorText("[]ColorTextColorTextColorTextColorTextColorTextColorTextColorTextColorTextColorTextColorTextColorTextColorText", WHITE, BLUE)
				.SetStrikeoutlineVisible(true)
				.SetUnderlineVisible(true)
				.SetSparkleEnable(true)
				.SetClickEnable(true)
				.SetInterval(ui::SpaceSize)
				.withCallback([&] {
					ui::message::Send("HELLO");
				});
			});
		}).SetColor(DARKBLUE);
	});
	auto& loadingbar = create::Prepare_Page([&] {
		ui::this_page->SetInterval(ui::UnitHeight * 3);
		ui::this_page->SetUnitInterval(ui::SpaceSize * 2);
		create::Head("加载条（ui::LoadingBar）");
		create::Line();
		create::Head(2, "0x00 | 加载条");
	});
	auto& hyperlink = create::Prepare_Page([&] {
		ui::this_page->SetInterval(ui::UnitHeight * 3);
		ui::this_page->SetUnitInterval(ui::SpaceSize * 2);
		create::Head("超链接（ui::HyperLink）");
		create::Line();
		create::Head(2, "0x00 | 创建超链接");
		create::Text("创建超链接只需要一个提示文本和一个目标网址，网址必须使用完整的地址，即以 http:// 或 https:// 开头的地址，否则无法识别网页。");
		create::Text("与按钮类似，在提示文本字符串前加上方括号可以更改超链接的图标。");
		create::TextBox("cpp","#include <ggcc/ggccui.h>\nusing namespace ggcc;\n\nint main() {\n	ui::Init();\n	create::Page([&] {\n		create::Hyperlink(\"洛谷\", \"https://www.luogu.com.cn/\");\n		create::Hyperlink(\"[]百度\", \"https://www.baidu.com/\");\n	});\n	ui::Run();\n}\n").SetCodeDefaultMode();
		create::Button("[]运行程序").withCallback([&] {
			RunProgram([&] {
				create::Hyperlink("洛谷", "https://www.luogu.com.cn/");
				create::Hyperlink("[]百度", "https://www.baidu.com/");
			});
		}).SetColor(DARKBLUE);
		create::Head(2, "0x10 | 设置回调函数");
		create::Text("与按钮类似，回调函数可以使用成员函数 withCallback() 设置，需要一个函数作为参数，可以使用 lambda 生成一个匿名函数。");
		create::Text("回调函数将在超链接被点击时调用，如果链接的网址为空，则不会打开网页，只调用回调函数。");
		create::TextBox("cpp","#include <ggcc/ggccui.h>\nusing namespace ggcc;\n\nint main() {\n	ui::Init();\n	create::Page([&] {\n		create::Hyperlink(\"[]百度\").withCallback([&] {\n			ui::message::Send_Error(\"无法打开网页......\");\n		});\n	});\n	ui::Run();\n}\n").SetCodeDefaultMode();
		create::Button("[]运行程序").withCallback([&] {
			RunProgram([&] {
				create::Hyperlink("[]百度").withCallback([&] {
					ui::message::Send_Error("无法打开网页......");
				});
			});
		}).SetColor(DARKBLUE);
	});
	// 支持&反馈
	auto& support = create::Prepare_Page([&] {
		ui::this_page->SetInterval(ui::UnitHeight * 3);
		ui::this_page->SetUnitInterval(ui::SpaceSize * 2);
		create::Head("支持&反馈");
		create::Line();
		create::Head(2, "0x00 | 支持本项目");
		create::Head(2, "0x10 | 反馈 Bug & 提出建议");
	});

	create::sider::Navigation("CONTENT", tr).SetWidth(250 * ui::dpi)
	.withCallback([&] {
		std::string str = ui::this_navigation->GetClickNode();
		if (str == "[]关于") 			ui::this_win->ShiftTo(&about, 		ui::this_navigation->GetShiftPos());
		if (str == "[]安装&配置") 		ui::this_win->ShiftTo(&package, 	ui::this_navigation->GetShiftPos());
		if (str == "[]我的第一个应用")	ui::this_win->ShiftTo(&first_app, 	ui::this_navigation->GetShiftPos());
		if (str == "什么是控件") 			ui::this_win->ShiftTo(&what_is_ele, ui::this_navigation->GetShiftPos());
		if (str == "控件结构体系") 		ui::this_win->ShiftTo(&ele_struct, 	ui::this_navigation->GetShiftPos());
		if (str == "如何创建控件") 		ui::this_win->ShiftTo(&create_ele, 	ui::this_navigation->GetShiftPos());
		if (str == "标题（Head）")		ui::this_win->ShiftTo(&head, 		ui::this_navigation->GetShiftPos());
		if (str == "文本（Text）")		ui::this_win->ShiftTo(&text, 		ui::this_navigation->GetShiftPos());
		if (str == "按钮（Button）") 		ui::this_win->ShiftTo(&button, 		ui::this_navigation->GetShiftPos());
		if (str == "分割线（Line）") 		ui::this_win->ShiftTo(&line, 		ui::this_navigation->GetShiftPos());
		if (str == "空格（Space）") 		ui::this_win->ShiftTo(&space, 		ui::this_navigation->GetShiftPos());
		if (str == "开关（Switch）") 		ui::this_win->ShiftTo(&switch_,		ui::this_navigation->GetShiftPos());
		if (str == "复选框（CheckBox）") 	ui::this_win->ShiftTo(&checkbox,	ui::this_navigation->GetShiftPos());
		if (str == "单选框（RadioBox）") 	ui::this_win->ShiftTo(&radiobox,	ui::this_navigation->GetShiftPos());
		if (str == "实数滚动条")			ui::this_win->ShiftTo(&slider_real,	ui::this_navigation->GetShiftPos());
		if (str == "整数滚动条")			ui::this_win->ShiftTo(&slider_int,	ui::this_navigation->GetShiftPos());
		if (str == "输入框（InputBox）")	ui::this_win->ShiftTo(&inputbox,	ui::this_navigation->GetShiftPos());
		if (str == "选择框（ChooseBox）")	ui::this_win->ShiftTo(&choosebox,	ui::this_navigation->GetShiftPos());
		if (str == "警告框（Warning）")	ui::this_win->ShiftTo(&warning,		ui::this_navigation->GetShiftPos());
		if (str == "错误框（Error）")		ui::this_win->ShiftTo(&error,		ui::this_navigation->GetShiftPos());
		if (str == "高级文本（ColorText）")ui::this_win->ShiftTo(&colortext,	ui::this_navigation->GetShiftPos());
		if (str == "加载条（LoadingBar）")ui::this_win->ShiftTo(&loadingbar,	ui::this_navigation->GetShiftPos());
		if (str == "超链接（Hyperlink）")	ui::this_win->ShiftTo(&hyperlink,	ui::this_navigation->GetShiftPos());
		if (str == "[]支持&反馈") 		ui::this_win->ShiftTo(&support, 	ui::this_navigation->GetShiftPos());
	});

	ui::Run();
}
