#pragma once

#include "DxLib.h"
#include "DebugList.h"
#include "ColorListh.h"
#include "BaseScene.h"
#include "BaseTask.h"
#include "ISceneChanger.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Button.h"
#include <string.h>
#include "ErrorCheck.h"
#include "Sound.h"

using namespace std;         //  ���O��Ԏw��

class cResult : public cBaseScene {

public:
	cResult(ISceneChanger* _scene);

	void Init()override;
	void Update()override;
	void Draw()override;
	void End()override;

private:
	int m_BG;

	// �摜�z�u�̕K�v���
	typedef struct {
		double ux = 0, uy = 0, dx = 0, dy = 0;	//����xy,�E��xy
		string filePath = "";		//�摜�̃t�@�C���p�X
		int handle = 0;				//�摜�n���h��
	}sImage;

	sImage m_image;
	cButton m_btn;
};
