#include "GameMgr.h"

cGameMgr::cGameMgr(ISceneChanger* _scene) : cBaseScene(_scene) {
	Init();
}

void cGameMgr::Init() {
	//時間
	cTime* ptime = new cTime(TIME_LIMIT);
	m_time = *ptime;

	//画像
	m_wave = LoadGraph("../resource/img/wave.png");
	FileCheck(m_wave);
	m_BG = LoadGraph("../resource/img/Sea.jpg");
	FileCheck(m_BG);
	m_ship = LoadGraph("../resource/img/Ship.png");
	FileCheck(m_ship);
	m_cloud[0].pos = VGet(0.0f, 0.0f, 0.0f);
	m_cloud[0].image = LoadGraph("../resource/img/BG_Cloud.png");
	FileCheck(m_cloud[0].image);
	m_cloud[1].pos = VGet(-1870.0f, 0.0f, 0.0f);
	m_cloud[1].image = LoadGraph("../resource/img/BG_Cloud.png");
	FileCheck(m_cloud[1].image);

	m_unitMgr.Set_MapData(m_mapMgr.GetMapData());

	//BGM
	cSound::Instance()->StopSound(cSound::Instance()->E_BGM_TITLE);
	cSound::Instance()->PlayBGM(
		cSound::Instance()->E_BGM_BATTLE, cSound::Instance()->E_PLAY_LOOP, FALSE);
	cSound::Instance()->PlayBGM(
		cSound::Instance()->E_BGM_SEA, cSound::Instance()->E_PLAY_LOOP, TRUE);

	m_maxPlayer = 15;
	m_PlayerCnt = 0;

	m_gameState = E_BATTLE;
}

void cGameMgr::Update() {

	switch (m_gameState)
	{
	case E_PREPARATION:
		m_unitMgr.Update();
		break;

	case E_BATTLE:
		UnitGenerate();		//ユニット生成
		DefSuccessJudge();
		m_unitMgr.Update();
		EscortDamageCalc();
		m_time.Update();
		break;

	case E_EVENT:
		break;

	case E_CUTSCENE:
		break;

	case E_POSE:
		//ゲームに戻る
		//設定
		m_setting.Update();
		//ゲームを終了
		break;
	}

	m_fps.Update();
	m_mapMgr.Update();
	
	m_camera.Update();
	
	m_UI.Update();
	MoveBackGround();

	m_spawnCnt++;			// 一定数まで行ったらスポーン
	m_spawnType = GetRand(2);	// スポーンするタイプを決めるランダム

#ifdef GAMEMGR_DEBUG
	if (GET_KEY_PRESS(KEY_INPUT_ESCAPE) == 1 && m_gameState != E_POSE) {m_gameState = E_POSE;}
	if (GET_KEY_PRESS(KEY_INPUT_B) == 1 && m_gameState != E_BATTLE) {m_gameState = E_BATTLE;}

	//タイトルへ
	if (GET_KEY_PRESS(KEY_INPUT_T) == 1) {m_sceneChanger->ChangeScene(E_SCENE_TITLE);}
	//メニューへ
	if (GET_KEY_PRESS(KEY_INPUT_M) == 1) {m_sceneChanger->ChangeScene(E_SCENE_MENU);}
	//ゲームへ
	if (GET_KEY_PRESS(KEY_INPUT_G) == 1) {m_sceneChanger->ChangeScene(E_SCENE_GAME);}
	//リザルトへ
	if (GET_KEY_PRESS(KEY_INPUT_R) == 1) {m_sceneChanger->ChangeScene(E_SCENE_RESULT);}

#endif // GAMEMGR_DEBUG

}

void cGameMgr::Draw() {

	DrawBillboard3D(VGet(0.0f, 0.0f, 0.0f), 0.5, 0.5, 1280, 0, m_BG, TRUE);				//背景
	DrawBillboard3D(VGet(m_cloud[0].pos.x, m_cloud[0].pos.y, m_cloud[0].pos.z),
		0.5, 0.5, 1903, 0, m_cloud[0].image, TRUE);		//雲(初期画面内)
	DrawBillboard3D(VGet(m_cloud[1].pos.x, m_cloud[1].pos.y, m_cloud[1].pos.z),
		0.5, 0.5, 1903, 0, m_cloud[1].image, TRUE);		//雲(後続)
	DrawBillboard3D(VGet(0.0f, 0.0f, 0.0f), 0.5, 0.5, 1280, 0, m_ship, TRUE);			//船
	DrawBillboard3D(VGet(-10.0f, -20.0f, 0.0f), 0.5, 0.5, 1280, 0, m_wave, TRUE);		//波

	m_fps.Draw();
	m_mapMgr.Draw();
	m_unitMgr.Draw();
	m_camera.Draw();

	UnitData();
	m_UI.Draw();

	switch (m_gameState)
	{
	case E_PREPARATION:
		break;

	case E_BATTLE:
		m_time.Draw();
		break;

	case E_EVENT:
		break;

	case E_CUTSCENE:
		break;

	case E_POSE:
		//ゲームに戻る
		//設定
		m_setting.Draw();
		//ゲームを終了する
		break;
	}



}

