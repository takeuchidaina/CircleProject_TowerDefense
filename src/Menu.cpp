#include "Menu.h"

cMenu::cMenu(ISceneChanger* _scene) : cBaseScene(_scene) {
}

void cMenu::Init() {
	m_stageSelect = 0;
}

void cMenu::Update() {

	if (GET_KEY_PRESS(KEY_INPUT_UP) == 1) {
		m_stageSelect++;
	}
	if (GET_KEY_PRESS(KEY_INPUT_DOWN) == 1) {
		m_stageSelect--;
	}
	if (m_stageSelect < 1) {
		m_stageSelect = 1;
	}

	if (GET_KEY_PRESS(KEY_INPUT_RETURN) == 1) {
		
		FILE* fp;

		errno_t err; // errno_t型(int型)
		err = fopen_s(&fp, "../StageSelect.txt", "w"); // ファイルを開く。失敗するとエラーコードを返す。
		if (err != 0) {
			DEBUG_LOG("file not open");
		}
		fprintf(fp,"%d",m_stageSelect);

		fclose(fp);

		m_sceneChanger->ChangeScene(E_SCENE_GAME);
	}
		

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

	DrawFormatString(400,400,WH,"上下矢印でステージ数を選択");
	DrawFormatString(400, 420, WH, "ステージ番号：%d",m_stageSelect);
	DrawFormatString(400, 440, WH, "エンターでステージ決定");

#ifdef MENU_DEBUG
	DrawFormatString(0, 0, WH, "メニュー画面");
#endif // MENU_DEBUG

}

void cMenu::End() {

}