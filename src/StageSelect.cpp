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
	if (MOUSE_PRESS(LEFT_CLICK) == 1) {
		//選択ステージ情報の受け渡し
		//シーン移行
	}
}

void cStageSelect::Draw() {
	for (int i = 0; i < stageButton.size(); i++) {
		stageButton[i].Draw();
	}
}

void cStageSelect::End() {

}