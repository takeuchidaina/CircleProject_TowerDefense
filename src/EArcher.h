#pragma once
#include "EnemyUnit.h"

#ifndef _INCLUDE_E_ARCHER_
#define _INCLUDE_E_ARCHER_

/********************************************************
���T�v
�@�G�l�~�[�|�����j�b�g�N���X

���쐬��
�@�Αq���

���X�V��
�@
********************************************************/

class cEArcher : public cEnemyUnit {

public:

	cEArcher(double _x, double _y, int _room, int _num) : cEnemyUnit() {

		m_pos.x = _x;
		m_pos.y = _y;
		m_pos.z = 0.0f;
		m_num = _num;
		m_room = _room;
		m_hp = 100;
		m_atk = 50;
		m_speed = 0.25;
		m_atkCoolTime = 500;
		m_imgNum = 0;
		m_moveCnt = 0;
		m_direction = U_LEFT;
		//target = NULL;
		m_Type = E_ARCHAR;

		if (0 != LoadDivGraph("../resource/img/EArchar1.png", 10, 5, 2, 256, 256, m_imgtbl))
		{
			ErrBox("�摜�ǂݍ��ݎ��s");
		}

		if (LoadDivGraph("../resource/img/ArcharEffect.png", 2, 2, 1, 64, 64, m_effectImage) != 0)
		{
			ErrBox("effect�摜�ǂݍ��ݎ��s");
		}
	}

	virtual ~cEArcher() {}

	virtual void AttackSE()
	{
		cSound::Instance()->PlaySE(cSound::Instance()->E_SE_SHEILD);
	}
};

#endif // !_INCLUDE_ESORD_