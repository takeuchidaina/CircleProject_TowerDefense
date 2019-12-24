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
	//メニュー項目一覧
	typedef enum {
		E_TITLE_MENU,
		E_TITLE_END,
		E_TITLE_MAX,
	}eTitle;

	//使用画像一覧
	typedef enum {
		E_BACK_GROUND,
		//E_LOGO,
		E_IMAGE_MAX,
	}eImage;

	//画像配置の必要情報
	typedef struct {
		sRECT rect = { 0,0,0,0 };	//左上xy,右下xy
		string filePath = "";		    //画像のファイルパス
		int handle = 0;				//画像ハンドル
	}sImage;

	//メニューの必要情報
	typedef struct {
		sImage image;	//画像情報
		int menu = 0;	//メニュー項目
	}sSelectMenu;

	const int m_menuNum = E_TITLE_MAX;	//メニュー項目数
	sSelectMenu m_menu[E_TITLE_MAX];	//メニュー情報の実態宣言

	sImage m_image[E_IMAGE_MAX];	//ボタン以外の画像
	cButton m_btn[E_TITLE_MAX];		//ボタン

};