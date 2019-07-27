#pragma once
#include <iostream>
#include "DxLib.h"
#include "BaseTask.h"
#include "DebugList.h"
#include "ColorListh.h"

#ifndef _INCLUED_FPS_
#define _INCLUED_FPS_

/********************************************************
���T�v
�@FPS�l���Œ肵�܂��B
  ��b�Ԃɂ��Ȃ���΂����Ȃ������𑁂��I���Ă��܂���
  �ꍇ�ɂ͑ҋ@���Ԃ��������܂��B

���쐬��
�|�����

���X�V��
2019/07/26 �쐬
********************************************************/

class cFPS
{
public:
	cFPS();
	virtual ~cFPS();
	void Update();
	void Draw();

private:
	int m_startTime;			// ����J�n����
	int m_count;				// �t���[���̃J�E���g
	float m_fps;				// FPS�l
	static const int FPS = 60;	// �ݒ肷��FPS�l

	/*****************************************************
	���O�@�Fint Wait();
	�T�v�@�F�����������ԂƂ�����ׂ����Ԃ̌v�Z����
	�@�@�@�@�󋵂ɂ���Ă͑҂������s��
	�����@�F�Ȃ�
	�߂�l�F�Ȃ�
	******************************************************/
	void Wait();
};

#endif // !_INCLUED_FPS_

