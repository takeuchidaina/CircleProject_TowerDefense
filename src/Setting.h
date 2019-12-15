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

class cSetting : public cBaseTask
{
public:
	cSetting();
	virtual ~cSetting();

	virtual void Init();
	virtual void Update();
	virtual void Draw();
	virtual void End();

	typedef enum {
		E_VOL_EVM,		//����
		E_VOL_BGM,		//BGM
		E_VOL_SE,		//SE
		E_VOL_LENGTH
	}eVolSetting;

	typedef enum {
		E_BTN_ENTER,	//����
		E_BTN_CANSEL,	//�L�����Z��
		E_BTN_APP,		//�K�p
		E_BTN_LENGTH
	}eButtonItem;

	//�ݒ肪�I����Ă��邩�ǂ����̃t���O��Ԃ�
	bool GetEndSetting();

private:

	int m_volume[E_VOL_LENGTH];		//�e���ʍ��ڂ̉��ʒl
	const int FONT_SIZE = 30;		//�t�H���g�T�C�Y

	bool m_settingEnd;				//�ݒ肪�I��������ǂ�����GM���E���@TRUE:�I���@FALSE:�ݒ蒆

	cButton m_btn[E_BTN_LENGTH];		//����E�߂�E�K�p�{�^��
	cButton m_volBtn[E_VOL_LENGTH][2];	//���ʂ𒲐߂���{�^��(�召)

	//�ς������ʒl���t�@�C���֏�������
	void SoundSettingApp();

};

#endif // !_INCLUED_SETTING_
