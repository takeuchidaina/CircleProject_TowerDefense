#pragma once
#pragma once
#ifndef _INCLUED_UNITSELECT_
#define _INCLUED_UNITSELECT_

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

class cUnitSelect : public cBaseScene {
public:
	cUnitSelect(ISceneChanger* _scene);

	void Init()override;
	void Update()override;
	void Draw()override;
	void End()override;

private:

};

#endif