#pragma once

#include "DxLib.h"
#include "BaseTask.h"

class cTime : public cBaseTask
{
public:
	cTime(){}
	cTime(int _sec);
	virtual ~cTime();

	virtual void Init();
	virtual void Update();
	virtual void Draw();
	virtual void End();

	int GetSecond() {
		return m_second;
	}

private:

	int m_second;
	int m_startTime;
	int m_timeCnt;
	int m_timeLimit;

};

