#include "BaseUnit.h"

cBaseUnit::cBaseUnit()
{
	m_condition = eNone;
	m_nextMove.sNextRoom = -1;
	m_nextMove.sNextX = NULL;
	m_isOnActive = true;
	m_state = E_IDLE;
	m_direction = U_RIGHT;
	m_targetNum = -1;
	m_atkCnt = m_atkCoolTime;
	m_moveCnt = 0;
	m_effectFlg = false;
	m_effectAnimeCnt = 0;
	m_Defense = 0;
	
	for (int i = 0; i < 2; i++)
	{
		m_effectImage[i] = MakeGraph(64, 64);
	}
}

cBaseUnit::~cBaseUnit()
{
	for (int i = 0; i < 6; i++)
	{
		DeleteGraph(m_imgtbl[i]);
	}

	for (int i = 0; i < 2; i++)
	{
		DeleteGraph(m_effectImage[i]);
	}
}

void cBaseUnit::Update()
{

}

void cBaseUnit::Draw()
{
	int imgNum = m_moveAnime[m_imgNum];

	// 右を向いている場合は画像配列番号に3足す
	if (m_direction == U_RIGHT)
	{
		imgNum += 3;
	}

	DrawBillboard3D(m_pos, 0.5f, 0.5f, 64, 0.0f, m_imgtbl[imgNum], TRUE);
}

void cBaseUnit::Move()
{
	// 現在地と行先が同じの場合
	if (m_room == m_nextMove.sNextRoom)
	{
		/* TODO
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
		*/
		// 指定された座標についたらIdle状態へ
		if (m_pos.x <= m_nextMove.sNextX + m_speed && m_nextMove.sNextX - m_speed <= m_pos.x)
		{
			m_state = E_IDLE;
			m_imgNum = 0;
		}

	}

	/* TODO
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
	*/
}

bool cBaseUnit::Attack()
{
	m_atkCnt--;
	if (m_atkCnt <= 0)
	{
		m_atkCnt = 300;
		//DEBUG_LOG("SordAttack");

		m_effectFlg = true;

		return true;
	}

	return false;
}

void cBaseUnit::AttackStart()
{
	if (m_targetNum != -1)
	{
		m_state = E_ATTACK;
	}
}

void cBaseUnit::AttackAnime(VECTOR _targetPos)
{
	if (m_effectAnimeCnt <= 60)
	{
		if (m_direction == U_LEFT)
		{

			DrawBillboard3D(_targetPos, 0.5f, 0.5f, 64, 0.0f, m_effectImage[1], TRUE);
		}
		else
		{
			DrawBillboard3D(_targetPos, 0.5f, 0.5f, 64, 0.0f, m_effectImage[0], TRUE);
		}
	}
	else
	{
		m_effectAnimeCnt = 0;
		m_effectFlg = false;
	}

	m_effectAnimeCnt++;
}

void cBaseUnit::Defense(int _atkPoint, int _atkNum)
{
	m_hp -= _atkPoint - m_Defense;
	/*if (m_targetNum == -1)
	{
		m_targetNum = _atkNum;
		m_effectFlg = true;


	}*/

	DEBUG_LOG("ナンバー%dは%dのダメージを受けた　残りHP:%d", m_num, _atkPoint, m_hp);
}