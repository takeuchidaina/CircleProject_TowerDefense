#pragma once

#include "DxLib.h"
#include "DebugList.h"
#include "ColorListh.h"
#include "BaseTask.h"
#include "ISceneChanger.h"

/**********************************************************
���T�v
�V�[���̊��N���X
�Q�lURL:https://dixq.net/g/sp_06.html

���쐬��
�|�����

���X�V��
2019/08/01 �쐬
**********************************************************/

#ifndef _INCLUDE_BASESCENE_
#define _INCLUDE_BASESCENE_

class cBaseScene : public cBaseTask {

protected:
	ISceneChanger* m_sceneChanger;	// �N���X���L��ɃV�[���؂�ւ���`����

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

