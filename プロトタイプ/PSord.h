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

		if (0 != LoadDivGraph("../resource/img/player.png", 6, 3, 2, 64, 64, m_imgtbl))
		{
			ErrBox("画像読み込み失敗");
		}


		/*if ((m_effectImage = LoadGraph("../resource/img/SordEffect.png")) != 0)
		{
			ErrBox("画像読み込み失敗");
		}*/
	}

	~cPSord(){}

	virtual void AttackAnime()
	{

		if (m_effectAnimeCnt <= 60)
		{
			if (m_direction == U_LEFT)
			{
				
				DrawBillboard3D(VGet(m_pos.x - UNIT_WIDTH, m_pos.y, 0.0f), 0.5f, 0.5f, 64, 0.0f, m_effectImage, TRUE);
			}
			else
			{
				DrawBillboard3D(VGet(m_pos.x + UNIT_WIDTH, m_pos.y, 0.0f), 0.5f, 0.5f, 64, 10.0f, m_effectImage, TRUE);
			}
		}
		else
		{
			m_effectAnimeCnt = 0;
			m_effectFlg = false;
		}

		m_effectAnimeCnt++;
	}

};
#endif // !_INCLUDE_PSORD_
