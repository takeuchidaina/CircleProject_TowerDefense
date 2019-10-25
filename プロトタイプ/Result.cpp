#include "Result.h"

cResult::cResult(ISceneChanger* _scene) : cBaseScene(_scene) {
	Init();
}

void cResult::Init() {
}

void cResult::Update() {
	DrawFormatString(0, 0, RD, "GAME CLEAR");

#ifdef RESULT_DEBUG

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

#endif // RESULT_DEBUG

}

void cResult::Draw() {

	DrawFormatString(500, 400, RD, "GAME CLEAR");
#ifdef RESULT_DEBUG
	DrawFormatString(0, 0, WH, "リザルト画面");
#endif // RESULT_DEBUG

}

void cResult::End() {

}