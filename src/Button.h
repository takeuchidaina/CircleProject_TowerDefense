#pragma once

#include "DxLib.h"
#include "DebugList.h"
#include "ColorListh.h"
#include "Constant.h"
#include "BaseTask.h"
#include "Mouse.h"
#include "Keyboard.h"
#include "Hit.h"
#include "ErrorCheck.h"

#ifndef _INCLUED_BUTTON_
#define _INCLUED_BUTTON_

class cButton : public cBaseTask {

public:

	cButton();
	~cButton();

	virtual void Init(sRECT _rect, const char* _filepth);
	virtual void Init(sRECT _rect, short _transNum, const char* _text, short _fontSize);
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

	sRECT m_rect;
	int m_image;		//画像
	const char* m_text;	//テキスト
	short m_transNum;	//透明度 0～255
	short m_fontSize;	//フォントサイズ

	bool buttonType;

	cHit m_hit;
};

#endif // !_INCLUED_BUTTON_