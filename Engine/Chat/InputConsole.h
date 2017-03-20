#pragma once
#include "../Mouse.h"
#include "../Keyboard.h"
#include "Vec4.h"
#include <string>

class Graphics;
class ChatLog;
class Text;

enum ConsoleState
{
	Idle,
	In_Use,
	Finished
};

class Console
{
public:
	virtual void Update(const Keyboard::Event& _kbdEvent, const char& _curKey, const Mouse::Event& _msEvent, const std::pair<int, int>& _msPair) = 0;
	virtual void Draw(Graphics& _gfx, Text& _text) = 0;

	void Reset(const bool SetActive = false);
	void CalculatePosition(const Vec2& _pos,const int _width, const int _height);
	void SetConState(const ConsoleState _state) { conState = _state; };

	const bool GetActive() const { return active; };
	const ConsoleState GetConState() const { return conState; };
	std::string& GetBuffer() { return buffer; };

protected:
	void HandleKBDInput(const Keyboard::Event& _kbdEvent, const char& _curKey);

protected:
	ConsoleState conState;
	bool active;
	Vec4 rect;
	Vec4 inputBox;
	std::string buffer;

};

class InputConsole : public Console
{
public:
	InputConsole();
	void Update(const Keyboard::Event& _kbdEvent, const char& _curKey, const Mouse::Event& _msEvent, const std::pair<int, int>& _msPair);
	void Draw(Graphics& _gfx, Text& _text);
};

class ChatConsole : public Console
{
public:
	ChatConsole();
	void Update(const Keyboard::Event& _kbdEvent, const char& _curKey, const Mouse::Event& _msEvent, const std::pair<int, int>& _msPair);
	void Draw(Graphics& _gfx, Text& _text);
};