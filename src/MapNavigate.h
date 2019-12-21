#pragma once
#include <iostream>
#include <vector>

#include "DxLib.h"
#include "MapMgr.h"
#include "BaseTask.h"
#include "Log.h"

using namespace std;

/********************************************************
���T�v
�@���j�b�g�̃��[�g����

���쐬��

�@�Αq���

���X�V��
********************************************************/
#ifndef _INCLUDE_MAPNAVIGATE_
#define _INCLUDE_MAPNAVIGATE_

class cMapNavigate : public cBaseTask {

protected:

public:

	cMapNavigate();
	virtual ~cMapNavigate();

	//vector<vector<int>> mapStack;		// �󂯎��ϐ�
	//vector<int> tbl;	// �S�[���܂ł̓��̂�
	int tbl;

	void Init()override;
	void Update()override;
	void Draw()override;

	void Set_MapDate(vector<vector<int>> _MapDate);		// MapDate�̎󂯎��

	int Get_EnemySpawnRoom();					// �G���X�|�[���̎��Ɏg��Get

	int MapNavigation(int _start, int _goal);	// �ȈՔ�
	int tmpRand;
};
#endif // !_INCLUDE_MAPNAVIGATE_
