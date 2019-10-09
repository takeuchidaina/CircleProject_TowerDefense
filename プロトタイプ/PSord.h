#pragma once
#include "PlayerUnit.h"
#include "WinBox.h"

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
		room = _room;
		hp = 50;
		atk = 50;
		speed = 3.0;
		atkCoolTime = 3;
		//target = NULL;

		m_img = LoadGraph("../resource/img/player.png");

		if (0 != LoadDivGraph("../resource/img/player.png", 6, 3, 2, 64, 64, m_imgtbl))
		{
			ErrBox("画像読み込み失敗");
		}
	}

	void Update() {}
	void Draw()
	{
		//DrawBox(x-UNIT_WIDTH/2, y, x+UNIT_WIDTH/2, y+ UNIT_HEIGHT, GetColor(255, 0, 0), TRUE);
		//DrawLine3D(m_pos, VGet(m_pos.x, m_pos.y + 50, 0.0f), GetColor(255, 0, 0));
		DrawBillboard3D(m_pos, 0.5f, 0.5f, 64, 0.0f, m_imgtbl[0], TRUE);
		////DrawModiBillboard3D(m_pos,
		//	64 * 0, 64 * 0,
		//	64 + 64 * 0, 64 * 0,
		//	64 + 64 * 0, 64 + 64 * 0,
		//	64 + 64 * 0, 64 * 0,
		//	m_imgtbl[0], TRUE);
		//DrawGraph(300, 100, m_img, TRUE);
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
