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
	//íËêîÇÃÇÊÇ§Ç»Ç‡ÇÃ
	static const int STAGE_NUM = 5;
	static const int BUTTON_MARGIN = 50;
	static const int TOP_MARGIN = 200;
	static const int LEFT_MARGIN = 250;
	static const int BUTTON_WIDTH = 100;
	static const int BUTTON_HEIGHT = 100;


	vector<cButton> stageButton;

	cButton okButton;
	sRECT okButtonRect;

};

#endif

