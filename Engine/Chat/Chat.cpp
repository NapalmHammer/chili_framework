#include "Chat.h"
#include "../Graphics.h"

Chat::Chat(Graphics& _gfx, Keyboard& _kbd, Mouse& _ms)
	:
	gfx(_gfx),
	kbd(_kbd),
	mouse(_ms),
	text(_gfx),
	chatLog(100, _gfx),
	client("n", 80, chatLog),
	mainMenu(_gfx, client, 100, 30),
	chatWindow(_gfx, chatLog, client, Vec4(50, 300, 700, 250))
{
}

void Chat::UpdateChat()
{
	//-- Read keyboard and mouse events --\/
	kbdEvent = kbd.ReadKey();
	curChar = kbd.ReadChar();

	mouseEvent = mouse.Read();
	mouseCur = mouse.GetPos();
	//------------------------------------//

	//-- update objects with readings --\/
	client.Update();
	mainMenu.Update(kbdEvent, curChar, mouseEvent, mouseCur);
	chatWindow.UpdateChat(kbdEvent, curChar, mouseEvent, mouseCur);
	//-------------------------------//
}

void Chat::DrawChat()
{
	chatWindow.Draw(text);
	mainMenu.Draw(gfx, chatLog, text);
}
