#include <ggcc/ggccui.h>
using namespace ggcc;

int main() {
	tree_node <std::string> tr;
	tr.set("[]root");
	tr.child(0).set("[]child0");
	tr.child(1).set("child1");
	tr.child(2).set("child2");
	tr.child(3).set("child3");
	tr.child(4).set("child4");
	tr.child(5).set("[]child5");
	tr.child(6).set("child6");
	tr.child(7).set("child7");
	tr.child(8).set("child8");
	tr.child(9).set("child9");
	tr.child(10).set("child10");
	tr.child(11).set("child11");
	tr.child(12).set("child12");
	tr.child(13).set("child13");
	tr.child(5).child(0).set("123");
	tr.child(5).child(1).set("123");
	tr.child(5).child(2).set("123");
	tr.child(5).child(2).child(0).set("hello");
	tr.child(5).child(3).set("123");
	
	ui::Init();
	ui::MenuColor = ui::ColorF(34, 38, 42);
	ui::highlight::SetColorTheme("Mariana");
	create::sider::Navigation(tr);
	create::MultiInputBox().SetCodeDefaultMode();
	ui::Run();
}
