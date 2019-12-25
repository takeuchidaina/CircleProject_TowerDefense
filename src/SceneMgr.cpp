#include "SceneMgr.h"

cSceneMgr::cSceneMgr() : m_nextScene(E_SCENE_NONE){

	m_scene = (cBaseScene*) new cGameMgr(this);
	m_nowScene = E_SCENE_GAME;
	//m_scene = (cBaseScene*) new cTitle(this);
	//m_scene = (cBaseScene*) new cStageSelect(this);
	//m_scene = (cBaseScene*) new cUnitSelect(this);
}

void cSceneMgr::Init() {
	m_scene->Init();
}

void cSceneMgr::Update() {

	//�ݒ肪�I��������
	if (m_setting.GetEndSetting() == TRUE) {
		isPose = FALSE;
	}

	if (GET_KEY_PRESS(KEY_INPUT_ESCAPE) == 1) {
		isPose = TRUE;
	}


	// ���̃V�[�����Z�b�g����Ă���Ȃ玟�̃V�[���ɕύX����
	if (m_nextScene != E_SCENE_NONE) {
		m_scene->End();
		delete m_scene;

		switch (m_nextScene){

		case E_SCENE_TITLE:
			m_scene = (cBaseScene*) new cTitle(this);
			m_nowScene = E_SCENE_TITLE;
			break;
		case E_SCENE_MENU:
			m_scene = (cBaseScene*) new cMenu(this);
			m_nowScene = E_SCENE_MENU;
			break;
		case E_SCENE_STAGESELECT:
			m_scene = (cBaseScene*) new cStageSelect(this);
			m_nowScene = E_SCENE_STAGESELECT;
			break;
		case E_SCENE_UNITSELECT:
			m_scene = (cBaseScene*) new cUnitSelect(this);
			m_nowScene = E_SCENE_UNITSELECT;
			break;
		case E_SCENE_GAME:
			m_scene = (cBaseScene*) new cGameMgr(this);
			m_nowScene = E_SCENE_GAME;
			break;
		case E_SCENE_RESULT:
			m_scene = (cBaseScene*) new cResult(this);
			m_nowScene = E_SCENE_RESULT;
			break;
		}

		m_nextScene = E_SCENE_NONE;		//���̃V�[�����̃N���A
		m_scene->Init();
	}

	//�X�V����
	if (isPose == FALSE) {
		m_scene->Update();
	}
	else {
		m_setting.Update();

		if (m_nowScene == E_SCENE_GAME) {
			m_poseCount++;
		}
	}
}

void cSceneMgr::Draw() {
	//�`�揈��
	m_scene->Draw();
	
	if (isPose == TRUE) {
		m_setting.Draw();
	}
}

void cSceneMgr::End() {
	m_scene->End();
}

void cSceneMgr::ChangeScene(eScene _nextScene) {
	m_nextScene = _nextScene;	// ���̃V�[�����Z�b�g����
}

void cSceneMgr::SettingStart() {
	m_setting.StartSetting();
	isPose = TRUE;
}

int cSceneMgr::Get_PoseCount() {
	return m_poseCount;
}