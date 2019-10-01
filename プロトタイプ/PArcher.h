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
	cPArcher(double _x, double _y, int _room) : cPlayerUnit()
	{
		m_x = _x;
		m_y = _y;
		m_room = _room;
		m_hp = 30;
		m_atk = 20;
		m_speed = 3.0;
		m_atkCoolTime = 5;
	}

	virtual void Update() {}
	virtual void Draw()
	{
		DrawCircle(m_x, m_y, 10, GetColor(255, 0, 0));
	}
	virtual void Set_Target() {}

private:
	virtual void Attack() {}
};
#endif // !_INCLUDE_P_ARCHER_
