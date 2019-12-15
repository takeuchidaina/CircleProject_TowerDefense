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
		E_TITLE_MENU,
		E_TITLE_GAME,
		E_TITLE_RESULT,
		E_TITLE_END,
		E_TITLE_MAX,
	}eTitle;
#endif // TITLE_DEBUG

#ifdef TITLE_DEBUG
	// メニュー項目一覧
	typedef enum {
		E_TITLE_MENU,
		E_TITLE_END,
		E_TITLE_MAX,
	}eTitle;
#endif // TITLE_DEBUG

	// 画像の種類
	typedef enum {
		E_BACK_GROUND,
		//E_LOGO,
		E_IMAGE_MAX,
	}eImage;

	// 画像配置の必要情報
	typedef struct {
		sRECT rect;				//左上xy,右下xy
		string filePath="";		//画像のファイルパス
		int handle=0;			//画像ハンドル
	}sImage;

	// メニューの必要情報
	typedef struct {
		sImage image;			//画像情報
		int menu = 0;			    //メニュー項目
	}sSelectMenu;

	const int m_menuNum = E_TITLE_MAX;	//メニュー項目数
	sSelectMenu m_menu[E_TITLE_MAX];	//メニュー情報の実態宣言

	const int FONT_SIZE = 20;	//フォントサイズ
	const int TEXT_X = 350;		//一行目の座標x
	const int TEXT_Y = 300;		//一行目の座標y

	sImage m_image[E_IMAGE_MAX];	//ボタン以外の画像
	cButton m_btn[E_TITLE_MAX];		//ボタン

	
	
};
