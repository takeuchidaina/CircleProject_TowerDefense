#pragma once

#include "BaseTask.h"
#include "Constant.h"
#include <vector>
#include "Log.h"
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
	int m_num;
	int m_hp;				// HP
	int m_room;				// ���݂��镔���ԍ�
	int m_atk;				// �U����
	int m_condition;		// ��Ԉُ�
	double m_speed;			// �ړ����x
	int m_atkCoolTime;		// ���̍U���܂ł̎���
	//int m_nextRoom;			// ���Ɍ����������ԍ�
	double m_atkR;			// �˒��͈�
	bool m_isOnActive;		// �����t���O
	int m_state;			// ���݂̏��
	int m_direction;		// ���j�b�g�̌����@1(U_RIGHT):�E -1(U_LEFT):��
	int m_moveCnt;			// �A�j���[�V�����p�J�E���g
	int m_moveAnime[4] = { 1, 0, 1, 2};	// �A�j���[�V�����z��
	sNextMove m_nextMove;

	int m_imgNum;			// �A�j���[�V�����i���o�[
	int m_imgtbl[6];		// �摜�z��
	// cMapMgr* mapMgr			// �}�b�v�S�̂̃A�h���X

public:

	void Update()
	{
		
	}

	void Draw()
	{
		int imgNum = m_moveAnime[m_imgNum];
		if (m_direction == U_RIGHT)
		{
			imgNum += 3;
		}

		DrawBillboard3D(m_pos, 0.5f, 0.5f, 64, 0.0f, m_imgtbl[imgNum], TRUE);
	}

	cBaseUnit()
	{
		m_condition = eNone;
		m_nextMove.sNextRoom = 0;
		m_nextMove.sNextX = 0;
		m_isOnActive = true;
		m_state = eIdle;
		m_atk = 0;
		m_atkCoolTime = 0;
		m_atkR = 0;
		m_hp = 0;

	}

	/*********************************************************************
	�֐����Fvoid Move()
	�T�v�F�ړ�����
	�����F�Ȃ�
	�߂�l�F�Ȃ�
	*********************************************************************/
	void Move()
	{
		if (m_room == m_nextMove.sNextRoom)
		{
			if (m_pos.x <= m_nextMove.sNextX)
			{
				m_direction = U_RIGHT;
			}
			else
			{
				m_direction = U_LEFT;
			}

			if (m_direction == U_RIGHT)
			{
				m_pos.x += m_speed;
			}
			else
			{
				m_pos.x -= m_speed;
			}

			if (m_pos.x <= m_nextMove.sNextX + m_speed && m_nextMove.sNextX - m_speed <= m_pos.x)
			{
				m_state = eIdle;
				m_imgNum = 0;
			}

		}

		m_moveCnt++;
		if (m_moveCnt >= 46)
		{
			m_imgNum++;
			if (m_imgNum >= 4)
			{
				m_imgNum = 0;
			}
			m_moveCnt = 0;
		}

		/*int imgNum = m_moveAnime[m_imgNum];
		if (m_direction == U_RIGHT)
		{
			imgNum += 3;
		}*/

		//DrawBillboard3D(m_pos, 0.5f, 0.5f, 64, 0.0f, m_imgtbl[imgNum], TRUE);

		//DEBUG_LOG("BaseUnit");
	}



	/*********************************************************************
	�֐����Fvoid Set_NextRoom(int)
	�T�v�F���Ɍ������������Z�b�g
	�����F_nextRoom:���Ɍ����������ԍ�
	�߂�l�F�Ȃ�
	*********************************************************************/
	void Set_NextMove(int _nextRoom, double _nextX)
	{
		m_nextMove.sNextRoom = _nextRoom;
		m_nextMove.sNextX = _nextX;
	}

	VECTOR Get_Pos()
	{
		return m_pos;
	}

	int Get_State()
	{
		return m_state;
	}

	void Set_State(eState _state)
	{
		m_state = _state;
	}

};
#endif // !_INCLUDE_BASE_UNIT_