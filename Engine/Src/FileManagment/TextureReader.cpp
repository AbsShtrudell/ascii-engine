#include "TextureReader.h"

void TextureReader::ReadFile(std::string path, Texture*& texture)
{
	std::wifstream file;
	file.open(path);

	Vec2 sz;
	int symb;
	if (file.is_open())
	{
		file >> sz.x >> sz.y;

		if (texture == NULL)
		{
			Texture* buff = new Texture(sz, { L' ', 7 });
			texture = buff;
			buff = NULL;
		}
		else
		{
			delete texture;
			texture = new Texture(sz, { L' ', 7 });
		}

		for (int i = 0; i < texture->getSize().x; i++)
		{
			for (int j = 0; j < texture->getSize().y; j++)
			{
				file >> symb;
				texture->at(i, j).symbol = (wchar_t)symb;
				file >> texture->at(i, j).color;
			}
		}
	}
	else throw(std::exception("Warning! Can't load file"));
}
