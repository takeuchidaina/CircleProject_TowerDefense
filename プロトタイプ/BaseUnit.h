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
	 VECTOR m_pos;			// ���W
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
	int m_direction;		// ���j�b�g�̌����@1(U_RIGHT):�E -1(U_LEFT):��
	int m_moveCnt;
	int m_moveAnime[4] = { 1, 0, 1, 2};

	int m_imgNum;
	int m_imgtbl[6];
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

	void Move()
	{
		m_moveCnt++;
		if (m_moveCnt >= 64)
		{
			m_imgNum++;
			if (m_imgNum >= 4)
			{
				m_imgNum = 0;
			}
			m_moveCnt = 0;
		}
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