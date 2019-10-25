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

	//�_���[�W�v�Z true:HP������@false:HP���Ȃ�
	bool DamageCalc(int _damage);

private:
	int m_hp;		//HP
	int m_room;		//����
	VECTOR m_pos;	//���W
	int m_img;		//�摜

};
#endif //_INCLUED_ESCORTTARGET_
