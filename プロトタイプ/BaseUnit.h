#pragma once

#include "BaseTask.h"
#include "Constant.h"
#include <vector>
#include "Log.h"
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
	int m_num;				// ユニット番号
	int m_Type;				// ユニットタイプ
	int m_targetNum;		// 攻撃対象の番号
	int m_hp;				// HP
	int m_room;				// 現在いる部屋番号
	int m_atk;				// 攻撃力
	int m_condition;		// 状態異常
	double m_speed;			// 移動速度
	int m_atkCoolTime;		// 次の攻撃までの時間
	int m_atkCnt;			// 攻撃までのカウント
	double m_atkR;			// 射程範囲
	int m_Defense;			// 防御
	bool m_isOnActive;		// 生存フラグ
	int m_state;			// 現在の状態
	int m_direction;		// ユニットの向き　1(U_RIGHT):右 -1(U_LEFT):左
	int m_moveCnt;			// アニメーション用カウント
	int m_moveAnime[4] = { 1, 0, 1, 2};	// アニメーション配列
	int m_effectImage[2];	// Effect用
	int m_effectAnimeCnt;	// Effectアニメーションカウント
	bool m_effectFlg;		// Effect再生フラグ
	sNextMove m_nextMove;	// 次に向かう場所

	int m_imgNum;			// アニメーションナンバー
	int m_imgtbl[6];		// 画像配列
	
public:

	void Update();

 	virtual void Draw();

	cBaseUnit();

	virtual ~cBaseUnit();

	/*********************************************************************
	関数名：void RoomDraw()
	概要：部屋の中の描画
	引数：VECTOR:描画座標
	戻り値：なし
	*********************************************************************/
	void RoomDraw(VECTOR _vPos);

	/*********************************************************************
	関数名：void Move()
	概要：移動処理
	引数：なし
	戻り値：なし
	*********************************************************************/
	void Move();

	/*********************************************************************
	関数名：bool Attack()
	概要：攻撃タイミング制御
	引数：なし
	戻り値：true:攻撃	false:リチャージ
	*********************************************************************/
	bool Attack();

	/*********************************************************************
	関数名：void AttackStart()
	概要：targetが決まったら、Stateを攻撃モードに
	引数：なし
	戻り値：なし
	*********************************************************************/
	void AttackStart();

	/*********************************************************************
	関数名：void Defense(int _atkPoint, int _atkNum)
	概要：攻撃判定を受け取る
	引数：int:ダメージ量, int:攻撃するUnitのナンバー
	戻り値：なし
	*********************************************************************/
	void Defense(int _atkPoint, int _atkNum);

	/*********************************************************************
	関数名：virtual void AttackAnime()
	概要：攻撃用アニメーション
	引数：なし
	戻り値：なし
	*********************************************************************/
	void AttackAnime(VECTOR _targetPos);

	/************************************    Get    *****************************************/

	// 向き
	int Get_Direction()
	{
		return m_direction;
	}

	// 攻撃範囲
	double Get_atkR()
	{
		return m_atkR;
	}

	// 現在の部屋番号
	int Get_NowRoom()
	{
		return m_room;
	}

	// 攻撃タイミングカウント
	int Get_AtkCnt()
	{
		return m_atkCnt;
	}

	// 火力
	int Get_AtkPoint()
	{
		return m_atk;
	}

	// 現在のターゲットナンバー
	int Get_TargetNum()
	{
		return m_targetNum;
	}

	// 体力
	int Get_Hp()
	{
		return m_hp;
	}

	// 現在座標
	VECTOR Get_Pos()
	{
		return m_pos;
	}

	// 現在のステート
	int Get_State()
	{
		return m_state;
	}

	// Effect描画フラグ
	bool Get_EffectFlg()
	{
		return m_effectFlg;
	}

	// Unitナンバー
	int Get_Num()
	{
		return m_num;
	}

	/************************************    Set    *****************************************/

	/*********************************************************************
	関数名：void Set_NextMove(int _nextRoom, double _nextX)
	概要：移動先セット
	引数：int:移動先の部屋番号, double:移動先のx座標
	戻り値：なし
	*********************************************************************/
	void Set_NextMove(int _nextRoom, double _nextX)
	{
		m_nextMove.sNextRoom = _nextRoom;
		m_nextMove.sNextX = _nextX;
	}

	/*********************************************************************
	関数名：void Set_Target(int _num)
	概要：ターゲットのセット
	引数：ターゲットにするUnitナンバー
	戻り値：なし
	*********************************************************************/
	void Set_Target(int _num)
	{
		m_targetNum = _num;
	}

	/*********************************************************************
	関数名：void Set_State(eState _state)
	概要：ステートの変更
	引数：eState:ステート
	　　　Constant.h 参照
	戻り値：なし
	*********************************************************************/
	void Set_State(eState _state)
	{
		m_state = _state;
	}

	void Set_Pos(VECTOR _pos)
	{
		m_pos = _pos;
	}
};

#endif // !_INCLUDE_BASE_UNIT_