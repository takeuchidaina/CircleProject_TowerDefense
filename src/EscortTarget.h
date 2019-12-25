#pragma once
#include "BaseTask.h"
#include "BaseUnit.h"
#include "PlayerUnit.h"
#include "WinBox.h"

#ifndef _INCLUED_ESCORTTARGET_
#define _INCLUED_ESCORTTARGET_

class cEscortTarget : public cPlayerUnit
{
public:
	cEscortTarget(int _room, int _num) : cPlayerUnit()
	{
		m_pos.x = 0.0;
		m_pos.y = 0.0;
		m_pos.z = 0.0f;
		m_num = _num;
		m_room = _room;
		m_hp = 100;
		m_atk = 0;
		m_speed = 0.25;
		m_atkCoolTime = 0;
		m_imgNum = 0;
		m_atkR = UNIT_WIDTH;
		m_atkCoolTime = 64;
		m_Type = E_ESCORT;

		m_img = LoadGraph("../resource/img/EscortTarget.png");
		if (m_img == NULL) {
			ErrBox("宝箱画像読み込み失敗");
		}
	}
	virtual ~cEscortTarget();

	virtual void Init();
	virtual void Update();
	virtual void Draw();
	virtual void End();

	virtual void AttackSE() {}

	//ダメージ計算 true:HPがある　false:HPがない
	bool DamageCalc(int _damage);

private:
	//int m_hp;		//HP
	//int m_room;		//部屋
	//VECTOR m_pos;	//座標
	int m_img;		//画像

};
#endif //_INCLUED_ESCORTTARGET_
