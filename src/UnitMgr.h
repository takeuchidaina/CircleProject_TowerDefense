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
#include "UnitGenerateUI.h"
using namespace std;

/********************************************************
●概要
　ユニット全体の制御・仲介
  
●作成者
　髙井隆太郎

********************************************************/

#ifndef _INCLUED_UNIT_MGR_
#define _INCLUED_UNIT_MGR_

#define MOVE_CNT 400

class cUnitMgr : public cBaseTask{

	vector<cPlayerUnit*> player;	// プレイヤー
	vector<cEnemyUnit*> enemy;		// エネミー
	int m_num;						// ナンバー
	int m_selectMarkImg;			// 選択マーカー画像格納
	int m_mapStack;					// マップの数格納

	int m_moveCnt = 0;				// 一定数まで行ったら移動
	int m_moveType = 0;				// moveするTypeを決めるランダム

	vector<vector<int>> m_roomPlayer;	// 各部屋内のプレイヤーID格納
	vector<vector<int>> m_roomEnemy;	// 各部屋内のエネミーID格納

	vector<sUnitLoad> m_unitCsvData;// ユニットCSVデータ

	sTypeCnt m_typeCnt;	//タイプ別のカウント

	vector<sMapData> m_mapData;		// マップデータ

	DATEDATA m_date;				// ランダム関数用日付取得

	cUnitGeneUIMgr *m_geneUI;		// ユニット生成用UIクラスの宣言

	int m_escortCnt;				// 護衛対象の数

public:
	cUnitMgr();
	~cUnitMgr();

	virtual void Update();
	virtual void Draw();

	int UnitGenerate();
	
	/*********************************************************************
	関数名：void Add_PSord(double _x, double _y, int _room)
	概要：剣士の生成
	引数：座標
	戻り値：なし
	*********************************************************************/
	int Add_PSord(double _x, double _y, int _room);

	/*********************************************************************
	関数名：void Add_PArcher(double _x, double _y, int _room)
	概要：弓兵？の生成
	引数：座標
	戻り値：なし
	*********************************************************************/
	int Add_PArcher(double _x, double _y, int _room);
	
	/*********************************************************************
	関数名：void Add_PArcher(double _x, double _y, int _room)
	概要：弓兵？の生成
	引数：座標
	戻り値：なし
	*********************************************************************/
	int Add_PDefense(double _x, double _y, int _room);

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

	// ランダム生成		変更後 (だいご追加)
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
	//bool CheckUnitAdd(int _roomNum);

	/*********************************************************************
	関数名：void TargetSelect()
	概要：ターゲットの検索
	引数：なし
	戻り値：なし
	*********************************************************************/
	//void TargetSelect();

	/*********************************************************************
	関数名：void TargetSelect(int _arrayNum, int _unit)
	概要：ターゲットの検索
	引数：int:検索をするUnitID
		  int:1 プレイヤー / -1 敵
	戻り値：なし
	*********************************************************************/
	void TargetSelect(int _arrayNum, int _unit);

	/*********************************************************************
	関数名：void InRoomUnit()
	概要：部屋ごとにUnitを整理
	引数：なし
	戻り値：なし
	*********************************************************************/
	void InRoomUnit();

	/*********************************************************************
	関数名：void UnitMove()
	概要：移動処理
	引数：なし
	戻り値：なし
	*********************************************************************/
	void UnitMove();

	/*********************************************************************
	関数名：int AttackRelay(int _atkP, int _difNum, int _atkNum)
	概要：攻撃の中継
	引数：int:火力, int:攻撃を受けるUnitナンバー, int:攻撃をするUnitナンバー
	戻り値：なし
	*********************************************************************/
	int AttackRelay(int _atkP, int _difNum, int _atkNum);

	/*********************************************************************
	関数名：bool EscortDie()
	概要：護衛対象が生きているかどうかの判定
	引数：なし
	戻り値：true:生きている
			false:死んだ
	*********************************************************************/
	bool EscortDie();

	/*********************************************************************
	関数名：void UnitDie()
	概要：ユニットが死んだときの処理
	引数：なし
	戻り値：なし
	*********************************************************************/
	void UnitDie();

	/*********************************************************************
	関数名：void NoTarget()
	概要：攻撃対象がいなくなったらIdleへ
	引数：なし
	戻り値：なし
	*********************************************************************/
	void NoTarget();

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
	//int CheckEnemyClick(VECTOR _pos);

	/************************************    Get    *****************************************/

	/*********************************************************************
	関数名：sTypeCnt Get_TypeCnt()
	概要：プレイヤーユニットのタイプ別の数を返す
	引数：なし
	戻り値：sTypeCnt:プレイヤーユニットのタイプ別の数
	*********************************************************************/
	sTypeCnt Get_TypeCnt();

	/************************************    Set    *****************************************/

	/*********************************************************************
	関数名：void Set_MapData(vector<sMapData> _mapData)
	概要：マップデータ格納
	引数：vector<sMapData>:マップデータ
	戻り値：なし
	*********************************************************************/
	void Set_MapData(vector<sMapData> _mapData);

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

};

#endif  // !_INCLUDE_UNIT_MGR_