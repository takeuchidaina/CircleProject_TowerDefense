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
#include "CSVLoad.h"

class cUnitSelect : public cBaseScene {
public:
	cUnitSelect(ISceneChanger* _scene);

	void Init()override;
	void Update()override;
	void Draw()override;
	void End()override;

private:

	string CSVFilePath;
	string ImageFilePath;
	string pathBG = "../resource/img/UI_BG.png";
	
	vector<cButton> unitButton;
	cButton resetButton;
	cButton okButton;
	vector<int> selectUnit;
	vector<sUnitLoad> unitData;

	sRECT selectUnitRect;
	sRECT resetButtonRect;
	sRECT okButtonRect;
};

#endif