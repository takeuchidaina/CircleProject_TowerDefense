#include "SceneMgr.h"

cSceneMgr::cSceneMgr() : m_nextScene(E_SCENE_NONE){

	//m_scene = (cBaseScene*) new cGameMgr(this);
	//m_nowScene = E_SCENE_GAME;
	m_scene = (cBaseScene*) new cTitle(this);
	m_nowScene = E_SCENE_TITLE;
	//m_scene = (cBaseScene*) new cStageSelect(this);
	//m_scene = (cBaseScene*) new cUnitSelect(this);
}

void cSceneMgr::Init() {
	m_scene->Init();

	sRECT rect = {/*左上y*/625,/*左上x*/1055,/*右下x*/1280,/*右下y*/700 };
	m_button.Init(rect, "../resource/img/Button_End.png");
}

void cSceneMgr::Update() {

	//設定が終了したら
	if (m_setting.GetEndSetting() == TRUE && isPose == TRUE) {
		isPose = FALSE;
	}

	if (GET_KEY_PRESS(KEY_INPUT_ESCAPE) == 1) {
		isPose = TRUE;
	}

	// 次のシーンがセットされているなら次のシーンに変更する
	if (m_nextScene != E_SCENE_NONE) {
		m_scene->End();
		delete m_scene;
		//m_poseCount = 0;

		switch (m_nextScene){

		case E_SCENE_TITLE:
			m_scene = (cBaseScene*) new cTitle(this);
			m_nowScene = E_SCENE_TITLE;
			break;
		case E_SCENE_MENU:
			m_scene = (cBaseScene*) new cMenu(this);
			m_nowScene = E_SCENE_MENU;
			break;
		case E_SCENE_STAGESELECT:
			m_scene = (cBaseScene*) new cStageSelect(this);
			m_nowScene = E_SCENE_STAGESELECT;
			break;
		case E_SCENE_UNITSELECT:
			m_scene = (cBaseScene*) new cUnitSelect(this);
			m_nowScene = E_SCENE_UNITSELECT;
			break;
		case E_SCENE_GAME:
			m_scene = (cBaseScene*) new cGameMgr(this);
			m_nowScene = E_SCENE_GAME;
			break;
		case E_SCENE_RESULT:
			m_scene = (cBaseScene*) new cResult(this);
			m_nowScene = E_SCENE_RESULT;
			break;
		}

		m_nextScene = E_SCENE_NONE;		//次のシーン情報のクリア
		m_scene->Init();
	}

	//更新処理
	if (isPose == FALSE) {
		m_scene->Update();
	}
	else {
		m_setting.Update();

		if (m_nowScene == E_SCENE_GAME) {
			m_poseCount++;		//ポーズ中の時間をカウントし時間制限に渡すことによりポーズ中に時間制限が減らない
		}

		//タイトルへ戻る
		if (m_nowScene == E_SCENE_GAME && MOUSE_PRESS(LEFT_CLICK) && m_button.ButtonClick() == TRUE) {
			isPose = FALSE;
			m_nextScene = E_SCENE_TITLE;
		}
	}
}

void cSceneMgr::Draw() {
	//描画処理
	m_scene->Draw();
	
	if (isPose == TRUE) {
		m_setting.Draw();
		if (m_nowScene == E_SCENE_GAME) {
			m_button.Draw();
		}
	}
}

void cSceneMgr::End() {
	m_scene->End();
}

void cSceneMgr::ChangeScene(eScene _nextScene) {
	m_nextScene = _nextScene;	// 次のシーンをセットする
}

void cSceneMgr::SettingStart() {
	m_setting.StartSetting();
	isPose = TRUE;
}

int cSceneMgr::Get_PoseCount() {
	return m_poseCount;
}

void cSceneMgr::ResetPoseCount() {
	m_poseCount = 0;
}