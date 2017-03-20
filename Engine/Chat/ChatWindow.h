#pragma once
#include "../Keyboard.h"
#include "../Mouse.h"
#include "Item.h"
#include "InputConsole.h"

class ChatLog;
class Graphics;
class Client;
class Text;

class ChatWindow
{
public:
	ChatWindow(Graphics& _gfx, ChatLog& _log, Client& _client, Vec4 _pos);
	void Draw(Text& _text);
	void UpdateChat(const Keyboard::Event& _kbdEvent, const char& _curKey, const Mouse::Event& _msEvent, const std::pair<int, int>& _msPair);

private:
	void CheckResizing(const Mouse::Event& _msEvent, const std::pair<int, int>& _msPair);
	void Resize(const Mouse::Event& _msEvent, const std::pair<int, int>& _msPair);
	void CheckMoving(const Mouse::Event& _msEvent, const std::pair<int, int>& _msPair);
	void Moving(const Mouse::Event& _msEvent, const std::pair<int, int>& _msPair);

	Client& client;
	Graphics& gfx;
	ChatLog& log;

	ChatConsole console;
	TopBar topBar;
	DragButton drag;
	Vec4 pos;

	std::pair<int, int> mouseLast;
	std::string message = "";

	bool inputState;
	bool resizingBox;
	bool movingWindow;

	int width;
	int height;
	int buttonSize;

	static constexpr int chatPad = 5;
};