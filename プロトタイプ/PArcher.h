#pragma once
#include "PlayerUnit.h"

#ifndef _INCLUDE_P_ARCHER_
#define _INCLUDE_P_ARCHER_

/********************************************************
●概要
　プレイヤー弓兵ユニットクラス

●作成者
　髙井隆太郎

●更新日
　
********************************************************/

class cPArcher : public cPlayerUnit
{
public:
	cPArcher(double _x, double _y, int _room) : cPlayerUnit()
	{
		m_pos.x = _x;
		m_pos.y = _y;
		m_pos.z = 0.0f;
		m_room = _room;
		m_hp = 50;
		m_atk = 50;
		m_speed = 3.0;
		m_atkCoolTime = 3;
		m_imgNum = 0;
		m_moveCnt = 0;
		m_direction = U_RIGHT;
		//target = NULL;

		if (0 != LoadDivGraph("../resource/img/player2.png", 6, 3, 2, 64, 64, m_imgtbl))
		{
			ErrBox("画像読み込み失敗");
		}
	}

	virtual void Update() {}
	virtual void Draw()
	{
		int imgNum = m_moveAnime[m_imgNum];
		if (m_direction == U_RIGHT)
		{
			imgNum += 3;
		}

		DrawBillboard3D(m_pos, 0.5f, 0.5f, 64, 0.0f, m_imgtbl[imgNum], TRUE);
	}
	virtual void Set_Target() {}

private:
	virtual void Attack() {}
};
#endif // !_INCLUDE_P_ARCHER_
