#pragma once

#ifndef _INCLUED_SETTING_
#define _INCLUED_SETTING_

#include "BaseTask.h"
#include <fstream>
#include "Log.h"
#include "Sound.h"
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
		E_SOUND_ENVIRONMENTAL,	//ŠÂ‹«‰¹
		E_SOUND_BGM,			//BGM
		E_SOUND_SE,				//SE
		E_VOL_LENGTH
	}eVolSetting;

private:

	int m_volume[E_VOL_LENGTH];

	int m_select;

};

#endif // !_INCLUED_SETTING_
