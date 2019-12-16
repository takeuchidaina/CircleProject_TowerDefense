#pragma once
#include <iostream>
#include "DxLib.h"
#include "BaseTask.h"
#include "DebugList.h"
#include "ColorListh.h"
#include "Singleton.h"

#ifndef _INCLUED_KEYBOARD_
#define _INCLUED_KEYBOARD_

/********************************************************
●概要
　キーボードの押しているキーやどれだけ押されているかを返す

●作成者
　竹内大奈
********************************************************/

/********************************************************
●(簡略化)関数呼び出し一覧
　例)
  ・if( GET_KEY_PRESS(KEY_INPUT_W) == 1)	// wが一度押された
  ・if( GET_KEY_RELEASE(KEY_INPUT_W) > 0)	// wが離されている
********************************************************/
#define GET_KEY_PRESS cKeyboard::Instance()->GetPressCnt
#define GET_KEY_RELEASE cKeyboard::Instance()->GetReleaseCnt

class cKeyboard : public cSingleton <cKeyboard>
{
	cKeyboard();
	friend cSingleton<cKeyboard>;

public:
	virtual ~cKeyboard();
	virtual void Update();
	virtual void Draw();

	/*****************************************************
	名前　：int GetPressCnt(int _keyCode);
	概要　：keyPressCnt[_keyCode]の値を返す
	引数　：_keyCode:フレーム数を知りたいキーコード
	戻り値：_keyCodeのキーが押されているフレーム数
	******************************************************/
	int GetPressCnt(int _keyCode);
	/*****************************************************
	名前　：int GetReleaseCnt(int _keyCode);
	概要　：keyReleaseCnt[_keyCode]の値を返す
	引数　：_keyCode:フレーム数を知りたいキーコード
	戻り値：_keyCodeのキーが離されているフレーム数
	******************************************************/
	int GetReleaseCnt(int _keyCode);

private:
	static const int KEY_NUM = 256;		// キー総数
	int m_keyPressCnt[KEY_NUM];			// 押されているカウント
	int m_keyReleaseCnt[KEY_NUM];		// 離されているカウント

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
#endif // !_INCLUED_KEYBOARD_

