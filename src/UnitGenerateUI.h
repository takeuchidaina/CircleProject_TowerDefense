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
#include <fstream>
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
	int m_nowHP;				// 現在のHP

	int m_img;					// 画像
	int m_unitImg[10];			// ユニット画像

	int m_scroll;

	sUnitLoad m_unit;

	bool m_isActive;				// true:生成済み

public:

	cUnitGenerateUI(float _x, float _y, sUnitLoad _unit) {

		m_x = _x;
		m_y = _y;
		m_width = 250;
		m_height = 80;
		m_unit = _unit;
		m_nowHP = m_unit.HP;
		m_isActive = true;
		m_unitID = _unit.ID;
		m_scroll = 0;

		// 画像格納
		m_img = LoadGraph("../resource/img/TitleBackGround.jpg");
		FileCheck(m_img, 0001);

		string imgPath = "../resource/img/" + m_unit.unitPath;
		LoadDivGraph(imgPath.c_str(), 10, 5, 2, 256, 256, m_unitImg);
		FileCheck(m_unitImg[0], 0000);

		m_unitType = "タイプ："+TypeUI(m_unit.type);
	}

	virtual ~cUnitGenerateUI(){}

	virtual void Update(){}
	virtual void Draw(){
		float tmpY = m_scroll * WINDOW_HEIGHT;
		DrawExtendGraph(m_x, m_y - tmpY, m_x + m_width, m_y + m_height - tmpY, m_img, TRUE);
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
		float tmpY = m_scroll * WINDOW_HEIGHT;
		DrawFormatString(m_x + 10, m_y + 10 - tmpY, BK, m_unitType.c_str());
		DrawFormatString(m_x + 10, m_y + 25 - tmpY, BK, "ATK：%d", m_unit.ATK);
		DrawFormatString(m_x + 10, m_y + 40 - tmpY, BK, "DEF：%d", m_unit.DEF);
		DrawFormatString(m_x + 10, m_y + 55 - tmpY, BK, "HP：%d", m_unit.HP);
		DrawExtendGraph(
			m_x+160, m_y - tmpY,
			m_x + m_width,
			m_y + m_height - tmpY,
			m_unitImg[3], TRUE
		);
		//DrawGraph(m_x + 190, m_y + 10, m_unitImg[3], TRUE);
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

	bool Get_Active()
	{
		return m_isActive;
	}

	int Get_ID()
	{
		return m_unitID;
	}

	void Set_Active(bool _isActive)
	{
		m_isActive = _isActive;
	}

	void Set_NowHP(int _hp)
	{
		m_nowHP = _hp;
	}

	void Set_Scroll(int _scroll)
	{
		m_scroll = _scroll;
	}
};

//////////////////////////////////////////////////////////// UI管理
class cUnitGeneUIMgr : public cBaseTask{

private:
	float m_x, m_y;				// 座標
	float m_width, m_height;	// 大きさ

	bool m_isMouseOver;			// マウスオーバーフラグ

	int m_wheel;
	int m_scroll;

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

		ifstream ifs("../UnitSelect.txt");
		if (ifs.fail())
		{
			ErrBox("UnitSelect.txt not file");
		}
		char str[10];
		int loadCnt = 0;

		while (ifs.getline(str, 9))
		{
			int tmp = atoi(str);
			m_ui.emplace_back(20, 20 + loadCnt * (80 + 20), m_unitData[tmp]);
			loadCnt++;
		}

		/*for (int i = 0; i < m_unitData.size(); i++){

			m_ui.emplace_back(20, 20 + i * (80 + 20), m_unitData[i]);
		}*/

		m_img = LoadGraph("../resource/img/PlayerGeneBack(tmp).png");
		FileCheck(m_img, 0003);

		m_wheel = MOUSE_WHEEL;

	}

	virtual ~cUnitGeneUIMgr() {}

	virtual void Update(){

		m_isMouseOver = MouseOverCheck(MOUSE_X, MOUSE_Y);

		if (m_isMouseOver == true)
		{
			if (m_wheel > MOUSE_WHEEL)
			{
				m_scroll = 1;
				m_wheel = MOUSE_WHEEL;
			}
			else if (m_wheel < MOUSE_WHEEL)
			{
				m_scroll = 0;
				m_wheel = MOUSE_WHEEL;
			}
		}
	}

	virtual void Draw(){

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
		DrawExtendGraph(m_x, m_y, m_x + m_width, m_y + m_height, m_img, TRUE);

		// 描画
		for (int i = 0; i < m_ui.size(); i++){

			if (m_ui[i].Get_Active() != true)
			{
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
			}
			else
			{
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
			}

			m_ui[i].Set_Scroll(m_scroll);
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

		sUnitGene unit = { -1, -1, -1};
		float tmpY = m_scroll * WINDOW_HEIGHT;

		for (int i = 0; i < m_ui.size(); i++){

			if (m_ui[i].Get_Active() != true) { continue; }

			sPos pos = m_ui[i].Get_Pos();

			int id = DragAndDrop(pos.x, pos.y-tmpY, pos.w, pos.h);

			if (id != -1){

				unit = { m_ui[i].Get_ID(), id, i};
				//m_ui[i].Set_Active(false);
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

	int Get_PlayerSize()
	{
		return m_ui.size();
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

	void Set_isActive(bool _isActive, int _uiID)
	{
		m_ui[_uiID].Set_Active(_isActive);
	}

	/*void Set_NowHP(int _hp, int _num)
	{
		 = _hp;
	}*/
};

#endif // !_UNIT_GENERATE_UI_INCLUDE_