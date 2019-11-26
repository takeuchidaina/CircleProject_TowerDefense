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
#include "EscortTarget.h"
#include "TimeLimit.h"
//#include "Result.h"
#include "Log.h"

#ifndef _INCLUDE_GAMEMGR_
#define _INCLUDE_GAMEMGR_

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
	cEscortTarget m_escort;
	cTime m_time;

	cUnitMgr m_PUnit;
	void PUnitGenerate();
	cUnitMgr m_EUnit;
	void EUnitGenerate();

	int m_img;
	const int TIME_LIMIT = 120;
};

#endif // !_INCLUDE_GAMEMGR_
