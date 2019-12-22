#include "BaseUnit.h"

// コンストラクタ
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

// デストラクタ
cBaseUnit::~cBaseUnit(){

	for (int i = 0; i < 6; i++){
		DeleteGraph(m_imgtbl[i]);
	}

	for (int i = 0; i < 2; i++)
	{
		DeleteGraph(m_effectImage[i]);
	}
}

// 演算処理
void cBaseUnit::Update()
{
	m_moveStartCnt++;				// 一定数まで行ったらmove
	m_moveType = GetRand(2);	// moveするTypeを決めるランダム
}

// 描画処理
void cBaseUnit::Draw()
{
	int imgNum = m_moveAnime[m_imgNum]; // 配列番号格納

	// 右を向いている場合は画像配列番号に3足す
	if (m_direction == U_RIGHT){
		imgNum += 3;
	}

	// 描画
	DrawBillboard3D(m_pos, 0.5f, 0.5f, 64, 0.0f, m_imgtbl[imgNum], TRUE);
}

// 移動処理
void cBaseUnit::Move()
{
	// 現在地と行先が同じの場合
	if (m_room == m_nextMove.sNextRoom){
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
		if (m_pos.x <= m_nextMove.sNextX + m_speed && m_nextMove.sNextX - m_speed <= m_pos.x){
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

// 攻撃処理
bool cBaseUnit::Attack()
{

	m_atkCnt--;

	// カウントが0になったら攻撃
	if (m_atkCnt <= 0){
		m_atkCnt = 300;
		//DEBUG_LOG("SordAttack");

		m_isEffect = true;

		return true;
	}

	return false;
}

// 攻撃開始判定
void cBaseUnit::AttackStart(){

	// ターゲットが見つかったら攻撃開始
	if (m_targetNum != -1){
		m_state = E_ATTACK;
	}
}

// 攻撃アニメーション制御
void cBaseUnit::AttackAnime(VECTOR _targetPos){

	// 攻撃モーションを60フレーム間描画
	if (m_effectAnimeCnt <= 60){

		// 向き
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

// 攻撃判定を受け取る
void cBaseUnit::Defense(int _atkPoint, int _atkNum){
	
	// 敵の攻撃力分HP減少
	m_hp -= _atkPoint - m_Defense;

	DEBUG_LOG("ナンバー%dは%dのダメージを受けた　残りHP:%d", m_num, _atkPoint, m_hp);
}

/*
void cBaseUnit::UnitMove(int _player, int _enemy) {
	// Unitの移動
	if (m_moveStartCnt >= MOVE_CNT) {		// m_moveCntが一定になったら
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

				
				// 指定された座標についたらIdle状態へ
				//if (m_pos.x <= m_nextMove.sNextX + m_speed && m_nextMove.sNextX - m_speed <= m_pos.x)
				//{
				//	m_state = E_IDLE;
				//	m_imgNum = 0;
				//}
				
			
			}
		}
	}
		
}*/