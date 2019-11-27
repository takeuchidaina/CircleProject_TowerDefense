#pragma once

#ifndef _INCLUED_UI_
#define _INCLUED_UI_

#include "DxLib.h"
#include "BaseTask.h"

class cUI : public cBaseTask
{
public:
	cUI();
	virtual ~cUI();
	virtual void Init();
	virtual void Update();
	virtual void Draw();
	virtual void End();

private:

};



#endif // !_INCLUED_UI_

