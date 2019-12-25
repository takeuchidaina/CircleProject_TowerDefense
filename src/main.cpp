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
	// ��ʃT�C�Y�̕ύX
	SetWindowIconID(333);
	SetMainWindowText("�C�̌ق���q�c");
	SetWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT, 16);

	// �E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); 
	
	//���Ԑ錾
	cFPS fps;
	cSceneMgr sceneMgr;

	sceneMgr.Init();

	// ���[�v
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

	// �I��
	DxLib_End();
	return 0;
}

