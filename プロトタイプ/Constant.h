#pragma once

#define WINDOW_WIDTH 1280	// Window��
#define WINDOW_HEIGHT 720	// Window����

#define UNIT_WIDTH 64		// ���j�b�g��
#define UNIT_HEIGHT 64		// ���j�b�g����

#define U_RIGHT 1			// �E����
#define U_LEFT -1			// ������

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
	eNone,		// �Ȃ�


}eCondition;

typedef enum
{
	eSord,		// ���m
	eArcher,	// �|��
}eUnitType;

typedef enum
{
	eIdle,		// �ҋ@��
	eAttack,	// �U����
	eMove,		// �ړ���
}eState;