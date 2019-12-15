#include "UnitMgr.h"

cUnitMgr::cUnitMgr()
{
	m_num = 0;
	m_mapStack = 7;

	GetDateTime(&m_date);
	int tmpDate = m_date.Day + m_date.Hour + m_date.Min + m_date.Mon + m_date.Sec + m_date.Year;
	SRand(tmpDate);

	m_selectMarkImg = LoadGraph("../resource/img/PlayerSelect.png");
	if (-1 == m_selectMarkImg)
	{
		//ErrBox("画像読み込み失敗");
	}

	for (int i = 0; i < m_mapStack; i++)
	{
		m_roomPlayer.push_back(vector<int>());
		m_roomEnemy.push_back(vector<int>());
	}

	m_escortCnt = 0;
}

cUnitMgr::~cUnitMgr()
{
	DeleteGraph(m_selectMarkImg);
}

void cUnitMgr::Update()
{
	m_moveCnt++;				// 一定数まで行ったらmove
	m_moveType = GetRand(2);	// moveするTypeを決めるランダム

	if (m_escortCnt <= 0)
	{
		player.emplace_back(new cEscortTarget(0, m_num));
		m_escortCnt++;
		m_num++;

		DEBUG_LOG("player.size:%d", player.size());
	}
	UnitDie();
	InRoomUnit();
	//UnitMove();
	//TargetSelect();
	for (int i = 0; i < player.size(); i++)
	{
		switch (player[i]->Get_State())
		{
		case E_IDLE:
			if (player[i]->Attack() == true)
			{
				TargetSelect(i, 1);
			}
			break;

		case E_ATTACK:
			if (player[i]->Attack() == true)
			{
				TargetSelect(i, 1);
				AttackRelay(player[i]->Get_AtkPoint(), player[i]->Get_TargetNum(), player[i]->Get_Num());
				player[i]->AttackSE();
			}
			
			break;

		case E_MOVE:
			player[i]->Move();
			break;

		default:
			break;
		}
		player[i]->AttackStart();

		//DrawFormatString(200, 400, RD, "player:%d", player[0]->Get_Hp());
	}

	for (int i = 0; i < enemy.size(); i++)
	{
		switch (enemy[i]->Get_State())
		{
		case E_IDLE:
			if (enemy[i]->Attack() == true)
			{
				TargetSelect(i, -1);
			}
			break;

		case E_ATTACK:
			if (enemy[i]->Attack() == true)
			{
				TargetSelect(i, -1);
				AttackRelay(enemy[i]->Get_AtkPoint(), enemy[i]->Get_TargetNum(), enemy[i]->Get_Num());
				enemy[i]->AttackSE();
			}
			break;

		case E_MOVE:
			UnitMove();
			break;
		default:
			break;
		}
		enemy[i]->AttackStart();

		//enemy[i]->Set_MapSize(4);
		//DrawFormatString(200, 450, RD, "enemy:%d", enemy[0]->Get_Hp());
	}

	NoTarget();
}

void cUnitMgr::Draw()
{
	RoomDraw();
	UnitMove();

	for (int i = 0; i < player.size(); i++)
	{
		if (player[i]->Get_EffectFlg() == true)
		{
			int num = EnemyArreySearch(player[i]->Get_TargetNum());
			if (num >= 0)
			{
				player[i]->AttackAnime(enemy[num]->Get_Pos());
			}
		}
	}
	for (int i = 0; i < enemy.size(); i++)
	{
		if (enemy[i]->Get_EffectFlg() == true)
		{
			int num = PlayerArreySearch(enemy[i]->Get_TargetNum());
			if (num >= 0)
			{
				enemy[i]->AttackAnime(player[num]->Get_Pos());
			}
		}
	}

#ifdef UNIT_MGR_DEBUG
	//DrawFormatString(100, 100, GetColor(255, 0, 0), "roomPlayer:%d", roomPlayer.size());
	//DrawFormatString(100, 150, GetColor(255, 0, 0), "roomEnemy:%d", roomEnemy.size());
#endif // UNIT_MGR_DEBUG
}

