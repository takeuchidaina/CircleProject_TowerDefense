#pragma once

#ifndef _INCLUEDE_HIT_
#define _INCLUEDE_HIT_
#include "DxLib.h"
#include <math.h>
#include "Mouse.h"

class cHit
{
public:
	cHit() {}
	~cHit() {}

	/*****************************************************
	���O�@�Fint TwoPoint(double _x1, double _y1, double _x2, double _y2);
	�T�v�@�F��_�Ԃ̋��������ߋ�����Ԃ�
	�����@�F_x1:�I�u�W�F1��x�@_y1:�I�u�W�F1��y
			_x2:�I�u�W�F2��x�@_y2:�I�u�W�F2��y
	�߂�l�F��_�Ԃ̋���
	******************************************************/
	double TwoPoint(double _x1, double _y1, double _x2, double _y2);

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
	bool Rect(double _x1, double _y1, double _w1, double _h1,
		double _x2, double _y2, double _w2, double _h2);

	/*****************************************************
	���O�@�Fint TwoPoint(double _x1, double _y1, double _x2, double _y2);
	�T�v�@�F�l�p�̏�Ƀ}�E�X�����邩�𔻒f
	�����@�F�I�u�W�F�N�g�̍���(x1,y1)
			�I�u�W�F�N�g�̉E��(x2,y2)
	�߂�l�FTRUE:���������@FALSE:�������Ă��Ȃ�
	******************************************************/
	bool RectOnClick(double _x1,double _y1,double _x2,double _y2);

private:

};
#endif // !_INCLUEDE_HIT_