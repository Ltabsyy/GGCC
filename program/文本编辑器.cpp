#include <ggcc/ggccui.h>
using namespace ggcc;
using namespace std;

int i1=ui::StartAni=false;
int i2=ui::Init(1500, 1000,1);
ui::MultiInputBox box,console_box;
ui::Interface console;

bool run = false;
bool finished = false;
bool close = false;
string op = "";
string system_op = "";
string file_name = "test\\test";

string link;

void thr() {
	while (!close) {
		if (run) {
			console_box.input_pos = console_box.InsertBack("编译单个文件...\n");
			console_box.input_pos = console_box.InsertBack("[#] 命令: " + op + "\n");
			if (FileExists("test\\test.exe"))system("del test\\test.exe");
			system((op + " > test\\note.txt 2>&1").c_str());
			if (FileExists("test\\test.exe"))system("start test\\command.exe");
			run = false;
			finished = true;
			ifstream fr;
			string str;
			fr.open("test\\note.txt");
			bool flag = false;
			while (getline(fr, str)) {
				if (!flag)console_box.input_pos = console_box.InsertBack("----------------------------------[Output]----------------------------------\n"), flag = true;
				console_box.input_pos = console_box.InsertBack(str + "\n");
			}
			fr.close();
			if (FileExists("test\\test.exe"))console_box.input_pos = console_box.InsertBack("[#] 编译成功\n");
			else console_box.input_pos = console_box.InsertBack("----------------------------------[Output]----------------------------------\n[#] 编译失败\n");
			console_box.input_pos = console_box.InsertBack(">>> ");
			op = "";
		}
		if (op != "") {
			string str = "";
			system((op + " > note.txt 2>&1").c_str());
			if (FileExists("test\\note.txt"))system("del test\\note.txt");
			system("PowerShell -Command \"& {get-content note.txt | set-content test\\note.txt -encoding utf8}\"");
			ifstream fr;
			fr.open("test\\note.txt");
			while (getline(fr, str))console_box.input_pos = console_box.Insert(console_box.input_pos, str + "\n");
			fr.close();
			console_box.input_pos = console_box.InsertBack(">>> ");
			op = "";
		}
	}
}

