#pragma once
#include <iostream>
#include <vector>

#include "DxLib.h"
#include "MapMgr.h"
#include "BaseTask.h"


using namespace std;

#ifndef _INCLUDE_MAP_NAVIGATE_
#define _INCLUDE_MAP_NAVIGATE_

/********************************************************
���T�v
�@���j�b�g�̃��[�g����

���쐬��

�@�Αq���

���X�V��
********************************************************/

class cMapNavigate : public cBaseTask {

protected:
	vector<vector<int>> mapStack;		// �󂯎��ϐ�
	vector<vector<int>> tmpMapStack;	// 

	int moveDistance;	
	

public:

	cMapNavigate();
	~cMapNavigate();

	virtual void Init();
	virtual void Update();
	virtual void Draw();

	//void Set_MapDate();
	int InspectMove(int _x, int _y, int _renge);		// Map�̃��[�g�����֐�
	int MapNavigation(int _x, int _y);						// Map�̃��[�g�����֐�
};
#endif // _INCLUDE__MAP_NAVIGATE_