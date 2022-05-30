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
	Coin* coin1 = new Coin();
	coin1->setLocation(Vec2(25, -16));
	Coin* coin2 = new Coin();
	coin2->setLocation(Vec2(20, -20));
	Coin* coin3 = new Coin();
	coin3->setLocation(Vec2(-10, -10));
	Coin* coin4 = new Coin();
	coin4->setLocation(Vec2(-20, -15));

	Enemy* enemy = new Enemy(Vec2(30, -8));
	enemy->setLocation(Vec2( 100, -8));
	Enemy* enemy1 = new Enemy(Vec2(30, -8));
	enemy1->setLocation(Vec2(120, -8));
	Enemy* enemy2 = new Enemy(Vec2(30, -8));
	enemy2->setLocation(Vec2(150, -8));
}

World::~World()
{
}

void World::LoadMenu()
{
	World
}
