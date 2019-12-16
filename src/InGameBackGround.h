#pragma once
#ifndef _INCLUED_BG_
#define _INCLUED_BG_

#include "DxLib.h"
#include "BaseTask.h"
#include "ErrorCheck.h"

/********************************************************
œŠT—v
@ƒQ[ƒ€ƒV[ƒ“‚É‚¨‚¯‚é”wŒi‚Ì•`‰æ

œì¬Ò
@’|“à ‘å“Ş
********************************************************/

class cBackGround : public cBaseTask {

public:
	cBackGround();
	virtual ~cBackGround();

	virtual void Init();
	virtual void Update();
	virtual void Draw();
	virtual void End();

private:

	int m_ship;
	int m_BG;
	int m_wave;

	typedef struct {
		VECTOR pos;
		int image;
	}sBG;

	sBG m_cloud[2];
	const float CLOUD_SPEED = 0.25f;

	void MoveBackGround();
};

#endif // !_INCLUED_BG_

