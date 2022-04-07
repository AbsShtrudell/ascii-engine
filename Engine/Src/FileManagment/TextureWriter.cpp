#include "TextureWriter.h"

void TextureWriter::WriteFile(std::string path, Texture* texture)
{
	std::wofstream file;
	file.open(path, std::ios::out);

	if (file.is_open())
	{
		if (texture != NULL)
		{
			file << texture->getSize().x << ' ' << texture->getSize().y << ' ';

			
			for (int i = 0; i < texture->getSize().x; i++)
			{
				for (int j = 0; j < texture->getSize().y; j++)
				{
					file << (int)texture->at(i, j).symbol << ' ';
					file << texture->at(i, j).color << ' ';
				}
			}
		}
	}
	else throw(std::exception("Warning! Can't load file"));//написать свои исключения
}
