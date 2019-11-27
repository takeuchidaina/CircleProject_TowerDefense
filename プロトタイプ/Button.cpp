#include "Button.h"

//cButton::cButton(double _ux, double _uy, double _dx, double _dy,const char* _filePath)
//{
//	//座標代入
//	m_ux = _ux,m_uy = _uy,m_dx = _dx,m_dy = _dy;
//	//画像代入
//	m_image = LoadGraph(_filePath);
//	if (m_image == NULL) {
//		//error
//	}
//}
cButton::cButton()
{
	m_ux = 0, m_uy = 0, m_dx = 0, m_dy = 0;
}

cButton::~cButton()
{
	DeleteGraph(m_image);
}

void cButton::Init(double _ux, double _uy, double _dx, double _dy, const char* _filePath){
	
	//座標代入
	m_ux = _ux, m_uy = _uy, m_dx = _dx, m_dy = _dy;

	//画像代入
	m_image = LoadGraph(_filePath);
	FileCheck(m_image);
}

//クリックされているかどうか
bool cButton::ButtonClick() {

	if(m_hit.RectOnClick(m_ux,m_uy,m_dx,m_dy) == TRUE) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

void cButton::Draw() {
	//指定された場所に指定されたサイズの画像を表示
	DrawExtendGraph(m_ux, m_uy, m_dx, m_dy, m_image, TRUE);
}