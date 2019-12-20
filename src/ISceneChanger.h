#pragma once

#include <iostream>
/**********************************************************
●概要
シーン管理をするクラスが継承し、
シーン変更をする際に呼び出すインターフェースクラス

●作成者
竹内大奈
**********************************************************/

#ifndef _INCLUDE_ISCENECHANGER_
#define _INCLUDE_ISCENECHANGER_

// シーンの定数
typedef enum {
	E_SCENE_TITLE,			// タイトル
	E_SCENE_MENU,			// メニュー
	E_SCENE_STAGESELECT,	// ステージ選択
	E_SCENE_UNITSELECT,		// ユニット選択
	E_SCENE_GAME,			// ゲーム
	E_SCENE_RESULT,			// リザルト
	E_SCENE_END,
	E_SCENE_NONE,			// 無し

}eScene;

class ISceneChanger
{
public:
	virtual ~ISceneChanger() = 0;

	/*****************************************************
	名前　：void ChangeScene(eScene _nextScene)
	概要　：シーンを引数のシーンに変更する
	引数　：eScene _nextScene:変更したいシーン
	戻り値：なし
	補足　：抽象クラス　記入必須
	******************************************************/
	virtual void ChangeScene(eScene _nextScene) = 0;
private:

};


#endif // !_INCLUDE_ISCENECHANGER_

