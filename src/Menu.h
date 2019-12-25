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
		E_MENU_NSCENE,
		E_MENU_BACK,
		E_MENU_SETTING,
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

	typedef enum {
		E_TUTO_TAKARA,
		E_TUTO_SOUSA,
		E_TUTO_TYPE,
		E_TUTO_EXPANTION,
		E_TUTO_LENGTH
	}eTutoRial;

	const int m_menuNum = E_TITLE_MAX;	//���j���[���ڐ�
	sSelectMenu m_menu[E_TITLE_MAX];	//���j���[���̎��Ԑ錾

	sImage m_image[E_IMAGE_MAX];	//�{�^���ȊO�̉摜
	cButton m_btn[E_TITLE_MAX];		//�{�^��

	sRECT m_btnSetumeiRect[E_TUTO_LENGTH];
	cButton m_btnSetumei[E_TUTO_LENGTH];
	string m_setumeiFilePath[E_TUTO_LENGTH];
	bool isExpantion;

};