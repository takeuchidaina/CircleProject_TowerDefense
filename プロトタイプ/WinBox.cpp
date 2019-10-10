#include <Windows.h>
#include "WinBox.h"

void ErrBox(const char* tmp) {
	MessageBox(
		NULL,
		TEXT(tmp),
		TEXT("エラー"),
		MB_OK | MB_ICONWARNING);
}

void ReportBox(const char* tmp) {
	MessageBox(
		NULL,
		TEXT(tmp),
		TEXT("報告"),
		MB_OK | MB_ICONINFORMATION);
}
