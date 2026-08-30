#include <ggcc/ggccui.h>
using namespace ggcc;

int main() {
	ui::Init();
	ui::MultiInputBox box;
	ui::mainwin.Set(&box);
	ui::highlight::SetColorTheme("Monokai Pro");
	create::sider::TopMenu().AddButton("转换").withCallback([&] {
		std::string ans = "create::TextBox(\"cpp\",\"";
		for (int i = 0; i < box.input.size(); i++) {
			std::string str = "";
			for (int j = 0; j < box.input[i].size(); j++) {
				if (box.input[i][j] == '\\') str += "\\\\";
				else if (box.input[i][j] == '\'') str += "\\\'";
				else if (box.input[i][j] == '\"') str += "\\\"";
				else str += box.input[i][j];
			}
			ans += "" + str + "\\n";
		}
		ans += "\").SetCodeDefaultMode();";
		box.Clear();
		box.InsertBack(ans);
	});
	ui::Run();
}
