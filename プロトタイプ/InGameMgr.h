#pragma once
#include "Singleton.h"
#include "UnitMgr.h"
#include "Map.h"
#include "Mouse.h"
#include "Constant.h"

#ifndef _INCLUDE_INGAME_MGR_
#define _INCLUDE_INGAME_MGR_

/********************************************************
���T�v
  �Q�[���V�[���S��
  �C���N���[�h�V�[��
  �E�퓬�}�l�[�W���[
  �E���G�V�[��
  �E�C�x���g�V�[��
  �E���̓��V�[��

���쐬��
�@���䗲���Y

���X�V��
  
********************************************************/

class cInGameMgr : public cSingleton <cInGameMgr>
{
	cInGameMgr() {}
	friend cSingleton <cInGameMgr>;

	cUnitMgr unit;
	cMap map;

public:
	void Update()
	{
		map.Update();

		if (cMouse::Instance()->GetReleaseCnt(0) == 1)
		{
			if (true == map.CheckInto(cMouse::Instance()->GetX(), cMouse::Instance()->GetY()))
			{
				unit.Add_PSord(cMouse::Instance()->GetX(), map.Get_Ground() - UNIT_HEIGHT);
			}
		}

		unit.Update();
	}

	void Draw()
	{
		map.Draw();
		unit.Draw();
	}
};
#endif // !_INCLUDE_INGAME_MGR_