#include "Sprite.h"

Sprite::Sprite(std::string path, Object* owner)
{
	LoadSprite(path);
	if (owner != NULL)
	{
		Attach(owner, this);
	}
}

Sprite::Sprite()
{
}

Sprite::~Sprite()
{
	if (texture != NULL) delete texture;
}

void Sprite::OnDrawn()
{
}

const Vec2 Sprite::getSize()
{
	return size;
}

const int Sprite::getZOrder()
{
	return Z;
}

Matrix<CSymb>* Sprite::getTexture()
{
	return texture;
}

const Vec2 Sprite::getDrawLoacation()
{
	return getWorldLocation();
}

void Sprite::setZOrder(int newValue)
{
	Z = newValue;
}

void Sprite::setSize(Vec2 sz)
{
	size = sz;
	if (texture == NULL) texture = new Texture(sz, {L' ', 7});
	else texture->setSize(sz);
	
}

void Sprite::setSize(int x, int y)
{
	size = Vec2(x, y);
	if (texture == NULL) texture = new Texture(Vec2(x, y), { L' ', 7 });
	else texture->setSize(Vec2(x, y));
}

const bool Sprite::isVisible()
{
	return visible;
}

void Sprite::setVisibility(bool visibility)
{
	visible = visibility;
}

void Sprite::LoadSprite(std::string path)
{
	TextureReader::ReadFile(path, texture);
	if (texture != NULL) size = texture->getSize();
	else setSize(0, 0);
}

void Sprite::SaveSprite(std::string path)
{
	TextureWriter::WriteFile(path, texture);
}
