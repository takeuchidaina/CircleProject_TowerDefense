#include "MapMgr.h"

cMapMgr::cMapMgr(){
	mapLood(fileName);
}
 cMapMgr::~cMapMgr(){
	 
 }

 // �}�b�v�̓ǂݍ���
 bool cMapMgr::mapLood(string fname) {

	 //���C�h�����ϊ��p�̃��P�[���ݒ�
	 std::locale::global(std::locale("japanese"));

	 ifstream ifs;
	 ifs.open(fname.c_str());

	 while (!ifs.eof()) {
		 
		 char c = 0;
		 string line;
		 getline(ifs, line);
		 line.push_back(comma);
		 line.push_back('/0');

		 //deque<string> csvfname;

		 for (int i = 0, j = 0; i < line.size(); i++) {
			 if (line[i] == comma) {
				 string s = line.substr(j, i - j);
				 i++;
				 j = i;
				 map.push_back(s);
			 }
		 }
		 map.push_back(line);
	 }
	 ifs.close();

	 return 1;
 }


void cMapMgr::Init(){	

}

void cMapMgr::Update(){

}

void cMapMgr::Draw(){

}


// 
int cMapMgr::stringChangeInt(int x, int y){
	string s = w(y, x);
	if (s.size() == 0) return -1;
	int n = atoi(s.c_str());
	return n;
}

int cMapMgr::csvSizeY() {
	return map.size();
}

int cMapMgr::csvSizeX(int y) {
	if (y < 0 || y >= map.size()) return -1;
	return map[y].size();
}


////////////////�}�b�v.csv�x�[�X
//Map					         Door01	 Door02	 Door03	 Door04	
//x	y	width	height	maxUnit	 x	y	 x	y	 x	y	 x	y

