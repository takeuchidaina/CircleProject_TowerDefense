#include "ErrorCheck.h"

/*****************************************************
名前　：void FileCheck(int _fileName)
概要　：ファイルや画像の中身があるかのチェックを行う
引数　：ファイルを入れた変数
戻り値：無し　※エラーが出た際にはエラーボックスが出る
******************************************************/
void FileCheck(int _fileName) {
	if (_fileName == -1 || _fileName == NULL) {
		ErrBox("ヌルポ");
	}
}