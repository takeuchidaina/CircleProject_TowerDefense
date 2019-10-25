#pragma once
#include "BaseTask.h"
#include "BaseUnit.h"

#ifndef _INCLUED_ESCORTTARGET_
#define _INCLUED_ESCORTTARGET_

class cEscortTarget : public cBaseTask
{
public:
	cEscortTarget();
	~cEscortTarget();

	virtual void Init();
	virtual void Update();
	virtual void Draw();
	virtual void End();

	//ダメージ計算 true:HPがある　false:HPがない
	bool DamageCalc(int _damage);

private:
	int m_hp;		//HP
	int m_room;		//部屋
	VECTOR m_pos;	//座標
	int m_img;		//画像

};
#endif //_INCLUED_ESCORTTARGET_
