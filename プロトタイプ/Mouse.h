#pragma once
#include <iostream>
#include "DxLib.h"
#include "BaseTask.h"
#include "DebugList.h"
#include "ColorListh.h"
#include "Singleton.h"

#ifndef _INCLUED_MOUSE_
#define _INCLUED_MOUSE_

/********************************************************
���T�v
�@�}�E�X�S��
�@�}�E�X�̍��W�≟���Ă��闣���Ă���A�z�C�[���̉�]�ʂ�
  �Ǘ����Q�b�g�֐��Ŏ擾�ł���悤�ɂ��Ă���

���쐬��
�@�|�����

���X�V��
�@2019/7/18:�N���b�N����W�̎擾�֐��̍쐬
  2019/7/19:�}�E�X�z�C�[���ƃ}�E�X�J�[�\����ON/OFF
********************************************************/

/********************************************************
��(�ȗ���)�֐��Ăяo���ꗗ
�@��)
  �Eif(MOUSE_X > 100)	// �}�E�X��x���W��100���傫��
  �Eif(MOUSE_PRESS(LEFT_CLICK) == 1) // ���N���b�N
********************************************************/
#define MOUSE_X cMouse::Instance()->GetX()
#define MOUSE_Y cMouse::Instance()->GetY()
#define MOUSE_PRESS cMouse::Instance()->GetPressCnt
#define MOUSE_RELEASE cMouse::Instance()->GetReleaseCnt
#define MOUSE_WHEEL cMouse::Instance()->GetWheel()
#define MOUSE_SET cMouse::Instance()->SetMousePoint
#define MOUSE_WHEEL_INIT cMouse::Instance()->InitMouseWheel()
#define MOUSE_DISPLAY cMouse::Instance()->SetMouseDisplay

#define LEFT_CLICK 0
#define RIGHT_CLICK 1

class cMouse : public cSingleton<cMouse> {

	cMouse();
	virtual ~cMouse();
	friend cSingleton< cMouse >;

public:

	virtual void Update();
	virtual void Draw();

#pragma region Get�֐��ꗗ

	/*****************************************************
	���O�@�Fint GetPressCnt(int _keyCode);
	�T�v�@�FbuttonPressCnt[_keyCode]�̒l��Ԃ�
	�����@�F_keyCode:�t���[������m�肽���L�[�R�[�h
	�߂�l�F_keyCode�̃L�[��������Ă���t���[����
	******************************************************/
	int GetPressCnt(int _keyCode);
	/*****************************************************
	���O�@�Fint GetReleaseCnt(int _keyCode);
	�T�v�@�FbuttonReleaseCnt[_keyCode]�̒l��Ԃ�
	�����@�F_keyCode:�t���[������m�肽���L�[�R�[�h
	�߂�l�F_keyCode�̃L�[��������Ă���t���[�������擾
	******************************************************/
	int GetReleaseCnt(int _keyCode);
	/*****************************************************
	���O�@�Fint GetX();
	�T�v�@�F�}�E�X�J�[�\�����W x �̒l��Ԃ�
	�����@�F�Ȃ�
	�߂�l�F�}�E�X�J�[�\�����W x
	******************************************************/
	int GetX();
	/*****************************************************
	���O�@�Fint GetY();
	�T�v�@�F�}�E�X�J�[�\�����W y �̒l��Ԃ�
	�����@�F�Ȃ�
	�߂�l�F�}�E�X�J�[�\�����W y
	******************************************************/
	int GetY();
	/*****************************************************
	���O�@�Fint GetWheel();
	�T�v�@�F�}�E�X�̃X�N���[���� wheel �̒l��Ԃ�
	�����@�F�Ȃ�
	�߂�l�F�X�N���[����
	******************************************************/
	int GetWheel();

#pragma endregion

#pragma region Set,Init�֐��ꗗ

	/*****************************************************
	���O�@�Fvoid SetMousePoint(int _x,int _y);
	�T�v�@�F�}�E�X�J�[�\�����w����W��
	�����@�Fint _x : x���W
�@�@�@�@int _y : y���W
	�߂�l�F�Ȃ�
	******************************************************/
	void SetMousePoint(int _x, int _y);
	/*****************************************************
	���O�@�Fvoid SetMouseWheel();
	�T�v�@�F�z�C�[���̐��l�̏�����
	�����@�F�Ȃ�
	�߂�l�F�Ȃ�
	******************************************************/
	void InitMouseWheel();
	/*****************************************************
	���O�@�Fvoid SetMouseWheel(bool _isDisplay);
	�T�v�@�F�}�E�X�J�[�\���̕\���A��\����ݒ�
	�����@�Fbool isDisplay TRUE:�\���@FALSE:��\��
	�߂�l�F�Ȃ�
	******************************************************/
	void SetMouseDisplay(bool _isDisplay);

#pragma endregion

private:
	static constexpr int KEY_NUM = 8;	// �L�[����
	int m_x, m_y;		// �}�E�X�J�[�\�����Wx,y
	int m_wheel;		// �}�E�X�z�C�[���̃X�N���[����
	int m_buttonPressCnt[KEY_NUM];	// ������Ă���J�E���g
	int m_buttonReleaseCnt[KEY_NUM];	// ������Ă���J�E���g

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

#endif // _INCLUED_MOUSE_
