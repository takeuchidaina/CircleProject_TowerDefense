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
		m_SE[i] = LoadSoundMem(m_SEPath[i].c_str());	//�����ǂݍ���
		FileCheck(m_SE[i]);								//���[�h�������`�F�b�N
	}

	//BGM
	m_BGMPath[E_BGM_TITLE]  = { "../resource/Sound/BGM/Title.wav" };
	m_BGMPath[E_BGM_PREPARATION] = { "../resource/Sound/BGM/Battle_Wait.wav" };
	m_BGMPath[E_BGM_BATTLE] = { "../resource/Sound/BGM/Battle_In.wav" };
	m_BGMPath[E_BGM_WIN]    = { "../resource/Sound/BGM/BGM_Win.ogg" };	//ogg�Ȃ̂͌���wav�t�@�C�����ǂݍ��߂Ȃ����g����bps�A�f�[�^�`��(�A�i���O)���Ⴉ��������
	m_BGMPath[E_BGM_LOSE]   = { "../resource/Sound/BGM/BGM_Lose.wav" };
	for (int i = 0; i < E_BGM_LENGTH; i++) {
		m_BGM[i] = LoadSoundMem(m_BGMPath[i].c_str());	//�����ǂݍ���
		FileCheck(m_BGM[i]);							//���[�h�������`�F�b�N
	}

	//EVM
	m_EVMPath[E_EVM_SEA_ROUGH] = { "../resource/Sound/EVM/Sea.wav" };
	m_EVMPath[E_EVM_SEA_RIPPLES] = { "../resource/Sound/EVM/Sea.wav" };
	for (int i = 0; i < E_EVM_LENGTH; i++) {
		m_EVM[i] = LoadSoundMem(m_EVMPath[i].c_str());	//�����ǂݍ���
		FileCheck(m_EVM[i]);							//���[�h�������`�F�b�N
	}

	m_volume[0] = { 0 };
	ChangeSoundVolume();	//�S�Ẳ��y�t�@�C�����L�^���ꂽ���ʐݒ�̉��ʂɕύX
}

/*****************************************************
���O�@�Fvoid PlaySE(eSE _se);
�T�v�@�F���ʉ����Đ�
�����P�FeSE _se:�炵�������ʉ�
�����Q�FePlayType _type:�Đ����@
�߂�l�F�Ȃ�
�⑫�@�F�����P�Ɉ����Q��ǉ�����`�ŃI�[�o�[���[�h�L
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
���O�@�Fvoid PlayBGM(eBGM _bgm);
�T�v�@�FBGM���Đ�
�����P�FeBGM _bgm:�Đ�������BGM
�����Q�FePlayType _type:�Đ����@
�����R�Fbool _topPos:(TRUE)������Đ� (FALSE)�O��̒��f�_����Đ�
�߂�l�F�Ȃ�
�⑫�@�F�����P�Ɉ����Q,�R��ǉ�����`�ŃI�[�o�[���[�h�L
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
���O�@�Fvoid PlayEVM(eEVM _evm);
�T�v�@�FEVM���Đ�
�����P�FeEVM _evm:�Đ�������EVM
�����Q�FePlayType _type:�Đ����@
�����R�Fbool _topPos:(TRUE)������Đ� (FALSE)�O��̒��f�_����Đ�
�߂�l�F�Ȃ�
�⑫�@�F�����P�Ɉ����Q,�R��ǉ�����`�ŃI�[�o�[���[�h�L
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
���O�@�Fvoid StopSound(eSE _se);
�T�v�@�F���ʉ����~�߂�
�����P�FeSE _se:�~�߂���SE
�����P�FeBGM _bgm:�~�߂���BGM
�����P�FeEVM _evm:�~�߂���EVM
�߂�l�F�Ȃ�
�⑫�@�F�������ɃI�[�o�[���[�h�L
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
���O�@�Fvoid CheckSound(eSE _se);
�T�v�@�F�����Đ�����Ă��邩���ׂ�
�����P�FeSE _se:�Đ������m�肽��SE
�����P�FeBGM _bgm:�Đ������m�肽��BGM
�����P�FeEVM _evm:�Đ������m�肽��EVM
�߂�l�F(TRUE)�Đ����@(FALSE)�Đ�����Ă��Ȃ�
�⑫�@�F�������ɃI�[�o�[���[�h�L
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
���O�@�Fbool CheckValidArgument(eSE _se);
�T�v�@�FSE�̈��������݂��邩�𒲂ׂ�
�����P�FeSE _se:���ׂ����l
�����P�FeBGM _bgm:���ׂ����l
�����P�FeEVM _evm:���ׂ����l
�߂�l�F(TRUE)�L���͈͓��@(FALSE)�L���͈͊O
�⑫�@�F�������ɃI�[�o�[���[�h�L
******************************************************/
bool cSound::CheckValidArgument(eSE _se) {
	if (_se < E_SE_LENGTH) {
		return TRUE;	//�L���͈͓�
	}
	else {
		ErrBox("���y�Đ��t�@�C���ɂėL���ł͂Ȃ��������n����܂���");
		return FALSE;	//�L���͈͊O
	}
}
bool cSound::CheckValidArgument(eBGM _bgm) {
	if (_bgm < E_BGM_LENGTH) {
		return TRUE;	//�L���͈͓�
	}
	else {
		ErrBox("���y�Đ��t�@�C���ɂėL���ł͂Ȃ��������n����܂���");
		return FALSE;	//�L���͈͊O
	}
}
bool cSound::CheckValidArgument(eEVM _evm) {
	if (_evm < E_EVM_LENGTH) {
		return TRUE;	//�L���͈͓�
	}
	else {
		ErrBox("���y�Đ��t�@�C���ɂėL���ł͂Ȃ��������n����܂���");
		return FALSE;	//�L���͈͊O
	}
}

/*****************************************************
���O�@�Fvoid ChangeSoundVolume();
�T�v�@�F���ʒl�̕ύX�𔽉f����
�����@�F�Ȃ�
�߂�l�F�Ȃ�
�⑫�@�F�l�̓t�@�C������ǂݎ��
******************************************************/
void cSound::ChangeSoundVolume() {
	
	string volume[E_VOL_LENGTH];	//�t�@�C������ǂݍ��񂾉��ʒl���i�[

	//�t�@�C�����特�ʐݒ�t�@�C���̒l��ǂݍ���
	ifstream ifs("../Data/Setting.txt");
	if (ifs.fail()) { DEBUG_LOG("�ݒ�t�@�C���ǂݍ��ݎ��s"); }

	//���ʂ��i�[
	for (int i = 0; i < E_VOL_LENGTH; i++) {
		getline(ifs, volume[i]);
		m_volume[i] = stoi(volume[i]);
	}

	ifs.close();

	//���ʕύX
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
	InitSoundMem();		//����S�č폜
}