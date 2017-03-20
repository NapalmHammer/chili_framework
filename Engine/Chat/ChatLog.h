#pragma once
#include <vector>
#include <string>
class Vec4;
class Graphics;
class Text;

class ChatLog
{
public:
	ChatLog(const unsigned int _historyLength, Graphics& _gfx);
	void SUpdateLog(const std::string _message);
	void UpdateLog(const std::string _name, const std::string _message);
	void DrawLogToWindow(const Vec4& _windowPos, const Vec4& _topBar, Text& _text);
	void OutputLog();

	const std::string& Getlog(const int _iter) const;
	const int GetMessageSize(const int _iter) const;
	const int GetMessageListSize() const;

private:
	void CycleLog();

	unsigned int histLength;
	int msgCount;
	std::vector<std::string> log;
};