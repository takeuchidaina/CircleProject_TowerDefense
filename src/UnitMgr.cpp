#include "UnitMgr.h"

cUnitMgr::cUnitMgr(){

	m_num = 0;
	m_mapStack = 3;

	// 生成用UI実態宣言
	m_geneUI = new cUnitGeneUIMgr();
	m_geneUI->Set_MapData(m_mapData);

	// ランダム関数準備
	GetDateTime(&m_date);
	int tmpDate = m_date.Day + m_date.Hour + m_date.Min + m_date.Mon + m_date.Sec + m_date.Year;
	SRand(tmpDate);

	// ユニット選択画像読み込み
	m_selectMarkImg = LoadGraph("../resource/img/PlayerSelect.png");
	if (-1 == m_selectMarkImg)
	{
		//ErrBox("画像読み込み失敗");
	}

	// ユニットデータをCSVから読み込み
	string unitCsvPath = "../resource/csv/UnitData.csv";
	m_unitCsvData = UnitLoad(unitCsvPath);

	// 部屋ごとのユニット管理準備
	for (int i = 0; i < m_mapData.size(); i++)
	{
		m_roomPlayer.push_back(vector<int>());
		m_roomEnemy.push_back(vector<int>());
	}

	m_escortCnt = 0;
}

// デストラクタ
cUnitMgr::~cUnitMgr(){

	DeleteGraph(m_selectMarkImg);
}

// 演算処理
void cUnitMgr::Update(){

	// ドラッグアンドドロップでユニット生成
	m_geneUI->Update();
	UnitGenerate();

	m_moveCnt++;				// 一定数まで行ったらmove
	m_moveType = GetRand(2);	// moveするTypeを決めるランダム

	// 護衛対象生成
	if (m_escortCnt <= 0){
		player.emplace_back(new cEscortTarget(0, 1000));
		m_escortCnt++;
		m_num++;

		DEBUG_LOG("player.size:%d", player.size());
	}

	UnitDie();
	InRoomUnit();
	
	// ユニットの各ステートに対する処理
	for (int i = 0; i < player.size(); i++){

		switch (player[i]->Get_State()){

		case E_IDLE:	// 待機

			// 攻撃できる場合、ターゲットを探す
			if (player[i]->Attack() == true){
				TargetSelect(i, 1);
			}
			break;

		case E_ATTACK:	// 攻撃

			// 攻撃できる場合、
			if (player[i]->Attack() == true){
				TargetSelect(i, 1);	// 攻撃対象検索
				// 攻撃
				AttackRelay(player[i]->Get_AtkPoint(), player[i]->Get_TargetNum(), player[i]->Get_Num());
				player[i]->AttackSE();
			}
			
			break;

		case E_MOVE:	// 移動
			player[i]->Move();
			break;

		default:
			break;
		}

		player[i]->AttackStart();

		//DrawFormatString(200, 400, RD, "player:%d", player[0]->Get_Hp());
	}

	for (int i = 0; i < enemy.size(); i++){

		switch (enemy[i]->Get_State()){

		case E_IDLE:	// 待機

			// 攻撃できる場合、ターゲットを探す
			if (enemy[i]->Attack() == true){
				TargetSelect(i, -1);
			}
			break;

		case E_ATTACK:	// 攻撃
			// 攻撃できる場合、
			if (enemy[i]->Attack() == true){
				TargetSelect(i, -1);	// 攻撃対象検索
				// 攻撃
				AttackRelay(enemy[i]->Get_AtkPoint(), enemy[i]->Get_TargetNum(), enemy[i]->Get_Num());
				enemy[i]->AttackSE();
			}
			break;

		case E_MOVE:	//移動
			UnitMove();
			break;
		default:
			break;
		}
		enemy[i]->AttackStart();

		//enemy[i]->Set_MapSize(4);
		//DrawFormatString(200, 450, RD, "enemy:%d", enemy[0]->Get_Hp());
	}

	NoTarget();
}

