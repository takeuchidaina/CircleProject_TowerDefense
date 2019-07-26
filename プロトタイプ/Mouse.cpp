#include "Mouse.h"

// �R���X�g���N�^
cMouse::cMouse(){
	x = 0;
	y = 0;
	wheel = 0;
	//buttonPressCnt[KEY_NUM] = { 0 };
	//buttonReleaseCnt[KEY_NUM] = { 0 };
}

// �f�X�g���N�^
cMouse::~cMouse(){
	//
}

/************************************************

�N���b�N��h���b�O�A�z�C�[�����̍X�V

************************************************/
void cMouse::Update() {

	/*�N���b�N*/
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

	/*�z�C�[��*/
	wheel += GetMouseWheelRotVol();

}

#pragma region Get�֐�
/************************************************

�����̃L�[��������Ă���t���[������Ԃ�

************************************************/
int cMouse::GetPressCnt(int _keyCode) {
	if (!IsAvailableCode(_keyCode)) {
		return -1;
	}
	return buttonPressCnt[_keyCode];
}

/************************************************

�����̃L�[��������Ă���t���[������Ԃ�

************************************************/
int cMouse::GetReleaseCnt(int _keyCode) {
	if (!IsAvailableCode(_keyCode)) {
		return -1;
	}
	return buttonReleaseCnt[_keyCode];
}
/************************************************

�}�E�X��x���W��Ԃ�

************************************************/
int cMouse::GetX() {
	return x;
}
/************************************************

�}�E�X��y���W��Ԃ�

************************************************/
int cMouse::GetY() {
	return y;
}
/************************************************

�}�E�X�̃z�C�[���ʂ�Ԃ�

************************************************/
int cMouse::GetWheel() {
	return wheel;
}

#pragma endregion

#pragma region Set�֐�

/************************************************

�}�E�X�J�[�\���̍��W���Z�b�g����

************************************************/
void cMouse::SetMousePoint(int _x,int _y) {
	x = _x;
	y = _y;
}
/************************************************

�}�E�X�̃z�C�[���ʂ�����������

************************************************/
void cMouse::InitMouseWheel() {
	wheel = 0;
}
/************************************************

�}�E�X�J�[�\���̍��W���Z�b�g����

************************************************/
void cMouse::SetMouseDisplay(bool _isDisplay) {
	SetMouseDispFlag(_isDisplay);
}


#pragma endregion

/************************************************

�e�֐��̈������L���Ȓl���m�F����

************************************************/
bool cMouse::IsAvailableCode(int _keyCode) {
	if (!(0 <= _keyCode && _keyCode < KEY_NUM)) {
		return FALSE;
	}
	return TRUE;
}

/************************************************

�f�o�b�O�����̕\��

************************************************/
void cMouse::Draw() {

#ifdef MOUSE_DEBUG
	// �}�E�X�̍��W�̕\��
	DrawFormatString(1150, 660, WH, "x:%d y:%d", x, y);
	// �N���b�N����Ă���J�E���g�̕\��
	DrawFormatString(1150, 680, WH, "��:%d �E:%d",
		buttonPressCnt[LEFT_CLICK], buttonPressCnt[RIGHT_CLICK]);
	// ��]�ʂ�\��
	DrawFormatString(1150, 700, GetColor(255, 255, 255), "�z�C�[��:%d", wheel);
#endif // DEBUG

}