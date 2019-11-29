#include "Log.h"

cLog::cLog()
{
	m_x = 10;
	m_y = 20;
	m_maxLogs = 5;

	m_count = 0;
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

void cLog::DebugLog(const char* _format, ...)
{
	char messageSize[256];
	char* message = messageSize;
	va_list ap;

	va_start(ap, _format);
	vsnprintf(message, 255, _format, ap);
	va_end(ap);

	m_count++;
	//m_message.insert(m_message.begin(), to_string(m_count) + "F" + message);
}