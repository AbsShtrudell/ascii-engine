#include "UsersController.h"
#include <algorithm>

UsersController::UsersController()
{
}

UsersController::~UsersController()
{
}

bool UsersController::Authorize(wstring name, wstring password)
{
	hash<wstring> hashing;

	size_t pass= hashing(password);
	size_t pass2;

	try
	{
		pass2 = ReadPassword(name);
	}
	catch (exception)
	{
		return false;
	}

	if (pass == pass2) return true;
	else return false;
}

bool UsersController::RegisterNewPlayer(wstring name, wstring password)
{
	vector<wstring> names = ListPlayers();

	for (auto name1 : names)
		if (name1 == name) return false;

	wstring path = L"Players\\" + name + L".plr";
	wofstream fileOut;
	fileOut.open(path, ios_base::out);

	if (fileOut.is_open())
	{
		fileOut << name << L' ';

		hash<wstring> hashing;
		size_t pass = hashing(password);
		fileOut << pass << L' ';

		fileOut << 0 << L' ';
		fileOut << Date::Today().getYear() << L' ';
		fileOut << Date::Today().getMonth() << L' ';
		fileOut << Date::Today().getDay();

		fileOut.close();
	}
}

vector<PlayerInfo> UsersController::GetAllPlayers()
{
	vector<PlayerInfo> players;

	vector<wstring> names = ListPlayers();

	for (auto name : names)
	{
		try
		{
			players.push_back(ReadPlayer(name));
		}
		catch (exception){}
	}

	return players;
}

void UsersController::EditPlayer(wstring name, Date date)
{
	size_t pass;
	wstring path = L"Players\\" + name + L".plr";
	PlayerInfo player;
	try
	{
		player = ReadPlayer(name);
		pass = ReadPassword(name);
	}
	catch (exception)
	{
		return;
	}

	wofstream fileOut;
	fileOut.open(path, ios_base::out);

	if (fileOut.is_open())
	{
		fileOut << name << L' ';
		fileOut << pass << L' ';

		fileOut << player.getHighScore() << L' ';
		fileOut << date.getYear() << L' ';
		fileOut << date.getMonth() << L' ';
		fileOut << date.getDay();

		fileOut.close();
	}
}

void UsersController::EditPlayer(wstring name, int highScore)
{
	size_t pass;
	wstring path = L"Players\\" + name + L".plr";
	PlayerInfo player;
	try
	{
		player = ReadPlayer(name);
		pass = ReadPassword(name);
	}
	catch (exception)
	{
		return;
	}

	wofstream fileOut;
	fileOut.open(path, ios_base::out);

	if (fileOut.is_open())
	{
		fileOut << name << L' ';
		fileOut << pass << L' ';

		fileOut << highScore << L' ';
		fileOut << player.getDate().getYear() << L' ';
		fileOut << player.getDate().getMonth() << L' ';
		fileOut << player.getDate().getDay();

		fileOut.close();
	}
}

void UsersController::DeletePlayer(wstring name)
{
	wstring path = L"Players\\" + name + L".plr";
	remove(string(path.begin(), path.end()).c_str());
}

PlayerInfo UsersController::ReadPlayer(wstring name)
{
	wstring path = L"Players\\" + name + L".plr";
	wifstream file;
	file.open(path, ios_base::in);

	Date date;
	wstring username;
	int highscore;
	int input;
	wchar_t symb;
	if (file.is_open())
	{
		file >> username;

		file.get(symb);
		while (file.get(symb))
			if (symb == L' ') break;

		file >> highscore;
		file >> input;
		date.setYear(input);
		file >> input;
		date.setMonth(input);
		file >> input;
		date.setDay(input);
		PlayerInfo player(username, highscore);
		player.setDate(date);

		file.close();

		return player;
	}
	else throw exception("Can't find such player");
}

void UsersController::WritePlayer(PlayerInfo info)
{
	wstring path = L"Players\\" + info.getName() + L".plr";

	size_t pass;
	
	try
	{
		pass = ReadPassword(info.getName());
	}
	catch (exception){}

	wofstream fileOut;
	fileOut.open(path, ios_base::out);

	if (fileOut.is_open())
	{
		fileOut << info.getName() << L' ';
		fileOut << pass << L' ';
		fileOut << info.getHighScore() << L' ';
		fileOut << info.getDate().getYear() << L' ';
		fileOut << info.getDate().getMonth() << L' ';
		fileOut << info.getDate().getDay();

		fileOut.close();
	}
}

size_t UsersController::ReadPassword(wstring name)
{
	wstring path = L"Players\\" + name + L".plr";
	wifstream file;
	file.open(path, ios_base::in);

	size_t password;

	wchar_t symb;
	if (file.is_open())
	{
		file.get(symb);
		while (file.get(symb))
			if (symb == L' ') break;
		file >> password;

		file.close();
	}
	else throw exception("Can't find such player");

	return password;
}

vector<wstring> UsersController::ListPlayers()
{
	vector<wstring> FileList;

	DIR* dir;
	dirent* ent;

	FileList.clear();

	if ((dir = opendir("Players\\")) != NULL) 
	{
		while ((ent = readdir(dir)) != NULL) 
		{
			string filename = string(ent->d_name);
			if (filename.length() > 4) {
				string ext = filename.substr(filename.size() - 3);
				if (ext == "plr") {
					FileList.push_back(wstring(filename.begin(), filename.end() - 4));
				}
			}
		}
		closedir(dir);
	}
	else {
		cerr << "Could not open directory: " << "Player\\" << "\n";
		return FileList;
	}
	return FileList;
}
