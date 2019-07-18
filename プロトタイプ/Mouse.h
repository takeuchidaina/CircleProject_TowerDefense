#pragma once
#include <iostream>
#include "DxLib.h"
#include "DebugList.h"
#include "Singleton.h"

class cMouse : public cSingleton<cMouse> {

	cMouse();
	virtual ~cMouse();
	friend cSingleton< cMouse >;

public:
	static constexpr int LEFT_CLICK = 0;
	static constexpr int RIGHT_CLICK = 1;

	virtual void Update();
	virtual void Draw();

	int GetPressCnt(int keyCode);//keyCodeのキーが押されているフレーム数を取得
	int GetReleaseCnt(int keyCode);//keyCodeのキーが離されているフレーム数を取得
	int GetX() { return x; }
	int GetY() { return y; }

private:
	static constexpr int KEY_NUM = 8;	//キー総数
	int x, y;
	int buttonPressCnt[KEY_NUM];	//押されカウンタ
	int buttonReleaseCnt[KEY_NUM];	//離されカウンタ

	bool isAvailableCode(int keyCode);//keyCodeが有効なキー番号か問う

};