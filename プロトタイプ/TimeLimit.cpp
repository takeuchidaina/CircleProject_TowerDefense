#include "timeLimit.h"

cTime::cTime(int _sec)		//à¯êî:ïb
{
	m_startTime = GetNowCount();
	m_second = 0;
	m_timeCnt = 0;
	m_timeLimit = _sec;
}

cTime::~cTime()
{
}

void cTime::Init() {

}

void cTime::Update() {
	m_second = (GetNowCount() - m_startTime) / 1000;
	m_second %= 60;
	m_timeCnt = m_timeLimit - m_second;

}

void cTime::Draw() {
	//êßå¿éûä‘ï\é¶
	DrawFormatString(0, 40, 0xFFFFFF, "Time:%02d",m_timeCnt);
}

void cTime::End() {

}