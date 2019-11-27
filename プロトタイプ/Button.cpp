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
	m_ux = 0, m_uy = 0, m_dx = 0, m_dy = 0;
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
	FileCheck(m_image);
}

//�N���b�N����Ă��邩�ǂ���
bool cButton::ButtonClick() {

	if(m_hit.RectOnClick(m_ux,m_uy,m_dx,m_dy) == TRUE) {
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