#pragma once
using namespace std;
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
//#include <deque>
#include "DxLib.h"
#include "BaseTask.h"

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
private:
	//deque<deque<string>> csvfname;
	char comma; //��؂�ƂȂ�J���}�B
	cMapMgr();

public:
	std::vector<cMap> map;		// cMap�̐錾

	bool mapLood(string line);				// �}�b�v�����[�h����֐�
	string fileName;
	string w (int x, int y);
	int stringChangeInt(int x, int y);		// string�̕������int�ɂ��Ă�
	int csvSizeY();							// csv�t�@�C���̍s���擾
	int csvSizeX(int x);					// �擾�����s���w�肵�ė���擾
	int mapnum;								// ������

	void SetComma(char c) { comma = c; }

	cMapMgr() {comma = L','; }
	cMapMgr(string fname) { comma = ','; mapLood(fname); }

	virtual void Init();
	virtual void Update();
	virtual void Draw();
};

#endif _INCLUDE_MAPMGR_