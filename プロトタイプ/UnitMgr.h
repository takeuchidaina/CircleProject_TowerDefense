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
#include "EDefense.h"
#include "EscortTarget.h"
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

#define MOVE_CNT 400

class cUnitMgr : public cBaseTask
{
	vector<cPlayerUnit*> player;	// プレイヤー
	vector<cEnemyUnit*> enemy;
	int m_num;	// ナンバー
	int m_selectMarkImg;
	int m_mapStack;					// マップの数格納

	int m_moveCnt = 0;				// 一定数まで行ったら移動
	int m_moveType = 0;				// moveするTypeを決めるランダム

	vector<vector<int>> m_roomPlayer;
	vector<vector<int>> m_roomEnemy;

	sTypeCnt m_typeCnt;	//タイプ別のカウント

	vector<sMapData> m_mapData;

	DATEDATA m_date;
	cBaseUnit m_baseUnit;

	int m_escortCnt;	// 護衛対象の数

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
		if (m_roomPlayer[_room].size() >= m_mapData[_room].roomSize) return -1;
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
		if (m_roomPlayer[_room].size() >= m_mapData[_room].roomSize) return -1;
		player.emplace_back(new cPArcher(_x, _y, _room, m_num));
		m_num++;

		return 0;
	}

	int Add_PDefense(double _x, double _y, int _room)
	{
		if (m_roomPlayer[_room].size() >= m_mapData[_room].roomSize) return -1;
		player.emplace_back(new cPDefense(_x, _y, _room, m_num));
		m_num++;

		return 0;
	}

	/**************************** エネミー ************************/
	/*		クリック生成関数 ESord	変更前
	int Add_ESord(double _x, double _y, int _room)
	{
		if (m_roomEnemy[_room].size() >= m_mapData[_room].roomSize) return 0;
		enemy.emplace_back(new cESord(_x, _y, _room, m_num));
		m_num++;
		DEBUG_LOG("AddESord来たよ");
		//Set_State(eMove);
		return 0;
	}
	// EArcher
	int Add_EArcher(double _x, double _y, int _room)
	{
		if (m_roomEnemy[_room].size() >= m_mapData[_room].roomSize) return 0;
		enemy.emplace_back(new cEArcher(_x, _y, _room, m_num));
		m_num++;

		return 0;
	}
	// EDefense
	int Add_EDefense(double _x, double _y, int _room)
	{
		if (m_roomEnemy[_room].size() >= m_mapData[_room].roomSize) return 0;
		enemy.emplace_back(new cEDefense(_x, _y,  _room, m_num));
		m_num++;

		return 0;
	}
	*/

	// ランダム生成		変更後
	// ESord
	int Add_ESord(double _x, double _y)
	{
		if (m_roomEnemy[2].size() >= m_mapData[2].roomSize) return 0;
		enemy.emplace_back(new cESord(_x, _y, 2, m_num));
		m_num++;
		//DEBUG_LOG("ESord Create");
		return 0;
	}
	// EArcher
	int Add_EArcher(double _x, double _y)
	{
		if (m_roomEnemy[2].size() >= m_mapData[2].roomSize) return 0;
		enemy.emplace_back(new cEArcher(_x, _y, 2, m_num));
		m_num++;

		return 0;
	}
	// EDefense
	int Add_EDefense(double _x, double _y)
	{
		if (m_roomEnemy[2].size() >= m_mapData[2].roomSize) return 0;
		enemy.emplace_back(new cEDefense(_x, _y, 2, m_num));
		m_num++;

		return 0;
	}

	/*********************************************************************
	関数名：void RoomDraw()
	概要：部屋内の描画
	引数：なし
	戻り値：なし
	*********************************************************************/
	void RoomDraw();

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

	void TargetSelect(int _arrayNum, int _unit);

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

	bool EscortDie()
	{
		if (player[0]->Get_Hp() <= 0)
		{
			return false;
		}

		return true;
	}

	void UnitDie()
	{
		for (int i = 0; i < player.size(); i++)
		{
			if (player[i]->Get_Hp() <= 0)
			{
				player.erase(player.begin() + i);
				DEBUG_LOG("player[%d].Die:%d", i, player.size());
			}
		}
		for (int i = 0; i < enemy.size(); i++)
		{
			if (enemy[i]->Get_Hp() <= 0)
			{
				enemy.erase(enemy.begin() + i);
				DEBUG_LOG("enemy[%d].Die:%d", i, enemy.size());
			}
		}
	}

	void NoTarget()
	{
		for (int i = 0; i < player.size(); i++)
		{
			if (player[i]->Get_TargetNum() < 0)
			{
				player[i]->Set_State(E_IDLE);
			}
		}
		for (int i = 0; i < enemy.size(); i++)
		{
			if (enemy[i]->Get_TargetNum() < 0)
			{
				enemy[i]->Set_State(E_IDLE);
			}
		}
	}

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

	sTypeCnt Get_TypeCnt()
	{
		m_typeCnt.sord = 0;
		m_typeCnt.archar = 0;
		m_typeCnt.defense = 0;

		for (int i = 0; i < player.size(); i++)
		{
			switch (player[i]->Get_Type())
			{
			case E_SORD:
				m_typeCnt.sord++;
				break;

			case E_ARCHAR:
				m_typeCnt.archar++;
				break;

			case E_DEFENSE:
				m_typeCnt.defense++;
				break;
			default:
				break;
			}
		}

		return m_typeCnt;
	}

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

	/*********************************************************************
	関数名：void Set_NextEnemyPos(int _enemyNum, int _nextRoom, double _nextX)
	概要：次の行先をセット
	引数：int:移動させるナンバー, int:移動先の部屋番号, int:移動先の座標
	戻り値：なし
	*********************************************************************/
	// だいご追加
	void Set_NextEnemyPos(int _enemyNum, int _nextRoom, int _nextX);
	/*********************************************************************
	関数名：void UnitMove()
	概要：移動処理
	引数：なし
	戻り値：なし
	*********************************************************************/
	void UnitMove();
};

#endif  // !_INCLUDE_UNIT_MGR_