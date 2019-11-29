#pragma once

#include "DxLib.h"
#include "ISceneChanger.h"
#include "BaseScene.h"
#include "BaseTask.h"
#include "Title.h"
#include "Menu.h"
#include "GameMgr.h"
#include "Result.h"

/**********************************************************
●概要
全てのシーンを管理するクラス
参考URL:https://dixq.net/g/sp_06.html

●作成者
竹内大奈

●更新日
2019/08/01 作成
**********************************************************/

#ifndef _INCLUED_SCENEMGR_
#define _INCLUED_SCENEMGR_

class cSceneMgr:public ISceneChanger , cBaseTask {

public:
	cSceneMgr();
	virtual ~cSceneMgr() {}

	void Init()override;
	void Update()override;
	void Draw()override;
	void End()override;

	void ChangeScene(eScene _nextScene)override;

private:

	cBaseScene* m_scene;	// シーン管理変数
	eScene m_nextScene;		// 次のシーン

};

#endif // !_INCLUED_SCENEMGR_

