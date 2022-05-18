#include "SelectMenuController.h"

void SelectMenuController::OnKeyUp(int key)
{
	if (active)
	{
		switch (key)
		{
		case '1':
			onAuthorization.Call(0);
			break;
		case '2':
			onRegistration.Call(0);
			break;
		case '3':
			onExit.Call(0);
		}
	}
}
