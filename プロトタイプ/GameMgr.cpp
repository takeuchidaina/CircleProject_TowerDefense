#include "GameMgr.h"

cGameMgr::cGameMgr(ISceneChanger* _scene) : cBaseScene(_scene) {
	cGameMgr::Init();
}

void cGameMgr::Init() {
}

void cGameMgr::Update() {
	fps.Update();

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

void cGameMgr::Draw() {

	cBaseScene::Draw();
	fps.Draw();

#ifdef GAMEMGR_DEBUG
	DrawFormatString(0, 0, WH, "�Q�[�����");
#endif // GAMEMGR_DEBUG

}

void cGameMgr::End() {

}