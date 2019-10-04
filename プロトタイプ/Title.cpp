#include "Title.h"

cTitle::cTitle(ISceneChanger* _scene) : cBaseScene(_scene) {
}

void cTitle::Init() {

	
#ifdef TITLE_DEBUG
	// x,y,eMenu,name
	m_menu[E_TITLE_MENU]   = { TEXT_X,TEXT_Y,E_TITLE_MENU,"メニュー" },
	m_menu[E_TITLE_GAME]   = { TEXT_X,TEXT_Y + (FONT_SIZE * E_TITLE_GAME) ,E_TITLE_GAME,"ゲーム" },
	m_menu[E_TITLE_RESULT] = { TEXT_X,TEXT_Y + (FONT_SIZE * E_TITLE_RESULT),E_TITLE_GAME,"リザルト" },
	m_menu[E_TITLE_END]    = { TEXT_X,TEXT_Y + (FONT_SIZE * E_TITLE_END),E_TITLE_END,"終了" };
#endif // TITLE_DEBUG

	nowSelect = 0;

	//背景
	m_background = LoadGraph("../resource/img/TitleBackGround.jpg");
	if (m_background == NULL) {
		//error
	}
	//ロゴ
	m_logo = LoadGraph("../resource/img/TitleLogo.png");
	if (m_logo == NULL) {
		//error
	}
	//開始ボタン
	m_startButton = LoadGraph("../resource/img/TitleStartButton.png");
	if (m_startButton == NULL) {
		//error
	}
	//終了ボタン
	m_endButton = LoadGraph("../resource/img/TitleEndButton.png");
	if (m_endButton == NULL) {
		//error
	}

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
		nowSelect = m_menu[m_menuNum-1].menu;
	}
	nowSelect %= m_menuNum;


#ifdef TITLE_DEBUG
	//項目を選択した状態でエンターを押すとシーン変更
	if (GET_KEY_PRESS(KEY_INPUT_RETURN) == 1) {
		switch (nowSelect)
		{
		case E_TITLE_MENU:
			m_sceneChanger->ChangeScene(E_SCENE_MENU);
			break;
		case E_TITLE_GAME:
			m_sceneChanger->ChangeScene(E_SCENE_GAME);
			break;
		case E_TITLE_RESULT:
			m_sceneChanger->ChangeScene(E_SCENE_RESULT);
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

	DrawGraph(0, 0, m_background, TRUE);	//背景
	DrawGraph(50, -100, m_logo, TRUE);		//ロゴ
	DrawGraph(640-225, 400, m_startButton, TRUE);	//開始ボタン
	DrawGraph(640-225, 550, m_endButton, TRUE);		//終了ボタン
	//DrawGraph(95, 500, m_startButton, TRUE);	//開始ボタン
	//DrawGraph(735, 500, m_endButton, TRUE);	//終了ボタン

	//文字の表示
	for (int i = 0; i < m_menuNum; i++) {
		DrawFormatString(m_menu[i].x,m_menu[i].y,WH,m_menu[i].text);
	}

	//選択項目の横に矢印を表示
	DrawFormatString(m_menu[nowSelect].x - FONT_SIZE, m_menu[nowSelect].y, WH, "→");

#ifdef TITLE_DEBUG
	DrawFormatString(0, 0, WH, "タイトル画面");
#endif // TITLE_DEBUG

}

void cTitle::End() {
	//画像ハンドルの削除
	DeleteGraph(m_background);
	DeleteGraph(m_logo);
	DeleteGraph(m_startButton);
	DeleteGraph(m_endButton);
}