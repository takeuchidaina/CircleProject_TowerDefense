#include <Windows.h>
#include "WinBox.h"

void ErrBox(const char* tmp) {
	MessageBox(NULL,
		TEXT(tmp),
		TEXT("ERROR"), 
		MB_OK | MB_ICONINFORMATION);
}

void ReportBox(const char* tmp) {
	MessageBox(NULL,
		TEXT(tmp),
		TEXT("REPORT"),
		MB_OK);
}
