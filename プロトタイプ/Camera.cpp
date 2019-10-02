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

	m_zoom = 1000.0;
	ModelHandle = MV1LoadModel("SimpleModel.mqo");
	GrHandle = LoadGraph("../resource/img/sample.png");

}

void cCamera::Update() {
	// �J�����𐳎ˉe�ɕύX
	// �g��k��
	SetupCamera_Ortho(m_zoom);		//�l�ŃJ�����̋������ς��(z��)

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

	//�J�����̎��_�A�����_��ݒ肷��
	SetCameraPositionAndTarget_UpVecY(m_camera.pos, m_camera.target);
}

void cCamera::Draw() {

	DrawBillboard3D(VGet(120.0f, 240.0f, 100.0f), 0.5f, 0.5f, 120.0f, 0.0f, GrHandle, TRUE);
	DrawTriangle3D(
		VGet(100.0f, 100.0f, 0.0f),
		VGet(500.0f, 400.0f, 0.0f),
		VGet(600.0f, 100.0f, 100.0f), GetColor(255, 255, 255), TRUE);
}

void cCamera::End() {

	DeleteGraph(GrHandle);

}