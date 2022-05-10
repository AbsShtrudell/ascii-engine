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

private:
	Camera* camera;
	Text* startGameText;
	Text* scoreMenuText;

public:
	Delegate<int> onStart;
};