// 描画処理
void cUnitMgr::Draw(){

	RoomDraw();
	UnitMove();

	// プレイヤー
	for (int i = 0; i < player.size(); i++){

		// エフェクト
		if (player[i]->Get_EffectFlg() == true){

			int num = EnemyArreySearch(player[i]->Get_TargetNum());
			if (num >= 0){

				player[i]->AttackAnime(enemy[num]->Get_Pos());
			}
		}
	}
	// 敵
	for (int i = 0; i < enemy.size(); i++){

		// エフェクト
		if (enemy[i]->Get_EffectFlg() == true){

			int num = PlayerArreySearch(enemy[i]->Get_TargetNum());
			if (num >= 0){

				enemy[i]->AttackAnime(player[num]->Get_Pos());
			}
		}
	}

	m_geneUI->Draw();

#ifdef UNIT_MGR_DEBUG
	//DrawFormatString(100, 100, GetColor(255, 0, 0), "roomPlayer:%d", roomPlayer.size());
	//DrawFormatString(100, 150, GetColor(255, 0, 0), "roomEnemy:%d", roomEnemy.size());
#endif // UNIT_MGR_DEBUG
}

// 部屋内の描画
void cUnitMgr::RoomDraw(){

	// プレイヤー
	for (int i = 0; i < m_roomPlayer.size(); i++){

		for (int j = 0; j < m_roomPlayer[i].size(); j++){

			int playerNum = m_roomPlayer[i][j];

			int arreyNum = PlayerArreySearch(playerNum);

			// 移動中を除く
			if (player[arreyNum]->Get_State() != E_MOVE){

				int num = m_mapData[i].roomSize - 1 - j;

				float x = m_mapData[i].pos.x;
				float wPos = m_mapData[i].width / 2 / (m_mapData[i].roomSize + 3) * num;

				x += wPos + 30;

				float y = m_mapData[i].pos.y;

				float hPos = m_mapData[i].height / 2 / (m_mapData[i].roomSize + 1) * num;

				y += hPos + 40;


				player[arreyNum]->Set_Pos(VGet(x, y, -(j / 10)));

				player[arreyNum]->Draw();
			}
		}
	}

	// 敵
	for (int i = 0; i < m_roomEnemy.size(); i++){

		for (int j = 0; j < m_roomEnemy[i].size(); j++){

			int enemyNum = m_roomEnemy[i][j];

			int arreyNum = EnemyArreySearch(enemyNum);

			// 移動中を除く
			if (enemy[arreyNum]->Get_State() != E_MOVE){

				int num = m_mapData[i].roomSize - 1 - j;

				float x = m_mapData[i].pos.x + m_mapData[i].width;
				float wPos = m_mapData[i].width / 2 / (m_mapData[i].roomSize + 3) * num;

				x -= wPos + 30;

				float y = m_mapData[i].pos.y;

				float hPos = m_mapData[i].height / 2 / (m_mapData[i].roomSize + 1) * num;

				y += hPos + 40;


				enemy[arreyNum]->Set_Pos(VGet(x, y, -(j / 10)));

				enemy[arreyNum]->Draw();
			}
		}
	}
}

// ターゲットの検索
void cUnitMgr::TargetSelect(int _arrayNum, int _unit){

	if (_unit == 1){	// Player
		int room = player[_arrayNum]->Get_NowRoom();
		vector<int> vNum;	// 候補格納用

		for (int i = 0; i < m_roomEnemy[room].size(); i++){

			int num = EnemyArreySearch(m_roomEnemy[room][i]);

			// 移動中じゃない盾がいたら
			if (enemy[num]->Get_Type() == E_DEFENSE && enemy[num]->Get_State() != E_MOVE){

				vNum.push_back(num);
				break;
			}

			// 移動中じゃない
			if (enemy[num]->Get_State() != E_MOVE)
			{
				vNum.push_back(num);
			}
		}

		// ターゲット候補が見つかったら
		if (vNum.size() > 0){

			int tNum = GetRand(vNum.size() -1);		// ランダム

			// ターゲット決定
			player[_arrayNum]->Set_Target(enemy[vNum[tNum]]->Get_Num());

			DEBUG_LOG("player[%d].Target:%d",_arrayNum , EnemyArreySearch(player[_arrayNum]->Get_TargetNum()));
		}
	}
	else {// Enemy	上記ほぼと同じ

		int room = enemy[_arrayNum]->Get_NowRoom();
		vector<int> vNum;

		for (int i = 0; i < m_roomPlayer[room].size(); i++){

			int num = PlayerArreySearch(m_roomPlayer[room][i]);

			if (player[num]->Get_Type() == E_DEFENSE && player[num]->Get_State() != E_MOVE){

				vNum.push_back(num);
				break;
			}

			// プレイヤーの護衛対象がいたら
			if (player[num]->Get_Type() == E_ESCORT && player[num]->Get_State() != E_MOVE){

				vNum.push_back(num);
				break;
			}

			if (player[num]->Get_State() != E_MOVE){

				vNum.push_back(num);
			}
		}
		if (vNum.size() > 0)
		{
			int tNum = GetRand(vNum.size() - 1);
			enemy[_arrayNum]->Set_Target(player[vNum[tNum]]->Get_Num());
		}
	}
}

