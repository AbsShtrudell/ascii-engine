#include "MainMenuControlller.h"

MainMenuControlller::MainMenuControlller()
{
	startGameText = new Text(L"ÍÀÆÌÈÒÅ \"SPACE\" ×ÒÎÁÛ ÍÀ×ÀÒÜ", 159);
	scoreMenuText = new Text(L"ÍÀÆÌÈÒÅ \"A\" ×ÒÎÁÛ ÎÒÊÐÛÒÜ ÒÀÁËÈÖÓ ÙÅÒÀ", 159);
	scoreMenuText->setLocation(Vec2(0, 2));

	camera = new Camera(this);
}

MainMenuControlller::~MainMenuControlller()
{
	delete camera;
	delete startGameText;
	delete scoreMenuText;
}

void MainMenuControlller::OnKeyUp(int key)
{
	switch (key)
	{
	case 32:
		onStart.Call(0);
		break;
	}
}
