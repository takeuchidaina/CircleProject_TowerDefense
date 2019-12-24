#include "SceneMgr.h"

cSceneMgr::cSceneMgr() : m_nextScene(E_SCENE_NONE){

	//m_scene = (cBaseScene*) new cGameMgr(this);
	m_scene = (cBaseScene*) new cTitle(this);
	//m_scene = (cBaseScene*) new cStageSelect(this);
	//m_scene = (cBaseScene*) new cUnitSelect(this);
}

void cSceneMgr::Init() {
	m_scene->Init();
}

void cSceneMgr::Update() {

	//設定が終了したら
	if (m_setting.GetEndSetting() == TRUE) {
		isPose = FALSE;
	}

	if (GET_KEY_PRESS(KEY_INPUT_ESCAPE) == 1) {
		isPose = TRUE;
	}


	// 次のシーンがセットされているなら次のシーンに変更する
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

		m_nextScene = E_SCENE_NONE;		//次のシーン情報のクリア
		m_scene->Init();
	}

	//更新処理
	if (isPose == FALSE) {
		m_scene->Update();
	}
	else {
		m_setting.Update();
	}
}

void cSceneMgr::Draw() {
	//描画処理
	m_scene->Draw();
	
	if (isPose == TRUE) {
		m_setting.Draw();
	}
}

void cSceneMgr::End() {
	m_scene->End();
}

void cSceneMgr::ChangeScene(eScene _nextScene) {
	m_nextScene = _nextScene;	// 次のシーンをセットする
}

void cSceneMgr::SettingStart() {
	isPose = TRUE;
}