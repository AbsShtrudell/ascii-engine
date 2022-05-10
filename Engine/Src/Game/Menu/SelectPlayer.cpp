#include "SelectPlayer.h"

SelectPlayer::SelectPlayer(UserContainer* users)
{
	this->users = users;

	camera = new Camera();
	addNewText = new Text(L"ÍÀÆÌÈÒÅ \"A\" ×ÒÎÁÛ ÑÎÇÄÀÒÜ ÍÎÂÎÃÎ ÈÃÐÎÊÀ", 159);

	selectExistedText = new Text(L"ÍÀÆÌÈÒÅ \"D\" ×ÒÎÁÛ ÂÛÁÐÀÒÜ ÑÓÙÅÑÒÂÓÞÙÅÃÎ ÈÃÐÎÊÀ", 159);
	selectExistedText->setLocation(Vec2(0, 2));

	enterNameText = new Text(L"ÂÂÅÄÈÒÅ ÈÌß", 159);
	enterNameText->setVisibility(false);

	enterPasswordText = new Text(L"ÂÂÅÄÈÒÅ ÏÀÐÎËÜ", 159);
	enterPasswordText->setVisibility(false);
	enterPasswordText->setLocation(Vec2(0, 4));

	enterPasswordWrite = new Write();
	enterPasswordWrite->setLocation(Vec2(0, 6));

	enterNameWrite = new Write();
	enterNameWrite->setLocation(Vec2(0, 2));
}

SelectPlayer::~SelectPlayer()
{
	if (player != NULL) delete player;
	delete camera;
	delete addNewText;
	delete selectExistedText;
	delete enterNameText;
	delete enterPasswordText;
	delete enterPasswordWrite;
	delete enterNameWrite;

}

void SelectPlayer::OnKeyDown(int key)
{
	if (selectionActive)
	{
		switch (key)
		{
		case 'A':
			SetWriteState();
			enterNameWrite->onEndWrite.Bind(std::bind(&SelectPlayer::EnterName, this, std::placeholders::_1));
			onDataEntered.Bind(std::bind(&SelectPlayer::AddUser, this, std::placeholders::_1));
			break;
		case 'D':
			SetWriteState();
			enterNameWrite->onEndWrite.Bind(std::bind(&SelectPlayer::EnterName, this, std::placeholders::_1));
			onDataEntered.Bind(std::bind(&SelectPlayer::FindUser, this, std::placeholders::_1));
			break;
		}
	}
}

void SelectPlayer::Exit()
{
	onSelected.Call(selectedPlayerID);
}

void SelectPlayer::SetWriteState()
{
	addNewText->setVisibility(false);
	selectExistedText->setVisibility(false);
	enterNameText->setVisibility(true);

	enterNameWrite->setWriteState(true);

	selectionActive = false;
}

void SelectPlayer::EnterName(std::wstring name)
{
	player = new PlayerInfo(name, 0);

	enterPasswordText->setVisibility(true);
	enterPasswordWrite->setWriteState(true);

	enterPasswordWrite->onEndWrite.Bind(std::bind(&SelectPlayer::EnterPassword, this, std::placeholders::_1));
}

void SelectPlayer::EnterPassword(std::wstring password)
{
	player->setPassword(password);
	onDataEntered.Call(0);
}

void SelectPlayer::StartCycle()
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

	delete player;
	player = nullptr;
}

void SelectPlayer::AddUser(int i)
{
	if (users->AddPlayer(*player))
		onSelected.Call(selectedPlayerID);
	else StartCycle();
}

void SelectPlayer::FindUser(int i)
{
	if (users->Authorize(player->getName(), player->getPassword()))
		onSelected.Call(selectedPlayerID);
	else StartCycle();
}
