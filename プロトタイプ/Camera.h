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

	double m_zoom;							//�g�嗦
	const double ZOOM_LIMIT_UP = 719.5;		//�J�����̍ő�k���l 1280x720�����x�\�������
	const double ZOOM_LIMIT_DOWN = 300.0;	//�J�����̍ŏ��g��l
	const double ZOOM_SCALE = 100.0;		//�g��k���̈ړ��l
	int m_wheeled;							//�ߋ��̃z�C�[���̒l�̊i�[

#ifdef CAMERA_DEBUG
	int GrHandle;	//�f�o�b�O�p�摜�n���h��
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