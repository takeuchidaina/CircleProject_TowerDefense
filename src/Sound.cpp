#include "Sound.h"

cSound::cSound(){
	Init();
}

cSound::~cSound(){
	End();
}

void cSound::Init() {

	m_volume[0] = { 0 };

	//SE
	m_SEPath[E_SE_SELECT] = { "../resource/Sound/SE/Select.wav" };
	m_SEPath[E_SE_CANSEL] = { "../resource/Sound/SE/Cansel.wav" };
	m_SEPath[E_SE_SWORD]  = { "../resource/Sound/SE/Sword.wav" };
	m_SEPath[E_SE_SHEILD]  = { "../resource/Sound/SE/Arrow.wav" };
	m_SEPath[E_SE_BULLET] = { "../resource/Sound/SE/Bullet.wav" };
	for (int i = 0; i < E_SE_LENGTH;i++) {
		m_SE[i] = LoadSoundMem(m_SEPath[i].c_str());	//音源読み込み
		FileCheck(m_SE[i]);								//ロード成功かチェック
	}
	//BGM
	m_BGMPath[E_BGM_TITLE]  = { "../resource/Sound/BGM/Title.wav" };
	m_BGMPath[E_BGM_BATTLE] = { "../resource/Sound/BGM/Battle.wav" };
	m_BGMPath[E_BGM_WIN]    = { "../resource/Sound/BGM/Win.wav" };
	m_BGMPath[E_BGM_LOSE]   = { "../resource/Sound/BGM/Lose.wav" };
	for (int i = 0; i < E_BGM_LENGTH; i++) {
		m_BGM[i] = LoadSoundMem(m_BGMPath[i].c_str());	//音源読み込み
		FileCheck(m_BGM[i]);							//ロード成功かチェック
	}

	//EVM
	m_EVMPath[E_EVM_SEA_ROUGH] = { "../resource/Sound/EVM/Sea.wav" };
	m_EVMPath[E_EVM_SEA_RIPPLES] = { "../resource/Sound/EVM/Sea.wav" };
	for (int i = 0; i < E_EVM_LENGTH; i++) {
		m_EVM[i] = LoadSoundMem(m_EVMPath[i].c_str());	//音源読み込み
		FileCheck(m_EVM[i]);							//ロード成功かチェック
	}

	ChangeSoundVolume();
}

//SEを再生
void cSound::PlaySE(eSE _se) {
	if (CheckValidArgument(_se) == TRUE) {
		PlaySoundMem(m_SE[_se], DX_PLAYTYPE_NORMAL);
	}
}
void cSound::PlaySE(eSE _se, ePlayType _type) {
	if (CheckValidArgument(_se) == TRUE) {
		switch (_type){
		case E_PLAY_NORMAL:
			PlaySoundMem(m_SE[_se], DX_PLAYTYPE_NORMAL, TRUE);
			break;
		case E_PLAY_BACK:
			PlaySoundMem(m_SE[_se], DX_PLAYTYPE_BACK, TRUE);
			break;
		case E_PLAY_LOOP:
			PlaySoundMem(m_SE[_se], DX_PLAYTYPE_LOOP, TRUE);
			break;
		}
	}
}

//BGMを再生
void cSound::PlayBGM(eBGM _bgm) {
	if (CheckValidArgument(_bgm) == TRUE) {
		PlaySoundMem(m_BGM[_bgm], DX_PLAYTYPE_LOOP);
	}
}
void cSound::PlayBGM(eBGM _bgm, ePlayType _type) {
	if (CheckValidArgument(_bgm) == TRUE) {
		switch (_type){
		case E_PLAY_NORMAL:
			PlaySoundMem(m_BGM[_bgm], DX_PLAYTYPE_NORMAL, TRUE);
			break;
		case E_PLAY_BACK:
			PlaySoundMem(m_BGM[_bgm], DX_PLAYTYPE_BACK, TRUE);
			break;
		case E_PLAY_LOOP:
			PlaySoundMem(m_BGM[_bgm], DX_PLAYTYPE_LOOP, TRUE);
			break;
		}
	}
}
void cSound::PlayBGM(eBGM _bgm, ePlayType _type,bool _topPos) {
	if (CheckValidArgument(_bgm) == TRUE) {
		switch (_type) {
		case E_PLAY_NORMAL:
			PlaySoundMem(m_BGM[_bgm], DX_PLAYTYPE_NORMAL, _topPos);
			break;
		case E_PLAY_BACK:
			PlaySoundMem(m_BGM[_bgm], DX_PLAYTYPE_BACK, _topPos);
			break;
		case E_PLAY_LOOP:
			PlaySoundMem(m_BGM[_bgm], DX_PLAYTYPE_LOOP, _topPos);
			break;
		}
	}
}

