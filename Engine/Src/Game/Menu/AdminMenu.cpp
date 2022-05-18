#include "AdminMenu.h"
#include <algorithm>;

AdminMenu::AdminMenu()
{
	UpdatePlayersList();
	activeLines = Vec2(0, (activeLines.x + 9) > players.size() - 1 ? players.size() - 1 : activeLines.x + 9);
	UpdateCounter();

	writeText = new Write;
	writeText->setWriteState(false);

	sortType.push_back(new Text(L"Ïî Î÷êàì Âîç"));
	sortType.push_back(new Text(L"Ïî Î÷êàì  Óá"));
	sortType.push_back(new Text(L"Ïî Äàòå  Âîç"));
	sortType.push_back(new Text(L"Ïî Äàòå   Óá"));	
	sortType.push_back(new Text(L"Ïî Èìåíè Âîç"));
	sortType.push_back(new Text(L"Ïî Èìåíè  Óá"));

	for (int i = 0; i < sortType.size(); i++)
	{
		sortType[i]->setLocation(Vec2(55, 2 + i));
		sortType[i]->setVisibility(false);
	}

	sortFunctions.push_back([](PlayerInfo player1, PlayerInfo player2) {return player1.getHighScore() < player2.getHighScore(); });
	sortFunctions.push_back([](PlayerInfo player1, PlayerInfo player2) {return player1.getHighScore() > player2.getHighScore(); });
	sortFunctions.push_back([](PlayerInfo player1, PlayerInfo player2) {return player1.getDate() < player2.getDate(); });
	sortFunctions.push_back([](PlayerInfo player1, PlayerInfo player2) {return player1.getDate() > player2.getDate(); });
	sortFunctions.push_back([](PlayerInfo player1, PlayerInfo player2) {return player1.getName().at(0) < player2.getName().at(0); });
	sortFunctions.push_back([](PlayerInfo player1, PlayerInfo player2) {return player1.getName().at(0) > player2.getName().at(0); });

	for (int i = 0; i < 10 && i < players.size(); i++)
	{
		playersNames.push_back(new Text(L" ", 159));
		playersNames[i]->setLocation(Vec2(10, 6 + i));
		playersScores.push_back(new Text(L" ", 159));
		playersScores[i]->setLocation(Vec2(30, 6 + i));
		playersDates.push_back(new Text(L" ", 159));
		playersDates[i]->setLocation(Vec2(40, 6 + i));
	}

	editTypes.push_back(new Text(L"Î÷êè  "));
	editTypes.push_back(new Text(L"Ãîä   "));
	editTypes.push_back(new Text(L"Ìåñÿö "));
	editTypes.push_back(new Text(L"Äåíü  "));

	for (int i = 0; i < editTypes.size(); i++)
	{
		editTypes[i]->setLocation(Vec2(55, 2 + i));
		editTypes[i]->setVisibility(false);
	}

	editFunctions.push_back([&](std::wstring value) { try { UsersController::EditPlayer(players[counter].getName(), std::stoi(value)); } catch (exception ex) {} });
	editFunctions.push_back([&](std::wstring value) { try { UsersController::EditPlayer(players[counter].getName(), Date(std::stoi(value), players[counter].getDate().getMonth(), players[counter].getDate().getDay())); } catch (exception ex) {}});
	editFunctions.push_back([&](std::wstring value) { try { UsersController::EditPlayer(players[counter].getName(), Date(players[counter].getDate().getYear(), std::stoi(value), players[counter].getDate().getDay()));}catch (exception ex) {} });
	editFunctions.push_back([&](std::wstring value) { try { UsersController::EditPlayer(players[counter].getName(), Date(players[counter].getDate().getYear(), players[counter].getDate().getMonth(), std::stoi(value)));}catch (exception ex) {} });

	infoText = new Text(L"\"ESC\"- ÂÛÉÒÈ | \"E\"- ĞÅÄÀÊÒÈĞÎÂÀÒÜ | \"V\"- ÑÎĞÒÈĞÎÂÀÒÜ | \"DEL\"- ÓÄÀËÈÒÜ | \"TAB\"- ÏÎÈÑÊ", 159);
	playersText = new Text(L"ÑÏÈÑÎÊ ÈÃĞÎÊÎÂ", 159);
	playersText->setLocation(Vec2(20, 4));

	UpdateTableText();
}

