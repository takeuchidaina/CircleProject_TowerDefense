#pragma once

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

#define UNIT_WIDTH 32
#define UNIT_HEIGHT 40

/********************************************************
●概要
  共通定義用ヘッダーファイル
  他のファイル・クラスでも使うと思う変数定義をここで定義し、
  インクルードすれば使えるようにする。
  目的：サイズ等の変更を楽にすると同時にバグ原因の見落とし防止

●作成者
　髙井隆太郎

●更新日
　
********************************************************/

typedef enum
{
	eNone,		// なし


}eCondition;

typedef enum
{
	eSord,		// 剣士
	eArcher,		// 弓兵
}eUnitType;

typedef enum
{
	eIdle,		// 待機中
	eAttack,	// 攻撃中
	eMove,		// 移動中
}eState;