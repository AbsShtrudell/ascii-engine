#pragma once
#include <Core/Pawn.h>
#include <Core/Camera.h>
#include <Game/Menu/Write.h>
#include <Game/Menu/UserContainer.h>
#include <map>
#include <algorithm>

class PlayersLeaderBoard : public Pawn
{
public:
	PlayersLeaderBoard(UserContainer* users);
	~PlayersLeaderBoard();

	void SortPlayers();
	void ReplacePlayers();
private:
	UserContainer* users;

	Camera* camera;
	Text* leadersText;
	std::map<Text*, Text*> leaderLinesText;

	Delegate<int> onExit;
};