/*
void cUnitMgr::TargetSelect()
{
	// Player
	for (int p = 0; p < player.size(); p++)
	{
		vector<int> eNum;
		// Enemy
		for (int e = 0; e < enemy.size(); e++)
		{
			// 同じ部屋かどうか
			if (player[p]->Get_NowRoom() == enemy[e]->Get_NowRoom())
			{
				if (player[p]->Get_State() == E_IDLE && enemy[e]->Get_State() != E_MOVE)
				{
					eNum.push_back(enemy[e]->Get_Num());
				}
				//DEBUG_LOG("同じ部屋");
				 //お互い戦闘中でないか
				if (player[p]->Get_State() != E_ATTACK && enemy[e]->Get_State() != E_ATTACK)
				{

					// 向き
					if (player[p]->Get_Direction() == U_RIGHT)
					{
						if (player[p]->Get_Pos().x <= enemy[e]->Get_Pos().x && player[p]->Get_Pos().x + player[p]->Get_atkR() >= enemy[e]->Get_Pos().x)
						{
							player[p]->Set_Target(enemy[e]->Get_Num());
							player[p]->Set_State(E_ATTACK);
						}
					}
					else
					{
						if (player[p]->Get_Pos().x >= enemy[e]->Get_Pos().x && player[p]->Get_Pos().x - player[p]->Get_atkR() <= enemy[e]->Get_Pos().x)
						{
							player[p]->Set_Target(enemy[e]->Get_Num());
							player[p]->Set_State(E_ATTACK);
						}
					}

					if (enemy[e]->Get_Direction() == U_RIGHT)
					{
						if (enemy[e]->Get_Pos().x <= player[p]->Get_Pos().x && enemy[e]->Get_Pos().x + enemy[e]->Get_atkR() >= player[p]->Get_Pos().x)
						{
							enemy[e]->Set_Target(player[p]->Get_Num());
							enemy[e]->Set_State(E_ATTACK);
						}
					}
					else
					{
						if (enemy[e]->Get_Pos().x >= player[p]->Get_Pos().x && enemy[e]->Get_Pos().x - enemy[e]->Get_atkR() <= player[p]->Get_Pos().x)
						{
							enemy[e]->Set_Target(player[p]->Get_Num());
							enemy[e]->Set_State(E_ATTACK);
						}
					}
				}
			}
		}
		if (eNum.size() > 0)
		{
			int num = GetRand(eNum.size() - 1);
			player[p]->Set_Target(eNum[num]);
		}
	}
}
*/

// 部屋ごとにUnitを整理
void cUnitMgr::InRoomUnit(){

	// いったんリセット
	for (int i = 0; i < m_mapData.size(); i++){

		m_roomPlayer[i].clear();
		m_roomEnemy[i].clear();
	}

	// ユニットの部屋ごとに分ける
	for (int i = 0; i < player.size(); i++){

		m_roomPlayer[player[i]->Get_NowRoom()].push_back(player[i]->Get_Num());
	}

	for (int i = 0; i < enemy.size(); i++){

		m_roomEnemy[enemy[i]->Get_NowRoom()].push_back(enemy[i]->Get_Num());
	}
}

// 攻撃の中継
int cUnitMgr::AttackRelay(int _atkP, int _difNum, int _atkNum){

	int tmp = 0;	// 攻撃対象の配列番号

	// プレイヤーにいる？
	if ((tmp = PlayerArreySearch(_difNum)) != -1){

		// 攻撃
		player[tmp]->Defense(_atkP, _atkNum);
		return 0;
	}

	// 敵にいる？
	if ((tmp = EnemyArreySearch(_difNum)) != -1){

		// 攻撃
		enemy[tmp]->Defense(_atkP, _atkNum);
		return 0;
	}

	return 0;
}

// 護衛対象が生きているかどうかの判定
bool cUnitMgr::EscortDie(){

	if (player[0]->Get_Hp() <= 0){
		// え、死んだんだけど...
		return false;
	}

	return true;
}

