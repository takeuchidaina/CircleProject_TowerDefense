#pragma once
#include "BaseTask.h"
#include "BaseUnit.h"
#include "PlayerUnit.h"

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
		m_hp = 500;
		m_atk = 0;
		m_speed = 0.25;
		m_atkCoolTime = 0;
		m_imgNum = 0;
		m_atkR = UNIT_WIDTH;
		m_atkCoolTime = 64;

		m_img = LoadGraph("../resource/img/sample.png");
		if (m_img == NULL) {
			DrawString(50, 50, "�摜���s", GetColor(255, 0, 255));
		}
	}
	virtual ~cEscortTarget();

	virtual void Init();
	virtual void Update();
	//void Draw();
	virtual void End();

	//�_���[�W�v�Z true:HP������@false:HP���Ȃ�
	bool DamageCalc(int _damage);

private:
	int m_hp;		//HP
	int m_room;		//����
	VECTOR m_pos;	//���W
	int m_img;		//�摜

};
#endif //_INCLUED_ESCORTTARGET_
