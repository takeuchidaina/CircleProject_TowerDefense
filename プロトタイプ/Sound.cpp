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
	m_SEPath[0] = { "../resource/Sound/SE/test.wav"};
	m_SEList[0] = LoadSoundMem(m_SEPath[0].c_str());
	FileCheck(m_SEList[0]);

	m_BGMPath[0] = { "../resource/Sound/BGM/ÉGÉäÉJ.wav" };
	m_BGMList[0] = LoadSoundMem(m_BGMPath[0].c_str());
	FileCheck(m_BGMList[0]);
}

void cSound::Update() {
	if (GET_KEY_PRESS(KEY_INPUT_S) == 1) {
		PlaySoundMem(m_SEList[0], DX_PLAYTYPE_NORMAL,FALSE);
	}
	if (GET_KEY_PRESS(KEY_INPUT_G) == 1) {
		PlaySoundMem(m_BGMList[0], DX_PLAYTYPE_BACK,FALSE);
	}
}

void cSound::Draw() {

}

void cSound::End() {

}