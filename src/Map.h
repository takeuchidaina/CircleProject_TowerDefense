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
	//double m_x, m_y;			//�������W

	VECTOR m_pos;				//x,y,z(z=0.0f) VECTOR��DxLib�Œ�`����Ă���
	double m_width, m_height;	//������
	int m_maxUnit;				//�����ɂ�����ő僆�j�b�g��
	int m_roomNum;				//�����ԍ�
	vector<sDoor> m_door;		//�h�A��vector�z��
	bool m_startMapFlg;			//�J�n�n�_�t���O
	bool m_DefenseMapFlg;		//�h�q�n�_�t���O

	vector<int> m_des;	//�h�A�Ȃ�ver�̈ړ���i�[vec�ϐ�

	int m_mapImg;
	int m_doorImg;


public:

	cMap(double _x, double _y, double _w, double _h,
		int _maxUnit, int _roomNum, vector<sDoor>& _door, bool m_startMapFlg, bool m_DefenseMapFlg);//�Q�Ɠn���g�p

	//�h�A�Ȃ�ver
	cMap(double _x, double _y, double _w, double _h,
		int _maxUnit, int _roomNum, vector<int>& _des, bool m_startMapFlg, bool m_DefenseMapFlg, int _mapDays);

	virtual ~cMap() {}
	virtual void Init();
	virtual void Update();
	virtual void Draw();

	//�h�A�̃A�h���X��Get�֐���Set�֐�
	//i=�h�A�ԍ�
	sDoor* GetDestination(int i) { return m_door[i].destination; }
	void SetDestination(int i, sDoor* _des) { m_door[i].destination = _des; }

	bool CheckInto(double, double);
	double Get_Ground() { return m_pos.y; }
	int GetRoomNum() { return m_roomNum; }
	int GetStartFlg() { if (m_startMapFlg == true)return true; }

	vector<int> GetMapDes() { return m_des; }
	
	// ����ǉ�
	/**************************************************************************
	�֐��Fint GetRoomSize()
	�����F������PlayerUnit�����鐔��n��
	�����F�Ȃ�
	�߂�l�Fint:������PlayerUnit�����鐔
	**************************************************************************/
	int GetRoomSize();

	/**************************************************************************
	�֐��FVECTOR GetPos()
	�����F�����̍��W
	�����F�Ȃ�
	�߂�l�FVECTOR:�����̍��W
	**************************************************************************/
	VECTOR GetPos();

	/**************************************************************************
	�֐��Fdouble GetWidth()
	�����F�����̕�
	�����F�Ȃ�
	�߂�l�Fdouble:�����̕�
	**************************************************************************/
	double GetWidth();

	/**************************************************************************
	�֐��Fdouble GetHeight()
	�����F�����̍���
	�����F�Ȃ�
	�߂�l�Fdouble:�����̍���
	**************************************************************************/
	double GetHeight();
};

#endif _MAP_INCLUDE_