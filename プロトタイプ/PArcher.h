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
		m_pos.x = _x;
		m_pos.y = _y;
		room = _room;
		hp = 30;
		atk = 20;
		speed = 3.0;
		atkCoolTime = 5;
	}

	virtual void Update() {}
	virtual void Draw()
	{
		//DrawCircle(m_pos.x, y, 10, GetColor(255, 0, 0));
	}
	virtual void Set_Target() {}

private:
	virtual void Attack() {}
};
#endif // !_INCLUDE_P_ARCHER_
