#include <Windows.h>
#include "WinBox.h"

void ErrBox(const char* tmp) {
	MessageBox(
		NULL,
		TEXT(tmp),
		TEXT("�G���["),
		MB_OK | MB_ICONWARNING);
}

void ReportBox(const char* tmp) {
	MessageBox(
		NULL,
		TEXT(tmp),
		TEXT("��"),
		MB_OK | MB_ICONINFORMATION);
}

int InterfaceYesNoBox() {
	int flag;
	flag = MessageBox(
		NULL,
		TEXT("�Q�[���p�b�h�ő��삵�܂����H"),
		TEXT("����ݒ�"),
		MB_YESNO | MB_ICONQUESTION);
	return flag;
}