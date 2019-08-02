#include "GameMgr.h"

cGameMgr::cGameMgr(ISceneChanger* _scene) : cBaseScene(_scene) {
	cGameMgr::Init();
}

void cGameMgr::Init() {
}

void cGameMgr::Update() {
	fps.Update();
}

void cGameMgr::Draw() {

	cBaseScene::Draw();
	fps.Draw();

#ifdef GAMEMGR_DEBUG
	DrawFormatString(0, 0, WH, "ÉQÅ[ÉÄâÊñ ");
#endif // GAMEMGR_DEBUG

}

void cGameMgr::End() {

}