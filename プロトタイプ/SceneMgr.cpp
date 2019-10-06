#include "SceneMgr.h"

cSceneMgr::cSceneMgr() : m_nextScene(E_SCENE_NONE){

	//m_scene = (cBaseScene*) new cGameMgr(this);
	m_scene = (cBaseScene*) new cTitle(this);

}

void cSceneMgr::Init() {
	m_scene->Init();
}

void cSceneMgr::Update() {

	// 次のシーンがセットされていたら
	if (m_nextScene != E_SCENE_NONE) {
		m_scene->End();
		delete m_scene;

		// シーンによって処理を分岐
		switch (m_nextScene){

		case E_SCENE_TITLE:
			m_scene = (cBaseScene*) new cTitle(this);
			break;
		case E_SCENE_MENU:
			m_scene = (cBaseScene*) new cMenu(this);
			break;
		case E_SCENE_GAME:
			m_scene = (cBaseScene*) new cGameMgr(this);
			break;
		case E_SCENE_RESULT:
			m_scene = (cBaseScene*) new cResult(this);
			break;
		case E_SCENE_END:
			DxLib_End();
			break;
		}

		m_nextScene = E_SCENE_NONE;		// 次のシーン情報のクリア
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
	m_nextScene = _nextScene;	// 次のシーンをセットする
}