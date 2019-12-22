#pragma once

#include "BaseTask.h"
#include "Constant.h"
#include "Sound.h"
#include <vector>
#include "Log.h"
#include "CSVLoad.h"
using namespace std;

#ifndef _INCLUDE_BASE_UNIT_
#define _INCLUDE_BASE_UNIT_

#define MOVE_CNT 400		// �ړ�����܂ł̃J�E���g
/********************************************************
���T�v
�@Unit�̃x�[�X�N���X

���쐬��
�@���䗲���Y

********************************************************/

class cBaseUnit : public cBaseTask{

protected:
	VECTOR m_pos;			// ���W
	int m_num;				// ���j�b�g�ԍ�
	int m_Type;				// ���j�b�g�^�C�v
	int m_targetNum;		// �U���Ώۂ̔ԍ�
	int m_hp;				// HP
	int m_room;				// ���݂��镔���ԍ�
	int m_atk;				// �U����
	int m_condition;		// ��Ԉُ�
	double m_speed;			// �ړ����x
	int m_atkCoolTime;		// ���̍U���܂ł̎���
	int m_atkCnt;			// �U���܂ł̃J�E���g
	double m_atkR;			// �˒��͈�
	int m_Defense;			// �h��
	bool m_isOnActive;		// �����t���O
	int m_state;			// ���݂̏��
	int m_direction;		// ���j�b�g�̌����@1(U_RIGHT):�E -1(U_LEFT):��
	int m_moveCnt;			// �A�j���[�V�����p�J�E���g
	int m_moveAnime[4] = { 1, 0, 1, 2};	// �A�j���[�V�����z��
	int m_effectImage[2];	// Effect�p
	int m_effectAnimeCnt;	// Effect�A�j���[�V�����J�E���g
	bool m_isEffect;		// Effect�Đ��t���O
	sNextMove m_nextMove;	// ���Ɍ������ꏊ

	int m_imgNum;			// �A�j���[�V�����i���o�[
	int m_imgtbl[6];		// �摜�z��

	int m_moveStartCnt = 0;				// ��萔�܂ōs������ړ�
	int m_moveType = 0;				// move����Type�����߂郉���_��

	//vector<cPlayerUnit*> m_player;	// Player��vectorSet
	//vector<cEnemyUnit*> m_enemy;	// Enemy��vector��Set
	//vector<vector<int>> tmpRoomPlayer;	// �����Ԃ�PlayerUnit��
	//vector<vector<int>> tmpRoomEnemy;	// �����Ԃ�EnemyUnit��
	
public:

	cBaseUnit();
	virtual ~cBaseUnit();
	virtual void Update();
 	virtual void Draw();

	/*********************************************************************
	�֐����Fvoid RoomDraw()
	�T�v�F�����̒��̕`��
	�����FVECTOR:�`����W
	�߂�l�F�Ȃ�
	*********************************************************************/
	//void RoomDraw(VECTOR _vPos);

	/*********************************************************************
	�֐����Fvoid Move()
	�T�v�F�ړ�����
	�����F�Ȃ�
	�߂�l�F�Ȃ�
	*********************************************************************/
	void Move();

	/*********************************************************************
	�֐����Fbool Attack()
	�T�v�F�U���^�C�~���O����
	�����F�Ȃ�
	�߂�l�Ftrue:�U��	false:���`���[�W
	*********************************************************************/
	bool Attack();

	/*********************************************************************
	�֐����Fvirtual void AttackSE()
	�T�v�F�U��SE�Ăяo��
	�����F�Ȃ�
	�߂�l�F�Ȃ�
	*********************************************************************/
	virtual void AttackSE() {}

	/*********************************************************************
	�֐����Fvoid AttackStart()
	�T�v�Ftarget�����܂�����AState���U�����[�h��
	�����F�Ȃ�
	�߂�l�F�Ȃ�
	*********************************************************************/
	void AttackStart();

