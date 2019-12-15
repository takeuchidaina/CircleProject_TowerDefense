#include "Result.h"

cResult::cResult(ISceneChanger* _scene) : cBaseScene(_scene) {
	Init();
}

void cResult::Init() {
	m_image = {/*����y*/600,/*����x*/880,/*�E��x*/1180,/*�E��y*/700,"../resource/img/TitleEndButton.png" };
	m_image.handle = LoadGraph(m_image.filePath.c_str());
	FileCheck(m_image.handle);

	m_btn.Init(m_image.rect,m_image.filePath.c_str());

	FILE* fp;

	errno_t err; // errno_t�^(int�^)
	err = fopen_s(&fp, "../result.txt", "r"); // �t�@�C�����J���B���s����ƃG���[�R�[�h��Ԃ��B
	if (err != 0) {
		DEBUG_LOG("file not open");
	}

	char result[256];
	if (fgets(result, 256, fp) != NULL) {
		if (result[0] == 'w') {
			m_BG = LoadGraph("../resource/img/seikou.png");
		}
		else {
			m_BG = LoadGraph("../resource/img/sippai.png");
		}
	}

	fclose(fp);

}

void cResult::Update() {

	//�N���b�N���ꂽ��{�^���̏ォ���f
	if (MOUSE_PRESS(LEFT_CLICK) == 1) {
		if (m_btn.ButtonClick() == TRUE) {
			cSound::Instance()->PlaySE(cSound::Instance()->E_SE_CANSEL);
			WaitTimer(200);
			m_sceneChanger->ChangeScene(E_SCENE_TITLE);
		}
	}
	
#ifdef RESULT_DEBUG
	DrawFormatString(0, 0, RD, "GAME CLEAR");
	//�^�C�g����
	if (GET_KEY_PRESS(KEY_INPUT_T) == 1) {
		m_sceneChanger->ChangeScene(E_SCENE_TITLE);
	}
	//���j���[��
	if (GET_KEY_PRESS(KEY_INPUT_M) == 1) {
		m_sceneChanger->ChangeScene(E_SCENE_MENU);
	}
	//�Q�[����
	if (GET_KEY_PRESS(KEY_INPUT_G) == 1) {
		m_sceneChanger->ChangeScene(E_SCENE_GAME);
	}
	//���U���g��
	if (GET_KEY_PRESS(KEY_INPUT_R) == 1) {
		m_sceneChanger->ChangeScene(E_SCENE_RESULT);
	}

#endif // RESULT_DEBUG

}

void cResult::Draw() {

	DrawGraph(0, /*Y���W����*/ -130,m_BG,FALSE);
	m_btn.Draw();

}

void cResult::End() {
	DeleteGraph(m_image.handle);
}