#pragma once
#include "PlayerUnit.h"

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
		speed = 3;
		atkCoolTime = 3;
		target = NULL;
	}

	void Update() {}
	void Draw()
	{
		//DrawCircle(x, y, 10, GetColor(255, 0, 0));

		DrawBox(x-32, y, x+32, y+ 64, GetColor(255, 0, 0), TRUE);
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