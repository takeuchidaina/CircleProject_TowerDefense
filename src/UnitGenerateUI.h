#pragma once
#include "DxLib.h"
#include "BaseTask.h"
#include <vector>
#include "Constant.h"
#include "ErrorCheck.h"
#include "Mouse.h"
#include "Log.h"
#include "WinBox.h"
#include "Log.h"
#include "CSVLoad.h"
#include "ColorListh.h"
using namespace std;

/********************************************************
●概要
　ドラッグアンドドロップ生成用のUI
　プレイヤーユニット生成

●作成者
　髙井隆太郎

********************************************************/

#ifndef _UNIT_GENERATE_UI_INCLUDE_
#define	_UNIT_GENERATE_UI_INCLUDE_

// 座標関連用
typedef struct{
	float x;
	float y;
	float w;
	float h;
}sPos;

// UI単体
class cUnitGenerateUI : public cBaseTask{

private:
	float m_x, m_y;				// 座標
	float m_width, m_height;	// 大きさ

	int m_unitID;				// 対応するユニットID
	string m_unitType;			// ユニットタイプUI

	int m_img;					// 画像
	int m_unitImg[6];			// ユニット画像

	sUnitLoad m_unit;

public:

	cUnitGenerateUI(float _x, float _y, sUnitLoad _unit) {

		m_x = _x;
		m_y = _y;
		m_width = 250;
		m_height = 80;
		m_unit = _unit;

		// 画像格納
		m_img = LoadGraph("../resource/img/TitleBackGround.jpg");
		FileCheck(m_img, 0001);

		string imgPath = "../resource/img/" + m_unit.unitPath;
		LoadDivGraph(imgPath.c_str(), 6, 3, 2, 64, 64, m_unitImg);
		FileCheck(m_unitImg[0], 0000);

		m_unitType = "タイプ："+TypeUI(m_unit.type);
	}

	virtual ~cUnitGenerateUI(){}

	virtual void Update(){}
	virtual void Draw(){

		DrawExtendGraph(m_x, m_y, m_x + m_width, m_y + m_height, m_img, TRUE);
		UnitDataDraw();
	}
	
	// 座標渡す
	sPos Get_Pos(){

		sPos pos;
		pos.x = m_x;
		pos.y = m_y;
		pos.w = m_width;
		pos.h = m_height;
		return pos;
	}

	void UnitDataDraw()
	{
		DrawFormatString(m_x + 10, m_y + 10, BK, m_unitType.c_str());
		DrawFormatString(m_x + 10, m_y + 30, BK, "HP：%d", m_unit.HP);
		DrawGraph(m_x + 190, m_y + 10, m_unitImg[0], TRUE);
	}

	string TypeUI(int _type)
	{
		switch (_type)
		{
		case E_SORD:
			return "Sord";
		case E_ARCHAR:
			return "Archar";
		case E_DEFENSE:
			return "Defender";
		default:
			break;
		}
	}
};

//////////////////////////////////////////////////////////// UI管理
class cUnitGeneUIMgr : public cBaseTask{

private:
	float m_x, m_y;				// 座標
	float m_width, m_height;	// 大きさ

	bool m_isMouseOver;			// マウスオーバーフラグ

	int m_img;					// 画像

	vector<sMapData> m_map;			// マップデータ
	vector<cUnitGenerateUI> m_ui;	// UI
	vector<sUnitLoad> m_unitData;	// ユニット

public:
	cUnitGeneUIMgr() : cBaseTask(){

		string unitCsv = "../resource/csv/UnitData.csv";

		m_x = 0;
		m_y = 0;
		m_width = 300;
		m_height = WINDOW_HEIGHT;

		m_isMouseOver = false;

		// 生成できるユニット分を生成
		m_unitData = UnitLoad(unitCsv);
		for (int i = 0; i < m_unitData.size(); i++){

			m_ui.emplace_back(20, 20 + i * (80 + 20), m_unitData[i]);
		}

		m_img = LoadGraph("../resource/img/PlayerGeneBack(tmp).png");
		FileCheck(m_img, 0003);
	}

