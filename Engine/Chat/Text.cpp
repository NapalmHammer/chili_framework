#include "Text.h"
#include "..\Graphics.h"

Text::Text(Graphics& _gfx)
	:gfx(_gfx)
{
}

void Text::StrToText(std::string str, int x, int y, int r,int g,int b)
{
	for (unsigned int i = 0; i < str.size(); ++i)
	{
		if (str[i] < 97 && str[i] > 64)
			str[i] += 32;

		switch (str[i])
		{
		case 'a':
		{
			chA(x + i * letterSize, y, r, g, b);
			break;				
		}						
		case 'b':				
		{						
			chB(x + i * letterSize, y, r, g, b);
			break;				
		}						
		case 'c':				
		{						
			chC(x + i * letterSize, y, r, g, b);
			break;				
		}						
		case 'd':				
		{						
			chD(x + i * letterSize, y, r, g, b);
			break;				
		}						
		case 'e':				
		{						
			chE(x + i * letterSize, y, r, g, b);
			break;				
		}						
		case 'f':				
		{						
			chF(x + i * letterSize, y, r, g, b);
			break;				
		}						
		case 'g':				
		{						
			chG(x + i * letterSize, y, r, g, b);
			break;				 
		}						 
		case 'h':				 
		{						 
			chH(x + i * letterSize, y, r, g, b);
			break;				 
		}						 
		case 'i':				 
		{						 
			chI(x + i * letterSize, y, r, g, b);
			break;				 
		}						 
		case 'j':				 
		{						 
			chJ(x + i * letterSize, y, r, g, b);
			break;				 
		}						 
		case 'k':				 
		{						 
			chK(x + i * letterSize, y, r, g, b);
			break;				 
		}						 
		case 'l':				 
		{						 
			chL(x + i * letterSize, y, r, g, b);
			break;				 
		}						 
		case 'm':				 
		{						 
			chM(x + i * letterSize, y, r, g, b);
			break;				
		}						
		case 'n':				
		{						
			chN(x + i * letterSize, y, r, g, b);
			break;				 
		}						 
		case 'o':				 
		{						 
			chO(x + i * letterSize, y, r, g, b);
			break;				 
		}						 
		case 'p':				 
		{						 
			chP(x + i * letterSize, y, r, g, b);
			break;
		}
		case 'q':
		{
			chQ(x + i * letterSize, y, r, g, b);
			break;
		}
		case 'r':
		{
			chR(x + i * letterSize, y, r, g, b);
			break;
		}
		case 's':
		{
			chS(x + i * letterSize, y, r, g, b);
			break;
		}
		case 't':
		{
			chT(x + i * letterSize, y, r, g, b);
			break;
		}
		case 'u':
		{
			chU(x + i * letterSize, y, r, g, b);
			break;
		}
		case 'v':
		{
			chV(x + i * letterSize, y, r, g, b);
			break;
		}
		case 'w':
		{
			chW(x + i * letterSize, y, r, g, b);
			break;
		}
		case 'x':
		{
			chX(x + i * letterSize, y, r, g, b);
			break;
		}
		case 'y':
		{
			chY(x + i * letterSize, y, r, g, b);
			break;
		}
		case 'z':
		{
			chZ(x + i * letterSize, y, r, g, b);
			break;
		}
		case ':':
		{
			chCol(x + i * letterSize, y, r, g, b);
			break;
		}
		case ';':
		{
			chSemiCol(x + i * letterSize, y, r, g, b);
			break;
		}
		case '?':
		{
			chQuery(x + i * letterSize, y, r, g, b);
			break;
		}
		case '!':
		{
			chExc(x + i * letterSize, y, r, g, b);
			break;
		}
		case '\'':
		{
			chSiQuo(x + i * letterSize, y, r, g, b);
			break;
		}
		case '\"':
		{
			chDuQuo(x + i * letterSize, y, r, g, b);
			break;
		}
		case ',':
		{
			chComm(x + i * letterSize, y, r, g, b);
			break;
		}
		case '.':
		{
			chPer(x + i * letterSize, y, r, g, b);
			break;
		}
		case '0':
		{
			zero(x + i * letterSize, y, r, g, b);
			break;
		}
		case '1':
		{
			one(x + i * letterSize, y, r, g, b);
			break;
		}
		case '2':
		{
			two(x + i * letterSize, y, r, g, b);
			break;
		}
		case '3':
		{
			three(x + i * letterSize, y, r, g, b);
			break;
		}
		case '4':
		{
			four(x + i * letterSize, y, r, g, b);
			break;
		}
		case '5':
		{
			five(x + i * letterSize, y, r, g, b);
			break;
		}
		case '6':
		{
			six(x + i * letterSize, y, r, g, b);
			break;
		}
		case '7':
		{
			seven(x + i * letterSize, y, r, g, b);
			break;
		}
		case '8':
		{
			eight(x + i * letterSize, y, r, g, b);
			break;
		}
		case '9':
		{
			nine(x + i * letterSize, y, r, g, b);
			break;
		}

		default:
		{
			break;
		}
		}
	}
}
void Text::Block(int x, int y, int r, int g, int b)
{
	for (int xPos = x; xPos <= (x + 1); xPos++)
	{
		for (int yPos = y; yPos <= (y + 1); yPos++)
		{
			gfx.PutPixel(xPos, yPos, r, g, b);
		}
	}
}