void cUnitMgr::RoomDraw()
{
	for (int i = 0; i < m_roomPlayer.size(); i++)
	{
		for (int j = 0; j < m_roomPlayer[i].size(); j++)
		{
			int playerNum = m_roomPlayer[i][j];

			int arreyNum = PlayerArreySearch(playerNum);

			if (player[arreyNum]->Get_State() != E_MOVE)
			{

				int num = m_mapData[i].roomSize - 1 - j;

				float x = m_mapData[i].pos.x;
				float wPos = m_mapData[i].width / 2 / (m_mapData[i].roomSize + 3) * num;

				x += wPos + 30;


				float y = m_mapData[i].pos.y;

				float hPos = m_mapData[i].height / 2 / (m_mapData[i].roomSize + 1) * num;

				y += hPos + 40;

				player[arreyNum]->Set_Pos(VGet(x, y, -(j / 10)));

				player[arreyNum]->Draw();
			}
		}
	}

	for (int i = 0; i < m_roomEnemy.size(); i++)
	{
		for (int j = 0; j < m_roomEnemy[i].size(); j++)
		{
			int enemyNum = m_roomEnemy[i][j];

			int arreyNum = EnemyArreySearch(enemyNum);

			if (enemy[arreyNum]->Get_State() != E_MOVE)
			{

				int num = m_mapData[i].roomSize - 1 - j;

				float x = m_mapData[i].pos.x + m_mapData[i].width;
				float wPos = m_mapData[i].width / 2 / (m_mapData[i].roomSize + 3) * num;

				x -= wPos + 30;


				float y = m_mapData[i].pos.y;

				float hPos = m_mapData[i].height / 2 / (m_mapData[i].roomSize + 1) * num;

				y += hPos + 40;

				enemy[arreyNum]->Set_Pos(VGet(x, y, -(j / 10)));

				enemy[arreyNum]->Draw();
			}
		}
	}
}

void cUnitMgr::TargetSelect(int _arrayNum, int _unit)
{
	if (_unit == 1)	// Player
	{
		int room = player[_arrayNum]->Get_NowRoom();
		vector<int> vNum;

		for (int i = 0; i < m_roomEnemy[room].size(); i++)
		{
			int num = EnemyArreySearch(m_roomEnemy[room][i]);

			if (enemy[num]->Get_Type() == E_DEFENSE && enemy[num]->Get_State() != E_MOVE)
			{
				vNum.push_back(num);
				break;
			}

			if (enemy[num]->Get_State() != E_MOVE)
			{
				vNum.push_back(num);
			}
		}
		if (vNum.size() > 0)
		{
			int tNum = GetRand(vNum.size() -1);
			player[_arrayNum]->Set_Target(enemy[vNum[tNum]]->Get_Num());

			DEBUG_LOG("player[%d].Target:%d",_arrayNum , EnemyArreySearch(player[_arrayNum]->Get_TargetNum()));
		}
	}
	else // Enemy
	{
		int room = enemy[_arrayNum]->Get_NowRoom();
		vector<int> vNum;

		for (int i = 0; i < m_roomPlayer[room].size(); i++)
		{
			int num = PlayerArreySearch(m_roomPlayer[room][i]);

			if (player[num]->Get_Type() == E_DEFENSE && player[num]->Get_State() != E_MOVE)
			{
				vNum.push_back(num);
				break;
			}

			if (player[num]->Get_Type() == E_ESCORT && player[num]->Get_State() != E_MOVE)
			{
				vNum.push_back(num);
				break;
			}

			if (player[num]->Get_State() != E_MOVE)
			{
				vNum.push_back(num);
			}
		}
		if (vNum.size() > 0)
		{
			int tNum = GetRand(vNum.size() - 1);
			enemy[_arrayNum]->Set_Target(player[vNum[tNum]]->Get_Num());
		}
	}
}

