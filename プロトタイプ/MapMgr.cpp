#include "MapMgr.h"

cMapMgr::cMapMgr(){			// �R���X�g

	MapLood(/*fileName*/);
}
 cMapMgr::~cMapMgr(){
	 
 }

 // �}�b�v�̓ǂݍ���
 bool cMapMgr::MapLood(/*string _fname*/) {

	 //���C�h�����ϊ��p�̃��P�[���ݒ�
	 locale::global(locale("japanese"));

	 strcpy(MapBase, "MAP/Test");

	 sprintf(MapNum, "%d", MapFlag);

	 strcpy(MapHandle, MapBase);	 

	 strcat(MapHandle, MapNum);

	 strcat(MapHandle, ".csv");

	 ifstream ifs;						// �t�@�C���X�g���[����錾
	 ifs.open(MapHandle);				// �t�@�C�����J��

	 if (!ifs) {		// �G���[����     ifs������̂̓t�@�C�����J���̂����s�������ǂ���
		 cerr <<"�t�@�C���I�[�v�����s" << endl;
		 exit(1);
	 }

	 /*
	 for (int i = 0; i < _MAP_STATUS_; i++) {
		 int n;
		 cin >> n;
		 cMap.push_back(n);
	 }
	 */

	 while (!ifs.eof()) {		// �t�@�C���X�g���[�����I���܂ŉ��
		 
		 //char c = 0;
		 string line;

		 getline(ifs, line);	 // ifs�ŊJ�����t�@�C������1�s�ǂݍ���
		 cin >> line;			 // ��s�ǂݍ���
		 if(line == comma){
			 int tmp = atoi(line.c_str());		// string��int
			 cMap.push_back(tmp);
		 }
		 /////////////////////////////////////////////////////

		 line.push_back(',');  // �z���','��ǉ�
		 

		 //deque<string> csvfname;

		 for (int i = 0, j = 0; i < line.size(); i++) {
			 if (line[i] == comma) {
				 string s = line.substr(j, i - j);		// j����i-j��string s�ɑ��
				 i++;
				 j = i;
				 line.push_back(s);	// �z��Ɉꎞ�ۑ�
			 }
		 }
		 line.push_back(line);		// �z��ɕۑ�
	 }
	 ifs.close();

	 return 1;
 }

void cMapMgr::Init(){	

}

void cMapMgr::Update(){

}

void cMapMgr::Draw(){
	cout << endl;
}

/*
string cMapMgr::w(int _y, int _x) {
	if (_x < 0 || _y < 0) return L'';
	if (_y >= map.size()) return L'';
	if (_x >= map[_y].size()) return L'';

	return map[_y][_x];
}
*/


int cMapMgr::AsciiToInt(int _x, int _y) {		// string�^��int�^�ɂ���
	string strTmp = w(_y, _x);					// 
	if (strTmp.size() == 0) return -1;
	int intTmp = atoi(strTmp.c_str());
	cout << strlen(strTmp.c_str()) << "\n";
	return intTmp;
}

int cMapMgr::CsvSizeY() {
	return cMap.size();
}

int cMapMgr::CsvSizeX(int _y) {
	if (_y < 0 || _y >= cMap.size()) return -1;
	return cMap[_y].size();
}

////////////////�}�b�v.csv�x�[�X
//Map					         Door01	 Door02	 Door03	 Door04	
//x	y	width	height	maxUnit	 x	y	 x	y	 x	y	 x	y

