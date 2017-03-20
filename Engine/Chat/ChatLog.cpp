#include "ChatLog.h"
#include "Text.h"
#include "../Graphics.h"
#include "Vec4.h"
#include <fstream>

ChatLog::ChatLog(const unsigned int _historyLength, Graphics& _gfx)
{
	msgCount = 0;
	histLength = _historyLength - 1;
}

void ChatLog::UpdateLog(const std::string _name, const std::string _message)
{
	if (log.size() > histLength)
	{
		CycleLog();
		log[histLength] = _name + ":" + _message;
	}
	else
	{
		log.push_back(_name + ":" + _message);
	}
	msgCount++;

	if (msgCount % histLength == 0)
		OutputLog();
}

void ChatLog::SUpdateLog(const std::string _message)
{
	if (log.size() > histLength)
	{
		CycleLog();
		log[histLength] = _message;
	}
	else
	{
		log.push_back(_message);
	}
	msgCount++;

	if (msgCount % histLength == 0)
		OutputLog();
}

void ChatLog::CycleLog()
{
	for (unsigned int i = 0; i < log.size() - 1; i++)
		std::swap(log[i], log[i + 1]);
}

const std::string& ChatLog::Getlog(const int _iter) const
{
	return log[_iter];
}

const int ChatLog::GetMessageSize(const int _iter) const
{
	return (int)log[_iter].size();
}
const int ChatLog::GetMessageListSize() const
{
	return (int)log.size();
}


void ChatLog::OutputLog()
{
	std::ofstream oFile;
	oFile.open("chatlog.txt", std::ios::app);
	auto count = msgCount % histLength;
	if (count != 0)
	{
		for (auto i = (int)log.size() - count; i < log.size(); i++)
		{
			oFile << log[i];
			oFile << '\n';
		}
	}
	else
	{
		for (unsigned int i = 0; i < log.size(); i++)
		{
			oFile << log[i];
			oFile << '\n';
		}
	}
	oFile.close();
}

void ChatLog::DrawLogToWindow(const Vec4& _windowPos, const Vec4& _topBar, Text& _text)
{
	//-- Forgot how all this works.. I know it's messy, I'll sort through it later --\/
	unsigned int numDisplayLines = (((_windowPos.y2 - _topBar.y2) - 20) / 10) - 1; 
	int totalMessagesToDisp = GetMessageListSize();				
	int displayLineX = _windowPos.x + 5;								
	int displayLineY = _windowPos.y2 - 35;							
	int textBoxWidth = ((_windowPos.x2 - _windowPos.x) - 10) / 6;			

	std::vector<std::string> dispText;

	for (auto i = totalMessagesToDisp; i > 0; i--)
	{
		if (GetMessageSize(i - 1) <= textBoxWidth)
		{
			dispText.push_back(Getlog(i - 1));
		}
		else
		{
			int curMessageLength = GetMessageSize(i - 1);
			int counter = 0;

			while (curMessageLength > textBoxWidth)
			{
				curMessageLength -= textBoxWidth;
				counter++;
			}
			//--------------------------
			std::string temp;
			for (auto j = (GetMessageSize(i - 1) - curMessageLength); j < GetMessageSize(i - 1); j++)
			{
				temp.push_back(Getlog(i - 1)[j]);
			}
			dispText.push_back(temp);
			//--------------------------
			for (auto j = counter; j > 0; j--)
			{
				curMessageLength += textBoxWidth;
				std::string temp;
				int newblock = GetMessageSize(i - 1) - curMessageLength;
				for (auto k = newblock; k < newblock + textBoxWidth; k++)
				{
					temp.push_back(Getlog(i - 1)[k]);
				}
				dispText.push_back(temp);
			}
		}

		if (!(dispText.size() < numDisplayLines))
			break;
	}

	for (unsigned int i = 0; i < dispText.size(); i++)
	{
		if (displayLineY > _topBar.y2)
		{
			_text.StrToText(dispText[i], displayLineX, displayLineY, 255, 255, 255);
			displayLineY -= 10;
		}
	}
}