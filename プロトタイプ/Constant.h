#pragma once

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

#define UNIT_WIDTH 32
#define UNIT_HEIGHT 64

typedef enum
{
	eNone,		// �Ȃ�


}eCondition;

typedef enum
{
	eSword,		// ���m
	eBow,		// �|��
}eUnitType;

typedef enum
{
	eStey,		// �ҋ@��
	eAttack,	// �U����
	eMove,		// �ړ���
}eState;