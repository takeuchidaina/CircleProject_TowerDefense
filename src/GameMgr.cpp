#include "GameMgr.h"

cGameMgr::cGameMgr(ISceneChanger* _scene) : cBaseScene(_scene) {

}

void cGameMgr::Init() {

	//ユニット管理部・敵AIにマップ情報を渡す
	m_unitMgr.Set_MapData(m_mapMgr.GetMapData());
	m_mapNavigate.Set_MapDate(m_mapMgr.GetMapDes());

	//BGM
	cSound::Instance()->StopSound(cSound::Instance()->E_BGM_TITLE);
	cSound::Instance()->PlayBGM(
		cSound::Instance()->E_BGM_PREPARATION, cSound::Instance()->E_PLAY_LOOP, FALSE);		//戦闘BGM
	cSound::Instance()->PlayEVM(
		cSound::Instance()->E_EVM_SEA_ROUGH, cSound::Instance()->E_PLAY_LOOP, TRUE);	//さざ波

	m_PlayerCnt = 0;		//プレイヤーユニットの出現数

	m_gameState = E_PREPARATION;	//初期ステート
	m_stateHistory = m_gameState;

	SRand(time(NULL));		//敵ユニットのランダム出現用に現在時刻でrandを初期化

	cTime* ptime = new cTime(TIME_LIMIT_WAIT);
	m_time = *ptime;
	delete ptime;
}

void cGameMgr::Update() {

	//BGM変更
	if (m_gameState != m_stateHistory && m_stateHistory == E_PREPARATION) {
		cSound::Instance()->StopSound(cSound::Instance()->E_BGM_PREPARATION);
		cSound::Instance()->PlayBGM(cSound::Instance()->E_BGM_BATTLE);		//戦闘BGM
		m_sceneChanger->ResetPoseCount();
		m_stateHistory = m_gameState;
	}

	//ステート管理
	switch (m_gameState)
	{
		//戦闘準備
	case E_PREPARATION:
		m_camera.Update();		//カメラの移動・ズーム
		m_unitMgr.Update();		//TODO:ユニットの生成をUnitMgrで行う
		m_BG.Update();			//雲のアニメーション
		PlayerGenerate();
		UnitData();
		m_time.Update();		//制限時間を更新
		m_time.Set_PoseTimer(m_sceneChanger->Get_PoseCount());

		if (m_time.GetSecond() <= 1/*sec*/) {
			//時間
			cTime* ptime = new cTime(TIME_LIMIT_GAME);
			m_time = *ptime;
			delete ptime;

			m_gameState = E_BATTLE;
		}
		break;
		//戦闘
	case E_BATTLE:
		m_unitMgr.Update();		//ユニットの行動
		UnitData();				//UIにユニットのデータをセットする
		m_time.Update();		//制限時間を更新
		DefSuccessJudge();		//時間制限による勝利判定
		EnemyExtermination();	//敵残滅数による勝利判定
		EscortDamageCalc();		//護衛対象のHPによる敗北判定
		m_mapMgr.Update();		//マップサイズ用　特段処理は無し
		m_camera.Update();		//カメラの移動・ズーム
		m_BG.Update();			//雲のアニメーション
		EnemyGenerate();		//敵生成

		m_time.Set_PoseTimer(m_sceneChanger->Get_PoseCount());
		break;
		//イベント
	case E_EVENT:
		break;
		//カットシーン
	case E_CUTSCENE:
		break;
		//ポーズ
	case E_POSE:
		//ゲームを終了ボタン
		break;
	}

}

void cGameMgr::Draw() {

	//ステート管理
	switch (m_gameState)
	{
		//戦闘準備
	case E_PREPARATION:
		m_BG.Draw();
		m_mapMgr.Draw();
		m_unitMgr.Draw();
		m_time.Draw();
		SetFontSize(30);
		DrawFormatString(900, 20, WH, " Defense Starts:");
		break;
		//戦闘
	case E_BATTLE:
		m_BG.Draw();
		m_mapMgr.Draw();
		m_unitMgr.Draw();
		SetFontSize(30);
		DrawFormatString(900, 20, WH, "Defense Success:");
		m_time.Draw();
		break;
		//イベント
	case E_EVENT:
		break;
		//カットシーン
	case E_CUTSCENE:
		break;
		//ポーズ
	case E_POSE:
		m_BG.Draw();
		m_mapMgr.Draw();
		m_unitMgr.Draw();
		break;
	}
}

