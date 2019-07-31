#pragma once

#include "BaseTask.h"
#include "Constant.h"
#include <vector>
using namespace std;

#define UNIT_WIDTH 64
#define UNIT_HEIGHT 64

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
		state = eStey;
	}

	// ���Ɍ����������̃Z�b�g
	void Set_NextRoom(int rr)
	{
		nextRoom = rr;
	}

};