void cUnitMgr::TargetSelect()
{
	// Player
	for (int p = 0; p < player.size(); p++)
	{
		vector<int> eNum;
		// Enemy
		for (int e = 0; e < enemy.size(); e++)
		{
			// 同じ部屋かどうか
			if (player[p]->Get_NowRoom() == enemy[e]->Get_NowRoom())
			{
				if (player[p]->Get_State() == E_IDLE && enemy[e]->Get_State() != E_MOVE)
				{
					eNum.push_back(enemy[e]->Get_Num());
				}
				//DEBUG_LOG("同じ部屋");
				 //お互い戦闘中でないか
				if (player[p]->Get_State() != E_ATTACK && enemy[e]->Get_State() != E_ATTACK)
				{
					/* Player */
					// 向き
					if (player[p]->Get_Direction() == U_RIGHT)
					{
						if (player[p]->Get_Pos().x <= enemy[e]->Get_Pos().x && player[p]->Get_Pos().x + player[p]->Get_atkR() >= enemy[e]->Get_Pos().x)
						{
							player[p]->Set_Target(enemy[e]->Get_Num());
							player[p]->Set_State(E_ATTACK);
						}
					}
					else
					{
						if (player[p]->Get_Pos().x >= enemy[e]->Get_Pos().x && player[p]->Get_Pos().x - player[p]->Get_atkR() <= enemy[e]->Get_Pos().x)
						{
							player[p]->Set_Target(enemy[e]->Get_Num());
							player[p]->Set_State(E_ATTACK);
						}
					}
					/* Enemy */
					if (enemy[e]->Get_Direction() == U_RIGHT)
					{
						if (enemy[e]->Get_Pos().x <= player[p]->Get_Pos().x && enemy[e]->Get_Pos().x + enemy[e]->Get_atkR() >= player[p]->Get_Pos().x)
						{
							enemy[e]->Set_Target(player[p]->Get_Num());
							enemy[e]->Set_State(E_ATTACK);
						}
					}
					else
					{
						if (enemy[e]->Get_Pos().x >= player[p]->Get_Pos().x && enemy[e]->Get_Pos().x - enemy[e]->Get_atkR() <= player[p]->Get_Pos().x)
						{
							enemy[e]->Set_Target(player[p]->Get_Num());
							enemy[e]->Set_State(E_ATTACK);
						}
					}
				}
			}
		}
		if (eNum.size() > 0)
		{
			int num = GetRand(eNum.size() - 1);
			player[p]->Set_Target(eNum[num]);
		}
	}
}

void cUnitMgr::InRoomUnit()
{
	for (int i = 0; i < m_mapData.size(); i++)
	{
		m_roomPlayer[i].clear();
		m_roomEnemy[i].clear();
	}

	for (int i = 0; i < player.size(); i++)
	{
		m_roomPlayer[player[i]->Get_NowRoom()].push_back(player[i]->Get_Num());
	}

	for (int i = 0; i < enemy.size(); i++)
	{
		m_roomEnemy[enemy[i]->Get_NowRoom()].push_back(enemy[i]->Get_Num());
	}
}

int cUnitMgr::AttackRelay(int _atkP, int _difNum, int _atkNum)
{
	int tmp = 0;
	if ((tmp = PlayerArreySearch(_difNum)) != -1)
	{
		player[tmp]->Defense(_atkP, _atkNum);
		return 0;
	}

	if ((tmp = EnemyArreySearch(_difNum)) != -1)
	{
		enemy[tmp]->Defense(_atkP, _atkNum);
		return 0;
	}

	return 0;
}

int cUnitMgr::EnemyArreySearch(int _num)
{
	for (int i = 0; i < enemy.size(); i++)
	{
		if (enemy[i]->Get_Num() == _num)
		{
			return i;
		}
	}

	return -1;
}

