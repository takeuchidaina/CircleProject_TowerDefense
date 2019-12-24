#include "UnitSelect.h"

cUnitSelect::cUnitSelect(ISceneChanger* _scene) : cBaseScene(_scene) {
	CSVFilePath = "../resource/csv/UnitData.csv";
	selectUnitRect.top = 400; selectUnitRect.left = 640; selectUnitRect.right = 740; selectUnitRect.bottom = 500;
	okButtonRect.top = 600;	okButtonRect.left = 1000; okButtonRect.right = 1100; okButtonRect.bottom = 650;
	resetButtonRect.top = 650;	resetButtonRect.left = 1000; resetButtonRect.right = 1100; resetButtonRect.bottom = 700;

	ImageFilePath = "../resource/img/";
}

void cUnitSelect::Init() {
	unitData = UnitLoad(CSVFilePath);
	cButton tmpButton;


	for (int i = 0; i < unitData.size(); i++) {
		unitButton.push_back(tmpButton);
		sRECT tmpRect;
		tmpRect.top = 100 + (i / 5) * 100;
		tmpRect.left = 640 + (i % 5) * 100;
		tmpRect.bottom = 200 + (i / 5) * 100;
		tmpRect.right = 740 + (i % 5) * 100;

		//cButton Init引数 RECT:右上と左下座標(top,left,right,buttom) filePath:ファイルパス
		//cButton Init(sRECT _rect, const char* _filepth);
		//cButton Init(sRECT _rect, short _transNum, const char* _text, short _fontSize);
		unitButton[i].Init(tmpRect, (ImageFilePath + unitData[i].unitPath).c_str());

		graphArray.push_back(LoadGraph((ImageFilePath + unitData[i].unitPath).c_str()));
	}

	okButton.Init(okButtonRect, 255, "OK", 20);
	resetButton.Init(resetButtonRect, 255, "RESET", 14);
}

void cUnitSelect::Update() {
	if (MOUSE_PRESS(LEFT_CLICK) == 1) {
		for (int i = 0; i < unitButton.size(); i++) {
			if (unitButton[i].ButtonClick() == true) {
				auto itr = find(selectUnit.begin(), selectUnit.end(), i);
				if (itr == selectUnit.end()) {
					selectUnit.push_back(i);
				}
			}
		}

		if (okButton.ButtonClick() == true) {
			if (selectUnit.size() > 0) {
				//選択されているユニット情報を渡す
				//txtファイル書き出し
				FILE* fp;

				errno_t err; // errno_t型(int型)
				err = fopen_s(&fp, "../UnitSelect.txt", "w"); // ファイルを開く。失敗するとエラーコードを返す。
				if (err != 0) {
					DEBUG_LOG("file not open");
				}
				for (int i = 0; i < selectUnit.size(); i++) {
					if (i == selectUnit.size()-1) {				//データが末尾なら改行なし
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
		}
	}
}

void cUnitSelect::Draw() {
	for (int i = 0; i < unitButton.size(); i++) {
		unitButton[i].Draw();
	}
	for (int i = 0; i < selectUnit.size(); i++) {
		DrawExtendGraph(
			selectUnitRect.left + (i % 5) * 100, selectUnitRect.top + (i / 5) * 100,
			selectUnitRect.right + (i % 5) * 100, selectUnitRect.bottom + (i / 5) * 100,
			graphArray[selectUnit[i]], TRUE);
	}

	okButton.Draw();
	resetButton.Draw();
}

void cUnitSelect::End() {

}