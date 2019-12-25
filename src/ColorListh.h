#pragma once
#include "DxLib.h"

#ifndef _INCLUED_COLORLIST_
#define _INCLUED_COLORLIST_

/********************************************************
●概要
　Dxライブラリのカラー関数の入力を簡易化することで
  デバッグを楽にすることを想定しています。
  また、色で誰のデバッグ内容か判別。
********************************************************/

/********************************************************
RGB色 一覧
命名規則：色の略語2文字
********************************************************/
#define WH	GetColor(255,255,255)	// 白	システム系
#define BK	GetColor(0,0,0)			// 黒	
#define RD	GetColor(255,0,0)		// 赤	高井
#define GR	GetColor(0,255,0)		// 緑	益子
#define BL	GetColor(0,0,255)		// 青	竹内
#define YL	GetColor(255,255,0)		// 黄	石倉
#define PK	GetColor(234,145,152)	// 桃	田島

#define BR  GetColor(176, 84, 56)		// 茶

#endif // !_INCLUED_COLORLIST_
