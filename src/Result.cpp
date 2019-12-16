#include "Result.h"

cResult::cResult(ISceneChanger* _scene) : cBaseScene(_scene) {
	Init();
}

void cResult::Init() {

	//タイトルバックのボタン
	m_image = {/*左上y*/600,/*左上x*/880,/*右下x*/1180,/*右下y*/700,"../resource/img/TitleEndButton.png" };
	m_image.handle = LoadGraph(m_image.filePath.c_str());
	FileCheck(m_image.handle);
	m_btn.Init(m_image.rect,m_image.filePath.c_str());

	//勝敗結果をファイルから読み取る
	FILE* fp;
	errno_t err; // errno_t型(int型)
	err = fopen_s(&fp, "../result.txt", "r"); // ファイルを開く。失敗するとエラーコードを返す。
	if (err != 0) {
		DEBUG_LOG("file not open");
	}

	char result[256];

	//勝敗結果に応じて表示する画像を変更
	if (fgets(result, 256, fp) != NULL) {
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

			//キャンセル音
			cSound::Instance()->PlaySE(cSound::Instance()->E_SE_CANSEL);

			//SEが鳴り終わるのを待つ
			WaitTimer(200);			

			//タイトルへ
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

	//背景描画
	DrawGraph(0, /*Y座標調節*/ -130,m_BG,FALSE);

	//ボタン描画
	m_btn.Draw();

}

void cResult::End() {
	DeleteGraph(m_image.handle);	//画像削除
}