#pragma once

#ifndef _INCLUEDE_HIT_
#define _INCLUEDE_HIT_
#include "DxLib.h"
#include <math.h>

class cHit
{
public:
	cHit() {}
	~cHit() {}

	/*****************************************************
	名前　：int TwoPoint(double _x1, double _y1, double _x2, double _y2);
	概要　：二点間の距離を求め距離を返す
	引数　：_x1:オブジェ1のx　_y1:オブジェ1のy
			_x2:オブジェ2のx　_y2:オブジェ2のy
	戻り値：二点間の距離
	******************************************************/
	int TwoPoint(double _x1, double _y1, double _x2, double _y2);

	/*****************************************************
	名前　：int Rect(double _x1, double _y1, double _w1, double _h1,
						double _x2, double _y2, double _w2, double _h2);
	概要　：四角同士の当たり判定を求める
	引数　：_x1:オブジェ1のx　   _y1:オブジェ1のy　
			_w1:オブジェ1の横幅　_h1:オブジェ1の高さ
			_x2:オブジェ2のx　	 _y2:オブジェ2のy
			_w2:オブジェ1の横幅　_h2:オブジェ1の高さ
	戻り値：TRUE:当たった　FALSE:当たっていない
	******************************************************/
	int Rect(double _x1, double _y1, double _w1, double _h1,
		double _x2, double _y2, double _w2, double _h2);

private:

};
#endif // !_INCLUEDE_HIT_
