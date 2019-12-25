#include "Button.h"

cButton::cButton()
{
	m_rect.left = 0, m_rect.top = 0, m_rect.right = 0, m_rect.bottom = 0;
	m_image = 0;
	m_fontSize = 20;
	m_text = "";
	m_transNum = 100;
	buttonType = FALSE;
}

cButton::~cButton(){
	End();
}

/*****************************************************
名前　：bool ButtonClick();
概要　：ボタンがクリックされているかどうかを判断
引数　：なし
戻り値：true:クリック　false:クリックされていない
******************************************************/
void cButton::Init(sRECT _rect, const char* _filePath){
	
	buttonType = TRUE;		//画像タイプのボタン

	//座標代入
	m_rect.top = _rect.top;
	m_rect.left = _rect.left;
	m_rect.right = _rect.right;
	m_rect.bottom = _rect.bottom;

	//画像代入
	m_image = LoadGraph(_filePath);
	FileCheck(m_image);
}

/*****************************************************
名前　：bool ButtonClick();
概要　：ボタンがクリックされているかどうかを判断
引数　：なし
戻り値：true:クリック　false:クリックされていない
******************************************************/
void cButton::Init(sRECT _rect, short _transNum, const char* _text, short _fontSize) {

	buttonType = FALSE;		//図形タイプのボタン

	//座標代入
	m_rect.top = _rect.top;
	m_rect.left = _rect.left;
	m_rect.right = _rect.right;
	m_rect.bottom = _rect.bottom;

	m_text = _text;				//テキスト
	m_transNum = _transNum;		//図形の透明度 0～255
	m_fontSize = _fontSize;		//フォントサイズ
	
}

void cButton::Draw() {

	if (buttonType == TRUE) {
		//指定された場所に指定されたサイズの画像を表示
		DrawExtendGraph(m_rect.left, m_rect.top, m_rect.right, m_rect.bottom, m_image, TRUE);
	}
	else {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_transNum);	//半透明
		DrawBox(m_rect.left, m_rect.top, m_rect.right, m_rect.bottom, BK, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//半透明をオフ

		SetFontSize(m_fontSize);
		DrawFormatString(m_rect.left + m_fontSize,
			m_rect.top + ((m_rect.bottom - m_rect.top) / 2) - m_fontSize / 2, WH, m_text);
	}

}

void cButton::DrawJPG() {
	if (buttonType == TRUE) {
		//指定された場所に指定されたサイズの画像を表示
		DrawExtendGraph(m_rect.left, m_rect.top, m_rect.right, m_rect.bottom, m_image, FALSE);
	}
}

void cButton::End() {
	if (buttonType == FALSE) {
		DeleteGraph(m_image);
	}
}

/*****************************************************
名前　：bool ButtonClick();
概要　：ボタンがクリックされているかどうかを判断
引数　：なし
戻り値：true:クリック　false:クリックされていない
******************************************************/
bool cButton::ButtonClick() {

	//TODO:関数ポインタにする

	//マウスがボタンと重なっているか確認
	if (MOUSE_X > m_rect.left&& MOUSE_X < m_rect.right && MOUSE_Y > m_rect.top&& MOUSE_Y < m_rect.bottom) {
		return TRUE;	//重なっている
	}
	else {
		return FALSE;	//重なっていない
	}
}