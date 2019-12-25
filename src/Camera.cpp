#include "Camera.h"

cCamera::cCamera(){
	Init();
}

cCamera::~cCamera(){
	End();
}

void cCamera::Init() {

	//���W�E�����_
	m_camera.pos = VGet(0.0f,0.0f,-800.0f);
	m_camera.target = VGet(0.0f, 0.0f, 0.0f);

	//�g��k��
	MOUSE_WHEEL_INIT;			//�}�E�X�z�C�[���̉񂵂��񐔒l��������
	m_wheeled = MOUSE_WHEEL;	//�}�E�X�z�C�[���̉񂵂��񐔂��擾
	m_zoom = ZOOM_LIMIT_UP;		//�J��������Ԉ�������Ԃ�
	m_zoomCnt = 0;

	//�ړ�
	m_wheelPosX = MOUSE_X;
	m_wheelPosY = MOUSE_Y;
	m_wheelClick = FALSE;

	//2D�^�p����ׁA���ˉe�ɕύX
	SetupCamera_Ortho(m_zoom);
}

void cCamera::Update() {

	//�g��k��
	//CameraScale();

	//�ړ�
	CameraMove();

	//�J�����̍��W�A�����_���X�V
	SetCameraPositionAndTarget_UpVecY(m_camera.pos, m_camera.target);
}

//�g��k�����s��
void cCamera::CameraScale() {

	//�g��
	if (m_wheeled < MOUSE_WHEEL) {

		//�z�C�[���ɂ���Ċg�嗦��ω�
		if (m_zoom > ZOOM_LIMIT_DOWN) {
			m_zoom -= ZOOM_SCALE;
			m_zoomCnt++;
		}

		m_wheeled = MOUSE_WHEEL;
		SetupCamera_Ortho(m_zoom);		//�J�����̋�����ύX
	}
	//�k��
	else if (m_wheeled > MOUSE_WHEEL) {

		//�z�C�[���ɂ���Ċg�嗦��ω�
		if (m_zoom < ZOOM_LIMIT_UP) {
			m_zoom += ZOOM_SCALE;
			m_zoomCnt--;
		}

		m_wheeled = MOUSE_WHEEL;
		SetupCamera_Ortho(m_zoom);		//�J�����̋�����ύX

		//�g�債����Ԃňړ����k��������Ɣw�i�ł͂Ȃ����̂��f���Ă��܂��ׁA�ړ�
		if (m_zoomCnt != -1) {
			CameraMoveX(-(ZOOM_SCALE - ZOOM_ADJUSTMENT));
			CameraMoveX((ZOOM_SCALE - ZOOM_ADJUSTMENT));	//�J�����𒆉��Ɋ񂹂�
		}
	}
}

//�ړ��ʂ��v�Z
void cCamera::CameraMove() {

	//�z�C�[���������ꂽ�n�_���L�^
	if (MOUSE_PRESS(MIDDLE_CLICK) == 1 && m_wheelClick == FALSE) {
		m_wheelClick = TRUE;
		m_wheelPosX = MOUSE_X;
		m_wheelPosY = MOUSE_Y;
	}
	//�z�C�[���������ꂽ�n�_�����ꂽ�n�_�̍��W�����Ɉړ�
	else if (MOUSE_PRESS(MIDDLE_CLICK) == 0 && m_wheelClick == TRUE) {
		CameraMoveX(m_wheelPosX - MOUSE_X);
		CameraMoveY(-(m_wheelPosY - MOUSE_Y));
		m_wheelClick = FALSE;
	}
}

//�J�����̈ړ�����
void cCamera::CameraDrawControl() {

	//��
	if (m_camera.pos.x < 0.0f - ((ZOOM_SCALE - ZOOM_ADJUSTMENT) * (float)m_zoomCnt)) {
		m_camera.pos.x = 0.0f - ((ZOOM_SCALE - ZOOM_ADJUSTMENT) * (float)m_zoomCnt);
		m_camera.target.x = m_camera.pos.x;
	}
	//�E
	else if (m_camera.pos.x > 0.0f + ((ZOOM_SCALE - ZOOM_ADJUSTMENT) * (float)m_zoomCnt)) {
		m_camera.pos.x = 0.0f + ((ZOOM_SCALE - ZOOM_ADJUSTMENT) * (float)m_zoomCnt);
		m_camera.target.x = m_camera.pos.x;
	}
	//��
	if (m_camera.pos.y > 0.0f + ((ZOOM_SCALE / 2.0f) * (float)m_zoomCnt)) {
		m_camera.pos.y = 0.0f + ((ZOOM_SCALE / 2.0f) * (float)m_zoomCnt);
		m_camera.target.y = m_camera.pos.y;
	}
	//��
	else if (m_camera.pos.y < 0.0f - ((ZOOM_SCALE / 2.0f) * (float)m_zoomCnt)) {
		m_camera.pos.y = 0.0f - ((ZOOM_SCALE / 2.0f) * (float)m_zoomCnt);
		m_camera.target.y = m_camera.pos.y;
	}
}

//�ړ�
void cCamera::CameraMoveX(float _moveAmount) {
	m_camera.target.x += _moveAmount;
	m_camera.pos.x = m_camera.target.x;

	CameraDrawControl();	//�J�������w�i���z���Ă���Ȃ�z���Ȃ��悤�ɍ��W�𒲐�
}
void cCamera::CameraMoveY(float _moveAmount) {
	m_camera.target.y += _moveAmount;
	m_camera.pos.y = m_camera.target.y;

	CameraDrawControl();	//�J�������w�i���z���Ă���Ȃ�z���Ȃ��悤�ɍ��W�𒲐�
}

void cCamera::Draw() {

#ifdef CAMERA_DEBUG

	// �R�c�̐�����`�悷��
	DrawLine3D(
		VGet(0, 0, 0),// VECTOR Pos1
		VGet(100, 0, 0),// VECTOR Pos2
		0xff0000// unsigned int Color
	);
	DrawLine3D(
		VGet(0, 0, 0),// VECTOR Pos1
		VGet(0, 100, 0),// VECTOR Pos2
		0x00ff00// unsigned int Color
	);
	DrawLine3D(
		VGet(0, 0, 0),// VECTOR Pos1
		VGet(0, 0, -100),// VECTOR Pos2
		0x0000ff// unsigned int Color
	);
#endif // CAMERA_DEBUG

}

void cCamera::End() {

}