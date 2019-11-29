#pragma once

#ifndef _INCLUED_UI_
#define _INCLUED_UI_

#include "DxLib.h"
#include <iostream>
#include "BaseTask.h"
#include "string.h"
#include "ErrorCheck.h"
#include "Map.h"

using namespace std;

class cUI : public cBaseTask
{
public:
	cUI();
	virtual ~cUI();

	virtual void Init();
	virtual void Update();
	virtual void Draw();
	virtual void End();

	void SetPlayerCount(int _type);

private:

	typedef enum {
		E_BG_SORD,
		E_BG_ARCHER,
		E_BG_SHIELD,
		E_BG_SUM,
		E_CHAR_SORD,
		E_CHAR_ARCHER,
		E_CHAR_SHIELD,
		E_UI_LENGTH
	}eUI;

	typedef struct {
		float ux, uy,dx,dy;
		string path;
		int image;
	}sUI;

	sUI m_UI[E_UI_LENGTH];
	int m_playerCnt[3];
	int m_sumPlayerCnt;
	int m_maxPlayer;

};



#endif // !_INCLUED_UI_

