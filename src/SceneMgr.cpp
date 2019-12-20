#include "SceneMgr.h"

cSceneMgr::cSceneMgr() : m_nextScene(E_SCENE_NONE){

	m_scene = (cBaseScene*) new cGameMgr(this);
	//m_scene = (cBaseScene*) new cTitle(this);
	//m_scene = (cBaseScene*) new cStageSelect(this);
	//m_scene = (cBaseScene*) new cUnitSelect(this);
}

void cSceneMgr::Init() {
	m_scene->Init();
}

void cSceneMgr::Update() {

	// ���̃V�[�����Z�b�g����Ă���Ȃ玟�̃V�[���ɕύX����
	if (m_nextScene != E_SCENE_NONE) {
		m_scene->End();
		delete m_scene;

		switch (m_nextScene){

		case E_SCENE_TITLE:
			m_scene = (cBaseScene*) new cTitle(this);
			break;
		case E_SCENE_MENU:
			m_scene = (cBaseScene*) new cMenu(this);
			break;
		case E_SCENE_STAGESELECT:
			m_scene = (cBaseScene*) new cStageSelect(this);
			break;
		case E_SCENE_UNITSELECT:
			m_scene = (cBaseScene*) new cUnitSelect(this);
			break;
		case E_SCENE_GAME:
			m_scene = (cBaseScene*) new cGameMgr(this);
			break;
		case E_SCENE_RESULT:
			m_scene = (cBaseScene*) new cResult(this);
			break;
		}

		m_nextScene = E_SCENE_NONE;		//���̃V�[�����̃N���A
		m_scene->Init();
	}

	//�X�V����
	m_scene->Update();
}

void cSceneMgr::Draw() {
	//�`�揈��
	m_scene->Draw();
}

void cSceneMgr::End() {
	m_scene->End();
}

void cSceneMgr::ChangeScene(eScene _nextScene) {
	m_nextScene = _nextScene;	// ���̃V�[�����Z�b�g����
}