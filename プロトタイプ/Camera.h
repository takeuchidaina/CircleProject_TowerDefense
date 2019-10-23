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

	double m_zoom;							//拡大率
	const double ZOOM_LIMIT_UP = 719.5;		//カメラの最大縮小値 1280x720が丁度表示される
	const double ZOOM_LIMIT_DOWN = 300.0;	//カメラの最小拡大値
	const double ZOOM_SCALE = 100.0;		//拡大縮小の移動値
	int m_wheeled;							//過去のホイールの値の格納

#ifdef CAMERA_DEBUG
	int GrHandle;	//デバッグ用画像ハンドル
#endif // !CAMERA_DEBUG



private:
	typedef struct {

		VECTOR pos;
		VECTOR target;
		VECTOR scale;

	}sCameraInfo;

	double m_wheelPosX;
	double m_wheelPosY;
	bool m_wheelClick;

	sCameraInfo m_camera;
};

#endif // !_INCLUED_CAMERA_