//----------------- Small letters

void Text::chA(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x + 2, y, r, g, b);

	gfx.PutPixel(x + 1, y + 1, r, g, b);
	gfx.PutPixel(x + 3, y + 1, r, g, b);

	gfx.PutPixel(x, y + 2, r, g, b);
	gfx.PutPixel(x + 4, y + 2, r, g, b);

	gfx.PutPixel(x, y + 3, r, g, b);
	gfx.PutPixel(x + 1, y + 3, r, g, b);
	gfx.PutPixel(x + 2, y + 3, r, g, b);
	gfx.PutPixel(x + 3, y + 3, r, g, b);
	gfx.PutPixel(x + 4, y + 3, r, g, b);

	gfx.PutPixel(x, y + 4, r, g, b);
	gfx.PutPixel(x + 4, y + 4, r, g, b);

	gfx.PutPixel(x, y + 5, r, g, b);
	gfx.PutPixel(x + 4, y + 5, r, g, b);
}
void Text::chB(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x, y, r, g, b);
	gfx.PutPixel(x + 1, y, r, g, b);
	gfx.PutPixel(x + 2, y, r, g, b);
	gfx.PutPixel(x + 3, y, r, g, b);

	gfx.PutPixel(x, y + 1, r, g, b);
	gfx.PutPixel(x + 4, y + 1, r, g, b);

	gfx.PutPixel(x, y + 2, r, g, b);
	gfx.PutPixel(x + 1, y + 2, r, g, b);
	gfx.PutPixel(x + 2, y + 2, r, g, b);
	gfx.PutPixel(x + 3, y + 2, r, g, b);

	gfx.PutPixel(x, y + 3, r, g, b);
	gfx.PutPixel(x + 4, y + 3, r, g, b);

	gfx.PutPixel(x, y + 4, r, g, b);
	gfx.PutPixel(x + 4, y + 4, r, g, b);

	gfx.PutPixel(x, y + 5, r, g, b);
	gfx.PutPixel(x + 1, y + 5, r, g, b);
	gfx.PutPixel(x + 2, y + 5, r, g, b);
	gfx.PutPixel(x + 3, y + 5, r, g, b);
}
void Text::chC(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x + 1, y, r, g, b);
	gfx.PutPixel(x + 2, y, r, g, b);
	gfx.PutPixel(x + 3, y, r, g, b);

	gfx.PutPixel(x, y + 1, r, g, b);
	gfx.PutPixel(x + 4, y + 1, r, g, b);

	gfx.PutPixel(x, y + 2, r, g, b);

	gfx.PutPixel(x, y + 3, r, g, b);

	gfx.PutPixel(x, y + 4, r, g, b);
	gfx.PutPixel(x + 4, y + 4, r, g, b);

	gfx.PutPixel(x + 1, y + 5, r, g, b);
	gfx.PutPixel(x + 2, y + 5, r, g, b);
	gfx.PutPixel(x + 3, y + 5, r, g, b);
}
void Text::chD(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x, y, r, g, b);
	gfx.PutPixel(x + 1, y, r, g, b);
	gfx.PutPixel(x + 2, y, r, g, b);

	gfx.PutPixel(x, y + 1, r, g, b);
	gfx.PutPixel(x + 3, y + 1, r, g, b);

	gfx.PutPixel(x, y + 2, r, g, b);
	gfx.PutPixel(x + 4, y + 2, r, g, b);

	gfx.PutPixel(x, y + 3, r, g, b);
	gfx.PutPixel(x + 4, y + 3, r, g, b);

	gfx.PutPixel(x, y + 4, r, g, b);
	gfx.PutPixel(x + 3, y + 4, r, g, b);

	gfx.PutPixel(x, y + 5, r, g, b);
	gfx.PutPixel(x + 1, y + 5, r, g, b);
	gfx.PutPixel(x + 2, y + 5, r, g, b);
}
void Text::chE(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x, y, r, g, b);
	gfx.PutPixel(x + 1, y, r, g, b);
	gfx.PutPixel(x + 2, y, r, g, b);
	gfx.PutPixel(x + 3, y, r, g, b);
	gfx.PutPixel(x + 4, y, r, g, b);

	gfx.PutPixel(x, y + 1, r, g, b);

	gfx.PutPixel(x, y + 2, r, g, b);
	gfx.PutPixel(x + 1, y + 2, r, g, b);
	gfx.PutPixel(x + 2, y + 2, r, g, b);

	gfx.PutPixel(x, y + 3, r, g, b);

	gfx.PutPixel(x, y + 4, r, g, b);

	gfx.PutPixel(x, y + 5, r, g, b);
	gfx.PutPixel(x + 1, y + 5, r, g, b);
	gfx.PutPixel(x + 2, y + 5, r, g, b);
	gfx.PutPixel(x + 3, y + 5, r, g, b);
	gfx.PutPixel(x + 4, y + 5, r, g, b);
}
void Text::chF(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x, y, r, g, b);
	gfx.PutPixel(x + 1, y, r, g, b);
	gfx.PutPixel(x + 2, y, r, g, b);
	gfx.PutPixel(x + 3, y, r, g, b);
	gfx.PutPixel(x + 4, y, r, g, b);

	gfx.PutPixel(x, y + 1, r, g, b);

	gfx.PutPixel(x, y + 2, r, g, b);
	gfx.PutPixel(x + 1, y + 2, r, g, b);
	gfx.PutPixel(x + 2, y + 2, r, g, b);

	gfx.PutPixel(x, y + 3, r, g, b);

	gfx.PutPixel(x, y + 4, r, g, b);

	gfx.PutPixel(x, y + 5, r, g, b);
}
void Text::chG(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x + 1, y, r, g, b);
	gfx.PutPixel(x + 2, y, r, g, b);
	gfx.PutPixel(x + 3, y, r, g, b);

	gfx.PutPixel(x, y + 1, r, g, b);
	gfx.PutPixel(x + 4, y + 1, r, g, b);

	gfx.PutPixel(x, y + 2, r, g, b);

	gfx.PutPixel(x, y + 3, r, g, b);
	gfx.PutPixel(x + 2, y + 3, r, g, b);
	gfx.PutPixel(x + 3, y + 3, r, g, b);
	gfx.PutPixel(x + 4, y + 3, r, g, b);

	gfx.PutPixel(x, y + 4, r, g, b);
	gfx.PutPixel(x + 4, y + 4, r, g, b);

	gfx.PutPixel(x + 1, y + 5, r, g, b);
	gfx.PutPixel(x + 2, y + 5, r, g, b);
	gfx.PutPixel(x + 3, y + 5, r, g, b);
}
void Text::chH(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x, y, r, g, b);
	gfx.PutPixel(x + 4, y, r, g, b);

	gfx.PutPixel(x, y + 1, r, g, b);
	gfx.PutPixel(x + 4, y + 1, r, g, b);

	gfx.PutPixel(x, y + 2, r, g, b);
	gfx.PutPixel(x + 1, y + 2, r, g, b);
	gfx.PutPixel(x + 2, y + 2, r, g, b);
	gfx.PutPixel(x + 3, y + 2, r, g, b);
	gfx.PutPixel(x + 4, y + 2, r, g, b);

	gfx.PutPixel(x, y + 3, r, g, b);
	gfx.PutPixel(x + 4, y + 3, r, g, b);

	gfx.PutPixel(x, y + 4, r, g, b);
	gfx.PutPixel(x + 4, y + 4, r, g, b);

	gfx.PutPixel(x, y + 5, r, g, b);
	gfx.PutPixel(x + 4, y + 5, r, g, b);
}
void Text::chI(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x, y, r, g, b);
	gfx.PutPixel(x + 1, y, r, g, b);
	gfx.PutPixel(x + 2, y, r, g, b);
	gfx.PutPixel(x + 3, y, r, g, b);
	gfx.PutPixel(x + 4, y, r, g, b);

	gfx.PutPixel(x + 2, y + 1, r, g, b);

	gfx.PutPixel(x + 2, y + 2, r, g, b);

	gfx.PutPixel(x + 2, y + 3, r, g, b);

	gfx.PutPixel(x + 2, y + 4, r, g, b);

	gfx.PutPixel(x, y + 5, r, g, b);
	gfx.PutPixel(x + 1, y + 5, r, g, b);
	gfx.PutPixel(x + 2, y + 5, r, g, b);
	gfx.PutPixel(x + 3, y + 5, r, g, b);
	gfx.PutPixel(x + 4, y + 5, r, g, b);
}
void Text::chJ(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x, y, r, g, b);
	gfx.PutPixel(x + 1, y, r, g, b);
	gfx.PutPixel(x + 2, y, r, g, b);
	gfx.PutPixel(x + 3, y, r, g, b);
	gfx.PutPixel(x + 4, y, r, g, b);

	gfx.PutPixel(x + 2, y + 1, r, g, b);

	gfx.PutPixel(x + 2, y + 2, r, g, b);

	gfx.PutPixel(x + 2, y + 3, r, g, b);

	gfx.PutPixel(x, y + 4, r, g, b);
	gfx.PutPixel(x + 2, y + 4, r, g, b);

	gfx.PutPixel(x + 1, y + 5, r, g, b);
	gfx.PutPixel(x + 2, y + 5, r, g, b);
}
void Text::chK(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x, y, r, g, b);
	gfx.PutPixel(x + 4, y, r, g, b);

	gfx.PutPixel(x, y + 1, r, g, b);
	gfx.PutPixel(x + 3, y + 1, r, g, b);

	gfx.PutPixel(x, y + 2, r, g, b);
	gfx.PutPixel(x + 1, y + 2, r, g, b);
	gfx.PutPixel(x + 2, y + 2, r, g, b);

	gfx.PutPixel(x, y + 3, r, g, b);
	gfx.PutPixel(x + 2, y + 3, r, g, b);

	gfx.PutPixel(x, y + 4, r, g, b);
	gfx.PutPixel(x + 3, y + 4, r, g, b);

	gfx.PutPixel(x, y + 5, r, g, b);
	gfx.PutPixel(x + 4, y + 5, r, g, b);
}
void Text::chL(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x, y, r, g, b);

	gfx.PutPixel(x, y + 1, r, g, b);

	gfx.PutPixel(x, y + 2, r, g, b);

	gfx.PutPixel(x, y + 3, r, g, b);

	gfx.PutPixel(x, y + 4, r, g, b);

	gfx.PutPixel(x, y + 5, r, g, b);
	gfx.PutPixel(x + 1, y + 5, r, g, b);
	gfx.PutPixel(x + 2, y + 5, r, g, b);
	gfx.PutPixel(x + 3, y + 5, r, g, b);
	gfx.PutPixel(x + 4, y + 5, r, g, b);
}
void Text::chM(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x, y, r, g, b);
	gfx.PutPixel(x + 4, y, r, g, b);

	gfx.PutPixel(x, y + 1, r, g, b);
	gfx.PutPixel(x + 1, y + 1, r, g, b);
	gfx.PutPixel(x + 3, y + 1, r, g, b);
	gfx.PutPixel(x + 4, y + 1, r, g, b);

	gfx.PutPixel(x, y + 2, r, g, b);
	gfx.PutPixel(x + 2, y + 2, r, g, b);
	gfx.PutPixel(x + 4, y + 2, r, g, b);

	gfx.PutPixel(x, y + 3, r, g, b);
	gfx.PutPixel(x + 2, y + 3, r, g, b);
	gfx.PutPixel(x + 4, y + 3, r, g, b);

	gfx.PutPixel(x, y + 4, r, g, b);
	gfx.PutPixel(x + 4, y + 4, r, g, b);

	gfx.PutPixel(x, y + 5, r, g, b);
	gfx.PutPixel(x + 4, y + 5, r, g, b);
}
void Text::chN(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x, y, r, g, b);
	gfx.PutPixel(x + 4, y, r, g, b);

	gfx.PutPixel(x, y + 1, r, g, b);
	gfx.PutPixel(x + 1, y + 1, r, g, b);
	gfx.PutPixel(x + 4, y + 1, r, g, b);

	gfx.PutPixel(x, y + 2, r, g, b);
	gfx.PutPixel(x + 2, y + 2, r, g, b);
	gfx.PutPixel(x + 4, y + 2, r, g, b);

	gfx.PutPixel(x, y + 3, r, g, b);
	gfx.PutPixel(x + 3, y + 3, r, g, b);
	gfx.PutPixel(x + 4, y + 3, r, g, b);

	gfx.PutPixel(x, y + 4, r, g, b);
	gfx.PutPixel(x + 4, y + 4, r, g, b);

	gfx.PutPixel(x, y + 5, r, g, b);
	gfx.PutPixel(x + 4, y + 5, r, g, b);
}
void Text::chO(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x + 1, y, r, g, b);
	gfx.PutPixel(x + 2, y, r, g, b);
	gfx.PutPixel(x + 3, y, r, g, b);

	gfx.PutPixel(x, y + 1, r, g, b);
	gfx.PutPixel(x + 4, y + 1, r, g, b);

	gfx.PutPixel(x, y + 2, r, g, b);
	gfx.PutPixel(x + 4, y + 2, r, g, b);

	gfx.PutPixel(x, y + 3, r, g, b);
	gfx.PutPixel(x + 4, y + 3, r, g, b);

	gfx.PutPixel(x, y + 4, r, g, b);
	gfx.PutPixel(x + 4, y + 4, r, g, b);

	gfx.PutPixel(x + 1, y + 5, r, g, b);
	gfx.PutPixel(x + 2, y + 5, r, g, b);
	gfx.PutPixel(x + 3, y + 5, r, g, b);
}
void Text::chP(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x, y, r, g, b);
	gfx.PutPixel(x + 1, y, r, g, b);
	gfx.PutPixel(x + 2, y, r, g, b);
	gfx.PutPixel(x + 3, y, r, g, b);

	gfx.PutPixel(x, y + 1, r, g, b);
	gfx.PutPixel(x + 4, y + 1, r, g, b);

	gfx.PutPixel(x, y + 2, r, g, b);
	gfx.PutPixel(x + 1, y + 2, r, g, b);
	gfx.PutPixel(x + 2, y + 2, r, g, b);
	gfx.PutPixel(x + 3, y + 2, r, g, b);

	gfx.PutPixel(x, y + 3, r, g, b);

	gfx.PutPixel(x, y + 4, r, g, b);

	gfx.PutPixel(x, y + 5, r, g, b);
}
void Text::chQ(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x + 1, y, r, g, b);
	gfx.PutPixel(x + 2, y, r, g, b);
	gfx.PutPixel(x + 3, y, r, g, b);

	gfx.PutPixel(x, y + 1, r, g, b);
	gfx.PutPixel(x + 4, y + 1, r, g, b);

	gfx.PutPixel(x, y + 2, r, g, b);
	gfx.PutPixel(x + 4, y + 2, r, g, b);

	gfx.PutPixel(x, y + 3, r, g, b);
	gfx.PutPixel(x + 2, y + 3, r, g, b);
	gfx.PutPixel(x + 4, y + 3, r, g, b);

	gfx.PutPixel(x, y + 4, r, g, b);
	gfx.PutPixel(x + 3, y + 4, r, g, b);

	gfx.PutPixel(x + 1, y + 5, r, g, b);
	gfx.PutPixel(x + 2, y + 5, r, g, b);
	gfx.PutPixel(x + 4, y + 5, r, g, b);
}
void Text::chR(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x, y, r, g, b);
	gfx.PutPixel(x + 1, y, r, g, b);
	gfx.PutPixel(x + 2, y, r, g, b);
	gfx.PutPixel(x + 3, y, r, g, b);

	gfx.PutPixel(x, y + 1, r, g, b);
	gfx.PutPixel(x + 4, y + 1, r, g, b);

	gfx.PutPixel(x, y + 2, r, g, b);
	gfx.PutPixel(x + 1, y + 2, r, g, b);
	gfx.PutPixel(x + 2, y + 2, r, g, b);
	gfx.PutPixel(x + 3, y + 2, r, g, b);

	gfx.PutPixel(x, y + 3, r, g, b);
	gfx.PutPixel(x + 4, y + 3, r, g, b);

	gfx.PutPixel(x, y + 4, r, g, b);
	gfx.PutPixel(x + 4, y + 4, r, g, b);

	gfx.PutPixel(x, y + 5, r, g, b);
	gfx.PutPixel(x + 4, y + 5, r, g, b);
}
void Text::chS(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x + 1, y, r, g, b);
	gfx.PutPixel(x + 2, y, r, g, b);
	gfx.PutPixel(x + 3, y, r, g, b);
	gfx.PutPixel(x + 4, y, r, g, b);

	gfx.PutPixel(x, y + 1, r, g, b);

	gfx.PutPixel(x + 1, y + 2, r, g, b);
	gfx.PutPixel(x + 2, y + 2, r, g, b);
	gfx.PutPixel(x + 3, y + 2, r, g, b);

	gfx.PutPixel(x + 4, y + 3, r, g, b);

	gfx.PutPixel(x + 4, y + 4, r, g, b);

	gfx.PutPixel(x, y + 5, r, g, b);
	gfx.PutPixel(x + 1, y + 5, r, g, b);
	gfx.PutPixel(x + 2, y + 5, r, g, b);
	gfx.PutPixel(x + 3, y + 5, r, g, b);
}
void Text::chT(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x, y, r, g, b);
	gfx.PutPixel(x + 1, y, r, g, b);
	gfx.PutPixel(x + 2, y, r, g, b);
	gfx.PutPixel(x + 3, y, r, g, b);
	gfx.PutPixel(x + 4, y, r, g, b);

	gfx.PutPixel(x + 2, y + 1, r, g, b);

	gfx.PutPixel(x + 2, y + 2, r, g, b);

	gfx.PutPixel(x + 2, y + 3, r, g, b);

	gfx.PutPixel(x + 2, y + 4, r, g, b);

	gfx.PutPixel(x + 2, y + 5, r, g, b);
}
void Text::chU(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x, y, r, g, b);
	gfx.PutPixel(x + 4, y, r, g, b);

	gfx.PutPixel(x, y + 1, r, g, b);
	gfx.PutPixel(x + 4, y + 1, r, g, b);

	gfx.PutPixel(x, y + 2, r, g, b);
	gfx.PutPixel(x + 4, y + 2, r, g, b);

	gfx.PutPixel(x, y + 3, r, g, b);
	gfx.PutPixel(x + 4, y + 3, r, g, b);

	gfx.PutPixel(x, y + 4, r, g, b);
	gfx.PutPixel(x + 4, y + 4, r, g, b);

	gfx.PutPixel(x + 1, y + 5, r, g, b);
	gfx.PutPixel(x + 2, y + 5, r, g, b);
	gfx.PutPixel(x + 3, y + 5, r, g, b);
}
void Text::chV(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x, y, r, g, b);
	gfx.PutPixel(x + 4, y, r, g, b);

	gfx.PutPixel(x, y + 1, r, g, b);
	gfx.PutPixel(x + 4, y + 1, r, g, b);

	gfx.PutPixel(x, y + 2, r, g, b);
	gfx.PutPixel(x + 4, y + 2, r, g, b);

	gfx.PutPixel(x + 1, y + 3, r, g, b);
	gfx.PutPixel(x + 3, y + 3, r, g, b);

	gfx.PutPixel(x + 1, y + 4, r, g, b);
	gfx.PutPixel(x + 3, y + 4, r, g, b);

	gfx.PutPixel(x + 2, y + 5, r, g, b);
}
void Text::chW(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x, y, r, g, b);
	gfx.PutPixel(x + 4, y, r, g, b);

	gfx.PutPixel(x, y + 1, r, g, b);
	gfx.PutPixel(x + 4, y + 1, r, g, b);

	gfx.PutPixel(x, y + 2, r, g, b);
	gfx.PutPixel(x + 4, y + 2, r, g, b);

	gfx.PutPixel(x, y + 3, r, g, b);
	gfx.PutPixel(x + 2, y + 3, r, g, b);
	gfx.PutPixel(x + 4, y + 3, r, g, b);

	gfx.PutPixel(x, y + 4, r, g, b);
	gfx.PutPixel(x + 2, y + 4, r, g, b);
	gfx.PutPixel(x + 4, y + 4, r, g, b);

	gfx.PutPixel(x + 1, y + 5, r, g, b);
	gfx.PutPixel(x + 3, y + 5, r, g, b);
}
void Text::chX(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x, y, r, g, b);
	gfx.PutPixel(x + 4, y, r, g, b);

	gfx.PutPixel(x + 1, y + 1, r, g, b);
	gfx.PutPixel(x + 3, y + 1, r, g, b);

	gfx.PutPixel(x + 2, y + 2, r, g, b);

	gfx.PutPixel(x + 2, y + 3, r, g, b);

	gfx.PutPixel(x + 1, y + 4, r, g, b);
	gfx.PutPixel(x + 3, y + 4, r, g, b);

	gfx.PutPixel(x, y + 5, r, g, b);
	gfx.PutPixel(x + 4, y + 5, r, g, b);
}
void Text::chY(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x, y, r, g, b);
	gfx.PutPixel(x + 4, y, r, g, b);

	gfx.PutPixel(x, y + 1, r, g, b);
	gfx.PutPixel(x + 4, y + 1, r, g, b);

	gfx.PutPixel(x + 1, y + 2, r, g, b);
	gfx.PutPixel(x + 3, y + 2, r, g, b);

	gfx.PutPixel(x + 2, y + 3, r, g, b);

	gfx.PutPixel(x + 2, y + 4, r, g, b);

	gfx.PutPixel(x + 2, y + 5, r, g, b);
}
void Text::chZ(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x, y, r, g, b);
	gfx.PutPixel(x + 1, y, r, g, b);
	gfx.PutPixel(x + 2, y, r, g, b);
	gfx.PutPixel(x + 3, y, r, g, b);
	gfx.PutPixel(x + 4, y, r, g, b);

	gfx.PutPixel(x + 4, y + 1, r, g, b);

	gfx.PutPixel(x + 3, y + 2, r, g, b);

	gfx.PutPixel(x + 2, y + 3, r, g, b);

	gfx.PutPixel(x + 1, y + 4, r, g, b);

	gfx.PutPixel(x, y + 5, r, g, b);
	gfx.PutPixel(x + 1, y + 5, r, g, b);
	gfx.PutPixel(x + 2, y + 5, r, g, b);
	gfx.PutPixel(x + 3, y + 5, r, g, b);
	gfx.PutPixel(x + 4, y + 5, r, g, b);
}

