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
		x = 300; y = 500;
		w = 300; h = 150;
		maxUnit = 3;
		roomNum = 1;
	}

	void Update();
	void Draw()
	{
		DrawBox(x, y, x + w, y + h, GetColor(255, 255, 255), TRUE);
	}

	bool CheckInto(double, double);
	double Get_Graound()
	{
		return y + h;
	}
};