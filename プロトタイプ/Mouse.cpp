#include "Mouse.h"

cMouse::cMouse(){
	x = 0;
	y = 0;
	//buttonPressCnt[KEY_NUM] = { 0 };
	//buttonReleaseCnt[KEY_NUM] = { 0 };
}

cMouse::~cMouse(){
	//
}

void cMouse::Update() {

	int nowButtonState = GetMouseInput();

	GetMousePoint(&x, &y);

	for (int i = 0; i < KEY_NUM; i++) {
		if ((nowButtonState >> i) & 1) {        //i�Ԃ̃{�^����������Ă�����
			if (buttonReleaseCnt[i] > 0) {		//������J�E���^��0���傫�����
				buttonReleaseCnt[i] = 0;		//0�ɖ߂�
			}
			buttonPressCnt[i]++;				//������J�E���^�𑝂₷
		}
		else {									//i�Ԃ̃L�[��������Ă�����
			if (buttonPressCnt[i] > 0) {		//������J�E���^��0���傫�����
				buttonPressCnt[i] = 0;			//0�ɖ߂�
			}
			buttonReleaseCnt[i]++;				//������J�E���^�𑝂₷
		}
	}
}

//keyCode�̃L�[��������Ă���t���[������Ԃ�
int cMouse::GetPressCnt(int keyCode) {
	if (!isAvailableCode(keyCode)) {
		return -1;
	}
	return buttonPressCnt[keyCode];
}

//keyCode�̃L�[��������Ă���t���[������Ԃ�
int cMouse::GetReleaseCnt(int keyCode) {
	if (!isAvailableCode(keyCode)) {
		return -1;
	}
	return buttonReleaseCnt[keyCode];
}

//keyCode���L���Ȓl���`�F�b�N����
bool cMouse::isAvailableCode(int keyCode) {
	if (!(0 <= keyCode && keyCode < KEY_NUM)) {
		return false;
	}
	return true;
}

void cMouse::Draw() {

#ifdef MOUSE_DEBUG
	DrawFormatString(0, 0, WH, "%d,%d", x, y);
	DrawFormatString(0, 20, WH, "%d %d",
		buttonPressCnt[LEFT_CLICK], buttonPressCnt[RIGHT_CLICK]);
#endif // DEBUG

}