void Text::chCol(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x + 2, y + 1, r, g, b);
	gfx.PutPixel(x + 2, y + 4, r, g, b);
}

void Text::chSemiCol(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x + 2, y + 1, r, g, b);
	gfx.PutPixel(x + 2, y + 4, r, g, b);
	gfx.PutPixel(x + 1, y + 5, r, g, b);
}
void Text::chQuery(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x, y + 1, r, g, b);
	gfx.PutPixel(x + 1, y, r, g, b);
	gfx.PutPixel(x + 2, y, r, g, b);
	gfx.PutPixel(x + 3, y, r, g, b);
	gfx.PutPixel(x + 4, y + 1, r, g, b);
	gfx.PutPixel(x + 3, y + 2, r, g, b);
	gfx.PutPixel(x + 2, y + 3, r, g, b);

	gfx.PutPixel(x + 2, y + 5, r, g, b);
}
void Text::chExc(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x + 2, y, r, g, b);
	gfx.PutPixel(x + 2, y + 1, r, g, b);
	gfx.PutPixel(x + 2, y + 2, r, g, b);
	gfx.PutPixel(x + 2, y + 3, r, g, b);

	gfx.PutPixel(x + 2, y + 5, r, g, b);
}
void Text::chSiQuo(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x + 2, y, r, g, b);
	gfx.PutPixel(x + 2, y + 1, r, g, b);
}
void Text::chDuQuo(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x + 1, y, r, g, b);
	gfx.PutPixel(x + 1, y + 1, r, g, b);

	gfx.PutPixel(x + 3, y, r, g, b);
	gfx.PutPixel(x + 3, y + 1, r, g, b);
}
void Text::chComm(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x + 2, y + 4, r, g, b);
	gfx.PutPixel(x + 1, y + 5, r, g, b);
}
void Text::chPer(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x + 2, y + 5, r, g, b);
}

