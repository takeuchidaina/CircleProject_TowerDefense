#include "Result.h"

cResult::cResult(ISceneChanger* _scene) : cBaseScene(_scene) {
	
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
			cSound::Instance()->PlaySE(cSound::Instance()->E_SE_WIN);
			
			m_result = TRUE;
		}
		else {
			m_BG = LoadGraph("../resource/img/sippai.png");
			cSound::Instance()->PlaySE(cSound::Instance()->E_SE_LOSE);
			
			m_result = FALSE;
		}
	}

	fclose(fp);

	m_sound = FALSE;

}

void cResult::Update() {

	//クリックされたらボタンの上か判断
	if (MOUSE_PRESS(LEFT_CLICK) == 1) {
		if (m_btn.ButtonClick() == TRUE) {

			//キャンセル音
			cSound::Instance()->PlaySE(cSound::Instance()->E_SE_CANSEL, cSound::Instance()->E_PLAY_NORMAL);		

			//タイトルへ
			m_sceneChanger->ChangeScene(E_SCENE_TITLE);		
		}
	}

	//MEが鳴り終わった後にBGMをループ再生(1回のみ)
	if (m_sound == FALSE) {
		if (m_result == TRUE && cSound::Instance()->CheckSound(cSound::Instance()->E_SE_WIN) == FALSE) {
			cSound::Instance()->PlayBGM(cSound::Instance()->E_BGM_WIN);
			m_sound = TRUE;
		}
		else if (m_result == FALSE && cSound::Instance()->CheckSound(cSound::Instance()->E_SE_LOSE) == FALSE) {
			cSound::Instance()->PlayBGM(cSound::Instance()->E_BGM_LOSE);
			m_sound = TRUE;
		}
	}
}

void cResult::Draw() {

	//背景描画
	DrawGraph(0, /*Y座標調節*/ -130,m_BG,FALSE);

	//ボタン描画
	m_btn.Draw();

}

void cResult::End() {
	DeleteGraph(m_image.handle);	//画像削除

	if (m_result == TRUE) {
		if (cSound::Instance()->CheckSound(cSound::Instance()->E_SE_WIN) == TRUE) {
			cSound::Instance()->StopSound(cSound::Instance()->E_SE_WIN);
		}
		if (m_sound == TRUE) {
			cSound::Instance()->StopSound(cSound::Instance()->E_BGM_WIN);
		}
	}
	else {
		if (cSound::Instance()->CheckSound(cSound::Instance()->E_SE_LOSE) == TRUE) {
			cSound::Instance()->StopSound(cSound::Instance()->E_SE_LOSE);
		}
		if (m_sound == TRUE) {
			cSound::Instance()->StopSound(cSound::Instance()->E_BGM_LOSE);
		}
	}
}