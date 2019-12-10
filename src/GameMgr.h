#pragma once

#include "DxLib.h"
#include "DebugList.h"
#include "ColorListh.h"
#include "BaseScene.h"
#include "BaseTask.h"
#include "ISceneChanger.h"
#include "Mouse.h"
#include "Keyboard.h"
#include "FPS.h"
#include "Camera.h"
#include "UnitMgr.h"
#include "MapMgr.h"
#include "Map.h"
#include "TimeLimit.h"
#include "Sound.h"
#include "ErrorCheck.h"
#include "UI.h"
#include "Setting.h"
#include "MapNavigate.h"

#ifndef _INCLUDE_GAMEMGR_
#define _INCLUDE_GAMEMGR_

#define SPAWN_CNT 200

class cGameMgr : public cBaseScene{

public:
	cGameMgr(ISceneChanger* _scene);

	void Init()override;
	void Update()override;
	void Draw()override;
	void End()override;
	
private:

	void EscortDamageCalc();
	void DefSuccessJudge();

	cFPS m_fps;
	cCamera m_camera;
	cMapMgr m_mapMgr;
	cTime m_time;
	cUI m_UI;
	cSetting m_setting;
	cUnitMgr m_unitMgr;
	cMapNavigate m_mapNavigate;

	void UnitGenerate();
	void UnitData();
	void MoveBackGround();
	void ResultSave(bool _result);

	int m_ship;
	int m_BG;
	int m_wave;

	typedef struct {
		VECTOR pos;
		int image;
	}sBG;

	sBG m_cloud[2];
	const float CLOUD_SPEED = 0.25f;

	int m_spawnCnt = 0;			// 
	int m_spawnType = 0;		// 

	const int TIME_LIMIT = 60;
	int SpawnCnt = 0;			// 一定数まで行ったらスポーン
	int SpawnType = 0;			// スポーンするタイプを決めるランダム
	int MoveCnt = 0;			// 一定数まで行ったら移動
	int MoveType = 0;			// moveするTypeを決めるランダム

	int m_maxPlayer;			// Unit生成コスト
	int m_PlayerCnt;			// PlayerUnit全体のカウント
	sTypeCnt m_unitCnt;			// タイプ別の数

	typedef enum {
		E_PREPARATION,	//準備
		E_BATTLE,		//戦闘
		E_EVENT,		//イベント
		E_CUTSCENE,		//カットシーン
		E_POSE,			//ポーズ
	}eGameState;
	eGameState m_gameState;

};

#endif // !_INCLUDE_GAMEMGR_
