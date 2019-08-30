#include "Title.h"

cTitle::cTitle(ISceneChanger* _scene) : cBaseScene(_scene) {
	cTitle::Init();
}

void cTitle::Init() {

	// x,y,eMenu,name
#ifndef TITLE_DEBUG
	m_menu[E_TITLE_GAME] = { TEXT_X,TEXT_Y,E_TITLE_GAME,"ゲーム開始" },
	m_menu[E_TITLE_END] = { TEXT_X,TEXT_Y + FONT_SIZE,E_TITLE_END,"ゲーム終了" };
#endif // !TITLE_DEBUG

#ifdef TITLE_DEBUG
	m_menu[E_TITLE_MENU]   = { TEXT_X,TEXT_Y,E_TITLE_MENU,"メニュー" },
	m_menu[E_TITLE_GAME]   = { TEXT_X,TEXT_Y + (FONT_SIZE * E_TITLE_GAME) ,E_TITLE_GAME,"ゲーム" },
	m_menu[E_TITLE_RESULT] = { TEXT_X,TEXT_Y + (FONT_SIZE * E_TITLE_RESULT),E_TITLE_GAME,"リザルト" },
	m_menu[E_TITLE_END]    = { TEXT_X,TEXT_Y + (FONT_SIZE * E_TITLE_END),E_TITLE_END,"終了" };
#endif // TITLE_DEBUG

	nowSelect = 0;
}

void cTitle::Update() {

	//なぜかシーンの変更を二回行っている
	
	//項目の移動
	if (GET_KEY_PRESS(KEY_INPUT_DOWN) == 1) {
		nowSelect++;
	}
	if (GET_KEY_PRESS(KEY_INPUT_UP) == 1) {
		nowSelect--;
	}

	//項目の移動の上限による処理
	if (nowSelect < 0) {
		nowSelect = m_menu[menuNum-1].menu;
	}
	nowSelect %= menuNum;

#ifndef TITLE_DEBUG
	//項目を選択した状態でエンターを押すとシーン変更
	if (GET_KEY_PRESS(KEY_INPUT_RETURN) == 1) {
		switch (nowSelect)
		{
		case E_TITLE_GAME:
			sceneChanger->ChangeScene(E_SCENE_MENU);
			break;
		case E_TITLE_END:
			DxLib_End();
			break;
		default:
			break;
		}
	}
#endif // !TITLE_DEBUG

#ifdef TITLE_DEBUG
	//項目を選択した状態でエンターを押すとシーン変更
	if (GET_KEY_PRESS(KEY_INPUT_RETURN) == 1) {
		switch (nowSelect)
		{
		case E_TITLE_MENU:
			sceneChanger->ChangeScene(E_SCENE_MENU);
			break;
		case E_TITLE_GAME:
			sceneChanger->ChangeScene(E_SCENE_GAME);
			break;
		case E_TITLE_RESULT:
			sceneChanger->ChangeScene(E_SCENE_RESULT);
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

	//cBaseScene::Draw();

	//文字の表示
	for (int i = 0; i < menuNum; i++) {
		DrawFormatString(m_menu[i].x,m_menu[i].y,WH,m_menu[i].text);
	}

	DrawFormatString(m_menu[nowSelect].x - FONT_SIZE, m_menu[nowSelect].y, WH, "→");
	
	

#ifdef TITLE_DEBUG
	DrawFormatString(0, 0, WH, "タイトル画面");
	DrawFormatString(0, 20, WH, "nowselect:%d",nowSelect);
	DrawFormatString(0, 40, WH, "enumNum:%d", E_TITLE_MAX);
#endif // TITLE_DEBUG

}

void cTitle::End() {
	//
}