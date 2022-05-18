#pragma once
#include <iostream>
#include <System/Delegate.h>
#include <Game/Menu/Date.h>

using namespace std;

class PlayerInfo
{
public:
	PlayerInfo(){}
	PlayerInfo(wstring name, int highScore);

	wstring getName() const;
	Date getDate();
	int getHighScore();

	void setDate(Date date);
	void setName(wstring name);
	void setHighScore(int highScore);
private:
	wstring name;
	Date highScoreDate;
	int highScore = 0;
};

