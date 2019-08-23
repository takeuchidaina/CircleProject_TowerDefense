#include "Menu.h"

cMenu::cMenu(ISceneChanger* _scene) : cBaseScene(_scene) {
	cMenu::Init();
}

void cMenu::Init() {

}

void cMenu::Update() {

	//�^�C�g����
	if (GET_KEY_PRESS(KEY_INPUT_T)) {
		sceneChanger->ChangeScene(E_SCENE_TITLE);
	}
	//���j���[��
	if (GET_KEY_PRESS(KEY_INPUT_M)) {
		sceneChanger->ChangeScene(E_SCENE_MENU);
	}
	//�Q�[����
	if (GET_KEY_PRESS(KEY_INPUT_G)) {
		sceneChanger->ChangeScene(E_SCENE_GAME);
	}
	//���U���g��
	if (GET_KEY_PRESS(KEY_INPUT_R)) {
		sceneChanger->ChangeScene(E_SCENE_RESULT);
	}

}

void cMenu::Draw() {

	cBaseScene::Draw();

#ifdef MENU_DEBUG
	DrawFormatString(0, 0, WH, "���j���[���");
#endif // MENU_DEBUG

}

void cMenu::End() {

}