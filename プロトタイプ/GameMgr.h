#pragma once

#include "DxLib.h"
#include "DebugList.h"
#include "ColorListh.h"
#include "BaseScene.h"
#include "BaseTask.h"
#include "ISceneChanger.h"
#include "FPS.h"

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

	cFPS fps;
};

#endif // !_INCLUDE_GAMEMGR_
