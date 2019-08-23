#include "Title.h"

cTitle::cTitle(ISceneChanger* _scene) : cBaseScene(_scene) {
	cTitle::Init();
}

void cTitle::Init() {
}

void cTitle::Update() {

#ifdef TITLE_DEBUG

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

#endif // TITLE_DEBUG

}

void cTitle::Draw() {

	cBaseScene::Draw();

#ifdef TITLE_DEBUG
	DrawFormatString(0, 0, WH, "タイトル画面");
#endif // TITLE_DEBUG

}

void cTitle::End() {

}