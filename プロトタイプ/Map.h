#pragma once
#ifndef _MAP_INCLUDE_
#define _MAP_INCLUDE_
using namespace std;
#include <vector>
#include "DxLib.h"
#include "BaseTask.h"

class cMap:public cBaseTask {
private:
	double m_x, m_y;
	double m_width, m_height;
	int m_maxUnit;
	int m_roomNum;
	vector<sDoor> m_door;

public:
	cMap(double _x, double _y, double _w, double _h, int _maxUnit, int _roomNum, vector<sDoor>& _door);
	~cMap();
	void Init();
	void Update();
	void Draw();
	void End();

	//ドアのアドレス系
	sDoor* GetDestination(int i) { return m_door[i].destination; }
	void SetDestination(int i, sDoor* _des) { m_door[i].destination = _des; }
};

struct sDoor {
	sDoor* destination;
	double x, y, width, height;
};

#endif _MAP_INCLUDE_