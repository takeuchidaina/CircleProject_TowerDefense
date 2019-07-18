#pragma once
#include <iostream>
#include "DxLib.h"
#include "BaseTask.h"
#include "DebugList.h"
#include "ColorListh.h"
#include "Singleton.h"

/********************************************************
���T�v
�@�}�E�X�S��
�@�}�E�X�̍��W�≟���Ă��闣���Ă���Ȃǂ��Ǘ���
�@�Q�b�g�֐��Ŏ擾�ł���悤�ɂ��Ă���

���쐬��
�@�|�����

���X�V��
�@2019/7/18:�N���b�N����W�̎擾�֐��̍쐬
********************************************************/

/********************************************************
��(�ȗ���)�֐��Ăяo���ꗗ
�@��)
  �Eif(MOUSE_X > 100)	// �}�E�X��x���W��100���傫��
  �Eif(MOUSE_PRESS(LEFT_CLICK) == 1) // ���N���b�N
********************************************************/
#define MOUSE_X cMouse::instance()->GetX()
#define MOUSE_Y cMouse::Instance()->GetY()
#define MOUSE_PRESS cMouse::Instance()->GetPressCnt
#define MOUSE_RELEASE cMouse::Instance()->GetReleaseCnt

class cMouse : public cSingleton<cMouse> {

	cMouse();
	virtual ~cMouse();
	friend cSingleton< cMouse >;

public:
	// constexpr�ϐ��̒l�̓R���p�C�����Ɍ��肳��ROM���\�Ȓl�ł���B
	// ���̖ړI�́A�v�Z���������s���ł͂Ȃ��R���p�C�����Ɉڂ��āA���s���̃v���O���������������邱�Ƃɂ���B
	static constexpr int LEFT_CLICK = 0;	// ���N���b�N
	static constexpr int RIGHT_CLICK = 1;	// �E�N���b�N

	virtual void Update();
	virtual void Draw();

	/*****************************************************
	���O�@�Fint GetPressCnt(int keyCode);
	�T�v�@�FbuttonPressCnt[keyCode]�̒l��Ԃ�
	�����@�FkeyCode:�t���[������m�肽���L�[�R�[�h
	�߂�l�FkeyCode�̃L�[��������Ă���t���[����
	******************************************************/
	int GetPressCnt(int keyCode);
	/*****************************************************
	���O�@�Fint GetReleaseCnt(int keyCode);
	�T�v�@�FbuttonReleaseCnt[keyCode]�̒l��Ԃ�
	�����@�FkeyCode:�t���[������m�肽���L�[�R�[�h
	�߂�l�FkeyCode�̃L�[��������Ă���t���[�������擾
	******************************************************/
	int GetReleaseCnt(int keyCode);
	/*****************************************************
	���O�@�Fint GetX();
	�T�v�@�F�}�E�X�J�[�\�����W x �̒l��Ԃ�
	�����@�F�Ȃ�
	�߂�l�F�}�E�X�J�[�\�����W x
	******************************************************/
	int GetX() { return x; }
	/*****************************************************
	���O�@�Fint GetY();
	�T�v�@�F�}�E�X�J�[�\�����W y �̒l��Ԃ�
	�����@�F�Ȃ�
	�߂�l�F�}�E�X�J�[�\�����W y
	******************************************************/
	int GetY() { return y; }

private:
	static constexpr int KEY_NUM = 8;	// �L�[����
	int x, y;		// �}�E�X�J�[�\�����Wx,y
	int buttonPressCnt[KEY_NUM];	// ������Ă���J�E���g
	int buttonReleaseCnt[KEY_NUM];	// ������Ă���J�E���g

	/*****************************************************
	���O�@�FIsAvailableCode(int keyCode)
	�T�v�@�F�������L�[�Ƃ��ėL���Ȓl�����m�F����
	�����@�FkeyCode:�e�Q�b�g�֐��łǂ̃L�[���Q�Ƃ��邩
	�@�@�@�@�@�@�@�@�����Ŏ󂯎��������
	�߂�l�FTRUE:�L���@FALSE:����
	�ڍׁ@�F�֐��Ŏ󂯎���������̃G���[�`�F�b�N�p�֐�
	******************************************************/
	bool IsAvailableCode(int keyCode);

};