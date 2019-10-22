#include "Camera.h"

cCamera::cCamera()
{
	Init();
}

cCamera::~cCamera()
{
}

void cCamera::Init() {

	m_camera.pos.x = 0.0;
	m_camera.pos.y = 0.0;
	m_camera.pos.z = -800.0;

	m_camera.target.x = 0.0;
	m_camera.target.y = 0.0;
	m_camera.target.z = 0.0;

	m_zoom = ZOOM_LIMIT_UP;
	MOUSE_WHEEL_INIT;			//マウスホイールの値の初期化
	m_wheeled = MOUSE_WHEEL;	//マウスホイール量の代入

	m_wheelPosX = MOUSE_X;
	m_wheelPosY = MOUSE_Y;

#ifdef CAMERA_DEBUG
	GrHandle = LoadGraph("../resource/img/sample.png");
#endif // CAMERA_DEBUG


}

void cCamera::Update() {

	// カメラを正射影に変更
	// 拡大縮小
	SetupCamera_Ortho(m_zoom);		//値でカメラの距離が変わる(z軸)

	//拡大
	if (m_wheeled < MOUSE_WHEEL) {

		//ホイールによって拡大率を変化
		if (m_zoom > ZOOM_LIMIT_DOWN ) {
			m_zoom -= ZOOM_SCALE;
		}
		m_wheeled = MOUSE_WHEEL;

		//カメラの座標・注視点を変化
		m_camera.pos.x += m_camera.target.x - MOUSE_X;
		m_camera.pos.y += m_camera.target.y - MOUSE_Y;
		m_camera.target.x -= m_camera.target.x - MOUSE_X;
		m_camera.target.y -= m_camera.target.y - MOUSE_Y;
	}
	//縮小
	else if (m_wheeled > MOUSE_WHEEL) {

		//ホイールによって拡大率を変化
		if (m_zoom < ZOOM_LIMIT_UP) {
			m_zoom += ZOOM_SCALE;
		}
		m_wheeled = MOUSE_WHEEL;

		//カメラの座標・注視点を変化
		m_camera.pos.x += m_camera.target.x - MOUSE_X;
		m_camera.pos.y += m_camera.target.y - MOUSE_Y;
		m_camera.target.x -= m_camera.target.x - MOUSE_X;
		m_camera.target.y -= m_camera.target.y - MOUSE_Y;
	}

	//移動
	if (MOUSE_PRESS(MIDDLE_CLICK) == 1 && m_wheelClick == FALSE) {
		m_wheelClick = TRUE;
		m_wheelPosX = MOUSE_X;
		m_wheelPosY = MOUSE_Y;
	}
	else if (MOUSE_PRESS(MIDDLE_CLICK) == 0 && m_wheelClick == TRUE) {
		m_wheelClick = FALSE;

		//クリックが押された地点離された地点の座標を元に移動
		m_camera.pos.x += m_wheelPosX - MOUSE_X;
		m_camera.target.x += m_wheelPosX - MOUSE_X;
		m_camera.pos.y -= m_wheelPosY - MOUSE_Y;
		m_camera.target.y -= m_wheelPosY - MOUSE_Y;
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

	//座標表示
	DrawFormatString(300,300,WH,"target x:%d y:%d\n pos x:%d y:%d", m_camera.target.x, m_camera.target.y, m_camera.pos.x, m_camera.pos.y);
	DrawCircle(m_camera.target.x, m_camera.target.y, 10, RD, TRUE);
	DrawCircle(m_camera.pos.x, m_camera.pos.y, 10, BL, FALSE);

	//画面フレーム
	DrawLine3D(VGet(-640.0f, -360.0f, m_camera.target.z), VGet(640.0f, -360.0f, m_camera.target.z), GetColor(255, 255, 255));
	DrawLine3D(VGet(-640.0f, -360.0f, m_camera.target.z), VGet(-640.0f, 360.0f, m_camera.target.z), GetColor(255, 255, 255));
	DrawLine3D(VGet(640.0f, 360.0f, m_camera.target.z), VGet(-640.0f, 360.0f, m_camera.target.z), GetColor(255, 255, 255));
	DrawLine3D(VGet(640.0f, 360.0f, m_camera.target.z), VGet(640.0f, -360.0f, m_camera.target.z), GetColor(255, 255, 255));
#endif // CAMERA_DEBUG

}

void cCamera::End() {

	DeleteGraph(GrHandle);

}