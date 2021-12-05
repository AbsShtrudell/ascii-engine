#include "Level.h"

Level::Level()
{
	
}

Level::~Level()
{

}

void Level::DestroyObject(Object& object)
{
	object.~Object();
}

void Level::SaveLevel(std::string filename)
{
	std::ofstream saveFile("save\\" + filename, std::ios_base::binary);

	long long fileSize = sizeof(this);
	saveFile << fileSize;
	saveFile.write((char*)this, fileSize);

	saveFile.close();
}

void Level::LoadLevel(std::string filename)
{
	std::ifstream saveFile("save\\" + filename);

	long long fileSize;

	saveFile >> fileSize;
	saveFile.read((char*)this, fileSize);

	saveFile.close();
}