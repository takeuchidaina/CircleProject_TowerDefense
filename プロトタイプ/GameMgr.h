#pragma once

#include "DxLib.h"
#include "DebugList.h"
#include "ColorListh.h"
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
//#include "EscortTarget.h"
#include "TimeLimit.h"
#include "Sound.h"
//#include "Result.h"
#include "ErrorCheck.h"
#include "UI.h"

#ifndef _INCLUDE_GAMEMGR_
#define _INCLUDE_GAMEMGR_

#define SPAWN_CNT 400
#define MOVE_CNT 100

class cGameMgr : public cBaseScene{

public:
	cGameMgr(ISceneChanger* _scene);

	void Init()override;
	void Update()override;
	void Draw()override;
	void End()override;
	
private:

	void EscortDamageCalc();
	void DefSuccessJudge();

	cFPS m_fps;
	cCamera m_camera;
	cMapMgr m_mapMgr;
	//cEscortTarget m_escort;
	cTime m_time;
	cUI m_UI;

	cUnitMgr m_unitMgr;
	void UnitGenerate();
	void UnitData();

	int m_img;
	const int TIME_LIMIT = 120;
	int SpawnCnt = 0;			// ��萔�܂ōs������X�|�[��
	int SpawnType = 0;			// �X�|�[������^�C�v�����߂郉���_��
	int MoveCnt = 0;			// ��萔�܂ōs������ړ�
	int MoveType = 0;			// move����Type�����߂郉���_��

	int m_maxPlayer;			// Unit�����R�X�g
	int m_PlayerCnt;			// PlayerUnit�S�̂̃J�E���g
	sTypeCnt m_unitCnt;			// �^�C�v�ʂ̐�

};

#endif // !_INCLUDE_GAMEMGR_
