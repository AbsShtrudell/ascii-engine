#include "Sprite.h"

Sprite::Sprite(std::string path)
{
	LoadSprite(path);
	CollisionSystem::get()->AddCollider(this);
}

Sprite::Sprite()
{
	CollisionSystem::get()->AddCollider(this);
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
	return GetWorldLocation();
}

const Vec2 Sprite::getCollideLocation()
{
	return GetWorldLocation();
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

void Sprite::OnCollide(IColliderResp* obj)
{

}

void Sprite::UpdateGravity(Vec2 direction)
{
	AddLocation(direction);
}

void Sprite::OnKeyDown(int key)
{
	switch (key)
	{
	case'W':
		AddLocation(0, -1);
		break;
	case'S':
		AddLocation(0, 1);
		break;
	case'A':
		AddLocation(-1, 0);
		break;
	case'D':
		AddLocation(1, 0);
		break;
	case 32:
		AddLocation(0, -3);
		collider->setVelocity(Vec2(0, -3));
		break;
	}
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