void cGameMgr::End() {
	if (m_gameState == E_PREPARATION) {
		cSound::Instance()->StopSound(cSound::Instance()->E_BGM_PREPARATION);
	}
	else if (m_gameState == E_BATTLE) {
		cSound::Instance()->StopSound(cSound::Instance()->E_BGM_BATTLE);
	}
	else {
		cSound::Instance()->StopSound(cSound::Instance()->E_BGM_PREPARATION);
		cSound::Instance()->StopSound(cSound::Instance()->E_BGM_BATTLE);
	}
	cSound::Instance()->StopSound(cSound::Instance()->E_EVM_SEA_ROUGH);

	m_sceneChanger->ResetPoseCount();
}

void cGameMgr::Set_GameState(eGameState _state) {
	m_gameState = _state;
}

/*****************************************************
名前　：void EscortDamageCalc();
概要　：護衛対象のHPを元に敗北判定を行う
引数　：なし
戻り値：なし
******************************************************/
void cGameMgr::EscortDamageCalc() {
	//HPが無くなったらリザルトへ
	if (m_unitMgr.EscortDie() == false) {
		cSound::Instance()->StopSound(cSound::Instance()->E_BGM_BATTLE);
		cSound::Instance()->StopSound(cSound::Instance()->E_EVM_SEA_ROUGH);
		ResultSave(FALSE);
		m_sceneChanger->ChangeScene(E_SCENE_RESULT);
	}
}

/*****************************************************
名前　：void DefSuccessJudge();
概要　：制限時間を元に勝利判定を行う
引数　：なし
戻り値：なし
******************************************************/
void cGameMgr::DefSuccessJudge() {
	if (m_time.GetSecond() <= 1/*sec*/) {
		cSound::Instance()->StopSound(cSound::Instance()->E_BGM_BATTLE);
		cSound::Instance()->StopSound(cSound::Instance()->E_EVM_SEA_ROUGH);
		ResultSave(TRUE);
		m_sceneChanger->ChangeScene(E_SCENE_RESULT);
	}
}

/*****************************************************
名前　：void DefSuccessJudge();
概要　：制限時間を元に勝利判定を行う
引数　：なし
戻り値：なし
******************************************************/
void cGameMgr::EnemyExtermination() {
	if (m_unitMgr.Get_GameClear() == TRUE) {
		cSound::Instance()->StopSound(cSound::Instance()->E_BGM_BATTLE);
		cSound::Instance()->StopSound(cSound::Instance()->E_EVM_SEA_ROUGH);
		ResultSave(TRUE);
		m_sceneChanger->ChangeScene(E_SCENE_RESULT);
	}
}

/*****************************************************
名前　：void ResultSave(bool _result);
概要　：ファイルに勝敗結果を書き出す
引数　：bool _result : 勝敗結果　(TRUE)勝利 (FALSE)敗北
戻り値：なし
******************************************************/
void cGameMgr::ResultSave(bool _result) {
	FILE* fp;

	errno_t err; // errno_t型(int型)
	err = fopen_s(&fp, "../Data/result.txt", "wb"); // ファイルを開く。失敗するとエラーコードを返す。
	if (err != 0) {
		DEBUG_LOG("file not open");
	}

	const char* result;
	if (_result == TRUE) {
		result = "win";
	}
	else {
		result = "lose";
	}

	fwrite(result, sizeof(result), 1, fp);
	fclose(fp);

}

