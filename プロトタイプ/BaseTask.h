#pragma once
#include <iostream>

/**********************************************************
概要　：全てのオブジェクトが継承する抽象クラス
作成者：竹内大奈
**********************************************************/

#ifndef _INCLUDE_BASETASK_
#define _INCLUDE_BASETASK_

class cBaseTask
{
public:

	virtual ~cBaseTask();

	/*****************************************************
	名前　：Init()
	概要　：初期化を行う
	引数　：なし
	戻り値：なし
	詳細　：書いても書かなくてもよい
	******************************************************/
	virtual void Init() {}
	/*****************************************************
	名前　：Update()
	概要　：毎秒呼ばれ、計算処理を行う
	引数　：なし
	戻り値：なし
	詳細　：純粋仮想関数な為、必ず記述すること
	******************************************************/
	virtual void Update() = 0;
	/*****************************************************
	名前　：Draw()
	概要　：毎秒呼ばれ、描画処理を行う
	引数　：なし
	戻り値：なし
	詳細　：純粋仮想関数な為、必ず記述すること
	******************************************************/
	virtual void Draw() = 0;
	/*****************************************************
	名前　：End()
	概要　：終了処理を行う
	引数　：なし
	戻り値：なし
	詳細　：書いても書かなくてもよい
	　　　　メモリの開放などは必ず同一ファイル内で行うこと
	******************************************************/
	virtual void End() {}


private:
	// なし

};
#endif
