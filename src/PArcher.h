#pragma once
#include "PlayerUnit.h"

#ifndef _INCLUDE_P_ARCHER_
#define _INCLUDE_P_ARCHER_

/********************************************************
���T�v
�@�v���C���[�|�����j�b�g�N���X

���쐬��
�@���䗲���Y

********************************************************/

class cPArcher : public cPlayerUnit{

public:
	// �R���X�g���N�^
	cPArcher(double _x, double _y, int _room, int _num) : cPlayerUnit(){

		m_pos.x = 0.0;
		m_pos.y = 0.0;
		m_pos.z = 0.0f;
		m_num = _num;
		m_room = _room;
		m_hp = 40;
		m_atk = 10;
		m_speed = 0.25;
		m_atkCoolTime = 3;
		m_imgNum = 0;
		m_atkR = 300;
		m_atkCoolTime = 64;
		m_Type = E_ARCHAR;

		if (0 != LoadDivGraph("../resource/img/PArchar01.png", 6, 3, 2, 64, 64, m_imgtbl))
		{
			ErrBox("�摜�ǂݍ��ݎ��s");
		}
		if (LoadDivGraph("../resource/img/ArcharEffect.png", 2, 2, 1, 64, 64, m_effectImage) != 0)
		{
			ErrBox("effect�摜�ǂݍ��ݎ��s");
		}
	}

	cPArcher(sUnitLoad _unitData, int _room, int _num) : cPlayerUnit() {

		m_pos.x = 0.0;
		m_pos.y = 0.0;
		m_pos.z = 0.0f;
		m_num = _num;
		m_room = _room;
		m_hp = _unitData.HP;
		m_atk = _unitData.ATK;
		m_speed = _unitData.speed;
		m_atkCoolTime = _unitData.coolTime;
		m_imgNum = 0;
		m_atkR = 300;
		m_Type = _unitData.type;
		m_Defense = _unitData.DEF;

		string unitPath = "../resource/img/" + _unitData.unitPath;
		if (0 != LoadDivGraph(unitPath.c_str(), 6, 3, 2, 64, 64, m_imgtbl))
		{
			ErrBox("�摜�ǂݍ��ݎ��s");
		}

		string effectPath = "../resource/img/" + _unitData.effectPath;
		if (LoadDivGraph(effectPath.c_str(), 2, 2, 1, 64, 64, m_effectImage) != 0)
		{
			ErrBox("effect�摜�ǂݍ��ݎ��s");
		}
	}

	virtual ~cPArcher(){}

	/*********************************************************************
	�֐����Fvirtual void AttackSE()
	�T�v�F�U��SE�Ăяo��
	�����F�Ȃ�
	�߂�l�F�Ȃ�
	*********************************************************************/
	virtual void AttackSE()
	{
		cSound::Instance()->PlaySE(cSound::Instance()->E_SE_ARROW);
	}

	//virtual void AttackAnime();

};
#endif // !_INCLUDE_P_ARCHER_
