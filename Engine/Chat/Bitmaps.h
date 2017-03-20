#pragma once
#include <fstream>
#include <vector>
#include "../Graphics.h"

class Vec2;

struct BitmapFileHeader
{
	unsigned int m_fileSize;
	unsigned short m_reserved1, m_reserved2;
	unsigned int m_offsetToPixelData;
};
struct BitmapInfoHeader
{
	unsigned int m_headerSize;
	int m_width, m_height;
	unsigned short m_planes;
	unsigned short m_bits;
	unsigned int m_compression;
	unsigned int m_imageSize;
	int m_xResolution, m_yResolution;
	unsigned int m_nColors;
	unsigned int m_importantColors;
};

struct Pixel24
{
	unsigned char blue;
	unsigned char green;
	unsigned char red;
};

class Bitmap
{
public:
	Bitmap() {};
	void Load(const char* _fileName);
	void Draw(Graphics& _gfx, Vec2 _pos, Color _key);
	std::ifstream m_infileStream;
	BitmapFileHeader bmFileHeader;
	BitmapInfoHeader bmInfoHeader;
	std::vector<Color> m_surface;
	std::vector<char> buffer;
};