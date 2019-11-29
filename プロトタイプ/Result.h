#pragma once

#include "DxLib.h"
#include "DebugList.h"
#include "ColorListh.h"
#include "BaseScene.h"
#include "BaseTask.h"
#include "ISceneChanger.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Button.h"
#include <string.h>
#include "ErrorCheck.h"
#include "Sound.h"

using namespace std;         //  名前空間指定

class cResult : public cBaseScene {

public:
	cResult(ISceneChanger* _scene);

	void Init()override;
	void Update()override;
	void Draw()override;
	void End()override;

private:
	int m_BG;

	// 画像配置の必要情報
	typedef struct {
		double ux = 0, uy = 0, dx = 0, dy = 0;	//左上xy,右下xy
		string filePath = "";		//画像のファイルパス
		int handle = 0;				//画像ハンドル
	}sImage;

	sImage m_image;
	cButton m_btn;
};