void Text::zero(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x + 2, y, r, g, b);
	gfx.PutPixel(x + 3, y, r, g, b);
	gfx.PutPixel(x + 1, y + 1, r, g, b);
	gfx.PutPixel(x + 4, y + 1, r, g, b);
	gfx.PutPixel(x + 1, y + 2, r, g, b);
	gfx.PutPixel(x + 4, y + 2, r, g, b);
	gfx.PutPixel(x + 1, y + 3, r, g, b);
	gfx.PutPixel(x + 4, y + 3, r, g, b);
	gfx.PutPixel(x + 1, y + 4, r, g, b);
	gfx.PutPixel(x + 4, y + 4, r, g, b);
	gfx.PutPixel(x + 2, y + 5, r, g, b);
	gfx.PutPixel(x + 3, y+ 5, r, g, b);
}

void Text::one(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x + 2, y, r, g, b);
	gfx.PutPixel(x + 3, y, r, g, b);
	gfx.PutPixel(x + 1, y + 1, r, g, b);

	gfx.PutPixel(x + 2, y + 1, r, g, b);
	gfx.PutPixel(x + 3, y + 1, r, g, b);
	gfx.PutPixel(x + 2, y + 2, r, g, b);
	gfx.PutPixel(x + 3, y + 2, r, g, b);
	gfx.PutPixel(x + 2, y + 3, r, g, b);
	gfx.PutPixel(x + 3, y + 3, r, g, b);
	gfx.PutPixel(x + 2, y + 4, r, g, b);
	gfx.PutPixel(x + 3, y + 4, r, g, b);

	gfx.PutPixel(x + 1, y +5, r, g, b);
	gfx.PutPixel(x + 2, y +5, r, g, b);
	gfx.PutPixel(x + 3, y +5, r, g, b);
	gfx.PutPixel(x + 4, y +5, r, g, b);
}

