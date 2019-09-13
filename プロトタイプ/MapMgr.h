#pragma once
using namespace std;
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdlib.h>

#include "DxLib.h"
#include "BaseTask.h"
#include "Map.h"

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

#define _MAP_STATUS_ 7

class cMapMgr : public cBaseTask {
private:
	//deque<deque<string>> csvfname;
	string comma; //��؂�ƂȂ�J���}�B
	cMapMgr();

public:
	vector<int> cMap;		// cMap�̐錾

	bool MapLood(/*string _line*/);				// �}�b�v�����[�h����֐�
	string fileName;
	//string w (int _x, int _y);
	int AsciiToInt(int _x, int _y);		    // string�̕������int�ɂ��Ă�
	int CsvSizeY();							// csv�t�@�C���̍s���擾
	int CsvSizeX(int _x);					// �擾�����s���w�肵�ė���擾
	

	// MAP�̃I�[�v���Ɏg���ϐ�����
	char MapBase[256];						// (MAP/MAP_)�܂ł�����
	char MapHandle[256];					//	���ʓI�ɊJ���ϐ�
	char MapNum[256];						// ��������Map�̃i���o�[
	int MapFlag = 1;						// MapNum�ɑ���O�̐���	

	void SetComma(string _c) { comma = _c; }

	cMapMgr() {comma = ','; }
	//cMapMgr(string _fname) { comma = ','; MapLood(_fname); }

	virtual void Init();
	virtual void Update();
	virtual void Draw();
};

#endif _INCLUDE_MAPMGR_