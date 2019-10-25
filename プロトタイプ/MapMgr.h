#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
//#include <deque>
#include "DxLib.h"
#include "BaseTask.h"
#include "CSVLoad.h"
#include "Map.h"

using namespace std;

/*******************�Q�l�T�C�g****************************
https://qiita.com/takoyaki3/items/269060a916a66d9c411a		csv�ǂݍ���
*********************************************************/

/**********************************************************
 substr�c���o�������͏ȗ����邱�Ƃ��ł��A���̏ꍇ�͎w�肵���ʒu����Ō�܂ł�
		 ������������擾�ł��܂��B

	��)	 �ϐ�.substr(�J�n�ʒu, ���o������);
*********************************************************/


#ifndef _INCLUDE_MAPMGR_
#define _INCLUDE_MAPMGR_

class cMapMgr : public cBaseTask {
public:
	vector<cMap>map;		// cMap�̐錾
	vector<vector<double>> tmpMap; //���i�[

	string fileName;			//�t�@�C���l�[��
	int mapnum;					// ������

	cMapMgr();
	~cMapMgr();

	virtual void Init();
	virtual void Update();
	virtual void Draw();
};

#endif _INCLUDE_MAPMGR_