void Text::two(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x + 2, y, r, g, b);
	gfx.PutPixel(x + 3, y, r, g, b);
	gfx.PutPixel(x + 1, y + 1, r, g, b);
	gfx.PutPixel(x + 4, y + 1, r, g, b);
	gfx.PutPixel(x + 4, y + 2, r, g, b);
	gfx.PutPixel(x + 3, y + 3, r, g, b);
	gfx.PutPixel(x + 2, y + 4, r, g, b);

	gfx.PutPixel(x + 1, y + 5, r, g, b);
	gfx.PutPixel(x + 2, y + 5, r, g, b);
	gfx.PutPixel(x + 3, y + 5, r, g, b);
	gfx.PutPixel(x + 4, y + 5, r, g, b);

}

void Text::three(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x + 2, y, r, g, b);
	gfx.PutPixel(x + 3, y, r, g, b);
	gfx.PutPixel(x + 1, y, r, g, b);
	gfx.PutPixel(x + 4, y + 1, r, g, b);

	gfx.PutPixel(x + 4, y + 2, r, g, b);
	gfx.PutPixel(x + 3, y + 2, r, g, b);
	gfx.PutPixel(x + 2, y + 2, r, g, b);


	gfx.PutPixel(x + 4, y + 3, r, g, b);
	gfx.PutPixel(x + 4, y + 4, r, g, b);
	gfx.PutPixel(x + 1, y + 5, r, g, b);
	gfx.PutPixel(x + 2, y + 5, r, g, b);
	gfx.PutPixel(x + 3, y + 5, r, g, b);

}

