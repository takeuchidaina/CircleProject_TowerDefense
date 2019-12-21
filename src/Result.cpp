#include "Result.h"

cResult::cResult(ISceneChanger* _scene) : cBaseScene(_scene) {
	
}

void cResult::Init() {

	//�^�C�g���o�b�N�̃{�^��
	m_image = {/*����y*/600,/*����x*/880,/*�E��x*/1180,/*�E��y*/700,"../resource/img/TitleEndButton.png" };
	m_image.handle = LoadGraph(m_image.filePath.c_str());
	FileCheck(m_image.handle);
	m_btn.Init(m_image.rect,m_image.filePath.c_str());

	//���s���ʂ��t�@�C������ǂݎ��
	FILE* fp;
	errno_t err; // errno_t�^(int�^)
	err = fopen_s(&fp, "../result.txt", "r"); // �t�@�C�����J���B���s����ƃG���[�R�[�h��Ԃ��B
	if (err != 0) {
		DEBUG_LOG("file not open");
	}

	char result[256];

	//���s���ʂɉ����ĕ\������摜��ύX
	if (fgets(result, 256, fp) != NULL) {
		if (result[0] == 'w') {
			m_BG = LoadGraph("../resource/img/seikou.png");
			cSound::Instance()->PlaySE(cSound::Instance()->E_SE_WIN);
			
			m_result = TRUE;
		}
		else {
			m_BG = LoadGraph("../resource/img/sippai.png");
			cSound::Instance()->PlaySE(cSound::Instance()->E_SE_LOSE);
			
			m_result = FALSE;
		}
	}

	fclose(fp);

	m_sound = FALSE;

}

void cResult::Update() {

	//�N���b�N���ꂽ��{�^���̏ォ���f
	if (MOUSE_PRESS(LEFT_CLICK) == 1) {
		if (m_btn.ButtonClick() == TRUE) {

			//�L�����Z����
			cSound::Instance()->PlaySE(cSound::Instance()->E_SE_CANSEL, cSound::Instance()->E_PLAY_NORMAL);		

			//�^�C�g����
			m_sceneChanger->ChangeScene(E_SCENE_TITLE);		
		}
	}

	//ME����I��������BGM�����[�v�Đ�(1��̂�)
	if (m_sound == FALSE) {
		if (m_result == TRUE && cSound::Instance()->CheckSound(cSound::Instance()->E_SE_WIN) == FALSE) {
			cSound::Instance()->PlayBGM(cSound::Instance()->E_BGM_WIN);
			m_sound = TRUE;
		}
		else if (m_result == FALSE && cSound::Instance()->CheckSound(cSound::Instance()->E_SE_LOSE) == FALSE) {
			cSound::Instance()->PlayBGM(cSound::Instance()->E_BGM_LOSE);
			m_sound = TRUE;
		}
	}
}

void cResult::Draw() {

	//�w�i�`��
	DrawGraph(0, /*Y���W����*/ -130,m_BG,FALSE);

	//�{�^���`��
	m_btn.Draw();

}

void cResult::End() {
	DeleteGraph(m_image.handle);	//�摜�폜

	if (m_result == TRUE) {
		if (cSound::Instance()->CheckSound(cSound::Instance()->E_SE_WIN) == TRUE) {
			cSound::Instance()->StopSound(cSound::Instance()->E_SE_WIN);
		}
		if (m_sound == TRUE) {
			cSound::Instance()->StopSound(cSound::Instance()->E_BGM_WIN);
		}
	}
	else {
		if (cSound::Instance()->CheckSound(cSound::Instance()->E_SE_LOSE) == TRUE) {
			cSound::Instance()->StopSound(cSound::Instance()->E_SE_LOSE);
		}
		if (m_sound == TRUE) {
			cSound::Instance()->StopSound(cSound::Instance()->E_BGM_LOSE);
		}
	}
}