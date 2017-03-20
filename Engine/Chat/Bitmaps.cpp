#include "Bitmaps.h"
#include "Vec2.h"

void Bitmap::Load(const char * _fileName)
{
	m_infileStream.open(_fileName, std::ios::binary | std::ios::beg);
	m_infileStream.seekg(0);

	if (m_infileStream) 
	{
		char signature[2];
		m_infileStream.read(signature, sizeof(char) * 2);
		m_infileStream.read((char*)&bmFileHeader, sizeof(BitmapFileHeader));
		m_infileStream.read((char*)&bmInfoHeader, sizeof(BitmapInfoHeader));
		m_infileStream.seekg(bmFileHeader.m_offsetToPixelData);

		int nPixels = bmInfoHeader.m_width * bmInfoHeader.m_height;
		m_surface.resize(nPixels);
		int nPaddingBytesPerRow = 4 - ((bmInfoHeader.m_width * 3) % 4);
		for (int y = 0; y < bmInfoHeader.m_height; y++)
		{
			for (int x = 0; x < bmInfoHeader.m_width; x++)
			{
				Pixel24 pixel;
				m_infileStream.read((char*)&pixel, sizeof(Pixel24));
				m_surface[x + ((bmInfoHeader.m_height - 1) - y) * bmInfoHeader.m_width] = Colors::MakeRGB(pixel.red, pixel.green, pixel.blue);
			}
			m_infileStream.seekg(nPaddingBytesPerRow, std::ios::cur);
		}
	}
	m_infileStream.close();
}

void Bitmap::Draw(Graphics & _gfx, Vec2 _pos, Color _key)
{
	for (auto y = 0; y < bmInfoHeader.m_height; y++)
	{
		for (auto x = 0; x < bmInfoHeader.m_width; x++)
		{
			Color c = m_surface[x + y * bmInfoHeader.m_width];
			if (c.dword != _key.dword)
			{
				_gfx.PutPixel(_pos.x + x, _pos.y + y, m_surface[x + y * bmInfoHeader.m_width]);
			}
		}
	}
}
