#include "Menu.h"

cMenu::cMenu(ISceneChanger* _scene) : cBaseScene(_scene) {
}

void cMenu::Init() {
	//���j���[�̏�����
//����y, ����x, �E��x, �E��y, �摜�t�@�C���p�X,�ړ���V�[��
	m_menu[E_MENU_NSCENE] =  { {/*����y*/600,/*����x*/170,/*�E��x*/470,/*�E��y*/700,"../resource/img/Button_Start.png" },E_SCENE_STAGESELECT };
	m_menu[E_MENU_SETTING] = { {/*����y*/600,/*����x*/490,/*�E��x*/790,/*�E��y*/700,"../resource/img/Button_Setting.png" }, E_SCENE_NONE };
	m_menu[E_MENU_BACK] =	 { {/*����y*/600,/*����x*/810,/*�E��x*/1130,/*�E��y*/700,"../resource/img/Button_BACK.png" }, E_SCENE_TITLE };
	for (int i = 0; i < E_TITLE_MAX; i++) {
		m_btn[i].Init(m_menu[i].image.rect, m_menu[i].image.filePath.c_str());
	}

	//�`���[�g���A���摜
	m_btnSetumeiRect[E_TUTO_TAKARA] =	{/*����y*/100,/*����x*/30,		   /*�E��x*/30 + 400,	   /*�E��y*/400 };
	m_btnSetumeiRect[E_TUTO_SOUSA]	=	{/*����y*/100,/*����x*/30 + 400 + 10,/*�E��x*/30 + 800 + 10 ,/*�E��y*/400 };
	m_btnSetumeiRect[E_TUTO_TYPE]	=	{/*����y*/100,/*����x*/30 + 800 + 20,/*�E��x*/30 + 1200 + 20,/*�E��y*/400 };
	m_btnSetumeiRect[E_TUTO_EXPANTION] = { 50,150,1280 - 150,720 - 150 };
	m_setumeiFilePath[E_TUTO_TAKARA] = "../resource/img/Menu_Setumei1.jpg";
	m_setumeiFilePath[E_TUTO_SOUSA] = "../resource/img/Menu_Setumei2.jpg";
	m_setumeiFilePath[E_TUTO_TYPE] = "../resource/img/Menu_Setumei3.jpg";
	m_setumeiFilePath[E_TUTO_EXPANTION] = m_setumeiFilePath[0];
	for (int i = 0; i < E_TUTO_LENGTH; i++) {
		m_btnSetumei[i].Init(m_btnSetumeiRect[i], m_setumeiFilePath[i].c_str());
	}
	isExpantion = FALSE;

	//�摜�̏�����
	m_image[E_BACK_GROUND] = { 0,0,1280,960,"../resource/img/BackGround.jpg" };
	//m_image[E_LOGO] = { 50,0,1330,960,"../resource/img/TitleLogo.png"};
	for (int i = 0; i < E_IMAGE_MAX; i++) {
		m_image[i].handle = LoadGraph(m_image[i].filePath.c_str());
		FileCheck(m_image[i].handle);
	}

	//�^�C�g���pBGM�̍Đ�
	cSound::Instance()->PlayBGM(cSound::Instance()->E_BGM_TITLE, cSound::Instance()->E_PLAY_LOOP, TRUE);
	
}

void cMenu::Update() {

	//���N���b�N
	if (MOUSE_PRESS(LEFT_CLICK) == 1) {

		//�{�^���̏�ŃN���b�N����Ă��邩���f
		for (int i = 0; i < E_TITLE_MAX; i++) {
			if (m_btn[i].ButtonClick() == TRUE) {

				//TODO:if elseif�ŏI�����f������ChangeScene�����ŏ������s��
				//START�{�^��
				if (m_menu[i].menu == E_SCENE_STAGESELECT) {
					cSound::Instance()->PlaySE(cSound::Instance()->E_SE_SELECT);		//���艹
					m_sceneChanger->ChangeScene((eScene)m_menu[i].menu);				//�V�[����ύX
				}
				//SETTING�{�^��
				else if (m_menu[i].menu == E_SCENE_NONE) {
					cSound::Instance()->PlaySE(cSound::Instance()->E_SE_SELECT);		//���艹
					m_sceneChanger->SettingStart();
				}
				//BACK�{�^��
				else if (m_menu[i].menu == E_SCENE_TITLE) {
					cSound::Instance()->PlaySE(cSound::Instance()->E_SE_CANSEL, cSound::Instance()->E_PLAY_NORMAL);		//�L�����Z����
					m_sceneChanger->ChangeScene((eScene)m_menu[i].menu);
				}
			}
		}

		//�`���[�g���A���{�^��
		for (int i = 0; i < E_TUTO_LENGTH-1; i++) {
			if (m_btnSetumei[i].ButtonClick() == TRUE && isExpantion == FALSE) {
				m_setumeiFilePath[E_TUTO_EXPANTION] = m_setumeiFilePath[i].c_str();
				m_btnSetumei[E_TUTO_EXPANTION].Init(m_btnSetumeiRect[E_TUTO_EXPANTION], m_setumeiFilePath[E_TUTO_EXPANTION].c_str());
				cSound::Instance()->PlaySE(cSound::Instance()->E_SE_SELECT);		//���艹
				isExpantion = TRUE;
				break;
			}
			else if (m_btnSetumei[i].ButtonClick() == FALSE && isExpantion == TRUE) {
				isExpantion = FALSE;
				break;
			}
		}
	}


}

void cMenu::Draw() {
	//�摜�\�� (���w�i������̂ň�ԍŏ��ɌĂяo������)
	for (int i = 0; i < E_IMAGE_MAX; i++) {
		DrawExtendGraph(m_image[i].rect.left, m_image[i].rect.top,
			m_image[i].rect.right, m_image[i].rect.bottom, m_image[i].handle, TRUE);
	}

	//�{�^���\��
	for (int i = 0; i < E_TITLE_MAX; i++) {
		m_btn[i].Draw();
	}

	//�`���[�g���A���\��
	for (int i = 0; i < E_TUTO_LENGTH-1; i++) {
		m_btnSetumei[i].DrawJPG();
	}
	if (isExpantion == TRUE) {
		m_btnSetumei[E_TUTO_EXPANTION].DrawJPG();
	}

}

void cMenu::End() {
	//�摜�n���h���̍폜
	for (int i = 0; i < E_IMAGE_MAX; i++) {
		DeleteGraph(m_image[i].handle);
	}
	cSound::Instance()->StopSound(cSound::Instance()->E_BGM_TITLE);		//BGM���~�߂�
}