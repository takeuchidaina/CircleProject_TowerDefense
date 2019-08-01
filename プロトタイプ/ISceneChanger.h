#pragma once

/**********************************************************
●概要
シーン管理をするクラスが継承し、
シーン変更をする際に呼び出すインターフェースクラス
参考URL:https://dixq.net/g/sp_06.html

●作成者
竹内大奈

●更新日
2019/08/01 作成
**********************************************************/

#ifndef _INCLUDE_ISCENECHANGER_
#define _INCLUDE_ISCENECHANGER_

// シーンの定数
typedef enum {
	E_SCENE_TITLE,		// タイトル
	E_SCENE_MENU,		// メニュー
	E_SCENE_GAME,		// ゲーム
	E_SCENE_RISULT,		// リザルト
	E_SCENE_NONE,		// 無し

}eScene;

class ISceneChanger
{
public:
	virtual ~ISceneChanger() = 0;
	virtual void ChangeScene(eScene _nextScene) = 0;
private:

};


#endif // !_INCLUDE_ISCENECHANGER_

