#include "Title.h"

cTitle::cTitle(ISceneChanger* _scene) : cBaseScene(_scene) {
}

void cTitle::Init() {

	//メニューの初期化
	m_menu[E_TITLE_MENU] = { {/*左上y*/600,/*左上x*/100,/*右下x*/400,/*右下y*/700,"../resource/img/TitleStartButton.png" },E_SCENE_GAME };
	m_menu[E_TITLE_END]  = { {/*左上y*/600,/*左上x*/420,/*右下x*/720,/*右下y*/700,"../resource/img/TitleEndButton.png" }, E_SCENE_END };
	for (int i = 0; i < E_TITLE_MAX; i++) {
		m_btn[i].Init(m_menu[i].image.rect,m_menu[i].image.filePath.c_str());
	}

	//画像の初期化
	m_image[E_BACK_GROUND] = { 0,0,1280,960,"../resource/img/TitleBG.png"};
	//m_image[E_LOGO] = { 50,0,1330,960,"../resource/img/TitleLogo.png"};
	for (int i = 0; i < E_IMAGE_MAX;i++) {
		m_image[i].handle = LoadGraph(m_image[i].filePath.c_str());
		FileCheck(m_image[i].handle);
	}

	cSound::Instance()->PlayBGM(
		cSound::Instance()->E_BGM_TITLE, cSound::Instance()->E_PLAY_LOOP,TRUE);
}

void cTitle::Update() {

	//クリックされたらボタンの上か判断
	if (MOUSE_PRESS(LEFT_CLICK) == 1) {
		for (int i = 0; i < E_TITLE_MAX;i++) {
			if (m_btn[i].ButtonClick() == TRUE) {

				//TODO:if elseifで終了判断せずにChangeSceneだけで処理を行う
				if (m_menu[i].menu == E_SCENE_GAME) {
					cSound::Instance()->PlaySE(cSound::Instance()->E_SE_SELECT);
					cSound::Instance()->StopSound(cSound::Instance()->E_BGM_TITLE);
					m_sceneChanger->ChangeScene((eScene)m_menu[i].menu);
				}
				else if (m_menu[i].menu == E_SCENE_END) {
					cSound::Instance()->PlaySE(cSound::Instance()->E_SE_CANSEL);
					cSound::Instance()->StopSound(cSound::Instance()->E_BGM_TITLE);
					WaitTimer(300);
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
		DrawExtendGraph(m_image[i].rect.left, m_image[i].rect.top,
			m_image[i].rect.right, m_image[i].rect.bottom, m_image[i].handle, TRUE);
	}

	//ボタン表示
	for (int i = 0; i < E_TITLE_MAX; i++) {
		m_btn[i].Draw();
	}

}

void cTitle::End() {

	//画像ハンドルの削除
	for (int i = 0; i < E_IMAGE_MAX; i++) {
		DeleteGraph(m_image[i].handle);
	}
}