#include <ggcc/ggccui.h>
using namespace ggcc;

std::string trim(std::string text) {
	int i, j;
	for (i = 0; text[i] == ' '; i++); 
	for (j = text.size() - 1; text[j] == ' ' || text[j] == '\r'; j--);
	return text.substr(i, j - i + 1);
}
// 提取表格中的文本
std::vector<std::vector<std::string>> extractTableText(const std::vector<std::string>& lines) {
	std::vector<std::vector<std::string>> table;
	std::vector<std::string> row;
	bool inTable = false;
	for (const auto& line : lines) {
		// 检查是否是表格的开始
		if (line.find("|") != std::string::npos && line.find("----") != std::string::npos) {
			inTable = true;
			continue;
		}
		// 提取表格的行
		std::stringstream ss(line);
		std::string cell;
		ss.get();
		while (std::getline(ss, cell, '|')) row.push_back(trim(cell));
		// 将提取的行添加到表格中
		table.push_back(row);
		row.clear();
	}
	return table;
}

int main() {
	ui::Init();
	ui::MultiInputBox box;
	ui::Page page;
	box.statebar_visible = true;
	ui::highlight::SetColorTheme("Monokai Pro");
	create::Layout(ui::split_row, &box, &page);
	create::sider::TopMenu().AddButton("刷新").withCallback([&] {
		page.ClearKey();
		std::string str = box.CopyAll();
		std::stringstream ss(str);
		std::string op, content;
		page.SetInterval(ui::UnitHeight * 4);
		page.SetUnitInterval(ui::SpaceSize * 4);
		create::Begin(&page, [&] {
			while (ss >> op) {
				if (op == "#") std::getline(ss, content), create::Head(1, trim(content));
				else if (op == "##") std::getline(ss, content), create::Head(2, trim(content));
				else if (op == "###") std::getline(ss, content), create::Head(3, trim(content));
				else if (op == "####") std::getline(ss, content), create::Head(4, trim(content));
				else if (op == "#####") std::getline(ss, content), create::Head(5, trim(content));
				else if (op == "-") {
					std::getline(ss, content);
					content = trim(content);
					if (content[0] == '[' && content[1] == ' ' && content[2] == ']') 
						create::OrderedText("", content.substr(3));
					else if (content[0] == '[' && content[1] == 'X' && content[2] == ']') 
						create::OrderedText("", content.substr(3));
					else create::OrderedText("", content);
				}
				else if (op == "----") std::getline(ss, content), create::Line();
				else if (op[0] == '`' && op[1] == '`' && op[2] == '`') {
					std::string temp;
					while (std::getline(ss, content)) {
						if (content == "\r") continue;
						if (trim(content) == "```") break;
						temp += trim(content) + "\n";
					}
					create::TextBox(op.substr(3), temp).label_visible = true;
				}
				else if (op == "|") {
					std::vector<std::string> table;
					for(int i = 0; ;i++) {
						if (i) {
							ss >> op;
							if (op != "|") break;
						}
						std::getline(ss, content);
						if (content.size() <= 2) break;
						table.push_back("| " + trim(content));
					}
					create::Table(extractTableText(table));
				}
				else std::getline(ss, content), create::Text(trim(op + " " + content));
			}
		});
	});
	ui::Run();
}
