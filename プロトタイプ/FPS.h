#pragma once
#include <iostream>
#include "DxLib.h"
#include "BaseTask.h"
#include "DebugList.h"
#include "ColorListh.h"

#ifndef _INCLUED_FPS_
#define _INCLUED_FPS_

/********************************************************
●概要
　FPS値を固定します。
  一秒間にしなければいけない処理を早く終えてしまった
  場合には待機時間が発生します。

●作成者
竹内大奈

●更新日
2019/07/26 作成
********************************************************/

class cFPS
{
public:
	cFPS();
	virtual ~cFPS();
	void Update();
	void Draw();

private:
	int m_startTime;			// 測定開始時刻
	int m_count;				// フレームのカウント
	float m_fps;				// FPS値
	static const int FPS = 60;	// 設定するFPS値

	/*****************************************************
	名前　：int Wait();
	概要　：かかった時間とかかるべき時間の計算をし
	　　　　状況によっては待つ処理を行う
	引数　：なし
	戻り値：なし
	******************************************************/
	void Wait();
};

#endif // !_INCLUED_FPS_

