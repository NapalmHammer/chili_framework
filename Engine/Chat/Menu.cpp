#include "Menu.h"
#include "Item.h"
#include "NapalmUtils.h"


void Menu::AddItem(std::unique_ptr<Item> _item)
{
	items.emplace_back(std::move(_item));
}

void Menu::AddcontextMenus(std::unique_ptr<Menu> _contextMenu)
{
	contextMenus.emplace_back(std::move(_contextMenu));
}

MainMenu::MainMenu(Graphics& _gfx, Client& _client, int _buttonWidth, int _buttonHeight)
{
	//-- Initialize variable, pointers, references --//
	gfx = &_gfx;
	client = &_client;

	menuButtonWidth = _buttonWidth;
	menuButtonHeight = _buttonHeight;
	active = false;
	mark = 0;
	//-----------------------------------------------//

	//-- Add button items here --\/

	AddItem(std::make_unique<ChatButton>());
	AddItem(std::make_unique<OptionsButton>());
	AddItem(std::make_unique<FilesButton>());
	//---------------------------/\
	//-- So we can get the button item count here, where it will be used later in the constructor. --//
	buttItemCount = (int)items.size();

	//-- Set position of menu --//
	pos.x = 1;
	pos.y = 1;
	pos.x2 = pos.x + menuButtonWidth;
	pos.y2 = pos.y + menuButtonHeight * buttItemCount; 
	//--------------------------//

	//-- Add context menus here --\/

	AddcontextMenus(std::make_unique<ChatMenu>(this));
	AddcontextMenus(std::make_unique<OptionsMenu>(this));
	AddcontextMenus(std::make_unique<FilesMenu>(this));
	//----------------------------/\

	for (auto i = 0; i < buttItemCount; i++)
	{
		items[i]->CalculatePos(Vec2(pos.x, pos.y + menuButtonHeight * i), menuButtonWidth, menuButtonHeight);
	}
}

void MainMenu::Update(const Keyboard::Event& _kbdEvent, const char& _curKey, const Mouse::Event& _msEv, const std::pair<int, int>& _msPair)
{
	for (auto i = 0; i < buttItemCount; i++)
	{
		if (CheckMouseIsIn(items[i]->Get_Pos(), _msEv, _msPair))
		{
			items[i]->Select();
			contextMenus[i]->Activate();
		}
		else
		{
			items[i]->UnSelect();
			if (!CheckMouseIsIn(contextMenus[i]->GetPos(), _msEv, _msPair))
			{
				contextMenus[i]->Deactivate();
			}
		}
		contextMenus[i]->Update(_kbdEvent, _curKey, _msEv, _msPair);
	}
}

void MainMenu::Draw(Graphics& _gfx, ChatLog& _log, Text& _text)
{
	for (unsigned int i = 0; i < items.size(); i++)
	{
		items[i]->Draw(*gfx, _text);
		contextMenus[i]->Draw(_gfx, _log, _text);
	}
}

ChatMenu::ChatMenu(Menu* _menu)
{
	//-- Initialize variable, pointers, references --//
	gfx = _menu->GetGFX();
	client = _menu->GetClient();

	menuButtonWidth = _menu->GetButtonWidth();
	menuButtonHeight = _menu->GetButtonHeight();
	active = false;
	mark = 0;
	//-----------------------------------------------//

	//-- Add button items here --\/
	AddItem(std::make_unique<ConnectButton>());
	AddItem(std::make_unique<DisconnectButton>());
	AddItem(std::make_unique<SaveChatButton>());
	AddItem(std::make_unique<SetNameButton>());
	//---------------------------/\
	//-- So we can get the button item count here, where it will be used later in the constructor. --//
	buttItemCount = (int)items.size();

	//-- Set position of menu --//
	Vec4 temp = _menu->GetPos();
	pos.x = temp.x2 + 1;
	pos.x2 = pos.x + menuButtonWidth;
	pos.y = temp.y;
	pos.y2 = pos.y + menuButtonHeight * buttItemCount;
	//--------------------------//

	for (auto i = 0; i < buttItemCount; i++)
	{
		items[i]->CalculatePos(Vec2(pos.x, pos.y + menuButtonHeight * i), menuButtonWidth, menuButtonHeight);
	}
}

