#include "Result.h"

cResult::cResult(ISceneChanger* _scene) : cBaseScene(_scene) {
	Init();
}

void cResult::Init() {
	FILE* fp;

	errno_t err; // errno_t型(int型)
	err = fopen_s(&fp, "../result.txt", "r"); // ファイルを開く。失敗するとエラーコードを返す。
	if (err != 0) {

	}

	char result[256];
	if (fgets(result, 256, fp) != NULL){
		if (result[0] == 'w') {
			m_image = LoadGraph("../resource/img/seikou.png");
		}
		else {
			m_image = LoadGraph("../resource/img/sippai.png");
		}
	}

	fclose(fp);
}

void cResult::Update() {
	
#ifdef RESULT_DEBUG
	DrawFormatString(0, 0, RD, "GAME CLEAR");
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

	DrawGraph(0, -130,m_image,FALSE);
#ifdef RESULT_DEBUG
	DrawFormatString(500, 400, RD, "GAME CLEAR");
	DrawFormatString(0, 0, WH, "リザルト画面");
#endif // RESULT_DEBUG

}

void cResult::End() {
	DeleteGraph(m_image);
}