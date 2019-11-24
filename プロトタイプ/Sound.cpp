#include "Sound.h"

cSound::cSound()
{
	Init();
}

cSound::~cSound()
{
	End();
}

void cSound::Init() {

	//SE
	m_SEPath[E_SE_SELECT] = { "../resource/Sound/SE/Select.wav" };
	m_SEPath[E_SE_CANSEL] = { "../resource/Sound/SE/Cansel.wav" };
	m_SEPath[E_SE_SWORD]  = { "../resource/Sound/SE/Sword.wav" };
	m_SEPath[E_SE_ARROW]  = { "../resource/Sound/SE/Arrow.wav" };
	m_SEPath[E_SE_BULLET] = { "../resource/Sound/SE/Bullet.wav" };
	for (int i = 0; i < E_SE_LENGTH;i++) {
		m_SE[i] = LoadSoundMem(m_SEPath[i].c_str());	//音源読み込み
		FileCheck(m_SE[i]);								//ロード成功かチェック
		ChangeVolumeSoundMem(255 % 70, m_SE[i]);		//音量調節
	}

	//BGM
	m_BGMPath[E_BGM_SEA]    = { "../resource/Sound/BGM/Sea.wav" };
	m_BGMPath[E_BGM_TITLE]  = { "../resource/Sound/BGM/Title.wav" };
	m_BGMPath[E_BGM_BATTLE] = { "../resource/Sound/BGM/Battle.wav" };
	m_BGMPath[E_BGM_WIN]    = { "../resource/Sound/BGM/Win.wav" };
	m_BGMPath[E_BGM_LOSE]   = { "../resource/Sound/BGM/Lose.wav" };
	for (int i = 0; i < E_BGM_LENGTH; i++) {
		m_BGM[i] = LoadSoundMem(m_BGMPath[i].c_str());	//音源読み込み
		FileCheck(m_BGM[i]);							//ロード成功かチェック
		ChangeVolumeSoundMem(50, m_BGM[i]);				//音量調節
	}
}

void cSound::Update() {

	//if (GET_KEY_PRESS(KEY_INPUT_L) == 1) {
	//	PlaySE(E_SE_BULLET,E_PLAY_BACK);
	//}
	//if (GET_KEY_PRESS(KEY_INPUT_K) == 1) {
	//	PlayBGM(E_BGM_BATTLE,E_PLAY_BACK);
	//}
}

//SEを再生
void cSound::PlaySE(eSE _se) {
	if (CheckValidArgument(_se) == TRUE) {
		PlaySoundMem(m_SE[_se], E_PLAY_BACK);
	}
}
void cSound::PlaySE(eSE _se, ePlayType _type) {
	if (CheckValidArgument(_se) == TRUE) {
		PlaySoundMem(m_SE[_se], _type, TRUE);
	}
}

//BGMを再生
void cSound::PlayBGM(eBGM _bgm) {
	if (CheckValidArgument(_bgm) == TRUE) {
		PlaySoundMem(m_BGM[_bgm], E_PLAY_BACK);
	}
}
void cSound::PlayBGM(eBGM _bgm, ePlayType _type) {
	if (CheckValidArgument(_bgm) == TRUE) {
		PlaySoundMem(m_BGM[_bgm], _type, TRUE);
	}
}
void cSound::PlayBGM(eBGM _bgm, ePlayType _type,bool _topPos) {
	if (CheckValidArgument(_bgm) == TRUE) {
		PlaySoundMem(m_BGM[_bgm], _type, _topPos);
	}
}

//音を止める
void cSound::StopSound(eSE _se) {
	if (CheckValidArgument(_se) == TRUE) {
		StopSoundMem(m_SE[_se]);
	}
}
void cSound::StopSound(eBGM _bgm) {
	if (CheckValidArgument(_bgm) == TRUE) {
		StopSoundMem(m_BGM[_bgm]);
	}
}

//再生中か調べる
bool cSound::CheckSound(eSE _se) {
	if (CheckValidArgument(_se) == TRUE) {
		return CheckSoundMem(m_SE[_se]);
	}
	else {
		return FALSE;
	}
}
bool cSound::CheckSound(eBGM _bgm) {
	if (CheckValidArgument(_bgm) == TRUE) {
		return CheckSoundMem(m_BGM[_bgm]);
	}
	else {
		return FALSE;
	}
}

//引数が有効か調べる
bool cSound::CheckValidArgument(eSE _se) {
	if (_se < E_SE_LENGTH) {
		return TRUE;	//有効範囲内
	}
	else {
		ErrBox("音楽再生ファイルにて有効ではない引数が渡されました");
		return FALSE;	//有効範囲外
	}
}
bool cSound::CheckValidArgument(eBGM _bgm) {
	if (_bgm < E_BGM_LENGTH) {
		return TRUE;	//有効範囲内
	}
	else {
		ErrBox("音楽再生ファイルにて有効ではない引数が渡されました");
		return FALSE;	//有効範囲外
	}
}

void cSound::End() {
	InitSoundMem();		//音を全て削除
}