#pragma once
#include "BaseUnit.h"
//#include "EnemyUnit.h"
#include <math.h>

#ifndef _INCLUDE_PLAYER_UNIT_
#define _INCLUDE_PLAYER_UNIT_

/********************************************************
●概要
　プレイヤーユニットのベースクラス

●作成者
　髙井隆太郎

●更新日
　
********************************************************/

class cPlayerUnit : public cBaseUnit
{
protected:
	int number;
	//cEnemyUnit* target;	// �_���G���j�b�g

public:

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
#endif // !_INCLUDE_PLAYER_UNIT_