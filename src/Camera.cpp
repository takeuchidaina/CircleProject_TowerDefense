#include "Camera.h"

cCamera::cCamera(){
	Init();
}

cCamera::~cCamera(){
	End();
}

void cCamera::Init() {

	//座標・注視点
	m_camera.pos = VGet(0.0f,0.0f,-800.0f);
	m_camera.target = VGet(0.0f, 0.0f, 0.0f);

	//拡大縮小
	MOUSE_WHEEL_INIT;			//マウスホイールの回した回数値を初期化
	m_wheeled = MOUSE_WHEEL;	//マウスホイールの回した回数を取得
	m_zoom = ZOOM_LIMIT_UP;		//カメラを一番引いた状態へ
	m_zoomCnt = 0;

	//移動
	m_wheelPosX = MOUSE_X;
	m_wheelPosY = MOUSE_Y;
	m_wheelClick = FALSE;

	//2D運用する為、正射影に変更
	SetupCamera_Ortho(m_zoom);
}

void cCamera::Update() {

	//拡大縮小
	//CameraScale();

	//移動
	CameraMove();

	//カメラの座標、注視点を更新
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

		//拡大した状態で移動し縮小をすると背景ではないものが映ってしまう為、移動
		if (m_zoomCnt != -1) {
			CameraMoveX(-(ZOOM_SCALE - ZOOM_ADJUSTMENT));
			CameraMoveX((ZOOM_SCALE - ZOOM_ADJUSTMENT));	//カメラを中央に寄せる
		}
	}
}

//移動量を計算
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

	//左
	if (m_camera.pos.x < 0.0f - ((ZOOM_SCALE - ZOOM_ADJUSTMENT) * (float)m_zoomCnt)) {
		m_camera.pos.x = 0.0f - ((ZOOM_SCALE - ZOOM_ADJUSTMENT) * (float)m_zoomCnt);
		m_camera.target.x = m_camera.pos.x;
	}
	//右
	else if (m_camera.pos.x > 0.0f + ((ZOOM_SCALE - ZOOM_ADJUSTMENT) * (float)m_zoomCnt)) {
		m_camera.pos.x = 0.0f + ((ZOOM_SCALE - ZOOM_ADJUSTMENT) * (float)m_zoomCnt);
		m_camera.target.x = m_camera.pos.x;
	}
	//上
	if (m_camera.pos.y > 0.0f + ((ZOOM_SCALE / 2.0f) * (float)m_zoomCnt)) {
		m_camera.pos.y = 0.0f + ((ZOOM_SCALE / 2.0f) * (float)m_zoomCnt);
		m_camera.target.y = m_camera.pos.y;
	}
	//下
	else if (m_camera.pos.y < 0.0f - ((ZOOM_SCALE / 2.0f) * (float)m_zoomCnt)) {
		m_camera.pos.y = 0.0f - ((ZOOM_SCALE / 2.0f) * (float)m_zoomCnt);
		m_camera.target.y = m_camera.pos.y;
	}
}

//移動
void cCamera::CameraMoveX(float _moveAmount) {
	m_camera.target.x += _moveAmount;
	m_camera.pos.x = m_camera.target.x;

	CameraDrawControl();	//カメラが背景を越しているなら越さないように座標を調整
}
void cCamera::CameraMoveY(float _moveAmount) {
	m_camera.target.y += _moveAmount;
	m_camera.pos.y = m_camera.target.y;

	CameraDrawControl();	//カメラが背景を越しているなら越さないように座標を調整
}

void cCamera::Draw() {

#ifdef CAMERA_DEBUG

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