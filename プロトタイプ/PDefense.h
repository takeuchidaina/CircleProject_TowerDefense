#pragma once
#include "DxLib.h"
#include "WinBox.h"
#include "EnemyUnit.h"

// ‰¼‚ÅEnemy‚Æ‚µ‚Äˆµ‚Á‚Ä‚¢‚é

class cPDefense :public cEnemyUnit
{
public:
	cPDefense(double _x, double _y, int _room, int _num) : cEnemyUnit()
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

		if (0 != LoadDivGraph("../resource/img/Shield.png", 6, 3, 2, 64, 64, m_imgtbl))
		{
			ErrBox("‰æ‘œ“Ç‚İ‚İ¸”s");
		}
	}
};