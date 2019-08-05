#include "Mouse.h"

// �R���X�g���N�^
cMouse::cMouse(){
	m_x = 0;
	m_y = 0;
	m_wheel = 0;
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

	GetMousePoint(&m_x, &m_y);

	for (int i = 0; i < KEY_NUM; i++) {
		if ((nowButtonState >> i) & 1) {        //i�Ԃ̃{�^����������Ă�����
			if (m_buttonReleaseCnt[i] > 0) {		//������J�E���^��0���傫�����
				m_buttonReleaseCnt[i] = 0;		//0�ɖ߂�
			}
			m_buttonPressCnt[i]++;				//������J�E���^�𑝂₷
		}
		else {									//i�Ԃ̃L�[��������Ă�����
			if (m_buttonPressCnt[i] > 0) {		//������J�E���^��0���傫�����
				m_buttonPressCnt[i] = 0;			//0�ɖ߂�
			}
			m_buttonReleaseCnt[i]++;				//������J�E���^�𑝂₷
		}
	}

	/*�z�C�[��*/
	m_wheel += GetMouseWheelRotVol();

}

/************************************************

�f�o�b�O�����̕\��

************************************************/
void cMouse::Draw() {

#ifdef MOUSE_DEBUG
	// �}�E�X�̍��W�̕\��
	DrawFormatString(1150, 660, WH, "x:%d y:%d", m_x, m_y);
	// �N���b�N����Ă���J�E���g�̕\��
	DrawFormatString(1150, 680, WH, "��:%d �E:%d",
		m_buttonPressCnt[LEFT_CLICK], m_buttonPressCnt[RIGHT_CLICK]);
	// ��]�ʂ�\��
	DrawFormatString(1150, 700, GetColor(255, 255, 255), "�z�C�[��:%d", m_wheel);
#endif // DEBUG

}

#pragma region Get�֐�
/************************************************

�����̃L�[��������Ă���t���[������Ԃ�

************************************************/
int cMouse::GetPressCnt(int _keyCode) {
	if (!IsAvailableCode(_keyCode)) {
		return -1;
	}
	return m_buttonPressCnt[_keyCode];
}

/************************************************

�����̃L�[��������Ă���t���[������Ԃ�

************************************************/
int cMouse::GetReleaseCnt(int _keyCode) {
	if (!IsAvailableCode(_keyCode)) {
		return -1;
	}
	return m_buttonReleaseCnt[_keyCode];
}
/************************************************

�}�E�X��x���W��Ԃ�

************************************************/
int cMouse::GetX() {
	return m_x;
}
/************************************************

�}�E�X��y���W��Ԃ�

************************************************/
int cMouse::GetY() {
	return m_y;
}
/************************************************

�}�E�X�̃z�C�[���ʂ�Ԃ�

************************************************/
int cMouse::GetWheel() {
	return m_wheel;
}

#pragma endregion

#pragma region Set�֐�

/************************************************

�}�E�X�J�[�\���̍��W���Z�b�g����

************************************************/
void cMouse::SetMousePoint(int _x,int _y) {
	m_x = _x;
	m_y = _y;
}
/************************************************

�}�E�X�̃z�C�[���ʂ�����������

************************************************/
void cMouse::InitMouseWheel() {
	m_wheel = 0;
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