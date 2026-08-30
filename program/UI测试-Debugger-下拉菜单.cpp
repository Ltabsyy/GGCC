#include <ggcc/ggccui.h>
using namespace ggcc;


int main() {
	ui::Init();
	ui::Pulldown pull, pull1, pull2;
	pull.AddButton("[]按钮111111111");
	pull.AddButton("[  ]按钮22222");
	pull.AddButton("[  ]按钮2");
	pull.AddLine();
	pull.AddCheckBox("复选框1");
	pull.AddCheckBox("复选框2");
	pull.AddCheckBox("复选框3");
	pull.AddLine();
	pull.AddRadioBox({"选项1", "选项2", "选项3"});
	pull.AddLine();
	pull.AddMenu("嵌套菜单", &pull1);
	{
		pull1.AddButton("按钮1111");
		pull1.AddButton("按钮2222");
		pull1.AddButton("按钮3333");
		pull1.AddMenu("嵌套菜单", &pull2);
		{
			pull2.AddCheckBox("复选框1");
			pull2.AddCheckBox("复选框2");
			pull2.AddCheckBox("复选框3");
		}
		pull1.AddButton("按钮4444");
	}

	create::sider::TopMenu().AddButton("菜单1").withMenu(&pull);

	ui::Run();
}
