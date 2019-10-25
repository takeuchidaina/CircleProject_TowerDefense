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

	img= LoadGraph("../resource/img/sample.png");
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
	DrawBillboard3D(VGet(m_x,m_y,0.0f),0.5,0.5,400,0,0,img,FALSE);
	for (int i = 0; i < m_door.size(); i++) {
		DrawBox(m_door[i].x, m_door[i].y, m_door[i].x + m_door[i].width + 1, m_door[i].y + m_door[i].height + 1, BL, TRUE);
	}
}

//高井追加
bool cMap::CheckInto(double _x, double _y)
{
	if (m_x + (UNIT_HEIGHT / 2) <= _x && m_x + m_width - (UNIT_WIDTH / 2) >= _x)
	{
		if (m_y <= _y && m_y + m_height >= _y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}
//ここまで