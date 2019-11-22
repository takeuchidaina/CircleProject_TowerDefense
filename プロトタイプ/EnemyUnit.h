#pragma once
#include <math.h>
#include <list>

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
	int i;
	int m_number;
	cPlayerUnit* target;				// 狙うプレイヤーユニット
	//vector<int>mapStack;		//
	vector<vector<int>> mapStack;		// マップの繋がりを格納するVector


public:

	cEnemyUnit() : cBaseUnit() {

	}

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
		mapStack = cMapMgr::GetMapSize();
	}


	void Set_MapSize() {
		int tmpMapSize = cMapMgr::GetMapSize();
	}

	void MapNavigation() {			// 現在のマップをstackしていく
		for (int i; i < cMapMgr::GetMapSize(); i++) {
			mapStack.push_back(0);
		}
	}
	*/

	// マップの番後のセット関数
	//void SetMapDate(int _i) { mapStack = _i; }	// 田島が作った2重Vectorを代入	




	// 最短距離を求めるアルゴリズム
	void mapSearch() {
		int state = 0;

		const int direction[4][2]{
			{0,1},
			{1,0},
			{0,-1},
			{-1,0}
		};
		typedef struct MAP {
			int x, y;			// マルの座標
			int connection[5];
		};

		MAP map[5] = {
			{100,100,{1,2,4,-1,-1}},
			{400,100,{1,0,4,-1,-1}},
			{200,400,{0,-1,-1,-1,-1}},
			{700,200,{4,-1,-1,-1,-1}},
			{500,600,{3,1,0,-1,-1}}
		};


		while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {

			if (CheckHitKey(KEY_INPUT_0) == 1) {
				state = 0;
			}
			if (CheckHitKey(KEY_INPUT_1) == 1) {
				state = 1;
			}
			if (CheckHitKey(KEY_INPUT_2) == 1) {
				state = 2;
			}
			if (CheckHitKey(KEY_INPUT_3) == 1) {
				state = 3;
			}
			if (CheckHitKey(KEY_INPUT_4) == 1) {
				state = 4;
			}

			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					if (map[i].connection[j] != -1) {
						if (map[i].connection[j] == state) {
							DrawCircle(map[i].x, map[i].y, 30, GetColor(100, 100, 255), true);
							for (int k = 0; k < 4; k++) {
								DrawLine(
									map[i].x + direction[k][0],
									map[i].y + direction[k][1],
									map[map[i].connection[j]].x + direction[k][0],
									map[map[i].connection[j]].y + direction[k][1],
									GetColor(100, 255, 100));
							}
						}
						DrawLine(map[i].x, map[i].y, map[map[i].connection[j]].x, map[map[i].connection[j]].y, GetColor(0, 100, 0));
					}
				}
			}
			for (int i = 0; i < 5; i++) {
				if (i == state) {
					DrawCircle(map[i].x, map[i].y, 30, GetColor(255, 0, 0), true);
				}
				DrawCircle(map[i].x, map[i].y, 20, GetColor(255, 255, 255), true);
			}
		}
	}

};

#endif  //_INCLUDE_ENEMY_UNIT_