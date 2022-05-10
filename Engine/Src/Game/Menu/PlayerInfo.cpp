#include "PlayerInfo.h"

PlayerInfo::PlayerInfo(std::wstring name, int highScore)
{
	this->name = name;
	this->highScore = highScore;
}

std::wstring PlayerInfo::getName()
{
	return name;
}

size_t PlayerInfo::getPassword()
{
	return password;
}

int PlayerInfo::getHighScore()
{
	return highScore;
}

void PlayerInfo::setName(std::wstring name)
{
	this->name = name;
	onNameChanged.Call(this->name);
}

void PlayerInfo::setPassword(std::wstring password)
{
	std::hash<std::wstring> hash_h;
	this->password = hash_h(password);
}

void PlayerInfo::setPassword(size_t password)
{
	this->password = password;
}


void PlayerInfo::setHighScore(int highScore)
{
	this->highScore = highScore;
	onHaighScoreChanged.Call(this->highScore);
}
