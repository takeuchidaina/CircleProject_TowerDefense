#include "cMap.h"

cMap::cMap(double _x, double _y, double _width, double _height, int _num)
{
	m_pos = VGet(_x, _y, 0.0f);
	m_width = _width;
	m_height = _height;
	m_num = _num;

	img = LoadGraph("../resource/img/‰¼ƒ}ƒbƒv.jpg");

}

void cMap::Update()
{

}

void cMap::Draw()
{
	DrawBillboard3D(m_pos, 0.5f, 0.5f, m_width, 0.0f, img, FALSE);
	DrawFormatString(200, 200, RD, "%f", m_pos.x);
	DrawFormatString(200, 250, RD, "%f", m_pos.y);
	DrawFormatString(200, 225, RD, "%f", m_pos.x+m_width);
	DrawFormatString(200, 270, RD, "%f", m_pos.y+m_height);
}