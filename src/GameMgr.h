#pragma once
#ifndef _INCLUDE_GAMEMGR_
#define _INCLUDE_GAMEMGR_

#include "DxLib.h"
#include "DebugList.h"
#include "ColorListh.h"
#include "Constant.h"
#include "BaseScene.h"
#include "BaseTask.h"
#include "ISceneChanger.h"
#include "Mouse.h"
#include "Keyboard.h"
#include "FPS.h"
#include "Camera.h"
#include "UnitMgr.h"
#include "MapMgr.h"
#include "Map.h"
#include "TimeLimit.h"
#include "Sound.h"
#include "ErrorCheck.h"
#include "UI.h"
#include "Setting.h"
#include "MapNavigate.h"
#include "InGameBackGround.h"
#include <time.h>
#include "Button.h"

/********************************************************
●概要
　ゲーム画面
 　戦闘を行う

●作成者
　竹内 大奈
********************************************************/

#define SPAWN_COOLTIME_MAX 200    //  Randで0~150
#define SPAWN_COOLTIME_MIN 250    //  MOVE_COOLTIME_MAXに固定+100

class cGameMgr : public cBaseScene{

public:
	cGameMgr(ISceneChanger* _scene);

	void Init()override;
	void Update()override;
	void Draw()override;
	void End()override;

	//GM内ステート
	typedef enum {
		E_PREPARATION,	//戦闘準備
		E_BATTLE,		//戦闘
		E_EVENT,		//イベント
		E_CUTSCENE,		//カットシーン
		E_POSE,			//ポーズ
	}eGameState;

	void Set_GameState(eGameState _state);
	
private:

	eGameState m_gameState;		//現在のステート
	eGameState m_stateHistory;	//前回のステートを保存する

	//各種クラス実態宣言
	cCamera m_camera;				//カメラ
	cMapMgr m_mapMgr;				//マップ
	cTime m_time;					//時間制限
	cUI m_UI;						//UI
	cUnitMgr m_unitMgr;				//ユニット
	cMapNavigate m_mapNavigate;		//敵AI
	cBackGround m_BG;				//背景

	const int m_maxPlayer = 15;		//ユニット生成上限		TODO:MAPから情報を受け取る
	int m_PlayerCnt;				//ユニット出現数		TODO:UnitMgrから情報を受け取る
	sTypeCnt m_unitCnt;				//タイプ別のユニット数	TODO:UnitMgrから情報を受け取る

	int m_spawnCnt = 0;			// 一定数まで行ったら敵ユニット生成		TODO:UnitMgrに管理させる
	int m_spawnType = 0;		// 一定数まで行ったら敵ユニット移動		TODO:UnitMgrに管理させる
	int m_spawnCoolTime = 0;	// m_spawnCntの最大数こきめる

	const int TIME_LIMIT_WAIT = 10;
	const int TIME_LIMIT_GAME = 61;	//時間制限	TODO:MAPから情報を受け取る

	/*****************************************************
	名前　：void EscortDamageCalc();
	概要　：護衛対象のHPを元に敗北判定を行う
	引数　：なし
	戻り値：なし
	******************************************************/
	void EscortDamageCalc();
	/*****************************************************
	名前　：void DefSuccessJudge();
	概要　：制限時間を元に勝利判定を行う
	引数　：なし
	戻り値：なし
	******************************************************/
	void DefSuccessJudge();
	/*****************************************************
	名前　：void EnemyExtermination();
	概要　：敵を一定数倒したら勝利
	引数　：なし
	戻り値：なし
	******************************************************/
	void EnemyExtermination();
	/*****************************************************
	名前　：void PlayerGenerate();
	概要　：プレイヤーユニットの生成
	引数　：なし
	戻り値：なし
	******************************************************/
	void PlayerGenerate();
	/*****************************************************
	名前　：void EnemyGenerate();
	概要　：敵ユニットの生成
	引数　：なし
	戻り値：なし
	******************************************************/
	void EnemyGenerate();
	/*****************************************************
	名前　：void UnitData();
	概要　：UIにプレイヤーのユニット情報(出現数等)を渡す
	引数　：ファイルを入れた変数
	戻り値：なし
	******************************************************/
	void UnitData();
	/*****************************************************
	名前　：void ResultSave(bool _result);
	概要　：ファイルに勝敗結果を書き出す
	引数　：bool _result : 勝敗結果　(TRUE)勝利 (FALSE)敗北
	戻り値：なし
	******************************************************/
	void ResultSave(bool _result);

};

#endif // !_INCLUDE_GAMEMGR_
