#include "UnitMgr.h"

void cUnitMgr::Update()
{
	//if (CheckHitKey(KEY_INPUT_S) == 1)
	//{
	//	player.emplace_back(new cPSord(100, 100, 1));
	//}
	//if (CheckHitKey(KEY_INPUT_A) == 1)
	//{
	//	player.emplace_back(new cPArcher(100, 150, 1));
	//}


}

void cUnitMgr::Draw()
{
	for (int i = 0; i < player.size(); i++)
	{
		player[i]->Draw();
	}

	DrawFormatString(100, 100, GetColor(255, 0, 0), "ユニット数：%d", player.size());
}