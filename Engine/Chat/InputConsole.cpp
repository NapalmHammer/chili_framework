#include "InputConsole.h"
#include "NapalmUtils.h"
#include "../Graphics.h"
#include "Text.h"
#include "ChatLog.h"

void Console::Reset( const bool SetActive)
{
	active = SetActive;
	buffer.clear();
	conState = Idle;
}

void Console::CalculatePosition(const Vec2& _pos, const int _width, const int _height)
{
	rect.x = _pos.x + 1;
	rect.y = _pos.y;
	rect.x2 = rect.x + _width;
	rect.y2 = rect.y + _height;

	inputBox.x = rect.x + 1;
	inputBox.y = rect.y2 - 26;
	inputBox.x2 = rect.x2 - 1;
	inputBox.y2 = rect.y2 - 1;
}

void Console::HandleKBDInput(const Keyboard::Event& _kbdEvent, const char& _curKey)
{
	if (_curKey > 31 && _curKey < 123)
		buffer += _curKey;
	if (_kbdEvent.GetCode() == VK_RETURN && _kbdEvent.IsRelease())
	{
		if (buffer.size() > 0)
		{
			conState = Finished;
		}
		else
		{
			conState = Finished;
			Reset(true);
		}
	}
	else if (_curKey == 8 && buffer.size() > 0)
	{
		buffer.pop_back();
	}
}

InputConsole::InputConsole()
{
	conState = Idle;
	active = true;
}

void InputConsole::Update(const Keyboard::Event& _kbdEvent, const char& _curKey, const Mouse::Event& _msEvent, const std::pair<int, int>& _msPair)
{
	if (_msEvent.GetType() == Mouse::Event::Type::LPress)
	{
		if (CheckMouseIsIn(rect, _msEvent, _msPair))
		{
			active = true;
		}
		else
		{
			active = false;
		}
	}

	if (active)
	{
		HandleKBDInput(_kbdEvent, _curKey);
	}
}

void InputConsole::Draw(Graphics& _gfx, Text& _text)
{
	_gfx.DrawSquare(rect, 200, 0, 0);
	_gfx.FillSquare(rect.x, rect.y, rect.x2, rect.y2, 100, 100, 100);
	_gfx.DrawSquare(inputBox, 150, 0, 0);
	_gfx.FillSquare(inputBox.x, inputBox.y, inputBox.x2, inputBox.y2, 150, 150, 150);

	auto halfWidth = (rect.x + ((rect.x2 - rect.x)) / 2);
	auto halfHeight = (rect.y + (((rect.y2 - 26) - rect.y)) / 2);
	_text.StrToText("input console", halfWidth - (14 * Text::letterSize) / 2, (halfHeight - 3), 230, 100, 250);
	if (active)
	{
		_gfx.PutLine(float(inputBox.x + 5), float(inputBox.y2 - 5), float(inputBox.x2 - 25), float(inputBox.y2 - 5), 255, 255, 255);

	}

	if (buffer.size() > unsigned int(((inputBox.x2 - inputBox.x) - 30) / Text::letterSize))
	{
		std::string newstr;
		int spot = ((int)buffer.size() - (((inputBox.x2 - inputBox.x) - 30) / Text::letterSize));
		for (unsigned int i = spot; i < buffer.size(); i++)
		{
			newstr.push_back(buffer[i]);
		}
		_text.StrToText(newstr, inputBox.x + 10, inputBox.y2 - 15, 255, 255, 255);
	}
	else
	{
		_text.StrToText(buffer, inputBox.x + 10, inputBox.y2 - 15, 255, 255, 255);
	}
}

ChatConsole::ChatConsole()
{
	conState = Idle;
	active = true;
}

void ChatConsole::Update(const Keyboard::Event & _kbdEvent, const char & _curKey, const Mouse::Event & _msEvent, const std::pair<int, int>& _msPair)
{
	if (_msEvent.LeftIsPressed())
	{
		if (CheckMouseIsIn(rect, _msEvent, _msPair))
		{
			active = true;
		}
		else
		{
			active = false;
		}
	}

	if (active)
	{
		HandleKBDInput(_kbdEvent, _curKey);
	}
}

void ChatConsole::Draw(Graphics& _gfx, Text& _text)
{
	_gfx.DrawSquare(rect, 200, 0, 0);
	_gfx.FillSquare(rect.x, rect.y, rect.x2, rect.y2, 100, 100, 100);
	_gfx.DrawSquare(inputBox, 150, 0, 0);
	_gfx.FillSquare(inputBox.x, inputBox.y, inputBox.x2, inputBox.y2, 150, 150, 150);

	auto halfWidth = (rect.x + ((rect.x2 - rect.x)) / 2);
	auto halfHeight = (rect.y + (((rect.y2 - 26) - rect.y)) / 2);
	_text.StrToText("Chat console", halfWidth - (14 * Text::letterSize) / 2, (halfHeight - 3), 230, 100, 250);

	if (active)
	{
		if (active)
		{
			_gfx.PutLine(float(inputBox.x + 5), float(inputBox.y2 - 5), float(inputBox.x2 - 25), float(inputBox.y2 - 5), 255, 255, 255);

		}
	}


	if (buffer.size() > unsigned int(((inputBox.x2 - inputBox.x) - 30) / Text::letterSize))
	{
		std::string newstr;
		int spot = ((int)buffer.size() - (((inputBox.x2 - inputBox.x) - 30) / Text::letterSize));
		for (unsigned int i = spot; i < buffer.size(); i++)
		{
			newstr.push_back(buffer[i]);
		}
		_text.StrToText(newstr, inputBox.x + 10, inputBox.y2 - 15, 255, 255, 255);
	}
	else
	{
		_text.StrToText(buffer, inputBox.x + 10, inputBox.y2 - 15, 255, 255, 255);
	}
}
