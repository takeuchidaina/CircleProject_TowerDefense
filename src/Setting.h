#pragma once

#ifndef _INCLUED_SETTING_
#define _INCLUED_SETTING_

#include "BaseTask.h"

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

};

#endif // !_INCLUED_SETTING_
