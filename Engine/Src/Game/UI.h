#pragma once
#include <Core/Text.h>
#include <Core/Sprite.h>

class UI : public Object
{
public:

	UI();
	~UI();

	void setCoinsCounterText(std::wstring text);

private:
	Sprite* coinicon = nullptr;
	Text* coinscounter = nullptr;
	Text* level = nullptr;
};

