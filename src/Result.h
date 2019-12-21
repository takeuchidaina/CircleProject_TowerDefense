#pragma once
#ifndef _INCLUED_RESULT_
#define _INCLUED_RESULT_

#include "DxLib.h"
#include "DebugList.h"
#include "ColorListh.h"
#include "Constant.h"
#include "BaseScene.h"
#include "BaseTask.h"
#include "ISceneChanger.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Button.h"
#include <string.h>
#include "ErrorCheck.h"
#include "Sound.h"
using namespace std;

/********************************************************
���T�v
�@���U���g���
 �@�퓬�ŋN���������ʂ�\������

���쐬��
�@�|�� ���
********************************************************/

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
		sRECT rect = { 0,0,0,0 };					//����xy,�E��xy
		string filePath = "";		//�摜�̃t�@�C���p�X
		int handle = 0;				//�摜�n���h��
	}sImage;

	sImage m_image;
	cButton m_btn;
	bool m_result;	//TRUE:���� FALSE:�s�k
	bool m_sound;	//TRUE:�炵�ς� FALSE:�炵�Ă��Ȃ��@BGM
};
#endif // _INCLUED_RESULT_
