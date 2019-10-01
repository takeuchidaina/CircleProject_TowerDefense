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

	//ボタンの生成
	//引数:左上(x,y),右下(x,y),ボタンの名前,色or画像
	//最終的には画像も表示できるように

	//ボタンを押しているかどうか
	//引数:ボタンの名前
	//Updateでマウスクリックがされていたら毎回当たり判定を取る
	//当たっていたらフラグをtrueにする

	//フラグがtrueかfalseで色を変えるようにする

private:

};