void Text::four(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x + 4, y, r, g, b);

	gfx.PutPixel(x + 4, y + 1, r, g, b);
	gfx.PutPixel(x + 3, y + 1, r, g, b);

	gfx.PutPixel(x + 4, y + 2, r, g, b);
	gfx.PutPixel(x + 2, y + 2, r, g, b);

	gfx.PutPixel(x + 5, y + 3, r, g, b);
	gfx.PutPixel(x + 4, y + 3, r, g, b);
	gfx.PutPixel(x + 3, y + 3, r, g, b);
	gfx.PutPixel(x + 2, y + 3, r, g, b);
	gfx.PutPixel(x + 1, y + 3, r, g, b);

	gfx.PutPixel(x + 4, y + 4, r, g, b);
	gfx.PutPixel(x + 4, y + 5, r, g, b);
}

void Text::five(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x + 1, y, r, g, b);
	gfx.PutPixel(x + 2, y, r, g, b);
	gfx.PutPixel(x + 3, y, r, g, b);
	gfx.PutPixel(x + 4, y, r, g, b);

	gfx.PutPixel(x + 1, y + 1, r, g, b);
	gfx.PutPixel(x + 1, y + 2, r, g, b);
	gfx.PutPixel(x + 2, y + 2, r, g, b);
	gfx.PutPixel(x + 3, y + 2, r, g, b);

	gfx.PutPixel(x + 4, y + 3, r, g, b);
	gfx.PutPixel(x + 4, y + 4, r, g, b);

	gfx.PutPixel(x + 1, y + 5, r, g, b);
	gfx.PutPixel(x + 2, y + 5, r, g, b);
	gfx.PutPixel(x + 3, y + 5, r, g, b);
}

