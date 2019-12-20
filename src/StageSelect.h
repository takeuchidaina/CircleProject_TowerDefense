#pragma once
#ifndef _INCLUED_STAGESELECT_
#define _INCLUED_STAGESELECT_

#include "DxLib.h"
#include "DebugList.h"
#include "ColorListh.h"
#include "Constant.h"
#include "BaseScene.h"
#include "BaseTask.h"
#include "ISceneChanger.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Button.h"
#include <string.h>
#include "ErrorCheck.h"
#include "Sound.h"

class cStageSelect : public cBaseScene {
public:
	cStageSelect(ISceneChanger* _scene);

	void Init()override;
	void Update()override;
	void Draw()override;
	void End()override;

private:

};

#endif

