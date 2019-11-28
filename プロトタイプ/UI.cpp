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
	m_UI[E_BG_SORD] = { m_UI[E_CHAR_SORD].ux - tyousei, m_UI[E_CHAR_SORD].uy - tyousei,
						  m_UI[E_CHAR_SORD].ux - tyousei + bgSizeX, m_UI[E_CHAR_SORD].uy - tyousei + bgSizeY,
							"../resource/img/UI_BG.png",0 };
	m_UI[E_BG_ARCHER] = { m_UI[E_CHAR_ARCHER].ux - tyousei, m_UI[E_CHAR_ARCHER].uy - tyousei,
						  m_UI[E_CHAR_ARCHER].ux - tyousei + bgSizeX, m_UI[E_CHAR_ARCHER].uy - tyousei + bgSizeY
							,"../resource/img/UI_BG.png",0 };
	m_UI[E_BG_SHIELD] = { m_UI[E_CHAR_SHIELD].ux - tyousei, m_UI[E_CHAR_SHIELD].uy - tyousei,
						  m_UI[E_CHAR_SHIELD].ux - tyousei + bgSizeX, m_UI[E_CHAR_SHIELD].uy - tyousei + bgSizeY,
							"../resource/img/UI_BG.png",0 };

	m_UI[E_BG_SUM] = { m_UI[E_BG_SHIELD].ux, m_UI[E_BG_SHIELD].uy + bgSizeY,
						  m_UI[E_BG_SHIELD].ux + bgSizeX/1.3f, m_UI[E_CHAR_SHIELD].uy + bgSizeY + bgSizeY - tyousei,
						"../resource/img/UI_BG.png",0 };

	for (int i = 0; i < E_UI_LENGTH; i++) {
		m_UI[i].image = LoadGraph(m_UI[i].path.c_str());
		FileCheck(m_UI[i].image);
	}

	m_maxPlayer = 15;	//MapMgr‚©GameMgr‚©‚çŽæ“¾
	m_playerCnt[0] = 0;m_playerCnt[1] = 0;m_playerCnt[2] = 0;

}

void cUI::Update() {
	for (int i = 0; i < sizeof(m_maxPlayer); i++) {
		//m_playerCnt[i] = ƒvƒŒƒCƒ„[‚Ì”;
	}
	m_sumPlayerCnt = m_playerCnt[0] + m_playerCnt[1] + m_playerCnt[2];
}

void cUI::Draw() {

	for (int i = 0; i < E_UI_LENGTH; i++) {
		DrawExtendGraph(m_UI[i].ux, m_UI[i].uy, m_UI[i].dx, m_UI[i].dy, m_UI[i].image, TRUE);
	}

	DrawFormatString(m_UI[E_CHAR_SORD].ux + 60, m_UI[E_CHAR_SORD].uy + 10, BK, "~ %d", m_playerCnt[0]);
	DrawFormatString(m_UI[E_CHAR_ARCHER].ux + 60, m_UI[E_CHAR_ARCHER].uy + 10, BK, "~ %d", m_playerCnt[1]);
	DrawFormatString(m_UI[E_CHAR_SHIELD].ux + 60, m_UI[E_CHAR_SHIELD].uy + 10, BK, "~ %d", m_playerCnt[2]);
	DrawFormatString(m_UI[E_BG_SUM].ux+10, m_UI[E_BG_SUM].uy + 15,BK,"%d / %d",m_sumPlayerCnt,m_maxPlayer);

}

void cUI::End() {
	for (int i = 0; i < E_UI_LENGTH; i++) {
		DeleteGraph(m_UI[i].image);
	}
	
}
