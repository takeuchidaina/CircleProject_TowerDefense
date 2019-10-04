#pragma once

#include "DxLib.h"
#include "DebugList.h"
#include "ColorListh.h"
#include "BaseScene.h"
#include "BaseTask.h"
#include "ISceneChanger.h"
#include "Keyboard.h"
#include "Mouse.h"
#include <string.h>

using namespace std;         //  ���O��Ԏw��

class cTitle : public cBaseScene {

public:
	cTitle(ISceneChanger* _scene);

	void Init()override;
	void Update()override;
	void Draw()override;
	void End()override;

private:

#ifdef TITLE_DEBUG
	// ���j���[���ڈꗗ
	typedef enum {
		E_TITLE_MENU,
		E_TITLE_GAME,
		E_TITLE_RESULT,
		E_TITLE_END,
		E_TITLE_MAX
	}eTitle;
#endif // TITLE_DEBUG

	// ���j���[�̕K�v���
	typedef struct {
		int x, y;
		eTitle menu;
		char text[20];
	}sSelectMenu;

	const int m_menuNum = E_TITLE_MAX;	//���j���[���ڐ�
	sSelectMenu m_menu[E_TITLE_MAX];	//���j���[���̎��Ԑ錾

	const int FONT_SIZE = 20;	//�t�H���g�T�C�Y
	const int TEXT_X = 350;		//��s�ڂ̍��Wx
	const int TEXT_Y = 300;		//��s�ڂ̍��Wy
	int nowSelect = 0;			//���݂̑I�����j���[

	int m_background;			//�w�i�摜
	int m_logo;					//���S�摜
	int m_startButton;			//�J�n�{�^��
	int m_endButton;			//�I���{�^��

};
