#pragma once
#include "DxLib.h"
#include <vector>

#ifndef _CONSTANT_INCLUDE_
#define _CONSTANT_INCLUDE_

/********************************************************
●概要
  共通定義用ヘッダーファイル
  他のファイル・クラスでも使うと思う変数定義をここで定義し、
  インクルードすれば使えるようにする。
  目的：サイズ等の変更を楽にすると同時にバグ原因の見落とし防止

●作成者
　髙井隆太郎

********************************************************/

/********************************************************

	マクロ

********************************************************/

#define WINDOW_WIDTH 1280	// Window幅
#define WINDOW_HEIGHT 720	// Window高さ

#define UNIT_WIDTH 64		// ユニット幅
#define UNIT_HEIGHT 64		// ユニット高さ

#define U_RIGHT 1			// 右向き
#define U_LEFT -1			// 左向き

/********************************************************

	列挙型

********************************************************/

// ユニットの体調
typedef enum{

	E_NONE		// 元気！！


}eCondition;

// ユニットのタイプ
typedef enum{

	E_SORD,		// 剣士
	E_ARCHAR,	// 銃兵
	E_DEFENSE,	// 盾
	E_ESCORT	// 護衛対象
}eUnitType;

// ユニットの状態
typedef enum{

	E_IDLE,		// 待機中
	E_ATTACK,	// 攻撃中
	E_MOVE		// 移動中
}eState;

/********************************************************

	構造体

********************************************************/

// 次の移動先設定用
typedef struct{

	int sNextRoom;	// 部屋番号
	double sNextX;	// x座標
}sNextMove;

// マップデータの受け渡し用
typedef struct{

	VECTOR pos;		// 座標
	double width;	// 幅
	double height;	// 高さ
	int roomSize;	// ユニットが入れる数
}sMapData;

// ユニットのタイプ別の数受け渡し用
typedef struct{

	int sord;		// 剣士
	int archar;		// 銃兵
	int defense;	// 盾
}sTypeCnt;

// プレイヤーユニットの数データ受け渡し用
typedef struct{

	sTypeCnt typeCnt;	// タイプ別
	int maxPlayer;		// 最大数
	int playerCnt;		// 全体数
}sUnitData;

// ユニット生成用
typedef struct{

	int unitID;			// 生成するユニットID
	int mapID;			// 生成する場所のID
}sUnitGene;

#endif // !_CONSTANT_INCLUDE_