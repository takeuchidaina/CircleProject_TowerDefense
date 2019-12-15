#include "Setting.h"

cSetting::cSetting(){
	Init();
}

cSetting::~cSetting(){
	End();
}

void cSetting::Init() {
	m_volume[0] = {0};
	m_settingEnd = FALSE;

	string volume[E_VOL_LENGTH];
	ifstream ifs("../Data/Setting.txt");
	if (ifs.fail()) {DEBUG_LOG("設定ファイル読み込み失敗");}
	
	for (int i = 0; i < E_VOL_LENGTH;i++) {
		getline(ifs,volume[i]);
		m_volume[i] = stoi(volume[i]);
	}

	ifs.close();

	const int fontSize = 30,posX = 410,posY = 420, transe = 150,rectSpace = 50;

	sRECT rect = {	/*左上y*/posY,
					/*左上x*/posX,
					/*右下x*/posX + fontSize * /*文字数＋左右の余白*/ 4 ,
					/*右下y*/posY + fontSize * /*文字列数＋上下の余白*/ 3 };
	m_btn[E_BTN_ENTER].Init(rect,transe,"決定", fontSize);

	sRECT rect2 = {	/*左上y*/posY,
					/*左上x*/rect.right + rectSpace,
					/*右下x*/rect.right + rectSpace + fontSize * /*文字数＋左右の余白*/ 4,
					/*右下y*/posY + fontSize * /*文字列数＋上下の余白*/ 3 };
	m_btn[E_BTN_CANSEL].Init(rect2, transe, "戻る", fontSize);

	sRECT rect3 ={	/*左上y*/posY,
					/*左上x*/rect2.right + rectSpace,
					/*右下x*/rect2.right + rectSpace + fontSize * /*文字数＋左右の余白*/ 4,	
					/*右下y*/posY + fontSize * /*文字列数＋上下の余白*/ 3 };
	m_btn[E_BTN_APP].Init(rect3, transe, "適用", fontSize);


	const int volPosX = 600, volPosY = 250;

	for (int i = 0; i < E_VOL_LENGTH;i++) {
		for (int j = 0; j < 2;j++) {
			sRECT volRect;
			if (j == 0) {
				volRect = {	/*左上y*/volPosY + (i * fontSize * 2),
							/*左上x*/volPosX,
							/*右下x*/volPosX + fontSize * 2,
							/*右下y*/volPosY + (i * fontSize * 2) + fontSize };
				m_volBtn[i][0].Init(volRect, transe, "<", fontSize);
			}
			else {
				volRect = {	/*左上y*/volPosY + (i * fontSize * 2),
							/*左上x*/volPosX + fontSize * 5,
							/*右下x*/volPosX + fontSize * 5 + fontSize * 2,
							/*右下y*/(volPosY + (i * fontSize * 2)) + fontSize };
				m_volBtn[i][1].Init(volRect, transe, ">", fontSize);
			}
		}
	}

}

void cSetting::Update() {

	//二回目以降の呼び出し時に使用される
	//FALSEにする処理がないと設定が終わった判定になる
	if (m_settingEnd == TRUE) {
		m_settingEnd = FALSE;
	}

	//ボタンクリック処理
	if (MOUSE_PRESS(LEFT_CLICK) == 1) {
		//決定
		if (m_btn[E_BTN_ENTER].ButtonClick() == TRUE) {
			SoundSettingApp();
			cSound::Instance()->PlaySE(cSound::Instance()->E_SE_SELECT);
			m_settingEnd = TRUE;
		}
		//キャンセル
		else if (m_btn[E_BTN_CANSEL].ButtonClick() == TRUE) {
			cSound::Instance()->PlaySE(cSound::Instance()->E_SE_CANSEL);
			m_settingEnd = TRUE;
		}
		//適用
		else if (m_btn[E_BTN_APP].ButtonClick() == TRUE) {
			cSound::Instance()->PlaySE(cSound::Instance()->E_SE_SELECT);
			SoundSettingApp();
		}

		//音量の調節
		for (int i = 0; i < E_VOL_LENGTH;i++) {
			for (int j = 0; j < 2; j++) {
				if (m_volBtn[i][j].ButtonClick() == TRUE) {
					if (j % 2 == 0) { m_volume[i]--; }
					else{ m_volume[i]++; }

					cSound::Instance()->PlaySE(cSound::Instance()->E_SE_SELECT);
				}
			}

		}
	}

	
}

void cSetting::SoundSettingApp() {

	ofstream ofs("../Data/Setting.txt");
	if (ofs.fail()) { DEBUG_LOG("設定ファイル読み込み失敗"); }

	for (int i = 0; i < E_VOL_LENGTH; i++) {
		ofs << to_string(m_volume[i]) << endl;
	}

	ofs.close();

	//TODO:enum番目だけ書き換える
	cSound::Instance()->ChangeSoundVolume();
}

bool cSetting::GetEndSetting() {

	return m_settingEnd;
}

void cSetting::Draw() {

	//背景の四角
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);	//半透明
	DrawBox(400,200,WINDOW_WIDTH - 400,WINDOW_HEIGHT - 200,BK,TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);	//半透明をオフ

	//文字
	SetFontSize(FONT_SIZE);
	int topPos = 250;
	DrawFormatString(450, topPos, WH, "環境音VOL　　　%d",m_volume[E_VOL_EVM]);
	DrawFormatString(450, topPos + FONT_SIZE*2, WH, "BGM   VOL　　　%d", m_volume[E_VOL_BGM]);
	DrawFormatString(450, topPos + FONT_SIZE*4, WH, "SE    VOL　　　%d", m_volume[E_VOL_SE]);

	//ボタン表示
	for (int i = 0; i < E_BTN_LENGTH; i++) {
		m_btn[i].Draw();
	}

	for (int i = 0; i < E_VOL_LENGTH;i++) {
		for (int j = 0; j < 2;j++) {
			m_volBtn[i][j].Draw();
		}
	}

}

void cSetting::End() {

}