	virtual ~cUnitGeneUIMgr() {}

	virtual void Update(){

		m_isMouseOver = MouseOverCheck(MOUSE_X, MOUSE_Y);
	}

	virtual void Draw(){

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
		DrawExtendGraph(m_x, m_y, m_x + m_width, m_y + m_height, m_img, TRUE);

		if (m_isMouseOver == true){ // マウスオーバー中なら

			// 透明度0％
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
			//DEBUG_LOG("MouseOver");
		}
		else{

			// 透明度50％
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
		}

		// 描画
		for (int i = 0; i < m_ui.size(); i++){
			m_ui[i].Draw();
		}

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
	}

	/*********************************************************************
	関数名：bool MouseOverCheck(int _mx, int _my)
	概要：マウスオーバー中か調べる
	引数：int:マウスx
		：int:マウスy
	戻り値：true:マウスオーバー
	*********************************************************************/
	bool MouseOverCheck(int _mx, int _my){

		// x
		if (m_x <= _mx && _mx <= m_x + m_width){

			// y
			if (m_y <= _my && _my <= m_y + m_height){

				return true;
			}
		}

		return false;
	}

	/*********************************************************************
	関数名：sUnitGene UnitGenerate()
	概要：ユニット生成制御
	引数：なし
	戻り値：sUnitGene:生成するユニット情報
	*********************************************************************/
	sUnitGene UnitGenerate(){

		sUnitGene unit = { -1, -1 };

		for (int i = 0; i < m_ui.size(); i++){

			sPos pos = m_ui[i].Get_Pos();

			int id = DragAndDrop(pos.x, pos.y, pos.w, pos.h);

			if (id != -1){

				unit = { i, id };
				return unit;
			}
		}
		return unit;
	}

	/*********************************************************************
	関数名：int DragAndDrop(float _x, float _y, float _w, float _h)
	概要：ドラッグアンドドロップ判定
	引数：なし
	戻り値：int:マップID（入らなかったら:-1）
	*********************************************************************/
	int DragAndDrop(float _x, float _y, float _w, float _h){

		// 左クリック
		if (MOUSE_PRESS(LEFT_CLICK) == 1){

			// x
			if (_x <= MOUSE_X && MOUSE_X <= _x + _w){

				// y
				if (_y <= MOUSE_Y && MOUSE_Y <= _y + _h){

					// ドラッグ中
					while (GetMouseInput() & MOUSE_INPUT_LEFT){
						cMouse::Instance()->Update();

						//　仮
						//DrawCircle(MOUSE_X, MOUSE_Y, 10, GetColor(51, 255, 255), TRUE);
					}

					// マウス座標更新
					cMouse::Instance()->Update();

					// マップに入ったか
					for (int i = 0; i < m_map.size(); i++){

						DEBUG_LOG("mousex:%d", MOUSE_X);

						// x
						if (m_map[i].pos.x <= MOUSE_V.x && MOUSE_V.x <= m_map[i].pos.x + m_map[i].width){

							// y
							if (m_map[i].pos.y <= MOUSE_V.y && MOUSE_V.y <= m_map[i].pos.y + m_map[i].height){

								//ReportBox("inMap");
								DEBUG_LOG("inMap:%d", i);
								return i;
							}
						}
					}
				}
			}
		}
		return -1;
	}

	/*********************************************************************
	関数名：void Set_MapData(vector<sMapData> _map)
	概要：マップデータ格納
	引数：vector<sMapData>:全体マップでーた
	戻り値：なし
	*********************************************************************/
	void Set_MapData(vector<sMapData> _map){

		m_map = _map;
	}
};

#endif // !_UNIT_GENERATE_UI_INCLUDE_