#include "Item.h"
#include "Text.h"
#include "../Graphics.h"
#include "Menu.h"
#include "NapalmUtils.h"


void Item::Draw(Graphics & _gfx, Text& _text, const bool _isMenuActive)
{
	if (_isMenuActive)
	{
		_gfx.DrawSquare(pos.x, pos.y, pos.x2, pos.y2, 100, 100, 100);
	
		if(selected)
			_gfx.FillSquare(pos.x + 1, pos.y + 1, pos.x2 - 1, pos.y2 - 1, 150, 150, 150);
		else
			_gfx.FillSquare(pos.x + 1, pos.y + 1, pos.x2 - 1, pos.y2 - 1, 100, 100, 100);
	
		auto halfWidth = (pos.x + ((pos.x2 - pos.x)) / 2);
		auto halfHeight = (pos.y + ((pos.y2 - pos.y)) / 2);
		_text.StrToText(name, halfWidth - ((int)name.size() * Text::letterSize) / 2, halfHeight - 3, 230, 100, 250);
	}
}

bool Item::Update(const Keyboard::Event & _kbdEvent, const char & _curKey, const Mouse::Event & _msEv, const std::pair<int, int>& _msPair, Menu * _menu)
{
	if (_menu->GetActive())
	{
		if (CheckMouseIsIn(Get_Pos(), _msEv, _msPair))
		{
			Select();
			if (_msEv.LeftIsPressed())
			{
				OnClick(_menu);
				return false;
			}
			return true;
		}
		else
		{
			UnSelect();
			return true;
		}
	}
	return true;
}

void Item::CalculatePos(const Vec2& _pos, const int _width, const int _height)
{
	pos.x = _pos.x;
	pos.y = _pos.y;
	pos.x2 = pos.x + _width;
	pos.y2 = pos.y + _height;
}

//-- Main Menu Buttons --\/
ChatButton::ChatButton()
{
	name = "Chat";
	selected = false;
}

OptionsButton::OptionsButton()
{
	name = "Options";
	selected = false;
}

FilesButton::FilesButton()
{
	name = "Files";
	selected = false;
}
//------------------------//

ConnectButton::ConnectButton()
{
	name = "Connect";
	selected = false;
}

void ConnectButton::OnClick(Menu* _menu)
{
	//-- Add m_console->GetBuffer() to get the input buffer from the console --//
	_menu->GetClient()->Connect(/*m_console->GetBuffer()*/);
}

DisconnectButton::DisconnectButton()
{
	name = "Disconnect";
	selected = false;
}

void DisconnectButton::OnClick(Menu* _menu)
{
	_menu->GetClient()->Disconnect();
}

SaveChatButton::SaveChatButton()
{
	name = "Save Chat";
	selected = false;
}

void SaveChatButton::OnClick(Menu* _menu)
{
	_menu->GetClient()->GetChatLog().OutputLog();
}

DragButton::DragButton()
{
	name = "D";
	selected = false;
}

TopBar::TopBar()
{
	name = "Top Bar";
	selected = false;
}

SendFile::SendFile()
{
	name = "Send File";
	selected = true;
}

void SendFile::OnClick(Menu * _menu)
{
	_menu->GetClient()->SendFile(m_console->GetBuffer());
}

GetFile::GetFile()
{
	name = "Get File";
	selected = true;
}

void GetFile::OnClick(Menu* _menu)
{
	_menu->GetClient()->RequestFile(m_console->GetBuffer());
}

TestButton::TestButton()
{
	name = "test";
}

void TestButton::OnClick(Menu * _menu)
{
	_menu->GetClient()->GetChatLog().UpdateLog("Testbutton", "This button does nothing.");
}

SetNameButton::SetNameButton()
{
	name = "Set Name";
	selected = true;;
}

void SetNameButton::OnClick(Menu * _menu)
{
	_menu->GetClient()->SetName(m_console->GetBuffer());
}

ConsoleButton::ConsoleButton()
{
	m_console = std::make_unique<InputConsole>();
	Vec2 temp(Get_Pos().x2, Get_Pos().y);
	m_console->CalculatePosition(temp, 150, 50);
}

void ConsoleButton::Draw(Graphics & _gfx, Text & _text, const bool _isMenuActive)
{
	if (_isMenuActive)
	{
		_gfx.DrawSquare(pos.x, pos.y, pos.x2, pos.y2, 100, 100, 100);

		if (selected)
			_gfx.FillSquare(pos.x + 1, pos.y + 1, pos.x2 - 1, pos.y2 - 1, 150, 150, 150);
		else
			_gfx.FillSquare(pos.x + 1, pos.y + 1, pos.x2 - 1, pos.y2 - 1, 100, 100, 100);

		auto halfWidth = (pos.x + ((pos.x2 - pos.x)) / 2);
		auto halfHeight = (pos.y + ((pos.y2 - pos.y)) / 2);
		_text.StrToText(name, halfWidth - ((int)name.size() * Text::letterSize) / 2, halfHeight - 3, 230, 100, 250);
	}

	if (m_console->GetConState() == In_Use)
	{
		m_console->Draw(_gfx, _text);
	}
}

bool ConsoleButton::Update(const Keyboard::Event & _kbdEvent, const char & _curKey, const Mouse::Event & _msEv, const std::pair<int, int>& _msPair, Menu* _menu)
{
	bool returnBool = true;
	if (_menu->GetActive())
	{
		if (CheckMouseIsIn(Get_Pos(), _msEv, _msPair))
		{
			Select();
			if (/*_msEv.GetType() == Mouse::Event::Type::LPress ||*/ _msEv.LeftIsPressed())
			{
				if (m_console->GetConState() == ConsoleState::Idle)
				{
					Vec2 temp(Get_Pos().x2, Get_Pos().y);
					m_console->CalculatePosition(temp, 150, 50);
					m_console->SetConState(In_Use);
					returnBool = false;
				}
			}
		}
		else
		{
			UnSelect();
		}
	}


	switch (m_console->GetConState())
	{
	case Idle:
		break;
	case In_Use:
		m_console->Update(_kbdEvent, _curKey, _msEv, _msPair);
		break;
	case Finished:
		OnClick(_menu);
		m_console->Reset(true);
		break;
	default:
		break;
	}
	return returnBool;
}
