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

	//カメラの座標・注視点
	m_camera.pos.x = 0.0;
	m_camera.pos.y = 0.0;
	m_camera.pos.z = -800.0;
	m_camera.target.x = 0.0;
	m_camera.target.y = 0.0;
	m_camera.target.z = 0.0;

	//拡大縮小
	MOUSE_WHEEL_INIT;
	m_wheeled = MOUSE_WHEEL;
	m_zoom = ZOOM_LIMIT_UP;
	m_zoomCnt = 0;

	//移動
	m_wheelPosX = MOUSE_X;
	m_wheelPosY = MOUSE_Y;
	m_wheelClick = FALSE;

	// カメラを正射影に変更
	SetupCamera_Ortho(m_zoom);
}

void cCamera::Update() {

	// 拡大縮小
	CameraScale();

	// 移動
	CameraMove();

	// カメラの座標、注視点を更新
	SetCameraPositionAndTarget_UpVecY(m_camera.pos, m_camera.target);
}

//拡大縮小を行う
void cCamera::CameraScale() {

	//拡大
	if (m_wheeled < MOUSE_WHEEL) {

		//ホイールによって拡大率を変化
		if (m_zoom > ZOOM_LIMIT_DOWN) {
			m_zoom -= ZOOM_SCALE;
			m_zoomCnt++;
		}

		m_wheeled = MOUSE_WHEEL;
		SetupCamera_Ortho(m_zoom);		//カメラの距離を変更
	}
	//縮小
	else if (m_wheeled > MOUSE_WHEEL) {

		//ホイールによって拡大率を変化
		if (m_zoom < ZOOM_LIMIT_UP) {
			m_zoom += ZOOM_SCALE;
			m_zoomCnt--;
		}

		m_wheeled = MOUSE_WHEEL;
		SetupCamera_Ortho(m_zoom);		//カメラの距離を変更
	}
}

//移動
void cCamera::CameraMove() {

	//ホイールが押された地点を記録
	if (MOUSE_PRESS(MIDDLE_CLICK) == 1 && m_wheelClick == FALSE) {
		m_wheelClick = TRUE;
		m_wheelPosX = MOUSE_X;
		m_wheelPosY = MOUSE_Y;
	}
	//ホイールが押された地点離された地点の座標を元に移動
	else if (MOUSE_PRESS(MIDDLE_CLICK) == 0 && m_wheelClick == TRUE) {
		CameraMoveX(m_wheelPosX - MOUSE_X);
		CameraMoveY(-(m_wheelPosY - MOUSE_Y));
		m_wheelClick = FALSE;
	}
}

//カメラの移動制御
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

	//座標表示
	DrawFormatString(300, 300, BL, "target x:%d y:%d\n pos x:%d y:%d", m_camera.target.x, m_camera.target.y, m_camera.pos.x, m_camera.pos.y);
	DrawCircle(m_camera.target.x, m_camera.target.y, 10, RD, TRUE);
	DrawCircle(m_camera.pos.x, m_camera.pos.y, 10, BL, FALSE);

	//画面フレーム
	DrawLine3D(VGet(-640.0f, -360.0f, m_camera.target.z), VGet(640.0f, -360.0f, m_camera.target.z), GetColor(255, 255, 255));
	DrawLine3D(VGet(-640.0f, -360.0f, m_camera.target.z), VGet(-640.0f, 360.0f, m_camera.target.z), GetColor(255, 255, 255));
	DrawLine3D(VGet(640.0f, 360.0f, m_camera.target.z), VGet(-640.0f, 360.0f, m_camera.target.z), GetColor(255, 255, 255));
	DrawLine3D(VGet(640.0f, 360.0f, m_camera.target.z), VGet(640.0f, -360.0f, m_camera.target.z), GetColor(255, 255, 255));

	// ３Ｄの線分を描画する
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