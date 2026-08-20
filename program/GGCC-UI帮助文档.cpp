#define SUPPORT_CUSTOM_FRAME_CONTROL
#include <ggcc/ggccui.h>
using namespace ggcc;

void RunProgram(std::function <void()> fun) {
	ui::MessageBox_TopMenu(ui::winW * 0.8, ui::winH * 0.8, fun).AddButton("", "返回");
}

int main() {
	ui::EnableRaylibLog = true;
	ui::Init();
	ui::highlight::SetColorTheme("Monokai Pro");
	create::Page([&] {
		create::Head("场景 (Scene)");
		create::Warning("提示：点击 “运行程序” 按钮可以进入程序交互");
		create::Head(2, "0x10 概况");
		create::Text("GGCC-UI 开发初衷是数学和物理的可视化，而场景 (Scene) 是 GGCC-UI 的重要功能，用于方便地绘制和控制几何图形。");
		create::Head(2, "0x20 基本使用方法");
		create::Head(3, "0x21 创建场景");
		create::Text("创建场景非常简单，只需要使用 create 方法即可，create::Scene() 函数会创建一个场景控件，在不指定创建位置的情况下，将被默认创建到主窗口。其参数是一个lambda匿名函数，表示场景中绘制的内容，该函数将在每帧调用绘制，称为“场景主循环”。");
		create::Text("下面这段代码中，通过 create::Scene() 创建了一个简单的场景，并绘制了一个圆，默认颜色为粉色。");
		create::Warning("在场景中，不关闭交互的情况下，按住鼠标左键拖动可以移动视图，滚轮可以缩放。这样可以很方便调试程序。");
		create::TextBox("cpp",
		                std::string("#include <ggcc/ggccui.h>					// 引用ggccui头文件\n") +
		                std::string("using namespace ggcc;						// 使用命名空间\n") +
		                std::string("\n") +
		                std::string("int main() {\n") +
		                std::string("	ui::Init();								// 初始化GUI窗口\n") +
		                std::string("	create::Scene([&] {						// 创建一个场景GUI控件\n") +
		                std::string("		ui::plot->circle(0, 0, 1);\n") +
		                std::string("	});\n") +
		                std::string("	ui::Run();								// 运行GUI\n") +
		                std::string("}\n")
		               ).label_visible = true;
		create::IconButton("", "运行程序", [&] {
			RunProgram([&] {
				create::Scene([&] {
					ui::plot->circle(0, 0, 1);
				}).StartSetting([&] {
					ui::plot->set_position(0, 0);
					ui::plot->set_zoom(2);
				});
			});
		}).SetColor(DARKBLUE);
		create::Head(2, "0x30 绘制简单图形");
		create::Text("场景中提供了丰富的绘图函数，可以通过 ui::plot-> 方法调用绘图函数。每种图形都有三种绘图方式：");
		create::OrderedText("    默认绘图: ", "绘制图形的边框并以半透明的颜色填充。");
		create::OrderedText("    边框绘图: ", "以 _line 结尾的函数，只绘制边框。");
		create::OrderedText("    填充绘图: ", "以 _solid 结尾的函数，绘制填充图形。");
		create::Text("为了方便，有两种坐标表示方法：");
		create::OrderedText("    向量: ", "以 vector2d 表示坐标");
		create::OrderedText("    x,y : ", "以 (realn, realn) 表示坐标");
		create::Text("以下列举了主要的绘图函数：");
		create::Warning("ui::plot-> 必须在场景的主循环中使用，否则无法绘制图形，并且可能出现空指针或悬挂指针问题导致程序崩溃");
		create::TextBox("cpp",
		                std::string("// 点\n") +
		                std::string("void point(realn x, realn y, unsigned color = gc::pink);\n") +
		                std::string("void point(vector2d v, unsigned color = gc::pink);\n") +
		                std::string("// 线\n") +
		                std::string("void line(realn x1, realn y1, realn x2, realn y2, unsigned color = gc::pink);\n") +
		                std::string("void line(vector2d v1, vector2d v2, unsigned color = gc::pink);\n") +
		                std::string("// 射线\n") +
		                std::string("void ray(realn x1, realn y1, realn x2, realn y2, unsigned color = gc::pink);\n") +
		                std::string("void ray(vector2d v1, vector2d v2, unsigned color = gc::pink);\n") +
		                std::string("// 矩形\n") +
		                std::string("void rectangle_lines(realn x1, realn y1, realn x2, realn y2, unsigned color = gc::pink);\n") +
		                std::string("void rectangle(realn x1, realn y1, realn x2, realn y2, unsigned color = gc::pink);\n") +
		                std::string("void rectangle_solid(realn x1, realn y1, realn x2, realn y2, unsigned color = gc::pink);\n") +
		                std::string("void rectangle(pg::aabb rect, unsigned color = gc::pink);\n") +
		                std::string("void rectangle(vector2d v1, vector2d v2, unsigned color = gc::pink);\n") +
		                std::string("// 旋转矩形\n") +
		                std::string("void rectangle_r(vector2d pos, realn w, realn h, realn rotate, unsigned color = gc::pink);\n") +
		                std::string("void rectangle_r_solid(vector2d pos, realn w, realn h, realn rotate, unsigned color = gc::pink);\n") +
		                std::string("// 三角形\n") +
		                std::string("void triangle(vector2d p1, vector2d p2, vector2d p3, unsigned color = gc::pink);\n") +
		                std::string("void triangle_lines(vector2d p1, vector2d p2, vector2d p3, unsigned color = gc::pink);\n") +
		                std::string("void triangle_solid(vector2d p1, vector2d p2, vector2d p3, unsigned color = gc::pink);\n") +
		                std::string("void triangle(realn x1, realn y1, realn x2, realn y2, realn x3, realn y3, unsigned color = gc::pink);\n") +
		                std::string("void triangle_solid(realn x1, realn y1, realn x2, realn y2, realn x3, realn y3, unsigned color = gc::pink);\n") +
		                std::string("// 圆弧\n") +
		                std::string("void arc(realn x1, realn y1, realn x2, realn y2, realn x3, realn y3, unsigned color = gc::pink);\n") +
		                std::string("void arc(vector2d p1, vector2d p2, vector2d p3, unsigned color = gc::pink);\n") +
		                std::string("void arc(vector2d o, realn r, realn start, realn end, unsigned color = gc::pink);\n") +
		                std::string("// 圆形\n") +
		                std::string("void circle(realn x1, realn y1, realn r, unsigned color = gc::pink);\n") +
		                std::string("void circle_solid(realn x1, realn y1, realn r, unsigned color = gc::pink);\n") +
		                std::string("void circle_lines(realn x1, realn y1, realn r, unsigned color = gc::pink);\n") +
		                std::string("void circle(vector2d pos, realn r, unsigned color = gc::pink);\n") +
		                std::string("void circle_solid(vector2d pos, realn r, unsigned color = gc::pink).\n") +
		                std::string("void circle_lines(vector2d pos, realn r, unsigned color = gc::pink);\n") +
		                std::string("// 多边形\n") +
		                std::string("void polygon(std::vector <vector2d> pos, unsigned color = gc::pink);\n") +
		                std::string("void polygon_lines(std::vector <vector2d> pos, unsigned color = gc::pink);\n") +
		                std::string("void polygon_solid(std::vector <vector2d> pos, unsigned color = gc::pink);\n") +
		                std::string("// 圆角多边形\n") +
		                std::string("void round_polygon(std::vector <vector2d> pos, realn r, unsigned color = gc::pink);\n") +
		                std::string("void round_polygon_lines(std::vector <vector2d> pos, realn r, unsigned color = gc::pink);\n") +
		                std::string("void round_polygon_solid(std::vector <vector2d> pos, realn r, unsigned color = gc::pink);\n") +
		                std::string("// 胶囊形\n") +
		                std::string("void capsule(vector2d p1, vector2d p2, realn r, unsigned color = gc::pink);\n") +
		                std::string("void capsule_lines(vector2d p1, vector2d p2, realn r, unsigned color = gc::pink);\n") +
		                std::string("void capsule_solid(vector2d p1, vector2d p2, realn r, unsigned color = gc::pink);\n") +
		                std::string("// 椭圆\n") +
		                std::string("void ellipse(vector2d pos, realn a, realn b, realn rotate = 0, unsigned color = gc::pink);\n") +
		                std::string("void ellipse_lines(vector2d pos, realn a, realn b, realn rotate = 0, unsigned color = gc::pink);\n") +
		                std::string("void ellipse_solid(vector2d pos, realn a, realn b, realn rotate = 0, unsigned color = gc::pink);\n") +
		                std::string("// 向量\n") +
		                std::string("void vector(realn x1, realn y1, realn x2, realn y2, unsigned color = gc::pink);\n") +
		                std::string("void vector(realn x, realn y, unsigned color = gc::pink);\n") +
		                std::string("void vector(vector2d v, unsigned color = gc::pink);\n") +
		                std::string("void vector(vector2d v1, vector2d v2, unsigned color = gc::pink);\n") +
		                std::string("// 箭头\n") +
		                std::string("void arrow(vector2d pos, vector2d dir, unsigned color = gc::pink);\n") +
		                std::string("void arrow(realn x, realn y, realn dx, realn dy, unsigned color = gc::pink);\n")
		               ).label_visible = true;
		create::Head(2, "0x40 绘制文本");
		create::Text("使用 ui::plot->text() 可以绘制文本，文本以所给坐标为中心，居中绘制，文字大小不随缩放改变，颜色默认为粉色。");
		create::TextBox("cpp",
			std::string("#include <ggcc/ggccui.h>\n") +
			std::string("using namespace ggcc;\n") +
			std::string("\n") +
			std::string("int main() {\n") +
			std::string("	ui::Init();\n") +
			std::string("	create::Scene([&] {\n") +
			std::string("		ui::plot->text(0, 1, \"你好世界\");\n") +
			std::string("		ui::plot->text(0, 2, \"你好世界\", gc::blue);\n") +
			std::string("	});\n") +
			std::string("	ui::Run();\n") +
			std::string("}\n")
			).label_visible = true;
		create::IconButton("", "运行程序", [&] {
			RunProgram([&] {
				create::Scene([&] {
					ui::plot->text(0, 1, "你好世界");
					ui::plot->text(0, 2, "你好世界", gc::blue);
				}).StartSetting([&] {
					ui::plot->set_position(0, 0);
					ui::plot->set_zoom(2);
				});
			});
		}).SetColor(DARKBLUE);
		create::Text("也可以使用向量表示坐标。");
		create::TextBox("cpp",
			std::string("#include <ggcc/ggccui.h>\n") +
			std::string("using namespace ggcc;\n") +
			std::string("\n") +
			std::string("int main() {\n") +
			std::string("	ui::Init();\n") +
			std::string("	create::Scene([&] {\n") +
			std::string("		ui::plot->text(vector2d(0, 1), \"你好世界\");\n") +
			std::string("	});\n") +
			std::string("	ui::Run();\n") +
			std::string("}\n")
			).label_visible = true;
		create::IconButton("", "运行程序", [&] {
			RunProgram([&] {
				create::Scene([&] {
					ui::plot->text(vector2d(0, 1), "你好世界");
				}).StartSetting([&] {
					ui::plot->set_position(0, 0);
					ui::plot->set_zoom(2);
				});
			});
		}).SetColor(DARKBLUE);
		create::Text("使用 ui::plot->raylib_text 可以绘制 raylib 风格的字体，文本同样居中，可以调节文字大小，字体大小 size 以坐标系中的单位长度为准。下面的示例程序中，绘制了两个字高为 2 个单位长度的字符串。");
		create::TextBox("cpp",
			std::string("#include <ggcc/ggccui.h>\n")+
			std::string("using namespace ggcc;\n")+
			std::string("\n")+
			std::string("int main() {\n")+
			std::string("	ui::Init();\n")+
			std::string("	create::Scene([&] {\n")+
			std::string("		ui::plot->raylib_text(0, 1, \"Hello\", 2);\n")+
			std::string("		ui::plot->raylib_text(vector2d(0, 3), \"Hello\", 2, gc::blue);\n")+
			std::string("	});\n")+
			std::string("	ui::Run();\n")+
			std::string("}\n")
			).label_visible = true;
		create::IconButton("", "运行程序", [&] {
			RunProgram([&] {
				create::Scene([&] {
					ui::plot->raylib_text(0, 1, "Hello", 2);
					ui::plot->raylib_text(vector2d(0, 3), "Hello", 2, gc::blue);
				}).StartSetting([&] {
					ui::plot->set_position(0, 0);
					ui::plot->set_zoom(2);
				});
			});
		}).SetColor(DARKBLUE);
		create::Head(2, "0x50 交互");
	}).SetInterval(ui::UnitHeight * 4).SetUnitInterval(ui::SpaceSize * 4).SetBlank(0.5);
	ui::Run();
}
