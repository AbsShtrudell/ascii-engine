#pragma once
#include <Core/Text.h>
#include <Core/Sprite.h>
#include <string>

class UI : public Object
{
public:

	UI();
	~UI();

	void setCoinsCounterText(std::wstring text);
	void setGameOverState(bool value);

private:
	Sprite* coinicon = nullptr;
	Text* coinscounter = nullptr;
	Text* level = nullptr;
	Text* gameOverText = nullptr;
};

