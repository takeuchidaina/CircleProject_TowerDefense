#include "Menu.h"

cMenu::cMenu(ISceneChanger* _scene) : cBaseScene(_scene) {
}

void cMenu::Init() {
	m_stageSelect = 0;
}

void cMenu::Update() {

	if (GET_KEY_PRESS(KEY_INPUT_UP) == 1) {
		m_stageSelect++;
	}
	if (GET_KEY_PRESS(KEY_INPUT_DOWN) == 1) {
		m_stageSelect--;
	}
	if (m_stageSelect < 1) {
		m_stageSelect = 1;
	}

	if (GET_KEY_PRESS(KEY_INPUT_RETURN) == 1) {
		
		FILE* fp;

		errno_t err; // errno_t�^(int�^)
		err = fopen_s(&fp, "../StageSelect.txt", "w"); // �t�@�C�����J���B���s����ƃG���[�R�[�h��Ԃ��B
		if (err != 0) {
			DEBUG_LOG("file not open");
		}
		fprintf(fp,"%d",m_stageSelect);

		fclose(fp);

		m_sceneChanger->ChangeScene(E_SCENE_GAME);
	}
		

#ifdef MENU_DEBUG

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

#endif // MENU_DEBUG

}

void cMenu::Draw() {

	cBaseScene::Draw();

	DrawFormatString(400,400,WH,"�㉺���ŃX�e�[�W����I��");
	DrawFormatString(400, 420, WH, "�X�e�[�W�ԍ��F%d",m_stageSelect);
	DrawFormatString(400, 440, WH, "�G���^�[�ŃX�e�[�W����");

#ifdef MENU_DEBUG
	DrawFormatString(0, 0, WH, "���j���[���");
#endif // MENU_DEBUG

}

void cMenu::End() {

}