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

********************************************************/

class cPSord : public cPlayerUnit{

public:
	// コンストラクタ
	cPSord(double _x, double _y, int _room, int _num) : cPlayerUnit(){

		m_pos.x = 0.0;
		m_pos.y = 0.0;
		m_pos.z = 0.0f;
		m_num = _num;
		m_room = _room;
		m_hp = 50;
		m_atk = 20;
		m_speed = 0.25;
		m_atkCoolTime = 8;
		m_imgNum = 0;
		m_atkR = UNIT_WIDTH;
		m_atkCoolTime = 64;
		m_Type = E_SORD;

		if (0 != LoadDivGraph("../resource/img/PSord01.png", 6, 3, 2, 64, 64, m_imgtbl))
		{
			ErrBox("画像読み込み失敗");
		}


		if (LoadDivGraph("../resource/img/SordEffect.png", 2, 2, 1, 64, 64, m_effectImage) != 0)
		{
			ErrBox("effect画像読み込み失敗");
		}
	}

	cPSord(sUnitLoad _unitData, int _room, int _num) : cPlayerUnit() {

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
		if (0 != LoadDivGraph(unitPath.c_str(), 10, 5, 2, 256, 256, m_imgtbl))
		{
			ErrBox("画像読み込み失敗");
		}

		string effectPath = "../resource/img/" + _unitData.effectPath;
		if (LoadDivGraph(effectPath.c_str(), 2, 2, 1, 64, 64, m_effectImage) != 0)
		{
			ErrBox("effect画像読み込み失敗");
		}
	}

	virtual ~cPSord(){}

	/*********************************************************************
	関数名：virtual void AttackSE()
	概要：攻撃SE呼び出し
	引数：なし
	戻り値：なし
	*********************************************************************/
	virtual void AttackSE()
	{
		cSound::Instance()->PlaySE(cSound::Instance()->E_SE_SWORD);
	}

};
#endif // !_INCLUDE_P_SORD_
