#pragma once
#ifndef _INCLUED_SCENEMGR_
#define _INCLUED_SCENEMGR_

#include "DxLib.h"
#include "ISceneChanger.h"
#include "BaseScene.h"
#include "BaseTask.h"
#include "Title.h"
#include "Menu.h"
#include "StageSelect.h"
#include "UnitSelect.h"
#include "GameMgr.h"
#include "Result.h"
#include "Setting.h"
#include "Mouse.h"

/**********************************************************
●概要
全てのシーンを管理する

●作成者
竹内大奈
**********************************************************/

class cSceneMgr:public ISceneChanger , cBaseTask {

public:
	cSceneMgr();
	virtual ~cSceneMgr() {}

	void Init()override;
	void Update()override;
	void Draw()override;
	void End()override;

	/*****************************************************
	名前　：void ChangeScene(eScene _nextScene)
	概要　：シーンを引数のシーンに変更する
	引数　：eScene _nextScene:変更したいシーン
	戻り値：なし
	補足　：ISceneChangerよりオーバーライド
	******************************************************/
	void ChangeScene(eScene _nextScene)override;

	void SettingStart()override;

	int Get_PoseCount()override;

	void ResetPoseCount()override;

private:

	cBaseScene* m_scene;	//シーン管理変数
	eScene m_nextScene;		//次のシーン
	cSetting m_setting;		//設定
	bool isPose;			//TRUE:ポーズ中　FALSE:ポーズ中ではない
	eScene m_nowScene;		//現在のシーン
	int m_poseCount;		//設定している時間
	cButton m_button;		//タイトルバックボタン

};

#endif // !_INCLUED_SCENEMGR_

