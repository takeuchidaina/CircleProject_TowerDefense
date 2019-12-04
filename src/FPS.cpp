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

FPS�l�̌v�Z

************************************************/
void cFPS::Update() {
	if (m_count == 0) { //1�t���[���ڂȂ玞�����L��
		m_startTime = GetNowCount();
	}
	if (m_count == FPS) { //60�t���[���ڂȂ畽�ς��v�Z����
		int t = GetNowCount();
		m_fps = 1000.f / ((t - m_startTime) / (float)FPS);
		m_count = 0;
		m_startTime = t;
	}
	m_count++;
}

/************************************************

�f�o�b�O�����̕\��

************************************************/
void cFPS::Draw() {

#ifdef FPS_DEBUG
	DrawFormatString(1220, 0, WH, "%.1f", m_fps);
#endif // FPS_DEBUG

}

/************************************************

�����������ԂƂ�����ׂ����Ԃ̌v�Z
�܂��A�K�v�ɉ����ď������~�߂�

************************************************/
void cFPS::Wait() {

	int tookTime = GetNowCount() - m_startTime;			//������������
	int waitTime = m_count * 1000 / FPS - tookTime;		//�҂ׂ�����
	if (waitTime > 0) {
		Sleep(waitTime);	//�ҋ@
	}
}