void Text::six(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x + 4, y, r, g, b);
	gfx.PutPixel(x + 3, y, r, g, b);
	gfx.PutPixel(x + 2, y + 1, r, g, b);
	gfx.PutPixel(x + 1, y + 2, r, g, b);
	gfx.PutPixel(x + 2, y + 2, r, g, b);
	gfx.PutPixel(x + 3, y + 2, r, g, b);

	gfx.PutPixel(x + 1, y + 3, r, g, b);
	gfx.PutPixel(x + 4, y + 3, r, g, b);
	gfx.PutPixel(x + 1, y + 4, r, g, b);
	gfx.PutPixel(x + 4, y + 4, r, g, b);

	gfx.PutPixel(x + 2, y + 5, r, g, b);
	gfx.PutPixel(x + 3, y + 5, r, g, b);
}

void Text::seven(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x + 1, y, r, g, b);
	gfx.PutPixel(x + 2, y, r, g, b);
	gfx.PutPixel(x + 3, y, r, g, b);
	gfx.PutPixel(x + 4, y, r, g, b);

	gfx.PutPixel(x + 3, y + 1, r, g, b);
	gfx.PutPixel(x + 3, y + 2, r, g, b);

	gfx.PutPixel(x + 2, y + 3, r, g, b);
	gfx.PutPixel(x + 2, y + 4, r, g, b);
	gfx.PutPixel(x + 2, y + 5, r, g, b);
	
}

