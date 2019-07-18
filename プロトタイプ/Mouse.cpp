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
		if ((nowButtonState >> i) & 1) {        //i番のボタンが押されていたら
			if (buttonReleaseCnt[i] > 0) {		//離されカウンタが0より大きければ
				buttonReleaseCnt[i] = 0;		//0に戻す
			}
			buttonPressCnt[i]++;				//押されカウンタを増やす
		}
		else {									//i番のキーが離されていたら
			if (buttonPressCnt[i] > 0) {		//押されカウンタが0より大きければ
				buttonPressCnt[i] = 0;			//0に戻す
			}
			buttonReleaseCnt[i]++;				//離されカウンタを増やす
		}
	}
}

//keyCodeのキーが押されているフレーム数を返す
int cMouse::GetPressCnt(int keyCode) {
	if (!isAvailableCode(keyCode)) {
		return -1;
	}
	return buttonPressCnt[keyCode];
}

//keyCodeのキーが離されているフレーム数を返す
int cMouse::GetReleaseCnt(int keyCode) {
	if (!isAvailableCode(keyCode)) {
		return -1;
	}
	return buttonReleaseCnt[keyCode];
}

//keyCodeが有効な値かチェックする
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