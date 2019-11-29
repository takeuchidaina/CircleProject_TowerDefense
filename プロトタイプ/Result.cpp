#include "Result.h"

cResult::cResult(ISceneChanger* _scene) : cBaseScene(_scene) {
	Init();
}

void cResult::Init() {
	FILE* fp;

	errno_t err; // errno_t�^(int�^)
	err = fopen_s(&fp, "../result.txt", "r"); // �t�@�C�����J���B���s����ƃG���[�R�[�h��Ԃ��B
	if (err != 0) {

	}

	char result[256];
	if (fgets(result, 256, fp) != NULL){
		if (result[0] == 'w') {
			m_image = LoadGraph("../resource/img/seikou.png");
		}
		else {
			m_image = LoadGraph("../resource/img/sippai.png");
		}
	}

	fclose(fp);
}

void cResult::Update() {
	
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

	DrawGraph(0, -130,m_image,FALSE);
#ifdef RESULT_DEBUG
	DrawFormatString(500, 400, RD, "GAME CLEAR");
	DrawFormatString(0, 0, WH, "���U���g���");
#endif // RESULT_DEBUG

}

void cResult::End() {
	DeleteGraph(m_image);
}