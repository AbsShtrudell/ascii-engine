#pragma once
#include <Core/Pawn.h>
#include <Core/Camera.h>
#include <Game/Menu/Write.h>
#include <Game/Menu/UsersController.h>
#include <Game/Menu/SelectMenuController.h>
#include <Core/Object.h>

class SelectMenu : public Object
{
public:
	SelectMenu();
	~SelectMenu();

	void Exit(int i);
	void Selected();
	void SetWriteState();
	void Authorize(int i);
	void Register(int i);
	void EnterName(std::wstring name);
	void EnterPassword(std::wstring password);
	void StartCycle();
	void AddUser(std::wstring);
	void FindUser(std::wstring);

private:
	Text* addNewText = nullptr;
	Text* selectExistedText = nullptr;
	Text* enterNameText = nullptr;
	Text* enterPasswordText = nullptr;
	Text* errorText = nullptr;
	Text* exitText = nullptr;
	Write* enterNameWrite = nullptr;
	Write* enterPasswordWrite = nullptr;
	SelectMenuController* controller = nullptr;

	bool selectionActive = true;
	int selectedPlayerID;

	std::wstring playerName;

	Delegate<std::wstring> onDataEntered;
public:
	Delegate<std::wstring> onSelected;
};

