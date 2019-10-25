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

	void PUnitGenerate();
	void EscortDamageCalc(int _damage);
	void DefSuccessJudge();

	cFPS m_fps;
	cCamera m_camera;
	cUnitMgr m_PUnit;
	cMapMgr m_mapMgr;
	cEscortTarget m_escort;
	cTime m_time;
	int m_img;
	const int TIME_LIMIT = 120;	//•b
};

#endif // !_INCLUDE_GAMEMGR_
