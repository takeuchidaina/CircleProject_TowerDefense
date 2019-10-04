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
	//
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
	if (m_image == NULL) {
		//error
	}
}

bool cButton::ButtonClick() {
	//クリックされているかどうか
	return true;
}

void cButton::Draw() {
	//指定された場所に指定されたサイズの画像を表示
	DrawExtendGraph(m_ux, m_uy, m_dx, m_dy, m_image, TRUE);
}