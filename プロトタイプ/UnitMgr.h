#pragma once
#include "BaseTask.h"
#include "DxLib.h"
#include "DebugList.h"
#include "PlayerUnit.h"
#include "EnemyUnit.h"
#include "Constant.h"
#include "PSord.h"
#include "PArcher.h"
#include "ESord.h"
#include "EArcher.h"
#include "Mouse.h"
#include <vector>
#include "Log.h"
using namespace std;

/********************************************************
���T�v
�@���j�b�g�S�̂̐���E����

���쐬��
�@���䗲���Y

���X�V��
�@
********************************************************/

#ifndef _INCLUED_UNIT_MGR_
#define _INCLUED_UNIT_MGR_

class cUnitMgr : public cBaseTask
{
	vector<cPlayerUnit*> player;
	vector<cEnemyUnit*> enemy;

	int m_num;

public:
	cUnitMgr()
	{
		m_num = 0;
	}

	~cUnitMgr()
	{
		
	}
	void Update();
	void Draw();
	
	void Add_PSord(double _x, double _y,int _room)
	{
		player.emplace_back(new cPSord(_x, _y, _room, m_num));
		m_num++;
		//cLog::Instance()->DebugLog("���m�𐶐�");
		//DEBUG_LOG("���m�𐶐�");
	}

	void Add_PArcher(double _x, double _y,int _room)
	{
		player.emplace_back(new cPArcher(_x, _y, _room, m_num));
		m_num++;
		//cLog::Instance()->DebugLog("�|���𐶐�");
	}
	
	/**************************** �G�l�~�[ ************************/
	
	void Add_ESord(double _x, double _y, int _room)
	{
		enemy.emplace_back(new cESord(_x, _y, _room, m_num));
		m_num++;
		DEBUG_LOG("AddESord������");
		//Set_State(eMove);
		//cLog::Instance()->DebugLog("���m�𐶐�");
		//DEBUG_LOG("���m�𐶐�");
	}

	void Add_EArcher(double _x, double _y, int _room)
	{
		enemy.emplace_back(new cEArcher(_x, _y, _room, m_num));
		m_num++;
		DEBUG_LOG("AddEArcher������");
		//cLog::Instance()->DebugLog("�|���𐶐�");
		//DEBUG_LOG("�|���𐶐�");
	}

	int CheckPlayerClick(VECTOR _pos);
	int CheckEnemyClick(VECTOR _pos);

	void Set_NextPlayerPos(int _playerNum, int _nextRoom, double _nextX)
	{
		player[_playerNum]->Set_NextMove(_nextRoom, _nextX);
		player[_playerNum]->Set_State(eMove);
		DEBUG_LOG("���̍��W�Z�b�g");
	}
								//-1		// �G��Ă邩	//mouse X
	void Set_NextEnemyPos(int _enemyNum, int _nextRoom, double _nextX)
	{
		enemy[_enemyNum]->Set_NextMove(_nextRoom, _nextX);
		enemy[_enemyNum]->Set_State(eMove);
		DEBUG_LOG("�G�̈ړ���Z�b�g");
	}
	
};

#endif  // !_INCLUDE_UNIT_MGR_