#pragma once
#include "PlayerUnit.h"
#include "WinBox.h"
#include "ColorListh.h"

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
	cPSord(double _x, double _y, int _room) : cPlayerUnit()
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

		if (0 != LoadDivGraph("../resource/img/player.png", 6, 3, 2, 64, 64, m_imgtbl))
		{
			ErrBox("画像読み込み失敗");
		}
	}

	void Update()
	{
		
	}
	void Draw()
	{
		int imgNum = m_moveAnime[m_imgNum];
		if (m_direction == U_RIGHT)
		{
			imgNum += 3;
		}
		
		DrawBillboard3D(m_pos, 0.5f, 0.5f, 64, 0.0f, m_imgtbl[imgNum], TRUE);
		
		//DrawFormatString(100, 400, RD, "%d", imgNum);
	}

	VECTOR GetPos()
	{
		return m_pos;
	}

	/* TODO;
	virtual void Set_Target(vector<cEnemyUnit>* _enemy)
	{
		double distance;

		for (int i = 0; i < _enemy->size(); i++)
		{
			if (room == _enemy[i].Get_room() && distance > fabs(x - _enemy[i].Get_X()))
			{
				target = _enemy[i];
			}
		}
	}
	*/

private:
	virtual void Attack() {}
};
#endif // !_INCLUDE_PSORD_
