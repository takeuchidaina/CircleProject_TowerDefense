#pragma once
#include "PlayerUnit.h"

#ifndef _INCLUDE_P_SORD_
#define _INCLUDE_P_SORD_

/********************************************************
●概要
　プレイヤー剣士ユニットクラス

●作成者
　髙井隆太郎

●更新日
　
********************************************************/

class cPSord : public cPlayerUnit
{
public:
	cPSord(double _x, double _y, int _room) : cPlayerUnit()
	{
		m_x = _x;
		m_y = _y;
		m_room = _room;
		m_hp = 50;
		m_atk = 50;
		m_speed = 3.0;
		m_atkCoolTime = 3;
		//target = NULL;
	}

	virtual void Update() {}
	virtual void Draw()
	{
		DrawBox(m_x-UNIT_WIDTH/2, m_y, m_x+UNIT_WIDTH/2, m_y+ UNIT_HEIGHT, GetColor(255, 0, 0), TRUE);
	}

	/* TODO;
	virtual void Set_Target(vector<cEnemyUnit>* _enemy)
	{
		double distance;

		for (int i = 0; i < _enemy->size(); i++)
		{
			if (room == _enemy[i].Get_room() && distance > fabs(x - _enemy[i].Get_X()))
			{
				target = _enemy[i];
			}
		}
	}
	*/

private:
	virtual void Attack() {}
};
#endif // !_INCLUDE_PSORD_
