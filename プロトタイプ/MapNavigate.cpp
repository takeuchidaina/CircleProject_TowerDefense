#include "MapNavigate.h"

cMapNavigate::cMapNavigate() {
	//mapStack = _i;
}

cMapNavigate::~cMapNavigate() {
	;
}

void cMapNavigate::Init() {
	
}

void cMapNavigate::Update() {

}

void cMapNavigate::Draw() {

}

void cMapNavigate::Get_MapDate(vector<vector<int>> _MapDate) {
	mapStack = _MapDate;		// Map�̌q�������
}

// Map���Ȃ����Ă��邩		����Ȃ�����
/*
int cMapNavigate::InspectMove(int _x, int _y, int _range) {
	_range++;
	
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
			if ((mapStack[_y + mapStack[i]][_x + mapStack[j]] >= 0 || mapStack[_y + mapStack[i]][_x + mapStack[j]] == �S�[��) &&
				(tmpMapStack[_y + mapStack[i]][_x + mapStack[j]] > _renge || tmpMapStack[_y + mapStack[i]][_x + mapStack[j]] >= 0)) {

				tmpMapStack[_y + mapStack[i]][_x + mapStack[j]] = _renge;
				InspectMove(_x + mapStack[j], _y + mapStack[i]);
			}
		}
	}
	
	return 0;
}
*/

// ���[�g����
// �ȈՔ�								1			2
int cMapNavigate::MapNavigation(int _start, int _goal) {
	int cnt = 0;
	for (int j = 0; j < mapStack.size(); j++) {
		cnt++;
		if (mapStack[_start][j] == _start) {
			return;			
		}
		else if (mapStack[_start][j] == _goal) {
			tbl.push_back(cnt);		// strat�܂ł̓��̂������
		}
		else if (mapStack[_start][j] != _start || mapStack[_start][j] != _goal) {
			MapNavigation(_start + 1, _goal);
		}
	}
	return cnt;
}

/*
// _start=�o��	_goal=�s����
bool cMapNavigate::isMapNavigation(int _start, int _goal) {
	int cnt = 0;
		for (int j = 0; j < mapStack[_start].size(); j++) {
					
			// �o��==_start, �s����==_start	�Ȃ�
			if (mapStack[_start][j] == _start) {	
				return false;						//�Ȃ���Ȃ�����false�ŕԂ�
			}

			// goal�ɂ�����
			if(mapStack[_start][j] == _goal) {		
				cnt++;								//���̂���J�E���g
				tbl.push_back(cnt);				// strat�܂ł̓��̂������
				return true;
			}

			// _start�ł�_goal�ł��Ȃ�
			if (mapStack[_start][j] != _start || mapStack[_start][j] != _goal) {		
				cnt++;								//���̂���J�E���g
				mapStack[_start][j + 1];	
				tbl.push_back(cnt);					// strat�܂ł̓��̂������
				isMapNavigation(_start + 1, _goal);	// ��A�֐�
			}
		}
	return 0;
}
*/