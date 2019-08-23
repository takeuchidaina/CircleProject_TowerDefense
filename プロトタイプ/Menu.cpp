#include "Menu.h"

cMenu::cMenu(ISceneChanger* _scene) : cBaseScene(_scene) {
	cMenu::Init();
}

void cMenu::Init() {

}

void cMenu::Update() {

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

}

void cMenu::Draw() {

	cBaseScene::Draw();

#ifdef MENU_DEBUG
	DrawFormatString(0, 0, WH, "メニュー画面");
#endif // MENU_DEBUG

}

void cMenu::End() {

}