#include "MapMgr.h"

cMapMgr::cMapMgr(){
	fileName = "C:/Users/nwuser/Documents/school/2GM/サークル/TowerDefense/Map1.csv";
	Init();

}
cMapMgr::~cMapMgr(){
	;
}

void cMapMgr::Init(){	

	tmpMap=CSVLoad(fileName);

	double tmpX, tmpY, tmpW, tmpH;
	int tmpMaxUnit,tmpRoomNum;
	vector<sDoor> tmpDoor(4);

	for (int i = 0; i < tmpMap.size(); i++) {
		for (int j = 0; j < tmpMap[i].size(); j++) {
			switch (j) {
			case 0:tmpRoomNum = tmpMap[i][j]; break;
			case 1:tmpX = tmpMap[i][j];	break;
			case 2:tmpY = tmpMap[i][j];	break;
			case 3:tmpW = tmpMap[i][j];	break;
			case 4:tmpH = tmpMap[i][j];	break;
			case 5:tmpMaxUnit = tmpMap[i][j];	break;
			case 6:tmpDoor[0].x = tmpMap[i][j];	break;
			case 7:tmpDoor[0].y = tmpMap[i][j];	break;
			case 8:tmpDoor[0].desMap = tmpMap[i][j];	break;
			case 9:tmpDoor[0].desDoor = tmpMap[i][j];	break;
			case 10:tmpDoor[1].x = tmpMap[i][j];	break;
			case 11:tmpDoor[1].y = tmpMap[i][j];	break;
			case 12:tmpDoor[1].desMap = tmpMap[i][j];	break;
			case 13:tmpDoor[1].desDoor = tmpMap[i][j];	break;
			case 14:tmpDoor[2].x = tmpMap[i][j];	break;
			case 15:tmpDoor[2].y = tmpMap[i][j];	break;
			case 16:tmpDoor[2].desMap = tmpMap[i][j];	break;
			case 17:tmpDoor[2].desDoor = tmpMap[i][j];	break;
			case 18:tmpDoor[3].x = tmpMap[i][j];	break;
			case 19:tmpDoor[3].y = tmpMap[i][j];	break;
			case 20:tmpDoor[3].desMap = tmpMap[i][j];	break;
			case 21:tmpDoor[3].desDoor = tmpMap[i][j];	break;
			default:break;
			}
		}
		cMap tmp(tmpX, tmpY, tmpW, tmpH, tmpMaxUnit, tmpRoomNum, tmpDoor);
		map.push_back(tmp);
	}
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

}

int cMapMgr::CsvSizeX(int _y) {
	if (_y < 0 || _y >= cMap.size()) return -1;
	return cMap[_y].size();
}

////////////////マップ.csvベース
//Map					         Door01	 destinetion	Door02  destinetion
//x	y	width	height	maxUnit	 x	y	 map  door		x	y	map  door

