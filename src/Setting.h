#pragma once

#ifndef _INCLUED_SETTING_
#define _INCLUED_SETTING_

#include "BaseTask.h"
#include <fstream>
#include "Log.h"
#include "Sound.h"
#include "Constant.h"
#include "Button.h"
using namespace std;

/**********************************************************
���T�v
�Q�[�����Ŏg�p���邠���鉹�ʂ����[�U�[�̓��͂����ɕύX����

���쐬��
�|�����
**********************************************************/

class cSetting : public cBaseTask
{
public:
	cSetting();
	virtual ~cSetting();

	virtual void Init();
	virtual void Update();
	virtual void Draw();
	virtual void End();

	//�ݒ荀�ڈꗗ
	typedef enum {
		E_VOL_EVM,		//����
		E_VOL_BGM,		//BGM
		E_VOL_SE,		//SE
		E_VOL_LENGTH
	}eVolSetting;

	//�{�^�����ڈꗗ ���ʂ𒲐߂�����͕̂ʂɂ���(m_volBtn)
	typedef enum {
		E_BTN_ENTER,	//����
		E_BTN_CANSEL,	//�L�����Z��
		E_BTN_APP,		//�K�p
		E_BTN_LENGTH
	}eButtonItem;

	/*****************************************************
	���O�@�Fbool GetEndSetting()
	�T�v�@�F�ݒ肪�ύX���I����Ă��邩�̃t���O��Ԃ�
	�����@�F�Ȃ�
	�߂�l�Fbool:m_setteingEnd
	******************************************************/
	bool GetEndSetting();
	/*****************************************************
	���O�@�Fbool StartSetting()
	�T�v�@�F�ݒ���J�n����A�t���O��ω�������
	�����@�F�Ȃ�
	�߂�l�F�Ȃ�
	******************************************************/
	void StartSetting();

private:

	/*****************************************************
	���O�@�Fvoid ChangeScene(eScene _nextScene)
	�T�v�@�F�t�@�C���։��ʂ���������
	�����@�F�Ȃ�
	�߂�l�F�Ȃ�
	******************************************************/
	void SoundSettingApp();

	int m_volume[E_VOL_LENGTH];		//�e���ʍ��ڂ̉��ʒl
	bool m_settingEnd;				//�ݒ肪�I��������ǂ�����GM���E���@TRUE:�I���@FALSE:�ݒ蒆
	const int FONT_SIZE = 30;		//�t�H���g�T�C�Y

	cButton m_btn[E_BTN_LENGTH];		//����E�߂�E�K�p�{�^��
	cButton m_volBtn[E_VOL_LENGTH][2];	//���ʂ𒲐߂���{�^��(�召)

};

#endif // !_INCLUED_SETTING_
