#include "Setting.h"

cSetting::cSetting(){
	Init();
}

cSetting::~cSetting(){
	End();
}

void cSetting::Init() {
	m_volume[0] = {0};

	string volume[E_VOL_LENGTH];
	ifstream ifs("../Data/Setting.txt");
	if (ifs.fail()) {DEBUG_LOG("設定ファイル読み込み失敗");}
	
	for (int i = 0; i < E_VOL_LENGTH;i++) {
		getline(ifs,volume[i]);
		m_volume[i] = stoi(volume[i]);
	}

	ifs.close();

	m_select = E_SOUND_ENVIRONMENTAL;
}

void cSetting::Update() {
	if (GET_KEY_PRESS(KEY_INPUT_UP) == 1 && m_select > 0) {
		m_select--;
	}
	if (GET_KEY_PRESS(KEY_INPUT_DOWN) == 1 && m_select < E_VOL_LENGTH) {
		m_select++;
	}

	if (GET_KEY_PRESS(KEY_INPUT_LEFT) == 1) {
		m_volume[m_select]--;
	}
	if (GET_KEY_PRESS(KEY_INPUT_RIGHT) == 1) {
		m_volume[m_select]++;
	}

	if (GET_KEY_PRESS(KEY_INPUT_RETURN) == 1 && m_select == E_VOL_LENGTH) {
		ofstream ofs("../Data/Setting.txt");
		if (ofs.fail()) { DEBUG_LOG("設定ファイル読み込み失敗"); }

		for (int i = 0; i < E_VOL_LENGTH;i++) {
			ofs << to_string(m_volume[i]) << endl;
		}
		
		ofs.close();

		cSound::Instance()->ChangeSoundVolume();
		//TODO:enum番目だけ書き換える
	}
	
}

void cSetting::Draw() {
	DrawBox(300,200,980,520,BK,TRUE);
	DrawFormatString(500, 400, WH, "環境音VOL:%d", m_volume[E_SOUND_ENVIRONMENTAL]);
	DrawFormatString(500, 420, WH, "BGM   VOL:%d", m_volume[E_SOUND_BGM]);
	DrawFormatString(500, 440, WH, "SE    VOL:%d", m_volume[E_SOUND_SE]);
	DrawFormatString(500, 460, WH, "決　　　　定");
	DrawFormatString(480, 400+(m_select*20), WH, "→");

}

void cSetting::End() {

}