	/*********************************************************************
	�֐����Fvoid Defense(int _atkPoint, int _atkNum)
	�T�v�F�U��������󂯎��
	�����Fint:�_���[�W��, int:�U������Unit�̃i���o�[
	�߂�l�F�Ȃ�
	*********************************************************************/
	void Defense(int _atkPoint, int _atkNum);

	/*********************************************************************
	�֐����Fvirtual void AttackAnime()
	�T�v�F�U���p�A�j���[�V����
	�����FVECTOR:�U���Ώۂ̈ʒu
	�߂�l�F�Ȃ�
	*********************************************************************/
	void AttackAnime(VECTOR _targetPos);

	/*********************************************************************
	�֐����Fvoid UnitMove(int _player, int _enemy)
	�T�v�FUnit�̕����Ԉړ�����
	�����F
	�߂�l�F�Ȃ�
	*********************************************************************/
	//void UnitMove(int _player, int _enemy);


	/************************************    Get    *****************************************/

	// ����
	int Get_Direction(){
		return m_direction;
	}

	// �U���͈�
	double Get_atkR(){
		return m_atkR;
	}

	// ���݂̕����ԍ�
	int Get_NowRoom(){
		return m_room;
	}

	// �U���^�C�~���O�J�E���g
	int Get_AtkCnt(){
		return m_atkCnt;
	}

	// �Η�
	int Get_AtkPoint(){
		return m_atk;
	}

	// ���݂̃^�[�Q�b�g�i���o�[
	int Get_TargetNum(){
		return m_targetNum;
	}

	// �̗�
	int Get_Hp(){
		return m_hp;
	}

	// ���ݍ��W
	VECTOR Get_Pos(){
		return m_pos;
	}

	// ���݂̃X�e�[�g
	int Get_State(){
		return m_state;
	}

	// Effect�`��t���O
	bool Get_EffectFlg(){
		return m_isEffect;
	}

	// Unit�i���o�[
	int Get_Num(){
		return m_num;
	}

	int Get_Type(){
		return m_Type;
	}

	/************************************    Set    *****************************************/

	/*********************************************************************
	�֐����Fvoid Set_NextMove(int _nextRoom, double _nextX)
	�T�v�F�ړ���Z�b�g
	�����Fint:�ړ���̕����ԍ�, double:�ړ����x���W
	�߂�l�F�Ȃ�
	*********************************************************************/
	void Set_NextMove(int _nextRoom, double _nextX){
		m_nextMove.sNextRoom = _nextRoom;
		m_nextMove.sNextX = _nextX;
	}

	/*********************************************************************
	�֐����Fvoid Set_Target(int _num)
	�T�v�F�^�[�Q�b�g�̃Z�b�g
	�����F�^�[�Q�b�g�ɂ���Unit�i���o�[
	�߂�l�F�Ȃ�
	*********************************************************************/
	void Set_Target(int _num){
		m_targetNum = _num;
	}

	/*********************************************************************
	�֐����Fvoid Set_State(eState _state)
	�T�v�F�X�e�[�g�̕ύX
	�����FeState:�X�e�[�g
	�@�@�@Constant.h �Q��
	�߂�l�F�Ȃ�
	*********************************************************************/
	void Set_State(eState _state){
		m_state = _state;
	}

	/*********************************************************************
	�֐����Fvoid Set_Pos(VECTOR _pos)
	�T�v�F���W�Z�b�g
	�����FVECTOR:���W
	�߂�l�F�Ȃ�
	*********************************************************************/
	void Set_Pos(VECTOR _pos){
		m_pos = _pos;
	}

	/*********************************************************************
	�֐����Fvoid Set_Room(int _room)
	�T�v�F�������Z�b�g
	�����Fint:�����ԍ�
	�߂�l�F�Ȃ�
	*********************************************************************/
	void Set_Room(int _room){
		m_room = _room;
	}

};

#endif // !_INCLUDE_BASE_UNIT_