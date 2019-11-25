#include "Log.h"

cLog::cLog()
{
	m_x = 10;
	m_y = 20;
	m_maxLogs = 5;

	count = 0;
}

cLog::~cLog()
{

}

void cLog::Update()
{
	while (m_message.size() > m_maxLogs)
	{
		m_message.pop_back();
	}
}

void cLog::Draw()
{
	SetFontSize(15);

	for (int i = 0; i < m_message.size(); i++)
	{
		//int j = 5 - i;
		DrawFormatString(m_x, (WINDOW_HEIGHT - 20) - m_y * i, RD, "%s", m_message[i].c_str());
	}
}

void cLog::DebugLog(string _message)
{
	count++;
	m_message.insert(m_message.begin(), count + "F" + _message);
}