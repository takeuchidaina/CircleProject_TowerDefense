#include <iostream>
#include "DxLib.h"


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


	// ���[�v
	while ((ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {

		// esc�������ƏI��

		/*************************************************

		�@Update��Draw�Ȃǂ̖���Ăяo�����̂��L�q����

		*************************************************/

	}

	// �I��
	DxLib_End();
	return 0;
}


// �L�[�{�[�h�̌Ăяo��
// CheckHitKey( );
// ()�̒���KEY_INPUT_�����ƋL������
// �����ɑ啶���̃A���t�@�x�b�g�Ȃǂ��L�q
// ��) if(CheckHitKey(KEY_INPUT_W) == 1)  // w�������ꂽ��
// ��) if(CheckHitKey(KEY_INPUT_W) >= 1)  // w��������Ă���Ȃ�
// URL : https://dxlib.xsrv.jp/function/dxfunc_input.html#R5N2

// �}�E�X�̌Ăяo��
// GetMouseInput();
// �ϐ� = GetMouseInput();	// �}�E�X�̓��͂��擾
// ��) if(�ϐ� & MOUSE_INPUT_LEFT ) == 1)	// ���N���b�N���ꂽ��
// URL : https://dxlib.xsrv.jp/function/dxfunc_input.html#R5N8