AdminMenu::~AdminMenu()
{
	for (int i = 0; i < playersNames.size(); i++)
	{
		playersNames[i]->Destroy();
		playersScores[i]->Destroy();
		playersDates[i]->Destroy();
	}

	infoText->Destroy();
	playersText->Destroy();
}

void AdminMenu::OnKeyUp(int key)
{
	if (scrollActive)
	{
		switch (key)
		{
		case 'W':
			PreviousPlayer();
			break;
		case'S':
			NextPlayer();
			break;
		case'V':
			StartSortSelection();
			break;
		case 46:
			DeletePlayer();
			break;
		case 9:
			StartSeekPlayer();
			break;
		case'E':
			StartEditTypeSelection();
			break;
		}
	}
	if (sortSelect)
	{
		switch (key)
		{
		case 'W':
			PreviousSortType();
			break;
		case'S':
			NextSortType();
			break;
		case 13:
			SelectSortType();
			break;
		case 27:
			ExitSelectionSortType();
			break;
		}
	}
	if (editSelect)
	{
		switch (key)
		{
		case 'W':
			PreviousEditType();
			break;
		case'S':
			NextEditType();
			break;
		case 9:
			SelectEditType();
			break;
		case 27:
			ExitSelectionEditType();
			break;
		}
	}
}

void AdminMenu::UpdateTableText()
{
	int line = activeLines.x;
	int color = 159;
	for (int i = 0; i < playersNames.size(); i++)
	{
		if (line >= players.size())
		{
			playersNames[i]->setVisibility(false);
			playersNames[i]->setColor(159);
			playersScores[i]->setVisibility(false);
			playersScores[i]->setColor(159);
			playersDates[i]->setVisibility(false);
			playersDates[i]->setColor(159);
			continue;
		}
		else
		{
			playersNames[i]->setVisibility(true);
			playersScores[i]->setVisibility(true);
			playersDates[i]->setVisibility(true);
		}

		if (line == counter) color = 156; else color = 159;
		playersNames[i]->setText(std::to_wstring(line + 1) + L"." + players[line].getName());
		playersNames[i]->setColor(color);
		playersScores[i]->setText(std::to_wstring(players[line].getHighScore()));
		playersScores[i]->setColor(color);
		playersDates[i]->setText(std::to_wstring(players[line].getDate().getYear()) + L":" + std::to_wstring(players[line].getDate().getMonth()) + L":" + std::to_wstring(players[line].getDate().getDay()));
		playersDates[i]->setColor(color);
		line++;
	}
}

void AdminMenu::UpdatePlayersList()
{
	players.clear();
	players = UsersController::GetAllPlayers();
	
	auto it = std::find_if(players.begin(), players.end(), [](const PlayerInfo& player) { return (player.getName() == L"ADMIN"); });
	if (it != players.end())
		players.erase(it);
}

void AdminMenu::NextPlayer()
{
	if (counter < players.size() - 1)
	{
		counter++;
		UpdateCounter();
		UpdateTableText();
	}
}

void AdminMenu::PreviousPlayer()
{
	if (counter > 0)
	{
		counter--;
		UpdateCounter();
		UpdateTableText();
	}
}

void AdminMenu::DeletePlayer()
{
	if (counter < players.size() && counter >= 0)
	{
		UsersController::DeletePlayer(players[counter].getName());
		UpdatePlayersList();
		UpdateCounter();
		UpdateTableText();
	}
}

