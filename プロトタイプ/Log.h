#pragma once
#include "DxLib.h"
#include "Singleton.h"
#include <vector>
#include <string>
#include "ColorListh.h"
#include "Constant.h"
#include <stdarg.h>
#include "Keyboard.h"

using namespace std;

#define DEBUG_LOG(_format, ...) cLog::Instance()->DebugLog(_format, __VA_ARGS__);

/********************************************************
●概要
　Log表示クラス
 ・使い方
	例) DEBUG_LOG("田島が魔剤を飲んだ");

●作成者
　髙井隆太郎

●更新日
  10/10 作成
　
********************************************************/
class cLog : public cSingleton<cLog>
{
public:
	cLog();
	~cLog();
	friend cSingleton<cLog>;

private:
	double m_x, m_y;
	vector<string> m_message;
	int m_maxLogs;
	int m_count;

	const int m_fontSize = 15;

public:
	void Update();
	void Draw();

	/*********************************************************************
	関数名：void DebugLog(const char* _format, ...)
	概要：書式付きログ
			使い方はprintfと同じ
	引数：_format:表示させたい文字列, ...表示させる数値
	戻り値：なし
	*********************************************************************/
	void DebugLog(const char* _format, ...);
};