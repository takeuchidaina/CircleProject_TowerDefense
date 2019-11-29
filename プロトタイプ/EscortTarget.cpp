#include "EscortTarget.h"

cEscortTarget::~cEscortTarget()
{
}

void cEscortTarget::Init() {

}
void cEscortTarget::Update() {
	
}
void cEscortTarget::Draw() {
	DrawBillboard3D(m_pos, 0.5, 0.5, 60, 0, m_img, TRUE);
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