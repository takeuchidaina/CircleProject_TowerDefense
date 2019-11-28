#include "Map.h"
#include "ErrorCheck.h"

//コンストラクタ、初期化
/*
cMap::cMap(double _x, double _y, double _w, double _h, 
	int _maxUnit, int _roomNum, vector<sDoor>& _door) {
	m_pos.x = _x;
	m_pos.y = _y;
	m_pos.z = 0.0f;
	m_width = _w;
	m_height = _w / 4 * 3 ;
	m_maxUnit = _maxUnit;
	m_roomNum = _roomNum;
	m_door = _door;

	mapimg= LoadGraph("../resource/img/Wall.png");
	doorimg = LoadGraph("../resource/img/Door.png");
	if (mapimg == NULL) {
		DrawString(50, 50, "画像失敗", GetColor(255,0,255));
	}
}
*/

//ドアなし用
cMap::cMap(double _x, double _y, double _w, double _h,
	int _maxUnit, int _roomNum, vector<int>& _des, bool _startMapFlg, bool _DefenseMapFlg) {
	m_pos.x = _x;
	m_pos.y = _y;
	m_pos.z = 0.0f;
	m_width = _w;
	m_height = _w / 4 * 3;
	m_maxUnit = _maxUnit;
	m_roomNum = _roomNum;
	m_des = _des;
	m_startMapFlg = _startMapFlg;
	m_DefenseMapFlg = _DefenseMapFlg;

	m_mapImg = LoadGraph("../resource/img/Wall.png");
	//m_doorImg = LoadGraph("../resource/img/Door.png");
	FileCheck(m_mapImg);
	//FileCheck(m_doorImg);
}

void cMap::Init() {
	;
}

void cMap::Update() {
	;
}

void cMap::Draw() {
	//DrawBillboard3D( VECTOR Pos, float cx, float cy, float Size, float Angle, int GrHandle, int TransFlag );
	DrawBillboard3D(m_pos,0,0,m_width,0,m_mapImg,FALSE);
	
	//ドア描画 コメントアウトなう
	/*
	for (int i = 0; i < m_door.size(); i++) {
		DrawBillboard3D(m_door[i].pos, 0, 0, 100, 0, m_doorImg, FALSE);
	}
	*/

}

bool cMap::CheckInto(double _x, double _y)
{
	if (m_pos.x <= _x - (UNIT_WIDTH / 2) && m_pos.x + m_width >= _x + (UNIT_WIDTH / 2))
	{
		// 画像の表示は中心から
		if (m_pos.y <= _y && m_pos.y + m_height >= _y)
		{
			return true;
		}
	}

	return false;

}

int cMap::GetRoomSize()
{
	return m_maxUnit;
}

VECTOR cMap::GetPos()
{
	return m_pos;
}

double cMap::GetWidth()
{
	return m_width;
}

double cMap::GetHeight()
{
	return m_height;
}