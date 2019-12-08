#pragma once

#ifndef _INCLUED_SETTING_
#define _INCLUED_SETTING_

#include "BaseTask.h"
#include <fstream>
#include "Log.h"
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

private:

	typedef enum {
		E_SOUND_ENVIRONMENTAL,	//����
		E_SOUND_BGM,			//BGM
		E_SOUND_SE,				//SE
		E_VOL_LENGTH
	}eVolSetting;

	int m_volume[E_VOL_LENGTH];

	int m_select;

};

#endif // !_INCLUED_SETTING_
