#pragma once
#ifndef _INCLUED_CAMERA_
#define _INCLUED_CAMERA_

#include "DxLib.h"
#include "DebugList.h"
#include "ColorListh.h"
#include "BaseTask.h"
#include "Mouse.h"
#include "Keyboard.h"
#include "Constant.h"

class cCamera : public cBaseTask
{
public:
	cCamera();
	~cCamera();

	virtual void Init();
	virtual void Update();
	virtual void Draw();
	virtual void End();

private:
#pragma region �ϐ�
	typedef struct {

		VECTOR pos;			//���W
		VECTOR target;		//�����_

	}sCameraInfo;

	sCameraInfo m_camera;	//���W�E�����_�̏��(x,y,z)

	//�ړ�
	double m_wheelPosX;		//�}�E�X�z�C�[���ŃN���b�N�����ꏊ x
	double m_wheelPosY;		//�}�E�X�z�C�[���ŃN���b�N�����ꏊ y
	bool m_wheelClick;		//�}�E�X�z�C�[���ŃN���b�N���Ă��邩�@TRUE:���Ă��� FALSE:���Ă��Ȃ�

	//�g��k��
	int m_wheeled;		//�ߋ��̃}�E�X�z�C�[���̒l�̊i�[
	int m_zoomCnt;		//�g������Ă����
	float m_zoom;		//�J�����̋���
	const float ZOOM_LIMIT_UP = 719.5f;		//�J�����̍ő�k���l 1280x720�����x�\�������
	const float ZOOM_LIMIT_DOWN = 300.0f;	//�J�����̍ŏ��g��l
	const float ZOOM_SCALE = 100.0f;		//�g��k���̃J�����ړ��l
	const float ZOOM_ADJUSTMENT = 11.0f;	//�k���̃J�����덷�����p���l
#pragma endregion

#pragma region �֐�
	/*****************************************************
	���O�@�Fvoid CameraScale();
	�T�v�@�F�g��k�����s��
	�����@�F�Ȃ�
	�߂�l�F�Ȃ�
	******************************************************/
	void CameraScale();
	/*****************************************************
	���O�@�Fvoid CameraMove();
	�T�v�@�F�J�����̈ړ��ʂ��v�Z���ړ�������
	�����@�F�Ȃ�
	�߂�l�F�Ȃ�
	�ڍׁ@�F�}�E�X�z�C�[���������ꂽ���W�Ɨ����ꂽ���W��
			�v�Z���ʂ�CameraMoveX,Y�֐��ɓn���ړ����܂�
	******************************************************/
	void CameraMove();
	/*****************************************************
	���O�@�Fvoid CameraMoveX(float _moveAmount);
	�T�v�@�F���������ɃJ�����̍��Wx�ƒ����_x���ړ�������
	�����@�Ffloat �ړ�����������
	�߂�l�F�Ȃ�
	******************************************************/
	void CameraMoveX(float _moveAmount);
	/*****************************************************
	���O�@�Fvoid CameraMoveY(float _moveAmount);
	�T�v�@�F���������ɃJ�����̍��Wy�ƒ����_y���ړ�������
	�����@�Ffloat �ړ�����������
	�߂�l�F�Ȃ�
	******************************************************/
	void CameraMoveY(float _moveAmount);
	/*****************************************************
	���O�@�Fvoid CameraDrawControl();
	�T�v�@�F�J�������w�i�O��`�ʂ��Ȃ��悤�ɂ���
	�����@�F�Ȃ�
	�߂�l�F�Ȃ�
	�ڍׁ@�F���W�ƒ����_�����̒l�𒴂����ۂ�
	 �@�@�@ ���������̒l�ɕύX���܂�
	******************************************************/
	void CameraDrawControl();
#pragma endregion

};

#endif // !_INCLUED_CAMERA_