void Text::eight(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x + 2, y, r, g, b);
	gfx.PutPixel(x + 3, y, r, g, b);

	gfx.PutPixel(x + 1, y + 1, r, g, b);
	gfx.PutPixel(x + 4, y + 1, r, g, b);
	gfx.PutPixel(x + 2, y + 2, r, g, b);
	gfx.PutPixel(x + 3, y + 2, r, g, b);

	gfx.PutPixel(x + 1, y + 3, r, g, b);
	gfx.PutPixel(x + 4, y + 3, r, g, b);
	gfx.PutPixel(x + 1, y + 4, r, g, b);
	gfx.PutPixel(x + 4, y + 4, r, g, b);

	gfx.PutPixel(x + 2, y + 5, r, g, b);
	gfx.PutPixel(x + 3, y + 5, r, g, b);
}

void Text::nine(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x + 2, y, r, g, b);
	gfx.PutPixel(x + 3, y, r, g, b);

	gfx.PutPixel(x + 1, y + 1, r, g, b);
	gfx.PutPixel(x + 4, y + 1, r, g, b);
	gfx.PutPixel(x + 1, y + 2, r, g, b);
	gfx.PutPixel(x + 4, y + 2, r, g, b);
	gfx.PutPixel(x + 2, y + 3, r, g, b);
	gfx.PutPixel(x + 3, y + 3, r, g, b);

	gfx.PutPixel(x + 4, y + 3, r, g, b);
	gfx.PutPixel(x + 4, y + 4, r, g, b);
	gfx.PutPixel(x + 1, y + 5, r, g, b);
	gfx.PutPixel(x + 2, y + 5, r, g, b);
	gfx.PutPixel(x + 3, y + 5, r, g, b);	
}
