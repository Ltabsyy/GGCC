#include "ggcc/ggccui.h"
using namespace ggcc;
using namespace std;

//int i1=ui::StartAni=false;
int i2=ui::Init(1500, 1000,1);
ui::MultiInputBox a;
ui::Interface f;

int main() {
//	a.color_scheme_enable=true;
	a.text="Input a text.";
	a.label_visible=true;
	a.background_color=ui::ColorF(40,44,52);		// 设置背景色
	a.minimap_visible=true;							// 小地图
	a.color_scheme_enable = true;
	f.Add(&a);
	ui::mainwin.layout.intf=&f;
	ui::Run();
}
