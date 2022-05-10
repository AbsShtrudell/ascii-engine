#pragma once
#include <Core/Pawn.h>
#include <Core/Camera.h>
#include <Game/Menu/Write.h>
#include <Game/Menu/UserContainer.h>

class SelectPlayer : public Pawn
{
public:
	SelectPlayer(UserContainer* users);
	~SelectPlayer();

	virtual void OnKeyDown(int key) override;

	void Exit();
	void SetWriteState();
	void EnterName(std::wstring name);
	void EnterPassword(std::wstring password);
	void StartCycle();
	void AddUser(int i);
	void FindUser(int i);

private:
	UserContainer* users;

	Camera* camera;
	Text* addNewText;
	Text* selectExistedText;
	Text* enterNameText;
	Text* enterPasswordText;
	Write* enterNameWrite;
	Write* enterPasswordWrite;

	bool selectionActive = true;
	int selectedPlayerID;

	PlayerInfo* player;
	Delegate<int> onDataEntered;
public:
	Delegate<int> onSelected;
};

