#pragma once
using namespace std;
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
//#include <deque>
#include "DxLib.h"
#include "BaseTask.h"

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

class cMapMgr : public cBaseTask {
private:
	//deque<deque<string>> csvfname;
	char comma; //区切りとなるカンマ。
	cMapMgr();

public:
	std::vector<cMap> map;		// cMapの宣言

	bool mapLood(string line);				// マップをロードする関数
	string fileName;
	string w (int x, int y);
	int stringChangeInt(int x, int y);		// stringの文字列をintにしてる
	int csvSizeY();							// csvファイルの行を取得
	int csvSizeX(int x);					// 取得した行を指定して列を取得
	int mapnum;								// 部屋数

	void SetComma(char c) { comma = c; }

	cMapMgr() {comma = L','; }
	cMapMgr(string fname) { comma = ','; mapLood(fname); }

	virtual void Init();
	virtual void Update();
	virtual void Draw();
};

#endif _INCLUDE_MAPMGR_