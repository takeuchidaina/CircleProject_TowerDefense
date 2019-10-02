#pragma once

#include "DxLib.h"
#include "DebugList.h"
#include "ColorListh.h"
#include "BaseTask.h"
#include "Mouse.h"
#include "Keyboard.h"

#ifndef _INCLUED_CAMERA_
#define _INCLUED_CAMERA_


class cCamera : public cBaseTask
{
public:
	cCamera();
	~cCamera();

	virtual void Init();
	virtual void Update();
	virtual void Draw();
	virtual void End();

	//MATRIX GetMatrix();
	//void Move();
	int ModelHandle;

private:
	typedef struct {

		VECTOR pos;
		VECTOR target;
		VECTOR scale;

	}sCameraInfo;

	sCameraInfo m_camera;
	VECTOR m_speed;
};

#endif // !_INCLUED_CAMERA_