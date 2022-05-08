#include "World.h"

World::World()
{
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			Box* box = new Box();
			box->setLocation(Vec2(i * 16, j * 8));
		}
	}
	Player* player = new Player();
	player->setLocation(Vec2(0, -8));

	Coin* coin = new Coin();
	coin->setLocation(Vec2(16, -8));

	Text* text = new Text(L"LEVEL-1", 158);
	player->AttachChild(text);
	text->setLocation(Vec2(-40, -30));
}
