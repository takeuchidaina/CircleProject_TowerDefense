#pragma once
#include "EnemyUnit.h"

#ifndef _INCLUDE_E_ARCHER_
#define _INCLUDE_E_ARCHER_

/********************************************************
●概要
　エネミー弓兵ユニットクラス

●作成者
　石倉大瑚

●更新日
　
********************************************************/

class cEArcher : public cEnemyUnit {

public:

	cEArcher(double _x, double _y, int _room, int _num) : cEnemyUnit() {

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
		m_moveCnt = 0;
		m_direction = U_LEFT;
		//target = NULL;

		if (0 != LoadDivGraph("../resource/img/Shield.png", 6, 3, 2, 64, 64, m_imgtbl))
		{
			ErrBox("画像読み込み失敗");
		}
	}

	~cEArcher() {
		// 画像削除
		for (int i = 0; i < 6; i++)
		{
			DeleteGraph(m_imgtbl[i]);
		}
	}
	/*
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
	*/
	virtual void Set_Target() {}

private:
	virtual void Attack() {}
};

#endif // !_INCLUDE_ESORD_