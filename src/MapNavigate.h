#pragma once
#include <iostream>
#include <vector>

#include "DxLib.h"
#include "MapMgr.h"
#include "BaseTask.h"

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
	vector<vector<int>> mapStack;		// �󂯎��ϐ�
	vector<int> tbl;	// �S�[���܂ł̓��̂�
	int tmpRand;


public:

	cMapNavigate();
	virtual ~cMapNavigate();

	void Init()override;
	void Update()override;
	void Draw()override;

	void Get_MapDate(vector<vector<int>> _MapDate);		// MapDate�̎󂯎��

	//int InspectMove(int _x, int _y, int _renge);		// Map�̃��[�g�����֐�
	//bool isMapNavigation(int _start, int _goal);						// Map�̃��[�g�����֐�
	int MapNavigation(int _start, int _goal);	// �ȈՔ�
};
#endif // !_INCLUDE_MAPNAVIGATE_
