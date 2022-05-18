#pragma once
#include <Game/World.h>
#include <Game/Menu/MainMenuControlller.h>
#include <Game/Menu/SelectMenu.h>
#include <Game/Menu/ScoreMenu.h>
#include <Game/Menu/AdminMenu.h>

class MainMenu : Object
{
public:
	MainMenu();
	~MainMenu();

	void OnUpdate() override;

	void ScoreExit(int i);
	void AdminExit(int i);
	void StartGame(int i);
	void OpenScoreMenu(int i);
	void OpenAdminMenu(int i);
	void Authorized(std::wstring name);
private:
	MainMenuControlller* menucontroler = nullptr;
	SelectMenu* selectPlayer = nullptr;
	ScoreMenu* scoreMenu = nullptr;
	AdminMenu* adminMenu = nullptr;
	Camera* camera = nullptr;
	vector<Sprite*> clouds;
	std::wstring playerName;
};