// ユニットが死んだときの処理
void cUnitMgr::UnitDie(){

	// プレイヤー
	for (int i = 0; i < player.size(); i++){

		if (player[i]->Get_Hp() <= 0){

			player.erase(player.begin() + i);
			DEBUG_LOG("player[%d].Die:%d", i, player.size());
		}
	}

	// 敵
	for (int i = 0; i < enemy.size(); i++){

		if (enemy[i]->Get_Hp() <= 0){

			enemy.erase(enemy.begin() + i);
			DEBUG_LOG("enemy[%d].Die:%d", i, enemy.size());
		}
	}
}
// 攻撃対象がいなくなったらIdleへ
void cUnitMgr::NoTarget(){

	// プレイヤー
	for (int i = 0; i < player.size(); i++){

		if (player[i]->Get_TargetNum() < 0){
			// 俺の獲物いねーじゃん！
			player[i]->Set_State(E_IDLE);
		}
	}

	// 敵
	for (int i = 0; i < enemy.size(); i++){

		if (enemy[i]->Get_TargetNum() < 0){

			enemy[i]->Set_State(E_IDLE);
		}
	}
}

// Unitナンバーからエネミーを探す
int cUnitMgr::EnemyArreySearch(int _num){

	for (int i = 0; i < enemy.size(); i++){

		if (enemy[i]->Get_Num() == _num){

			return i;
		}
	}

	return -1;
}

// Unitナンバーからプレイヤーを探す
int cUnitMgr::PlayerArreySearch(int _num){

	for (int i = 0; i < player.size(); i++){

		if (player[i]->Get_Num() == _num){

			return i;
		}
	}

	return -1;
}

// プレイヤーとの当たり判定
int cUnitMgr::CheckPlayerClick(VECTOR _pos){

	for (int i = 0; i < player.size(); i++){

		VECTOR p_pos = player[i]->Get_Pos();

		// x
		if ((p_pos.x - UNIT_WIDTH / 2) <= _pos.x && (p_pos.x + UNIT_WIDTH / 2) >= _pos.x){

			// y
			if ((p_pos.y - UNIT_HEIGHT / 2) <= _pos.y && (p_pos.y + UNIT_HEIGHT / 2) >= _pos.y){

				return player[i]->Get_Num();
			}
			
		}
		
	}
	return -1;
}

/*
int cUnitMgr::CheckEnemyClick(VECTOR _pos)
{
	for (int i = 0; i < enemy.size(); i++)
	{
		VECTOR e_pos = enemy[i]->Get_Pos();

		if ((e_pos.x - UNIT_WIDTH / 2) <= _pos.x && (e_pos.x + UNIT_WIDTH / 2) >= _pos.x)
		{
			if ((e_pos.y - UNIT_HEIGHT / 2) <= _pos.y && (e_pos.y + UNIT_HEIGHT / 2) >= _pos.y)
			{
				return enemy[i]->Get_Num();
			}
		}
	}
	return -1;
}
*/

/********************	ユニット生成	**************************/
int cUnitMgr::UnitGenerate()
{
	sUnitGene gene = m_geneUI->UnitGenerate();
	if (gene.unitID <= -1) return 0;

	switch (m_unitCsvData[gene.unitID].type)
	{
	case E_SORD:
		if (m_roomPlayer[gene.mapID].size() >= m_mapData[gene.mapID].roomSize) {
			return -1;
		}
		player.emplace_back(new cPSord(m_unitCsvData[gene.unitID], gene.mapID));
		break;

	case E_ARCHAR:
		if (m_roomPlayer[gene.mapID].size() >= m_mapData[gene.mapID].roomSize) {
			return -1;
		}
		player.emplace_back(new cPArcher(m_unitCsvData[gene.unitID], gene.mapID));
		break;

	case E_DEFENSE:
		if (m_roomPlayer[gene.mapID].size() >= m_mapData[gene.mapID].roomSize) {
			return -1;
		}
		player.emplace_back(new cPDefense(m_unitCsvData[gene.unitID], gene.mapID));
		break;
	default:
		break;
	}

	return 0;
}

int cUnitMgr::Add_PSord(double _x, double _y, int _room){
	if (m_roomPlayer[_room].size() >= m_mapData[_room].roomSize) {
		return -1;
	}
	player.emplace_back(new cPSord(_x, _y, _room, m_num));
	m_num++;

	return 0;
}

int cUnitMgr::Add_PArcher(double _x, double _y, int _room)
{
	if (m_roomPlayer[_room].size() >= m_mapData[_room].roomSize) {
		return -1;
	}
	player.emplace_back(new cPArcher(_x, _y, _room, m_num));
	m_num++;

	return 0;
}

