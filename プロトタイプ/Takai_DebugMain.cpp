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
	// ��ʃT�C�Y�̕ύX
	SetWindowSize(1280, 720);
	SetGraphMode(1280, 720, 16);

	// �E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); 
	
	/*************************************************

�@		���̐錾���s��

	*************************************************/
	cFPS fps;
	//cSceneMgr sceneMgr;
	
	cMap map(100, 200, 800/2, 450/2, 1);

	cUnitMgr player;

	cCamera camera;

	// ���[�v
	while ((ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {

		// esc�������ƏI��

		/*************************************************

		�@Update��Draw�Ȃǂ̖���Ăяo�����̂��L�q����

		*************************************************/
		cMouse::Instance()->Update();
		cMouse::Instance()->Draw();
		
		fps.Update();
		fps.Draw();

		// �v���C���[����
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

		// �v���C���[�ړ�
		if (MOUSE_PRESS(LEFT_CLICK) == 1 && cMouse::Instance()->GetPlayerNum() >= 0 && CheckHitKeyAll != 0)
		{
			int tmp = map.CheckInto(MOUSE_V.x, MOUSE_V.y);
			if (tmp != -1)
			{
				player.Set_NextPlayerPos(cMouse::Instance()->GetPlayerNum(), tmp, MOUSE_V.x);
				cMouse::Instance()->SetPlayerNum(-1);
			}
		}

		// �v���C���[�I��
		if (MOUSE_PRESS(LEFT_CLICK) == 1)
		{
			int tmp = 0;

			tmp = player.CheckPlayerClick(MOUSE_V);
			if (0 <= tmp)
			{
				cMouse::Instance()->SetPlayerNum(tmp);
				DEBUG_LOG("�v���C���[�i���o�[�i�[");
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

	// �I��
	DxLib_End();
	return 0;
}