void ChatMenu::Update(const Keyboard::Event& _kbdEvent, const char& _curKey, const Mouse::Event& _msEv, const std::pair<int, int>& _msPair)
{

	for (auto i = 0; i < buttItemCount; i++)
	{
		if (!items[i]->Update(_kbdEvent, _curKey, _msEv, _msPair, this))
		{
			Deactivate();
		}			
	}
}

void ChatMenu::Draw(Graphics& _gfx, ChatLog& _log, Text& _text)
{
	for (unsigned int i = 0; i < items.size(); i++)
	{
		items[i]->Draw(*gfx, _text, active);
	}
}

OptionsMenu::OptionsMenu(Menu* _menu)
{
	//-- Initialize variable, pointers, references --//
	gfx = _menu->GetGFX();
	client = _menu->GetClient();

	menuButtonWidth = _menu->GetButtonWidth();
	menuButtonHeight = _menu->GetButtonHeight();
	active = false;
	mark = 0;
	//-----------------------------------------------//

	//-- Add button items here --\/
	AddItem(std::make_unique<TestButton>());
	//---------------------------/\
		//-- So we can get the button item count here, where it will be used later in the constructor. --//
	buttItemCount = (int)items.size();

	//-- Set position of menu --//
	Vec4 temp = _menu->GetPos();
	pos.x = temp.x2 + 1;
	pos.x2 = pos.x + menuButtonWidth;
	pos.y = temp.y + menuButtonHeight;
	pos.y2 = pos.y + menuButtonHeight * buttItemCount;
	//--------------------------//

	for (auto i = 0; i < buttItemCount; i++)
	{
		items[i]->CalculatePos(Vec2(pos.x, pos.y + (menuButtonHeight * i)), menuButtonWidth, menuButtonHeight);
	}
}

void OptionsMenu::Update(const Keyboard::Event & _kbdEvent, const char & _curKey, const Mouse::Event & _msEv, const std::pair<int, int>& _msPair)
{
	for (auto i = 0; i < buttItemCount; i++)
	{
		if (!items[i]->Update(_kbdEvent, _curKey, _msEv, _msPair, this))
		{
			Deactivate();
		}
	}
}

void OptionsMenu::Draw(Graphics& _gfx, ChatLog& _log, Text& _text)
{
	for (unsigned int i = 0; i < items.size(); i++)
	{
		items[i]->Draw(*gfx, _text, active);
	}
}

FilesMenu::FilesMenu(Menu* _menu)
{
	//-- Initialize variable, pointers, references --//
	gfx = _menu->GetGFX();
	client = _menu->GetClient();

	menuButtonWidth = _menu->GetButtonWidth();
	menuButtonHeight = _menu->GetButtonHeight();
	active = false;
	mark = 0;
	//-----------------------------------------------//

	//-- Add button items here --\/
	AddItem(std::make_unique<SendFile>());
	AddItem(std::make_unique<GetFile>());
	AddItem(std::make_unique<TestButton>());
	//---------------------------/\
			//-- So we can get the button item count here, where it will be used later in the constructor. --//
	buttItemCount = (int)items.size();

	//-- Set position of menu --//
	Vec4 temp = _menu->GetPos();
	pos.x = temp.x2 + 1;
	pos.x2 = pos.x + menuButtonWidth;
	pos.y = temp.y + menuButtonHeight * 2;
	pos.y2 = pos.y + menuButtonHeight * buttItemCount;
	//--------------------------//

	for (auto i = 0; i < buttItemCount; i++)
	{
		items[i]->CalculatePos(Vec2(pos.x, pos.y + menuButtonHeight * i), menuButtonWidth, menuButtonHeight);
	}
}

void FilesMenu::Update(const Keyboard::Event & _kbdEvent, const char & _curKey, const Mouse::Event & _msEv, const std::pair<int, int>& _msPair)
{
	for (auto i = 0; i < buttItemCount; i++)
	{
		if (!items[i]->Update(_kbdEvent, _curKey, _msEv, _msPair, this))
		{
			Deactivate();
		}
	}
}

void FilesMenu::Draw(Graphics& _gfx, ChatLog& _log, Text& _text)
{
	for (unsigned int i = 0; i < items.size(); i++)
	{
		items[i]->Draw(*gfx, _text, active);
	}
}
