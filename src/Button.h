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
	���O�@�Fbool ButtonClick();
	�T�v�@�F�{�^�����N���b�N����Ă��邩�ǂ����𔻒f
	�����@�F�Ȃ�
	�߂�l�Ftrue:�N���b�N�@false:�N���b�N����Ă��Ȃ�
	******************************************************/
	bool ButtonClick();

private:

	sRECT m_rect;
	int m_image;		//�摜
	const char* m_text;	//�e�L�X�g
	short m_transNum;	//�����x 0�`255
	short m_fontSize;	//�t�H���g�T�C�Y

	bool buttonType;

	cHit m_hit;
};

#endif // !_INCLUED_BUTTON_