#pragma once

#include "DxLib.h"
#include "DebugList.h"
#include "ColorListh.h"
#include "BaseTask.h"
#include "Mouse.h"
#include "Keyboard.h"

class cButton : public cBaseTask {

public:
	cButton();
	~cButton();

	virtual void Init();
	virtual void Update();
	virtual void Draw();
	virtual void End();

	//�{�^���̐���
	//����:����(x,y),�E��(x,y),�{�^���̖��O,�For�摜
	//�ŏI�I�ɂ͉摜���\���ł���悤��

	//�{�^���������Ă��邩�ǂ���
	//����:�{�^���̖��O
	//Update�Ń}�E�X�N���b�N������Ă����疈�񓖂��蔻������
	//�������Ă�����t���O��true�ɂ���

	//�t���O��true��false�ŐF��ς���悤�ɂ���

private:

};