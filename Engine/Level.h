#pragma once

#include <fstream>
#include "Object.h"
#include "Vector2.h"

class Level
{
public:

	Level();
	~Level();

	void DestroyObject(Object& object);
	void SaveLevel(std::string filename);
	void LoadLevel(std::string filename);
private:

};

