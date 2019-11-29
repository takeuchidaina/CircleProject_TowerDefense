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
���T�v
�S�ẴV�[�����Ǘ�����N���X
�Q�lURL:https://dixq.net/g/sp_06.html

���쐬��
�|�����

���X�V��
2019/08/01 �쐬
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

	cBaseScene* m_scene;	// �V�[���Ǘ��ϐ�
	eScene m_nextScene;		// ���̃V�[��

};

#endif // !_INCLUED_SCENEMGR_

