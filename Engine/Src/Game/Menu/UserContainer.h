#pragma once
#include <fstream>
#include <iostream>
#include <dirent.h>
#include <vector>
#include <Game/Menu/PlayerInfo.h>

class UserContainer
{
public:
	UserContainer();
	~UserContainer();

	bool Authorize(std::wstring name, size_t password);

	bool AddPlayer(PlayerInfo info);

	void ReadPlayer(std::wstring name);
	void WritePlayer(PlayerInfo info);

	std::vector<std::string> ListPlayers();

	void ReadPlayers();
	void WritePlayers();
private:
	std::vector<PlayerInfo*> players;
};

