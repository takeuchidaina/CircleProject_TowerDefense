#pragma once
#include <iostream>
#include <vector>

#include "DxLib.h"
#include "MapMgr.h"
#include "BaseTask.h"


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
	vector<vector<int>> tmpMapStack;	// 

	int moveDistance;	
	

public:

	cMapNavigate();
	~cMapNavigate();

	virtual void Init();
	virtual void Update();
	virtual void Draw();

	//void Set_MapDate();
	int InspectMove(int _x, int _y, int _renge);		// Mapのルート検索関数
	int MapNavigation(int _x, int _y);						// Mapのルート検索関数
};
#endif // _INCLUDE__MAP_NAVIGATE_