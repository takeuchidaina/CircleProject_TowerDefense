#pragma once
#include "BaseTask.h"
#include "DxLib.h"
#include "DebugList.h"
#include "PlayerUnit.h"
#include "Constant.h"
#include "PSord.h"
#include "PArcher.h"
#include <vector>
using namespace std;

#ifndef _INCLUED_UNIT_MGR_
#define _INCLUED_UNIT_MGR_

class cUnitSelectUI
{
	double x, y, width, height;
	int type;

public:
	cUnitSelectUI(double _x, int _type)
	{
		x = _x;
		y = 1250.0;
		width = 60.0;
		height = 30.0;

		type = _type;
	}

	void Draw()
	{
		DrawBox(x, y, x + width, y + height, GetColor(0, 0, 255), TRUE);
		DrawFormatString(x + 5, y + 10, GetColor(0, 0, 0), "%d", type);
	}
};

class cUnitMgr : public cBaseTask
{
	vector<cPlayerUnit*> player;

	vector<cUnitSelectUI> ui;

public:
	cUnitMgr() {}
	void Update();
	void Draw();

	void Add_PSord(double _x, double _y)
	{
		player.emplace_back(new cPSord(_x, _y, 1));
	}

	void UnitSelectUI();
};

#endif  // !_INCLUDE_UNIT_MGR_