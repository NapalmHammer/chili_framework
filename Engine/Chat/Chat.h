#pragma once

#include "Menu.h"
#include "Text.h"
#include "ChatLog.h"
#include "Client\Client.h"
#include "ChatWindow.h"

class Chat
{
public:
	Chat(Graphics& _gfx, Keyboard& _kbd, Mouse& _ms);
	void UpdateChat();
	void DrawChat();
private:
	Graphics& gfx;
	Keyboard& kbd;
	Mouse& mouse;

	Text text;
	ChatLog chatLog;
	Client client;
	ChatWindow chatWindow;
	MainMenu mainMenu;
	Vec4 pos;

	Keyboard::Event kbdEvent;
	Mouse::Event mouseEvent;
	std::pair<int, int> mouseCur;
	char curChar;
};