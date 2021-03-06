#include "Mouse.h"

// コンストラクタ
cMouse::cMouse(){
	m_x = 0;
	m_y = 0;
	m_wheel = 0;
	m_playerNum = -1;
	m_enemyNum = -1;
	//buttonPressCnt[KEY_NUM] = { 0 };
	//buttonReleaseCnt[KEY_NUM] = { 0 };
}

// デストラクタ
cMouse::~cMouse(){
	//
}

/************************************************

クリックやドラッグ、ホイール情報の更新

************************************************/
void cMouse::Update() {

	//クリック情報
	int nowButtonState = GetMouseInput();

	//座標情報
	GetMousePoint(&m_x, &m_y);

	//ホイール情報
	m_wheel += GetMouseWheelRotVol();

	for (int i = 0; i < KEY_NUM; i++) {
		//キーが押されている
		if ((nowButtonState >> i) & 1) {
			//離されカウンタが0より大きければ0に戻す
			if (m_buttonReleaseCnt[i] > 0) {	
				m_buttonReleaseCnt[i] = 0;
			}
			m_buttonPressCnt[i]++;		//押されカウンタを増やす
		}
		//キーが離されている
		else {
			//押されているカウンタが0より大きければ0に戻す
			if (m_buttonPressCnt[i] > 0) {		
				m_buttonPressCnt[i] = 0;		
			}
			m_buttonReleaseCnt[i]++;	//離されカウンタを増やす
		}
	}
}

void cMouse::Draw() {

#ifdef MOUSE_DEBUG
	// マウスの座標の表示
	DrawFormatString(1150, 660, WH, "x:%d y:%d", m_x, m_y);
	// クリックされているカウントの表示
	DrawFormatString(1150, 620, WH, "左:%d 右:%d 中:%d",
		m_buttonPressCnt[LEFT_CLICK], m_buttonPressCnt[RIGHT_CLICK], m_buttonPressCnt[MIDDLE_CLICK]);
	// 回転量を表示
	DrawFormatString(1150, 700, GetColor(255, 255, 255), "ホイール:%d", m_wheel);
#endif // DEBUG

}

#pragma region Get関数
/************************************************

引数のキーが押されているフレーム数を返す

************************************************/
int cMouse::GetPressCnt(int _keyCode) {
	if (!IsAvailableCode(_keyCode)) {
		return -1;
	}
	return m_buttonPressCnt[_keyCode];
}

/************************************************

引数のキーが離されているフレーム数を返す

************************************************/
int cMouse::GetReleaseCnt(int _keyCode) {
	if (!IsAvailableCode(_keyCode)) {
		return -1;
	}
	return m_buttonReleaseCnt[_keyCode];
}
/************************************************

マウスのx座標を返す

************************************************/
int cMouse::GetX() {
	return m_x;
}
/************************************************

マウスのy座標を返す

************************************************/
int cMouse::GetY() {
	return m_y;
}

/************************************************

マウスのワールド座標を返す

************************************************/
VECTOR cMouse::GetV()
{
	return ConvScreenPosToWorldPos(VGet(m_x, m_y, 0.0f));
}

/************************************************

マウスのホイール量を返す

************************************************/
int cMouse::GetWheel() {
	return m_wheel;
}

#pragma endregion

#pragma region Set関数

/************************************************

マウスカーソルの座標をセットする

************************************************/
void cMouse::SetMousePoint(int _x,int _y) {
	m_x = _x;
	m_y = _y;
}
/************************************************

マウスのホイール量を初期化する

************************************************/
void cMouse::InitMouseWheel() {
	m_wheel = 0;
}
/************************************************

マウスカーソルの座標をセットする

************************************************/
void cMouse::SetMouseDisplay(bool _isDisplay) {
	SetMouseDispFlag(_isDisplay);
}
#pragma endregion

/************************************************

各関数の引数が有効な値か確認する

************************************************/
bool cMouse::IsAvailableCode(int _keyCode) {
	if (!(0 <= _keyCode && _keyCode < KEY_NUM)) {
		return FALSE;
	}
	return TRUE;
}

/************************************************

プレイヤーナンバー格納

************************************************/
void cMouse::SetPlayerNum(int _num)
{
	m_playerNum = _num;
}

int cMouse::GetPlayerNum()
{
	return m_playerNum;
}

/************************************************

エネミーナンバー格納

************************************************/
void cMouse::SetEnemyNum(int _num)
{
	m_enemyNum = _num;
}

int cMouse::GetEnemyNum()
{
	return m_enemyNum;
}
