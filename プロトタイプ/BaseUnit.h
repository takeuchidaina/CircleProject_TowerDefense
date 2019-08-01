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
	double x, y;			// 座標
	int hp;					// HP
	int room;				// 現在いる部屋番号
	int atk;				// 攻撃力
	int condition;			// 状態異常
	double speed;			// 移動速度
	int atkCoolTime;		// 次の攻撃までの時間
	int nextRoom;			// 次に向かう部屋番号
	double atkR;			// 射程範囲
	bool isOnActive;		// 生存フラグ
	int state;				// 現在の状態
	// cMapMgr* mapMgr			// マップ全体のアドレス

public:

	void Update() {}
	void Draw() {}

	cBaseUnit()
	{
		condition = eNone;
		nextRoom = -1;
		isOnActive = true;
		state = eIdle;
	}

	/*********************************************************************
	関数名：void Set_NextRoom(int)
	概要：次に向かう部屋をセット
	引数：_nextRoom:次に向かう部屋番号
	戻り値：なし
	*********************************************************************/
	void Set_NextRoom(int _nextRoom)
	{
		nextRoom = _nextRoom;
	}

};
#endif // !_INCLUDE_BASE_UNIT_