#include "SceneMgr.h"

cSceneMgr::cSceneMgr() : m_nextScene(E_SCENE_NONE){

	//m_scene = (cBaseScene*) new cInGameMgr(this);
}

void cSceneMgr::Init() {
	m_scene->Init();
}

void cSceneMgr::Update() {

	// ���̃V�[�����Z�b�g����Ă�����
	if (m_nextScene != E_SCENE_NONE) {
		m_scene->End();
		delete m_scene;

		// �V�[���ɂ���ď����𕪊�
		switch (m_nextScene){

		case E_SCENE_TITLE:
			//m_scene = (cBaseScene*) new cTitle(this);
			break;
		case E_SCENE_MENU:
			//m_scene = (cBaseScene*) new cMenu(this);
			break;
		case E_SCENE_GAME:
			//m_scene = (cBaseScene*) new cGame(this);
			break;
		case E_SCENE_RISULT:
			//m_scene = (cBaseScene*) new cRisult(this);
			break;

		}

		m_nextScene = E_SCENE_NONE;		// ���̃V�[�����̃N���A
		m_scene->Init();
	}

	m_scene->Update();
}

void cSceneMgr::Draw() {
	m_scene->Draw();
}

void cSceneMgr::End() {
	m_scene->End();
}

void cSceneMgr::ChangeScene(eScene _nextScene) {
	m_nextScene = _nextScene;	// ���̃V�[�����Z�b�g����
}