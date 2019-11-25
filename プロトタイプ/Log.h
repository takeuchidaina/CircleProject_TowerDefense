#pragma once
#include "DxLib.h"
#include "Singleton.h"
#include <vector>
#include <string>
#include "ColorListh.h"
#include "Constant.h"
#include <stdarg.h>

using namespace std;

#define DEBUG_LOG(_message) cLog::Instance()->DebugLog(_message);

/********************************************************
���T�v
�@Log�\���N���X
 �E�g����
	��) DEBUG_LOG("�c�������܂�����");

���쐬��
�@���䗲���Y

���X�V��
  10/10 �쐬
�@
********************************************************/
class cLog : public cSingleton<cLog>
{
public:
	cLog();
	~cLog();
	friend cSingleton<cLog>;

private:
	double m_x, m_y;
	vector<string> m_message;
	int m_maxLogs;
	int m_count;

public:
	void Update();
	void Draw();

	/*********************************************************************
	�֐����Fvoid DebugLog(string)
	�T�v�F�f�o�b�O���O��\��

	�����F_message:�\�������������O
	�߂�l�F�Ȃ�
	*********************************************************************/
	void DebugLog(string _message);

};