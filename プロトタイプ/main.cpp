#include <iostream>
#include "DxLib.h"
#include "SceneMgr.h"
#include "Mouse.h"
#include "Keyboard.h"
#include "FPS.h"
#include "Log.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// ��ʃT�C�Y�̕ύX
	SetWindowSize(1280, 720);
	SetGraphMode(1280, 720, 16);

	// �E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); 
	
	/*************************************************

�@		���̐錾���s��

	*************************************************/
	//cFPS fps;
	cSceneMgr sceneMgr;

	sceneMgr.Init();

	// ���[�v
	while ((ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {

		// esc�������ƏI��

		/*************************************************

		�@Update��Draw�Ȃǂ̖���Ăяo�����̂��L�q����

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

	// �I��
	DxLib_End();
	return 0;
}

