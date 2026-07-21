// to_utf8.h
// ggcc编码转换库

#ifndef GGCC_TO_UTF8_H
#define GGCC_TO_UTF8_H

namespace to_utf8 {
	std::string GetChar(int a) {
		string str="";
		if(a<128)str+=char(a);
		else if(a<4096) {
			str+=char(a/64+192);
			str+=char(a%64+128);
		} else {
			str+=char(a/4096+224);
			str+=char(a%4096/64+128);
			str+=char(a%64+128);
		}
		return str;
	}
}

#endif
