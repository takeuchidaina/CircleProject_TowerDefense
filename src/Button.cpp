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
	
	//���W���
	m_rect.top = _rect.top, m_rect.left = _rect.left, m_rect.right = _rect.right, m_rect.bottom = _rect.bottom;

	//�摜���
	m_image = LoadGraph(_filePath);
	FileCheck(m_image);

	buttonType = TRUE;
}

void cButton::Init(sRECT _rect, short _transNum, const char* _text, short _fontSize) {

	//���W���
	m_rect.top = _rect.top, m_rect.left = _rect.left,  m_rect.right = _rect.right, m_rect.bottom = _rect.bottom;

	m_text = _text;
	m_transNum = _transNum;
	m_fontSize = _fontSize;

	buttonType = FALSE;
}

//�N���b�N����Ă��邩�ǂ���
bool cButton::ButtonClick() {

	//�}�E�X���{�^���Əd�Ȃ��Ă��邩�m�F
	if (MOUSE_X > m_rect.left && MOUSE_X < m_rect.right && MOUSE_Y > m_rect.top && MOUSE_Y < m_rect.bottom) {
		return TRUE;	//�d�Ȃ��Ă���
	}
	else {
		return FALSE;	//�d�Ȃ��Ă��Ȃ�
	}
}

void cButton::Draw() {

	if (buttonType == TRUE) {
		//�w�肳�ꂽ�ꏊ�Ɏw�肳�ꂽ�T�C�Y�̉摜��\��
		DrawExtendGraph(m_rect.left, m_rect.top, m_rect.right, m_rect.bottom, m_image, TRUE);
	}
	else {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_transNum);	//������
		DrawBox(m_rect.left, m_rect.top, m_rect.right, m_rect.bottom, BK, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//���������I�t

		SetFontSize(m_fontSize);
		DrawFormatString(m_rect.left + m_fontSize,
			m_rect.top + ((m_rect.bottom - m_rect.top) / 2) - m_fontSize / 2, WH, m_text);
	}

}