#pragma once
#include "PlayerUnit.h"

#ifndef _INCLUDE_P_SORD_
#define _INCLUDE_P_SORD_

class cPSord : public cPlayerUnit
{
public:
	cPSord(double _x, double _y, int _room) : cPlayerUnit()
	{
		x = _x;
		y = _y;
		room = _room;
		hp = 50;
		atk = 50;
		speed = 3.0;
		atkCoolTime = 3;
		//target = NULL;
	}

	void Update() {}
	void Draw()
	{
		//DrawCircle(x, y, 10, GetColor(255, 0, 0));

		DrawBox(x-UNIT_WIDTH/2, y, x+UNIT_WIDTH/2, y+ UNIT_HEIGHT, GetColor(255, 0, 0), TRUE);
	}

	/*virtual void Set_Target(vector<cEnemyUnit>* _enemy)
	{
		double distance;

		for (int i = 0; i < _enemy->size(); i++)
		{
			if (room == _enemy[i].Get_room() && distance > fabs(x - _enemy[i].Get_X()))
			{
				target = _enemy[i];
			}
		}
	}*/

private:
	virtual void Attack() {}
};
#endif // !_INCLUDE_PSORD_
