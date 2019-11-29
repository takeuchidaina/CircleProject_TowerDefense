#include "Result.h"

cResult::cResult(ISceneChanger* _scene) : cBaseScene(_scene) {
	Init();
}

void cResult::Init() {
	m_image = { 920,600,1220,700,"../resource/img/TitleEndButton.png" };
	m_image.handle = LoadGraph(m_image.filePath.c_str());
	FileCheck(m_image.handle);

	m_btn.Init(m_image.ux, m_image.uy,m_image.dx, m_image.dy,m_image.filePath.c_str());

	FILE* fp;

	errno_t err; // errno_t型(int型)
	err = fopen_s(&fp, "../result.txt", "r"); // ファイルを開く。失敗するとエラーコードを返す。
	if (err != 0) {

	}

	char result[256];
	if (fgets(result, 256, fp) != NULL){
		if (result[0] == 'w') {
			m_BG = LoadGraph("../resource/img/seikou.png");
		}
		else {
			m_BG = LoadGraph("../resource/img/sippai.png");
		}
	}

	fclose(fp);
}

void cResult::Update() {

	//クリックされたらボタンの上か判断
	if (MOUSE_PRESS(LEFT_CLICK) == 1) {
		if (m_btn.ButtonClick() == TRUE) {
			cSound::Instance()->PlaySE(cSound::Instance()->E_SE_CANSEL);
			WaitTimer(200);
			m_sceneChanger->ChangeScene(E_SCENE_TITLE);
		}
	}
	
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

	DrawGraph(0, -130,m_BG,FALSE);
	m_btn.Draw();
#ifdef RESULT_DEBUG
	DrawFormatString(500, 400, RD, "GAME CLEAR");
	DrawFormatString(0, 0, WH, "リザルト画面");
#endif // RESULT_DEBUG

}

void cResult::End() {
	DeleteGraph(m_image.handle);
}