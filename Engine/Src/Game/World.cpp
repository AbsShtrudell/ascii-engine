#include "World.h"

World::World()
{
	for (int i = 0; i < 20; i++)
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
}
