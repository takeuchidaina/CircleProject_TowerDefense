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

�L�[���͏��̍X�V

************************************************/
void cKeyboard::Update() {

	char nowKeyState[KEY_NUM];
	GetHitKeyStateAll(nowKeyState);

	// �L�[�̉�����Ă�����擾
	for (int i = 0; i < KEY_NUM; i++) {
		if (nowKeyState[i] != 0) {				//i�Ԃ̃L�[��������Ă�����
			if (m_keyReleaseCnt[i] > 0) {		//������J�E���^��0���傫�����
				m_keyReleaseCnt[i] = 0;			//0�ɖ߂�
			}
			m_keyPressCnt[i]++;					//������J�E���^�𑝂₷
		}
		else {									//i�Ԃ̃L�[��������Ă�����
			if (m_keyPressCnt[i] > 0) {			//������J�E���^��0���傫�����
				m_keyPressCnt[i] = 0;			//0�ɖ߂�
			}
			m_keyReleaseCnt[i]++;				//������J�E���^�𑝂₷
		}
	}
}

/************************************************

�f�o�b�O�����̕\��

************************************************/
void cKeyboard::Draw() {

#ifdef KEYBOARD_DEBUG
	
#endif // DEBUG

}

/************************************************

�����̃L�[��������Ă���t���[������Ԃ�

************************************************/
int cKeyboard::GetPressCnt(int _keyCode) {
	if (!IsAvailableCode(_keyCode)) {
		return -1;
	}
	return m_keyPressCnt[_keyCode];
}

/************************************************

�����̃L�[��������Ă���t���[������Ԃ�

************************************************/
int cKeyboard::GetReleaseCnt(int _keyCode) {
	if (!IsAvailableCode(_keyCode)) {
		return -1;
	}
	return m_keyReleaseCnt[_keyCode];
}

/************************************************

�e�֐��̈������L���Ȓl���m�F����

************************************************/
bool cKeyboard::IsAvailableCode(int _keyCode) {
	if (!(0 <= _keyCode && _keyCode < KEY_NUM)) {
		return FALSE;
	}
	return TRUE;
}