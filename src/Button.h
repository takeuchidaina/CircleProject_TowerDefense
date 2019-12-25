#pragma once
#ifndef _INCLUED_BUTTON_
#define _INCLUED_BUTTON_

#include "DxLib.h"
#include "DebugList.h"
#include "ColorListh.h"
#include "Constant.h"
#include "BaseTask.h"
#include "Mouse.h"
#include "Keyboard.h"
#include "Hit.h"
#include "ErrorCheck.h"

/**********************************************************
●概要
Initで登録さえれた座標にボタンを表示する
クリックされているかの判断も内包
種類１：画像を表示
種類２：図形と文字を表示　透明処理可

●作成者
竹内大奈
**********************************************************/

class cButton : public cBaseTask {

public:

	cButton();
	virtual ~cButton();

	/*****************************************************
	名前　：bool ButtonClick();
	概要　：ボタンがクリックされているかどうかを判断
	引数　：なし
	戻り値：true:クリック　false:クリックされていない
	******************************************************/
	virtual void Init(sRECT _rect, const char* _filepth);

	/*****************************************************
	名前　：bool ButtonClick();
	概要　：ボタンがクリックされているかどうかを判断
	引数　：なし
	戻り値：true:クリック　false:クリックされていない
	******************************************************/
	virtual void Init(sRECT _rect, short _transNum, const char* _text, short _fontSize);

	virtual void Update() {}
	virtual void Draw();
	void DrawJPG();
	virtual void End();

	/*****************************************************
	名前　：bool ButtonClick();
	概要　：ボタンがクリックされているかどうかを判断
	引数　：なし
	戻り値：true:クリック　false:クリックされていない
	******************************************************/
	bool ButtonClick();

	sRECT GetRect() { return m_rect; }

private:

	sRECT m_rect;		//画像座標(y1,x1,x2,y2)
	int m_image;		//画像ハンドル
	const char* m_text;	//表示テキスト
	short m_transNum;	//背景透明度 0～255
	short m_fontSize;	//テキストのフォントサイズ

	bool buttonType;	//ボタンのタイプ　TRUE:画像有　FALSE:画像無しの図形
};

#endif // !_INCLUED_BUTTON_