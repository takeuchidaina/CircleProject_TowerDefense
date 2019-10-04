#pragma once

#include "BaseTask.h"
#include "Constant.h"
#include <vector>
using namespace std;

#ifndef _INCLUDE_BASE_UNIT_
#define _INCLUDE_BASE_UNIT_

/********************************************************
●概要
　Unitのベースクラス

●作成者
　髙井隆太郎

●更新日
  
********************************************************/

class cBaseUnit : public cBaseTask
{
protected:
	double m_x, m_y;			// 座標
	int m_hp;					// HP
	int m_room;				// 現在いる部屋番号
	int m_atk;				// 攻撃力
	int m_condition;			// 状態異常
	double m_speed;			// 移動速度
	int m_atkCoolTime;		// 次の攻撃までの時間
	int m_nextRoom;			// 次に向かう部屋番号
	double m_atkR;			// 射程範囲
	bool m_isOnActive;		// 生存フラグ
	int m_state;				// 現在の状態
	// cMapMgr* mapMgr			// マップ全体のアドレス

public:

	virtual void Update() {}
	virtual void Draw() {}

	cBaseUnit()
	{
		m_condition = E_NONE;
		m_nextRoom = -1;
		m_isOnActive = true;
		m_state = E_IDLE;
	}

	/*********************************************************************
	関数名：void Set_NextRoom(int)
	概要：次に向かう部屋をセット
	引数：_nextRoom:次に向かう部屋番号
	戻り値：なし
	*********************************************************************/
	void Set_NextRoom(int _nextRoom)
	{
		m_nextRoom = _nextRoom;
	}

};
#endif // !_INCLUDE_BASE_UNIT_