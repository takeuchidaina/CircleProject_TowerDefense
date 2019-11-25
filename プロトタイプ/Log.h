#pragma once
#include "DxLib.h"
#include "Singleton.h"
#include <vector>
#include <string>
#include "ColorListh.h"
#include "Constant.h"
#include <stdarg.h>

using namespace std;

#define DEBUG_LOG(_message) cLog::Instance()->DebugLog(_message);

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

public:
	void Update();
	void Draw();

	/*********************************************************************
	関数名：void DebugLog(string)
	概要：デバッグログを表示

	引数：_message:表示させたいログ
	戻り値：なし
	*********************************************************************/
	void DebugLog(string _message);

};