#include "MainMenuControlller.h"

MainMenuControlller::MainMenuControlller()
{
	startGameText = new Text(L"ÍÀÆÌÈÒÅ \"SPACE\" ×ÒÎÁÛ ÍÀ×ÀÒÜ ÈÃĞÓ", 159);
	scoreMenuText = new Text(L"ÍÀÆÌÈÒÅ \"S\" ×ÒÎÁÛ ÎÒÊĞÛÒÜ ÒÀÁËÈÖÓ ËÈÄÅĞÎÂ", 159);
	scoreMenuText->setLocation(Vec2(0, 2));
	adminMenuText = new Text(L"ÍÀÆÌÈÒÅ \"A\" ×ÒÎÁÛ ÎÒÊĞÛÒÜ ÌÅÍŞ ÀÄÌÈÍÈÑÒĞÀÒÎĞÀ", 159);
	adminMenuText->setVisibility(admin);
	adminMenuText->setLocation(Vec2(0, 4));
	exitMenuText = new Text(L"ÍÀÆÌÈÒÅ \"ESC\" ×ÒÎÁÛ ÂÛÉÒÈ", 159);
	exitMenuText->setLocation(Vec2(0, 4));
}

MainMenuControlller::~MainMenuControlller()
{
	startGameText->Destroy();
	scoreMenuText->Destroy();
	adminMenuText->Destroy();
	exitMenuText->Destroy();
}

void MainMenuControlller::OnKeyUp(int key)
{
	switch (key)
	{
	case 32:
		onStart.Call(0);
		break;
	case 'S':
		onScoreMenu.Call(0);
		break;
	case 'A':
		if (admin)
		{
			onAdminMenu.Call(0);
		}
		break;
	}
}

void MainMenuControlller::setAdminState(bool value)
{
	admin = value;
	adminMenuText->setVisibility(admin);
}
