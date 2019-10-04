#include "Hit.h"

/*****************************************************
名前　：int TwoPoint(double _x1, double _y1, double _x2, double _y2);
概要　：二点間の距離を求め距離を返す
引数　：_x1:オブジェ1のx　_y1:オブジェ1のy
		_x2:オブジェ2のx　_y2:オブジェ2のy
戻り値：二点間の距離
******************************************************/
int cHit::TwoPoint(double _x1, double _y1, double _x2, double _y2) {

	double l, xx, yy;

	xx = _x1 - _x2;
	yy = _y1 - _y2;

	l = sqrt(xx * xx + yy * yy);

	return l;
}

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
int cHit::Rect(double _x1, double _y1, double _w1, double _h1,
	double _x2, double _y2, double _w2, double _h2) {

	// 四角2の左上xは四角1の右下xより左にあり
	// 四角1の左上xは四角2の右下xより左にあり
	// 四角2の左上yは四角1の右下yより左にあり
	// 四角1の左上yは四角2の右下yより左にある
	if ( (_x2 < (_x1 + _w1)) && (_x1 < (_x2 + _w2)) &&
		 (_y2 < (_y1 + _h1)) && (_y1 < (_y2 + _h2)) ){
		return TRUE;
	}
	else {
		return FALSE;
	}
}