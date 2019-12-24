#include "StageSelect.h"

cStageSelect::cStageSelect(ISceneChanger* _scene) : cBaseScene(_scene) {
}

void cStageSelect::Init() {
	stageButton.resize(STAGE_NUM);
	sRECT tmpRect;
	const char* stageStr = "stage";
		;
	for (int i = 0; i < stageButton.size(); i++) {

		tmpRect.left = LEFT_MARGIN + (BUTTON_WIDTH + BUTTON_MARGIN) * i;
		tmpRect.top = TOP_MARGIN;
		tmpRect.right = tmpRect.left + BUTTON_WIDTH;
		tmpRect.bottom = TOP_MARGIN + BUTTON_HEIGHT;

		//cButton Init(sRECT _rect, short _transNum, const char* _text, short _fontSize);
		stageButton[i].Init(tmpRect, 255, stageStr, 30);
	}
}

void cStageSelect::Update() {

	//選択ステージ情報の受け渡し
	//シーン移行

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

				m_sceneChanger->ChangeScene((eScene)E_SCENE_UNITSELECT);

			}
		}
	}
}

void cStageSelect::Draw() {
	for (int i = 0; i < stageButton.size(); i++) {
		stageButton[i].Draw();
	}
}

void cStageSelect::End() {

}