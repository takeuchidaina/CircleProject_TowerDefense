#include "ErrorCheck.h"

/*****************************************************
���O�@�Fvoid FileCheck(int _fileName)
�T�v�@�F�t�@�C����摜�̒��g�����邩�̃`�F�b�N���s��
�����@�F�t�@�C������ꂽ�ϐ�
�߂�l�F�����@���G���[���o���ۂɂ̓G���[�{�b�N�X���o��
******************************************************/
void FileCheck(int _fileName) {
	if (_fileName == NULL) {
		ErrBox("�k���|");
	}
}