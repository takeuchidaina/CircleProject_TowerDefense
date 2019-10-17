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
	int m_number;
	//cEnemyUnit* target;	// �_���G���j�b�g

public:

	cPlayerUnit() : cBaseUnit()
	{
		
	}

	/*void Update() {}
	void Draw() {}*/

	int Get_Num()
	{
		return m_num;
	}

	void Set_NextMove(int _nextRoom, double _nextX)
	{
		m_nextMove.sNextRoom = _nextRoom;
		m_nextMove.sNextX = _nextX;
	}

};
#endif // !_INCLUDE_PLAYER_UNIT_