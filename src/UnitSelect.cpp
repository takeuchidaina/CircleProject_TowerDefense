#include "UnitSelect.h"

cUnitSelect::cUnitSelect(ISceneChanger* _scene) : cBaseScene(_scene) {
	CSVFilePath = "../resource/csv/UnitData.csv";
	selectUnitRect.top = 400; selectUnitRect.left = 640; selectUnitRect.right = 740; selectUnitRect.bottom = 500;

	okButtonRect.top = 600;	okButtonRect.left = 900; okButtonRect.right = 1200; okButtonRect.bottom = 700;
	resetButtonRect.top = 600;	resetButtonRect.left = 600; resetButtonRect.right = 900; resetButtonRect.bottom = 700;
	backButtonRect.top = 600; backButtonRect.left = 100; backButtonRect.right = 400; backButtonRect.bottom = 700;

	ImageFilePath = "../resource/img/";
	pathBG = "../resource/img/SelectScene_BG.jpg";
	pathUI = "../resource/img/UI_BG.png";
	pathImage1 = "../resource/img/3.png";
}

void cUnitSelect::Init() {
	unitCostNum = 0;

	pathBGGraph = LoadGraph(pathBG.c_str());
	pathUIGraph = LoadGraph(pathUI.c_str());
	pathImage1Graph = LoadGraph(pathImage1.c_str());

	//���j�b�g�f�[�^�ǂݍ���
	unitData = UnitLoad(CSVFilePath);
	tmpGraph = new int* [unitData.size()];
	for (int i = 0; i < unitData.size(); i++) {
		tmpGraph[i] = new int[10];
	}

	//�e��{�^������
	cButton tmpButton;

	for (int i = 0; i < unitData.size(); i++) {
		unitButton.push_back(tmpButton);
		sRECT tmpRect;
		tmpRect.top = 100 + (i / 5) * 100;
		tmpRect.left = 640 + (i % 5) * 100;
		tmpRect.bottom = 200 + (i / 5) * 100;
		tmpRect.right = 740 + (i % 5) * 100;

		//cButton Init���� RECT:�E��ƍ������W(top,left,right,buttom) filePath:�t�@�C���p�X
		//cButton Init(sRECT _rect, const char* _filepth);
		//cButton Init(sRECT _rect, short _transNum, const char* _text, short _fontSize);
		unitButton[i].Init(tmpRect, pathUI.c_str());
		LoadDivGraph((ImageFilePath + unitData[i].unitPath).c_str(), 10, 5, 2, 256, 256, tmpGraph[i]);
		graphArray.push_back(tmpGraph[i][0]);

		unitCostArray.push_back(unitData[i].cost);
	}

	okButton.Init(okButtonRect, (ImageFilePath + "Button_OK.png").c_str());
	resetButton.Init(resetButtonRect, (ImageFilePath + "Button_Reset.png").c_str());
	backButton.Init(backButtonRect, (ImageFilePath + "Button_Back.png").c_str());

	//���j�b�g�f�[�^�̉摜�f�[�^�̂ݏ���(���I�m�ۂ̂���)
	for (int i = 0; i < unitData.size(); i++) {
		delete[] tmpGraph[i];
	}
	delete[] tmpGraph;
}

