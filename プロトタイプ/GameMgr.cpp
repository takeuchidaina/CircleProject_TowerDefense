#include "GameMgr.h"

cGameMgr::cGameMgr(ISceneChanger* _scene) : cBaseScene(_scene) {
}

void cGameMgr::Init() {
}

void cGameMgr::Update() {
	m_fps.Update();
	m_camera.Update();
	

#ifdef GAMEMGR_DEBUG

	//タイトルへ
	if (GET_KEY_PRESS(KEY_INPUT_T) == 1) {
		m_sceneChanger->ChangeScene(E_SCENE_TITLE);
	}
	//メニューへ
	if (GET_KEY_PRESS(KEY_INPUT_M) == 1) {
		m_sceneChanger->ChangeScene(E_SCENE_MENU);
	}
	//ゲームへ
	if (GET_KEY_PRESS(KEY_INPUT_G) == 1) {
		m_sceneChanger->ChangeScene(E_SCENE_GAME);
	}
	//リザルトへ
	if (GET_KEY_PRESS(KEY_INPUT_R) == 1) {
		m_sceneChanger->ChangeScene(E_SCENE_RESULT);
	}

#endif // GAMEMGR_DEBUG

}

void cGameMgr::Draw() {

	cBaseScene::Draw();
	m_fps.Draw();

#ifdef GAMEMGR_DEBUG
	DrawFormatString(0, 0, WH, "ゲーム画面");
	//DrawBox(100,100,600,600,GR,TRUE);
#endif // GAMEMGR_DEBUG

	m_camera.Draw();

}

void cGameMgr::End() {

}