#include "Button.h"

cButton::cButton()
{
	m_rect.left = 0, m_rect.top = 0, m_rect.right = 0, m_rect.bottom = 0;
	m_image = 0;
	buttonType = false;
}

cButton::~cButton()
{
	DeleteGraph(m_image);
}

void cButton::Init(sRECT _rect, const char* _filePath){
	
	//座標代入
	m_rect.top = _rect.top, m_rect.left = _rect.left, m_rect.right = _rect.right, m_rect.bottom = _rect.bottom;

	//画像代入
	m_image = LoadGraph(_filePath);
	FileCheck(m_image);

	buttonType = TRUE;
}

void cButton::Init(sRECT _rect, short _transNum, const char* _text, short _fontSize) {

	//座標代入
	m_rect.top = _rect.top, m_rect.left = _rect.left,  m_rect.right = _rect.right, m_rect.bottom = _rect.bottom;

	m_text = _text;
	m_transNum = _transNum;
	m_fontSize = _fontSize;

	buttonType = FALSE;
}

//クリックされているかどうか
bool cButton::ButtonClick() {

	//マウスがボタンと重なっているか確認
	if (MOUSE_X > m_rect.left && MOUSE_X < m_rect.right && MOUSE_Y > m_rect.top && MOUSE_Y < m_rect.bottom) {
		return TRUE;	//重なっている
	}
	else {
		return FALSE;	//重なっていない
	}
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
		DrawFormatString(m_rect.left + m_fontSize, m_rect.top + m_fontSize, WH, m_text);
	}

}