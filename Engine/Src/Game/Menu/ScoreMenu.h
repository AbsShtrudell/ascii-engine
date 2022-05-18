#pragma once
#include <string>
#include <Core/Pawn.h>
#include <Core/Text.h>
#include <System/Delegate.h>
#include <Game/Menu/UsersController.h>

class ScoreMenu : public Pawn
{
public:
	ScoreMenu(std::wstring name);
	~ScoreMenu();

	void OnKeyUp(int key) override;

private:
	std::vector<PlayerInfo> players;

	std::vector<Text*> leadersNames;
	std::vector<Text*> leadersScores;
	std::vector<Text*> leadersDates;

	Text* exitText = nullptr;
	Text* leaderText = nullptr;

	std::wstring playerName;
public:
	Delegate<int> onBack;
};

