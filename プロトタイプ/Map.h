#pragma once
#ifndef _MAP_INCLUDE_
#define _MAP_INCLUDE_
#include <vector>
#include "BaseTask.h"
using namespace std;

class cMap:public cBaseTask {
private:
	int m_maxUnit;
	double m_width, m_height;
	int m_roomNum;
	vector<sDoor> door;
	sPos pos;

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

struct sPos {
	double x, y;
};


#endif _MAP_INCLUDE_