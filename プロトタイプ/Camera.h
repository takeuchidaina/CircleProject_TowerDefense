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
#pragma region 変数
	typedef struct {

		VECTOR pos;			//座標
		VECTOR target;		//注視点

	}sCameraInfo;

	sCameraInfo m_camera;	//座標・注視点の情報(x,y,z)

	//移動
	double m_wheelPosX;		//マウスホイールでクリックした場所 x
	double m_wheelPosY;		//マウスホイールでクリックした場所 y
	bool m_wheelClick;		//マウスホイールでクリックしているか　TRUE:している FALSE:していない

	//拡大縮小
	int m_wheeled;		//過去のマウスホイールの値の格納
	int m_zoomCnt;		//拡大をしている回数
	float m_zoom;		//カメラの距離
	const float ZOOM_LIMIT_UP = 719.5f;		//カメラの最大縮小値 1280x720が丁度表示される
	const float ZOOM_LIMIT_DOWN = 300.0f;	//カメラの最小拡大値
	const float ZOOM_SCALE = 100.0f;		//拡大縮小のカメラ移動値
	const float ZOOM_ADJUSTMENT = 11.0f;	//縮小のカメラ誤差調整用数値
#pragma endregion

#pragma region 関数
	/*****************************************************
	名前　：void CameraScale();
	概要　：拡大縮小を行う
	引数　：なし
	戻り値：なし
	******************************************************/
	void CameraScale();
	/*****************************************************
	名前　：void CameraMove();
	概要　：カメラの移動量を計算し移動させる
	引数　：なし
	戻り値：なし
	詳細　：マウスホイールが押された座標と離された座標の
			計算結果をCameraMoveX,Y関数に渡し移動します
	******************************************************/
	void CameraMove();
	/*****************************************************
	名前　：void CameraMoveX(float _moveAmount);
	概要　：引数を元にカメラの座標xと注視点xを移動させる
	引数　：float 移動させたい量
	戻り値：なし
	******************************************************/
	void CameraMoveX(float _moveAmount);
	/*****************************************************
	名前　：void CameraMoveY(float _moveAmount);
	概要　：引数を元にカメラの座標yと注視点yを移動させる
	引数　：float 移動させたい量
	戻り値：なし
	******************************************************/
	void CameraMoveY(float _moveAmount);
	/*****************************************************
	名前　：void CameraDrawControl();
	概要　：カメラが背景外を描写しないようにする
	引数　：なし
	戻り値：なし
	詳細　：座標と注視点が一定の値を超えた際に
	 　　　 それらを一定の値に変更します
	******************************************************/
	void CameraDrawControl();
#pragma endregion

};

#endif // !_INCLUED_CAMERA_