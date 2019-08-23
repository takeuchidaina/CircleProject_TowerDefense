#include "Result.h"

cResult::cResult(ISceneChanger* _scene) : cBaseScene(_scene) {
	cResult::Init();
}

void cResult::Init() {
}

void cResult::Update() {

#ifdef RESULT_DEBUG

	//タイトルへ
	if (GET_KEY_PRESS(KEY_INPUT_T)) {
		sceneChanger->ChangeScene(E_SCENE_TITLE);
	}
	//メニューへ
	if (GET_KEY_PRESS(KEY_INPUT_M)) {
		sceneChanger->ChangeScene(E_SCENE_MENU);
	}
	//ゲームへ
	if (GET_KEY_PRESS(KEY_INPUT_G)) {
		sceneChanger->ChangeScene(E_SCENE_GAME);
	}
	//リザルトへ
	if (GET_KEY_PRESS(KEY_INPUT_R)) {
		sceneChanger->ChangeScene(E_SCENE_RESULT);
	}

#endif // RESULT_DEBUG

}

void cResult::Draw() {

	cBaseScene::Draw();

#ifdef RESULT_DEBUG
	DrawFormatString(0, 0, WH, "リザルト画面");
#endif // RESULT_DEBUG

}

void cResult::End() {

}