#pragma once
#include "BaseTask.h"
#include "BaseUnit.h"

#ifndef _INCLUED_ESCORTTARGET_
#define _INCLUED_ESCORTTARGET_

class cEscortTarget : public cBaseUnit,cBaseTask
{
public:
	cEscortTarget();
	~cEscortTarget();

	virtual void Init();
	virtual void Update();
	virtual void Draw();
	virtual void End();

private:

};
#endif //_INCLUED_ESCORTTARGET_
