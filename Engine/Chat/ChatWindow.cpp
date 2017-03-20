#include "ChatWindow.h"
#include "NapalmUtils.h"
#include "ChatLog.h"
#include "..\Graphics.h"
#include "Client\Client.h"
#include "Text.h"

ChatWindow::ChatWindow(Graphics& _gfx, ChatLog& _log, Client& _client, Vec4 a)
	:
	client(_client),
	gfx(_gfx),
	log(_log),
	topBar(),
	drag()
{
	//-- Initializing variables, etc --\/
	buttonSize = 18;
	inputState = false;
	resizingBox = false;
	movingWindow = false;

	width = a.x2;
	height = a.y2;
	//-------------------------------------------//

	//-- initializing position of chat window --\/
	pos.x = a.x;
	pos.y = a.y;
	pos.x2 = pos.x + width;
	pos.y2 = pos.y + height;
	//------------------------------------------//

	//-- Calculating position of interactive items --\/
	console.CalculatePosition(Vec2(pos.x, pos.y2 - 41), pos.x2 - pos.x - 2, 40);
	topBar.CalculatePos(Vec2(pos.x + 1, pos.y + 1), width - 2, buttonSize - 2);
	drag.CalculatePos(Vec2(pos.x2 - buttonSize, pos.y2 - buttonSize), buttonSize - 1, buttonSize - 1);
	//-------------------------------------------------//
}

void ChatWindow::UpdateChat(	const Keyboard::Event& _kbdEvent, 
								const char& _curKey, 
								const Mouse::Event& _msEvent, 
								const std::pair<int, int>& _mouseCur)
{
	//-- inputState controls whether we are taking input for the ChatLog \/
	console.Update(_kbdEvent, _curKey, _msEvent, _mouseCur);
	if (console.GetConState() == Finished)
	{
		client.HandleInput(console.GetBuffer());
		console.Reset(true);
	}

	//-- When resizing or moving, we must also recalculate the position of the interactive items.	
	//-- Update resizing the chat window --\/
	if (!resizingBox)
	{
		CheckResizing(_msEvent, _mouseCur);
	}
	else
	{
		Resize(_msEvent, _mouseCur);
		console.CalculatePosition(Vec2(pos.x, pos.y2 - 41), pos.x2 - pos.x - 2, 40);
		topBar.CalculatePos(Vec2(pos.x + 1, pos.y + 1), width - 2, buttonSize - 2);
		drag.CalculatePos(Vec2(pos.x2 - buttonSize, pos.y2 - buttonSize), buttonSize - 1, buttonSize - 1);
	}

	//-- Update moving the chat window --\/
	if (!movingWindow)
	{
		CheckMoving(_msEvent, _mouseCur);
	}
	else
	{
		Moving(_msEvent, _mouseCur);
		console.CalculatePosition(Vec2(pos.x, pos.y2 - 41), pos.x2 - pos.x - 2, 40);
		topBar.CalculatePos(Vec2(pos.x + 1, pos.y + 1), width - 2, buttonSize - 2);
		drag.CalculatePos(Vec2(pos.x2 - buttonSize, pos.y2 - buttonSize), buttonSize - 1, buttonSize - 1);
	}	
}

void ChatWindow::CheckResizing(	const Mouse::Event& _msEvent, const std::pair<int, int>& _msPair) 
{
	if (CheckMouseIsIn(drag.Get_Pos(), _msEvent, _msPair))
	{
		drag.Select();
		if (_msEvent.GetType() == Mouse::Event::Type::LPress)
		{
			resizingBox = true;
			mouseLast = _msPair;
		}
	}
	else
	{
		drag.UnSelect();
	}
}

void ChatWindow::Resize(const Mouse::Event& _msEvent, const std::pair<int, int>& _msPair)
{
	width += _msPair.first - mouseLast.first;
	pos.x2 = pos.x + width;
	if (pos.x2 < (pos.x + 50))
		pos.x2 = pos.x + 50;

	height += _msPair.second - mouseLast.second;
	pos.y2 = pos.y + height;
	if (pos.y2 < (pos.y + buttonSize + 40))
		pos.y2 = pos.y + buttonSize + 40;

	mouseLast = _msPair;

	if (_msEvent.GetType() == Mouse::Event::Type::LRelease)
		resizingBox = false;
}

void ChatWindow::CheckMoving(const Mouse::Event& _msEvent, const std::pair<int, int>& _msPair)
{
	if (CheckMouseIsIn(topBar.Get_Pos(), _msEvent, _msPair))
	{
		topBar.Select();
		if (_msEvent.GetType() == Mouse::Event::Type::LPress)
		{
			movingWindow = true;
			mouseLast = _msPair;
		}
	}
	else
	{
		topBar.UnSelect();
	}
}

void ChatWindow::Moving(const Mouse::Event& _msEvent, const std::pair<int, int>& _msPair)
{
	pos.x += _msPair.first - mouseLast.first;
	pos.y += _msPair.second - mouseLast.second;
	pos.x2 = pos.x + width;
	pos.y2 = pos.y + height;

	mouseLast = _msPair;

	if (_msEvent.GetType() == Mouse::Event::Type::LRelease)
		movingWindow = false;
}

void ChatWindow::Draw(Text& _text)
{
	log.DrawLogToWindow(Vec4(pos.x, pos.y, pos.x2, pos.y2 - 20), topBar.Get_Pos(), _text);

	gfx.DrawSquare(pos.x, pos.y, pos.x2, pos.y2, 255, 0, 0);
	topBar.Draw(gfx, _text);

	console.Draw(gfx, _text);
	drag.Draw(gfx, _text);
}