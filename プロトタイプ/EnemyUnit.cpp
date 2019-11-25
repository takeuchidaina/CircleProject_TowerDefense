#include "EnemyUnit.h"
/*
cEnemyUnit::cEnemyUnit() {

	Init();
}

cEnemyUnit::~cEnemyUnit() {
	;
}
*/

void cEnemyUnit::Init() {
	
	//mapStack = GetMapDes();

}

int cEnemyUnit::Get_Num() {
	return m_num;
}
/*
void cEnemyUnit::Set_NextMove(int _nextRoom, double _nextX) {
	m_nextMove.sNextRoom = _nextRoom;
	m_nextMove.sNextX = _nextX;
}
*/

/*
void cEnemyUnit::EnemyMove() {
	DEBUG_LOG("enemyMove来たよ");
	if (m_room == m_nextMove.sNextRoom)
	{
		if (m_direction = U_LEFT) {

			m_pos.x -= m_speed;
		}
	}
}
*/

void Set_MapSize(int _i) {
	return;
}
// マップの番後のセット関数　田島が作った2重Vectorを代入
// mapDate-マップ番号
// TODO
// vector<vector<int>> mapStack(vector<vector<int>>& _mapDate) {
	
//}

// Mapのルート検索関数
void cEnemyUnit::MapNavigation() {
	/*
	for (int i; i < mapStack(); i++) {
	mapStack.push_back();
	*/
}

void cEnemyUnit::Update() {

}

void cEnemyUnit::Draw() {

}
