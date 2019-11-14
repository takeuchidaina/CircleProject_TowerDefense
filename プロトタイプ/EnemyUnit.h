#pragma once
#include <math.h>
#include "BaseUnit.h"
#include "UnitMgr.h"
#include "MapMgr.h"

#ifndef _INCLUDE_ENEMY_UNIT_
#define _INCLUDE_ENEMY_UNIT_

/********************************************************
●概要
　敵ユニットのステータス管理

●作成者

　石倉大瑚
   
●更新日 
********************************************************/

class cEnemyUnit : public cBaseUnit {

protected:
		int m_number;
		cPlayerUnit *target;				// 狙うプレイヤーユニット
		vector<int>mapStack;		//
public:
	/*
	cEnemyUnit() : cBaseUnit() {

	}
	~cEnemyUnit();	
	
	void NextRoom();				  // 次に向かう部屋の選択
	void TargetSelect(_cPlayerUnit*){}	// 射程範囲 引数:調べるプレイヤーのアドレス
	virtual void Update();			  // 計算処理
 	virtual void Draw();			  // 描画処理
    */
	void Attack() 
	{
		//;
	}

	int Get_Num()
	{
		return m_num;
	}

	void Set_NextMove(int _nextRoom, double _nextX)
	{
		m_nextMove.sNextRoom = _nextRoom;
		m_nextMove.sNextX = _nextX;
	}

	void enemyMove() {
		DEBUG_LOG("enemyMove来たよ");
		if (m_room == m_nextMove.sNextRoom)
		{
			if (m_direction = U_LEFT) {

				m_pos.x -= m_speed;
			}
			// プレイヤーと対面したら
			/*
			cUnitMgr::Set_Hit(//m_pos.x, m_pos.y, 64, 64, m_pos.x, m_pos.y, 64, 64));

				DEBUG_LOG("重なったああああ");
				m_state = eAttack;
				m_imgNum = 0;
			*/
		}
		// アニメーション
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
	/*
	void Set_MapSize() {
		mapStack = cMapMgr::GetMapSize;
	}
	*/

	void MapNavigation() {
		for (int i; i < mapSize(); i++) {
			mapStack.push_back(0);
		}
	}

};
#endif  //_INCLUDE_ENEMY_UNIT_