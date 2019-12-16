#pragma once
#ifndef _INCLUDE_BASESCENE_
#define _INCLUDE_BASESCENE_

#include "DxLib.h"
#include "DebugList.h"
#include "ColorListh.h"
#include "BaseTask.h"
#include "ISceneChanger.h"

/**********************************************************
●概要
シーンの基底クラス
遷移対象のシーンは全て継承をする

●作成者
竹内大奈
**********************************************************/

class cBaseScene : public cBaseTask {

protected:
	ISceneChanger* m_sceneChanger;	// クラス所有基にシーン切り替えを伝える

public:
	cBaseScene(ISceneChanger* _scene);
	virtual ~cBaseScene(){}
	virtual void Init()override {}
	virtual void Update()override {}
	virtual void Draw()override {}
	virtual void End()override {}

private:

};

#endif // !_INCLUDE_BASESCENE_

