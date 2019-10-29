#include "EscortTarget.h"

cEscortTarget::cEscortTarget()
{
	m_hp = 500;
	m_pos.x = 0.0f;
	m_pos.y = 0.0f;
	m_pos.z = 0.0f;
	m_room = 0;

	m_img = LoadGraph("../resource/img/sample.png");
	if (m_img == NULL) {
		DrawString(50, 50, "‰æ‘œ¸”s", GetColor(255, 0, 255));
	}
}

cEscortTarget::~cEscortTarget()
{
}

void cEscortTarget::Init() {

}
void cEscortTarget::Update() {
	
}
void cEscortTarget::Draw() {
	DrawBillboard3D(m_pos, 0.5, 0.5, 60, 0, m_img, FALSE);
	DrawFormatString(100, 130, BL, "HP:%d", m_hp);
}
void cEscortTarget::End() {

}

bool cEscortTarget::DamageCalc(int _damage) {
	m_hp -= _damage;

	if (m_hp > 0) {
		return true;	//¶‘¶
	}
	else {
		return false;	//GameOver
	}
}