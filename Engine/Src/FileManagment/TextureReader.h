#pragma once
#include <fstream>
#include "../Matrix.h"

class TextureReader
{
public:
	TextureReader() {}
	~TextureReader(){}

	static void ReadFile(std::string path, Texture*& texture );
};

