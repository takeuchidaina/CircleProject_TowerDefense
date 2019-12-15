#pragma once

#include "DxLib.h"
#include "DebugList.h"
#include "ColorListh.h"
#include "Constant.h"
#include "BaseScene.h"
#include "BaseTask.h"
#include "ISceneChanger.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Button.h"
#include <string.h>
#include "Sound.h"
#include "ErrorCheck.h"
#include "SceneMgr.h"

using namespace std;         //  ���O��Ԏw��

class cTitle : public cBaseScene {

public:
	cTitle(ISceneChanger* _scene);

	void Init()override;
	void Update()override;
	void Draw()override;
	void End()override;

private:

#ifndef TITLE_DEBUG
	// ���j���[���ڈꗗ
	typedef enum {
		E_TITLE_MENU,
		E_TITLE_GAME,
		E_TITLE_RESULT,
		E_TITLE_END,
		E_TITLE_MAX,
	}eTitle;
#endif // TITLE_DEBUG

#ifdef TITLE_DEBUG
	// ���j���[���ڈꗗ
	typedef enum {
		E_TITLE_MENU,
		E_TITLE_END,
		E_TITLE_MAX,
	}eTitle;
#endif // TITLE_DEBUG

	// �摜�̎��
	typedef enum {
		E_BACK_GROUND,
		//E_LOGO,
		E_IMAGE_MAX,
	}eImage;

	// �摜�z�u�̕K�v���
	typedef struct {
		sRECT rect;				//����xy,�E��xy
		string filePath="";		//�摜�̃t�@�C���p�X
		int handle=0;			//�摜�n���h��
	}sImage;

	// ���j���[�̕K�v���
	typedef struct {
		sImage image;			//�摜���
		int menu = 0;			    //���j���[����
	}sSelectMenu;

	const int m_menuNum = E_TITLE_MAX;	//���j���[���ڐ�
	sSelectMenu m_menu[E_TITLE_MAX];	//���j���[���̎��Ԑ錾

	const int FONT_SIZE = 20;	//�t�H���g�T�C�Y
	const int TEXT_X = 350;		//��s�ڂ̍��Wx
	const int TEXT_Y = 300;		//��s�ڂ̍��Wy

	sImage m_image[E_IMAGE_MAX];	//�{�^���ȊO�̉摜
	cButton m_btn[E_TITLE_MAX];		//�{�^��

	
	
};
