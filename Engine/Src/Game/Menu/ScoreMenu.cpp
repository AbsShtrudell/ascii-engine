#include "ScoreMenu.h"
#include <algorithm>

ScoreMenu::ScoreMenu(std::wstring name)
{
	playerName = name;
	players = UsersController::GetAllPlayers();
	
	auto it = std::find_if(players.begin(), players.end(), [](const PlayerInfo& player) { return (player.getName() == L"ADMIN"); });
	if (it != players.end())
		players.erase(it);

	std::sort(players.begin(), players.end(), [&](PlayerInfo player1, PlayerInfo player2) { return (player1.getHighScore() > player2.getHighScore()); });


	exitText = new Text(L"Íàæìèòå \"ENTER\" ×ÒÎÁÛ ÂÅÐÍÓÒÜÑß Â ÌÅÍÞ", 159);
	leaderText = new Text(L"ÒÀÁËÈÖÀ ËÈÄÅÐÎÂ", 159);
	leaderText->setLocation(Vec2(20, 4));

	int color;
	bool found = false;
	int i = 0;
	for (; i < players.size() && i < 10; i++)
	{
		color = 159;
		if (players[i].getName() == playerName) { color = 156; found = true; }
		leadersNames.push_back(new Text(std::to_wstring(i + 1) + L"." + players[i].getName(), color));
		leadersNames[i]->setLocation(Vec2(10, 6 + i));
		leadersScores.push_back(new Text(std::to_wstring(players[i].getHighScore()), color));
		leadersScores[i]->setLocation(Vec2(30, 6 + i));
		leadersDates.push_back(new Text(std::to_wstring(players[i].getDate().getYear()) + L":" + std::to_wstring(players[i].getDate().getMonth()) + L":" + std::to_wstring(players[i].getDate().getDay()), color));
		leadersDates[i]->setLocation(Vec2(40, 6 + i));
	}

	if (!found)
	{
		color = 156;
		for (int counter = i; counter < players.size(); counter++)
		{
			if (players[counter].getName() == playerName)
			{
				leadersNames.push_back(new Text(std::to_wstring(counter + 1) + L"." + players[counter].getName(), color));
				leadersNames[i]->setLocation(Vec2(10, 6 + i));
				leadersScores.push_back(new Text(std::to_wstring(players[counter].getHighScore()), color));
				leadersScores[i]->setLocation(Vec2(30, 6 + i));
				leadersDates.push_back(new Text(std::to_wstring(players[counter].getDate().getYear()) + L":" + std::to_wstring(players[counter].getDate().getMonth()) + L":" + std::to_wstring(players[counter].getDate().getDay()), color));
				leadersDates[i]->setLocation(Vec2(40, 6 + i));
			}
		}
	}
}

ScoreMenu::~ScoreMenu()
{
	for (int i = 0; i < leadersNames.size(); i++)
	{
		leadersNames[i]->Destroy();
		leadersDates[i]->Destroy();
		leadersScores[i]->Destroy();
	}

	exitText->Destroy();
	leaderText->Destroy();
}

void ScoreMenu::OnKeyUp(int key)
{
	switch (key)
	{
	case 13:
		onBack.Call(0);
		break;
	}
}
