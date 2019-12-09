#pragma once
#ifndef _INCLUED_SOUND_
#define _INCLUED_SOUND_
#include "DxLib.h"
#include <iostream>
#include "BaseTask.h"
#include "ErrorCheck.h"
#include "Keyboard.h"
#include "string.h"
#include "WinBox.h"
#include "Singleton.h"
#include <fstream>
#include "Log.h"

using namespace std;

class cSound : public cBaseTask,public cSingleton<cSound>
{
public:
	cSound();
	friend cSingleton<cSound>;
	virtual ~cSound();

	virtual void Init();
	virtual void Update();
	virtual void Draw() {}
	virtual void End();

	typedef enum {
		E_SOUND_ENVIRONMENTAL,	//����
		E_SOUND_BGM,			//BGM
		E_SOUND_SE,				//SE
		E_VOL_LENGTH
	}eVolSetting;

	//SE
	typedef enum{
		E_SE_SELECT,	//����
		E_SE_CANSEL,	//�L�����Z��
		E_SE_SWORD,		//���m�@�U��
		E_SE_ARROW,		//�|�@�U��
		E_SE_BULLET,	//�e�@�U��
		E_SE_LENGTH,	//enum�̃T�C�Y
	}eSE;

	//BGM
	typedef enum{
		E_BGM_SEA,		//�C
		E_BGM_TITLE,	//�^�C�g��
		E_BGM_BATTLE,	//�o�g��
		E_BGM_WIN,		//���U���g�@����
		E_BGM_LOSE,		//���U���g�@�s�k
		E_BGM_LENGTH,	//enum�̃T�C�Y
	}eBGM;

	//�Đ����@
	typedef enum {
		E_PLAY_NORMAL,	//�m�[�}���Đ�
		E_PLAY_BACK,	//�o�b�N�O���E���h�Đ�
		E_PLAY_LOOP		//���[�v�Đ�
	}ePlayType;

#pragma region �֐�

	/*****************************************************
	���O�@�Fvoid ChangeSoundVolume();
	�T�v�@�F
	�����@�F
	�߂�l�F
	�⑫�@
	******************************************************/
	void ChangeSoundVolume();

	/*****************************************************
	���O�@�Fvoid PlaySE(eSE _se);
	�T�v�@�F���ʉ����Đ�
	�����@�FeSE _se:�炵�������ʉ�
	�߂�l�F�Ȃ�
	�⑫�@�F�I�[�o�[���[�h�L
	******************************************************/
	void PlaySE(eSE _se);

	/*****************************************************
	���O�@�Fvoid PlaySE(eSE _se);
	�T�v�@�F���ʉ����Đ�
	�����P�FeSE _se:�炵�������ʉ�
	�����Q�FePlayType _type:�Đ����@
	�߂�l�F�Ȃ�
	�⑫�@�F�I�[�o�[���[�h�L
	******************************************************/
	void PlaySE(eSE _se ,ePlayType _type);

	/*****************************************************
	���O�@�Fvoid PlayBGM(eBGM _bgm);
	�T�v�@�FBGM�𓪂���Đ�
	�����@�FeBGM _bgm:�炵����BGM
	�߂�l�F�Ȃ�
	�⑫�@�F�I�[�o�[���[�h�L
	******************************************************/
	void PlayBGM(eBGM _bgm);

	/*****************************************************
	���O�@�Fvoid PlayBGM(eBGM _bgm, ePlayType _type);
	�T�v�@�FBGM�𓪂���Đ��A�Đ����@��I���\
	�����P�FeBGM _bgm:�炵�������ʉ�
	�����Q�FePlayType _type:�Đ����@
	�߂�l�F�Ȃ�
	�⑫�@�F�I�[�o�[���[�h�L
	******************************************************/
	void PlayBGM(eBGM _bgm, ePlayType _type);

	/*****************************************************
	���O�@�Fvoid PlayBGM(eBGM _bgm, ePlayType _type, bool _topPos);
	�T�v�@�F
	�����P�FeBGM _bgm:�炵�������ʉ�
	�����Q�FePlayType _type:�Đ����@
	�����R�Fbool _topPos:(TRUE)������Đ� (FALSE)�O��̒��f�_����Đ�
	�߂�l�F�Ȃ�
	�⑫�@�F�I�[�o�[���[�h�L
	******************************************************/
	void PlayBGM(eBGM _bgm, ePlayType _type, bool _topPos);

	/*****************************************************
	���O�@�Fvoid CheckSound(eSE _se);
	�T�v�@�F���ʉ����Đ�����Ă��邩���ׂ�
	�����@�FeSE _se:�Đ������m�肽�����ʉ�
	�߂�l�F(TRUE)�Đ����@(FALSE)�Đ�����Ă��Ȃ�
	�⑫�@�F�I�[�o�[���[�h�L
	******************************************************/
	bool CheckSound(eSE _se);

	/*****************************************************
	���O�@�Fvoid CheckSound(eBGM _bgm);
	�T�v�@�FBGM���Đ�����Ă��邩���ׂ�
	�����@�FeBGM _bgm:�Đ������m�肽��BGM
	�߂�l�F(TRUE)�Đ����@(FALSE)�Đ�����Ă��Ȃ�
	�⑫�@�F�I�[�o�[���[�h�L
	******************************************************/
	bool CheckSound(eBGM _bgm);

	/*****************************************************
	���O�@�Fvoid StopSound(eSE _se);
	�T�v�@�F���ʉ����~�߂�
	�����@�FeSE _se:�~�߂������ʉ�
	�߂�l�F�Ȃ�
	�⑫�@�F�I�[�o�[���[�h�L
	******************************************************/
	void StopSound(eSE _se);

	/*****************************************************
	���O�@�Fvoid StopSound(eBGM _bgm);
	�T�v�@�FBGM���~�߂�
	�����@�FeBGM _bgm:�~�߂���BGM
	�߂�l�F�Ȃ�
	�⑫�@�F�I�[�o�[���[�h�L
	******************************************************/
	void StopSound(eBGM _bgm);

#pragma endregion

private:
	string m_SEPath[E_SE_LENGTH];		//SE�̃t�@�C���p�X
	string m_BGMPath[E_BGM_LENGTH];		//BGM�̃t�@�C���p�X
	int m_SE[E_SE_LENGTH];				//SE�̃T�E���h�n���h��
	int m_BGM[E_BGM_LENGTH];			//BGM�̃T�E���h�n���h��

	/*****************************************************
	���O�@�Fbool CheckValidArgument(eSE _se);
	�T�v�@�FSE�̈��������݂��邩�𒲂ׂ�
	�����@�FeSE _se:���ׂ����l
	�߂�l�F(TRUE)�L���͈͓��@(FALSE)�L���͈͊O
	�⑫�@�F�I�[�o�[���[�h�L
	******************************************************/
	bool CheckValidArgument(eSE _se);

	/*****************************************************
	���O�@�Fbool CheckValidArgument(eBGM _bgm);
	�T�v�@�FBGM�̈��������݂��邩�𒲂ׂ�
	�����@�FeBGM _bgm:���ׂ����l
	�߂�l�F(TRUE)�L���͈͓��@(FALSE)�L���͈͊O
	�⑫�@�F�I�[�o�[���[�h�L
	******************************************************/
	bool CheckValidArgument(eBGM _bgm);



	int m_volume[E_VOL_LENGTH];

};


#endif // !_INCLUED_SOUND_
