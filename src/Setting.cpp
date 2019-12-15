#include "Setting.h"

cSetting::cSetting(){
	Init();
}

cSetting::~cSetting(){
	End();
}

void cSetting::Init() {
	m_volume[0] = {0};
	m_settingEnd = FALSE;

	string volume[E_VOL_LENGTH];
	ifstream ifs("../Data/Setting.txt");
	if (ifs.fail()) {DEBUG_LOG("�ݒ�t�@�C���ǂݍ��ݎ��s");}
	
	for (int i = 0; i < E_VOL_LENGTH;i++) {
		getline(ifs,volume[i]);
		m_volume[i] = stoi(volume[i]);
	}

	ifs.close();

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

		//���ʂ̒���
		for (int i = 0; i < E_VOL_LENGTH;i++) {
			for (int j = 0; j < 2; j++) {
				if (m_volBtn[i][j].ButtonClick() == TRUE) {
					if (j % 2 == 0) { m_volume[i]--; }
					else{ m_volume[i]++; }

					cSound::Instance()->PlaySE(cSound::Instance()->E_SE_SELECT);
				}
			}

		}
	}

	
}

void cSetting::SoundSettingApp() {

	ofstream ofs("../Data/Setting.txt");
	if (ofs.fail()) { DEBUG_LOG("�ݒ�t�@�C���ǂݍ��ݎ��s"); }

	for (int i = 0; i < E_VOL_LENGTH; i++) {
		ofs << to_string(m_volume[i]) << endl;
	}

	ofs.close();

	//TODO:enum�Ԗڂ�������������
	cSound::Instance()->ChangeSoundVolume();
}

bool cSetting::GetEndSetting() {

	return m_settingEnd;
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