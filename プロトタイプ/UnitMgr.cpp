#include "UnitMgr.h"

cUnitMgr::cUnitMgr()
{
	m_num = 0;

	m_selectMarkImg = LoadGraph("../resource/img/PlayerSelect.png");
	if (-1 == m_selectMarkImg)
	{
		//ErrBox("画像読み込み失敗");
	}
}

cUnitMgr::~cUnitMgr()
{
	DeleteGraph(m_selectMarkImg);
}

void cUnitMgr::Update()
{
	TargetSelect();
	for (int i = 0; i < player.size(); i++)
	{
		switch (player[i]->Get_State())
		{
		case eIdle:
			break;

		case eAttack:
			if (player[i]->Attack() == true)
			{
				AttackRelay(player[i]->Get_AtkPoint(), player[i]->Get_TargetNum(), player[i]->Get_Num());
			}
			/*if (player[i]->Get_EffectFlg() == true)
			{
				player[i]->AttackAnime();
			}*/
			break;

		case eMove:
			player[i]->Move();
			break;

		default:
			break;
		}
		player[i]->AttackStart();

		DrawFormatString(200, 400, RD, "player:%d", player[0]->Get_Hp());
	}

	for (int i = 0; i < enemy.size(); i++)
	{
		switch (enemy[i]->Get_State())
		{
		case eIdle:

			break;

		case eAttack:
			if (enemy[i]->Attack() == true)
			{
				AttackRelay(enemy[i]->Get_AtkPoint(), enemy[i]->Get_TargetNum(), enemy[i]->Get_Num());
			}
			break;

		case eMove:
			enemy[i]->Move();
			break;

		default:
			break;
		}
		//enemy[i]->AttackStart();

		enemy[i]->Set_MapSize(4);
		DrawFormatString(200, 450, RD, "enemy:%d", enemy[0]->Get_Hp());
	}
}

void cUnitMgr::Draw()
{
	for (int i = 0; i < player.size(); i++)
	{
		player[i]->Draw();
	}
	for (int i = 0; i < enemy.size(); i++)
	{
		enemy[i]->Draw();
	}

	for (int i = 0; i < player.size(); i++)
	{
		if (player[i]->Get_EffectFlg() == true)
		{
			player[i]->AttackAnime();
		}
	}
	for (int i = 0; i < enemy.size(); i++)
	{
		//enemy[i]->Draw();
	}
#ifdef UNIT_MGR_DEBUG
	//DrawFormatString(100, 100, GetColor(255, 0, 0), "ƒ†ƒjƒbƒg”F%d", player.size());
	//DrawFormatString(100, 150, GetColor(255, 0, 0), "ƒ†ƒjƒbƒge”F%d", enemy.size());
#endif // UNIT_MGR_DEBUG
}

void cUnitMgr::TargetSelect()
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
					if (player[p]->Get_Direction() == U_RIGHT)
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
					}
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

int cUnitMgr::AttackRelay(int _atkP, int _difNum, int _atkNum)
{
	int tmp = 0;
	if ((tmp = PlayerArreySearch(_difNum)) != -1)
	{
		player[tmp]->Defense(_atkP, _atkNum);
		return 0;
	}

	if ((tmp = EnemyArreySearch(_difNum)) != -1)
	{
		enemy[tmp]->Defense(_atkP, _atkNum);
		return 0;
	}

	return 0;
}

int cUnitMgr::EnemyArreySearch(int _num)
{
	for (int i = 0; i < enemy.size(); i++)
	{
		if (enemy[i]->Get_Num() == _num)
		{
			return i;
		}
	}

	return -1;
}

int cUnitMgr::PlayerArreySearch(int _num)
{
	for (int i = 0; i < player.size(); i++)
	{
		if (player[i]->Get_Num() == _num)
		{
			return i;
		}
	}

	return -1;
}

int cUnitMgr::CheckPlayerClick(VECTOR _pos)
{
	for (int i = 0; i < player.size(); i++)
	{
		VECTOR p_pos = player[i]->Get_Pos();

		if ((p_pos.x - UNIT_WIDTH / 2) <= _pos.x && (p_pos.x + UNIT_WIDTH / 2) >= _pos.x)
		{
			if ((p_pos.y - UNIT_HEIGHT / 2) <= _pos.y && (p_pos.y + UNIT_HEIGHT / 2) >= _pos.y)
			{
				return player[i]->Get_Num();
			}
			
		}
		
	}
	return -1;
}

int cUnitMgr::CheckEnemyClick(VECTOR _pos)
{
	for (int i = 0; i < enemy.size(); i++)
	{
		VECTOR e_pos = enemy[i]->Get_Pos();

		if ((e_pos.x - UNIT_WIDTH / 2) <= _pos.x && (e_pos.x + UNIT_WIDTH / 2) >= _pos.x)
		{
			if ((e_pos.y - UNIT_HEIGHT / 2) <= _pos.y && (e_pos.y + UNIT_HEIGHT / 2) >= _pos.y)
			{
				return enemy[i]->Get_Num();
			}
		}
	}
	return -1;
}

void cUnitMgr::Set_NextPlayerPos(int _playerNum, int _nextRoom, double _nextX)
{
	for (int i = 0; i < player.size(); i++)
	{
		if (player[i]->Get_Num() == _playerNum)
		{
			player[i]->Set_NextMove(_nextRoom, _nextX);
			player[i]->Set_State(eMove);
		}
		//DEBUG_LOG("次の座標セット");
	}
}

void cUnitMgr::Set_NextEnemyPos(int _enemyNum, int _nextRoom, double _nextX)
{
	enemy[_enemyNum]->Set_NextMove(_nextRoom, _nextX);
	enemy[_enemyNum]->Set_State(eMove);
	//DEBUG_LOG("敵の移動先セット");
}

void cUnitMgr::SelectUI(int _num)
{
	double sx = player[_num]->Get_Pos().x;
	double sy = (player[_num]->Get_Pos().y + UNIT_HEIGHT / 2 + 13);

	DrawBillboard3D(VGet(sx, sy, 0.0f), 0.5f, 0.5f, 18.0f, 0.0f, m_selectMarkImg, TRUE);
}