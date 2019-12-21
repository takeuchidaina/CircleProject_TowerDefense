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
●概要
音楽ファイルを格納し再生や停止を行う
シングルトン化されているのでどこの
クラスからでも呼び出すことが可能

●作成者
竹内大奈
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

	//音量の設定項目
	typedef enum {
		E_VOL_EVM,		//環境音
		E_VOL_BGM,		//BGM
		E_VOL_SE,		//SE
		E_VOL_LENGTH
	}eVolSetting;

	//SE
	typedef enum{
		E_SE_SELECT,	//決定
		E_SE_CANSEL,	//キャンセル
		E_SE_SWORD,		//剣　攻撃
		E_SE_SHEILD,	//盾　防御
		E_SE_BULLET,	//銃　攻撃
		E_SE_WIN,		//ME 勝ち
		E_SE_LOSE,		//ME 負け
		E_SE_LENGTH
	}eSE;

	//BGM
	typedef enum{
		E_BGM_TITLE,	//タイトル
		E_BGM_PREPARATION,	//バトル　待機
		E_BGM_BATTLE,	//バトル　戦闘
		E_BGM_WIN,		//リザルト　勝利
		E_BGM_LOSE,		//リザルト　敗北
		E_BGM_LENGTH
	}eBGM;

	//EVM	(environment:環境)
	typedef enum {
		E_EVM_SEA_ROUGH,	//荒波
		E_EVM_SEA_RIPPLES,	//さざ波
		E_EVM_LENGTH
	}eEVM;

	//再生方法
	typedef enum {
		E_PLAY_NORMAL,	//ノーマル再生
		E_PLAY_BACK,	//バックグラウンド再生
		E_PLAY_LOOP		//ループ再生
	}ePlayType;

#pragma region 関数

	/*****************************************************
	名前　：void ChangeSoundVolume();
	概要　：音量値の変更を反映する
	引数　：なし
	戻り値：なし
	補足　：値はファイルから読み取る
	******************************************************/
	void ChangeSoundVolume();

	/*****************************************************
	名前　：void PlaySE(eSE _se);
	概要　：効果音を再生
	引数１：eSE _se:鳴らしたい効果音
	引数２：ePlayType _type:再生方法
	戻り値：なし
	補足　：引数１に引数２を追加する形でオーバーロード有
	******************************************************/
	void PlaySE(eSE _se);
	void PlaySE(eSE _se, ePlayType _type);

	/*****************************************************
	名前　：void PlayBGM(eBGM _bgm);
	概要　：BGMを再生
	引数１：eBGM _bgm:再生したいBGM
	引数２：ePlayType _type:再生方法
	引数３：bool _topPos:(TRUE)頭から再生 (FALSE)前回の中断点から再生
	戻り値：なし
	補足　：引数１に引数２,３を追加する形でオーバーロード有
	******************************************************/
	void PlayBGM(eBGM _bgm);
	void PlayBGM(eBGM _bgm, ePlayType _type);
	void PlayBGM(eBGM _bgm, ePlayType _type, bool _topPos);

	/*****************************************************
	名前　：void PlayEVM(eEVM _evm);
	概要　：EVMを再生
	引数１：eEVM _evm:再生したいEVM
	引数２：ePlayType _type:再生方法
	引数３：bool _topPos:(TRUE)頭から再生 (FALSE)前回の中断点から再生
	戻り値：なし
	補足　：引数１に引数２,３を追加する形でオーバーロード有
	******************************************************/
	void PlayEVM(eEVM _evm);
	void PlayEVM(eEVM _evm, ePlayType _type);
	void PlayEVM(eEVM _evm, ePlayType _type, bool _topPos);

	/*****************************************************
	名前　：void CheckSound(eSE _se);
	概要　：音が再生されているか調べる
	引数１：eSE _se:再生中か知りたいSE
	引数１：eBGM _bgm:再生中か知りたいBGM
	引数１：eEVM _evm:再生中か知りたいEVM
	戻り値：(TRUE)再生中　(FALSE)再生されていない
	補足　：引数毎にオーバーロード有
	******************************************************/
	bool CheckSound(eSE _se);
	bool CheckSound(eBGM _bgm);
	bool CheckSound(eEVM _evm);

	/*****************************************************
	名前　：void StopSound(eSE _se);
	概要　：効果音を止める
	引数１：eSE _se:止めたいSE
	引数１：eBGM _bgm:止めたいBGM
	引数１：eEVM _evm:止めたいEVM
	戻り値：なし
	補足　：引数毎にオーバーロード有
	******************************************************/
	void StopSound(eSE _se);
	void StopSound(eBGM _bgm);
	void StopSound(eEVM _evm);

#pragma endregion

private:
	string m_SEPath[E_SE_LENGTH];		//SEのファイルパス
	string m_BGMPath[E_BGM_LENGTH];		//BGMのファイルパス
	string m_EVMPath[E_EVM_LENGTH];		//EVMのファイルパス
	int m_SE[E_SE_LENGTH];				//SEのサウンドハンドル
	int m_BGM[E_BGM_LENGTH];			//BGMのサウンドハンドル
	int m_EVM[E_EVM_LENGTH];			//EVMのサウンドハンドル

	int m_volume[E_VOL_LENGTH];			//各項目の音量値

	/*****************************************************
	名前　：bool CheckValidArgument(eSE _se);
	概要　：SEの引数が存在するかを調べる
	引数１：eSE _se:調べたい値
	引数１：eBGM _bgm:調べたい値
	引数１：eEVM _evm:調べたい値
	戻り値：(TRUE)有効範囲内　(FALSE)有効範囲外
	補足　：引数毎にオーバーロード有
	******************************************************/
	bool CheckValidArgument(eSE _se);
	bool CheckValidArgument(eBGM _bgm);
	bool CheckValidArgument(eEVM _evm);

};


#endif // !_INCLUED_SOUND_
