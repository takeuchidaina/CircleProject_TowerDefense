#include "Map.h"

void cMap::Update()
{

}

bool cMap::CheckInto(double _x, double _y)
{
	if (x + (UNIT_HEIGHT/2) <= _x && x + w - (UNIT_WIDTH/2) >= _x)
	{
		if (y <= _y && y + h >= _y)
		{
			return true;
		}
		else return false;
	}
	else return false;
}