#include "ErrorCheck.h"

/*****************************************************
���O�@�Fvoid FileCheck(int _fileName)
�T�v�@�F�t�@�C����摜�̒��g�����邩�̃`�F�b�N���s��
�����@�F�t�@�C������ꂽ�ϐ�
�߂�l�F�����@���G���[���o���ۂɂ̓G���[�{�b�N�X���o��
******************************************************/
void FileCheck(int _fileName) {
	if (_fileName == -1 || _fileName == NULL) {
		ErrBox("�t�@�C����������܂���ł���");
	}
}

void FileCheck(int _fileName, int _num){

	if (_fileName == -1 || _fileName == NULL) {
		FormatErrBox("�t�@�C����������܂���ł����F%d", _num);
	}
}