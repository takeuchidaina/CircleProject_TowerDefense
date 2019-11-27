#pragma once
#include "PlayerUnit.h"

#ifndef _INCLUDE_P_ARCHER_
#define _INCLUDE_P_ARCHER_

/********************************************************
���T�v
�@�v���C���[�|�����j�b�g�N���X

���쐬��
�@���䗲���Y

���X�V��
�@
********************************************************/

class cPArcher : public cPlayerUnit
{
public:
	cPArcher(double _x, double _y, int _room, int _num) : cPlayerUnit()
	{
		m_pos.x = 0;
		m_pos.y = 0;
		m_pos.z = 0.0f;
		m_num = _num;
		m_room = _room;
		m_hp = 50;
		m_atk = 50;
		m_speed = 0.25;
		m_atkCoolTime = 3;
		m_imgNum = 0;
		m_atkR = 300;
		m_atkCoolTime = 64;

		if (0 != LoadDivGraph("../resource/img/Archar.png", 6, 3, 2, 64, 64, m_imgtbl))
		{
			ErrBox("�摜�ǂݍ��ݎ��s");
		}
	}

	~cPArcher(){}

};
#endif // !_INCLUDE_P_ARCHER_
