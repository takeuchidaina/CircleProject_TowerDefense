#include "Title.h"

cTitle::cTitle(ISceneChanger* _scene) : cBaseScene(_scene) {
	cTitle::Init();
}

void cTitle::Init() {

	// x,y,eMenu,name
#ifndef TITLE_DEBUG
	m_menu[E_TITLE_GAME] = { TEXT_X,TEXT_Y,E_TITLE_GAME,"�Q�[���J�n" },
	m_menu[E_TITLE_END] = { TEXT_X,TEXT_Y + FONT_SIZE,E_TITLE_END,"�Q�[���I��" };
#endif // !TITLE_DEBUG

#ifdef TITLE_DEBUG
	m_menu[E_TITLE_MENU]   = { TEXT_X,TEXT_Y,E_TITLE_MENU,"���j���[" },
	m_menu[E_TITLE_GAME]   = { TEXT_X,TEXT_Y + (FONT_SIZE * E_TITLE_GAME) ,E_TITLE_GAME,"�Q�[��" },
	m_menu[E_TITLE_RESULT] = { TEXT_X,TEXT_Y + (FONT_SIZE * E_TITLE_RESULT),E_TITLE_GAME,"���U���g" },
	m_menu[E_TITLE_END]    = { TEXT_X,TEXT_Y + (FONT_SIZE * E_TITLE_END),E_TITLE_END,"�I��" };
#endif // TITLE_DEBUG

	nowSelect = 0;
}

void cTitle::Update() {

	//�Ȃ����V�[���̕ύX����s���Ă���
	
	//���ڂ̈ړ�
	if (GET_KEY_PRESS(KEY_INPUT_DOWN) == 1) {
		nowSelect++;
	}
	if (GET_KEY_PRESS(KEY_INPUT_UP) == 1) {
		nowSelect--;
	}

	//���ڂ̈ړ��̏���ɂ�鏈��
	if (nowSelect < 0) {
		nowSelect = m_menu[menuNum-1].menu;
	}
	nowSelect %= menuNum;

#ifndef TITLE_DEBUG
	//���ڂ�I��������ԂŃG���^�[�������ƃV�[���ύX
	if (GET_KEY_PRESS(KEY_INPUT_RETURN) == 1) {
		switch (nowSelect)
		{
		case E_TITLE_GAME:
			sceneChanger->ChangeScene(E_SCENE_MENU);
			break;
		case E_TITLE_END:
			DxLib_End();
			break;
		default:
			break;
		}
	}
#endif // !TITLE_DEBUG

#ifdef TITLE_DEBUG
	//���ڂ�I��������ԂŃG���^�[�������ƃV�[���ύX
	if (GET_KEY_PRESS(KEY_INPUT_RETURN) == 1) {
		switch (nowSelect)
		{
		case E_TITLE_MENU:
			sceneChanger->ChangeScene(E_SCENE_MENU);
			break;
		case E_TITLE_GAME:
			sceneChanger->ChangeScene(E_SCENE_GAME);
			break;
		case E_TITLE_RESULT:
			sceneChanger->ChangeScene(E_SCENE_RESULT);
			break;
		case E_TITLE_END:
			DxLib_End();
			break;
		default:
			break;
		}
	}
#endif // TITLE_DEBUG

}

void cTitle::Draw() {

	//cBaseScene::Draw();

	//�����̕\��
	for (int i = 0; i < menuNum; i++) {
		DrawFormatString(m_menu[i].x,m_menu[i].y,WH,m_menu[i].text);
	}

	DrawFormatString(m_menu[nowSelect].x - FONT_SIZE, m_menu[nowSelect].y, WH, "��");
	
	

#ifdef TITLE_DEBUG
	DrawFormatString(0, 0, WH, "�^�C�g�����");
	DrawFormatString(0, 20, WH, "nowselect:%d",nowSelect);
	DrawFormatString(0, 40, WH, "enumNum:%d", E_TITLE_MAX);
#endif // TITLE_DEBUG

}

void cTitle::End() {
	//
}