#include "StageSelect.h"

cStageSelect::cStageSelect(ISceneChanger* _scene) : cBaseScene(_scene) {
	Init();
}

void cStageSelect::Init() {

}

void cStageSelect::Update() {

}

void cStageSelect::Draw() {
	DrawFormatString(0, 0, RD, "SS");
}

void cStageSelect::End() {

}