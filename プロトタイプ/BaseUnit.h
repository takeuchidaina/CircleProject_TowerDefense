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
	double m_x, m_y;			// ���W
	int m_hp;					// HP
	int m_room;				// ���݂��镔���ԍ�
	int m_atk;				// �U����
	int m_condition;			// ��Ԉُ�
	double m_speed;			// �ړ����x
	int m_atkCoolTime;		// ���̍U���܂ł̎���
	int m_nextRoom;			// ���Ɍ����������ԍ�
	double m_atkR;			// �˒��͈�
	bool m_isOnActive;		// �����t���O
	int m_state;				// ���݂̏��
	// cMapMgr* mapMgr			// �}�b�v�S�̂̃A�h���X

public:

	virtual void Update() {}
	virtual void Draw() {}

	cBaseUnit()
	{
		m_condition = E_NONE;
		m_nextRoom = -1;
		m_isOnActive = true;
		m_state = E_IDLE;
	}

	/*********************************************************************
	�֐����Fvoid Set_NextRoom(int)
	�T�v�F���Ɍ������������Z�b�g
	�����F_nextRoom:���Ɍ����������ԍ�
	�߂�l�F�Ȃ�
	*********************************************************************/
	void Set_NextRoom(int _nextRoom)
	{
		m_nextRoom = _nextRoom;
	}

};
#endif // !_INCLUDE_BASE_UNIT_