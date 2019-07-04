#include <iostream>
#include "DxLib.h"


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


	// ループ
	while ((ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {

		// escを押すと終了

		/*************************************************

		　UpdateやDrawなどの毎回呼び出すものを記述する

		*************************************************/

	}

	// 終了
	DxLib_End();
	return 0;
}


// キーボードの呼び出し
// CheckHitKey( );
// ()の中にKEY_INPUT_○○と記入する
// ○○に大文字のアルファベットなどを記述
// 例) if(CheckHitKey(KEY_INPUT_W) == 1)  // wが押されたら
// 例) if(CheckHitKey(KEY_INPUT_W) >= 1)  // wが押されているなら
// URL : https://dxlib.xsrv.jp/function/dxfunc_input.html#R5N2

// マウスの呼び出し
// GetMouseInput();
// 変数 = GetMouseInput();	// マウスの入力を取得
// 例) if(変数 & MOUSE_INPUT_LEFT ) == 1)	// 左クリックされたら
// URL : https://dxlib.xsrv.jp/function/dxfunc_input.html#R5N8

