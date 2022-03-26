#include "InputSystem.h"
#include <Windows.h>

InputSystem::InputSystem()
{
}

InputSystem::~InputSystem()
{
}

void InputSystem::Update()
{
	memset(KeyState, 0, sizeof(256));
	GetKeyState(0);
	if (GetKeyboardState(KeyState))
	{
		for (unsigned int i = 0; i < 256; i++)
		{
			if (KeyState[i] & 0x80) //KEY IS DOWN
			{
				std::map<InputListener*, InputListener*>::iterator it = ListenersList.begin();

				while (it != ListenersList.end())
				{
					it->second->OnKeyDown(i);
					it++;
				}
			}
			else //KEY IS UP
			{
				if (KeyState[i] != OldKeyState[i])
				{
					std::map<InputListener*, InputListener*>::iterator it = ListenersList.begin();

					while (it != ListenersList.end())
					{
						it->second->OnKeyUp(i);
						it++;
					}
				}
			}
		}
		memcpy(OldKeyState, KeyState, sizeof(unsigned char) * 256);
	}
}

void InputSystem::AddListener(InputListener* listener)
{
	ListenersList.insert(std::make_pair<InputListener*, InputListener*>
		(std::forward<InputListener*>(listener), std::forward<InputListener*>(listener)));
}

void InputSystem::RemoveListener(InputListener* listener)
{
	std::map<InputListener*, InputListener*>::iterator it = ListenersList.find(listener);

	if (it != ListenersList.end())
	{
		ListenersList.erase(it);
	}
}

InputSystem* InputSystem::Get()
{
	static InputSystem system;
	return &system;
}
