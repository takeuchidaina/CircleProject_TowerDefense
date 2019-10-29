#pragma once

#include "BaseTask.h"
#include "Constant.h"
#include <vector>
#include "Log.h"
using namespace std;

//template <typename _T>

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
	int m_targetNum;		// 攻撃対象の番号
	int m_hp;				// HP
	int m_room;				// 現在いる部屋番号
	int m_atk;				// 攻撃力
	int m_condition;		// 状態異常
	double m_speed;			// 移動速度
	int m_atkCoolTime;		// 次の攻撃までの時間
	int m_atkCnt;			// 攻撃までのカウント
	double m_atkR;			// 射程範囲
	bool m_isOnActive;		// 生存フラグ
	int m_state;			// 現在の状態
	int m_direction;		// ユニットの向き　1(U_RIGHT):右 -1(U_LEFT):左
	int m_moveCnt;			// アニメーション用カウント
	int m_moveAnime[4] = { 1, 0, 1, 2};	// アニメーション配列
	sNextMove m_nextMove;	// 次に向かう場所

	int m_imgNum;			// アニメーションナンバー
	int m_imgtbl[6];		// 画像配列
	
public:

	void Update()
	{
		
	}

	void Draw()
	{
		int imgNum = m_moveAnime[m_imgNum];

		// 右を向いている場合は画像配列番号に3足す
		if (m_direction == U_RIGHT)
		{
			imgNum += 3;
		}

		DrawBillboard3D(m_pos, 0.5f, 0.5f, 64, 0.0f, m_imgtbl[imgNum], TRUE);
	}

	cBaseUnit()
	{
		m_condition = eNone;
		m_nextMove.sNextRoom = -1;
		m_nextMove.sNextX = NULL;
		m_isOnActive = true;
		m_state = eIdle;
		m_direction = U_RIGHT;
		m_targetNum = -1;
		m_atkCnt = m_atkCoolTime;
		m_moveCnt = 0;

	}

	~cBaseUnit()
	{
		for (int i = 0; i < 6; i++)
		{
			DeleteGraph(m_imgtbl[i]);
		}
	}

	/*********************************************************************
	関数名：void Move()
	概要：移動処理
	引数：なし
	戻り値：なし
	*********************************************************************/
	void Move()
	{
		// 現在地と行先が同じの場合
		if (m_room == m_nextMove.sNextRoom)
		{
			// 行先が右側
			if (m_pos.x <= m_nextMove.sNextX)
			{
				m_direction = U_RIGHT;
			}
			else // 左側
			{
				m_direction = U_LEFT;
			}

			// 右へ
			if (m_direction == U_RIGHT)
			{
				m_pos.x += m_speed;
			}
			else // 左へ
			{
				m_pos.x -= m_speed;
			}

			// 指定された座標についたらIdle状態へ
			if (m_pos.x <= m_nextMove.sNextX + m_speed && m_nextMove.sNextX - m_speed <= m_pos.x)
			{
				m_state = eIdle;
				m_imgNum = 0;
			}

		}

		// 移動中の画像配列計算
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

	void Attack()
	{
		m_atkCnt--;
		if (m_atkCnt <= 0)
		{
			m_atkCnt = 0;
		}
	}

	int Get_Direction()
	{
		return m_direction;
	}

	double Get_atkR()
	{
		return m_atkR;
	}

	int Get_NowRoom()
	{
		return m_room;
	}

	void AttackStart()
	{
		if (m_targetNum != -1)
		{
			m_state = eAttack;
		}
	}

	int Get_AtkCnt()
	{
		return m_atkCnt;
	}

	/*********************************************************************
	関数名：void Set_NextRoom(int)
	概要：次に向かう部屋をセット
	引数：_nextRoom:次に向かう部屋番号
	戻り値：なし
	*********************************************************************/
	void Set_NextMove(int _nextRoom, double _nextX)
	{
		m_nextMove.sNextRoom = _nextRoom;
		m_nextMove.sNextX = _nextX;
	}

	/*********************************************************************
	関数名：VECTOR Get_Pos()
	概要：現在地の取得
	引数：なし
	戻り値：VECTOR m_pos:現在地
	*********************************************************************/
	VECTOR Get_Pos()
	{
		return m_pos;
	}

	/*********************************************************************
	関数名：int Get_State()
	概要：現在の状態取得
	引数：なし
	戻り値：int m_state:状態 eIdleなど
	*********************************************************************/
	int Get_State()
	{
		return m_state;
	}

	void Set_Target(int _num)
	{
		m_targetNum = _num;
	}

	/*********************************************************************
	関数名：int Set_State()
	概要：状態の変更
	引数：eState _state:変更したい状態 Idleなど
	戻り値：なし
	*********************************************************************/
	void Set_State(eState _state)
	{
		m_state = _state;
	}



	/*********************************************************************
	関数名：int Get_Num()
	概要：ナンバー取得
	引数：なし
	戻り値：int:ナンバー
	*********************************************************************/
	int Get_Num()
	{
		return m_num;
	}
};

#endif // !_INCLUDE_BASE_UNIT_