void AdminMenu::UpdateCounter()
{
	if (players.size() == 0)
	{
		counter = 0;
		activeLines = Vec2(0, 0);
		return;
	}
	if (counter >= players.size())
	{
		counter = players.size() - 1;
		activeLines.y = counter;
		activeLines.x = (activeLines.y - 9) < 0 ? 0 : activeLines.y - 9;
		return;
	}
	if (counter < activeLines.x)
	{
		activeLines.x = counter;
		activeLines.y = (activeLines.x + 9) > players.size() - 1 ? players.size() - 1 : activeLines.x + 9;
		return;
	}
	if (counter > activeLines.y)
	{
		activeLines.y = counter;
		activeLines.x = (activeLines.y - 9) < 0 ? 0 : activeLines.y - 9;
		return;
	}
}

void AdminMenu::StartSortSelection()
{
	scrollActive = false;
	sortSelect = true;
	sortTypeCounter = 0;
	for (auto sort : sortType)
	{
		sort->setVisibility(true);
	}
	UpdateSortTypeTextColor();
}

void AdminMenu::NextSortType()
{
	if (sortTypeCounter < sortType.size() - 1)
	{
		sortTypeCounter++;
		UpdateSortTypeTextColor();
	}
}

void AdminMenu::PreviousSortType()
{
	if (sortTypeCounter > 0)
	{
		sortTypeCounter--;
		UpdateSortTypeTextColor();
	}
}

void AdminMenu::SelectSortType()
{
	std::sort(players.begin(), players.end(), sortFunctions[sortTypeCounter]);
	UpdateTableText();
	ExitSelectionSortType();
}

void AdminMenu::ExitSelectionSortType()
{
	scrollActive = true;
	sortSelect = false;
	for (auto sort : sortType)
	{
		sort->setVisibility(false);
	}
}

void AdminMenu::UpdateSortTypeTextColor()
{
	for (int i = 0; i < sortType.size(); i++)
	{
		if (i == sortTypeCounter)
			sortType[i]->setColor(79);
		else
			sortType[i]->setColor(47);
	}
}

void AdminMenu::StartSeekPlayer()
{
	scrollActive = false;
	writeText->setWriteState(true);
	writeText->setLocation(Vec2(0, 2));
	writeText->onEndWrite.Bind(std::bind(&AdminMenu::FindPlayer, this, std::placeholders::_1));
}

void AdminMenu::FindPlayer(std::wstring name)
{
	scrollActive = true;
	writeText->setWriteState(false);
	writeText->Clear();
	for (int i = 0; i < players.size(); i++)
	{
		if (players[i].getName() == name)
		{
			counter = i;
			UpdateCounter();
			UpdateTableText();
			break;
		}
	}
}

void AdminMenu::StartEditTypeSelection()
{
	scrollActive = false;
	editSelect = true;
	editCounter = 0;
	for (auto edit : editTypes)
	{
		edit->setVisibility(true);
	}
	UpdateEditTypeTextColor();
}

void AdminMenu::NextEditType()
{
	if (editCounter < editTypes.size())
	{
		editCounter++;
		UpdateEditTypeTextColor();
	}
}

void AdminMenu::PreviousEditType()
{
	if (editCounter > 0)
	{
		editCounter--;
		UpdateEditTypeTextColor();
	}
}

void AdminMenu::SelectEditType()
{
	editSelect = false;
	for (auto edit : editTypes)
	{
		edit->setVisibility(false);
	}
	writeText->setWriteState(true);
	writeText->setLocation(Vec2(0, 2));
	writeText->onEndWrite.Bind(std::bind(&AdminMenu::EndEditing, this, std::placeholders::_1));
}

void AdminMenu::ExitSelectionEditType()
{
	scrollActive = true;
	editSelect = false;
	for (auto edit : editTypes)
	{
		edit->setVisibility(false);
	}
}

void AdminMenu::UpdateEditTypeTextColor()
{
	for (int i = 0; i < editTypes.size(); i++)
	{
		if (i == editCounter)
			editTypes[i]->setColor(79);
		else
			editTypes[i]->setColor(47);
	}
}

void AdminMenu::EndEditing(std::wstring value)
{
	scrollActive = true;
	writeText->setWriteState(false);
	writeText->Clear();
	
	editFunctions[editCounter](value);

	UpdatePlayersList();
	UpdateCounter();
	UpdateTableText();
}
