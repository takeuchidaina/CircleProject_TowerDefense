#include "Hit.h"

/*****************************************************
���O�@�Fint TwoPoint(double _x1, double _y1, double _x2, double _y2);
�T�v�@�F��_�Ԃ̋��������ߋ�����Ԃ�
�����@�F_x1:�I�u�W�F1��x�@_y1:�I�u�W�F1��y
		_x2:�I�u�W�F2��x�@_y2:�I�u�W�F2��y
�߂�l�F��_�Ԃ̋���
******************************************************/
int cHit::TwoPoint(double _x1, double _y1, double _x2, double _y2) {

	double l, xx, yy;

	xx = _x1 - _x2;
	yy = _y1 - _y2;

	l = sqrt(xx * xx + yy * yy);

	return l;
}

/*****************************************************
���O�@�Fint Rect(double _x1, double _y1, double _w1, double _h1,
					double _x2, double _y2, double _w2, double _h2);
�T�v�@�F�l�p���m�̓����蔻������߂�
�����@�F_x1:�I�u�W�F1��x�@   _y1:�I�u�W�F1��y�@
		_w1:�I�u�W�F1�̉����@_h1:�I�u�W�F1�̍���
		_x2:�I�u�W�F2��x�@	 _y2:�I�u�W�F2��y
		_w2:�I�u�W�F1�̉����@_h2:�I�u�W�F1�̍���
�߂�l�FTRUE:���������@FALSE:�������Ă��Ȃ�
******************************************************/
int cHit::Rect(double _x1, double _y1, double _w1, double _h1,
	double _x2, double _y2, double _w2, double _h2) {

	// �l�p2�̍���x�͎l�p1�̉E��x��荶�ɂ���
	// �l�p1�̍���x�͎l�p2�̉E��x��荶�ɂ���
	// �l�p2�̍���y�͎l�p1�̉E��y��荶�ɂ���
	// �l�p1�̍���y�͎l�p2�̉E��y��荶�ɂ���
	if ( (_x2 < (_x1 + _w1)) && (_x1 < (_x2 + _w2)) &&
		 (_y2 < (_y1 + _h1)) && (_y1 < (_y2 + _h2)) ){
		return TRUE;
	}
	else {
		return FALSE;
	}
}