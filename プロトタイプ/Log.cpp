#include "Log.h"

cLog::cLog()
{
	m_x = 10;
	m_y = 20;
	m_maxLogs = 5;
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
	for (int i = 0; i < m_message.size(); i++)
	{
		//int j = 5 - i;
		DrawFormatString(m_x, (WINDOW_HEIGHT - 20) - m_y * i, RD, "%s", m_message[i].c_str());
	}
}

void cLog::DebugLog(string _message)
{
	m_message.insert(m_message.begin(), _message);
}