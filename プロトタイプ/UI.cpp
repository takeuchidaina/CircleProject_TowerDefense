#include "UI.h"

cUI::cUI()
{
	Init();
}

cUI::~cUI()
{
	End();
}

void cUI::Init() {

	int bgSizeX = 130;
	int bgSizeY = 42;
	int charSize = 32;
	m_UI[E_CHAR_SORD]   = { 10, 10, 62, 42,"../resource/img/UI_Sord.png",0 };
	m_UI[E_CHAR_ARCHER] = { 10, 52, 62, 84,"../resource/img/UI_Archer.png",0 };
	m_UI[E_CHAR_SHIELD] = { 10, 94, 62, 126,"../resource/img/UI_Shield.png",0 };
	
	int tyousei = 5;
	m_UI[E_BG_SORD]   = { m_UI[E_CHAR_SORD].ux - tyousei, m_UI[E_CHAR_SORD].uy - tyousei,
						  m_UI[E_CHAR_SORD].ux - tyousei + bgSizeX, m_UI[E_CHAR_SORD].uy - tyousei + bgSizeY,
							"../resource/img/UI_BG.png",0 };
	m_UI[E_BG_ARCHER] = { m_UI[E_CHAR_ARCHER].ux - tyousei, m_UI[E_CHAR_ARCHER].uy - tyousei,
						  m_UI[E_CHAR_ARCHER].ux - tyousei + bgSizeX, m_UI[E_CHAR_ARCHER].uy - tyousei + bgSizeY
							,"../resource/img/UI_BG.png",0 };
	m_UI[E_BG_SHIELD] = { m_UI[E_CHAR_SHIELD].ux - tyousei, m_UI[E_CHAR_SHIELD].uy - tyousei,
						  m_UI[E_CHAR_SHIELD].ux - tyousei + bgSizeX, m_UI[E_CHAR_SHIELD].uy - tyousei + bgSizeY,
							"../resource/img/UI_BG.png",0 };

	m_UI[E_BG_SUM] = { m_UI[E_BG_SHIELD].ux, m_UI[E_BG_SHIELD].uy + bgSizeY,
						  m_UI[E_BG_SHIELD].ux + bgSizeX / 2, m_UI[E_CHAR_SHIELD].uy + bgSizeY + bgSizeY - tyousei,
						"../resource/img/UI_BG.png",0 };

	for (int i = 0; i < E_UI_LENGTH;i++) {
		m_UI[i].image = LoadGraph(m_UI[i].path.c_str());
		FileCheck(m_UI[i].image);
	}
}

void cUI::Update() {
	//キャラクターの数を取得

}

void cUI::Draw() {

	for (int i = 0; i < E_UI_LENGTH; i++) {
		DrawExtendGraph(m_UI[i].ux, m_UI[i].uy, m_UI[i].dx, m_UI[i].dy, m_UI[i].image, TRUE);
	}

}

void cUI::End() {
	for (int i = 0; i < E_UI_LENGTH; i++) {
		DeleteGraph(m_UI[i].image);
	}
	
}
