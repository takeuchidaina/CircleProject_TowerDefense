#include "MapMgr.h"

cMapMgr::cMapMgr(){
	mapLood(fileName);
}
 cMapMgr::~cMapMgr(){
	 
 }

 // マップの読み込み
 bool cMapMgr::mapLood(string fname) {

	 //ワイド文字変換用のロケール設定
	 std::locale::global(std::locale("japanese"));

	 std::ifstream ifs("test.txt");				//	ファイルストリームを宣言
	 ifs.open(fname.c_str());	// ファイルを開く

	 if (!ifs) {		// エラー処理     ifsをつけるのはファイルを開くのを失敗したかどうか
		 std::cerr <<"ファイルオープン失敗" << std::endl;
		 std::exit(1);
	 }

	 while (!ifs.eof()) {		// ファイルストリームが終わるまで回る
		 
		 char c = 0;
		 string line;
		 getline(ifs, line);	 // ifsで開いたファイルから1行読み込む
		 line.push_back(comma);  // 配列に','を追加
		 line.push_back('/0');

		 //deque<string> csvfname;

		 for (int i = 0, j = 0; i < line.size(); i++) {
			 if (line[i] == comma) {
				 string s = line.substr(j, i - j);
				 i++;
				 j = i;
				 map.push_back(s);	// 配列に一時保存
			 }
		 }
		 map.push_back(line);		// 配列に保存
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
int cMapMgr::stringChangeInt(int x, int y){		// string型をint型にする
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


////////////////マップ.csvベース
//Map					         Door01	 Door02	 Door03	 Door04	
//x	y	width	height	maxUnit	 x	y	 x	y	 x	y	 x	y