int cUnitMgr::Add_PDefense(double _x, double _y, int _room)
{
	if (m_roomPlayer[_room].size() >= m_mapData[_room].roomSize) {
		return -1;
	}
	player.emplace_back(new cPDefense(_x, _y, _room, m_num));
	m_num++;

	return 0;
}

sTypeCnt cUnitMgr::Get_TypeCnt(){

	m_typeCnt.sord = 0;
	m_typeCnt.archar = 0;
	m_typeCnt.defense = 0;

	// カウント
	for (int i = 0; i < player.size(); i++){

		switch (player[i]->Get_Type()){

		case E_SORD:
			m_typeCnt.sord++;
			break;

		case E_ARCHAR:
			m_typeCnt.archar++;
			break;

		case E_DEFENSE:
			m_typeCnt.defense++;
			break;
		default:
			break;
		}
	}

	return m_typeCnt;
}

void cUnitMgr::Set_MapData(vector<sMapData> _mapData){

	m_mapData = _mapData;
	m_geneUI->Set_MapData(m_mapData);

	for (int i = 0; i < m_mapData.size(); i++)
	{
		m_roomPlayer.push_back(vector<int>());
		m_roomEnemy.push_back(vector<int>());
	}
}

void cUnitMgr::Set_NextPlayerPos(int _playerNum, int _nextRoom, double _nextX){

	for (int i = 0; i < player.size(); i++){

		if (player[i]->Get_Num() == _playerNum){

			player[i]->Set_NextMove(_nextRoom, _nextX);
			player[i]->Set_State(E_MOVE);
		}
		//DEBUG_LOG("次の座標セット");
	}
}

void cUnitMgr::Set_NextEnemyPos(int _enemyNum, int _nextRoom, int _nextX){

	enemy[_enemyNum]->Set_NextMove(_nextRoom, _nextX);
	enemy[_enemyNum]->Set_State(E_MOVE);
	//DEBUG_LOG("敵の移動先セット");
}

void cUnitMgr::SelectUI(int _num){

	double sx = player[_num]->Get_Pos().x;
	double sy = (player[_num]->Get_Pos().y + UNIT_HEIGHT / 2 + 13);

	DrawBillboard3D(VGet(sx, sy, 0.0f), 0.5f, 0.5f, 18.0f, 0.0f, m_selectMarkImg, TRUE);
}

void cUnitMgr::MoveRand() {

	int moveRand = 0;	// 動き始まめるかどうか　0=動かない, 1=tmptblの部屋番号に動く
	moveRand = GetRand(1);
	for (int i = 0; i < enemy.size(); i++) {

		if (moveRand == 0) { enemy[i]->Set_State(E_IDLE); }

		if (moveRand == 1) {
			enemy[i]->Set_State(E_MOVE);
		}
	}
}

// Unitの移動
void cUnitMgr::UnitMove() {

	int findNum = 0;	// MapNavigationで中身を入れる
	int loodtbl = 0;	// 次行く部屋
	int moveCoolTime = GetRand(MOVE_COOLTIME_MAX) + MOVE_COOLTIME_MIN;

	//int moveRand = GetRand(1);	// 動き始まめるかどうか　0=動かない, 1=tmptblの部屋番号に動く
	//int tmp = GetRand(m_mapNavigate.Get_EnemySpawnRoom);

	if (m_moveCnt >= moveCoolTime) {		// m_moveCntが一定になったら

		for (int i = 0; i < enemy.size(); i++) {
			int moveSelectEnemy = GetRand(i);	// 今いる出現しているどの敵を動かすかランダム

			/// MapNavigation関数のreturnを代入　次行く部屋の部屋番号
			loodtbl = m_mapNavigate.MapNavigation(enemy[i]->Get_NowRoom(), findNum);

			if (enemy[moveSelectEnemy]->Get_NowRoom() != 0) {		// 今の部屋が0じゃなかったら

				int cnt = 0;
				cnt = m_roomEnemy[loodtbl].size();			// 次行きたい部屋の敵の数
				int roomMax = m_mapData[loodtbl].roomSize;		// 次行きたい部屋の数制限

				//	　今いる部屋をreturn
				if (cnt > roomMax) { return enemy[i]->Set_Room(enemy[i]->Get_NowRoom()); }
				else if (cnt < roomMax) {		// 次行きたい部屋に空きがあったら
					enemy[moveSelectEnemy]->Set_Room(loodtbl);
					WaitTimer(100);

				}
				m_moveCnt = 0;
				//break;
			}
		}
	}
}