#include <iostream>
#include "DxLib.h"
#include "Mouse.h"
#include "FPS.h"
#include "UnitMgr.h"
#include "cMap.h"
#include "Camera.h"
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
	cFPS fps;
	//cSceneMgr sceneMgr;
	
	cMap map(100, 200, 800/2, 450/2, 1);

	cUnitMgr player;

	cCamera camera;

	// ループ
	while ((ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {

		// escを押すと終了

		/*************************************************

		　UpdateやDrawなどの毎回呼び出すものを記述する

		*************************************************/
		cMouse::Instance()->Update();
		cMouse::Instance()->Draw();
		
		fps.Update();
		fps.Draw();

		// プレイヤー生成
		if (MOUSE_PRESS(LEFT_CLICK) == 1 && CheckHitKey(KEY_INPUT_S) >= 1)
		{
			if (-1 != map.CheckInto(MOUSE_V.x, MOUSE_V.y))
			{
				player.Add_PSord(MOUSE_V.x, map.Get_Ground()+UNIT_HEIGHT/2);

			}
		}
		if (MOUSE_PRESS(LEFT_CLICK) == 1 && CheckHitKey(KEY_INPUT_A) >= 1)
		{
			if (-1 != map.CheckInto(MOUSE_V.x, MOUSE_V.y))
			{
				player.Add_PArcher(MOUSE_V.x, map.Get_Ground() + UNIT_HEIGHT / 2);

			}
		}

		if (MOUSE_PRESS(LEFT_CLICK) == 1 && CheckHitKey(KEY_INPUT_E) >= 1)
		{
			if (-1 != map.CheckInto(MOUSE_V.x, MOUSE_V.y))
			{
				player.Add_ESord(MOUSE_V.x, map.Get_Ground() + UNIT_HEIGHT / 2);

			}
		}

		// プレイヤー移動
		if (MOUSE_PRESS(LEFT_CLICK) == 1 && cMouse::Instance()->GetPlayerNum() >= 0 && CheckHitKeyAll != 0)
		{
			int tmp = map.CheckInto(MOUSE_V.x, MOUSE_V.y);
			if (tmp != -1)
			{
				player.Set_NextPlayerPos(cMouse::Instance()->GetPlayerNum(), tmp, MOUSE_V.x);
				cMouse::Instance()->SetPlayerNum(-1);
			}
		}

		// プレイヤー選択
		if (MOUSE_PRESS(LEFT_CLICK) == 1)
		{
			int tmp = 0;

			tmp = player.CheckPlayerClick(MOUSE_V);
			if (0 <= tmp)
			{
				cMouse::Instance()->SetPlayerNum(tmp);
				DEBUG_LOG("プレイヤーナンバー格納");
			}
		}

		map.Draw();
		
		if (cMouse::Instance()->GetPlayerNum() >= 0)
		{
			//player.SelectUI(cMouse::Instance()->GetPlayerNum());
		}
		
		player.Update();
		player.Draw();

		camera.Update();
		camera.Draw();

		cLog::Instance()->Update();
		cLog::Instance()->Draw();
		
	}

	// 終了
	DxLib_End();
	return 0;
}

