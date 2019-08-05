#include "Map.h"

//コンストラクタ、初期化
cMap::cMap(double _x, double _y, double _w, double _h, int _maxUnit, int _roomNum, vector<sDoor>& _door) {
	m_x = _x;
	m_y = _y;
	m_width = _w;
	m_height = _h;
	m_maxUnit = _maxUnit;
	m_roomNum = _roomNum;
	m_door = _door;
}

cMap::~cMap() {
	;
}

void cMap::Init() {
	;
}

void cMap::Update() {
	;
}

void cMap::Draw() {
	//とりあえず箱
	DrawBox(m_x, m_y, m_x + m_width + 1, m_y + m_height + 1, WH, TRUE);
	for (int i = 0; i < m_door.size(); i++) {
		DrawBox(m_door[i].x, m_door[i].y, m_door[i].x + m_door[i].width + 1, m_door[i].y + m_door[i].height + 1, BL, TRUE);
	}
}

void cMap::End() {
	;
}