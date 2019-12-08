#include "timeLimit.h"

cTime::cTime(int _sec)		//����:�b
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
	//�������ԕ\��
	DrawFormatString(1080, 20, m_color, "�h�q�����܂�:%02d�b",m_timeCnt-1);
}

void cTime::End() {

}