#pragma once

#ifndef _INCLUED_ERRORCHECK_
#define _INCLUED_ERRORCHECK_

#include <iostream>
#include "WinBox.h"

/********************************************************
●概要
　エラーチェックを行う

●作成者
　竹内 大奈
********************************************************/

/*****************************************************
名前　：void FileCheck(int _fileName)
概要　：ファイルや画像の中身があるかのチェックを行う
引数　：ファイルを入れた変数
戻り値：無し　※エラーが出た際にはエラーボックスが出る
******************************************************/
extern void FileCheck(int _fileName);

#endif // !_INCLUED_ERRORCHECK_