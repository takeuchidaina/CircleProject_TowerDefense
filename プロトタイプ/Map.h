#pragma once
#include "DxLib.h"
#include "PlayerUnit.h"
#include "Constant.h"

class cMap
{
	double x, y;
	double w, h;
	int maxUnit;
	int roomNum;

public:
	cMap()
	{
		x = 300.0; y = 500.0;
		w = 150.0; h = 100.0;
		maxUnit = 3;
		roomNum = 1;
	}

	void Update();
	void Draw()
	{
		DrawBox(x, y, x + w, y + h, GetColor(255, 255, 255), TRUE);
	}

	bool CheckInto(double, double);
	double Get_Ground()
	{
		return y + h;
	}
};