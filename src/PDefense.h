#pragma once
#include "DxLib.h"
#include "WinBox.h"
#include "PlayerUnit.h"

#ifndef _PDEFENSE_INCLUDE_
#define _PDEFENSE_INCLUDE_

class cPDefense :public cPlayerUnit{

public:
	// コンストラクタ
	cPDefense(double _x, double _y, int _room, int _num) : cPlayerUnit(){

		m_pos.x = _x;
		m_pos.y = _y;
		m_pos.z = 0.0f;
		m_num = _num;
		m_room = _room;
		m_hp = 70;
		m_atk = 5;
		m_speed = 0.25;
		m_atkCoolTime = 3;
		m_imgNum = 0;
		m_atkR = UNIT_WIDTH;
		m_atkCoolTime = 64;
		m_Type = E_DEFENSE;

		if (0 != LoadDivGraph("../resource/img/PShield01.png", 6, 3, 2, 64, 64, m_imgtbl))
		{
			ErrBox("画像読み込み失敗");
		}
	}

	cPDefense(sUnitLoad _unitData, int _room, int _num) : cPlayerUnit() {

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
			ErrBox("画像読み込み失敗");
		}

		string effectPath = "../resource/img/" + _unitData.effectPath;
		if (LoadDivGraph(effectPath.c_str(), 2, 2, 1, 64, 64, m_effectImage) != 0)
		{
			//ErrBox("effect画像読み込み失敗");
		}
	}
};

#endif // !_PDEFENSE_INCLUDE_