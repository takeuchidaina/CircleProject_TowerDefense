#include "timeLimit.h"

cTime::cTime(int _sec)		//à¯êî:ïb
{
	m_startTime = GetNowCount();
	m_second = 0;
	m_timeCnt = _sec;
	m_timeLimit = _sec;
	m_color = WH;
}

cTime::~cTime()
{
}

void cTime::Init() {

}

void cTime::Update() {
	m_second = (GetNowCount() - m_startTime) / 1000;
	m_second %= m_timeLimit;
	m_timeCnt = m_timeLimit - m_second;

	if (m_timeCnt < 10) {
		m_color = RD;
	}

}

void cTime::Draw() {
	//êßå¿éûä‘ï\é¶
	DrawFormatString(1080, 20, m_color, "ñhâqê¨å˜Ç‹Ç≈:%02dïb",m_timeCnt-1);
}

void cTime::End() {

}