#pragma once
#include "DxLib.h"
#include "Singleton.h"
#include <vector>
#include <string>
#include "ColorListh.h"
#include "Constant.h"
#include <stdarg.h>
#include "Keyboard.h"

using namespace std;

#define DEBUG_LOG(_format, ...) cLog::Instance()->DebugLog(_format, __VA_ARGS__);

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

	const int m_fontSize = 15;

public:
	void Update();
	void Draw();

	/*********************************************************************
	�֐����Fvoid DebugLog(const char* _format, ...)
	�T�v�F�����t�����O
			�g������printf�Ɠ���
	�����F_format:�\����������������, ...�\�������鐔�l
	�߂�l�F�Ȃ�
	*********************************************************************/
	void DebugLog(const char* _format, ...);
};