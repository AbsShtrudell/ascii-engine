#pragma once
#include <Game/World.h>
#include <Game/Menu/MainMenuControlller.h>
#include <Game/Menu/SelectPlayer.h>

class Menu
{
public:
	Menu();
	~Menu();

	void StartGame(int i);
	void Authorized(int i);
private:
	UserContainer* users;
	MainMenuControlller* menucontroler;
	SelectPlayer* selectPlayer;
};
