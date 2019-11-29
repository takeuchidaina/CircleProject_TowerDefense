#include "Menu.h"

cMenu::cMenu(ISceneChanger* _scene) : cBaseScene(_scene) {
}

void cMenu::Init() {

}

void cMenu::Update() {

#ifdef MENU_DEBUG

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

#endif // MENU_DEBUG

}

void cMenu::Draw() {

	cBaseScene::Draw();

#ifdef MENU_DEBUG
	DrawFormatString(0, 0, WH, "メニュー画面");
#endif // MENU_DEBUG

}

void cMenu::End() {

}