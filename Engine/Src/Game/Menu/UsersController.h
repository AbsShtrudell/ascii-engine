#pragma once
#include <fstream>
#include <iostream>
#include <dirent.h>
#include <cstdio>
#include <vector>
#include <Game/Menu/PlayerInfo.h>

using namespace std;

class UsersController
{
public:
	UsersController();
	~UsersController();

	static bool Authorize(wstring name, wstring password);
	static bool RegisterNewPlayer(wstring name, wstring password);
	static vector<PlayerInfo> GetAllPlayers();

	static void EditPlayer(wstring name, Date date);
	static void EditPlayer(wstring name, int highScore);

	static void DeletePlayer(wstring name);

private:
	static PlayerInfo ReadPlayer(wstring name);
	static void WritePlayer(PlayerInfo info);
	static size_t ReadPassword(wstring name);

	static vector<wstring> ListPlayers();
};

