#pragma once
#ifndef _INCLUED_SOUND_
#define _INCLUED_SOUND_
#include "DxLib.h"
#include "BaseTask.h"
#include "ErrorCheck.h"

class cSound : cBaseTask
{
public:
	cSound();
	virtual ~cSound();

	virtual void Init();
	virtual void Update();
	virtual void Draw();
	virtual void End();

private:

};


#endif // !_INCLUED_SOUND_
