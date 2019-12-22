#include <Windows.h>
#include "WinBox.h"
#include <stdio.h>

void ErrBox(const char* tmp) {
	MessageBox(NULL,
		TEXT(tmp),
		TEXT("ERROR"), 
		MB_OK | MB_ICONINFORMATION);
}

void FormatErrBox(const char* _format, ...) {

	char messageSize[256];
	char* message = messageSize;
	va_list ap;

	va_start(ap, _format);
	vsnprintf(message, 255, _format, ap);
	va_end(ap);

	MessageBox(NULL,
		TEXT(message),
		TEXT("ERROR"),
		MB_OK | MB_ICONINFORMATION);
}

void ReportBox(const char* tmp) {
	MessageBox(NULL,
		TEXT(tmp),
		TEXT("REPORT"),
		MB_OK);
}
