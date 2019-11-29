#pragma once
#include "EnemyUnit.h"
#include "WinBox.h"
#include "ColorListh.h"
#include "Log.h"

#ifndef _INCLUDE_E_SORD_
#define _INCLUDE_E_SORD_

/********************************************************
���T�v
�@�G�l�~�[���m���j�b�g�N���X

���쐬��
�@�Αq���  

���X�V��
�@
********************************************************/

class cESord : public cEnemyUnit {
	  
public:

	cESord(double _x, double _y, int _room, int _num) : cEnemyUnit () {

		m_pos.x = _x;
		m_pos.y = _y;
		m_pos.z = 0.0f;
		m_num = _num;
		m_room = _room;
		m_hp = 50;
		m_atk = 5;
		m_speed = 0.25;
		m_atkCoolTime = 3;
		m_imgNum = 0;
		m_moveCnt = 0;
		m_direction = U_LEFT;
		//target = NULL;
		m_Type = E_SORD;

		if (0 != LoadDivGraph("../resource/img/ESord.png", 6, 3, 2, 64, 64, m_imgtbl))
		{
			ErrBox("�摜�ǂݍ��ݎ��s");
		}

		if (LoadDivGraph("../resource/img/SordEffect.png", 2, 2, 1, 64, 64, m_effectImage) != 0)
		{
			ErrBox("effect�摜�ǂݍ��ݎ��s");
		}
	}

	virtual ~cESord() {}

	VECTOR GetPos()
	{
		return m_pos;
	}
};
#endif // !_INCLUDE_ESORD_