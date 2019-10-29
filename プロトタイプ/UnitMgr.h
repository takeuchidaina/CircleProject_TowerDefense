#pragma once
#include "BaseTask.h"
#include "DxLib.h"
#include "DebugList.h"
#include "PlayerUnit.h"
#include "EnemyUnit.h"
#include "Constant.h"
#include "PSord.h"
#include "PArcher.h"
#include "PDefense.h"
#include "ESord.h"
#include "EArcher.h"
#include "Mouse.h"
#include <vector>
#include "Log.h"
using namespace std;

/********************************************************
●概要
　ユニット全体の制御・仲介

●作成者
　髙井隆太郎

●更新日
　
********************************************************/

#ifndef _INCLUED_UNIT_MGR_
#define _INCLUED_UNIT_MGR_

class cUnitMgr : public cBaseTask
{
	vector<cPlayerUnit*> player;	// プレイヤー
	vector<cEnemyUnit*> enemy;
	int m_num;	// ナンバー
	int m_selectMarkImg;

public:
	cUnitMgr()
	{
		m_num = 0;

		m_selectMarkImg = LoadGraph("../resource/img/PlayerSelect.png");
		if (-1 == m_selectMarkImg)
		{
			//ErrBox("画像読み込み失敗");
		}
	}

	~cUnitMgr()
	{
		DeleteGraph(m_selectMarkImg);
	}

	void Update();
	void Draw();
	

	/*********************************************************************
	関数名：void Add_PSord(double _x, double _y)
	概要：剣士の生成
	引数：座標
	戻り値：なし
	*********************************************************************/
	void Add_PSord(double _x, double _y)
	{
  		player.emplace_back(new cPSord(_x, _y, 1, m_num));
		m_num++;
	}
	/*********************************************************************
	関数名：void Add_PArcher(double _x, double _y)
	概要：弓兵？の生成
	引数：座標
	戻り値：なし
	*********************************************************************/
	void Add_PArcher(double _x, double _y)
	{
		player.emplace_back(new cPArcher(_x, _y, 1, m_num));
		m_num++;
	}

	/**************************** エネミー ************************/
	
	void Add_ESord(double _x, double _y, int _room)
	{
		enemy.emplace_back(new cESord(_x, _y, _room, m_num));
		m_num++;
		DEBUG_LOG("AddESord来たよ");
		//Set_State(eMove);
	}

	void Add_EArcher(double _x, double _y, int _room)
	{
		enemy.emplace_back(new cEArcher(_x, _y, _room, m_num));
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
				// 同じ部屋かどうか
				if (player[p]->Get_NowRoom() == enemy[e]->Get_NowRoom())
				{
					//DEBUG_LOG("同じ部屋");
					// お互い戦闘中でないか
					if (player[p]->Get_State() != eAttack && enemy[e]->Get_State() != eAttack)
					{
						/* Player */
						// 向き
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
	関数名：int CheckPlayerClick(VECTOR _pos);
	概要：プレイヤーとの当たり判定
	引数：VECTOR:座標
	戻り値：int:当たったプレイヤーのナンバー -1:外れ
	*********************************************************************/
	int CheckPlayerClick(VECTOR _pos);
	int CheckEnemyClick(VECTOR _pos);

	/*********************************************************************
	関数名：void Set_NextPlayerPos(int _playerNum, int _nextRoom, double _nextX)
	概要：次の行先をセット
	引数：int:移動させるナンバー, int:移動先の部屋番号, double:移動先の座標
	戻り値：なし
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
			DEBUG_LOG("次の座標セット");
		}		
	}

	void SelectUI(int _num);	//-1	// 触れてるか	//mouse X

	void Set_NextEnemyPos(int _enemyNum, int _nextRoom, double _nextX)
	{
		enemy[_enemyNum]->Set_NextMove(_nextRoom, _nextX);
		enemy[_enemyNum]->Set_State(eMove);
		DEBUG_LOG("敵の移動先セット");
	}
};

#endif  // !_INCLUDE_UNIT_MGR_