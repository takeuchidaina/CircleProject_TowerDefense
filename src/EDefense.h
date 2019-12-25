#pragma once
#include "DxLib.h"
#include "WinBox.h"
#include "EnemyUnit.h"

class cEDefense :public cEnemyUnit
{
public:
	cEDefense(double _x, double _y, int _room, int _num) : cEnemyUnit()
	{
		m_pos.x = _x;
		m_pos.y = _y;
		m_pos.z = 0.0f;
		m_num = _num;
		m_room = _room;
		m_hp = 500;
		m_atk = 0;
		m_speed = 0.25;
		m_atkCoolTime = 0;
		m_imgNum = 0;
		m_atkR = UNIT_WIDTH;
		//m_atkCoolTime = 64;
		m_direction = U_LEFT;
		m_Type = E_DEFENSE;

		if (0 != LoadDivGraph("../resource/img/EShield1.png", 10, 5, 2, 256, 256, m_imgtbl))
		{
			ErrBox("âÊëúì«Ç›çûÇ›é∏îs");
		}
	}
};