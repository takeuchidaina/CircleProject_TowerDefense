#include "Button.h"

//cButton::cButton(double _ux, double _uy, double _dx, double _dy,const char* _filePath)
//{
//	//���W���
//	m_ux = _ux,m_uy = _uy,m_dx = _dx,m_dy = _dy;
//	//�摜���
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
	
	//���W���
	m_ux = _ux, m_uy = _uy, m_dx = _dx, m_dy = _dy;

	//�摜���
	m_image = LoadGraph(_filePath);
	if (m_image == NULL) {
		//error
	}
}

//�N���b�N����Ă��邩�ǂ���
bool cButton::ButtonClick() {

	if(m_hit.Rect(m_ux,m_uy,(m_dx-m_ux),(m_dy-m_ux),
				  MOUSE_X,MOUSE_Y,(MOUSE_X+1),(MOUSE_Y+1)) == TRUE) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

void cButton::Draw() {
	//�w�肳�ꂽ�ꏊ�Ɏw�肳�ꂽ�T�C�Y�̉摜��\��
	DrawExtendGraph(m_ux, m_uy, m_dx, m_dy, m_image, TRUE);
}