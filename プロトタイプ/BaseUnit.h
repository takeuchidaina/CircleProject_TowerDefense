#pragma once

#include "BaseTask.h"
#include "Constant.h"
#include <vector>
using namespace std;

#ifndef _INCLUDE_BASE_UNIT_
#define _INCLUDE_BASE_UNIT_



class cBaseUnit : public cBaseTask
{
protected:
	double x, y;			// ���W
	int hp;					// HP
	int room;				// ���݂��镔���ԍ�
	int atk;				// �U����
	int condition;			// ��Ԉُ�
	double speed;			// �ړ����x
	int atkCoolTime;		// ���̍U���܂ł̎���
	int nextRoom;			// ���Ɍ����������ԍ�
	double atkR;			// �˒��͈�
	bool isOnActive;		// �����t���O
	int state;				// ���݂̏��
	// cMapMgr* mapMgr			// �}�b�v�S�̂̃A�h���X

public:
	//cBaseUnit(int hh, double xx, double yy, int rr, int aa, double ss, int act, double ar)
	//{
	//	hp = hh; x = xx; y = yy; room = rr; atk = aa; speed = ss; atkCoolTime = act; atkR = ar;
	//	isOnActive = true;
	//	nextRoom = -1;
	//	condition = eNone;
	//	state = eStey;
	//}
	//~cBaseUnit();

	void Update() {}
	void Draw() {}

	cBaseUnit()
	{
		condition = eNone;
		nextRoom = -1;
		isOnActive = true;
		state = eIdle;
	}

	// ���Ɍ����������̃Z�b�g
	void Set_NextRoom(int _nextRoom)
	{
		nextRoom = _nextRoom;
	}

};
#endif // !_INCLUDE_BASE_UNIT_