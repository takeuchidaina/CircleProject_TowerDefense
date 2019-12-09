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
		E_SOUND_ENVIRONMENTAL,	//環境音
		E_SOUND_BGM,			//BGM
		E_SOUND_SE,				//SE
		E_VOL_LENGTH
	}eVolSetting;

	//SE
	typedef enum{
		E_SE_SELECT,	//決定
		E_SE_CANSEL,	//キャンセル
		E_SE_SWORD,		//剣士　攻撃
		E_SE_ARROW,		//弓　攻撃
		E_SE_BULLET,	//銃　攻撃
		E_SE_LENGTH,	//enumのサイズ
	}eSE;

	//BGM
	typedef enum{
		E_BGM_SEA,		//海
		E_BGM_TITLE,	//タイトル
		E_BGM_BATTLE,	//バトル
		E_BGM_WIN,		//リザルト　勝利
		E_BGM_LOSE,		//リザルト　敗北
		E_BGM_LENGTH,	//enumのサイズ
	}eBGM;

	//再生方法
	typedef enum {
		E_PLAY_NORMAL,	//ノーマル再生
		E_PLAY_BACK,	//バックグラウンド再生
		E_PLAY_LOOP		//ループ再生
	}ePlayType;

#pragma region 関数

	/*****************************************************
	名前　：void ChangeSoundVolume();
	概要　：
	引数　：
	戻り値：
	補足　
	******************************************************/
	void ChangeSoundVolume();

	/*****************************************************
	名前　：void PlaySE(eSE _se);
	概要　：効果音を再生
	引数　：eSE _se:鳴らしたい効果音
	戻り値：なし
	補足　：オーバーロード有
	******************************************************/
	void PlaySE(eSE _se);

	/*****************************************************
	名前　：void PlaySE(eSE _se);
	概要　：効果音を再生
	引数１：eSE _se:鳴らしたい効果音
	引数２：ePlayType _type:再生方法
	戻り値：なし
	補足　：オーバーロード有
	******************************************************/
	void PlaySE(eSE _se ,ePlayType _type);

	/*****************************************************
	名前　：void PlayBGM(eBGM _bgm);
	概要　：BGMを頭から再生
	引数　：eBGM _bgm:鳴らしたいBGM
	戻り値：なし
	補足　：オーバーロード有
	******************************************************/
	void PlayBGM(eBGM _bgm);

	/*****************************************************
	名前　：void PlayBGM(eBGM _bgm, ePlayType _type);
	概要　：BGMを頭から再生、再生方法を選択可能
	引数１：eBGM _bgm:鳴らしたい効果音
	引数２：ePlayType _type:再生方法
	戻り値：なし
	補足　：オーバーロード有
	******************************************************/
	void PlayBGM(eBGM _bgm, ePlayType _type);

	/*****************************************************
	名前　：void PlayBGM(eBGM _bgm, ePlayType _type, bool _topPos);
	概要　：
	引数１：eBGM _bgm:鳴らしたい効果音
	引数２：ePlayType _type:再生方法
	引数３：bool _topPos:(TRUE)頭から再生 (FALSE)前回の中断点から再生
	戻り値：なし
	補足　：オーバーロード有
	******************************************************/
	void PlayBGM(eBGM _bgm, ePlayType _type, bool _topPos);

	/*****************************************************
	名前　：void CheckSound(eSE _se);
	概要　：効果音が再生されているか調べる
	引数　：eSE _se:再生中か知りたい効果音
	戻り値：(TRUE)再生中　(FALSE)再生されていない
	補足　：オーバーロード有
	******************************************************/
	bool CheckSound(eSE _se);

	/*****************************************************
	名前　：void CheckSound(eBGM _bgm);
	概要　：BGMが再生されているか調べる
	引数　：eBGM _bgm:再生中か知りたいBGM
	戻り値：(TRUE)再生中　(FALSE)再生されていない
	補足　：オーバーロード有
	******************************************************/
	bool CheckSound(eBGM _bgm);

	/*****************************************************
	名前　：void StopSound(eSE _se);
	概要　：効果音を止める
	引数　：eSE _se:止めたい効果音
	戻り値：なし
	補足　：オーバーロード有
	******************************************************/
	void StopSound(eSE _se);

	/*****************************************************
	名前　：void StopSound(eBGM _bgm);
	概要　：BGMを止める
	引数　：eBGM _bgm:止めたいBGM
	戻り値：なし
	補足　：オーバーロード有
	******************************************************/
	void StopSound(eBGM _bgm);

#pragma endregion

private:
	string m_SEPath[E_SE_LENGTH];		//SEのファイルパス
	string m_BGMPath[E_BGM_LENGTH];		//BGMのファイルパス
	int m_SE[E_SE_LENGTH];				//SEのサウンドハンドル
	int m_BGM[E_BGM_LENGTH];			//BGMのサウンドハンドル

	/*****************************************************
	名前　：bool CheckValidArgument(eSE _se);
	概要　：SEの引数が存在するかを調べる
	引数　：eSE _se:調べたい値
	戻り値：(TRUE)有効範囲内　(FALSE)有効範囲外
	補足　：オーバーロード有
	******************************************************/
	bool CheckValidArgument(eSE _se);

	/*****************************************************
	名前　：bool CheckValidArgument(eBGM _bgm);
	概要　：BGMの引数が存在するかを調べる
	引数　：eBGM _bgm:調べたい値
	戻り値：(TRUE)有効範囲内　(FALSE)有効範囲外
	補足　：オーバーロード有
	******************************************************/
	bool CheckValidArgument(eBGM _bgm);



	int m_volume[E_VOL_LENGTH];

};


#endif // !_INCLUED_SOUND_
