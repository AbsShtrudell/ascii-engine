#include "UserContainer.h"
#include <algorithm>

UserContainer::UserContainer()
{
	ReadPlayers();
}

UserContainer::~UserContainer()
{
	for (int i = 0; i < players.size(); i++)
	{
		delete players[i];
	}
}

bool UserContainer::Authorize(std::wstring name, size_t password)
{
	for (int i = 0; i < players.size(); i++)
		if (players[i]->getName() == name)
		{
			if (players[i]->getPassword() == password)
				return true;
			else return false;
		}
	return false;
}

bool UserContainer::AddPlayer(PlayerInfo info)
{
	for (int i = 0; i < players.size(); i++)
		if (players[i]->getName() == info.getName())
			return false;
	WritePlayer(info);
	ReadPlayer(info.getName());
	return true;
}

void UserContainer::ReadPlayer(std::wstring name)
{
	std::wstring path = L"Players\\" + name + L".plr";
	std::wifstream file;
	file.open(path);

	size_t password;
	std::wstring username;
	int highscore;

	int symb;
	if (file.is_open())
	{
		file >> username;
		file >> password;
		file >> highscore;

		PlayerInfo* player = new PlayerInfo(username, highscore);
		player->setPassword(password);

		if (std::find(players.begin(), players.end(), player) == players.end())
			players.push_back(player);
		else
			delete player;
	}
}

void UserContainer::WritePlayer(PlayerInfo info)
{
	std::wstring path = L"Players\\" + info.getName() + L".plr";

	std::wofstream file;
	file.open(path, std::ios::out);

	if (file.is_open())
	{
		file << info.getName() << L" ";
		file << info.getPassword() << L" ";
		file << info.getHighScore();
	}
}

std::vector<std::string> UserContainer::ListPlayers()
{
	std::vector<std::string> FileList;

	DIR* dir;
	struct dirent* ent;
	FileList.clear();

	if ((dir = opendir("Players\\")) != NULL) {
		while ((ent = readdir(dir)) != NULL) {
			std::string filename = std::string(ent->d_name);
			if (filename.length() > 4) {
				std::string ext = filename.substr(filename.size() - 3);
				if (ext == "plr") {
					FileList.push_back(filename);
				}
			}
		}
		closedir(dir);
	}
	else {
		std::cerr << "Could not open directory: " << "Player\\" << "\n";
		return FileList;
	}
	return FileList;
}

void UserContainer::ReadPlayers()
{
	std::vector<std::string> PlayerList = ListPlayers();
	for (int i = 0; i < PlayerList.size(); i++)
	{
		ReadPlayer(std::wstring(PlayerList[i].begin(), PlayerList[i].end() - 4));
	}
}

void UserContainer::WritePlayers()
{
	for (auto player : players)
	{
		WritePlayer(*player);
	}
}
