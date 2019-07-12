#include <iostream>
#include <vector>       

#include "DxLib.h"
#include "BaseTask.h"
#include "MapMgr.h"

using namespace std;

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

	class cMapMgr : public cBaseTask {

			std::vector<cMap> map;		// cMapの宣言
			int mapnum;	// 部屋数

		virtual void Init() {			// 仮想関数

			FileHandle = FileRead_open();	// .csv　読み込み


			FileHandle = FileRead_close();	// .csv　閉じる

		}

		virtual void Update() {

		}

		virtual void Draw() {

		}

	};



	// ループ
	while ((ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {

		// escを押すと終了

		/*************************************************

		　UpdateやDrawなどの毎回呼び出すものを記述する

		*************************************************/

		////////////////マップ.csvベース
//Map					         Door01	 Door02	 Door03	 Door04	
//x	y	width	height	maxUnit	 x	y	 x	y	 x	y	 x	y



	}

	// 終了
	DxLib_End();
	return 0;
}


