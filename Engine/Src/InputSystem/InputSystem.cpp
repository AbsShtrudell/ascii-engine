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
			if (KeyState[i] & 0x80)
			{
				for(const auto& listener : ListenersList)
					listener->OnKeyDown(i);
			}
			else
			{
				if (KeyState[i] != OldKeyState[i])
				{
					for (const auto& listener : ListenersList)
						listener->OnKeyUp(i);
				}
			}
		}
		memcpy(OldKeyState, KeyState, sizeof(unsigned char) * 256);
	}
}

void InputSystem::AddListener(InputListener* listener)
{
	ListenersList.push_back(listener);
}

void InputSystem::RemoveListener(InputListener* listener)
{
	auto it = find(ListenersList.begin(), ListenersList.end(), listener);

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
