#pragma once
#ifndef _INCLUED_SOUND_
#define _INCLUED_SOUND_
#include "DxLib.h"
#include <iostream>
#include "BaseTask.h"
#include "ErrorCheck.h"
#include "Keyboard.h"
#include "string.h"

using namespace std;

class cSound : cBaseTask
{
public:
	cSound();
	virtual ~cSound();

	virtual void Init();
	virtual void Update();
	virtual void Draw();
	virtual void End();

	typedef enum{
		E_SELECT,
		E_CANSEL,
		E_BLADE,
		E_SE_LENGTH,
	}SE;

	typedef enum{
		E_SEA,
		E_TITLE,
		E_BATTLE,
		E_WIN,
		E_LOSE,
		E_BGM_LENGTH
	}BGM;

private:
	string m_SEPath[E_SE_LENGTH];
	string m_BGMPath[E_BGM_LENGTH];
	int m_SEList[E_SE_LENGTH];
	int m_BGMList[E_BGM_LENGTH];

};


#endif // !_INCLUED_SOUND_
