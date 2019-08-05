#pragma once

#include <vector>
#include "DxLib.h"
#include "BaseTask.h"
#include "ColorListh.h"
#include "Constant.h"



#ifndef _MAP_INCLUDE_
#define _MAP_INCLUDE_
using namespace std;

struct sDoor {
	sDoor* destination;
	double x, y, width, height;
};

class cMap:public cBaseTask {

private:
	double m_x, m_y;			//左下座標
	double m_width, m_height;	//幅高さ
	int m_maxUnit;				//部屋にいられる最大ユニット数
	int m_roomNum;				//部屋番号
	vector<sDoor> m_door;		//ドアのvector配列

public:
	cMap(double _x, double _y, double _w, double _h, int _maxUnit, int _roomNum, vector<sDoor>& _door);//ドア配列を参照渡し
	virtual ~cMap();
	virtual void Init();
	virtual void Update();
	virtual void Draw();
	virtual void End();

	//ドアのアドレスのGet関数とSet関数
	//i=ドア番号
	sDoor* GetDestination(int i) { return m_door[i].destination; }
	void SetDestination(int i, sDoor* _des) { m_door[i].destination = _des; }

	//高井追加
	bool CheckInto(double, double);
	double Get_Ground()
	{
		return m_y + m_height;
	}
	//ここまで
};

#endif _MAP_INCLUDE_