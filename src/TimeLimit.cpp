#include "timeLimit.h"

cTime::cTime(int _sec)		//����:�b
{
	m_startTime = GetNowCount();
	m_second = 0;
	m_timeCnt = _sec;
	m_timeLimit = _sec;
	m_color = WH;
	m_poseTime = 0;
}

cTime::~cTime()
{
}

void cTime::Init() {

}

void cTime::Update() {
	m_second = (GetNowCount() + m_poseTime - m_startTime) / 1000;
	m_second %= m_timeLimit;
	m_timeCnt = m_timeLimit - m_second + (m_poseTime / 60);

	if (m_timeCnt < 10) {
		m_color = RD;
	}

}

void cTime::Draw() {
	//�������ԕ\��
	SetFontSize(30);
	DrawFormatString(980, 20, m_color, "�h�q�����܂�:%02d�b",m_timeCnt-1);
}

void cTime::End() {

}

void cTime::Set_PoseTimer(int _time) {
	m_poseTime = _time;
}