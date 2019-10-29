#pragma once
#include "BaseTask.h"
#include "DxLib.h"
#include "DebugList.h"
#include "PlayerUnit.h"
#include "Constant.h"
#include "PSord.h"
#include "PArcher.h"
#include "PDefense.h"
#include "Mouse.h"
#include <vector>
#include "Log.h"
using namespace std;

/********************************************************
���T�v
�@���j�b�g�S�̂̐���E����

���쐬��
�@���䗲���Y

���X�V��
�@
********************************************************/

#ifndef _INCLUED_UNIT_MGR_
#define _INCLUED_UNIT_MGR_

class cUnitMgr : public cBaseTask
{
	vector<cPlayerUnit*> player;	// �v���C���[
	vector<cEnemyUnit*> enemy;
	int m_num;	// �i���o�[

	int m_selectMarkImg;

public:
	cUnitMgr()
	{
		m_num = 0;

		m_selectMarkImg = LoadGraph("../resource/img/PlayerSelect.png");
		if (-1 == m_selectMarkImg)
		{
			ErrBox("�摜�ǂݍ��ݎ��s");
		}
	}

	~cUnitMgr()
	{
		DeleteGraph(m_selectMarkImg);
	}

	void Update();
	void Draw();

	/*********************************************************************
	�֐����Fvoid Add_PSord(double _x, double _y)
	�T�v�F���m�̐���
	�����F���W
	�߂�l�F�Ȃ�
	*********************************************************************/
	void Add_PSord(double _x, double _y)
	{
		player.emplace_back(new cPSord(_x, _y, 1, m_num));
		m_num++;
	}

	/*********************************************************************
	�֐����Fvoid Add_PArcher(double _x, double _y)
	�T�v�F�|���H�̐���
	�����F���W
	�߂�l�F�Ȃ�
	*********************************************************************/
	void Add_PArcher(double _x, double _y)
	{
		player.emplace_back(new cPArcher(_x, _y, 1, m_num));
		m_num++;
	}

	void Add_ESord(double _x, double _y)
	{
		enemy.emplace_back(new cPDefense(_x, _y,  1, m_num));
		m_num++;
	}

	void TargetSelect()
	{
		// Player
		for (int p = 0; p < player.size(); p++)
		{
			// Enemy
			for (int e = 0; e < enemy.size(); e++)
			{
				// �����������ǂ���
				if (player[p]->Get_NowRoom() == enemy[e]->Get_NowRoom())
				{
					//DEBUG_LOG("��������");
					// ���݂��퓬���łȂ���
					if (player[p]->Get_State() != eAttack && enemy[e]->Get_State() != eAttack)
					{
						/* Player */
						// ����
						/*if (player[p]->Get_Direction() == U_RIGHT)
						{
							if (player[p]->Get_Pos().x <= enemy[e]->Get_Pos().x && player[p]->Get_Pos().x + player[p]->Get_atkR() >= enemy[e]->Get_Pos().x)
							{
								player[p]->Set_Target(enemy[e]->Get_Num());
								player[p]->Set_State(eAttack);
							}
						}
						else
						{
							if (player[p]->Get_Pos().x >= enemy[e]->Get_Pos().x && player[p]->Get_Pos().x - player[p]->Get_atkR() <= enemy[e]->Get_Pos().x)
							{
								player[p]->Set_Target(enemy[e]->Get_Num());
								player[p]->Set_State(eAttack);
							}
						}*/
						/* Enemy */
						if (enemy[e]->Get_Direction() == U_RIGHT)
						{
							if (enemy[e]->Get_Pos().x <= player[p]->Get_Pos().x && enemy[e]->Get_Pos().x + enemy[e]->Get_atkR() >= player[p]->Get_Pos().x)
							{
								enemy[e]->Set_Target(player[p]->Get_Num());
								enemy[e]->Set_State(eAttack);
							}
						}
						else
						{
							if (enemy[e]->Get_Pos().x >= player[p]->Get_Pos().x && enemy[e]->Get_Pos().x - enemy[e]->Get_atkR() <= player[p]->Get_Pos().x)
							{
								enemy[e]->Set_Target(player[p]->Get_Num());
								enemy[e]->Set_State(eAttack);
							}
						}
					}
				}
			}
		}
	}

	int AttackRelay(int _num)
	{
		if (_num == -1)
		{
			return -1;
		}



		return 0;
	}

	

	/*********************************************************************
	�֐����Fint CheckPlayerClick(VECTOR _pos);
	�T�v�F�v���C���[�Ƃ̓����蔻��
	�����FVECTOR:���W
	�߂�l�Fint:���������v���C���[�̃i���o�[ -1:�O��
	*********************************************************************/
	int CheckPlayerClick(VECTOR _pos);

	/*********************************************************************
	�֐����Fvoid Set_NextPlayerPos(int _playerNum, int _nextRoom, double _nextX)
	�T�v�F���̍s����Z�b�g
	�����Fint:�ړ�������i���o�[, int:�ړ���̕����ԍ�, double:�ړ���̍��W
	�߂�l�F�Ȃ�
	*********************************************************************/
	void Set_NextPlayerPos(int _playerNum, int _nextRoom, double _nextX)
	{
		for (int i = 0; i < player.size(); i++)
		{
			if (player[i]->Get_Num() == _playerNum)
			{
				player[i]->Set_NextMove(_nextRoom, _nextX);
				player[i]->Set_State(eMove);
			}
			//DEBUG_LOG("���̍��W�Z�b�g");
		}		
	}

	void SelectUI(int _num);
};

#endif  // !_INCLUDE_UNIT_MGR_