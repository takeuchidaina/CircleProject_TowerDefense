#include "MapNavigate.h"

cMapNavigate::cMapNavigate() {
	Init();
}

cMapNavigate::~cMapNavigate() {
	;
}

void cMapNavigate::Init() {
	//mapStack = tmp;	// Mapの繋がりを代入
}

void cMapNavigate::Update() {

}

void cMapNavigate::Draw() {

}

// Mapがつながっているか
int cMapNavigate::InspectMove(int _x, int _y, int _renge) {
	_renge++;
	/*
	//int yy = 0, xx = 0;
	for (int i = 0; i < mapStack.size(); i++) {
		for (int j = 0; j < mapStack[i].size(); j++) {

		////////////////////////////
		if(mapStack[i].size == 0){
			return;
		} else if(mapStack[i].size == 1){

		} else if(mapStack[i].size == 2){

		} else if(mapStack[i].size == 3){

		} else {return;}

		/////////////////////////////////
			if ((mapStack[_y + mapStack[i]][_x + mapStack[j]] >= 0 || mapStack[_y + mapStack[i]][_x + mapStack[j]] == ゴール) &&
				(tmpMapStack[_y + mapStack[i]][_x + mapStack[j]] > _renge || tmpMapStack[_y + mapStack[i]][_x + mapStack[j]] >= 0)) {

				tmpMapStack[_y + mapStack[i]][_x + mapStack[j]] = _renge;
				InspectMove(_x + mapStack[j], _y + mapStack[i]);
			}
		}
	}
	*/
	return 0;
}

// ルート検索
int cMapNavigate::MapNavigation(int _x, int _y) {
	/*
	for (int i = 0; i < mapStack.size(); i++) {
		for (int j = 0; j < mapStack[i].size(); j++) {
			if (tmpMapStack[i][j] == 0) {	// Mapがつながっていない
				if () {
					

				}
			}
		}
	}
	*/
	return 0;
}

