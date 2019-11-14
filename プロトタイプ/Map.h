#pragma once


#include <vector>
#include "DxLib.h"
#include "BaseTask.h"
#include "ColorListh.h"
#include "Constant.h"
//#include "MapMgr.h"
using namespace std;


#ifndef _MAP_INCLUDE_
#define _MAP_INCLUDE_

struct sDoor {
	sDoor* destination;
	VECTOR pos;
	double width, height;
	int desMap, desDoor;
};

class cMap:public cBaseTask {

private:
	//double m_x, m_y;			//左下座標

	VECTOR m_pos;				//x,y,z(z=0.0f) VECTORはDxLibで定義されている
	double m_width, m_height;	//幅高さ
	int m_maxUnit;				//部屋にいられる最大ユニット数
	int m_roomNum;				//部屋番号
	vector<sDoor> m_door;		//ドアのvector配列

	int mapimg;
	int doorimg;


public:

	cMap(double _x, double _y, double _w, double _h, int _maxUnit, int _roomNum, vector<sDoor>& _door);//ドア配列を参照渡し
	virtual ~cMap() {}
	virtual void Init();
	virtual void Update();
	virtual void Draw();

	//ドアのアドレスのGet関数とSet関数
	//i=ドア番号
	sDoor* GetDestination(int i) { return m_door[i].destination; }
	void SetDestination(int i, sDoor* _des) { m_door[i].destination = _des; }

	bool CheckInto(double, double);
	double Get_Ground()
	{
		return m_pos.y - (m_height / 2);
	}
	int GetRoomNum() {
		return m_roomNum;
	}


};

#endif _MAP_INCLUDE_