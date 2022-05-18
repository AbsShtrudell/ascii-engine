#include "MainMenu.h"

MainMenu::MainMenu()
{
	camera = new Camera(this);

	selectPlayer = new SelectMenu();
	selectPlayer->onSelected.Bind(std::bind(&MainMenu::Authorized, this, std::placeholders::_1));

	for (int i = 0; i < 7; i++)
	{
		clouds.push_back(new Sprite("Resources\\MarioBrosSprites\\cloud.spr"));
	}
	clouds[0]->setLocation(Vec2(20, 10));
	clouds[1]->setLocation(Vec2(50, 22));
	clouds[2]->setLocation(Vec2(0, 40));
	clouds[3]->setLocation(Vec2(100, 15));
	clouds[4]->setLocation(Vec2(135, 35));
	clouds[5]->setLocation(Vec2(78, 50));
	clouds[6]->setLocation(Vec2(198, 10));
}

MainMenu::~MainMenu()
{
	if(menucontroler != NULL)
		menucontroler ->Destroy();
	camera->Destroy();
	if (selectPlayer != NULL)
		selectPlayer->Destroy();
	if (scoreMenu != NULL)
		scoreMenu->Destroy();
	if (adminMenu != NULL)
		adminMenu->Destroy();
	for (auto cloud : clouds)
		cloud->Destroy();
}

void MainMenu::OnUpdate()
{
	for (auto cloud : clouds)
	{
		if (cloud->getWorldLocation().x < 220)
			cloud->addLocation(1, 0);
		else
			cloud->setLocation(Vec2(-33, cloud->getWorldLocation().y));
	}
}

void MainMenu::ScoreExit(int i)
{
	if (scoreMenu != NULL)
	{
		scoreMenu->Destroy();
		scoreMenu = nullptr;
	}
	
	menucontroler = new MainMenuControlller;
	menucontroler->onStart.Bind(std::bind(&MainMenu::StartGame, this, std::placeholders::_1));
	menucontroler->onScoreMenu.Bind(std::bind(&MainMenu::OpenScoreMenu, this, std::placeholders::_1));
	menucontroler->onAdminMenu.Bind(std::bind(&MainMenu::OpenAdminMenu, this, std::placeholders::_1));
	if (playerName == L"ADMIN")menucontroler->setAdminState(true);
}

void MainMenu::AdminExit(int i)
{
	if (adminMenu != NULL)
	{
		adminMenu->Destroy();
		adminMenu = nullptr;
	}

	menucontroler = new MainMenuControlller;
	menucontroler->onStart.Bind(std::bind(&MainMenu::StartGame, this, std::placeholders::_1));
	menucontroler->onScoreMenu.Bind(std::bind(&MainMenu::OpenScoreMenu, this, std::placeholders::_1));
	menucontroler->onAdminMenu.Bind(std::bind(&MainMenu::OpenAdminMenu, this, std::placeholders::_1));
	if (playerName == L"ADMIN")menucontroler->setAdminState(true);
}

void MainMenu::StartGame(int i)
{
	World* world = new World();
	this->Destroy();
}

void MainMenu::OpenScoreMenu(int i)
{
	if (menucontroler != NULL)
	{
		menucontroler->Destroy();
		menucontroler = nullptr;
	}

	scoreMenu = new ScoreMenu(playerName);
	scoreMenu->onBack.Bind(std::bind(&MainMenu::ScoreExit, this, std::placeholders::_1));
}

void MainMenu::OpenAdminMenu(int i)
{
	if (menucontroler != NULL)
	{
		menucontroler->Destroy();
		menucontroler = nullptr;
	}

	adminMenu = new AdminMenu();
	adminMenu->onBack.Bind(std::bind(&MainMenu::AdminExit, this, std::placeholders::_1));
}

void MainMenu::Authorized(std::wstring name)
{
	playerName = name;
	selectPlayer->Destroy();
	selectPlayer = nullptr;

	menucontroler = new MainMenuControlller;
	menucontroler->onStart.Bind(std::bind(&MainMenu::StartGame, this, std::placeholders::_1));
	menucontroler->onScoreMenu.Bind(std::bind(&MainMenu::OpenScoreMenu, this, std::placeholders::_1));
	menucontroler->onAdminMenu.Bind(std::bind(&MainMenu::OpenAdminMenu, this, std::placeholders::_1));
	if (playerName == L"ADMIN")menucontroler->setAdminState(true);
}
