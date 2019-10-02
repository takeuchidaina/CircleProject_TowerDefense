#include "Camera.h"

cCamera::cCamera()
{
	Init();
}

cCamera::~cCamera()
{
}

void cCamera::Init() {

	m_speed.x = 10.0;
	m_speed.y = 10.0;
	m_speed.z = 0.0;

	m_camera.pos.x = 0.0;
	m_camera.pos.y = 0.0;
	m_camera.pos.z = -800.0;

	m_camera.target.x = 0.0;
	m_camera.target.y = 0.0;
	m_camera.target.z = 0.0;

	m_zoom = ZOOM_LIMIT_UP;
	MOUSE_WHEEL_INIT;			//�}�E�X�z�C�[���̒l�̏�����
	m_wheeled = MOUSE_WHEEL;	//�}�E�X�z�C�[���ʂ̑��

#ifdef CAMERA_DEBUG
	GrHandle = LoadGraph("../resource/img/sample.png");
#endif // CAMERA_DEBUG


}

void cCamera::Update() {

	// �J�����𐳎ˉe�ɕύX
	// �g��k��
	SetupCamera_Ortho(m_zoom);		//�l�ŃJ�����̋������ς��(z��)

	//TODO:�}�E�X�̒l�ˑ��Ȃ̂Ń}�E�X�z�C�[���̒l7�ȏオ�g�������P���K�v
	//�g��
	if (m_wheeled < MOUSE_WHEEL) {
		m_zoom -= ZOOM_SCALE;
		m_wheeled = MOUSE_WHEEL;
	}
	//�k��
	else if (m_wheeled > MOUSE_WHEEL) {
		m_zoom += ZOOM_SCALE;
		m_wheeled = MOUSE_WHEEL;
	}

	//�ړ����� �J�������W�̕ω��Ƃ���ɔ��������_���ꏏ�Ɉړ� �� ��]�����Ȃ�
	if (GET_KEY_PRESS(KEY_INPUT_W) > 0) {
		m_camera.pos.y -= m_speed.y;
		m_camera.target.y -= m_speed.y;
	}
	if (GET_KEY_PRESS(KEY_INPUT_A) > 0) {
		m_camera.pos.x += m_speed.x;
		m_camera.target.x += m_speed.x;
	}
	if (GET_KEY_PRESS(KEY_INPUT_S) > 0) {
		m_camera.pos.y += m_speed.y;
		m_camera.target.y += m_speed.y;
	}
	if (GET_KEY_PRESS(KEY_INPUT_D) > 0) {
		m_camera.pos.x -= m_speed.x;
		m_camera.target.x -= m_speed.x;
	}

	//�J�����̍��W�A�����_���X�V
	SetCameraPositionAndTarget_UpVecY(m_camera.pos, m_camera.target);
}

void cCamera::Draw() {

#ifdef CAMERA_DEBUG
	//3D�p�̉摜�\��
	DrawBillboard3D(VGet(120.0f, 240.0f, 100.0f), 0.5f, 0.5f, 120.0f, 0.0f, GrHandle, TRUE);

	//��̎O�p�`
	DrawTriangle3D(
		VGet(100.0f, 100.0f, 0.0f),
		VGet(500.0f, 400.0f, 0.0f),
		VGet(600.0f, 100.0f, 100.0f), GetColor(255, 255, 255), TRUE);
#endif // CAMERA_DEBUG

}

void cCamera::End() {

	DeleteGraph(GrHandle);

}