#pragma once
#include <string>
#include "Vec4.h"
#include "Client\Client.h"
#include "InputConsole.h"

class Graphics;
class Text;
class Menu;

class Item
{
public:
	virtual void Draw(Graphics& _gfx, Text& _text, const bool _isMenuActive = true);
	virtual void OnClick(Menu* _menu) = 0;
	virtual bool Update(const Keyboard::Event& _kbdEvent, const char& _curKey, const Mouse::Event& _msEv, const std::pair<int, int>& _msPair, Menu* _menu);

	void CalculatePos(const Vec2& _pos, const int _width, const int _height);
	void Select() { selected = true; };
	void UnSelect() { selected = false; };
	const Vec4 Get_Pos() const { return pos; };
	const bool Get_Selected() const { return selected; };

protected:
	bool selected = false;
	Vec4 pos;
	std::string name;
};

class ConsoleButton : public Item
{
public:
	ConsoleButton();
	void OnClick(Menu* _menu) { return; };
	void Draw(Graphics& _gfx, Text& _text, const bool _isMenuActive = true);
	bool Update(const Keyboard::Event& _kbdEvent, const char& _curKey, const Mouse::Event& _msEv, const std::pair<int, int>& _msPair, Menu* _menu);

protected:
	std::unique_ptr<InputConsole> m_console = nullptr;
};

//-- MainMenu Buttons --\/

class ChatButton : public Item
{
public:
	ChatButton();
	void OnClick(Menu* _menu) { return; };
private:
	int a;
};

class OptionsButton : public Item
{
public:
	OptionsButton();
	void OnClick(Menu* _menu) {	return;	};
private:
};

class FilesButton : public Item
{
public:
	FilesButton();
	void OnClick(Menu* _menu) { return; };
private:
};
//------------------------// 

class ConnectButton : public ConsoleButton
{
public:
	ConnectButton();
	void OnClick(Menu* _menu);
};

class DisconnectButton : public Item
{
public:
	DisconnectButton();
	void OnClick(Menu* _menu);
};

class SetNameButton : public ConsoleButton
{
public:
	SetNameButton();
	void OnClick(Menu* _menu);
};

class SaveChatButton : public Item
{
public:
	SaveChatButton();
	void OnClick(Menu* _menu);
};

class DragButton : public Item
{
public:
	DragButton();
	void OnClick(Menu* _menu) { return; };
};

class TopBar : public Item
{
public:
	TopBar();
	void OnClick(Menu* _menu) { return; };
};

class SendFile : public ConsoleButton
{
public:
	SendFile();
	void OnClick(Menu* _menu);
};

class GetFile : public ConsoleButton
{
public:
	GetFile();
	void OnClick(Menu* _menu);
};

class TestButton : public Item
{
public:
	TestButton();
	void OnClick(Menu* _menu) { return; };
};