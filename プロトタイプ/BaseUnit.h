#pragma once

#include "BaseTask.h"
#include "Constant.h"
#include <vector>
#include "Log.h"
using namespace std;

//template <typename _T>

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
	int m_num;				// ���j�b�g�ԍ�
	int m_targetNum;		// �U���Ώۂ̔ԍ�
	int m_hp;				// HP
	int m_room;				// ���݂��镔���ԍ�
	int m_atk;				// �U����
	int m_condition;		// ��Ԉُ�
	double m_speed;			// �ړ����x
	int m_atkCoolTime;		// ���̍U���܂ł̎���
	int m_atkCnt;			// �U���܂ł̃J�E���g
	double m_atkR;			// �˒��͈�
	bool m_isOnActive;		// �����t���O
	int m_state;			// ���݂̏��
	int m_direction;		// ���j�b�g�̌����@1(U_RIGHT):�E -1(U_LEFT):��
	int m_moveCnt;			// �A�j���[�V�����p�J�E���g
	int m_moveAnime[4] = { 1, 0, 1, 2};	// �A�j���[�V�����z��
	sNextMove m_nextMove;	// ���Ɍ������ꏊ

	int m_imgNum;			// �A�j���[�V�����i���o�[
	int m_imgtbl[6];		// �摜�z��
	
public:

	void Update()
	{
		
	}

	void Draw()
	{
		int imgNum = m_moveAnime[m_imgNum];

		// �E�������Ă���ꍇ�͉摜�z��ԍ���3����
		if (m_direction == U_RIGHT)
		{
			imgNum += 3;
		}

		DrawBillboard3D(m_pos, 0.5f, 0.5f, 64, 0.0f, m_imgtbl[imgNum], TRUE);
	}

	cBaseUnit()
	{
		m_condition = eNone;
		m_nextMove.sNextRoom = -1;
		m_nextMove.sNextX = NULL;
		m_isOnActive = true;
		m_state = eIdle;
		m_direction = U_RIGHT;
		m_targetNum = -1;
		m_atkCnt = m_atkCoolTime;
		m_moveCnt = 0;

	}

	~cBaseUnit()
	{
		for (int i = 0; i < 6; i++)
		{
			DeleteGraph(m_imgtbl[i]);
		}
	}

	/*********************************************************************
	�֐����Fvoid Move()
	�T�v�F�ړ�����
	�����F�Ȃ�
	�߂�l�F�Ȃ�
	*********************************************************************/
	void Move()
	{
		// ���ݒn�ƍs�悪�����̏ꍇ
		if (m_room == m_nextMove.sNextRoom)
		{
			// �s�悪�E��
			if (m_pos.x <= m_nextMove.sNextX)
			{
				m_direction = U_RIGHT;
			}
			else // ����
			{
				m_direction = U_LEFT;
			}

			// �E��
			if (m_direction == U_RIGHT)
			{
				m_pos.x += m_speed;
			}
			else // ����
			{
				m_pos.x -= m_speed;
			}

			// �w�肳�ꂽ���W�ɂ�����Idle��Ԃ�
			if (m_pos.x <= m_nextMove.sNextX + m_speed && m_nextMove.sNextX - m_speed <= m_pos.x)
			{
				m_state = eIdle;
				m_imgNum = 0;
			}

		}

		// �ړ����̉摜�z��v�Z
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

	}

	void Attack()
	{
		m_atkCnt--;
		if (m_atkCnt <= 0)
		{
			m_atkCnt = 0;
		}
	}

	int Get_Direction()
	{
		return m_direction;
	}

	double Get_atkR()
	{
		return m_atkR;
	}

	int Get_NowRoom()
	{
		return m_room;
	}

	void AttackStart()
	{
		if (m_targetNum != -1)
		{
			m_state = eAttack;
		}
	}

	int Get_AtkCnt()
	{
		return m_atkCnt;
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

	/*********************************************************************
	�֐����FVECTOR Get_Pos()
	�T�v�F���ݒn�̎擾
	�����F�Ȃ�
	�߂�l�FVECTOR m_pos:���ݒn
	*********************************************************************/
	VECTOR Get_Pos()
	{
		return m_pos;
	}

	/*********************************************************************
	�֐����Fint Get_State()
	�T�v�F���݂̏�Ԏ擾
	�����F�Ȃ�
	�߂�l�Fint m_state:��� eIdle�Ȃ�
	*********************************************************************/
	int Get_State()
	{
		return m_state;
	}

	void Set_Target(int _num)
	{
		m_targetNum = _num;
	}

	/*********************************************************************
	�֐����Fint Set_State()
	�T�v�F��Ԃ̕ύX
	�����FeState _state:�ύX��������� Idle�Ȃ�
	�߂�l�F�Ȃ�
	*********************************************************************/
	void Set_State(eState _state)
	{
		m_state = _state;
	}



	/*********************************************************************
	�֐����Fint Get_Num()
	�T�v�F�i���o�[�擾
	�����F�Ȃ�
	�߂�l�Fint:�i���o�[
	*********************************************************************/
	int Get_Num()
	{
		return m_num;
	}
};

#endif // !_INCLUDE_BASE_UNIT_