#pragma once

#ifndef _INCLUED_DEBUGLIST_
#define _INCLUED_DEBUGLIST_

/********************************************************
���T�v
�@�f�o�b�O�ŕ\���������̂��Ǘ����܂��B
�@�����[�X���ɂ͂��̃t�@�C�����C���N���[�h���܂���B

���g����
�@�e�I�u�W�F�N�g�̃f�o�b�O�� #ifdef ���g�p���Ă��������B
�@#ifdef �̖��O�����̃t�@�C���� #define �Œ�`���܂��B
�@
 ��ifdef�ɂ���
 �@#ifdef �f�t�@�C���̖��O
    �f�o�b�O���e
�@ #endif
  �f�t�@�C���̖��O����`����Ă��Ȃ���
  �ǂݍ��܂�Ȃ��Ƃ��������ł��B

*********************************************************/


/********************************************************
#define �ꗗ
�����K���F�I�u�W�F�N�g��_DEBUG
���A�C�E�G�I���ɂȂ�悤�ɂ��Ă�������
********************************************************/
#define FPS_DEBUG			// FPS
#define KEYBOARD_DEBUG		// �L�[�{�[�h
#define GAMEMGR_DEBUG		// �Q�[���}�l�[�W���[
#define SCENE_MGR_DEBUG		// �V�[���}�l�[�W���[
#define TITLE_DEBUG			// �^�C�g��
#define MOUSE_DEBUG			// �}�E�X
#define MAP_MGR_DEBUG		// �}�b�v�}�l�[�W���[
#define MAP_DEBUG			// �}�b�v
#define MENU_DEBUG			// ���j���[
#define RESULT_DEBUG		// ���U���g
#define UNIT_MGR_DEBUG		// ���j�b�g�}�l�[�W���[
#define UNIT_DEBUG			// ���j�b�g

#endif // !_INCLUED_DEBUGLIST_