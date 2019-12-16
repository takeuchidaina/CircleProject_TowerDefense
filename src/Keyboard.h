#pragma once
#include <iostream>
#include "DxLib.h"
#include "BaseTask.h"
#include "DebugList.h"
#include "ColorListh.h"
#include "Singleton.h"

#ifndef _INCLUED_KEYBOARD_
#define _INCLUED_KEYBOARD_

/********************************************************
���T�v
�@�L�[�{�[�h�̉����Ă���L�[��ǂꂾ��������Ă��邩��Ԃ�

���쐬��
�@�|�����
********************************************************/

/********************************************************
��(�ȗ���)�֐��Ăяo���ꗗ
�@��)
  �Eif( GET_KEY_PRESS(KEY_INPUT_W) == 1)	// w����x�����ꂽ
  �Eif( GET_KEY_RELEASE(KEY_INPUT_W) > 0)	// w��������Ă���
********************************************************/
#define GET_KEY_PRESS cKeyboard::Instance()->GetPressCnt
#define GET_KEY_RELEASE cKeyboard::Instance()->GetReleaseCnt

class cKeyboard : public cSingleton <cKeyboard>
{
	cKeyboard();
	friend cSingleton<cKeyboard>;

public:
	virtual ~cKeyboard();
	virtual void Update();
	virtual void Draw();

	/*****************************************************
	���O�@�Fint GetPressCnt(int _keyCode);
	�T�v�@�FkeyPressCnt[_keyCode]�̒l��Ԃ�
	�����@�F_keyCode:�t���[������m�肽���L�[�R�[�h
	�߂�l�F_keyCode�̃L�[��������Ă���t���[����
	******************************************************/
	int GetPressCnt(int _keyCode);
	/*****************************************************
	���O�@�Fint GetReleaseCnt(int _keyCode);
	�T�v�@�FkeyReleaseCnt[_keyCode]�̒l��Ԃ�
	�����@�F_keyCode:�t���[������m�肽���L�[�R�[�h
	�߂�l�F_keyCode�̃L�[��������Ă���t���[����
	******************************************************/
	int GetReleaseCnt(int _keyCode);

private:
	static const int KEY_NUM = 256;		// �L�[����
	int m_keyPressCnt[KEY_NUM];			// ������Ă���J�E���g
	int m_keyReleaseCnt[KEY_NUM];		// ������Ă���J�E���g

	/*****************************************************
	���O�@�FIsAvailableCode(int _keyCode)
	�T�v�@�F�������L�[�Ƃ��ėL���Ȓl�����m�F����
	�����@�F_keyCode:�e�Q�b�g�֐��łǂ̃L�[���Q�Ƃ��邩
	�@�@�@�@�@�@�@�@ �����Ŏ󂯎��������
	�߂�l�FTRUE:�L���@FALSE:����
	�ڍׁ@�F�֐��Ŏ󂯎���������̃G���[�`�F�b�N�p�֐�
	******************************************************/
	bool IsAvailableCode(int _keyCode);
};
#endif // !_INCLUED_KEYBOARD_

