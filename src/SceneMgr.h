#pragma once
#ifndef _INCLUED_SCENEMGR_
#define _INCLUED_SCENEMGR_

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
�S�ẴV�[�����Ǘ�����

���쐬��
�|�����
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
	���O�@�Fvoid ChangeScene(eScene _nextScene)
	�T�v�@�F�V�[���������̃V�[���ɕύX����
	�����@�FeScene _nextScene:�ύX�������V�[��
	�߂�l�F�Ȃ�
	�⑫�@�FISceneChanger���I�[�o�[���C�h
	******************************************************/
	void ChangeScene(eScene _nextScene)override;

private:

	cBaseScene* m_scene;	//�V�[���Ǘ��ϐ�
	eScene m_nextScene;		//���̃V�[��

};

#endif // !_INCLUED_SCENEMGR_

