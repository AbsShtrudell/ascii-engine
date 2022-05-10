#include "Menu.h"

Menu::Menu()
{
	users = new UserContainer();
	selectPlayer = new SelectPlayer(users);
	selectPlayer->onSelected.Bind(std::bind(&Menu::Authorized, this, std::placeholders::_1));
}

Menu::~Menu()
{
	menucontroler->Destroy();
}

void Menu::StartGame(int i)
{
	World* world = new World();
	delete world;
	delete this;
}

void Menu::Authorized(int i)
{
	selectPlayer->Destroy();
	menucontroler = new MainMenuControlller;
	menucontroler->onStart.Bind(std::bind(&Menu::StartGame, this, std::placeholders::_1));
}
