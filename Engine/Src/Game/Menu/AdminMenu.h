#pragma once
#include <string>
#include <Core/Pawn.h>
#include <Core/Text.h>
#include <System/Delegate.h>
#include <Game/Menu/UsersController.h>
#include <Game/Menu/Write.h>

class AdminMenu : public Pawn
{
public:
	AdminMenu();
	~AdminMenu();

	void OnKeyUp(int key) override;

	void UpdateTableText();
	void UpdatePlayersList();
	void NextPlayer();
	void PreviousPlayer();
	void DeletePlayer();
	void UpdateCounter();

	void StartSortSelection();
	void NextSortType();
	void PreviousSortType();
	void SelectSortType();
	void ExitSelectionSortType();
	void UpdateSortTypeTextColor();

	void StartSeekPlayer();
	void FindPlayer(std::wstring name);

	void StartEditTypeSelection();
	void NextEditType();
	void PreviousEditType();
	void SelectEditType();
	void ExitSelectionEditType();
	void UpdateEditTypeTextColor();
	void EndEditing(std::wstring value);
private:
	std::vector<PlayerInfo> players;

	std::vector<Text*> playersNames;
	std::vector<Text*> playersScores;
	std::vector<Text*> playersDates;
	std::vector<Text*> sortType;
	std::vector<Text*> editTypes;
	std::vector<function<bool(PlayerInfo, PlayerInfo)>> sortFunctions;
	std::vector<function<void(std::wstring value)>> editFunctions;

	int editCounter = 0;
	int sortTypeCounter = 0;
	int counter = 0;

	bool scrollActive = true;
	bool sortSelect = false;
	bool editSelect = false;

	Vec2 activeLines;

	Text* playersText = nullptr;
	Text* infoText = nullptr;

	Write* writeText = nullptr;
public:
	Delegate<int> onBack;
};

