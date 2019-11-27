
#pragma once
#include <iostream>
#include <vector>

#include "DxLib.h"
#include "MapMgr.h"
#include "BaseTask.h"
#include "GameMgr.h"

using namespace std;

#ifndef _INCLUDE_MAP_NAVIGATE_
#define _INCLUDE_MAP_NAVIGATE_

/********************************************************
●概要
　ユニットのルート検索

●作成者

　石倉大瑚

●更新日
********************************************************/


class cMapNavigate : public cBaseTask {

protected:
	vector<vector<int>> mapStack;		// 受け取る変数
	vector<int> tbl;	// ゴールまでの道のり

	int moveDistance;	
	
public:

	cMapNavigate();
	virtual ~cMapNavigate();

	virtual void Init();
	virtual void Update();
	virtual void Draw();

	void Get_MapDate(vector<vector<int>> _i);		// MapDateの受け取り

	int InspectMove(int _x, int _y, int _renge);		// Mapのルート検索関数
	bool isMapNavigation(int _start, int _goal);						// Mapのルート検索関数
	int MapNavigation(int _start, int _goal);	// 簡易版
};
#endif // _INCLUDE__MAP_NAVIGATE_
