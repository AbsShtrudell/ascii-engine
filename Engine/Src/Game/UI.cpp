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

	gameOverText = new Text(L"GAME OVER", 158);
	gameOverText->setLocation(Vec2(90, 25));
	gameOverText->setVisibility(false);
	AttachChild(gameOverText);
}

UI::~UI()
{
	delete coinicon;
	delete coinscounter;
	delete level;
	delete gameOverText;
}

void UI::setCoinsCounterText(std::wstring text)
{
	coinscounter->setText(text);
}

void UI::setGameOverState(bool value)
{
	gameOverText->setVisibility(value);
}
