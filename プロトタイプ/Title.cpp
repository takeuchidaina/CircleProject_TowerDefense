#include "Title.h"

cTitle::cTitle(ISceneChanger* _scene) : cBaseScene(_scene) {
	cTitle::Init();
}

void cTitle::Init() {

	// x,y,eMenu,name
	m_menu[E_MENU_GAME] = { 300,300,E_MENU_GAME,"ゲーム開始" },
	m_menu[E_MENU_END] = { 300,300,E_MENU_END,"ゲーム終了"};

	nowSelect = E_MENU_GAME;
}

void cTitle::Update() {
	
	if (GET_KEY_PRESS(KEY_INPUT_DOWN) == 1) {
		nowSelect++;

		//if (nowSelect > menuNum) {
		//	nowSelect = 0;
		//}
	}


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

	for (int i = 0; i < menuNum; i++) {
		//DrawFormatString(m_menu[i].x,m_menu[i].y,WH,m_menu[i].text);
		//DrawFormatString(m_menu[nowSelect].x - 20, m_menu[nowSelect].y, WH, "→");
	}
	
	

#ifdef TITLE_DEBUG
	DrawFormatString(0, 0, WH, "タイトル画面");
	DrawFormatString(0, 20, WH, "nowSelect:%d",nowSelect);
#endif // TITLE_DEBUG

}

void cTitle::End() {

}