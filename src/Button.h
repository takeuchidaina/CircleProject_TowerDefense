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
���T�v
Init�œo�^�����ꂽ���W�Ƀ{�^����\������
�N���b�N����Ă��邩�̔��f������
��ނP�F�摜��\��
��ނQ�F�}�`�ƕ�����\���@����������

���쐬��
�|�����
**********************************************************/

class cButton : public cBaseTask {

public:

	cButton();
	virtual ~cButton();

	/*****************************************************
	���O�@�Fbool ButtonClick();
	�T�v�@�F�{�^�����N���b�N����Ă��邩�ǂ����𔻒f
	�����@�F�Ȃ�
	�߂�l�Ftrue:�N���b�N�@false:�N���b�N����Ă��Ȃ�
	******************************************************/
	virtual void Init(sRECT _rect, const char* _filepth);

	/*****************************************************
	���O�@�Fbool ButtonClick();
	�T�v�@�F�{�^�����N���b�N����Ă��邩�ǂ����𔻒f
	�����@�F�Ȃ�
	�߂�l�Ftrue:�N���b�N�@false:�N���b�N����Ă��Ȃ�
	******************************************************/
	virtual void Init(sRECT _rect, short _transNum, const char* _text, short _fontSize);

	virtual void Update() {}
	virtual void Draw();
	void DrawJPG();
	virtual void End();

	/*****************************************************
	���O�@�Fbool ButtonClick();
	�T�v�@�F�{�^�����N���b�N����Ă��邩�ǂ����𔻒f
	�����@�F�Ȃ�
	�߂�l�Ftrue:�N���b�N�@false:�N���b�N����Ă��Ȃ�
	******************************************************/
	bool ButtonClick();

	sRECT GetRect() { return m_rect; }

private:

	sRECT m_rect;		//�摜���W(y1,x1,x2,y2)
	int m_image;		//�摜�n���h��
	const char* m_text;	//�\���e�L�X�g
	short m_transNum;	//�w�i�����x 0�`255
	short m_fontSize;	//�e�L�X�g�̃t�H���g�T�C�Y

	bool buttonType;	//�{�^���̃^�C�v�@TRUE:�摜�L�@FALSE:�摜�����̐}�`
};

#endif // !_INCLUED_BUTTON_