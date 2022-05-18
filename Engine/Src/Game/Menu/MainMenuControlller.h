#pragma once
#include <Core/Pawn.h>
#include <Core/Camera.h>
#include <Game/Menu/Write.h>

class MainMenuControlller : public Pawn
{
public:
	MainMenuControlller();
	~MainMenuControlller();

	virtual void OnKeyUp(int key) override;

	void setAdminState(bool value);
private:
	Text* startGameText;
	Text* scoreMenuText;
	Text* adminMenuText;
	Text* exitMenuText;

	bool admin = false;
public:
	Delegate<int> onStart;
	Delegate<int> onScoreMenu;
	Delegate<int> onAdminMenu;
};

