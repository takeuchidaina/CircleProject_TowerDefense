#include "StageSelect.h"

cStageSelect::cStageSelect(ISceneChanger* _scene) : cBaseScene(_scene) {
}

void cStageSelect::Init() {

	for (int i = 1; i <= STAGE_NUM;i++) {
		
		m_stageUI.emplace_back(100 + (i-1) * 200, 200, i);
	}

	stageButton.resize(m_stageUI.size());
	sRECT tmpRect;
	m_imgBacGround = LoadGraph("../resource/img/SelectScene_BG.jpg");
	FileCheck(m_imgBacGround, 0015);
	const char* stageStr = "stage";
		;
	for (int i = 0; i < stageButton.size(); i++) {

		tmpRect.left = m_stageUI[i].Get_Pos().x;
		tmpRect.top = m_stageUI[i].Get_Pos().y;
		tmpRect.right = tmpRect.left + m_stageUI[i].Get_Pos().w;
		tmpRect.bottom = tmpRect.top + m_stageUI[i].Get_Pos().h;

		//cButton Init(sRECT _rect, short _transNum, const char* _text, short _fontSize);
		stageButton[i].Init(tmpRect, 255, "", 30);
	}

	cSound::Instance()->PlayBGM(cSound::Instance()->E_BGM_TITLE, cSound::Instance()->E_PLAY_LOOP, FALSE);
	cSound::Instance()->PlayEVM(cSound::Instance()->E_EVM_SEA_ROUGH, cSound::Instance()->E_PLAY_LOOP, TRUE);
}

void cStageSelect::Update() {

	//選択ステージ情報の受け渡し
	//シーン移行

	for (int i = 0; i < m_stageUI.size(); i++)
	{
		m_stageUI[i].Update();
	}

	if (MOUSE_PRESS(LEFT_CLICK) == 1) {
		for (int i = 0; i < stageButton.size(); i++) {
			if (stageButton[i].ButtonClick() == true) {
				FILE* fp;

				errno_t err; // errno_t型(int型)
				err = fopen_s(&fp, "../StageSelect.txt", "w"); // ファイルを開く。失敗するとエラーコードを返す。
				if (err != 0) {
					DEBUG_LOG("file not open");
				}

				fprintf(fp, "%d", i+1);

				fclose(fp);

				cSound::Instance()->PlaySE(cSound::Instance()->E_SE_SELECT);
				m_sceneChanger->ChangeScene((eScene)E_SCENE_UNITSELECT);

			}
		}
	}
}

void cStageSelect::Draw() {
	DrawGraph(0, 0, m_imgBacGround, FALSE);
	/*for (int i = 0; i < stageButton.size(); i++) {
		stageButton[i].Draw();
	}*/

	SetFontSize(64);
	DrawFormatString(20, 20, BK, "Stage Select");

	for (int i = 0; i < m_stageUI.size(); i++)
	{
		m_stageUI[i].Draw();
	}
}

void cStageSelect::End() {
	cSound::Instance()->StopSound(cSound::Instance()->E_BGM_TITLE);		//BGMを止める
	cSound::Instance()->StopSound(cSound::Instance()->E_EVM_SEA_ROUGH);
}