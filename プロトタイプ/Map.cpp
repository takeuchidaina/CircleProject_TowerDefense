#include "Map.h"
#include "ErrorCheck.h"

//�R���X�g���N�^�A������
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
		DrawString(50, 50, "�摜���s", GetColor(255,0,255));
	}
}
*/

//�h�A�Ȃ��p
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

	mapImg = LoadGraph("../resource/img/Wall.png");
	doorImg = LoadGraph("../resource/img/Door.png");
	if (mapImg == NULL) FileCheck(mapImg);
	if (doorImg == NULL) FileCheck(doorImg);
}

void cMap::Init() {
	;
}

void cMap::Update() {
	;
}

void cMap::Draw() {
	//DrawBillboard3D( VECTOR Pos, float cx, float cy, float Size, float Angle, int GrHandle, int TransFlag );
	DrawBillboard3D(m_pos,0,0,m_width,0,mapImg,FALSE);
	
	//�h�A�`�� �R�����g�A�E�g�Ȃ�
	/*
	for (int i = 0; i < m_door.size(); i++) {
		DrawBillboard3D(m_door[i].pos, 0, 0, 100, 0, doorimg, FALSE);
	}
	*/

}

bool cMap::CheckInto(double _x, double _y)
{
	if (m_pos.x <= _x - (UNIT_WIDTH / 2) && m_pos.x + m_width >= _x + (UNIT_WIDTH / 2))
	{
		// �摜�̕\���͒��S����
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