int main() {
	ui::highlight::SetColorTheme("Monokai Pro");
	box.text="Input a text.";
	box.label_visible=true;
	box.minimap_visible=true;	
	box.color_scheme_enable = true;
	box.statebar_visible = true;
	box.shadow_visible = false;
	box.tabline_visible = true;
	ui::mainintf.Add(&box);
	
	std::thread thread_(thr);
	
	ui::Pulldown menu1,menu11,menu12,menu2,menu21,menu211,menu22,menu221,menu3,menu4,menu41,menu5,menu6,menu61,menu7;
	ui::Pulldown menu8,menu9,menuA,menuB;
	
	menu1.AddMenu("新建",&menu11); {
		menu11.AddButton("","新建C/C++文件");
		menu11.AddButton("","新建GUN汇编文件");
		menu11.AddButton("","新建文本文件");
		menu11.AddButton("","新建项目");
		menu11.AddLine();
		menu11.AddButton("  ","新建模板");
		menu11.AddLine();
		menu11.AddButton("  ","新建类");
		menu11.AddButton("  ","新建头文件");
	}
	menu1.AddButton("","打开");
	menu1.AddButton("","选择工作文件夹");
	menu1.AddLine();
	menu1.AddButton("","保存");
	menu1.AddButton("","另存为");
	menu1.AddButton("","全部保存");
	menu1.AddLine();
	menu1.AddButton("","关闭");
	menu1.AddButton("","关闭项目");
	menu1.AddButton("","全部关闭");
	menu1.AddLine();
	menu1.AddMenu("导出",&menu12); {
		menu12.AddButton("  ","导出为RTF");
		menu12.AddButton("  ","导出为HTML");
	}
	menu1.AddButton("","打印");
	menu1.AddLine();
	menu1.AddButton("  ","项目历史");
	menu1.AddButton("  ","文件历史");
	menu1.AddLine();
	menu1.AddButton("  ","退出");
	
	menu2.AddButton("","撤销");
	menu2.AddButton("","重做");
	menu2.AddLine();
	menu2.AddButton("","剪切");
	menu2.AddButton("","复制");
	menu2.AddButton("","粘贴");
	menu2.AddLine();
	menu2.AddButton("","缩进");
	menu2.AddButton("","取消缩进");
	menu2.AddLine();
	menu2.AddButton("  ","切换注释");
	menu2.AddButton("  ","切换块注释");
	menu2.AddLine();
	menu2.AddMenu("文件编码",&menu21); {
		menu21.AddButton("  ","自动检测");
		menu21.AddRadioBox({
			"使用ANSI编码",
			"使用UTF-8编码",
			"使用UTF-8 BOM编码"
		},0);
		menu21.AddMenu("字符集",&menu211); {
			menu211.AddMenu("Unicode",nullptr);
			menu211.AddMenu("东欧语系",nullptr);
			menu211.AddMenu("中文",nullptr);
			menu211.AddMenu("中欧语系",nullptr);
			menu211.AddMenu("凯尔特语",nullptr);
			menu211.AddMenu("土耳其语系",nullptr);
			menu211.AddMenu("巴尔干语系",nullptr);
			menu211.AddMenu("希伯来语系",nullptr);
			menu211.AddMenu("希腊语系",nullptr);
			menu211.AddMenu("日语",nullptr);
			menu211.AddMenu("汉语",nullptr);
			menu211.AddMenu("泰语",nullptr);
			menu211.AddMenu("西欧语系",nullptr);
			menu211.AddMenu("西里尔语系",nullptr);
			menu211.AddMenu("越南语",nullptr);
			menu211.AddMenu("阿拉伯语",nullptr);
		}
		menu21.AddLine();
		menu21.AddButton("  ","转换为ANSI编码");
		menu21.AddButton("  ","转换为UTF-8编码");
		menu21.AddButton("  ","转换为UTF-8 BOM编码");
		menu21.AddButton("  ","转换为GBK编码");
		menu21.AddButton("  ","转换为GBK 18030编码");
	}
	menu2.AddLine();
	menu2.AddButton("  ","全部收起");
	menu2.AddButton("  ","全部展开");
	menu2.AddLine();
	menu2.AddMenu("移动光标",&menu22); {
		menu22.AddButton("  ","向上翻页");
		menu22.AddButton("  ","向下翻页");
		menu22.AddButton("  ","跳转到行首");
		menu22.AddButton("  ","跳转到行尾");
		menu22.AddButton("  ","跳转到文件开头");
		menu22.AddButton("  ","跳转到文件结尾");
		menu22.AddButton("  ","页首");
		menu22.AddButton("  ","尾首");
	}
	menu2.AddLine();
	menu2.AddButton("  ","删除当前行");
	menu2.AddButton("  ","复制当前行");
	menu2.AddButton("  ","删除当前单词");
	menu2.AddButton("  ","删除到单词开头");
	menu2.AddButton("  ","删除到单词结尾");
	menu2.AddButton("  ","删除到行首");
	menu2.AddButton("  ","删除到行尾");
	menu2.AddLine();
	menu2.AddButton("  ","切换到只读模式");
	
	menu3.AddButton("  ","选择全部");
	menu3.AddButton("  ","选择当前单词");
	menu3.AddLine();
	menu3.AddButton("  ","向上移动选中的行");
	menu3.AddButton("  ","向下移动选中的行");
	menu3.AddLine();
	menu3.AddButton("  ","向上翻页并选中");
	menu3.AddButton("  ","向下翻页并选中");
	menu3.AddButton("  ","跳转到页首并选中");
	menu3.AddButton("  ","跳转到页尾并选中");
	menu3.AddButton("  ","跳转到行首并选中");
	menu3.AddButton("  ","跳转到文件开头并选中");
	menu3.AddButton("  ","跳转到文件结尾并选中");
	
	menu4.AddCheckBox("显示全部工具面板",true);
	menu4.AddMenu("工具面板",&menu41); {
		menu41.AddCheckBox("项目",true);
		menu41.AddCheckBox("监视",true);
		menu41.AddCheckBox("结构",true);
		menu41.AddCheckBox("文件",true);
		menu41.AddCheckBox("试题集",true);
		menu41.AddLine();
		menu41.AddCheckBox("编译器",true);
		menu41.AddCheckBox("工具输出",true);
		menu41.AddCheckBox("调试",true);
		menu41.AddCheckBox("查找",true);
		menu41.AddCheckBox("TODO",true);
		menu41.AddCheckBox("书签",true);
		menu41.AddCheckBox("试题",true);
	}
	menu4.AddCheckBox("状态栏",true);
	menu4.AddLine();
	menu4.AddButton("  ","切换管理器面板");
	menu4.AddButton("  ","切换消息面板");
	
	menu5.AddButton("","查找...");
	menu5.AddButton("","在文件中查找...");
	menu5.AddButton("","替换");
	menu5.AddLine();
	menu5.AddButton("  ","查找上一个");
	menu5.AddButton("  ","查找前一个");
	
	menu6.AddButton("","前一次编辑位置");
	menu6.AddButton("","后一次编辑位置");
	menu6.AddLine();
	menu6.AddButton("  ","匹配当前括号");
	menu6.AddButton("  ","跳转到行...");
	menu6.AddButton("  ","跳转到代码段开始");
	menu6.AddButton("  ","跳转到代码段结束");
	menu6.AddButton("  ","代码补全");
	menu6.AddLine();
	menu6.AddButton(" ","切换书签");
	menu6.AddButton("  ","修改书签说明");
	menu6.AddLine();
	menu6.AddMenu("插入代码段",&menu61); {
		menu61.AddButton("  ","Comment Header");
		menu61.AddButton("  ","Date/Time");
	}
	menu6.AddLine();
	menu6.AddButton("  ","删除行尾空格");
	menu6.AddLine();
	menu6.AddButton("","对代码重新排版");
	
	menu7.AddButton("  ","重命名符号");
	
	menu8.AddButton("","编译");
	menu8.AddButton("","运行");
	menu8.AddButton("","全部重编译");
	menu8.AddButton("  ","生成汇编");
	menu8.AddLine();
	menu8.AddButton("","运行参数...");
	menu8.AddButton("","编译器选项...");
	menu8.AddLine();
	menu8.AddButton("","调试");
	menu8.AddButton("","单步跨过");
	menu8.AddButton("","单步进入");
	menu8.AddButton(" ","单步跳出");
	menu8.AddButton("","执行到光标处");
	menu8.AddButton("","继续执行");
	menu8.AddButton("","停止执行");
	menu8.AddLine();
	menu8.AddButton("","添加监视");
	menu8.AddButton("  ","添加变量断点");
	menu8.AddButton("  ","打开CPU信息窗口...");
	
	menu9.AddButton("","选项");
	menu9.AddLine();
	menu9.AddButton("  ","删除编译文件");
	
	menuA.AddButton("","全部关闭");
	menuA.AddButton("","关闭");
	menuA.AddButton("","最大化编辑器");
	menuA.AddLine();
	menuA.AddButton("  ","移动到其他试图");
	menuA.AddButton("","下一窗口");
	menuA.AddButton("","前一窗口");
	
	menuB.AddButton("  ","使用说明");
	menuB.AddButton("  ","C参考手册");
	menuB.AddButton("  ","C++参考手册");
	menuB.AddLine();
	menuB.AddButton("  ","OI Wiki");
	menuB.AddButton("  ","Raylib教程");
	menuB.AddButton("  ","EGE图形库手册");
	menuB.AddButton("  ","海龟作图教程");
	menuB.AddButton("  ","GGCC-UI教程");
	menuB.AddLine();
	menuB.AddButton("  ","GUN汇编手册");
	menuB.AddButton("  ","X86汇编语言参考手册");
	menuB.AddLine();
	menuB.AddButton("  ","官方网站");
	menuB.AddButton("  ","反馈与建议");
	menuB.AddButton("","关于");
	
	add::sider::TopMenuButton()
		.SetHeight(ui::UnitHeight*1.5)
		.AddButton("文件").withMenu(&menu1)
		.AddButton("编辑").withMenu(&menu2)
		.AddButton("选择").withMenu(&menu3)
		.AddButton("视图").withMenu(&menu4)
		.AddButton("查找").withMenu(&menu5)
		.AddButton("代码").withMenu(&menu6)
		.AddButton("重构").withMenu(&menu7)
		.AddButton("运行").withMenu(&menu8)
		.AddButton("工具").withMenu(&menu9)
		.AddButton("窗口").withMenu(&menuA)
		.AddButton("帮助").withMenu(&menuB);
	
	add::sider::TopMenuButton()
		.SetHeight(ui::UnitHeight*1.5)
		.AddButton("","新建").withCallback([]() {
			box.input_pos = box.Clear();
		})
		.AddButton("","保存").withCallback([]() {
			box.Export(file_name+".cpp");
		})
		.AddButton("","另存为").withCallback([]() {
			box.Export(file_name+".cpp");
		})
		.AddButton("","运行").withCallback([]() {
			box.Export(file_name+".cpp");
			ui::mainwin.layout.Split(ui::split_col,&ui::mainintf,&console);
			ui::mainwin.layout.split = 1.0*(ui::winH - ui::UnitHeight*10)/ui::winH;
			finished = false;
			run = true;
			op = "g++ \"" + file_name + ".cpp\" -o \"" + file_name + ".exe\" " + link;
		});
	
	add::Begin(&console, []() {
		console.Add(&console_box);
		console_box.input_pos = console_box.InsertBack("GGCC Studio [版本 6.0.0]\n(c) GGCC Studio 保留所有权\n\n");
		add::sider::BottomMenu()
		.SetHeight(ui::UnitHeight*1.7)
		.AddButton("程序已提交运行，点击关闭控制台",ui::MixColor(ui::ColorF(255,100,100),ui::BgColor,0.5))
		.withCallback([]() {
			ui::mainwin.layout.Split(ui::split_main,&ui::mainintf);
		});
	});
	
	ui::MenuColor = ui::highlight::GetBgColor();
	ui::BgColor = ui::highlight::GetBgColor();
	ui::DrawSpecialEffect = false;
	
	ui::Run([]() {
		SetWindowTitle((file_name+" - Text Editor").c_str());
		if (run)ui::special_effect::DrawLoadingCircle(ui::winW / 2, ui::winH / 2, ui::UnitHeight * 2, "Compiling...");
		else if (op != "")ui::special_effect::DrawLoadingLine(console.X, console.Y, console.W);
		if (finished)finished = false;
	});
	
	close = true;
	thread_.join();
}
