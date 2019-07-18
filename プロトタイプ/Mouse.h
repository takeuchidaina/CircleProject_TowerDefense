#pragma once
#include <iostream>
#include "DxLib.h"
#include "BaseTask.h"
#include "DebugList.h"
#include "ColorListh.h"
#include "Singleton.h"

/********************************************************
●概要
　マウス全般
　マウスの座標や押している離しているなどを管理し
　ゲット関数で取得できるようにしている

●作成者
　竹内大奈

●更新日
　2019/7/18:クリックや座標の取得関数の作成
********************************************************/

/********************************************************
●(簡略化)関数呼び出し一覧
　例)
  ・if(MOUSE_X > 100)	// マウスのx座標が100より大きい
  ・if(MOUSE_PRESS(LEFT_CLICK) == 1) // 左クリック
********************************************************/
#define MOUSE_X cMouse::instance()->GetX()
#define MOUSE_Y cMouse::Instance()->GetY()
#define MOUSE_PRESS cMouse::Instance()->GetPressCnt
#define MOUSE_RELEASE cMouse::Instance()->GetReleaseCnt

class cMouse : public cSingleton<cMouse> {

	cMouse();
	virtual ~cMouse();
	friend cSingleton< cMouse >;

public:
	// constexpr変数の値はコンパイル時に決定されROM化可能な値である。
	// その目的は、計算処理を実行時ではなくコンパイル時に移して、実行時のプログラムを高速化することにある。
	static constexpr int LEFT_CLICK = 0;	// 左クリック
	static constexpr int RIGHT_CLICK = 1;	// 右クリック

	virtual void Update();
	virtual void Draw();

	/*****************************************************
	名前　：int GetPressCnt(int keyCode);
	概要　：buttonPressCnt[keyCode]の値を返す
	引数　：keyCode:フレーム数を知りたいキーコード
	戻り値：keyCodeのキーが押されているフレーム数
	******************************************************/
	int GetPressCnt(int keyCode);
	/*****************************************************
	名前　：int GetReleaseCnt(int keyCode);
	概要　：buttonReleaseCnt[keyCode]の値を返す
	引数　：keyCode:フレーム数を知りたいキーコード
	戻り値：keyCodeのキーが離されているフレーム数を取得
	******************************************************/
	int GetReleaseCnt(int keyCode);
	/*****************************************************
	名前　：int GetX();
	概要　：マウスカーソル座標 x の値を返す
	引数　：なし
	戻り値：マウスカーソル座標 x
	******************************************************/
	int GetX() { return x; }
	/*****************************************************
	名前　：int GetY();
	概要　：マウスカーソル座標 y の値を返す
	引数　：なし
	戻り値：マウスカーソル座標 y
	******************************************************/
	int GetY() { return y; }

private:
	static constexpr int KEY_NUM = 8;	// キー総数
	int x, y;		// マウスカーソル座標x,y
	int buttonPressCnt[KEY_NUM];	// 押されているカウント
	int buttonReleaseCnt[KEY_NUM];	// 離されているカウント

	/*****************************************************
	名前　：IsAvailableCode(int keyCode)
	概要　：引数がキーとして有効な値かを確認する
	引数　：keyCode:各ゲット関数でどのキーを参照するか
	　　　　　　　　引数で受け取ったもの
	戻り値：TRUE:有効　FALSE:無効
	詳細　：関数で受け取った引数のエラーチェック用関数
	******************************************************/
	bool IsAvailableCode(int keyCode);

};