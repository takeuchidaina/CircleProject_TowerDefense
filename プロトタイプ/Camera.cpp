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

	ModelHandle = MV1LoadModel("SimpleModel.mqo");
	GrHandle = LoadGraph("../resource/img/sample.png");

}

void cCamera::Update() {
	// カメラを正射影に変更
	SetupCamera_Ortho(1000.0f);		//値でカメラの距離が変わる(z軸)

	//移動制御
	if (GET_KEY_PRESS(KEY_INPUT_W) > 0) {
		m_camera.pos.y += m_speed.y;
	}
	if (GET_KEY_PRESS(KEY_INPUT_A) > 0) {
		m_camera.pos.x -= m_speed.x;
	}
	if (GET_KEY_PRESS(KEY_INPUT_S) > 0) {
		m_camera.pos.y -= m_speed.y;
	}
	if (GET_KEY_PRESS(KEY_INPUT_D) > 0) {
		m_camera.pos.x += m_speed.x;
	}

	//拡大縮小制御
	if (MOUSE_PRESS(LEFT_CLICK) > 0){
		m_camera.scale.x += 0.1f;
	}
	if (MOUSE_PRESS(RIGHT_CLICK) > 0) {
		m_camera.scale.y += 0.1f;
	}

	//カメラの視点、注視点を設定する( 上方向はＹ軸から算出 )
	//https://dxlib.xsrv.jp/function/dxfunc_3d_camera.html#R12N2
	SetCameraPositionAndTarget_UpVecY(m_camera.pos, VGet(0.0f, 0.0f, 0.0f));
}

void cCamera::Draw() {
	MV1DrawModel(ModelHandle);
	DrawBillboard3D(VGet(120.0f, 240.0f, 100.0f), 0.5f, 0.5f, 120.0f, 0.0f, GrHandle, TRUE);
	DrawTriangle3D(
		VGet(100.0f, 100.0f, 0.0f),
		VGet(500.0f, 400.0f, 0.0f),
		VGet(600.0f, 100.0f, 100.0f), GetColor(255, 255, 255), TRUE);
}

void cCamera::End() {
	MV1DeleteModel(ModelHandle);
	DeleteGraph(GrHandle);
}