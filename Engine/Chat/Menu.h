#pragma once
#include "../Mouse.h"
#include "../Keyboard.h"
#include "Item.h"
#include "InputConsole.h"
#include <memory>

class ContextMenu;
class Graphics;
class Text;
class Client;

class Menu
{
public:
	//virtual ~Menu() = 0;
	virtual void Update(const Keyboard::Event& _kbdEvent, const char& _curKey, const Mouse::Event& _msEv, const std::pair<int, int>& _msPair) = 0;
	virtual void Draw(Graphics& _gfx, ChatLog& _log, Text& _text) = 0;

	void AddItem(std::unique_ptr<Item> _item);
	void AddcontextMenus(std::unique_ptr<Menu> _contextMenu);

	const int& GetButtonHeight() const { return menuButtonHeight; };
	const int& GetButtonWidth() const { return menuButtonWidth; };
	const bool GetSelected() const { return selected; };
	const bool GetActive() const { return active; };
	const Vec4 GetPos() const { return pos; };
	Graphics* GetGFX() const { return gfx; };
	Client* GetClient() { return client; };

	void Activate() { active = true; };
	void Deactivate() { active = false; };

protected:
	int mark;
	int buttItemCount;
	int menuButtonWidth;
	int menuButtonHeight;
	bool selected;
	bool active;
	Vec4 pos;
	std::vector<std::unique_ptr<Item>> items;
	std::vector<std::unique_ptr<Menu>> contextMenus;

	Graphics* gfx;
	Client* client;
};

class MainMenu : public Menu
{
public:
	MainMenu(Graphics& _gfx, Client& _client, int _buttonWidth, int _buttonHeight);
	void Update(const Keyboard::Event& _kbdEvent, const char& _curKey, const Mouse::Event& _msEv, const std::pair<int, int>& _msPair);
	void Draw(Graphics& _gfx, ChatLog& _log, Text& _text);
};

class ChatMenu : public Menu
{
public:
	ChatMenu(Menu* _menu);
	void Update(const Keyboard::Event& _kbdEvent, const char& _curKey, const Mouse::Event& _msEv, const std::pair<int, int>& _msPair);
	void Draw(Graphics& _gfx, ChatLog& _log, Text& _text);
};

class OptionsMenu : public Menu
{
public:
	OptionsMenu(Menu* _menu);
	void Update(const Keyboard::Event& _kbdEvent, const char& _curKey, const Mouse::Event& _msEv, const std::pair<int, int>& _msPair);
	void Draw(Graphics& _gfx, ChatLog& _log, Text& _text);
};

class FilesMenu : public Menu
{
public:
	FilesMenu(Menu* _menu);
	void Update(const Keyboard::Event& _kbdEvent, const char& _curKey, const Mouse::Event& _msEv, const std::pair<int, int>& _msPair);
	void Draw(Graphics& _gfx, ChatLog& _log, Text& _text);
};