#include "MapMgr.h"

cMapMgr::cMapMgr(){
	fileName = "../resource/Map/Map1.csv";
	Init();

}
cMapMgr::~cMapMgr(){
	;
}

void cMapMgr::Init(){	

	tmpMap=CSVLoad(fileName);

	double tmpX=0.0, tmpY=0.0, tmpW=0.0, tmpH=0.0;
	int tmpMaxUnit=0,tmpRoomNum=0;
	bool tmpStartMapFlg = FALSE, tmpDefenseMapFlg = FALSE;
	vector<sDoor> tmpDoor(4);

	//ドアなしver用,
	vector<int> tmpDesMap; 

	for (int i = 0; i < tmpMap.size(); i++) {
		for (int j = 0; j < tmpMap[i].size(); j++) {
			switch (j) {
			case 0:tmpRoomNum = tmpMap[i][j];			break;
			case 1:tmpX = tmpMap[i][j];					break;
			case 2:tmpY = tmpMap[i][j];					break;
			case 3:tmpW = tmpMap[i][j];					break;
			case 4:tmpH = tmpMap[i][j];					break;
			case 5:tmpMaxUnit = tmpMap[i][j];			break;
			case 6:tmpStartMapFlg = tmpMap[i][j];		break;
			case 7:tmpDefenseMapFlg = tmpMap[i][j];		break;

			case 8:tmpDoor[0].pos.x = tmpMap[i][j];		break;
			case 9:tmpDoor[0].pos.y = tmpMap[i][j];		break;
			case 10:tmpDoor[0].desMap = tmpMap[i][j];
				if (tmpMap[i][j] != 0)tmpDesMap.push_back(tmpMap[i][j]);			break;
			case 11:tmpDoor[0].desDoor = tmpMap[i][j];	break;

			case 12:tmpDoor[1].pos.x = tmpMap[i][j];	break;
			case 13:tmpDoor[1].pos.y = tmpMap[i][j];	break;
			case 14:tmpDoor[1].desMap = tmpMap[i][j];
				if (tmpMap[i][j] != 0)tmpDesMap.push_back(tmpMap[i][j]);			break;
			case 15:tmpDoor[1].desDoor = tmpMap[i][j];	break;

			case 16:tmpDoor[2].pos.x = tmpMap[i][j];	break;
			case 17:tmpDoor[2].pos.y = tmpMap[i][j];	break;
			case 18:tmpDoor[2].desMap = tmpMap[i][j];
				if (tmpMap[i][j] != 0)tmpDesMap.push_back(tmpMap[i][j]);			break;
			case 19:tmpDoor[2].desDoor = tmpMap[i][j];	break;

			case 20:tmpDoor[3].pos.x = tmpMap[i][j];	break;
			case 21:tmpDoor[3].pos.y = tmpMap[i][j];	break;
			case 22:tmpDoor[3].desMap = tmpMap[i][j];	
				if (tmpMap[i][j] != 0)tmpDesMap.push_back(tmpMap[i][j]);			break;
			case 23:tmpDoor[3].desDoor = tmpMap[i][j];	break;

			default:break;
			}

		}

		//ドアの中身が空の場合、配列から削除 WIP!!!!!!!!!!
		/*
		for (int k = 3; k > 0; k--) {
			if (tmpDoor[k].pos.x == 0 && tmpDoor[k].pos.y == 0 && tmpDoor[k].desMap) {
				tmpDoor.pop_back();
			}
		}
		*/

		//cMap tmp(tmpX, tmpY, tmpW, tmpH, tmpMaxUnit, tmpRoomNum, tmpDoor);

		//ドアなし用
		cMap tmp(tmpX, tmpY, tmpW, tmpH, tmpMaxUnit, tmpRoomNum, tmpDesMap, tmpStartMapFlg, tmpDefenseMapFlg);
		tmpDesMap.clear();

		map.push_back(tmp);
	}

	vector<vector<int>> tmp = GetMapDes();
}

void cMapMgr::Update(){
	for (int i = 0; i < map.size(); i++) {
		map[i].Update();
	}
}

void cMapMgr::Draw(){
	for (int i = 0; i < map.size(); i++) {
		map[i].Draw();
	}
	DrawFormatString(300,400,RD,"roomNum:%d",map[0].GetRoomNum());

}

double cMapMgr::Get_Ground(int _num) {
	return map[_num].Get_Ground();
}

int cMapMgr::CheckInto(double _x, double _y) {
	for (int i = 0; i < map.size();i++) {
		if (map[i].CheckInto(_x, _y) == true) {
			return map[i].GetRoomNum();
		}
	}
	return -1;
	
}

int cMapMgr::GetMapSize() {
	return map.size();
}

//ドアなしver用
vector<vector<int>> cMapMgr::GetMapDes(){
	vector<vector<int>> tmpDes;
	for (int i = 0; i < map.size(); i++) {
		tmpDes.push_back(map[i].GetMapDes());
	}
	return tmpDes;
}

vector<sMapData> cMapMgr::GetMapData()
{
	vector<sMapData> mapData;

	for (int i = 0; i < map.size(); i++)
	{
		sMapData tmp = { map[i].GetPos(), map[i].GetWidth(), map[i].GetHeight(), map[i].GetRoomSize() };
		mapData.push_back(tmp);
	}

	return mapData;
}

////////////////マップ.csvベース
//Map					         Door01	 destinetion	Door02  destinetion
//x	y	width	height	maxUnit	 x	y	 map  door		x	y	map  door

