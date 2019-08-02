#include "FPS.h"

cFPS::cFPS(){
	m_startTime = 0;
	m_count = 0;
	m_fps = 0.0;
}

cFPS::~cFPS() {
	//
}

/************************************************

FPS値の計算

************************************************/
void cFPS::Update() {
	if (m_count == 0) { //1フレーム目なら時刻を記憶
		m_startTime = GetNowCount();
	}
	if (m_count == FPS) { //60フレーム目なら平均を計算する
		int t = GetNowCount();
		m_fps = 1000.f / ((t - m_startTime) / (float)FPS);
		m_count = 0;
		m_startTime = t;
	}
	m_count++;
}

/************************************************

デバッグ文字の表示

************************************************/
void cFPS::Draw() {

#ifdef FPS_DEBUG
	DrawFormatString(1220, 0, WH, "%.1f", m_fps);
#endif // FPS_DEBUG

}

/************************************************

かかった時間とかかるべき時間の計算
また、必要に応じて処理を止める

************************************************/
void cFPS::Wait() {

	int tookTime = GetNowCount() - m_startTime;			//かかった時間
	int waitTime = m_count * 1000 / FPS - tookTime;		//待つべき時間
	if (waitTime > 0) {
		Sleep(waitTime);	//待機
	}
}