//EVMを再生
void cSound::PlayEVM(eEVM _EVM) {
	if (CheckValidArgument(_EVM) == TRUE) {
		PlaySoundMem(m_EVM[_EVM], DX_PLAYTYPE_LOOP);
	}
}
void cSound::PlayEVM(eEVM _EVM, ePlayType _type) {
	if (CheckValidArgument(_EVM) == TRUE) {
		switch (_type) {
		case E_PLAY_NORMAL:
			PlaySoundMem(m_EVM[_EVM], DX_PLAYTYPE_NORMAL, TRUE);
			break;
		case E_PLAY_BACK:
			PlaySoundMem(m_EVM[_EVM], DX_PLAYTYPE_BACK, TRUE);
			break;
		case E_PLAY_LOOP:
			PlaySoundMem(m_EVM[_EVM], DX_PLAYTYPE_LOOP, TRUE);
			break;
		}
	}
}
void cSound::PlayEVM(eEVM _evm, ePlayType _type, bool _topPos) {
	if (CheckValidArgument(_evm) == TRUE) {
		switch (_type) {
		case E_PLAY_NORMAL:
			PlaySoundMem(m_EVM[_evm], DX_PLAYTYPE_NORMAL, _topPos);
			break;
		case E_PLAY_BACK:
			PlaySoundMem(m_EVM[_evm], DX_PLAYTYPE_BACK, _topPos);
			break;
		case E_PLAY_LOOP:
			PlaySoundMem(m_EVM[_evm], DX_PLAYTYPE_LOOP, _topPos);
			break;
		}
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
void cSound::StopSound(eEVM _evm) {
	if (CheckValidArgument(_evm) == TRUE) {
		StopSoundMem(m_EVM[_evm]);
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
bool cSound::CheckSound(eEVM _evm) {
	if (CheckValidArgument(_evm) == TRUE) {
		return CheckSoundMem(m_EVM[_evm]);
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
bool cSound::CheckValidArgument(eEVM _evm) {
	if (_evm < E_EVM_LENGTH) {
		return TRUE;	//有効範囲内
	}
	else {
		ErrBox("音楽再生ファイルにて有効ではない引数が渡されました");
		return FALSE;	//有効範囲外
	}
}

//音量設定適用
void cSound::ChangeSoundVolume() {
	
	string volume[E_VOL_LENGTH];	//ファイルから読み込んだ音量値を格納

	//ファイル読み込み
	ifstream ifs("../Data/Setting.txt");
	if (ifs.fail()) { DEBUG_LOG("設定ファイル読み込み失敗"); }

	for (int i = 0; i < E_VOL_LENGTH; i++) {
		getline(ifs, volume[i]);
		m_volume[i] = stoi(volume[i]);
	}

	ifs.close();

	//音量変更
	for (int i = 0; i < E_EVM_LENGTH; i++) {
		ChangeVolumeSoundMem((255 / 100) * m_volume[E_VOL_EVM], m_EVM[i]);
	}
	for (int i = 0; i < E_SE_LENGTH;i++) {
		ChangeVolumeSoundMem((255 / 100) * m_volume[E_VOL_SE],m_SE[i]);
	}
	for (int i = 0; i < E_BGM_LENGTH; i++) {
		ChangeVolumeSoundMem((255 /100) * m_volume[E_VOL_BGM], m_BGM[i]);
	}

}

void cSound::End() {
	InitSoundMem();		//音を全て削除
}