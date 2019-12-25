#include "Menu.h"

cMenu::cMenu(ISceneChanger* _scene) : cBaseScene(_scene) {
}

void cMenu::Init() {
	//メニューの初期化
//左上y, 左上x, 右下x, 右下y, 画像ファイルパス,移動先シーン
	m_menu[E_MENU_NSCENE] =  { {/*左上y*/600,/*左上x*/170,/*右下x*/470,/*右下y*/700,"../resource/img/Button_Start.png" },E_SCENE_STAGESELECT };
	m_menu[E_MENU_SETTING] = { {/*左上y*/600,/*左上x*/490,/*右下x*/790,/*右下y*/700,"../resource/img/Button_Setting.png" }, E_SCENE_NONE };
	m_menu[E_MENU_BACK] =	 { {/*左上y*/600,/*左上x*/810,/*右下x*/1130,/*右下y*/700,"../resource/img/Button_BACK.png" }, E_SCENE_TITLE };
	for (int i = 0; i < E_TITLE_MAX; i++) {
		m_btn[i].Init(m_menu[i].image.rect, m_menu[i].image.filePath.c_str());
	}

	//チュートリアル画像
	m_btnSetumeiRect[E_TUTO_TAKARA] =	{/*左上y*/100,/*左上x*/30,		   /*右下x*/30 + 400,	   /*右下y*/400 };
	m_btnSetumeiRect[E_TUTO_SOUSA]	=	{/*左上y*/100,/*左上x*/30 + 400 + 10,/*右下x*/30 + 800 + 10 ,/*右下y*/400 };
	m_btnSetumeiRect[E_TUTO_TYPE]	=	{/*左上y*/100,/*左上x*/30 + 800 + 20,/*右下x*/30 + 1200 + 20,/*右下y*/400 };
	m_btnSetumeiRect[E_TUTO_EXPANTION] = { 50,150,1280 - 150,720 - 150 };
	m_setumeiFilePath[E_TUTO_TAKARA] = "../resource/img/Menu_Setumei1.jpg";
	m_setumeiFilePath[E_TUTO_SOUSA] = "../resource/img/Menu_Setumei2.jpg";
	m_setumeiFilePath[E_TUTO_TYPE] = "../resource/img/Menu_Setumei3.jpg";
	m_setumeiFilePath[E_TUTO_EXPANTION] = m_setumeiFilePath[0];
	for (int i = 0; i < E_TUTO_LENGTH; i++) {
		m_btnSetumei[i].Init(m_btnSetumeiRect[i], m_setumeiFilePath[i].c_str());
	}
	isExpantion = FALSE;

	//画像の初期化
	m_image[E_BACK_GROUND] = { 0,0,1280,960,"../resource/img/BackGround.jpg" };
	//m_image[E_LOGO] = { 50,0,1330,960,"../resource/img/TitleLogo.png"};
	for (int i = 0; i < E_IMAGE_MAX; i++) {
		m_image[i].handle = LoadGraph(m_image[i].filePath.c_str());
		FileCheck(m_image[i].handle);
	}

	//タイトル用BGMの再生
	cSound::Instance()->PlayBGM(cSound::Instance()->E_BGM_TITLE, cSound::Instance()->E_PLAY_LOOP, TRUE);
	
}

void cMenu::Update() {

	//左クリック
	if (MOUSE_PRESS(LEFT_CLICK) == 1) {

		//ボタンの上でクリックされているか判断
		for (int i = 0; i < E_TITLE_MAX; i++) {
			if (m_btn[i].ButtonClick() == TRUE) {

				//TODO:if elseifで終了判断せずにChangeSceneだけで処理を行う
				//STARTボタン
				if (m_menu[i].menu == E_SCENE_STAGESELECT) {
					cSound::Instance()->PlaySE(cSound::Instance()->E_SE_SELECT);		//決定音
					m_sceneChanger->ChangeScene((eScene)m_menu[i].menu);				//シーンを変更
				}
				//SETTINGボタン
				else if (m_menu[i].menu == E_SCENE_NONE) {
					cSound::Instance()->PlaySE(cSound::Instance()->E_SE_SELECT);		//決定音
					m_sceneChanger->SettingStart();
				}
				//BACKボタン
				else if (m_menu[i].menu == E_SCENE_TITLE) {
					cSound::Instance()->PlaySE(cSound::Instance()->E_SE_CANSEL, cSound::Instance()->E_PLAY_NORMAL);		//キャンセル音
					m_sceneChanger->ChangeScene((eScene)m_menu[i].menu);
				}
			}
		}

		//チュートリアルボタン
		for (int i = 0; i < E_TUTO_LENGTH-1; i++) {
			if (m_btnSetumei[i].ButtonClick() == TRUE && isExpantion == FALSE) {
				m_setumeiFilePath[E_TUTO_EXPANTION] = m_setumeiFilePath[i].c_str();
				m_btnSetumei[E_TUTO_EXPANTION].Init(m_btnSetumeiRect[E_TUTO_EXPANTION], m_setumeiFilePath[E_TUTO_EXPANTION].c_str());
				cSound::Instance()->PlaySE(cSound::Instance()->E_SE_SELECT);		//決定音
				isExpantion = TRUE;
				break;
			}
			else if (m_btnSetumei[i].ButtonClick() == FALSE && isExpantion == TRUE) {
				isExpantion = FALSE;
				break;
			}
		}
	}


}

void cMenu::Draw() {
	//画像表示 (※背景があるので一番最初に呼び出すこと)
	for (int i = 0; i < E_IMAGE_MAX; i++) {
		DrawExtendGraph(m_image[i].rect.left, m_image[i].rect.top,
			m_image[i].rect.right, m_image[i].rect.bottom, m_image[i].handle, TRUE);
	}

	//ボタン表示
	for (int i = 0; i < E_TITLE_MAX; i++) {
		m_btn[i].Draw();
	}

	//チュートリアル表示
	for (int i = 0; i < E_TUTO_LENGTH-1; i++) {
		m_btnSetumei[i].DrawJPG();
	}
	if (isExpantion == TRUE) {
		m_btnSetumei[E_TUTO_EXPANTION].DrawJPG();
	}

}

void cMenu::End() {
	//画像ハンドルの削除
	for (int i = 0; i < E_IMAGE_MAX; i++) {
		DeleteGraph(m_image[i].handle);
	}
	cSound::Instance()->StopSound(cSound::Instance()->E_BGM_TITLE);		//BGMを止める
}