#pragma once
#include <math.h>
#include "BaseUnit.h"
//#include "UnitMgr.h"
#include "MapMgr.h"
//#include "PlayerUnit.h"

//using namespace std;

#ifndef _INCLUDE_ENEMY_UNIT_
#define _INCLUDE_ENEMY_UNIT_

/********************************************************
●概要
　敵ユニットのステータス管理

●作成者

　石倉大瑚
   
●更新日 
********************************************************/

class cEnemyUnit : public cBaseUnit {

protected:
	
public:

	cEnemyUnit() : cBaseUnit() {}
	virtual ~cEnemyUnit() {}				

	int m_number;
	//cPlayerUnit* target;				// 狙うプレイヤーユニット
	vector<vector<int>> mapStack;		// Map番号を入れる

	virtual void Init();
	virtual void Update();
	virtual void Draw();

	int Get_Num();
	void Set_MapSize();
	void EnemyMove();
	void MapNavigation();		// Mapのルート検索関数
};
#endif // _INCLUDE_ENEMY_UNIT_