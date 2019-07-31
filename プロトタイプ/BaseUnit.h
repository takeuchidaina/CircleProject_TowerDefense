#pragma once

#include "BaseTask.h"
#include "Constant.h"
#include <vector>
using namespace std;

#define UNIT_WIDTH 64
#define UNIT_HEIGHT 64

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
	//cBaseUnit(int hh, double xx, double yy, int rr, int aa, double ss, int act, double ar)
	//{
	//	hp = hh; x = xx; y = yy; room = rr; atk = aa; speed = ss; atkCoolTime = act; atkR = ar;
	//	isOnActive = true;
	//	nextRoom = -1;
	//	condition = eNone;
	//	state = eStey;
	//}
	//~cBaseUnit();

	void Update() {}
	void Draw() {}

	cBaseUnit()
	{
		condition = eNone;
		nextRoom = -1;
		isOnActive = true;
		state = eStey;
	}

	// 次に向かう部屋のセット
	void Set_NextRoom(int rr)
	{
		nextRoom = rr;
	}

};