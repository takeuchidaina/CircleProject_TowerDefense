#pragma once
#include "Singleton.h"
#include "UnitMgr.h"
#include "Map.h"
#include "Mouse.h"
#include "Constant.h"

#ifndef _INCLUDE_INGAME_MGR_
#define _INCLUDE_INGAME_MGR_

/********************************************************
●概要
  ゲームシーン全般
  インクルードシーン
  ・戦闘マネージャー
  ・索敵シーン
  ・イベントシーン
  ・次の日シーン

●作成者
　��井隆太郎

●更新日
  
********************************************************/

class cInGameMgr : public cSingleton <cInGameMgr>
{
	cInGameMgr() {}
	friend cSingleton <cInGameMgr>;

	cUnitMgr unit;
	cMap map;

public:
	void Update()
	{
		map.Update();

		if (cMouse::Instance()->GetReleaseCnt(0) == 1)
		{
			if (true == map.CheckInto(cMouse::Instance()->GetX(), cMouse::Instance()->GetY()))
			{
				unit.Add_PSord(cMouse::Instance()->GetX(), map.Get_Ground() - UNIT_HEIGHT);
			}
		}

		unit.Update();
	}

	void Draw()
	{
		map.Draw();
		unit.Draw();
	}
};
#endif // !_INCLUDE_INGAME_MGR_