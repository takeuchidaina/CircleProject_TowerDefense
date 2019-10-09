#include "UnitMgr.h"

void cUnitMgr::Update()
{
	/*VECTOR tmppos;
	tmppos = ConvScreenPosToWorldPos(VGet(100, 100, 0.0f));
	if (CheckHitKey(KEY_INPUT_S) == 1)
	{
		player.emplace_back(new cPSord(tmppos.x, tmppos.y, 1));
	}
	if (CheckHitKey(KEY_INPUT_A) == 1)
	{
		player.emplace_back(new cPArcher(100, 150, 1));
	}*/

	//UnitSelectUI();

}

void cUnitMgr::Draw()
{
	for (int i = 0; i < player.size(); i++)
	{
		player[i]->Draw();
	}

	/*for (int i = 0; i < ui.size(); i++)
	{
		ui[i].Draw();
	}*/

#ifdef UNIT_MGR_DEBUG
	DrawFormatString(100, 100, GetColor(255, 0, 0), "ユニット数：%d", player.size());
#endif // UNIT_MGR_DEBUG
}

//void cUnitMgr::UnitSelectUI()
//{
//	for (int i = 0; i < 2; i++)
//	{
//		ui.emplace_back(200 + 65 * i, i);
//	}
//	
//}