#pragma once

/**********************************************************
���T�v
�V�[���Ǘ�������N���X���p�����A
�V�[���ύX������ۂɌĂяo���C���^�[�t�F�[�X�N���X
�Q�lURL:https://dixq.net/g/sp_06.html

���쐬��
�|�����

���X�V��
2019/08/01 �쐬
**********************************************************/

#ifndef _INCLUDE_ISCENECHANGER_
#define _INCLUDE_ISCENECHANGER_

// �V�[���̒萔
typedef enum {
	E_SCENE_TITLE,		// �^�C�g��
	E_SCENE_MENU,		// ���j���[
	E_SCENE_GAME,		// �Q�[��
	E_SCENE_RISULT,		// ���U���g
	E_SCENE_NONE,		// ����

}eScene;

class ISceneChanger
{
public:
	virtual ~ISceneChanger() = 0;
	virtual void ChangeScene(eScene _nextScene) = 0;
private:

};


#endif // !_INCLUDE_ISCENECHANGER_

