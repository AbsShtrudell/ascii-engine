#include "Text.h"

Text::Text(std::wstring text, int color)
{
	textSprite = new Texture(Vec2(1, 1), { L' ', 7 });
	setColor(color);
	setText(text);
}

Text::Text()
{
	textSprite = new Texture(Vec2(1, 1), { L' ', 7 });
	setText(L" ");
}

Text::~Text()
{
	delete textSprite;
}

void Text::OnDrawn()
{
}

const Vec2 Text::getSize()
{
	return textSprite->getSize();
}

const int Text::getZOrder()
{
	return Z;
}

Texture Text::getTexture()
{
	return *textSprite;
}

const Vec2 Text::getDrawLoacation()
{
	return getWorldLocation();
}

const bool Text::isVisible()
{
	return visible;
}

void Text::setZOrder(int newValue)
{
	Z = newValue;
}

void Text::setVisibility(bool visibility)
{
	visible = visibility;
}

void Text::setText(std::wstring text)
{
	CSymb symb;
	symb.color = color;
	textSprite->setSize(Vec2(text.size(), 1));
	for (int i = 0; i < text.size(); i++)
	{
		symb.symbol = text.at(i);
		textSprite->at(i, 0) = symb;
	}
}

void Text::setColor(int value)
{
	if (value > 255 && value < 0) return;
	color = value;
}
