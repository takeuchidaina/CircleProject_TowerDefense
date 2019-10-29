#include "UnitMgr.h"

void cUnitMgr::Update()
{
	TargetSelect();
	for (int i = 0; i < player.size(); i++)
	{
		switch (player[i]->Get_State())
		{
		case eIdle:		// 待機

			break;

		case eAttack:	// 攻撃中
			//DEBUG_LOG("プレイヤー攻撃中");
			break;

		case eMove:		// 移動中
			player[i]->Move();
			break;

		default:
			break;
		}
		player[i]->AttackStart();
	}

	for (int i = 0; i < enemy.size(); i++)
	{
		switch (enemy[i]->Get_State())
		{
		case eIdle:		// 待機

			break;

		case eAttack:	// 攻撃中
			//DEBUG_LOG("攻撃中");
			break;

		case eMove:		// 移動中
			enemy[i]->Move();
			break;

		default:
			break;
		}
		//enemy[i]->AttackStart();
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
#ifdef UNIT_MGR_DEBUG
	DrawFormatString(100, 100, GetColor(255, 0, 0), "ユニット数：%d", player.size());
	//DrawFormatString(100, 150, GetColor(255, 0, 0), "ユニットe数：%d", enemy.size());
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

void cUnitMgr::SelectUI(int _num)
{
	double sx = player[_num]->Get_Pos().x;
	double sy = player[_num]->Get_Pos().y + UNIT_HEIGHT / 2 + 13;

	DrawBillboard3D(VGet(sx, sy, 0.0f), 0.5f, 0.5f, 18.0f, 0.0f, m_selectMarkImg, TRUE);
}