#pragma once

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

#define UNIT_WIDTH 32
#define UNIT_HEIGHT 40

/********************************************************
���T�v
  ���ʒ�`�p�w�b�_�[�t�@�C��
  ���̃t�@�C���E�N���X�ł��g���Ǝv���ϐ���`�������Œ�`���A
  �C���N���[�h����Ύg����悤�ɂ���B
  �ړI�F�T�C�Y���̕ύX���y�ɂ���Ɠ����Ƀo�O�����̌����Ƃ��h�~

���쐬��
�@���䗲���Y

���X�V��
�@
********************************************************/

typedef enum
{
	E_NONE,		// �Ȃ�


}eCondition;

typedef enum
{
	E_SORD,		// ���m
	E_ARCHER,	// �|��
}eUnitType;

typedef enum
{
	E_IDLE,		// �ҋ@��
	E_ATTACK,	// �U����
	E_MOVE,		// �ړ���
}eState;