#pragma once
#include "PlayerUnit.h"
#include "WinBox.h"
#include "ColorListh.h"
#include "Log.h"

#ifndef _INCLUDE_P_SORD_
#define _INCLUDE_P_SORD_

/********************************************************
���T�v
�@�v���C���[���m���j�b�g�N���X

���쐬��
�@���䗲���Y

���X�V��
�@
********************************************************/

class cPSord : public cPlayerUnit
{
public:
	cPSord(double _x, double _y, int _room, int _num) : cPlayerUnit()
	{
		m_pos.x = _x;
		m_pos.y = _y;
		m_pos.z = 0.0f;
		m_num = _num;
		m_room = _room;
		m_hp = 50;
		m_atk = 50;
		m_speed = 0.25;
		m_atkCoolTime = 3;
		m_imgNum = 0;
		m_atkR = UNIT_WIDTH;
		m_atkCoolTime = 64;

		if (0 != LoadDivGraph("../resource/img/player.png", 6, 3, 2, 64, 64, m_imgtbl))
		{
			ErrBox("�摜�ǂݍ��ݎ��s");
		}
	}

	~cPSord()
	{
		// �摜�폜
		
	}

	/*void Update()
	{
		
	}
	void Draw()
	{
		
	}*/

	VECTOR GetPos()
	{
		return m_pos;
	}

};
#endif // !_INCLUDE_PSORD_
