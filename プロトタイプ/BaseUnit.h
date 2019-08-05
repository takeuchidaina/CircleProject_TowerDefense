#pragma once

#include "BaseTask.h"
#include "Constant.h"
#include <vector>
using namespace std;

#ifndef _INCLUDE_BASE_UNIT_
#define _INCLUDE_BASE_UNIT_

/********************************************************
���T�v
�@Unit�̃x�[�X�N���X

���쐬��
�@���䗲���Y

���X�V��
  
********************************************************/

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

	void Update() {}
	void Draw() {}

	cBaseUnit()
	{
		condition = eNone;
		nextRoom = -1;
		isOnActive = true;
		state = eIdle;
	}

	/*********************************************************************
	�֐����Fvoid Set_NextRoom(int)
	�T�v�F���Ɍ������������Z�b�g
	�����F_nextRoom:���Ɍ����������ԍ�
	�߂�l�F�Ȃ�
	*********************************************************************/
	void Set_NextRoom(int _nextRoom)
	{
		nextRoom = _nextRoom;
	}

};
#endif // !_INCLUDE_BASE_UNIT_