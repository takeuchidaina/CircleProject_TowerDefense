#pragma once
#include "DxLib.h"
#include <vector>

#ifndef _CONSTANT_INCLUDE_
#define _CONSTANT_INCLUDE_

/********************************************************
���T�v
  ���ʒ�`�p�w�b�_�[�t�@�C��
  ���̃t�@�C���E�N���X�ł��g���Ǝv���ϐ���`�������Œ�`���A
  �C���N���[�h����Ύg����悤�ɂ���B
  �ړI�F�T�C�Y���̕ύX���y�ɂ���Ɠ����Ƀo�O�����̌����Ƃ��h�~

���쐬��
�@���䗲���Y

********************************************************/

/********************************************************

	�}�N��

********************************************************/

#define WINDOW_WIDTH 1280	// Window��
#define WINDOW_HEIGHT 720	// Window����

#define UNIT_WIDTH 64		// ���j�b�g��
#define UNIT_HEIGHT 64		// ���j�b�g����

#define U_RIGHT 1			// �E����
#define U_LEFT -1			// ������

/********************************************************

	�񋓌^

********************************************************/

// ���j�b�g�̑̒�
typedef enum{

	E_NONE		// ���C�I�I


}eCondition;

// ���j�b�g�̃^�C�v
typedef enum{

	E_SORD,		// ���m
	E_ARCHAR,	// �e��
	E_DEFENSE,	// ��
	E_ESCORT	// ��q�Ώ�
}eUnitType;

// ���j�b�g�̏��
typedef enum{

	E_IDLE,		// �ҋ@��
	E_ATTACK,	// �U����
	E_MOVE		// �ړ���
}eState;

/********************************************************

	�\����

********************************************************/

// ���̈ړ���ݒ�p
typedef struct{

	int sNextRoom;	// �����ԍ�
	double sNextX;	// x���W
}sNextMove;

// �}�b�v�f�[�^�̎󂯓n���p
typedef struct{

	VECTOR pos;		// ���W
	double width;	// ��
	double height;	// ����
	int roomSize;	// ���j�b�g������鐔
}sMapData;

// ���j�b�g�̃^�C�v�ʂ̐��󂯓n���p
typedef struct{

	int sord;		// ���m
	int archar;		// �e��
	int defense;	// ��
}sTypeCnt;

// �v���C���[���j�b�g�̐��f�[�^�󂯓n���p
typedef struct{

	sTypeCnt typeCnt;	// �^�C�v��
	int maxPlayer;		// �ő吔
	int playerCnt;		// �S�̐�
}sUnitData;

// ���j�b�g�����p
typedef struct{

	int unitID;			// �������郆�j�b�gID
	int mapID;			// ��������ꏊ��ID
}sUnitGene;

#endif // !_CONSTANT_INCLUDE_