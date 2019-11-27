#include <iostream>
#include "DxLib.h"
#include "SceneMgr.h"
#include "Mouse.h"
#include "Keyboard.h"
#include "FPS.h"
#include "Log.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// 画面サイズの変更
	SetWindowSize(1280, 720);
	SetGraphMode(1280, 720, 16);

	// ウィンドウモード変更と初期化と裏画面設定
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); 
	
	/*************************************************

　		実体宣言を行う

	*************************************************/
	//cFPS fps;
	cSceneMgr sceneMgr;

	sceneMgr.Init();

	// ループ
	while ((ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {

		// escを押すと終了

		/*************************************************

		　UpdateやDrawなどの毎回呼び出すものを記述する

		*************************************************/
		cMouse::Instance()->Update();
		cMouse::Instance()->Draw();
		cKeyboard::Instance()->Update();
		cKeyboard::Instance()->Draw();

		//fps.Update();
		//fps.Draw();

		sceneMgr.Update();
		sceneMgr.Draw();

		cLog::Instance()->Update();
		cLog::Instance()->Draw();
		
	}
	sceneMgr.End();

	// 終了
	DxLib_End();
	return 0;
}

