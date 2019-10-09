#include <iostream>
#include "DxLib.h"
//#include "SceneMgr.h"
#include "Mouse.h"
//#include "Keyboard.h"
#include "FPS.h"
#include "UnitMgr.h"
#include "cMap.h"
#include "Camera.h"


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

	VECTOR tmpos;

	VECTOR testpos = VGet(0,0,0);

	// ループ
	while ((ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {

		// escを押すと終了

		/*************************************************

		　UpdateやDrawなどの毎回呼び出すものを記述する

		*************************************************/
		cMouse::Instance()->Update();
		cMouse::Instance()->Draw();
		/*cKeyboard::Instance()->Update();
		cKeyboard::Instance()->Draw();*/
		fps.Update();
		fps.Draw();

		//if (cMouse::Instance()->GetReleaseCnt(0) == 1)
		if (MOUSE_PRESS(LEFT_CLICK) == 1)
		{
			if (true == map.CheckInto(MOUSE_V.x, MOUSE_V.y))
			{
				player.Add_PSord(MOUSE_V.x, map.Get_Ground()+UNIT_HEIGHT/2);

			}
			testpos = MOUSE_V;
		}

		DrawFormatString(100, 200, RD, "%f", testpos.x);
		DrawFormatString(100, 250, RD, "%f", testpos.y);

		map.Draw();
		
		player.Update();
		player.Draw();

		/*sceneMgr.Update();
		sceneMgr.Draw();*/
		
		camera.Update();
		camera.Draw();

		/*** 座標 ***/

		DrawLine3D(VGet(0, 0, 0), VGet(100, 0, 0), RD);
		DrawLine3D(VGet(0, 0, 0), VGet(0, 100, 0), GR);

		tmpos = ConvScreenPosToWorldPos(VGet(500, 100, 0.0f));

		DrawCircle(500, 100, 50, RD);
		//DrawCircle(tmpos.x, tmpos.y, 50, RD);
		DrawLine3D(tmpos, VGet(tmpos.x, tmpos.y+100, 0.0f), GR);

	}

	// 終了
	DxLib_End();
	return 0;
}

