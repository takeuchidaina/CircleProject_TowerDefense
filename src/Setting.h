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
●概要
ゲーム内で使用するあらゆる音量をユーザーの入力を元に変更する

●作成者
竹内大奈
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

	//設定項目一覧
	typedef enum {
		E_VOL_EVM,		//環境音
		E_VOL_BGM,		//BGM
		E_VOL_SE,		//SE
		E_VOL_LENGTH
	}eVolSetting;

	//ボタン項目一覧 音量を調節するものは別にあり(m_volBtn)
	typedef enum {
		E_BTN_ENTER,	//決定
		E_BTN_CANSEL,	//キャンセル
		E_BTN_APP,		//適用
		E_BTN_LENGTH
	}eButtonItem;

	/*****************************************************
	名前　：bool GetEndSetting()
	概要　：設定が変更し終わっているかのフラグを返す
	引数　：なし
	戻り値：bool:m_setteingEnd
	******************************************************/
	bool GetEndSetting();
	/*****************************************************
	名前　：bool StartSetting()
	概要　：設定を開始する、フラグを変化させる
	引数　：なし
	戻り値：なし
	******************************************************/
	void StartSetting();

private:

	/*****************************************************
	名前　：void ChangeScene(eScene _nextScene)
	概要　：ファイルへ音量を書き込む
	引数　：なし
	戻り値：なし
	******************************************************/
	void SoundSettingApp();

	int m_volume[E_VOL_LENGTH];		//各音量項目の音量値
	bool m_settingEnd;				//設定が終わったかどうかをGMが拾う　TRUE:終了　FALSE:設定中
	const int FONT_SIZE = 30;		//フォントサイズ

	cButton m_btn[E_BTN_LENGTH];		//決定・戻る・適用ボタン
	cButton m_volBtn[E_VOL_LENGTH][2];	//音量を調節するボタン(大小)

};

#endif // !_INCLUED_SETTING_
