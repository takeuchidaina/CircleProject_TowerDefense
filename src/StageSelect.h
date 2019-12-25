#pragma once
#ifndef _INCLUED_STAGESELECT_
#define _INCLUED_STAGESELECT_

#include "DxLib.h"
#include "DebugList.h"
#include "ColorListh.h"
#include "Constant.h"
#include "BaseScene.h"
#include "BaseTask.h"
#include "ISceneChanger.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Button.h"
#include <string.h>
#include "ErrorCheck.h"
#include "Sound.h"
#include <string>
#include <sstream>
#include "CSVLoad.h"
#include "Sound.h"

typedef struct {
	float x, y, w, h;
}sSelectPos;

class cStageSelectUI {
public:
	cStageSelectUI(float _x, float _y, int _num) {
		ostringstream tmpInt;
		tmpInt << _num;
		m_stageCsvPath = "../resource/Map/Map" + tmpInt.str() + ".csv";
		string imgPath = "../resource/img/Map" + tmpInt.str() + ".png";
		m_image = LoadGraph(imgPath.c_str());

		vector<vector<double>> tmpMapData;
		tmpMapData = CSVLoad(m_stageCsvPath);

		m_mapSize = tmpMapData.size();

		m_pos = { _x, _y, 200, 200 };
		m_imagePos = { _x + 20, _y + 50, 160, 90 };
		m_num = _num;

		m_imageMouseOver = LoadGraph("../resource/img/PlayerGeneBack(tmp).png");
	}

	void Update(){
		
	}
	void Draw() {

		if (MouseOverCheck(MOUSE_X, MOUSE_Y) == true) {
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
			DrawExtendGraph(
				m_pos.x, m_pos.y,
				m_pos.x + m_pos.w, m_pos.y + m_pos.h,
				m_imageMouseOver, TRUE
			);
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
		}

		ostringstream tmpInt;
		tmpInt << m_num;
		string tmpStr = "Stage" + tmpInt.str();
		SetFontSize(30);
		DrawFormatString(m_pos.x + 20, m_pos.y + 10, BK, tmpStr.c_str());

		DrawExtendGraph(
			m_imagePos.x, m_imagePos.y,
			m_imagePos.x + m_imagePos.w, m_imagePos.y + m_imagePos.h,
			m_image, FALSE
		);

		ostringstream tmpMapSize;
		tmpMapSize << m_mapSize;
		tmpStr = "MapSizeF" + tmpMapSize.str();

		SetFontSize(20);
		DrawFormatString(m_pos.x + 20, m_pos.y + 150, BK, tmpStr.c_str());
	}

	bool MouseOverCheck(int _mx, int _my) {

		// x
		if (m_pos.x <= _mx && _mx <= m_pos.x + m_pos.w) {

			// y
			if (m_pos.y <= _my && _my <= m_pos.y + m_pos.h) {

				return true;
			}
		}

		return false;
	}

	sSelectPos Get_Pos()
	{
		return m_pos;
	}

private:
	
	typedef struct {
		float x, y, w, h;
	}sImagePos;
	
	int m_num;
	sSelectPos m_pos;
	sImagePos m_imagePos;
	string m_stageCsvPath;
	int m_mapSize;
	int m_image;
	int m_imageMouseOver;
};

class cStageSelect : public cBaseScene {
public:
	cStageSelect(ISceneChanger* _scene);

	void Init()override;
	void Update()override;
	void Draw()override;
	void End()override;

private:
	//’è”‚Ì‚æ‚¤‚È‚à‚Ì
	static const int STAGE_NUM = 5;
	static const int BUTTON_MARGIN = 50;
	static const int TOP_MARGIN = 200;
	static const int LEFT_MARGIN = 250;
	static const int BUTTON_WIDTH = 100;
	static const int BUTTON_HEIGHT = 100;

	vector<cStageSelectUI> m_stageUI;

	vector<cButton> stageButton;

	cButton okButton;
	sRECT okButtonRect;

	int m_imgBacGround;

};

#endif

