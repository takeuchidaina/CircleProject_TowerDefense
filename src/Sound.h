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

/**********************************************************
���T�v
���y�t�@�C�����i�[���Đ����~���s��
�V���O���g��������Ă���̂łǂ���
�N���X����ł��Ăяo�����Ƃ��\

���쐬��
�|�����
**********************************************************/

class cSound : public cBaseTask,public cSingleton<cSound>
{
public:
	cSound();
	friend cSingleton<cSound>;
	virtual ~cSound();

	virtual void Init();
	virtual void Update(){}
	virtual void Draw() {}
	virtual void End();

	//���ʂ̐ݒ荀��
	typedef enum {
		E_VOL_EVM,		//����
		E_VOL_BGM,		//BGM
		E_VOL_SE,		//SE
		E_VOL_LENGTH
	}eVolSetting;

	//SE
	typedef enum{
		E_SE_SELECT,	//����
		E_SE_CANSEL,	//�L�����Z��
		E_SE_SWORD,		//���@�U��
		E_SE_SHEILD,	//���@�h��
		E_SE_BULLET,	//�e�@�U��
		E_SE_WIN,		//ME ����
		E_SE_LOSE,		//ME ����
		E_SE_LENGTH
	}eSE;

	//BGM
	typedef enum{
		E_BGM_TITLE,	//�^�C�g��
		E_BGM_PREPARATION,	//�o�g���@�ҋ@
		E_BGM_BATTLE,	//�o�g���@�퓬
		E_BGM_WIN,		//���U���g�@����
		E_BGM_LOSE,		//���U���g�@�s�k
		E_BGM_LENGTH
	}eBGM;

	//EVM	(environment:��)
	typedef enum {
		E_EVM_SEA_ROUGH,	//�r�g
		E_EVM_SEA_RIPPLES,	//�����g
		E_EVM_LENGTH
	}eEVM;

	//�Đ����@
	typedef enum {
		E_PLAY_NORMAL,	//�m�[�}���Đ�
		E_PLAY_BACK,	//�o�b�N�O���E���h�Đ�
		E_PLAY_LOOP		//���[�v�Đ�
	}ePlayType;

#pragma region �֐�

	/*****************************************************
	���O�@�Fvoid ChangeSoundVolume();
	�T�v�@�F���ʒl�̕ύX�𔽉f����
	�����@�F�Ȃ�
	�߂�l�F�Ȃ�
	�⑫�@�F�l�̓t�@�C������ǂݎ��
	******************************************************/
	void ChangeSoundVolume();

	/*****************************************************
	���O�@�Fvoid PlaySE(eSE _se);
	�T�v�@�F���ʉ����Đ�
	�����P�FeSE _se:�炵�������ʉ�
	�����Q�FePlayType _type:�Đ����@
	�߂�l�F�Ȃ�
	�⑫�@�F�����P�Ɉ����Q��ǉ�����`�ŃI�[�o�[���[�h�L
	******************************************************/
	void PlaySE(eSE _se);
	void PlaySE(eSE _se, ePlayType _type);

	/*****************************************************
	���O�@�Fvoid PlayBGM(eBGM _bgm);
	�T�v�@�FBGM���Đ�
	�����P�FeBGM _bgm:�Đ�������BGM
	�����Q�FePlayType _type:�Đ����@
	�����R�Fbool _topPos:(TRUE)������Đ� (FALSE)�O��̒��f�_����Đ�
	�߂�l�F�Ȃ�
	�⑫�@�F�����P�Ɉ����Q,�R��ǉ�����`�ŃI�[�o�[���[�h�L
	******************************************************/
	void PlayBGM(eBGM _bgm);
	void PlayBGM(eBGM _bgm, ePlayType _type);
	void PlayBGM(eBGM _bgm, ePlayType _type, bool _topPos);

	/*****************************************************
	���O�@�Fvoid PlayEVM(eEVM _evm);
	�T�v�@�FEVM���Đ�
	�����P�FeEVM _evm:�Đ�������EVM
	�����Q�FePlayType _type:�Đ����@
	�����R�Fbool _topPos:(TRUE)������Đ� (FALSE)�O��̒��f�_����Đ�
	�߂�l�F�Ȃ�
	�⑫�@�F�����P�Ɉ����Q,�R��ǉ�����`�ŃI�[�o�[���[�h�L
	******************************************************/
	void PlayEVM(eEVM _evm);
	void PlayEVM(eEVM _evm, ePlayType _type);
	void PlayEVM(eEVM _evm, ePlayType _type, bool _topPos);

	/*****************************************************
	���O�@�Fvoid CheckSound(eSE _se);
	�T�v�@�F�����Đ�����Ă��邩���ׂ�
	�����P�FeSE _se:�Đ������m�肽��SE
	�����P�FeBGM _bgm:�Đ������m�肽��BGM
	�����P�FeEVM _evm:�Đ������m�肽��EVM
	�߂�l�F(TRUE)�Đ����@(FALSE)�Đ�����Ă��Ȃ�
	�⑫�@�F�������ɃI�[�o�[���[�h�L
	******************************************************/
	bool CheckSound(eSE _se);
	bool CheckSound(eBGM _bgm);
	bool CheckSound(eEVM _evm);

	/*****************************************************
	���O�@�Fvoid StopSound(eSE _se);
	�T�v�@�F���ʉ����~�߂�
	�����P�FeSE _se:�~�߂���SE
	�����P�FeBGM _bgm:�~�߂���BGM
	�����P�FeEVM _evm:�~�߂���EVM
	�߂�l�F�Ȃ�
	�⑫�@�F�������ɃI�[�o�[���[�h�L
	******************************************************/
	void StopSound(eSE _se);
	void StopSound(eBGM _bgm);
	void StopSound(eEVM _evm);

#pragma endregion

private:
	string m_SEPath[E_SE_LENGTH];		//SE�̃t�@�C���p�X
	string m_BGMPath[E_BGM_LENGTH];		//BGM�̃t�@�C���p�X
	string m_EVMPath[E_EVM_LENGTH];		//EVM�̃t�@�C���p�X
	int m_SE[E_SE_LENGTH];				//SE�̃T�E���h�n���h��
	int m_BGM[E_BGM_LENGTH];			//BGM�̃T�E���h�n���h��
	int m_EVM[E_EVM_LENGTH];			//EVM�̃T�E���h�n���h��

	int m_volume[E_VOL_LENGTH];			//�e���ڂ̉��ʒl

	/*****************************************************
	���O�@�Fbool CheckValidArgument(eSE _se);
	�T�v�@�FSE�̈��������݂��邩�𒲂ׂ�
	�����P�FeSE _se:���ׂ����l
	�����P�FeBGM _bgm:���ׂ����l
	�����P�FeEVM _evm:���ׂ����l
	�߂�l�F(TRUE)�L���͈͓��@(FALSE)�L���͈͊O
	�⑫�@�F�������ɃI�[�o�[���[�h�L
	******************************************************/
	bool CheckValidArgument(eSE _se);
	bool CheckValidArgument(eBGM _bgm);
	bool CheckValidArgument(eEVM _evm);

};


#endif // !_INCLUED_SOUND_
