#include "BaseUnit.h"

// �R���X�g���N�^
cBaseUnit::cBaseUnit(){

	m_condition = E_NONE;
	m_nextMove.sNextRoom = -1;
	m_nextMove.sNextX = NULL;
	m_isOnActive = true;
	m_state = E_IDLE;
	m_direction = U_RIGHT;
	m_targetNum = -1;
	m_atkCnt = m_atkCoolTime;
	m_moveCnt = 0;
	m_isEffect = false;
	m_effectAnimeCnt = 0;
	m_Defense = 0;

	for (int i = 0; i < 2; i++){
		m_effectImage[i] = MakeGraph(64, 64);
	}
}

// �f�X�g���N�^
cBaseUnit::~cBaseUnit(){

	for (int i = 0; i < 6; i++){
		DeleteGraph(m_imgtbl[i]);
	}

	for (int i = 0; i < 2; i++)
	{
		DeleteGraph(m_effectImage[i]);
	}
}

// ���Z����
void cBaseUnit::Update()
{
	m_moveStartCnt++;				// ��萔�܂ōs������move
	m_moveType = GetRand(2);	// move����Type�����߂郉���_��
}

// �`�揈��
void cBaseUnit::Draw()
{
	int imgNum = m_moveAnime[m_imgNum]; // �z��ԍ��i�[

	// �E�������Ă���ꍇ�͉摜�z��ԍ���3����
	if (m_direction == U_RIGHT){
		imgNum += 3;
	}

	// �`��
	DrawBillboard3D(m_pos, 0.5f, 0.5f, 64, 0.0f, m_imgtbl[imgNum], TRUE);
}

// �ړ�����
void cBaseUnit::Move()
{
	// ���ݒn�ƍs�悪�����̏ꍇ
	if (m_room == m_nextMove.sNextRoom){
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
		if (m_pos.x <= m_nextMove.sNextX + m_speed && m_nextMove.sNextX - m_speed <= m_pos.x){
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

// �U������
bool cBaseUnit::Attack()
{

	m_atkCnt--;

	// �J�E���g��0�ɂȂ�����U��
	if (m_atkCnt <= 0){
		m_atkCnt = 300;
		//DEBUG_LOG("SordAttack");

		m_isEffect = true;

		return true;
	}

	return false;
}

// �U���J�n����
void cBaseUnit::AttackStart(){

	// �^�[�Q�b�g������������U���J�n
	if (m_targetNum != -1){
		m_state = E_ATTACK;
	}
}

// �U���A�j���[�V��������
void cBaseUnit::AttackAnime(VECTOR _targetPos){

	// �U�����[�V������60�t���[���ԕ`��
	if (m_effectAnimeCnt <= 60){

		// ����
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
		m_isEffect = false;
	}

	m_effectAnimeCnt++;
}

// �U��������󂯎��
void cBaseUnit::Defense(int _atkPoint, int _atkNum){
	
	// �G�̍U���͕�HP����
	m_hp -= _atkPoint - m_Defense;

	DEBUG_LOG("�i���o�[%d��%d�̃_���[�W���󂯂��@�c��HP:%d", m_num, _atkPoint, m_hp);
}

/*
void cBaseUnit::UnitMove(int _player, int _enemy) {
	// Unit�̈ړ�
	if (m_moveStartCnt >= MOVE_CNT) {		// m_moveCnt�����ɂȂ�����
		for (int i = 0; i < m_enemy.size(); i++) {

			int next = enemy[i]->Get_NowRoom() - 1;

			if (enemy[i]->Get_NowRoom() != 0) {

				int cnt = tmpRoomEnemy[next].size();
				int max = m_mapData[next].roomSize;

				if (cnt < max)
				{
					//if (m_stayCnt >= STEY_CNT) {
					enemy[i]->Set_Room(next);
					//break;
				//}
				}
				//Set_NextEnemyPos(EnemyArreySearch(enemy[i]->Get_Num()), enemy[i]->Get_NowRoom() - 1, enemy[i]->Get_NowRoom() - 1);
				m_moveStartCnt = 0;

				
				// �w�肳�ꂽ���W�ɂ�����Idle��Ԃ�
				//if (m_pos.x <= m_nextMove.sNextX + m_speed && m_nextMove.sNextX - m_speed <= m_pos.x)
				//{
				//	m_state = E_IDLE;
				//	m_imgNum = 0;
				//}
				
			
			}
		}
	}
		
}*/