#pragma once
#include "PlayerUnit.h"

#ifndef _INCLUDE_P_ARCHER_
#define _INCLUDE_P_ARCHER_

class cPArcher : public cPlayerUnit
{
public:
	cPArcher(double _x, double _y, int _room) : cPlayerUnit()
	{
		x = _x;
		y = _y;
		room = _room;
		hp = 30;
		atk = 20;
		speed = 3.0;
		atkCoolTime = 5;
	}

	virtual void Update() {}
	virtual void Draw()
	{
		DrawCircle(x, y, 10, GetColor(255, 0, 0));
	}
	virtual void Set_Target() {}

private:
	virtual void Attack() {}
};
#endif // !_INCLUDE_P_ARCHER_