void cUnitSelect::Update() {
	if (MOUSE_PRESS(LEFT_CLICK) == 1) {

		for (int i = 0; i < unitButton.size(); i++) {
			if (unitButton[i].ButtonClick() == true) {
				//auto itr = find(selectUnit.begin(), selectUnit.end(), i);
				//if (itr == selectUnit.end()) {
				if (unitCostNum + unitCostArray[i] <= MAP_COST) {
					selectUnit.push_back(i);
					unitCostNum += unitCostArray[i];
				}
				//}
			}
		}

		if (okButton.ButtonClick() == true) {
			if (selectUnit.size() > 0) {
				//�I������Ă��郆�j�b�g����n��
				//txt�t�@�C�������o��
				FILE* fp;

				errno_t err; // errno_t�^(int�^)
				err = fopen_s(&fp, "../UnitSelect.txt", "w"); // �t�@�C�����J���B���s����ƃG���[�R�[�h��Ԃ��B
				if (err != 0) {
					DEBUG_LOG("file not open");
				}
				for (int i = 0; i < selectUnit.size(); i++) {
					if (i == selectUnit.size() - 1) {				//�f�[�^�������Ȃ���s�Ȃ�
						fprintf(fp, "%d", selectUnit[i]);
					}
					else {
						fprintf(fp, "%d\n", selectUnit[i]);
					}
				}

				fclose(fp);

				m_sceneChanger->ChangeScene((eScene)E_SCENE_GAME);
			}
		}
		if (resetButton.ButtonClick() == true) {
			selectUnit.clear();
			unitCostNum = 0;
		}
		if (backButton.ButtonClick() == true) {
			m_sceneChanger->ChangeScene((eScene)E_SCENE_STAGESELECT);
		}
	}

	//�J�[�\���������Ă�Ƃ�
	for (int i = 0; i < unitButton.size(); i++) {
		if (unitButton[i].ButtonClick() == true) {
			unitCursorFlg = i;
			break;
		}
		else {
			unitCursorFlg = -1;
		}
	}
}

void cUnitSelect::Draw() {

	//�w�i
	DrawExtendGraph(0, 0, 1280, 960, pathBGGraph, true);


	//�{�^��
	for (int i = 0; i < unitButton.size(); i++) {

		sRECT tmpRect = unitButton[i].GetRect();

		unitButton[i].Draw();

		DrawExtendGraph(tmpRect.left, tmpRect.top, tmpRect.right, tmpRect.bottom, graphArray[i], true);

		DrawFormatString(tmpRect.left, tmpRect.top + 5, BK, "%d", unitCostArray[i]);
	}
	for (int i = 0; i < selectUnit.size(); i++) {

		DrawExtendGraph(
			selectUnitRect.left + (i % 5) * 100, selectUnitRect.top + (i / 5) * 100,
			selectUnitRect.right + (i % 5) * 100, selectUnitRect.bottom + (i / 5) * 100,
			pathUIGraph, true);

		DrawExtendGraph(
			selectUnitRect.left + (i % 5) * 100, selectUnitRect.top + (i / 5) * 100,
			selectUnitRect.right + (i % 5) * 100, selectUnitRect.bottom + (i / 5) * 100,
			graphArray[selectUnit[i]], TRUE);

		DrawFormatString(selectUnitRect.left + (i % 5) * 100, selectUnitRect.top + 5 + (i / 5) * 100, BK, "%d", unitCostArray[selectUnit[i]]);

	}

	//���j�b�g�{�^����̃R�X�g
	DrawExtendGraph(840, 80, 1040, 100, pathUIGraph, true);
	DrawFormatString(850, 85, BK, "�R�X�g : %d / %d", unitCostNum, MAP_COST);

	DrawExtendGraph(640, 80, 840, 100, pathUIGraph, true);
	DrawFormatString(680, 85, BK, "���j�b�g��I��");


	//���̕�
	DrawExtendGraph(100, 50, 540, 550, pathUIGraph, true);

	SetFontSize(30);
	if (unitCursorFlg != -1) {
		switch (unitData[unitCursorFlg].type) {
		case 0: DrawFormatString(130, 100, BK, "�^�C�v�FSord"); break;
		case 1: DrawFormatString(130, 100, BK, "�^�C�v�FArchar"); break;
		case 2: DrawFormatString(130, 100, BK, "�^�C�v�FShield"); break;
		}
		DrawFormatString(130, 150, BK, "HP�F%d", unitData[unitCursorFlg].HP);
		DrawFormatString(130, 200, BK, "ATK�F%d", unitData[unitCursorFlg].ATK);
		DrawFormatString(130, 250, BK, "�U���N�[���^�C���F%df", unitData[unitCursorFlg].coolTime);
		DrawFormatString(130, 300, BK, "�R�X�g�F%d", unitData[unitCursorFlg].cost);
	}

	DrawExtendGraph(210, 340, 410, 540, pathImage1Graph, true);

	okButton.Draw();
	resetButton.Draw();
	backButton.Draw();
}

void cUnitSelect::End() {
}