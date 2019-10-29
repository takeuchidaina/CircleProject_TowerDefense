#include "GameMgr.h"

cGameMgr::cGameMgr(ISceneChanger* _scene) : cBaseScene(_scene) {
	Init();
}

void cGameMgr::Init() {
	cTime* ptime = new cTime(TIME_LIMIT);
	m_time = *ptime;
	m_img = LoadGraph("../resource/img/GameBG.png");
}

void cGameMgr::Update() {
	m_fps.Update();
	m_mapMgr.Update();
	m_PUnit.Update();

	m_EUnit.Update();
	m_escort.Update();
	m_camera.Update();
	m_time.Update();
  
  PUnitGenerate();
	EUnitGenerate();

#ifdef GAMEMGR_DEBUG
	if (GET_KEY_PRESS(KEY_INPUT_E) == 1) {
		EscortDamageCalc(50);
	}
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
	DrawBillboard3D(VGet(0.0f, 0.0f, 0.0f), 0.5, 0.5, 1280, 0, m_img, FALSE);

	m_fps.Draw();
    m_mapMgr.Draw();
	m_PUnit.Draw();
	m_escort.Draw();
	m_camera.Draw();
	m_time.Draw();
    m_EUnit.Draw();

#ifdef GAMEMGR_DEBUG
	DrawFormatString(0, 0, WH, "ゲーム画面");
	//DrawBox(100,100,600,600,GR,TRUE);
#endif // GAMEMGR_DEBUG


}

void cGameMgr::End() {
}

void cGameMgr::EscortDamageCalc(int _damage) {
	//HPが無くなったらリザルトへ
	if (m_escort.DamageCalc(_damage) == false) {
		//resultDefSuccess = false;
		m_sceneChanger->ChangeScene(E_SCENE_RESULT);
	}
}

void cGameMgr::DefSuccessJudge() {
	if (m_time.GetSecond() < 0) {
		//resultDefSuccess = true;
		m_sceneChanger->ChangeScene(E_SCENE_RESULT);
	}
}

void cGameMgr::PUnitGenerate() {

	if (MOUSE_PRESS(LEFT_CLICK) == 1 && CheckHitKey(KEY_INPUT_S) >= 1)
	{
		int tmp = m_mapMgr.CheckInto(MOUSE_V.x, MOUSE_V.y);
		if (tmp != -1)
		{
			//m_PUnit.Add_PSord(MOUSE_V.x, m_mapMgr.Get_Ground(tmp) + UNIT_HEIGHT / 2, tmp);
			m_PUnit.Add_PSord(MOUSE_V.x, m_mapMgr.Get_Ground(tmp) + UNIT_HEIGHT / 2);
			DEBUG_LOG("剣出現");
		}
	}
	else if (MOUSE_PRESS(LEFT_CLICK) == 1 && CheckHitKey(KEY_INPUT_A) >= 1)
	{
		int tmp = m_mapMgr.CheckInto(MOUSE_V.x, MOUSE_V.y);
		if (tmp != -1)
		{
			//m_PUnit.Add_PArcher(MOUSE_V.x, m_mapMgr.Get_Ground(tmp) + UNIT_HEIGHT / 2, tmp);
			m_PUnit.Add_PArcher(MOUSE_V.x, m_mapMgr.Get_Ground(tmp) + UNIT_HEIGHT / 2);
		}
	}
	else if (MOUSE_PRESS(LEFT_CLICK) == 1 && cMouse::Instance()->GetPlayerNum() >= 0 && CheckHitKeyAll != 0)
	{
		int tmp = m_mapMgr.CheckInto(MOUSE_V.x, MOUSE_V.y);
		if (tmp != -1)
		{
			m_PUnit.Set_NextPlayerPos(cMouse::Instance()->GetPlayerNum(), tmp, MOUSE_V.x);
			cMouse::Instance()->SetPlayerNum(-1);
		}
	}
	else if (MOUSE_PRESS(LEFT_CLICK) == 1)
	{
		int tmp = 0;

		tmp = m_PUnit.CheckPlayerClick(MOUSE_V);
		if (0 <= tmp)
		{
			cMouse::Instance()->SetPlayerNum(tmp);
		}
	}
}

void cGameMgr::EUnitGenerate() {

	if (MOUSE_PRESS(RIGHT_CLICK) == 1 && CheckHitKey(KEY_INPUT_S) >= 1)
	{
		int tmp = m_mapMgr.CheckInto(MOUSE_V.x, MOUSE_V.y);
		if (tmp != -1)
		{
			m_EUnit.Add_ESord(MOUSE_V.x, m_mapMgr.Get_Ground(tmp) + UNIT_HEIGHT / 2, tmp);
			DEBUG_LOG("剣エネミー出現");
		}
	}

	if (MOUSE_PRESS(RIGHT_CLICK) == 1 && CheckHitKey(KEY_INPUT_A) >= 1)
	{
		int tmp = m_mapMgr.CheckInto(MOUSE_V.x, MOUSE_V.y);
		if (tmp != -1)
		{
			m_EUnit.Add_EArcher(MOUSE_V.x, m_mapMgr.Get_Ground(tmp) + UNIT_HEIGHT / 2, tmp);
			//enemy.Set_NextEnemyPos(cMouse::Instance()->GetEnemyNum(), tmp, MOUSE_V.x);
			DEBUG_LOG("弓エネミー出現");
		}
	}

	if (MOUSE_PRESS(RIGHT_CLICK) == 1 && cMouse::Instance()->GetEnemyNum() >= 0 && CheckHitKeyAll != 0)
	{
		int tmp = m_mapMgr.CheckInto(MOUSE_V.x, MOUSE_V.y);
		if (tmp != -1)
		{
			m_EUnit.Set_NextEnemyPos(cMouse::Instance()->GetEnemyNum(), tmp, MOUSE_V.x);
			cMouse::Instance()->SetEnemyNum(-1);
		}
	}

	if (MOUSE_PRESS(RIGHT_CLICK) == 1)
	{
		int tmp = 0;
		tmp = m_EUnit.CheckEnemyClick(MOUSE_V);
		if (0 <= tmp)
		{
			cMouse::Instance()->SetEnemyNum(tmp);
		}
		//enemy.Set_NextEnemyPos(eMove);
	}

}