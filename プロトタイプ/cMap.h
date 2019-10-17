#pragma once
#include "DxLib.h"
#include "BaseTask.h"
#include "ColorListh.h"
#include "Constant.h"

class cMap : public cBaseTask
{
protected:
	VECTOR m_pos;
	double m_width, m_height;
	int m_num;

	int img;

public:
	cMap(double _x, double _y, double _width, double _height, int _num);

	virtual void Update();
	virtual void Draw();

	int CheckInto(double _x, double _y)
	{
		if (m_pos.x - (m_width/2) <= _x - (UNIT_WIDTH/2) && m_pos.x + (m_width/2) >= _x + (UNIT_WIDTH/2))
		{
			// ‰æ‘œ‚Ì•\¦‚Í’†S‚©‚ç
			if (m_pos.y - (m_height/2) <= _y && m_pos.y + (m_height/2) >= _y)
			{
				return m_num;
			}
			else
			{
				return -1;
			}
		}
		else
		{
			return -1;
		}
	}

	double Get_Ground()
	{
		return m_pos.y - (m_height/2);
	}

	int Get_Num()
	{
		return m_num;
	}

};