#pragma once
#include <fstream>
#include "../Matrix.h"

class TextureWriter
{
public:
	TextureWriter() {}
	~TextureWriter(){}

	static void WriteFile(std::string path, Texture* texture);
};

