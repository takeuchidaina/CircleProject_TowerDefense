#include "MapMgr.h"

cMapMgr::cMapMgr(){			// コンスト

	MapLood(/*fileName*/);
}
 cMapMgr::~cMapMgr(){
	 
 }

 // マップの読み込み
 bool cMapMgr::MapLood(/*string _fname*/) {

	 //ワイド文字変換用のロケール設定
	 locale::global(locale("japanese"));

	 strcpy(MapBase, "MAP/Test");

	 sprintf(MapNum, "%d", MapFlag);

	 strcpy(MapHandle, MapBase);	 

	 strcat(MapHandle, MapNum);

	 strcat(MapHandle, ".csv");

	 ifstream ifs;						// ファイルストリームを宣言
	 ifs.open(MapHandle);				// ファイルを開く

	 if (!ifs) {		// エラー処理     ifsをつけるのはファイルを開くのを失敗したかどうか
		 cerr <<"ファイルオープン失敗" << endl;
		 exit(1);
	 }

	 /*
	 for (int i = 0; i < _MAP_STATUS_; i++) {
		 int n;
		 cin >> n;
		 cMap.push_back(n);
	 }
	 */

	 while (!ifs.eof()) {		// ファイルストリームが終わるまで回る
		 
		 //char c = 0;
		 string line;

		 getline(ifs, line);	 // ifsで開いたファイルから1行読み込む
		 cin >> line;			 // 一行読み込み
		 if(line == comma){
			 int tmp = atoi(line.c_str());		// stringをint
			 cMap.push_back(tmp);
		 }
		 /////////////////////////////////////////////////////

		 line.push_back(',');  // 配列に','を追加
		 

		 //deque<string> csvfname;

		 for (int i = 0, j = 0; i < line.size(); i++) {
			 if (line[i] == comma) {
				 string s = line.substr(j, i - j);		// jからi-jをstring sに代入
				 i++;
				 j = i;
				 line.push_back(s);	// 配列に一時保存
			 }
		 }
		 line.push_back(line);		// 配列に保存
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


int cMapMgr::AsciiToInt(int _x, int _y) {		// string型をint型にする
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

////////////////マップ.csvベース
//Map					         Door01	 Door02	 Door03	 Door04	
//x	y	width	height	maxUnit	 x	y	 x	y	 x	y	 x	y

