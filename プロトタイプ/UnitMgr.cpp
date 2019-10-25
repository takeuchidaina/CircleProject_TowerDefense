#include "UnitMgr.h"

void cUnitMgr::Update()
{
	
	for (int i = 0; i < player.size(); i++)
	{
		switch (player[i]->Get_State())
		{
		case eIdle:

			break;

		case eAttack:

			break;

		case eMove:
			player[i]->Move();
			break;

		default:
			break;
		}
	}

	for (int i = 0; i < enemy.size(); i++)
	{
		switch (enemy[i]->Get_State())
		{
		case eIdle:
			break;

		case eAttack:
			enemy[i]->Attack();
			break;

		case eMove:
			enemy[i]->Move();
			break;

		default:
			break;
		}
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
	}a

#ifdef UNIT_MGR_DEBUG
	DrawFormatString(100, 100, GetColor(255, 0, 0), "ユニット数：%d", player.size());
#endif // UNIT_MGR_DEBUG
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