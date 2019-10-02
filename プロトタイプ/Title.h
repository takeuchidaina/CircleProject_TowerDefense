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

using namespace std;         //  名前空間指定

class cTitle : public cBaseScene {

public:
	cTitle(ISceneChanger* _scene);

	void Init()override;
	void Update()override;
	void Draw()override;
	void End()override;

private:

#ifndef TITLE_DEBUG
	// メニュー項目一覧
	typedef enum {
		E_TITLE_GAME,
		E_TITLE_END,
		E_TITLE_MAX
	}eTitle;
#endif // !TITLE_DEBUG

#ifdef TITLE_DEBUG
	// メニュー項目一覧
	typedef enum {
		E_TITLE_MENU,
		E_TITLE_GAME,
		E_TITLE_RESULT,
		E_TITLE_END,
		E_TITLE_MAX
	}eTitle;
#endif // TITLE_DEBUG



	// メニューの必要情報
	typedef struct {
		int x, y;
		eTitle menu;
		char text[20];
	}sSelectMenu;

	const int m_menuNum = E_TITLE_MAX;
	sSelectMenu m_menu[E_TITLE_MAX];

	const int FONT_SIZE = 20;
	const int TEXT_X = 350;
	const int TEXT_Y = 300;
	int nowSelect = 0;


};
