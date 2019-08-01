#pragma once

#include "DxLib.h"
#include "BaseTask.h"
#include "ISceneChanger.h"

/**********************************************************
●概要
シーンの基底クラス
参考URL:https://dixq.net/g/sp_06.html

●作成者
竹内大奈

●更新日
2019/08/01 作成
**********************************************************/

#ifndef _INCLUDE_BASESCENE_
#define _INCLUDE_BASESCENE_

class cBaseScene : public cBaseTask {

protected:
	ISceneChanger* sceneChanger;	// クラス所有基にシーン切り替えを伝える

public:
	cBaseScene(ISceneChanger* _scene);
	virtual ~cBaseScene(){}

	virtual void Init()override;
	virtual void Update()override;
	virtual void Draw()override;
	virtual void End()override;

private:

};

#endif // !_INCLUDE_BASESCENE_

