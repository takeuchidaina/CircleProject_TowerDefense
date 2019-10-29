#include "Map.h"

//コンストラクタ、初期化
cMap::cMap(double _x, double _y, double _w, double _h, int _maxUnit, int _roomNum, vector<sDoor>& _door) {
	m_pos.x = _x;
	m_pos.y = _y;
	m_pos.z = 0.0f;
	m_width = _w;
	m_height = _w / 4 * 3 ;
	m_maxUnit = _maxUnit;
	m_roomNum = _roomNum;
	m_door = _door;

	img= LoadGraph("../resource/img/Wall.png");
	if (img == NULL) {
		DrawString(50, 50, "画像失敗", GetColor(255,0,255));
	}
}

void cMap::Init() {
	;
}

void cMap::Update() {
	;
}

void cMap::Draw() {
	//とりあえず箱
	DrawBillboard3D(m_pos,0.5,0.5,m_width,0,img,FALSE);
	for (int i = 0; i < m_door.size(); i++) {
		DrawBox(m_door[i].x, m_door[i].y, m_door[i].x + m_door[i].width + 1, m_door[i].y + m_door[i].height + 1, BL, TRUE);
	}

}

bool cMap::CheckInto(double _x, double _y)
{
	if (m_pos.x - (m_width / 2) <= _x - (UNIT_WIDTH / 2) && m_pos.x + (m_width / 2) >= _x + (UNIT_WIDTH / 2))
	{
		// 画像の表示は中心から
		if (m_pos.y - (m_height / 2) <= _y && m_pos.y + (m_height / 2) >= _y)
		{
			return true;
		}
	}

	return false;

}