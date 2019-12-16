#include "InGameBackGround.h"

cBackGround::cBackGround() {
	Init();
}

cBackGround::~cBackGround() {
	End();
}

void cBackGround::Init() {

	//‰æ‘œ“Ç‚Ýž‚Ý
	//”g
	m_wave = LoadGraph("../resource/img/wave.png");
	FileCheck(m_wave);
	//”wŒi
	m_BG = LoadGraph("../resource/img/Sea.jpg");
	FileCheck(m_BG);
	//‘D
	m_ship = LoadGraph("../resource/img/Ship.png");
	FileCheck(m_ship);
	//‰_
	m_cloud[0].pos = VGet(0.0f, 0.0f, 0.0f);
	m_cloud[0].image = LoadGraph("../resource/img/BG_Cloud.png");
	FileCheck(m_cloud[0].image);
	m_cloud[1].pos = VGet(-1870.0f, 0.0f, 0.0f);
	m_cloud[1].image = LoadGraph("../resource/img/BG_Cloud.png");
	FileCheck(m_cloud[1].image);
}

void cBackGround::Update() {
	MoveBackGround();	//‰_‚ð“®‚©‚·
}

void cBackGround::Draw() {
	DrawBillboard3D(VGet(0.0f, 0.0f, 0.0f), 0.5, 0.5, 1280, 0, m_BG, TRUE);				//”wŒi
	DrawBillboard3D(VGet(m_cloud[0].pos.x, m_cloud[0].pos.y, m_cloud[0].pos.z),
										0.5, 0.5, 1903, 0, m_cloud[0].image, TRUE);		//‰_(‰Šú‰æ–Ê“à)
	DrawBillboard3D(VGet(m_cloud[1].pos.x, m_cloud[1].pos.y, m_cloud[1].pos.z),
										0.5, 0.5, 1903, 0, m_cloud[1].image, TRUE);		//‰_(Œã‘±)
	DrawBillboard3D(VGet(0.0f, 0.0f, 0.0f), 0.5, 0.5, 1280, 0, m_ship, TRUE);			//‘D
	DrawBillboard3D(VGet(-10.0f, -20.0f, 0.0f), 0.5, 0.5, 1280, 0, m_wave, TRUE);		//”g
}

void cBackGround::End() {

	//‰æ‘œ‚Ìƒƒ‚ƒŠŠ„‚è“–‚Äíœ
	DeleteGraph(m_BG);
	DeleteGraph(m_cloud[0].image);
	DeleteGraph(m_cloud[1].image);
	DeleteGraph(m_ship);
	DeleteGraph(m_wave);
}


void cBackGround::MoveBackGround() {

	//ˆÚ“®
	m_cloud[0].pos.x += CLOUD_SPEED;
	m_cloud[1].pos.x += CLOUD_SPEED;

	//‰æ–ÊŠOˆ—AƒXƒNƒ[ƒ‹Ý’è
	//‰æ‘œ‚ª‰¡‚ÉŒq‚ª‚é‚æ‚¤‚É‚È‚Á‚Ä‚¢‚é
	//‰æ–ÊŠO‚És‚­‚ÆA‰æ–Ê“à‚Ì‰æ‘œ‚ÌŒã‚ë‚ÉˆÚ“®
	if (m_cloud[0].pos.x >= 1870.0f) {
		m_cloud[0].pos.x = m_cloud[1].pos.x - 1870.0f;
	}
	else if (m_cloud[1].pos.x >= 1870.0f) {
		m_cloud[1].pos.x = m_cloud[0].pos.x - 1870.0f;
	}
}