#pragma once
#include <InputSystem/InputListener.h>
#include <list>

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
	std::list<InputListener*> ListenersList;
	unsigned char KeyState[256] = {};
	unsigned char OldKeyState[256] = {};
};

