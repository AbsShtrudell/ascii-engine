#include "UI.h"

UI::UI()
{
	coinicon = new Sprite("Resources\\MarioBrosSprites\\coin_icon.spr", this);
	coinscounter = new Text(L"0", 158);
	AttachChild(coinscounter);
	level = new Text(L"спнбемэ-1", 158);
	AttachChild(level);

	coinicon->setLocation(Vec2(2, 2));
	coinscounter->setLocation(Vec2(3 + coinicon->getSize().x, 4));
}

UI::~UI()
{
	delete coinicon;
	delete coinscounter;
	delete level;
}

void UI::setCoinsCounterText(std::wstring text)
{
	coinscounter->setText(text);
}
