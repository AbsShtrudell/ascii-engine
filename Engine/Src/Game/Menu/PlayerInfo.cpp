#include "PlayerInfo.h"

PlayerInfo::PlayerInfo(wstring name, int highScore)
{
	this->name = name;
	this->highScore = highScore;
}

wstring PlayerInfo::getName() const
{
	return name;
}

Date PlayerInfo::getDate()
{
	return highScoreDate;
}

int PlayerInfo::getHighScore()
{
	return highScore;
}

void PlayerInfo::setDate(Date date)
{
	highScoreDate = date;
}

void PlayerInfo::setName(wstring name)
{
	this->name = name;
}


void PlayerInfo::setHighScore(int highScore)
{
	this->highScore = highScore;
}
