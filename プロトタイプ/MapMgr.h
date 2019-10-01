#pragma once
using namespace std;
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdlib.h>

#include "DxLib.h"
#include "BaseTask.h"
#include "Map.h"

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
private:
	//deque<deque<string>> csvfname;
	string comma; //区切りとなるカンマ。
	cMapMgr();

public:
	vector<int> cMap;		// cMapの宣言

	bool MapLood(/*string _line*/);				// マップをロードする関数
	string fileName;
	//string w (int _x, int _y);
	int AsciiToInt(int _x, int _y);		    // stringの文字列をintにしてる
	int CsvSizeY();							// csvファイルの行を取得
	int CsvSizeX(int _x);					// 取得した行を指定して列を取得
	

	// MAPのオープンに使う変数たち
	char MapBase[256];						// (MAP/MAP_)までを入れる
	char MapHandle[256];					//	結果的に開く変数
	char MapNum[256];						// 部屋数とMapのナンバー
	int MapFlag = 1;						// MapNumに代入前の数字	

	void SetComma(string _c) { comma = _c; }

	cMapMgr() {comma = ','; }
	//cMapMgr(string _fname) { comma = ','; MapLood(_fname); }

	virtual void Init();
	virtual void Update();
	virtual void Draw();
};

#endif _INCLUDE_MAPMGR_