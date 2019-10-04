#include "Title.h"

cTitle::cTitle(ISceneChanger* _scene) : cBaseScene(_scene) {
}

void cTitle::Init() {

	
#ifdef TITLE_DEBUG
	// x,y,eMenu,name
	m_menu[E_TITLE_MENU]   = { TEXT_X,TEXT_Y,E_TITLE_MENU,"���j���[" },
	m_menu[E_TITLE_GAME]   = { TEXT_X,TEXT_Y + (FONT_SIZE * E_TITLE_GAME) ,E_TITLE_GAME,"�Q�[��" },
	m_menu[E_TITLE_RESULT] = { TEXT_X,TEXT_Y + (FONT_SIZE * E_TITLE_RESULT),E_TITLE_GAME,"���U���g" },
	m_menu[E_TITLE_END]    = { TEXT_X,TEXT_Y + (FONT_SIZE * E_TITLE_END),E_TITLE_END,"�I��" };
#endif // TITLE_DEBUG

	nowSelect = 0;

	//�w�i
	m_background = LoadGraph("../resource/img/TitleBackGround.jpg");
	if (m_background == NULL) {
		//error
	}
	//���S
	m_logo = LoadGraph("../resource/img/TitleLogo.png");
	if (m_logo == NULL) {
		//error
	}
	//�J�n�{�^��
	m_startButton = LoadGraph("../resource/img/TitleStartButton.png");
	if (m_startButton == NULL) {
		//error
	}
	//�I���{�^��
	m_endButton = LoadGraph("../resource/img/TitleEndButton.png");
	if (m_endButton == NULL) {
		//error
	}

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
		nowSelect = m_menu[m_menuNum-1].menu;
	}
	nowSelect %= m_menuNum;


#ifdef TITLE_DEBUG
	//���ڂ�I��������ԂŃG���^�[�������ƃV�[���ύX
	if (GET_KEY_PRESS(KEY_INPUT_RETURN) == 1) {
		switch (nowSelect)
		{
		case E_TITLE_MENU:
			m_sceneChanger->ChangeScene(E_SCENE_MENU);
			break;
		case E_TITLE_GAME:
			m_sceneChanger->ChangeScene(E_SCENE_GAME);
			break;
		case E_TITLE_RESULT:
			m_sceneChanger->ChangeScene(E_SCENE_RESULT);
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

	DrawGraph(0, 0, m_background, TRUE);	//�w�i
	DrawGraph(50, -100, m_logo, TRUE);		//���S
	DrawGraph(640-225, 400, m_startButton, TRUE);	//�J�n�{�^��
	DrawGraph(640-225, 550, m_endButton, TRUE);		//�I���{�^��
	//DrawGraph(95, 500, m_startButton, TRUE);	//�J�n�{�^��
	//DrawGraph(735, 500, m_endButton, TRUE);	//�I���{�^��

	//�����̕\��
	for (int i = 0; i < m_menuNum; i++) {
		DrawFormatString(m_menu[i].x,m_menu[i].y,WH,m_menu[i].text);
	}

	//�I�����ڂ̉��ɖ���\��
	DrawFormatString(m_menu[nowSelect].x - FONT_SIZE, m_menu[nowSelect].y, WH, "��");

#ifdef TITLE_DEBUG
	DrawFormatString(0, 0, WH, "�^�C�g�����");
#endif // TITLE_DEBUG

}

void cTitle::End() {
	//�摜�n���h���̍폜
	DeleteGraph(m_background);
	DeleteGraph(m_logo);
	DeleteGraph(m_startButton);
	DeleteGraph(m_endButton);
}