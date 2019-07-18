#pragma once
#include <iostream>
#include "DxLib.h"
#include "DebugList.h"
#include "Singleton.h"

class cMouse : public cSingleton<cMouse> {

	cMouse();
	virtual ~cMouse();
	friend cSingleton< cMouse >;

public:
	static constexpr int LEFT_CLICK = 0;
	static constexpr int RIGHT_CLICK = 1;

	virtual void Update();
	virtual void Draw();

	int GetPressCnt(int keyCode);//keyCode�̃L�[��������Ă���t���[�������擾
	int GetReleaseCnt(int keyCode);//keyCode�̃L�[��������Ă���t���[�������擾
	int GetX() { return x; }
	int GetY() { return y; }

private:
	static constexpr int KEY_NUM = 8;	//�L�[����
	int x, y;
	int buttonPressCnt[KEY_NUM];	//������J�E���^
	int buttonReleaseCnt[KEY_NUM];	//������J�E���^

	bool isAvailableCode(int keyCode);//keyCode���L���ȃL�[�ԍ����₤

};