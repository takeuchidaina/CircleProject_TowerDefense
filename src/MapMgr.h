#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdlib.h>

#include "DxLib.h"
#include "BaseTask.h"
#include "CSVLoad.h"
#include "Map.h"

using namespace std;

/*******************参考サイト****************************
https://qiita.com/takoyaki3/items/269060a916a66d9c411a		csv読み込み
*********************************************************/

/**********************************************************
 substr…取り出す長さは省略することができ、その場合は指定した位置から最後までの
		 部分文字列を取得できます。

	例)	 変数.substr(開始位置, 取り出す長さ);
*********************************************************/


#ifndef _INCLUDE_MAPMGR_
#define _INCLUDE_MAPMGR_

#define _MAP_STATUS_ 7

class cMapMgr : public cBaseTask {

public:
	vector<cMap>map;		// cMapの宣言
	vector<vector<double>> tmpMap; //仮格納

	string fileName;			//ファイルネーム
	int mapnum;					// 部屋数

	int mapDays;				//何日間のマップか

	VECTOR enemyStartPos;		//敵の開始地点
	vector<FLOAT2> LinePos;		//線を結ぶ部屋の組み合わせを格納

	cMapMgr();
	virtual ~cMapMgr();
  
	virtual void Init();
	virtual void Update();
	virtual void Draw();

	double Get_Ground(int _num);
	int CheckInto(double _x, double _y);
	int GetMapSize();
	vector<vector<int>> GetMapDes();
	int GetStartRoomNum();
	int GetMapDays() { return mapDays; }
	// 髙井追加
	/**************************************************************************
	関数：vector<sMapData> GetMapData()
	説明：マップデータ渡す
	引数：なし
	戻り値：vector<sMapData>:マップデータ
	**************************************************************************/
	vector<sMapData> GetMapData();
};

#endif _INCLUDE_MAPMGR_