void cGameMgr::End() {
}

void cGameMgr::ResultSave(bool _result) {
	FILE* fp;

	errno_t err; // errno_t型(int型)
	err = fopen_s(&fp, "../result.txt", "w"); // ファイルを開く。失敗するとエラーコードを返す。
	if (err != 0) {
		DEBUG_LOG("file not open");
	}

	if (_result == TRUE) {
		fprintf(fp, "win");
	}
	else {
		fprintf(fp, "lose");
	}

	fclose(fp);
}
void cGameMgr::EscortDamageCalc() {
	//HPが無くなったらリザルトへ
	if (m_unitMgr.EscortDie() == false) {
		cSound::Instance()->StopSound(cSound::Instance()->E_BGM_BATTLE);
		cSound::Instance()->StopSound(cSound::Instance()->E_BGM_SEA);
		ResultSave(FALSE);
		m_sceneChanger->ChangeScene(E_SCENE_RESULT);
	}
}

void cGameMgr::DefSuccessJudge() {
	if (m_time.GetSecond() <= 1) {
		cSound::Instance()->StopSound(cSound::Instance()->E_BGM_BATTLE);
		cSound::Instance()->StopSound(cSound::Instance()->E_BGM_SEA);
		ResultSave(TRUE);
		m_sceneChanger->ChangeScene(E_SCENE_RESULT);
	}
}

void cGameMgr::MoveBackGround() {
	//移動
	m_cloud[0].pos.x += CLOUD_SPEED;
	m_cloud[1].pos.x += CLOUD_SPEED;
	//画面外処理、スクロール設定
	if (m_cloud[0].pos.x >= 1870.0f) {
		m_cloud[0].pos.x = m_cloud[1].pos.x - 1870.0f;
	}
	else if (m_cloud[1].pos.x >= 1870.0f) {
		m_cloud[1].pos.x = m_cloud[0].pos.x - 1870.0f;
	}
}

