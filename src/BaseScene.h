#pragma once
#ifndef _INCLUDE_BASESCENE_
#define _INCLUDE_BASESCENE_

#include "DxLib.h"
#include "DebugList.h"
#include "ColorListh.h"
#include "BaseTask.h"
#include "ISceneChanger.h"

/**********************************************************
���T�v
�V�[���̊��N���X
�J�ڑΏۂ̃V�[���͑S�Čp��������

���쐬��
�|�����
**********************************************************/

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

