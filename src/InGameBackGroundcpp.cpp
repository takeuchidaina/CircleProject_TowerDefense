#include "InGameBackGround.h"

cBackGround::cBackGround() {
	Init();
}

cBackGround::~cBackGround() {
	End();
}

void cBackGround::Init() {

	//画像読み込み
	//波
	m_wave = LoadGraph("../resource/img/wave.png");
	FileCheck(m_wave);
	//背景
	m_BG = LoadGraph("../resource/img/Sea.jpg");
	FileCheck(m_BG);
	//船
	m_ship = LoadGraph("../resource/img/Ship.png");
	FileCheck(m_ship);
	//雲
	m_cloud[0].pos = VGet(0.0f, 0.0f, 0.0f);
	m_cloud[0].image = LoadGraph("../resource/img/BG_Cloud.png");
	FileCheck(m_cloud[0].image);
	m_cloud[1].pos = VGet(1870.0f, 0.0f, 0.0f);
	m_cloud[1].image = LoadGraph("../resource/img/BG_Cloud.png");
	FileCheck(m_cloud[1].image);
}

void cBackGround::Update() {
	MoveBackGround();	//雲を動かす
}

void cBackGround::Draw() {
	DrawBillboard3D(VGet(0.0f, 0.0f, 0.0f), 0.5, 0.5, 1280, 0, m_BG, TRUE);				//背景
	DrawBillboard3D(VGet(m_cloud[0].pos.x, m_cloud[0].pos.y, m_cloud[0].pos.z),
										0.5, 0.5, 1903, 0, m_cloud[0].image, TRUE);		//雲(初期画面内)
	DrawBillboard3D(VGet(m_cloud[1].pos.x, m_cloud[1].pos.y, m_cloud[1].pos.z),
										0.5, 0.5, 1903, 0, m_cloud[1].image, TRUE);		//雲(後続)
	DrawBillboard3D(VGet(0.0f, 0.0f, 0.0f), 0.5, 0.5, 1280, 0, m_ship, TRUE);			//船
	DrawBillboard3D(VGet(-10.0f, -20.0f, 0.0f), 0.5, 0.5, 1280, 0, m_wave, TRUE);		//波
}

void cBackGround::End() {

	//画像のメモリ割り当て削除
	DeleteGraph(m_BG);
	DeleteGraph(m_cloud[0].image);
	DeleteGraph(m_cloud[1].image);
	DeleteGraph(m_ship);
	DeleteGraph(m_wave);
}


void cBackGround::MoveBackGround() {

	//移動
	m_cloud[0].pos.x -= CLOUD_SPEED;
	m_cloud[1].pos.x -= CLOUD_SPEED;

	//画面外処理、スクロール設定
	//画像が横に繋がるようになっている
	//画面外に行くと、画面内の画像の後ろに移動
	if (m_cloud[0].pos.x <= -1870.0f) {
		m_cloud[0].pos.x = m_cloud[1].pos.x + 1870.0f;
	}
	else if (m_cloud[1].pos.x <= -1870.0f) {
		m_cloud[1].pos.x = m_cloud[0].pos.x + 1870.0f;
	}
}