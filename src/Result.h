#pragma once
#ifndef _INCLUED_RESULT_
#define _INCLUED_RESULT_

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
using namespace std;

/********************************************************
●概要
　リザルト画面
 　戦闘で起こった結果を表示する

●作成者
　竹内 大奈
********************************************************/

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
		sRECT rect = { 0,0,0,0 };					//左上xy,右下xy
		string filePath = "";		//画像のファイルパス
		int handle = 0;				//画像ハンドル
	}sImage;

	sImage m_image;
	cButton m_btn;
	bool m_result;	//TRUE:勝利 FALSE:敗北
	bool m_sound;	//TRUE:鳴らし済み FALSE:鳴らしていない　BGM
};
#endif // _INCLUED_RESULT_
