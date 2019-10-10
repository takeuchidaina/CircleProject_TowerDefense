#pragma once
#include "BaseTask.h"
#include "DxLib.h"
#include "DebugList.h"
#include "PlayerUnit.h"
#include "Constant.h"
#include "PSord.h"
#include "PArcher.h"
#include "Mouse.h"
#include <vector>
using namespace std;

/********************************************************
●概要
　ユニット全体の制御・仲介

●作成者
　髙井隆太郎

●更新日
　
********************************************************/

#ifndef _INCLUED_UNIT_MGR_
#define _INCLUED_UNIT_MGR_

class cUnitMgr : public cBaseTask
{
	vector<cPlayerUnit*> player;

public:
	cUnitMgr() {}
	void Update();
	void Draw();

	void Add_PSord(double _x, double _y)
	{
		player.emplace_back(new cPSord(_x, _y, 1));
	}

	void Add_PArcher(double _x, double _y)
	{
		player.emplace_back(new cPArcher(_x, _y, 1));
	}

};

#endif  // !_INCLUDE_UNIT_MGR_