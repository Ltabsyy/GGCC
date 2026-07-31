#include <ggcc/ggccui.h>
using namespace ggcc;
using namespace std;

//int i1=ui::StartAni=false;
int i2=ui::Init(1500, 1000,1);
ui::MultiInputBox a;
ui::Interface f;

int main() {
	a.text="Input a text.";
	a.label_visible=true;
	a.minimap_visible=true;			// 小地图
	a.statebar_visible=true;		// 状态栏
	a.tabline_visible=true;			// 缩进提示线			
	a.color_scheme_enable = true;	// 代码高亮
	f.Add(&a);
	ui::mainwin.layout.intf=&f;
	ui::Run();
}
