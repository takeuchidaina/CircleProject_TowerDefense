#pragma once
#include "DxLib.h"
#include "WinBox.h"
#include "PlayerUnit.h"

class cPDefense :public cPlayerUnit
{
public:
	cPDefense(double _x, double _y, int _room, int _num) : cPlayerUnit()
	{
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
		m_atkR = UNIT_WIDTH;
		m_atkCoolTime = 64;
		m_Type = E_DEFENSE;

		if (0 != LoadDivGraph("../resource/img/Shield.png", 6, 3, 2, 64, 64, m_imgtbl))
		{
			ErrBox("âÊëúì«Ç›çûÇ›é∏îs");
		}
	}
};