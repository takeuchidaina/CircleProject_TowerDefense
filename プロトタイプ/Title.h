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

	const int m_menuNum = E_TITLE_MAX;	//メニュー項目数
	sSelectMenu m_menu[E_TITLE_MAX];	//メニュー情報の実態宣言

	const int FONT_SIZE = 20;	//フォントサイズ
	const int TEXT_X = 350;		//一行目の座標x
	const int TEXT_Y = 300;		//一行目の座標y
	int nowSelect = 0;			//現在の選択メニュー

	int m_background;			//背景画像
	int m_logo;					//ロゴ画像
	int m_startButton;			//開始ボタン
	int m_endButton;			//終了ボタン

};
