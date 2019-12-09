#pragma once
#include <iostream>
#include <vector>

#include "DxLib.h"
#include "MapMgr.h"
#include "BaseTask.h"

using namespace std;

/********************************************************
●概要
　ユニットのルート検索

●作成者

　石倉大瑚

●更新日
********************************************************/
#ifndef _INCLUDE_MAPNAVIGATE_
#define _INCLUDE_MAPNAVIGATE_

class cMapNavigate : public cBaseTask {

protected:
	vector<vector<int>> mapStack;		// 受け取る変数
	vector<int> tbl;	// ゴールまでの道のり
	int tmpRand;


public:

	cMapNavigate();
	virtual ~cMapNavigate();

	void Init()override;
	void Update()override;
	void Draw()override;

	void Get_MapDate(vector<vector<int>> _MapDate);		// MapDateの受け取り

	//int InspectMove(int _x, int _y, int _renge);		// Mapのルート検索関数
	//bool isMapNavigation(int _start, int _goal);						// Mapのルート検索関数
	int MapNavigation(int _start, int _goal);	// 簡易版
};
#endif // !_INCLUDE_MAPNAVIGATE_
