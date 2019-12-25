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
	string pathBG;
	int pathBGGraph;
	string pathUI;
	int pathUIGraph;
	
	vector<cButton> unitButton;
	cButton resetButton;
	cButton okButton;
	cButton backButton;

	sRECT selectUnitRect;
	sRECT resetButtonRect;
	sRECT okButtonRect;
	sRECT backButtonRect;

	vector<int> selectUnit;
	vector<sUnitLoad> unitData;
	vector<int> unitCostArray;		//unitDataèá
	int unitCostNum;
	vector<int> graphArray;
	int unitCursorFlg;

};
#endif