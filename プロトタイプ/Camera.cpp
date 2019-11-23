#include "Camera.h"

cCamera::cCamera()
{
	Init();
}

cCamera::~cCamera()
{
	End();
}

void cCamera::Init() {

	//�J�����̍��W�E�����_
	m_camera.pos.x = 0.0;
	m_camera.pos.y = 0.0;
	m_camera.pos.z = -800.0;
	m_camera.target.x = 0.0;
	m_camera.target.y = 0.0;
	m_camera.target.z = 0.0;

	//�g��k��
	MOUSE_WHEEL_INIT;
	m_wheeled = MOUSE_WHEEL;
	m_zoom = ZOOM_LIMIT_UP;
	m_zoomCnt = 0;

	//�ړ�
	m_wheelPosX = MOUSE_X;
	m_wheelPosY = MOUSE_Y;
	m_wheelClick = FALSE;

	// �J�����𐳎ˉe�ɕύX
	SetupCamera_Ortho(m_zoom);
}

void cCamera::Update() {

	// �g��k��
	CameraScale();

	// �ړ�
	CameraMove();

	// �J�����̍��W�A�����_���X�V
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
	}
}

//�ړ�
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

	if (m_camera.pos.x <= 0.0 + (ZOOM_SCALE * m_zoomCnt)) {
		m_camera.pos.x = 0.0 + (ZOOM_SCALE * m_zoomCnt);
		m_camera.target.x = m_camera.pos.x;
	}
	if (m_camera.pos.y >= 0.0 - (ZOOM_SCALE * m_zoomCnt)) {
		m_camera.pos.y = 0.0 - (ZOOM_SCALE * m_zoomCnt);
		m_camera.target.y = m_camera.pos.y;
	}
	if (m_camera.pos.x <= WINDOW_WIDTH + (ZOOM_SCALE * m_zoomCnt)) {
		m_camera.pos.x = WINDOW_WIDTH + (ZOOM_SCALE * m_zoomCnt);
		m_camera.target.x = m_camera.pos.x;
	}
	if (m_camera.pos.y <= WINDOW_HEIGHT - (ZOOM_SCALE * m_zoomCnt)) {
		m_camera.pos.y = WINDOW_HEIGHT - (ZOOM_SCALE * m_zoomCnt);
		m_camera.target.y = m_camera.pos.y;
	}

}

void cCamera::CameraMoveX(double _moveAmount) {
	m_camera.target.x += _moveAmount;
	m_camera.pos.x = m_camera.target.x;
}

void cCamera::CameraMoveY(double _moveAmount) {
	m_camera.target.y += _moveAmount;
	m_camera.pos.y = m_camera.target.y;
}

void cCamera::Draw() {

#ifdef CAMERA_DEBUG
	DrawFormatString(300, 360, BL, "m_zoomCnt : %d", m_zoomCnt);

	//���W�\��
	DrawFormatString(300, 300, BL, "target x:%d y:%d\n pos x:%d y:%d", m_camera.target.x, m_camera.target.y, m_camera.pos.x, m_camera.pos.y);
	DrawCircle(m_camera.target.x, m_camera.target.y, 10, RD, TRUE);
	DrawCircle(m_camera.pos.x, m_camera.pos.y, 10, BL, FALSE);

	//��ʃt���[��
	DrawLine3D(VGet(-640.0f, -360.0f, m_camera.target.z), VGet(640.0f, -360.0f, m_camera.target.z), GetColor(255, 255, 255));
	DrawLine3D(VGet(-640.0f, -360.0f, m_camera.target.z), VGet(-640.0f, 360.0f, m_camera.target.z), GetColor(255, 255, 255));
	DrawLine3D(VGet(640.0f, 360.0f, m_camera.target.z), VGet(-640.0f, 360.0f, m_camera.target.z), GetColor(255, 255, 255));
	DrawLine3D(VGet(640.0f, 360.0f, m_camera.target.z), VGet(640.0f, -360.0f, m_camera.target.z), GetColor(255, 255, 255));

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