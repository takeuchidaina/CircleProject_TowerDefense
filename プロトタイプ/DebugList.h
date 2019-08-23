#pragma once

#ifndef _INCLUED_DEBUGLIST_
#define _INCLUED_DEBUGLIST_

/********************************************************
●概要
　デバッグで表示されるものを管理します。
　リリース時にはこのファイルをインクルードしません。

●使い方
　各オブジェクトのデバッグは #ifdef を使用してください。
　#ifdef の名前をこのファイルに #define で定義します。
　
 ※ifdefについて
 　#ifdef デファインの名前
    デバッグ内容
　 #endif
  デファインの名前が定義されていないと
  読み込まれないという処理です。

*********************************************************/


/********************************************************
#define 一覧
命名規則：オブジェクト名_DEBUG
※アイウエオ順になるようにしてください
********************************************************/
#define FPS_DEBUG			// FPS
#define KEYBOARD_DEBUG		// キーボード
#define GAMEMGR_DEBUG		// ゲームマネージャー
#define SCENE_MGR_DEBUG		// シーンマネージャー
#define TITLE_DEBUG			// タイトル
#define MOUSE_DEBUG			// マウス
#define MAP_MGR_DEBUG		// マップマネージャー
#define MAP_DEBUG			// マップ
#define MENU_DEBUG			// メニュー
#define RESULT_DEBUG		// リザルト
#define UNIT_MGR_DEBUG		// ユニットマネージャー
#define UNIT_DEBUG			// ユニット

#endif // !_INCLUED_DEBUGLIST_