#include "GameMgr.h"

cGameMgr::cGameMgr(ISceneChanger* _scene) : cBaseScene(_scene) {
	//cMap *map = new cMap(100, 200, 800 / 2, 450 / 2, 1);
	//m_map = *map;
	//delete(map);
}

void cGameMgr::Init() {
}

void cGameMgr::Update() {
	m_fps.Update();
	m_camera.Update();
	m_map.Update();
	m_PUnit.Update();
	
	PUnitGenerate();
#ifdef GAMEMGR_DEBUG

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

#endif // GAMEMGR_DEBUG

}

void cGameMgr::Draw() {

	cBaseScene::Draw();
	m_fps.Draw();

#ifdef GAMEMGR_DEBUG
	DrawFormatString(0, 0, WH, "ゲーム画面");
	//DrawBox(100,100,600,600,GR,TRUE);
#endif // GAMEMGR_DEBUG

	m_camera.Draw();
	m_map.Draw();
	m_PUnit.Draw();
	
}

void cGameMgr::End() {
}

void cGameMgr::PUnitGenerate() {
	if (MOUSE_PRESS(LEFT_CLICK) == 1 && CheckHitKey(KEY_INPUT_S) >= 1)
	{
		if (-1 != m_map.CheckInto(MOUSE_V.x, MOUSE_V.y))
		{
			m_PUnit.Add_PSord(MOUSE_V.x, m_map.Get_Ground() + UNIT_HEIGHT / 2);
		}
	}
	if (MOUSE_PRESS(LEFT_CLICK) == 1 && CheckHitKey(KEY_INPUT_A) >= 1)
	{
		if (-1 != m_map.CheckInto(MOUSE_V.x, MOUSE_V.y))
		{
			m_PUnit.Add_PArcher(MOUSE_V.x, m_map.Get_Ground() + UNIT_HEIGHT / 2);

		}
	}
	if (MOUSE_PRESS(LEFT_CLICK) == 1 && cMouse::Instance()->GetPlayerNum() >= 0 && CheckHitKeyAll != 0)
	{
		int tmp = m_map.CheckInto(MOUSE_V.x, MOUSE_V.y);
		if (tmp != -1)
		{
			m_PUnit.Set_NextPlayerPos(cMouse::Instance()->GetPlayerNum(), tmp, MOUSE_V.x);
			cMouse::Instance()->SetPlayerNum(-1);
		}
	}

	if (MOUSE_PRESS(LEFT_CLICK) == 1)
	{
		int tmp = 0;

		tmp = m_PUnit.CheckPlayerClick(MOUSE_V);
		if (0 <= tmp)
		{
			cMouse::Instance()->SetPlayerNum(tmp);
		}
	}
}