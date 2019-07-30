#pragma once
#include "BaseTask.h"
#include "DxLib.h"
#include "PlayerUnit.h"
#include "PSord.h"
#include "PArcher.h"
#include <vector>
using namespace std;

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
};