#include <iostream>
#include <vector>       

#include "DxLib.h"
#include "BaseTask.h"
#include "MapMgr.h"

using namespace std;

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

	class cMapMgr : public cBaseTask {

			std::vector<cMap> map;		// cMap�̐錾
			int mapnum;	// ������

		virtual void Init() {			// ���z�֐�

			FileHandle = FileRead_open();	// .csv�@�ǂݍ���


			FileHandle = FileRead_close();	// .csv�@����

		}

		virtual void Update() {

		}

		virtual void Draw() {

		}

	};



	// ���[�v
	while ((ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {

		// esc�������ƏI��

		/*************************************************

		�@Update��Draw�Ȃǂ̖���Ăяo�����̂��L�q����

		*************************************************/

		////////////////�}�b�v.csv�x�[�X
//Map					         Door01	 Door02	 Door03	 Door04	
//x	y	width	height	maxUnit	 x	y	 x	y	 x	y	 x	y



	}

	// �I��
	DxLib_End();
	return 0;
}


