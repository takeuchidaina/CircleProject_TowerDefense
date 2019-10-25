#pragma once
#include "BaseTask.h"
#include "DxLib.h"
#include "DebugList.h"
#include "PlayerUnit.h"
#include "Constant.h"
#include "PSord.h"
#include "PArcher.h"
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

	void Add_PSord(double _x, double _y)
	{
		player.emplace_back(new cPSord(_x, _y, 1, m_num));
		m_num++;
		//cLog::Instance()->DebugLog("���m�𐶐�");
		//DEBUG_LOG("���m�𐶐�");
	}

	void Add_PArcher(double _x, double _y)
	{
		player.emplace_back(new cPArcher(_x, _y, 1, m_num));
		m_num++;
		//cLog::Instance()->DebugLog("�|���𐶐�");
	}

	int CheckPlayerClick(VECTOR _pos);

	void Set_NextPlayerPos(int _playerNum, int _nextRoom, double _nextX)
	{
		player[_playerNum]->Set_NextMove(_nextRoom, _nextX);
		player[_playerNum]->Set_State(eMove);
		DEBUG_LOG("���̍��W�Z�b�g");
	}

};

#endif  // !_INCLUDE_UNIT_MGR_