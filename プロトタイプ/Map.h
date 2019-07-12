#pragma once
#ifndef _MAP_INCLUDE_
#define _MAP_INCLUDE_
#include "BaseTask.h"

class cMap:public cBaseTask {
private:
	int m_maxUnit;
	double m_x, m_y, m_width, m_height;
	int m_roomNum;
	sDoor door[];

public:
	cMap();
	~cMap();
	void Init();
	void Update();
	void Draw();
	void End();
};

struct sDoor {
	sDoor* destination;
	double x, y, width, height;
};


#endif _MAP_INCLUDE_