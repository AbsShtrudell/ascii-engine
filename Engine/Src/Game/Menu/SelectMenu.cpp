#include "SelectMenu.h"

SelectMenu::SelectMenu()
{
	addNewText = new Text(L"ÍÀÆÌÈÒÅ \"1\" ×ÒÎÁÛ ÑÎÇÄÀÒÜ ÍÎÂÎÃÎ ÈÃÐÎÊÀ", 159);

	selectExistedText = new Text(L"ÍÀÆÌÈÒÅ \"2\" ×ÒÎÁÛ ÂÛÁÐÀÒÜ ÑÓÙÅÑÒÂÓÞÙÅÃÎ ÈÃÐÎÊÀ", 159);
	selectExistedText->setLocation(Vec2(0, 2));

	exitText = new Text(L"ÍÀÆÌÈÒÅ \"3\" ×ÒÎÁÛ ÂÛÉÒÈ", 159);
	exitText->setLocation(Vec2(0, 4));

	enterNameText = new Text(L"ÂÂÅÄÈÒÅ ÈÌß", 159);
	enterNameText->setVisibility(false);

	errorText = new Text(L"ÍÅÂÅÐÍÎÅ ÈÌß ÏÎËÜÇÎÂÀÒÅËß ÈËÈ ÏÀÐÎËÜ!!!", 148);
	errorText->setVisibility(false);
	errorText->setLocation(Vec2(0, 6));

	enterPasswordText = new Text(L"ÂÂÅÄÈÒÅ ÏÀÐÎËÜ", 159);
	enterPasswordText->setVisibility(false);
	enterPasswordText->setLocation(Vec2(0, 4));

	enterPasswordWrite = new Write();
	enterPasswordWrite->setLocation(Vec2(0, 6));

	enterNameWrite = new Write();
	enterNameWrite->setLocation(Vec2(0, 2));

	controller = new SelectMenuController();
	controller->onAuthorization.Bind(std::bind(&SelectMenu::Authorize, this, std::placeholders::_1));
	controller->onRegistration.Bind(std::bind(&SelectMenu::Register, this, std::placeholders::_1));
	controller->onExit.Bind(std::bind(&SelectMenu::Exit, this, std::placeholders::_1));
}

SelectMenu::~SelectMenu()
{
	delete addNewText;
	delete selectExistedText;
	delete enterNameText;
	delete enterPasswordText;
	delete enterPasswordWrite;
	delete enterNameWrite;
	delete controller;
	delete errorText;
	delete exitText;

}

void SelectMenu::Exit(int i)
{
	exit(0);
}

void SelectMenu::Selected()
{
	onSelected.Call(playerName);
}

void SelectMenu::SetWriteState()
{
	addNewText->setVisibility(false);
	selectExistedText->setVisibility(false);
	enterNameText->setVisibility(true);
	errorText->setVisibility(false);
	exitText->setVisibility(false);
	enterNameWrite->setWriteState(true);

	selectionActive = false;
	controller->setActive(false);
}

void SelectMenu::Authorize(int i)
{
	SetWriteState();
	enterNameWrite->onEndWrite.Bind(std::bind(&SelectMenu::EnterName, this, std::placeholders::_1));
	onDataEntered.Bind(std::bind(&SelectMenu::AddUser, this, std::placeholders::_1));
}

void SelectMenu::Register(int i)
{
	SetWriteState();
	enterNameWrite->onEndWrite.Bind(std::bind(&SelectMenu::EnterName, this, std::placeholders::_1));
	onDataEntered.Bind(std::bind(&SelectMenu::FindUser, this, std::placeholders::_1));
}

void SelectMenu::EnterName(std::wstring name)
{
	playerName = name;
	enterPasswordText->setVisibility(true);
	enterPasswordWrite->setWriteState(true);

	enterPasswordWrite->onEndWrite.Bind(std::bind(&SelectMenu::EnterPassword, this, std::placeholders::_1));
}

void SelectMenu::EnterPassword(std::wstring password)
{
	onDataEntered.Call(password);
}

void SelectMenu::StartCycle()
{
	enterNameText->setVisibility(false);
	enterPasswordText->setVisibility(false);
	enterPasswordWrite->setWriteState(false);
	enterPasswordWrite->Clear();
	addNewText->setVisibility(true);
	selectExistedText->setVisibility(true);
	enterNameText->setVisibility(false);
	enterNameWrite->setWriteState(false);
	enterNameWrite->Clear();
	selectionActive = true;
	controller->setActive(true);
	errorText->setVisibility(true);
	exitText->setVisibility(true);
}

void SelectMenu::AddUser(std::wstring password)
{
	if (UsersController::RegisterNewPlayer(playerName, password))
		Selected();
	else StartCycle();
}

void SelectMenu::FindUser(std::wstring password)
{
	if (UsersController::Authorize(playerName, password))
		Selected();
	else StartCycle();
}
