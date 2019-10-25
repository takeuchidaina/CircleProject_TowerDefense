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
	
	cFPS m_fps;
	cCamera m_camera;

	cUnitMgr m_PUnit;
	void PUnitGenerate();

	cUnitMgr m_EUnit;
	void EUnitGenerate();

	cMapMgr m_mapMgr;
	//cMap m_map;
};

#endif // !_INCLUDE_GAMEMGR_
