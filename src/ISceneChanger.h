#pragma once

#include <iostream>
/**********************************************************
���T�v
�V�[���Ǘ�������N���X���p�����A
�V�[���ύX������ۂɌĂяo���C���^�[�t�F�[�X�N���X

���쐬��
�|�����
**********************************************************/

#ifndef _INCLUDE_ISCENECHANGER_
#define _INCLUDE_ISCENECHANGER_

// �V�[���̒萔
typedef enum {
	E_SCENE_TITLE,			// �^�C�g��
	E_SCENE_MENU,			// ���j���[
	E_SCENE_STAGESELECT,	// �X�e�[�W�I��
	E_SCENE_UNITSELECT,		// ���j�b�g�I��
	E_SCENE_GAME,			// �Q�[��
	E_SCENE_RESULT,			// ���U���g
	E_SCENE_END,
	E_SCENE_NONE,			// ����

}eScene;

class ISceneChanger
{
public:
	virtual ~ISceneChanger() = 0;

	/*****************************************************
	���O�@�Fvoid ChangeScene(eScene _nextScene)
	�T�v�@�F�V�[���������̃V�[���ɕύX����
	�����@�FeScene _nextScene:�ύX�������V�[��
	�߂�l�F�Ȃ�
	�⑫�@�F���ۃN���X�@�L���K�{
	******************************************************/
	virtual void ChangeScene(eScene _nextScene) = 0;
private:

};


#endif // !_INCLUDE_ISCENECHANGER_

