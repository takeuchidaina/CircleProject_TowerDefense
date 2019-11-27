#pragma once

#include "DxLib.h"
#include "DebugList.h"
#include "ColorListh.h"
#include "BaseTask.h"
#include "Mouse.h"
#include "Keyboard.h"
#include "Hit.h"
#include "ErrorCheck.h"

#ifndef _INCLUED_BUTTON_
#define _INCLUED_BUTTON_

class cButton : public cBaseTask {

public:
	//����x,����y,�E��x,�E��y,�摜�̃t�@�C���p�X
	//cButton(double _ux,double _uy, double _dx, double _dy,const char* _filepth);
	cButton();
	~cButton();

	virtual void Init(double _ux, double _uy, double _dx, double _dy, const char* _filepth);
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
	double m_ux;		//����x
	double m_uy;		//����y
	double m_dx;		//�E��x
	double m_dy;		//�E��y
	int m_image;		//�摜

	cHit m_hit;
};

#endif // !_INCLUED_BUTTON_