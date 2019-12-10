#pragma once

#include <vector>
#include "DxLib.h"
#include "BaseTask.h"
#include "ColorListh.h"
#include "Constant.h"
//#include "MapMgr.h"
using namespace std;


#ifndef _MAP_INCLUDE_
#define _MAP_INCLUDE_

struct sDoor {
	sDoor* destination;
	VECTOR pos;
	double width, height;
	int desMap, desDoor;
};

class cMap:public cBaseTask {

private:
	//double m_x, m_y;			//左下座標

	VECTOR m_pos;				//x,y,z(z=0.0f) VECTORはDxLibで定義されている
	double m_width, m_height;	//幅高さ
	int m_maxUnit;				//部屋にいられる最大ユニット数
	int m_roomNum;				//部屋番号
	vector<sDoor> m_door;		//ドアのvector配列
	bool m_startMapFlg;			//開始地点フラグ
	bool m_DefenseMapFlg;		//防衛地点フラグ

	vector<int> m_des;	//ドアなしverの移動先格納vec変数

	int m_mapImg;
	int m_doorImg;


public:

	cMap(double _x, double _y, double _w, double _h,
		int _maxUnit, int _roomNum, vector<sDoor>& _door, bool m_startMapFlg, bool m_DefenseMapFlg);//参照渡し使用

	//ドアなしver
	cMap(double _x, double _y, double _w, double _h,
		int _maxUnit, int _roomNum, vector<int>& _des, bool m_startMapFlg, bool m_DefenseMapFlg, int _mapDays);

	virtual ~cMap() {}
	virtual void Init();
	virtual void Update();
	virtual void Draw();

	//ドアのアドレスのGet関数とSet関数
	//i=ドア番号
	sDoor* GetDestination(int i) { return m_door[i].destination; }
	void SetDestination(int i, sDoor* _des) { m_door[i].destination = _des; }

	bool CheckInto(double, double);
	double Get_Ground() { return m_pos.y; }
	int GetRoomNum() { return m_roomNum; }
	int GetStartFlg() { if (m_startMapFlg == true)return true; }

	vector<int> GetMapDes() { return m_des; }
	
	// 髙井追加
	/**************************************************************************
	関数：int GetRoomSize()
	説明：部屋のPlayerUnitが入る数を渡す
	引数：なし
	戻り値：int:部屋のPlayerUnitが入る数
	**************************************************************************/
	int GetRoomSize();

	/**************************************************************************
	関数：VECTOR GetPos()
	説明：部屋の座標
	引数：なし
	戻り値：VECTOR:部屋の座標
	**************************************************************************/
	VECTOR GetPos();

	/**************************************************************************
	関数：double GetWidth()
	説明：部屋の幅
	引数：なし
	戻り値：double:部屋の幅
	**************************************************************************/
	double GetWidth();

	/**************************************************************************
	関数：double GetHeight()
	説明：部屋の高さ
	引数：なし
	戻り値：double:部屋の高さ
	**************************************************************************/
	double GetHeight();
};

#endif _MAP_INCLUDE_