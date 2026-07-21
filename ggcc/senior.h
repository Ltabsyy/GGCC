// senior.h
// ggcc高级功能库

#ifndef __GGCCSENIOR_H__
#define __GGCCSENIOR_H__

#include <bits/stdc++.h>
#include <windows.h>

namespace ggcc {

	// 剪切板

	// 复制数据至剪切板
	BOOL CopyToClipboard(const char* pszData, const int nDataLen) {
		if(::OpenClipboard(NULL)) {
			::EmptyClipboard();
			HGLOBAL clipbuffer;
			char *buffer;
			clipbuffer = ::GlobalAlloc(GMEM_DDESHARE, nDataLen+1);

			buffer = (char *)::GlobalLock(clipbuffer);
			strcpy(buffer, pszData);
			::GlobalUnlock(clipbuffer);
			::SetClipboardData(CF_TEXT, clipbuffer);
			HANDLE SetClipboardData(
			    UINT uFormat,
			    HANDLE hMem
			);
			::CloseClipboard();
			return TRUE;
		}
		return FALSE;
	}

	// 从剪切板中取得数据
	BOOL GetTextFromClipboard() {
		if(::OpenClipboard(NULL)) {
			HGLOBAL hMem = GetClipboardData(CF_TEXT);
			if(NULL != hMem) {
				char* lpStr = (char*)::GlobalLock(hMem);
				if(NULL != lpStr) {
					::GlobalUnlock(hMem);
				}
			}
			::CloseClipboard();
			return TRUE;
		}
		return FALSE;
	}

}

#endif
