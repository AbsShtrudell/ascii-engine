#pragma once
#include <iostream>
#include <System/Delegate.h>
class PlayerInfo
{
public:
	PlayerInfo(){}
	PlayerInfo(std::wstring name, int highScore);

	std::wstring getName();
	size_t  getPassword();
	int getHighScore();

	void setName(std::wstring name);
	void setPassword(std::wstring password);
	void setPassword(size_t password);
	void setHighScore(int highScore);
private:
	std::wstring name;
	size_t password = 0;
	int highScore = 0;
public:
	Delegate<int> onHaighScoreChanged;
	Delegate<std::wstring> onNameChanged;
};

