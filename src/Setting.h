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
		E_VOL_EVM,		//環境音
		E_VOL_BGM,		//BGM
		E_VOL_SE,		//SE
		E_VOL_LENGTH
	}eVolSetting;

	typedef enum {
		E_BTN_ENTER,	//決定
		E_BTN_CANSEL,	//キャンセル
		E_BTN_APP,		//適用
		E_BTN_LENGTH
	}eButtonItem;

	//設定が終わっているかどうかのフラグを返す
	bool GetEndSetting();

private:

	int m_volume[E_VOL_LENGTH];		//各音量項目の音量値
	const int FONT_SIZE = 30;		//フォントサイズ

	bool m_settingEnd;				//設定が終わったかどうかをGMが拾う　TRUE:終了　FALSE:設定中

	cButton m_btn[E_BTN_LENGTH];		//決定・戻る・適用ボタン
	cButton m_volBtn[E_VOL_LENGTH][2];	//音量を調節するボタン(大小)

	//変えた音量値をファイルへ書き込む
	void SoundSettingApp();

};

#endif // !_INCLUED_SETTING_
