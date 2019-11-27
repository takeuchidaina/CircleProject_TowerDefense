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
			ErrBox("画像読み込み失敗");
		}
	}

	~cPArcher(){}

};
#endif // !_INCLUDE_P_ARCHER_
