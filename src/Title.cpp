#include "Title.h"

cTitle::cTitle(ISceneChanger* _scene) : cBaseScene(_scene) {
}

void cTitle::Init() {

	//���j���[�̏�����
	//����y, ����x, �E��x, �E��y, �摜�t�@�C���p�X,�ړ���V�[��
	m_menu[E_TITLE_MENU] = { {/*����y*/600,/*����x*/100,/*�E��x*/400,/*�E��y*/700,"../resource/img/Button_Start.png" },E_SCENE_MENU };
	m_menu[E_TITLE_END]  = { {/*����y*/600,/*����x*/420,/*�E��x*/720,/*�E��y*/700,"../resource/img/Button_End.png" }, E_SCENE_END };
	for (int i = 0; i < E_TITLE_MAX; i++) {
		m_btn[i].Init(m_menu[i].image.rect,m_menu[i].image.filePath.c_str());
	}

	//�摜�̏�����
	m_image[E_BACK_GROUND] = { 0,0,1280,960,"../resource/img/TitleBG.png"};
	//m_image[E_LOGO] = { 50,0,1330,960,"../resource/img/TitleLogo.png"};
	for (int i = 0; i < E_IMAGE_MAX;i++) {
		m_image[i].handle = LoadGraph(m_image[i].filePath.c_str());
		FileCheck(m_image[i].handle);
	}

	//�^�C�g���pBGM�̍Đ�
	cSound::Instance()->PlayEVM(
		cSound::Instance()->E_EVM_SEA_ROUGH, cSound::Instance()->E_PLAY_LOOP,TRUE);
}

void cTitle::Update() {

	//���N���b�N
	if (MOUSE_PRESS(LEFT_CLICK) == 1) {

		//�{�^���̏�ŃN���b�N����Ă��邩���f
		for (int i = 0; i < E_TITLE_MAX;i++) {
			if (m_btn[i].ButtonClick() == TRUE) {

				//TODO:if elseif�ŏI�����f������ChangeScene�����ŏ������s��
				//START�{�^��
				if (m_menu[i].menu == E_SCENE_MENU) {
					cSound::Instance()->PlaySE(cSound::Instance()->E_SE_SELECT);		//���艹
					cSound::Instance()->StopSound(cSound::Instance()->E_EVM_SEA_ROUGH);		//BGM���~�߂�
					m_sceneChanger->ChangeScene((eScene)m_menu[i].menu);				//�V�[����ύX
				}
				//END�{�^��
				else if (m_menu[i].menu == E_SCENE_END) {
					cSound::Instance()->PlaySE(cSound::Instance()->E_SE_CANSEL, cSound::Instance()->E_PLAY_NORMAL);		//�L�����Z����
					cSound::Instance()->StopSound(cSound::Instance()->E_EVM_SEA_ROUGH);		//BGM���~�߂�
					cSound::Instance()->End();
					DxLib_End();
				}
			}
		}
	}

}

void cTitle::Draw() {

	//�摜�\�� (���w�i������̂ň�ԍŏ��ɌĂяo������)
	for (int i = 0; i < E_IMAGE_MAX; i++) {
		DrawExtendGraph(m_image[i].rect.left, m_image[i].rect.top,
			m_image[i].rect.right, m_image[i].rect.bottom, m_image[i].handle, TRUE);
	}

	//�{�^���\��
	for (int i = 0; i < E_TITLE_MAX; i++) {
		m_btn[i].Draw();
	}

}

void cTitle::End() {

	//�摜�n���h���̍폜
	for (int i = 0; i < E_IMAGE_MAX; i++) {
		DeleteGraph(m_image[i].handle);
	}
}