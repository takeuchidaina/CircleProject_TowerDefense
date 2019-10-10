#include "UnitMgr.h"

void cUnitMgr::Update()
{
	
	for (int i = 0; i < player.size(); i++)
	{
		player[i]->Move();
	}

}

void cUnitMgr::Draw()
{
	for (int i = 0; i < player.size(); i++)
	{
		player[i]->Draw();
	}

#ifdef UNIT_MGR_DEBUG
	DrawFormatString(100, 100, GetColor(255, 0, 0), "ユニット数：%d", player.size());
#endif // UNIT_MGR_DEBUG
}