/*****************************************************
名前　：void PlayerGenerate();
概要　：プレイヤーユニットの生成
引数　：なし
戻り値：なし
******************************************************/
void cGameMgr::PlayerGenerate() {

	//プレイヤーの生成
	int clickRoom = 0;
	if (MOUSE_PRESS(LEFT_CLICK) == 1 || MOUSE_PRESS(RIGHT_CLICK) == 1) {
		clickRoom = m_mapMgr.CheckInto(MOUSE_V.x, MOUSE_V.y);
	}

	if (m_maxPlayer > m_PlayerCnt) {			// コスト制限
		//剣　生成
		if (MOUSE_PRESS(LEFT_CLICK) == 1 && CheckHitKey(KEY_INPUT_S) >= 1) {
			if (clickRoom != -1) {
				if (m_unitMgr.Add_PSord(MOUSE_V.x, m_mapMgr.Get_Ground(clickRoom) + UNIT_HEIGHT / 2, clickRoom) == 0) {
					m_PlayerCnt++;
					m_UI.SetPlayerCount(0);
				}
			}
		}
		//銃　生成
		else if (MOUSE_PRESS(LEFT_CLICK) == 1 && CheckHitKey(KEY_INPUT_A) >= 1) {
			if (clickRoom != -1) {
				if (m_unitMgr.Add_PArcher(MOUSE_V.x, m_mapMgr.Get_Ground(clickRoom) + UNIT_HEIGHT / 2, clickRoom) == 0) {
					m_PlayerCnt++;
					m_UI.SetPlayerCount(1);
				}
			}
		}
		//盾　生成
		else if (MOUSE_PRESS(LEFT_CLICK) == 1 && CheckHitKey(KEY_INPUT_D) >= 1) {
			if (clickRoom != -1) {
				if (m_unitMgr.Add_PDefense(MOUSE_V.x, m_mapMgr.Get_Ground(clickRoom) + UNIT_HEIGHT / 2, clickRoom) == 0) {
					m_PlayerCnt++;
					m_UI.SetPlayerCount(2);
				}
			}
		}
	}
	//部屋の移動
	else if (MOUSE_PRESS(LEFT_CLICK) == 1 && cMouse::Instance()->GetPlayerNum() >= 0 && CheckHitKeyAll != 0) {
		int clickRoom = m_mapMgr.CheckInto(MOUSE_V.x, MOUSE_V.y);
		if (clickRoom != -1) {
			m_unitMgr.Set_NextPlayerPos(cMouse::Instance()->GetPlayerNum(), clickRoom, MOUSE_V.x);
			cMouse::Instance()->SetPlayerNum(-1);
		}
	}
	//ユニットの選択
	else if (MOUSE_PRESS(LEFT_CLICK) == 1) {
		int selectPlayer = 0;
		clickRoom = m_unitMgr.CheckPlayerClick(MOUSE_V);
		if (0 <= selectPlayer) {
			cMouse::Instance()->SetPlayerNum(selectPlayer);
		}
	}
}

/*****************************************************
名前　：void EnemyGenerate();
概要　：敵ユニットの生成
引数　：なし
戻り値：なし
******************************************************/
void cGameMgr::EnemyGenerate() {

	//Enemyのランダム生成
	m_spawnCnt++;				// 一定数まで行ったらスポーン
	m_spawnType = GetRand(2);	// スポーンするタイプを決めるランダム
	m_spawnCoolTime = GetRand(MOVE_COOLTIME_MAX) + MOVE_COOLTIME_MIN;

	if (m_spawnCnt >= m_spawnCoolTime) {
		switch (m_spawnType) {
		case 0:	m_unitMgr.Add_ESord(m_mapMgr.GetStartRoomNum(), m_mapMgr.Get_Ground(0) + UNIT_HEIGHT / 2);
			m_spawnCnt = 0;
			break;
		case 1:	m_unitMgr.Add_EArcher(m_mapMgr.GetStartRoomNum(), m_mapMgr.Get_Ground(0) + UNIT_HEIGHT / 2);
			m_spawnCnt = 0;
			break;
		case 2:	m_unitMgr.Add_EDefense(m_mapMgr.GetStartRoomNum(), m_mapMgr.Get_Ground(0) + UNIT_HEIGHT / 2);
			m_spawnCnt = 0;
			break;
		}
	}
}

/*****************************************************
名前　：void UnitData();
概要　：UIにプレイヤーのユニット情報(出現数等)を渡す
引数　：ファイルを入れた変数
戻り値：なし
******************************************************/
void cGameMgr::UnitData() {

	sUnitData data;

	//必要なデータを構造体に格納しセット
	data.maxPlayer = m_maxPlayer;			//プレイヤーの最大数
	data.playerCnt = m_PlayerCnt;			//プレイヤーの出現数
	data.typeCnt = m_unitMgr.Get_TypeCnt();	//タイプのカウント
	m_UI.SetUnitData(data);
}