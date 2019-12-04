#include "Keyboard.h"

cKeyboard::cKeyboard()
{
	//
}

cKeyboard::~cKeyboard()
{
	//
}

/************************************************

キー入力情報の更新

************************************************/
void cKeyboard::Update() {

	char nowKeyState[KEY_NUM];
	GetHitKeyStateAll(nowKeyState);

	// キーの押されている情報取得
	for (int i = 0; i < KEY_NUM; i++) {
		if (nowKeyState[i] != 0) {				//i番のキーが押されていたら
			if (m_keyReleaseCnt[i] > 0) {		//離されカウンタが0より大きければ
				m_keyReleaseCnt[i] = 0;			//0に戻す
			}
			m_keyPressCnt[i]++;					//押されカウンタを増やす
		}
		else {									//i番のキーが離されていたら
			if (m_keyPressCnt[i] > 0) {			//押されカウンタが0より大きければ
				m_keyPressCnt[i] = 0;			//0に戻す
			}
			m_keyReleaseCnt[i]++;				//離されカウンタを増やす
		}
	}
}

/************************************************

デバッグ文字の表示

************************************************/
void cKeyboard::Draw() {

#ifdef KEYBOARD_DEBUG
	
#endif // DEBUG

}

/************************************************

引数のキーが押されているフレーム数を返す

************************************************/
int cKeyboard::GetPressCnt(int _keyCode) {
	if (!IsAvailableCode(_keyCode)) {
		return -1;
	}
	return m_keyPressCnt[_keyCode];
}

/************************************************

引数のキーが離されているフレーム数を返す

************************************************/
int cKeyboard::GetReleaseCnt(int _keyCode) {
	if (!IsAvailableCode(_keyCode)) {
		return -1;
	}
	return m_keyReleaseCnt[_keyCode];
}

/************************************************

各関数の引数が有効な値か確認する

************************************************/
bool cKeyboard::IsAvailableCode(int _keyCode) {
	if (!(0 <= _keyCode && _keyCode < KEY_NUM)) {
		return FALSE;
	}
	return TRUE;
}