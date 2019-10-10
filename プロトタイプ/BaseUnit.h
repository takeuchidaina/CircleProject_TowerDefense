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
	 VECTOR m_pos;			// 座標
	int m_hp;				// HP
	int m_room;				// 現在いる部屋番号
	int m_atk;				// 攻撃力
	int m_condition;		// 状態異常
	double m_speed;			// 移動速度
	int m_atkCoolTime;		// 次の攻撃までの時間
	int m_nextRoom;			// 次に向かう部屋番号
	double m_atkR;			// 射程範囲
	bool m_isOnActive;		// 生存フラグ
	int m_state;			// 現在の状態
	int m_direction;		// ユニットの向き　1(U_RIGHT):右 -1(U_LEFT):左
	int m_moveCnt;			// アニメーション用カウント
	int m_moveAnime[4] = { 1, 0, 1, 2};	// アニメーション配列

	int m_imgNum;			// アニメーションナンバー
	int m_imgtbl[6];		// 画像配列
	// cMapMgr* mapMgr			// マップ全体のアドレス

public:

	void Update()
	{
		switch (m_state)
		{
		case eIdle:

			break;

		case eAttack:

			break;

		case eMove:
			//Move();
			break;

		default:
			break;
		}
	}
	void Draw() {}

	cBaseUnit()
	{
		m_condition = eNone;
		m_nextRoom = -1;
		m_isOnActive = true;
		m_state = eIdle;
		m_atk = 0;
		m_atkCoolTime = 0;
		m_atkR = 0;
		m_hp = 0;

	}

	/*********************************************************************
	関数名：void Move()
	概要：移動処理
	引数：なし
	戻り値：なし
	*********************************************************************/
	void Move()
	{
		
		m_moveCnt++;
		if (m_moveCnt >= 46)
		{
			m_imgNum++;
			if (m_imgNum >= 4)
			{
				m_imgNum = 0;
			}
			m_moveCnt = 0;
		}
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