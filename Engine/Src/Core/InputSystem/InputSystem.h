#pragma once
#include "InputListener.h"
#include <map>

class InputSystem
{
public:
	InputSystem();
	~InputSystem();

	void Update();
	void AddListener(InputListener* listener);
	void RemoveListener(InputListener* listener);

	static InputSystem* Get();

private:
	std::map<InputListener*, InputListener*> ListenersList;
	unsigned char KeyState[256] = {};
	unsigned char OldKeyState[256] = {};
};