int cUnitMgr::PlayerArreySearch(int _num)
{
	for (int i = 0; i < player.size(); i++)
	{
		if (player[i]->Get_Num() == _num)
		{
			return i;
		}
	}

	return -1;
}

int cUnitMgr::CheckPlayerClick(VECTOR _pos)
{
	for (int i = 0; i < player.size(); i++)
	{
		VECTOR p_pos = player[i]->Get_Pos();

		if ((p_pos.x - UNIT_WIDTH / 2) <= _pos.x && (p_pos.x + UNIT_WIDTH / 2) >= _pos.x)
		{
			if ((p_pos.y - UNIT_HEIGHT / 2) <= _pos.y && (p_pos.y + UNIT_HEIGHT / 2) >= _pos.y)
			{
				return player[i]->Get_Num();
			}
			
		}
		
	}
	return -1;
}

int cUnitMgr::CheckEnemyClick(VECTOR _pos)
{
	for (int i = 0; i < enemy.size(); i++)
	{
		VECTOR e_pos = enemy[i]->Get_Pos();

		if ((e_pos.x - UNIT_WIDTH / 2) <= _pos.x && (e_pos.x + UNIT_WIDTH / 2) >= _pos.x)
		{
			if ((e_pos.y - UNIT_HEIGHT / 2) <= _pos.y && (e_pos.y + UNIT_HEIGHT / 2) >= _pos.y)
			{
				return enemy[i]->Get_Num();
			}
		}
	}
	return -1;
}

void cUnitMgr::Set_NextPlayerPos(int _playerNum, int _nextRoom, double _nextX)
{
	for (int i = 0; i < player.size(); i++)
	{
		if (player[i]->Get_Num() == _playerNum)
		{
			player[i]->Set_NextMove(_nextRoom, _nextX);
			player[i]->Set_State(E_MOVE);
		}
		//DEBUG_LOG("次の座標セット");
	}
}

void cUnitMgr::Set_NextEnemyPos(int _enemyNum, int _nextRoom, int _nextX)
{
	enemy[_enemyNum]->Set_NextMove(_nextRoom, _nextX);
	enemy[_enemyNum]->Set_State(E_MOVE);
	//DEBUG_LOG("敵の移動先セット");
}

void cUnitMgr::SelectUI(int _num)
{
	double sx = player[_num]->Get_Pos().x;
	double sy = (player[_num]->Get_Pos().y + UNIT_HEIGHT / 2 + 13);

	DrawBillboard3D(VGet(sx, sy, 0.0f), 0.5f, 0.5f, 18.0f, 0.0f, m_selectMarkImg, TRUE);
}

void cUnitMgr::UnitMove() {

	int tmpRand=0;
	int tmptbl=0;
	// Unitの移動
	if (m_moveCnt >= MOVE_CNT) {		// m_moveCntが一定になったら
		for (int i = 0; i < enemy.size(); i++) {

			// MapNavigation関数のreturnを代入
			tmptbl = m_mapNavigate.MapNavigation(enemy[i]->Get_NowRoom(), tmpRand);
			
			// int next = m_mapNavigate.MapNavigation(enemy[i]->Get_NowRoom(), tmpRand);//enemy[i]->Get_NowRoom() - 1;		// 今いる部屋の-1
			 //int next = enemy[i]->Get_NowRoom() - 1;


			if (enemy[i]->Get_NowRoom() != 0) {		// 今の部屋が0じゃなかったら

				int cnt = m_roomEnemy[tmptbl].size();		// 次行きたい部屋のエネミーの要素数
				int max = m_mapData[tmptbl].roomSize;		// 次行きたい部屋のエネミーの数制限

				if (cnt >= max) {
					return;
				} else if (cnt < max)		// 次行きたい部屋に空きがあったら
				{
					enemy[i]->Set_Room(tmptbl);
				}
				m_moveCnt = 0;
			}
		}
	}
}
