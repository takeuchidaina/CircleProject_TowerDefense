
#pragma once
#include <iostream>
#include <vector>

#include "DxLib.h"
#include "MapMgr.h"
#include "BaseTask.h"
#include "GameMgr.h"

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
	vector<int> tbl;	// �S�[���܂ł̓��̂�

	int moveDistance;	
	
public:

	cMapNavigate();
	virtual ~cMapNavigate();

	virtual void Init();
	virtual void Update();
	virtual void Draw();

	void Get_MapDate(vector<vector<int>> _i);		// MapDate�̎󂯎��

	int InspectMove(int _x, int _y, int _renge);		// Map�̃��[�g�����֐�
	bool isMapNavigation(int _start, int _goal);						// Map�̃��[�g�����֐�
	int MapNavigation(int _start, int _goal);	// �ȈՔ�
};
#endif // _INCLUDE__MAP_NAVIGATE_
