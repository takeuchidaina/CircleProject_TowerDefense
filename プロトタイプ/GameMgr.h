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
//#include "EscortTarget.h"
#include "TimeLimit.h"
#include "Sound.h"
//#include "Result.h"
#include "ErrorCheck.h"
#include "UI.h"

#pragma warning(disable : 4996)

#ifndef _INCLUDE_GAMEMGR_
#define _INCLUDE_GAMEMGR_

#define SPAWN_CNT 400
#define MOVE_CNT 100

class cGameMgr : public cBaseScene{

public:
	cGameMgr(ISceneChanger* _scene);

	void Init()override;
	void Update()override;
	void Draw()override;
	void End()override;
	
private:

	void EscortDamageCalc(int _damage);
	void DefSuccessJudge();

	cFPS m_fps;
	cCamera m_camera;
	cMapMgr m_mapMgr;
	//cEscortTarget m_escort;
	cTime m_time;
	cUI m_UI;

	cUnitMgr m_unitMgr;
	void UnitGenerate();

	int m_ship;
	int m_BG;
	int m_wave;

	typedef struct {
		VECTOR pos;
		int image;
	}sBG;

	sBG m_cloud[2];
	const float CLOUD_SPEED = 0.25f;
	const int TIME_LIMIT = 60;

	void MoveBackGround();
	void ResultSave(bool _result);

	int SpawnCnt = 0;			// 一定数まで行ったらスポーン
	int SpawnType = 0;			// スポーンするタイプを決めるランダム
	int MoveCnt = 0;			// 一定数まで行ったら移動
	int MoveType = 0;			// moveするTypeを決めるランダム

};

#endif // !_INCLUDE_GAMEMGR_
