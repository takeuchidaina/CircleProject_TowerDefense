#include <iostream>
#include "DxLib.h"
#include "SceneMgr.h"
#include "Mouse.h"
#include "Keyboard.h"
#include "FPS.h"
#include "Log.h"
#include "Sound.h"
#include "Constant.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// 画面サイズの変更
	SetWindowIconID(333);
	SetMainWindowText("海の雇われ護衛団");
	SetWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT, 16);

	// ウィンドウモード変更と初期化と裏画面設定
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); 
	
	//実態宣言
	cFPS fps;
	cSceneMgr sceneMgr;

	sceneMgr.Init();

	// ループ
	while ((ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)){

		cMouse::Instance()->Update();
		cMouse::Instance()->Draw();
		cKeyboard::Instance()->Update();
		cKeyboard::Instance()->Draw();

		fps.Update();
		fps.Draw();

		sceneMgr.Update();
		sceneMgr.Draw();

		cLog::Instance()->Update();
		cLog::Instance()->Draw();
		
	}
	sceneMgr.End();
	cSound::Instance()->End();

	// 終了
	DxLib_End();
	return 0;
}

