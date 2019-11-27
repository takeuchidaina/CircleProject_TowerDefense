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
}

cBaseUnit::~cBaseUnit()
{
	for (int i = 0; i < 6; i++)
	{
		DeleteGraph(m_imgtbl[i]);
	}
	DeleteGraph(m_effectImage);
}

void cBaseUnit::Update()
{

}

void cBaseUnit::Draw()
{
	int imgNum = m_moveAnime[m_imgNum];

	// �E�������Ă���ꍇ�͉摜�z��ԍ���3����
	if (m_direction == U_RIGHT)
	{
		imgNum += 3;
	}

	DrawBillboard3D(m_pos, 0.5f, 0.5f, 64, 0.0f, m_imgtbl[imgNum], TRUE);
}

void cBaseUnit::Move()
{
	// ���ݒn�ƍs�悪�����̏ꍇ
	if (m_room == m_nextMove.sNextRoom)
	{
		/* TODO
		// �s�悪�E��
		if (m_pos.x <= m_nextMove.sNextX)
		{
			m_direction = U_RIGHT;
		}
		else // ����
		{
			m_direction = U_LEFT;
		}

		// �E��
		if (m_direction == U_RIGHT)
		{
			m_pos.x += m_speed;
		}
		else // ����
		{
			m_pos.x -= m_speed;
		}
		*/
		// �w�肳�ꂽ���W�ɂ�����Idle��Ԃ�
		if (m_pos.x <= m_nextMove.sNextX + m_speed && m_nextMove.sNextX - m_speed <= m_pos.x)
		{
			m_state = E_IDLE;
			m_imgNum = 0;
		}

	}

	/* TODO
	// �ړ����̉摜�z��v�Z
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

void cBaseUnit::Defense(int _atkPoint, int _atkNum)
{
	m_hp -= _atkPoint;
	if (m_targetNum == -1)
	{
		m_targetNum = _atkNum;
		m_effectFlg = true;
	}
}