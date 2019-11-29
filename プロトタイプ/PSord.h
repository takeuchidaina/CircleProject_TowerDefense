#pragma once
#include "PlayerUnit.h"
#include "WinBox.h"
#include "ColorListh.h"
#include "Log.h"

#ifndef _INCLUDE_P_SORD_
#define _INCLUDE_P_SORD_

/********************************************************
●概要
　プレイヤー剣士ユニットクラス

●作成者
　髙井隆太郎

●更新日
　
********************************************************/

class cPSord : public cPlayerUnit
{
public:
	cPSord(double _x, double _y, int _room, int _num) : cPlayerUnit()
	{
		m_pos.x = 0.0;
		m_pos.y = 0.0;
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

		if (0 != LoadDivGraph("../resource/img/player.png", 6, 3, 2, 64, 64, m_imgtbl))
		{
			ErrBox("画像読み込み失敗");
		}


		if (LoadDivGraph("../resource/img/SordEffect.png", 2, 2, 1, 64, 64, m_effectImage) != 0)
		{
			ErrBox("effect画像読み込み失敗");
		}
	}

	virtual ~cPSord(){}

};
#endif // !_INCLUDE_PSORD_
