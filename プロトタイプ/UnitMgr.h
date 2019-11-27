#pragma once
#include "BaseTask.h"
#include "DxLib.h"
#include "DebugList.h"
#include "PlayerUnit.h"
#include "EnemyUnit.h"
#include "Constant.h"
#include "PSord.h"
#include "PArcher.h"
#include "PDefense.h"
#include "ESord.h"
#include "EArcher.h"
#include "Mouse.h"
#include <vector>
#include "Log.h"
using namespace std;

/********************************************************
●概要
　ユニット全体の制御・仲介
  
●作成者
　髙井隆太郎

●更新日
　
********************************************************/

#ifndef _INCLUED_UNIT_MGR_
#define _INCLUED_UNIT_MGR_

class cUnitMgr : public cBaseTask
{
	vector<cPlayerUnit*> player;	// プレイヤー
	vector<cEnemyUnit*> enemy;
	int m_num;	// ナンバー
	int m_selectMarkImg;
	int m_mapStack;					// マップの数格納
	vector<vector<int>> m_roomPlayer;
	vector<vector<int>> m_roomEnemy;

	vector<sMapData> m_mapData;

	// 仮
	float m_mapWidth;
	float m_mapHiight;

public:
	cUnitMgr();
	~cUnitMgr();

	void Update();
	void Draw();
	

	/*********************************************************************
	関数名：void Add_PSord(double _x, double _y, int _room)
	概要：剣士の生成
	引数：座標
	戻り値：なし
	*********************************************************************/
	int Add_PSord(double _x, double _y, int _room)
	{
		if (m_roomPlayer[_room].size() >= m_mapData[_room].roomSize) return 0;
  		player.emplace_back(new cPSord(_x, _y, _room, m_num));
		DEBUG_LOG("playerSize:%d", player.size());
		m_num++;

		return 0;
	}
	/*********************************************************************
	関数名：void Add_PArcher(double _x, double _y, int _room)
	概要：弓兵？の生成
	引数：座標
	戻り値：なし
	*********************************************************************/
	int Add_PArcher(double _x, double _y, int _room)
	{
		if (m_roomPlayer[_room].size() >= m_mapData[_room].roomSize) return 0;
		player.emplace_back(new cPArcher(_x, _y, _room, m_num));
		m_num++;

		return 0;
	}

	/**************************** エネミー ************************/
	
	void Add_ESord(double _x, double _y, int _room)
	{
		enemy.emplace_back(new cESord(_x, _y, _room, m_num));
		m_num++;
		DEBUG_LOG("AddESord来たよ");
		//Set_State(eMove);
	}

	void Add_EArcher(double _x, double _y, int _room)
	{
		enemy.emplace_back(new cEArcher(_x, _y, _room, m_num));
		m_num++;
	}

	void Add_ESord(double _x, double _y)
	{
		enemy.emplace_back(new cPDefense(_x, _y,  1, m_num));
		m_num++;
	}

	void RoomDraw()
	{
		for (int i = 0; i < m_roomPlayer.size(); i++)
		{
			for (int j = 0; j < m_roomPlayer[i].size(); j++)
			{
				int playerNum = m_roomPlayer[i][j];

				int arreyNum = PlayerArreySearch(playerNum);


				float x = 0;
				float width = m_mapData[i].width - m_mapData[i].pos.x;
				int wPos = (m_mapData[i].roomSize + 1) - j;

				x = width / 2 / (m_mapData[i].roomSize+3) * wPos;
				x += m_mapData[i].pos.x;

				float y = 0;
				float height = m_mapData[i].height - m_mapData[i].pos.y;
				int hPos = (m_mapData[i].roomSize + 1) - j;

				y = height / 2 / (m_mapData[i].roomSize+1) * hPos;
				y += m_mapData[i].pos.y;

				player[arreyNum]->Set_Pos(VGet(x, y, -(j/10)));

				//int num = m_mapData[i].roomSize - j;

				player[arreyNum]->Draw();
			}
		}
	}

	/*********************************************************************
	関数名：bool CheckUnitAdd(int _roomNum)
	概要：引数の部屋にUnitが入れるか調べる
	引数：int:入りたい部屋番号
	戻り値：true:入れる
			false:入れない
	*********************************************************************/
	bool CheckUnitAdd(int _roomNum);

	/*********************************************************************
	関数名：void TargetSelect()
	概要：ターゲットの検索
	引数：なし
	戻り値：なし
	*********************************************************************/
	void TargetSelect();

	/*********************************************************************
	関数名：void InRoomUnit()
	概要：部屋ごとにUnitを整理
	引数：なし
	戻り値：なし
	*********************************************************************/
	void InRoomUnit();

	/*********************************************************************
	関数名：int AttackRelay(int _atkP, int _difNum, int _atkNum)
	概要：攻撃の中継
	引数：int:火力, int:攻撃を受けるUnitナンバー, int:攻撃をするUnitナンバー
	戻り値：なし
	*********************************************************************/
	int AttackRelay(int _atkP, int _difNum, int _atkNum);

	/*********************************************************************
	関数名：int PlayerArreySearch(int _num)
	概要：Unitナンバーからプレイヤーを探す
	引数：int:検索するUnitナンバー
	戻り値：なし
	*********************************************************************/
	int PlayerArreySearch(int _num);

	/*********************************************************************
	関数名：int EnemyArreySearch(int _num)
	概要：Unitナンバーからエネミーを探す
	引数：int:検索するUnitナンバー
	戻り値：なし
	*********************************************************************/
	int EnemyArreySearch(int _num);

	/*********************************************************************
	関数名：int CheckPlayerClick(VECTOR _pos);
	概要：プレイヤーとの当たり判定
	引数：VECTOR:座標
	戻り値：int:当たったプレイヤーのナンバー -1:外れ
	*********************************************************************/
	int CheckPlayerClick(VECTOR _pos);

	// だいご追加
	int CheckEnemyClick(VECTOR _pos);

	void Set_MapData(vector<sMapData> _mapData)
	{
		m_mapData = _mapData;
	}

	/*********************************************************************
	関数名：void Set_NextPlayerPos(int _playerNum, int _nextRoom, double _nextX)
	概要：次の行先をセット
	引数：int:移動させるナンバー, int:移動先の部屋番号, double:移動先の座標
	戻り値：なし
	*********************************************************************/
	void Set_NextPlayerPos(int _playerNum, int _nextRoom, double _nextX);

	/*********************************************************************
	関数名：void SelectUI(int _num)
	概要：選択されているUnitのUI表示
	引数：int:Unitナンバー
	戻り値：なし
	*********************************************************************/
	void SelectUI(int _num);	//-1	// 触れてるか	//mouse X

	// だいご追加
	void Set_NextEnemyPos(int _enemyNum, int _nextRoom, double _nextX);
};

#endif  // !_INCLUDE_UNIT_MGR_