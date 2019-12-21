#pragma once
#include <iostream>
#include <vector>

#include "DxLib.h"
#include "MapMgr.h"
#include "BaseTask.h"
#include "Log.h"

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

public:

	cMapNavigate();
	virtual ~cMapNavigate();

	//vector<vector<int>> mapStack;		// 受け取る変数
	//vector<int> tbl;	// ゴールまでの道のり
	int tbl;

	void Init()override;
	void Update()override;
	void Draw()override;

	void Set_MapDate(vector<vector<int>> _MapDate);		// MapDateの受け取り

	int Get_EnemySpawnRoom();					// 敵リスポーンの時に使うGet

	int MapNavigation(int _start, int _goal);	// 簡易版
	int tmpRand;
};
#endif // !_INCLUDE_MAPNAVIGATE_