void cGameMgr::UnitGenerate() {
	int clickRoom = 0;

	if (MOUSE_PRESS(LEFT_CLICK) == 1 || MOUSE_PRESS(RIGHT_CLICK) == 1) {
		clickRoom = m_mapMgr.CheckInto(MOUSE_V.x, MOUSE_V.y);
	}

	if (m_maxPlayer > m_PlayerCnt){			// コスト制限
		//Player
		if (MOUSE_PRESS(LEFT_CLICK) == 1 && CheckHitKey(KEY_INPUT_S) >= 1){
			if (clickRoom != -1){
				if (m_unitMgr.Add_PSord(MOUSE_V.x, m_mapMgr.Get_Ground(clickRoom) + UNIT_HEIGHT / 2, clickRoom) == 0){
					m_PlayerCnt++;
					m_UI.SetPlayerCount(0);
				}
			}
		}
		else if (MOUSE_PRESS(LEFT_CLICK) == 1 && CheckHitKey(KEY_INPUT_A) >= 1){
			if (clickRoom != -1){
				if (m_unitMgr.Add_PArcher(MOUSE_V.x, m_mapMgr.Get_Ground(clickRoom) + UNIT_HEIGHT / 2, clickRoom) == 0){
					m_PlayerCnt++;
					m_UI.SetPlayerCount(1);
				}
			}
		}
		else if (MOUSE_PRESS(LEFT_CLICK) == 1 && CheckHitKey(KEY_INPUT_D) >= 1){
			if (clickRoom != -1){
				if (m_unitMgr.Add_PDefense(MOUSE_V.x, m_mapMgr.Get_Ground(clickRoom) + UNIT_HEIGHT / 2, clickRoom) == 0){
					m_PlayerCnt++;
					m_UI.SetPlayerCount(2);
				}
			}
		}
	}
	else if (MOUSE_PRESS(LEFT_CLICK) == 1 && cMouse::Instance()->GetPlayerNum() >= 0 && CheckHitKeyAll != 0){
		int clickRoom = m_mapMgr.CheckInto(MOUSE_V.x, MOUSE_V.y);
		if (clickRoom != -1){
			m_unitMgr.Set_NextPlayerPos(cMouse::Instance()->GetPlayerNum(), clickRoom, MOUSE_V.x);
			cMouse::Instance()->SetPlayerNum(-1);
		}
	}
	else if (MOUSE_PRESS(LEFT_CLICK) == 1){
		int selectPlayer = 0;
		clickRoom = m_unitMgr.CheckPlayerClick(MOUSE_V);
		if (0 <= selectPlayer){
			cMouse::Instance()->SetPlayerNum(selectPlayer);
		}
	}

	// Enemyのランダム生成
	if (m_spawnCnt == SPAWN_CNT) {
		switch (m_spawnType) {
		case 0:	m_unitMgr.Add_ESord(m_mapMgr.GetStartRoomNum(), m_mapMgr.Get_Ground(2) + UNIT_HEIGHT / 2);
			m_spawnCnt = 0;
			break;
		case 1:	m_unitMgr.Add_EArcher(m_mapMgr.GetStartRoomNum(), m_mapMgr.Get_Ground(2) + UNIT_HEIGHT / 2);
			m_spawnCnt = 0;
			break;
		case 2:	m_unitMgr.Add_EDefense(m_mapMgr.GetStartRoomNum(), m_mapMgr.Get_Ground(2) + UNIT_HEIGHT / 2);
			m_spawnCnt = 0;
			break;
		}
	}


	/*
	//Enemy		クリック生成 ESord
	if (MOUSE_PRESS(RIGHT_CLICK) == 1 && CheckHitKey(KEY_INPUT_S) >= 1)
	{
		if (clickRoom != -1)
		{
			m_unitMgr.Add_ESord(MOUSE_V.x, m_mapMgr.Get_Ground(clickRoom) + UNIT_HEIGHT / 2, clickRoom);
			//DEBUG_LOG("剣エネミー出現");
		}
	}
	// クリック生成 EArcher
	else if (MOUSE_PRESS(RIGHT_CLICK) == 1 && CheckHitKey(KEY_INPUT_A) >= 1)
	{
		if (clickRoom != -1)
		{
			m_unitMgr.Add_EArcher(MOUSE_V.x, m_mapMgr.Get_Ground(clickRoom) + UNIT_HEIGHT / 2, clickRoom);
			//enemy.Set_NextEnemyPos(cMouse::Instance()->GetEnemyNum(), clickRoom, MOUSE_V.x);
			//DEBUG_LOG("弓エネミー出現");
		}
	}
	// クリック生成 EDefense
	else if (MOUSE_PRESS(RIGHT_CLICK) == 1 && CheckHitKey(KEY_INPUT_D) >= 1)
	{
		if (clickRoom != -1)
		{
			m_unitMgr.Add_EDefense(MOUSE_V.x, m_mapMgr.Get_Ground(clickRoom) + UNIT_HEIGHT / 2, clickRoom);
			//enemy.Set_NextEnemyPos(cMouse::Instance()->GetEnemyNum(), clickRoom, MOUSE_V.x);
			//DEBUG_LOG("弓エネミー出現");
		}
	}
	else if (MOUSE_PRESS(RIGHT_CLICK) == 1 && cMouse::Instance()->GetEnemyNum() >= 0 && CheckHitKeyAll != 0)
	{
		if (clickRoom != -1)
		{
			m_unitMgr.Set_NextEnemyPos(cMouse::Instance()->GetEnemyNum(), clickRoom, MOUSE_V.x);
			cMouse::Instance()->SetEnemyNum(-1);
		}
	}
	else if (MOUSE_PRESS(RIGHT_CLICK) == 1)
	{
		int selectEnemy = 0;
		selectEnemy = m_unitMgr.CheckEnemyClick(MOUSE_V);
		if (0 <= selectEnemy)
		{
			cMouse::Instance()->SetEnemyNum(selectEnemy);
		}
		//enemy.Set_NextEnemyPos(eMove);
	}
	*/
}

void cGameMgr::UnitData()
{
	sUnitData tmp;

	tmp.maxPlayer = m_maxPlayer;
	tmp.playerCnt = m_PlayerCnt;
	tmp.typeCnt = m_unitMgr.Get_TypeCnt();
	m_UI.SetUnitData(tmp);
}