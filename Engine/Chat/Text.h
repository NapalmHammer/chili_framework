#pragma once
#include <string>
//#include "../Graphics.h"
class Graphics;

class Text
{
public:
	Text(Graphics& _gfx);
	void StrToText(std::string str, int x, int y, int r, int g, int b);
	static constexpr int letterSize = 6;
private:
	void Block(int x, int y, int r, int g, int b);
	void chA(int x, int y, int r, int g, int b);
	void chB(int x, int y, int r, int g, int b);
	void chC(int x, int y, int r, int g, int b);
	void chD(int x, int y, int r, int g, int b);
	void chE(int x, int y, int r, int g, int b);
	void chF(int x, int y, int r, int g, int b);
	void chG(int x, int y, int r, int g, int b);
	void chH(int x, int y, int r, int g, int b);
	void chI(int x, int y, int r, int g, int b);
	void chJ(int x, int y, int r, int g, int b);
	void chK(int x, int y, int r, int g, int b);
	void chL(int x, int y, int r, int g, int b);
	void chM(int x, int y, int r, int g, int b);
	void chN(int x, int y, int r, int g, int b);
	void chO(int x, int y, int r, int g, int b);
	void chP(int x, int y, int r, int g, int b);
	void chQ(int x, int y, int r, int g, int b);
	void chR(int x, int y, int r, int g, int b);
	void chS(int x, int y, int r, int g, int b);
	void chT(int x, int y, int r, int g, int b);
	void chU(int x, int y, int r, int g, int b);
	void chV(int x, int y, int r, int g, int b);
	void chW(int x, int y, int r, int g, int b);
	void chX(int x, int y, int r, int g, int b);
	void chY(int x, int y, int r, int g, int b);
	void chZ(int x, int y, int r, int g, int b);
	void chCol(int x, int y, int r, int g, int b);
	void chSemiCol(int x, int y, int r, int g, int b);
	void chQuery(int x, int y, int r, int g, int b);
	void chExc(int x, int y, int r, int g, int b);
	void chSiQuo(int x, int y, int r, int g, int b);
	void chDuQuo(int x, int y, int r, int g, int b);
	void chComm(int x, int y, int r, int g, int b);
	void chPer(int x, int y, int r, int g, int b);
	void zero(int x, int y, int r, int g, int b);
	void one(int x, int y, int r, int g, int b);
	void two(int x, int y, int r, int g, int b);
	void three(int x, int y, int r, int g, int b);
	void four(int x, int y, int r, int g, int b);
	void five(int x, int y, int r, int g, int b);
	void six(int x, int y, int r, int g, int b);
	void seven(int x, int y, int r, int g, int b);
	void eight(int x, int y, int r, int g, int b);
	void nine(int x, int y, int r, int g, int b);
	Graphics& gfx;
};
