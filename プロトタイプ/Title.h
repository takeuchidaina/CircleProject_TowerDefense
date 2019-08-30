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

	// メニュー項目一覧
	typedef enum {
		E_MENU_GAME,
		E_MENU_END,
		
	}eMenu;

	// メニューの必要情報
	typedef struct {
		int x, y;
		eMenu menu;
		char text[20];
	}sSelectMenu;

	sSelectMenu m_menu[2];

	static const int fontSize = 30;
	int nowSelect;
	const int menuNum = 2;

};
