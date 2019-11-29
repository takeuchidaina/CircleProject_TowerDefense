#include "Title.h"

cTitle::cTitle(ISceneChanger* _scene) : cBaseScene(_scene) {
}

void cTitle::Init() {

	nowSelect = 0;

	//メニューの初期化
	m_menu[E_TITLE_MENU] = { {120,500,420,600,"../resource/img/TitleStartButton.png" },E_SCENE_GAME };
	m_menu[E_TITLE_END] = { {420,500,720,600,"../resource/img/TitleEndButton.png" }, E_SCENE_END };
	for (int i = 0; i < E_TITLE_MAX; i++) {
		m_btn[i].Init(m_menu[i].image.ux, m_menu[i].image.uy,
						 m_menu[i].image.dx, m_menu[i].image.dy,
							m_menu[i].image.filePath.c_str());
	}

	//画像の初期化
	m_image[E_BACK_GROUND] = { 0,0,1280,960,"../resource/img/TitleBG.png"};
	//m_image[E_LOGO] = { 50,0,1330,960,"../resource/img/TitleLogo.png"};
	for (int i = 0; i < E_IMAGE_MAX;i++) {
		m_image[i].handle = LoadGraph(m_image[i].filePath.c_str());
		FileCheck(m_image[i].handle);
	}

	cSound::Instance()->PlayBGM(
		cSound::Instance()->E_BGM_TITLE, cSound::Instance()->E_PLAY_LOOP);
}

void cTitle::Update() {

	//クリックされたらボタンの上か判断
	if (MOUSE_PRESS(LEFT_CLICK) == 1) {
		for (int i = 0; i < E_TITLE_MAX;i++) {
			if (m_btn[i].ButtonClick() == TRUE) {

				//TODO:if elseifで終了判断せずにChangeSceneだけで処理を行う
				if (m_menu[i].menu == E_SCENE_GAME) {
					m_sceneChanger->ChangeScene((eScene)m_menu[i].menu);
					cSound::Instance()->PlaySE(cSound::Instance()->E_SE_SELECT);
					cSound::Instance()->StopSound(cSound::Instance()->E_BGM_TITLE);
				}
				else if (m_menu[i].menu == E_SCENE_END) {
					cSound::Instance()->PlaySE(cSound::Instance()->E_SE_CANSEL);
					cSound::Instance()->StopSound(cSound::Instance()->E_BGM_TITLE);
					cSound::Instance()->End();
					DxLib_End();
				}
			}
		}
	}

}

void cTitle::Draw() {

	//画像表示 (※背景があるので一番最初に呼び出すこと)
	for (int i = 0; i < E_IMAGE_MAX; i++) {
		DrawExtendGraph(m_image[i].ux, m_image[i].uy,
			m_image[i].dx, m_image[i].dy, m_image[i].handle, TRUE);
	}

	//ボタン表示
	for (int i = 0; i < E_TITLE_MAX; i++) {
		m_btn[i].Draw();
	}



#ifdef TITLE_DEBUG
	DrawFormatString(0, 0, WH, "タイトル画面");
	DrawFormatString(0, 20, WH, "nowSelect:%d",nowSelect);
#endif // TITLE_DEBUG

}

void cTitle::End() {

	//画像ハンドルの削除
	for (int i = 0; i < E_IMAGE_MAX; i++) {
		DeleteGraph(m_image[i].handle);
	}
}