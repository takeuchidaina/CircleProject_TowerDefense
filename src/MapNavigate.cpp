#include "MapNavigate.h"

vector<vector<int>> mapStack;		// 受け取る変数

cMapNavigate::cMapNavigate() {
	Init();
}

cMapNavigate::~cMapNavigate() {
	;
}

void cMapNavigate::Init() {
	//tmpRand = GetRand(mapStack.size());
}

void cMapNavigate::Update() {
	
}

void cMapNavigate::Draw() {

}

void cMapNavigate::Set_MapDate(vector<vector<int>> _MapDate) {
	mapStack = _MapDate;		// Mapの繋がりを代入
	//tmpRand = GetRand(mapStack.size()-1);
	//int a = mapStack.size()-1;
}

// 敵リスポーンの時に使うGet	Mapの要素数の最後でもある
int cMapNavigate::Get_EnemySpawnRoom() {
	int enemySpawnRoom = mapStack.size()-1;
	return enemySpawnRoom;
}

// _start=出発	_goal=行き先		  			  
int cMapNavigate::MapNavigation(int _start, int _goal) {

	int cnt = 0;
	//_goal = tmpRand;	// 行きたいマップ番号
	_goal = 0;	// 0が護衛対象のテイ

		// 今いるマップに繋がっているマップの数だけループ　
	for (int j = 0; j < mapStack[_start].size(); j++) {

		// 出発==_start, 行き先==_start	なら
		if (mapStack[_start][j] == _start) {
			return _start;						//返す
		}

		// _startでも_goalでもない
		if (mapStack[_start][j] != _start && mapStack[_start][j] != _goal) {
			cnt++;								// 何部屋移動したか
			tbl = mapStack[_start][GetRand(mapStack[_start].size() - 1)];
			return tbl;
		}

		// goalに行ける
		if (mapStack[_start][j] == _goal) {
			cnt++;								// 何部屋移動したか
			tbl = _goal;				// 次の部屋を入れる
			return tbl;
		}
	}
}