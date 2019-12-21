#include "Sound.h"

cSound::cSound(){
	Init();
}

cSound::~cSound(){
	End();
}

void cSound::Init() {

	m_BGM[E_BGM_WIN] = 0;

	//SE
	m_SEPath[E_SE_SELECT] = { "../resource/Sound/SE/Select.wav" };
	m_SEPath[E_SE_CANSEL] = { "../resource/Sound/SE/Cansel.wav" };
	m_SEPath[E_SE_SWORD]  = { "../resource/Sound/SE/Sword.wav" };
	m_SEPath[E_SE_SHEILD]  = { "../resource/Sound/SE/Sheild_bySword.wav" };
	m_SEPath[E_SE_BULLET] = { "../resource/Sound/SE/Bullet.wav" };
	m_SEPath[E_SE_WIN] = { "../resource/Sound/SE/ME_Win.wav" };
	m_SEPath[E_SE_LOSE] = { "../resource/Sound/SE/ME_Lose.ogg" };
	for (int i = 0; i < E_SE_LENGTH;i++) {
		m_SE[i] = LoadSoundMem(m_SEPath[i].c_str());	//音源読み込み
		FileCheck(m_SE[i]);								//ロード成功かチェック
	}

	//BGM
	m_BGMPath[E_BGM_TITLE]  = { "../resource/Sound/BGM/Title.wav" };
	m_BGMPath[E_BGM_PREPARATION] = { "../resource/Sound/BGM/Battle_Wait.wav" };
	m_BGMPath[E_BGM_BATTLE] = { "../resource/Sound/BGM/Battle_In.wav" };
	m_BGMPath[E_BGM_WIN]    = { "../resource/Sound/BGM/BGM_Win.ogg" };	//oggなのは元のwavファイルが読み込めない周波数やbps、データ形式(アナログ)が違かったため
	m_BGMPath[E_BGM_LOSE]   = { "../resource/Sound/BGM/BGM_Lose.wav" };
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

	m_volume[0] = { 0 };
	ChangeSoundVolume();	//全ての音楽ファイルを記録された音量設定の音量に変更
}

/*****************************************************
名前　：void PlaySE(eSE _se);
概要　：効果音を再生
引数１：eSE _se:鳴らしたい効果音
引数２：ePlayType _type:再生方法
戻り値：なし
補足　：引数１に引数２を追加する形でオーバーロード有
******************************************************/
void cSound::PlaySE(eSE _se) {
	if (CheckValidArgument(_se) == TRUE) {
		PlaySoundMem(m_SE[_se], DX_PLAYTYPE_BACK);
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

/*****************************************************
名前　：void PlayBGM(eBGM _bgm);
概要　：BGMを再生
引数１：eBGM _bgm:再生したいBGM
引数２：ePlayType _type:再生方法
引数３：bool _topPos:(TRUE)頭から再生 (FALSE)前回の中断点から再生
戻り値：なし
補足　：引数１に引数２,３を追加する形でオーバーロード有
******************************************************/
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

/*****************************************************
名前　：void PlayEVM(eEVM _evm);
概要　：EVMを再生
引数１：eEVM _evm:再生したいEVM
引数２：ePlayType _type:再生方法
引数３：bool _topPos:(TRUE)頭から再生 (FALSE)前回の中断点から再生
戻り値：なし
補足　：引数１に引数２,３を追加する形でオーバーロード有
******************************************************/
void cSound::PlayEVM(eEVM _evm) {
	if (CheckValidArgument(_evm) == TRUE) {
		PlaySoundMem(m_EVM[_evm], DX_PLAYTYPE_LOOP);
	}
}
void cSound::PlayEVM(eEVM _evm, ePlayType _type) {
	if (CheckValidArgument(_evm) == TRUE) {
		switch (_type) {
		case E_PLAY_NORMAL:
			PlaySoundMem(m_EVM[_evm], DX_PLAYTYPE_NORMAL, TRUE);
			break;
		case E_PLAY_BACK:
			PlaySoundMem(m_EVM[_evm], DX_PLAYTYPE_BACK, TRUE);
			break;
		case E_PLAY_LOOP:
			PlaySoundMem(m_EVM[_evm], DX_PLAYTYPE_LOOP, TRUE);
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

/*****************************************************
名前　：void StopSound(eSE _se);
概要　：効果音を止める
引数１：eSE _se:止めたいSE
引数１：eBGM _bgm:止めたいBGM
引数１：eEVM _evm:止めたいEVM
戻り値：なし
補足　：引数毎にオーバーロード有
******************************************************/
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

/*****************************************************
名前　：void CheckSound(eSE _se);
概要　：音が再生されているか調べる
引数１：eSE _se:再生中か知りたいSE
引数１：eBGM _bgm:再生中か知りたいBGM
引数１：eEVM _evm:再生中か知りたいEVM
戻り値：(TRUE)再生中　(FALSE)再生されていない
補足　：引数毎にオーバーロード有
******************************************************/
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

/*****************************************************
名前　：bool CheckValidArgument(eSE _se);
概要　：SEの引数が存在するかを調べる
引数１：eSE _se:調べたい値
引数１：eBGM _bgm:調べたい値
引数１：eEVM _evm:調べたい値
戻り値：(TRUE)有効範囲内　(FALSE)有効範囲外
補足　：引数毎にオーバーロード有
******************************************************/
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

/*****************************************************
名前　：void ChangeSoundVolume();
概要　：音量値の変更を反映する
引数　：なし
戻り値：なし
補足　：値はファイルから読み取る
******************************************************/
void cSound::ChangeSoundVolume() {
	
	string volume[E_VOL_LENGTH];	//ファイルから読み込んだ音量値を格納

	//ファイルから音量設定ファイルの値を読み込む
	ifstream ifs("../Data/Setting.txt");
	if (ifs.fail()) { DEBUG_LOG("設定ファイル読み込み失敗"); }

	//音量を格納
	for (int i = 0; i < E_VOL_LENGTH; i++) {
		getline(ifs, volume[i]);
		m_volume[i] = stoi(volume[i]);
	}

	ifs.close();

	//音量変更
	//EVM
	for (int i = 0; i < E_EVM_LENGTH; i++) {	
		ChangeVolumeSoundMem((255 / 100) * m_volume[E_VOL_EVM], m_EVM[i]);
	}
	//SE
	for (int i = 0; i < E_SE_LENGTH;i++) {		
		ChangeVolumeSoundMem((255 / 100) * m_volume[E_VOL_SE],m_SE[i]);
	}
	//BGM
	for (int i = 0; i < E_BGM_LENGTH; i++) {	
		ChangeVolumeSoundMem((255 /100) * m_volume[E_VOL_BGM], m_BGM[i]);
	}

}

void cSound::End() {
	InitSoundMem();		//音を全て削除
}