#pragma once

#include "DxLib.h"
#include "DebugList.h"
#include "ColorListh.h"
#include "BaseScene.h"
#include "BaseTask.h"
#include "ISceneChanger.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Log.h"
#include "Button.h"
#include "Sound.h"

class cMenu : public cBaseScene {

public:
	cMenu(ISceneChanger* _scene);

	void Init()override;
	void Update()override;
	void Draw()override;
	void End()override;

private:
	//���j���[���ڈꗗ
	typedef enum {
		E_TITLE_MENU,
		E_TITLE_END,
		E_TITLE_MAX,
	}eTitle;

	//�g�p�摜�ꗗ
	typedef enum {
		E_BACK_GROUND,
		//E_LOGO,
		E_IMAGE_MAX,
	}eImage;

	//�摜�z�u�̕K�v���
	typedef struct {
		sRECT rect = { 0,0,0,0 };	//����xy,�E��xy
		string filePath = "";		    //�摜�̃t�@�C���p�X
		int handle = 0;				//�摜�n���h��
	}sImage;

	//���j���[�̕K�v���
	typedef struct {
		sImage image;	//�摜���
		int menu = 0;	//���j���[����
	}sSelectMenu;

	const int m_menuNum = E_TITLE_MAX;	//���j���[���ڐ�
	sSelectMenu m_menu[E_TITLE_MAX];	//���j���[���̎��Ԑ錾

	sImage m_image[E_IMAGE_MAX];	//�{�^���ȊO�̉摜
	cButton m_btn[E_TITLE_MAX];		//�{�^��

};