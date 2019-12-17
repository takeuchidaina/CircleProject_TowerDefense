#include "Setting.h"

cSetting::cSetting(){
	Init();
}

cSetting::~cSetting(){
	End();
}

void cSetting::Init() {

	m_volume[0] = { 0 };
	string volume[E_VOL_LENGTH];	//�t�@�C���ɋL�����Ă��鉹�ʂ��i�[

	ifstream ifs("../Data/Setting.txt");
	if (ifs.fail()) {DEBUG_LOG("�ݒ�t�@�C���ǂݍ��ݎ��s");}
	
	for (int i = 0; i < E_VOL_LENGTH;i++) {
		getline(ifs,volume[i]);
		m_volume[i] = stoi(volume[i]);
	}

	ifs.close();

	
	m_settingEnd = FALSE;

	//����E�߂�E�K�p�@�{�^��
	const int fontSize = 30,posX = 410,posY = 420, transe = 150,rectSpace = 50;
	sRECT rect = {	/*����y*/posY,
					/*����x*/posX,
					/*�E��x*/posX + fontSize * /*�������{���E�̗]��*/ 4 ,
					/*�E��y*/posY + fontSize * /*�����񐔁{�㉺�̗]��*/ 3 };
	m_btn[E_BTN_ENTER].Init(rect,transe,"����", fontSize);

	sRECT rect2 = {	/*����y*/posY,
					/*����x*/rect.right + rectSpace,
					/*�E��x*/rect.right + rectSpace + fontSize * /*�������{���E�̗]��*/ 4,
					/*�E��y*/posY + fontSize * /*�����񐔁{�㉺�̗]��*/ 3 };
	m_btn[E_BTN_CANSEL].Init(rect2, transe, "�߂�", fontSize);

	sRECT rect3 ={	/*����y*/posY,
					/*����x*/rect2.right + rectSpace,
					/*�E��x*/rect2.right + rectSpace + fontSize * /*�������{���E�̗]��*/ 4,	
					/*�E��y*/posY + fontSize * /*�����񐔁{�㉺�̗]��*/ 3 };
	m_btn[E_BTN_APP].Init(rect3, transe, "�K�p", fontSize);


	//���ʂ�ω������� < > �{�^��
	const int volPosX = 600, volPosY = 250;
	for (int i = 0; i < E_VOL_LENGTH;i++) {
		for (int j = 0; j < 2;j++) {
			sRECT volRect;
			if (j == 0) {
				volRect = {	/*����y*/volPosY + (i * fontSize * 2),
							/*����x*/volPosX,
							/*�E��x*/volPosX + fontSize * 2,
							/*�E��y*/volPosY + (i * fontSize * 2) + fontSize };
				m_volBtn[i][0].Init(volRect, transe, "<", fontSize);
			}
			else {
				volRect = {	/*����y*/volPosY + (i * fontSize * 2),
							/*����x*/volPosX + fontSize * 5,
							/*�E��x*/volPosX + fontSize * 5 + fontSize * 2,
							/*�E��y*/(volPosY + (i * fontSize * 2)) + fontSize };
				m_volBtn[i][1].Init(volRect, transe, ">", fontSize);
			}
		}
	}

}

void cSetting::Update() {

	//���ڈȍ~�̌Ăяo�����Ɏg�p�����
	//FALSE�ɂ��鏈�����Ȃ��Ɛݒ肪�I���������ɂȂ�
	if (m_settingEnd == TRUE) {
		m_settingEnd = FALSE;
	}

	//�{�^���N���b�N����
	if (MOUSE_PRESS(LEFT_CLICK) == 1) {
		//����
		if (m_btn[E_BTN_ENTER].ButtonClick() == TRUE) {
			SoundSettingApp();
			cSound::Instance()->PlaySE(cSound::Instance()->E_SE_SELECT);
			m_settingEnd = TRUE;
		}
		//�L�����Z��
		else if (m_btn[E_BTN_CANSEL].ButtonClick() == TRUE) {
			cSound::Instance()->PlaySE(cSound::Instance()->E_SE_CANSEL);
			m_settingEnd = TRUE;
		}
		//�K�p
		else if (m_btn[E_BTN_APP].ButtonClick() == TRUE) {
			cSound::Instance()->PlaySE(cSound::Instance()->E_SE_SELECT);
			SoundSettingApp();
		}
	}

	//�{�^�����N���b�N����Ă����
	if (MOUSE_PRESS(LEFT_CLICK) >= 1) {
		//���ʂ̒��� < > �̃}�E�X����
		for (int i = 0; i < E_VOL_LENGTH; i++) {
			for (int j = 0; j < 2; j++) {
				if (m_volBtn[i][j].ButtonClick() == TRUE) {
					if (j % 2 == 0) { m_volume[i]--; }	//���ʂ�������
					else { m_volume[i]++; }				//���ʂ��グ��

					cSound::Instance()->PlaySE(cSound::Instance()->E_SE_SELECT);
				}
			}

		}
	}
	
}

void cSetting::Draw() {

	//�w�i�̎l�p
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);	//������
	DrawBox(400,200,WINDOW_WIDTH - 400,WINDOW_HEIGHT - 200,BK,TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);	//���������I�t

	//����
	SetFontSize(FONT_SIZE);
	int topPos = 250;
	DrawFormatString(450, topPos, WH, "����VOL�@�@�@%d",m_volume[E_VOL_EVM]);
	DrawFormatString(450, topPos + FONT_SIZE*2, WH, "BGM   VOL�@�@�@%d", m_volume[E_VOL_BGM]);
	DrawFormatString(450, topPos + FONT_SIZE*4, WH, "SE    VOL�@�@�@%d", m_volume[E_VOL_SE]);

	//�{�^���\��
	for (int i = 0; i < E_BTN_LENGTH; i++) {
		m_btn[i].Draw();
	}

	for (int i = 0; i < E_VOL_LENGTH;i++) {
		for (int j = 0; j < 2;j++) {
			m_volBtn[i][j].Draw();
		}
	}

}

void cSetting::End() {

}

/*****************************************************
���O�@�Fvoid ChangeScene(eScene _nextScene)
�T�v�@�F�t�@�C���։��ʂ���������
�����@�F�Ȃ�
�߂�l�F�Ȃ�
******************************************************/
void cSetting::SoundSettingApp() {

	//TODO:enum�Ԗڂ�������������
	//�t�@�C���ɕύX��̉��ʒl����������
	ofstream ofs("../Data/Setting.txt");
	if (ofs.fail()) { DEBUG_LOG("�ݒ�t�@�C���ǂݍ��ݎ��s"); }

	for (int i = 0; i < E_VOL_LENGTH; i++) {
		ofs << to_string(m_volume[i]) << endl;
	}

	ofs.close();

	//�t�@�C����ǂݍ��݂Ȃ���
	cSound::Instance()->ChangeSoundVolume();
}

/*****************************************************
���O�@�Fbool GetEndSetting()
�T�v�@�F�ݒ肪�ύX���I����Ă��邩�̃t���O��Ԃ�
�����@�F�Ȃ�
�߂�l�Fbool m_setteingEnd  �ݒ肪�I�����Ă��邩�ǂ���
		TRUE:�I���@FALSE�F�ݒ蒆
******************************************************/
bool cSetting::GetEndSetting() {

	return m_settingEnd;
}