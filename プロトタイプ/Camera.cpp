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
	MOUSE_WHEEL_INIT;			//マウスホイールの値の初期化
	m_wheeled = MOUSE_WHEEL;	//マウスホイール量の代入

#ifdef CAMERA_DEBUG
	GrHandle = LoadGraph("../resource/img/sample.png");
#endif // CAMERA_DEBUG


}

void cCamera::Update() {

	// カメラを正射影に変更
	// 拡大縮小
	SetupCamera_Ortho(m_zoom);		//値でカメラの距離が変わる(z軸)

	//TODO:マウスの値依存なのでマウスホイールの値7以上が使えず改善が必要
	//拡大
	if (m_wheeled < MOUSE_WHEEL) {
		m_zoom -= ZOOM_SCALE;
		m_wheeled = MOUSE_WHEEL;
	}
	//縮小
	else if (m_wheeled > MOUSE_WHEEL) {
		m_zoom += ZOOM_SCALE;
		m_wheeled = MOUSE_WHEEL;
	}

	//移動制御 カメラ座標の変化とそれに伴い注視点を一緒に移動 → 回転がしない
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

	//カメラの座標、注視点を更新
	SetCameraPositionAndTarget_UpVecY(m_camera.pos, m_camera.target);
}

void cCamera::Draw() {

#ifdef CAMERA_DEBUG
	//3D用の画像表示
	DrawBillboard3D(VGet(120.0f, 240.0f, 100.0f), 0.5f, 0.5f, 120.0f, 0.0f, GrHandle, TRUE);

	//謎の三角形
	DrawTriangle3D(
		VGet(100.0f, 100.0f, 0.0f),
		VGet(500.0f, 400.0f, 0.0f),
		VGet(600.0f, 100.0f, 100.0f), GetColor(255, 255, 255), TRUE);
#endif // CAMERA_DEBUG

}

void cCamera::End() {

	DeleteGraph(GrHandle);

}