#pragma once

#include "DxLib.h"
#include "DebugList.h"
#include "ColorListh.h"
#include "BaseTask.h"
#include "Mouse.h"
#include "Keyboard.h"
#include "Hit.h"
#include "ErrorCheck.h"

#ifndef _INCLUED_BUTTON_
#define _INCLUED_BUTTON_

class cButton : public cBaseTask {

public:
	//左上x,左上y,右下x,右下y,画像のファイルパス
	//cButton(double _ux,double _uy, double _dx, double _dy,const char* _filepth);
	cButton();
	~cButton();

	virtual void Init(double _ux, double _uy, double _dx, double _dy, const char* _filepth);
	virtual void Update() {}
	virtual void Draw();
	virtual void End() {}

	/*****************************************************
	名前　：bool ButtonClick();
	概要　：ボタンがクリックされているかどうかを判断
	引数　：なし
	戻り値：true:クリック　false:クリックされていない
	******************************************************/
	bool ButtonClick();

private:
	double m_ux;		//左上x
	double m_uy;		//左上y
	double m_dx;		//右下x
	double m_dy;		//右下y
	int m_image;		//画像

	cHit m_hit;
};

#endif // !_INCLUED_BUTTON_