#pragma once
#include <iostream>
#include "DxLib.h"
#include "BaseTask.h"
#include "DebugList.h"
#include "ColorListh.h"
#include "Singleton.h"

#ifndef _INCLUED_MOUSE_
#define _INCLUED_MOUSE_

/********************************************************
●概要
　マウス全般
　マウスの座標や押している離している、ホイールの回転量を
  管理しゲット関数で取得できるようにしている

●作成者
　竹内大奈

●更新日
　2019/7/18:クリックや座標の取得関数の作成
  2019/7/19:マウスホイールとマウスカーソルのON/OFF
********************************************************/

/********************************************************
●(簡略化)関数呼び出し一覧
　例)
  ・if(MOUSE_X > 100)	// マウスのx座標が100より大きい
  ・if(MOUSE_PRESS(LEFT_CLICK) == 1) // 左クリック
********************************************************/
#define MOUSE_X cMouse::Instance()->GetX()
#define MOUSE_Y cMouse::Instance()->GetY()
#define MOUSE_PRESS cMouse::Instance()->GetPressCnt
#define MOUSE_RELEASE cMouse::Instance()->GetReleaseCnt
#define MOUSE_WHEEL cMouse::Instance()->GetWheel()
#define MOUSE_SET cMouse::Instance()->SetMousePoint
#define MOUSE_WHEEL_INIT cMouse::Instance()->InitMouseWheel()
#define MOUSE_DISPLAY cMouse::Instance()->SetMouseDisplay

#define LEFT_CLICK 0
#define RIGHT_CLICK 1

class cMouse : public cSingleton<cMouse> {

	cMouse();
	virtual ~cMouse();
	friend cSingleton< cMouse >;

public:

	virtual void Update();
	virtual void Draw();

#pragma region Get関数一覧

	/*****************************************************
	名前　：int GetPressCnt(int _keyCode);
	概要　：buttonPressCnt[_keyCode]の値を返す
	引数　：_keyCode:フレーム数を知りたいキーコード
	戻り値：_keyCodeのキーが押されているフレーム数
	******************************************************/
	int GetPressCnt(int _keyCode);
	/*****************************************************
	名前　：int GetReleaseCnt(int _keyCode);
	概要　：buttonReleaseCnt[_keyCode]の値を返す
	引数　：_keyCode:フレーム数を知りたいキーコード
	戻り値：_keyCodeのキーが離されているフレーム数を取得
	******************************************************/
	int GetReleaseCnt(int _keyCode);
	/*****************************************************
	名前　：int GetX();
	概要　：マウスカーソル座標 x の値を返す
	引数　：なし
	戻り値：マウスカーソル座標 x
	******************************************************/
	int GetX();
	/*****************************************************
	名前　：int GetY();
	概要　：マウスカーソル座標 y の値を返す
	引数　：なし
	戻り値：マウスカーソル座標 y
	******************************************************/
	int GetY();
	/*****************************************************
	名前　：int GetWheel();
	概要　：マウスのスクロール量 wheel の値を返す
	引数　：なし
	戻り値：スクロール量
	******************************************************/
	int GetWheel();

#pragma endregion

#pragma region Set,Init関数一覧

	/*****************************************************
	名前　：void SetMousePoint(int _x,int _y);
	概要　：マウスカーソルを指定座標へ
	引数　：int _x : x座標
　　　　int _y : y座標
	戻り値：なし
	******************************************************/
	void SetMousePoint(int _x, int _y);
	/*****************************************************
	名前　：void SetMouseWheel();
	概要　：ホイールの数値の初期化
	引数　：なし
	戻り値：なし
	******************************************************/
	void InitMouseWheel();
	/*****************************************************
	名前　：void SetMouseWheel(bool _isDisplay);
	概要　：マウスカーソルの表示、非表示を設定
	引数　：bool isDisplay TRUE:表示　FALSE:非表示
	戻り値：なし
	******************************************************/
	void SetMouseDisplay(bool _isDisplay);

#pragma endregion

private:
	static constexpr int KEY_NUM = 8;	// キー総数
	int m_x, m_y;		// マウスカーソル座標x,y
	int m_wheel;		// マウスホイールのスクロール量
	int m_buttonPressCnt[KEY_NUM];	// 押されているカウント
	int m_buttonReleaseCnt[KEY_NUM];	// 離されているカウント

	/*****************************************************
	名前　：IsAvailableCode(int _keyCode)
	概要　：引数がキーとして有効な値かを確認する
	引数　：_keyCode:各ゲット関数でどのキーを参照するか
	　　　　　　　　 引数で受け取ったもの
	戻り値：TRUE:有効　FALSE:無効
	詳細　：関数で受け取った引数のエラーチェック用関数
	******************************************************/
	bool IsAvailableCode(int _keyCode);

};

#endif // _INCLUED_MOUSE_
