#pragma once
#include "BaseUnit.h"
//#include "EnemyUnit.h"
#include <math.h>

class cPlayerUnit : public cBaseUnit
{
protected:
	int number;
	//cEnemyUnit* target;	// �_���G���j�b�g
	//int type;			// �W���u

public:
	//cPlayerUnit(int hh, double xx, double yy, int rr, int aa, double ss, int act, double ar, int tt)
	//	: cBaseUnit(hh, xx, yy, rr, aa, ss, act, ar)
	//{
	//	type = tt;
	//}
	//~cPlayerUnit();

	cPlayerUnit() : cBaseUnit()
	{
		
	}

	void Update() {}
	void Draw() {}

	void Set_Pos(double _x, double _y)
	{
		x = _x; y = _y;
	}


};