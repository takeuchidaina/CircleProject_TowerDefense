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
	double x, y, width, height;
	int desMap, desDoor;
};

class cMap:public cBaseTask {

private:
	//double m_x, m_y;			//�������W
	double m_width, m_height;	//������
	int m_maxUnit;				//�����ɂ�����ő僆�j�b�g��
	int m_roomNum;				//�����ԍ�
	vector<sDoor> m_door;		//�h�A��vector�z��

	int img;

	VECTOR m_pos;

public:

	cMap(double _x, double _y, double _w, double _h, int _maxUnit, int _roomNum, vector<sDoor>& _door);//�h�A�z����Q�Ɠn��
	virtual ~cMap() {}
	virtual void Init();
	virtual void Update();
	virtual void Draw();

	//�h�A�̃A�h���X��Get�֐���Set�֐�
	//i=�h�A�ԍ�
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