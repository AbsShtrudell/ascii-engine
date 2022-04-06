#include "Sprite.h"

Sprite::Sprite(std::string path)
{
	symbolMatrix = nullptr;

	SpriteReader::LoadSprite(path, this);

	AllSprites.push_back(this);
	ZSort();
}

Sprite::Sprite()
{
	symbolMatrix = nullptr;

	AllSprites.push_back(this);
	ZSort();
}

Sprite::~Sprite()
{
	for (size_t i = 0; i < AllSprites.size(); i++)
		if (this == AllSprites[i])
		{
			AllSprites.erase(AllSprites.begin() + i);
			break;
		}

	ZSort();

	if (symbolMatrix != NULL) delete symbolMatrix;
}

const Vec2 Sprite::getSize()
{
	return size;
}

const int Sprite::getZOrder()
{
	return Z;
}

Matrix<CSymb> Sprite::getSymbMatrix()
{
	return *symbolMatrix;
}

int Sprite::setZOrder(int newValue)
{
	Z = newValue;
	return Z;
}

void Sprite::setSize(Vec2 sz)
{
	size = sz;
	if (symbolMatrix == NULL) symbolMatrix = new Matrix<CSymb>(sz, {L' ', 7});
	symbolMatrix->setSize(sz);
	
}

void Sprite::setSize(int x, int y)
{
	size = Vec2(x, y);
	if (symbolMatrix != NULL) symbolMatrix->setSize(Vec2(x, y));
}

const bool Sprite::isVisible() const
{
	return visible;
}

void Sprite::setVisibility(bool visibility)
{
	visible = visibility;
}

void Sprite::LoadSprite(std::string path)
{
	SpriteReader::LoadSprite(path, this);
}

void Sprite::SaveSprite(std::string path)
{
	SpriteWriter::WriteSprite(path, this);
}

void Sprite::ZSort()
{
	if (AllSprites.size() == 0) return;
	for (size_t i = 0; i < AllSprites.size() - 1; i++)
		for (size_t j = 0; j < AllSprites.size() - i - 1; j++)
		{
			if (AllSprites[j]->getZOrder() > AllSprites[j + 1]->getZOrder())
				std::swap(AllSprites[j], AllSprites[j + 1]);
		}
}

std::vector<Sprite*> Sprite::getAllSprites()
{
	return AllSprites;
}

std::vector<Sprite*> Sprite::AllSprites = {};

void Sprite::SpriteReader::LoadSprite(std::string path, Sprite* sprite)
{
	std::ifstream file;
	file.open(path, std::ios_base::binary);

	Vec2 sz;

	if (file.is_open())
	{
		file >> sz.x >> sz.y;

		sprite->setSize(sz.x, sz.y);

		if (sprite->symbolMatrix != NULL)
		{
			delete sprite->symbolMatrix;
		}
		sprite->symbolMatrix = new Matrix<CSymb>(sprite->getSize(), {L' ', 7});

		for (int i = 0; i < sprite->getSize().x; i++)
		{
			for (int j = 0; j < sprite->getSize().y; j++)
			{
				file.get() >> sprite->symbolMatrix->at(i, j).symbol;
				file.get() >> sprite->symbolMatrix->at(i, j).color;
			}
		}
	}
	else throw(std::exception("Warning! Can't load file"));//написать свои исключения
}

void Sprite::SpriteWriter::WriteSprite(std::string path, Sprite* sprite)
{
	std::ofstream file;
	file.open(path, std::ios::out | std::ios::binary);

	if (file.is_open())
	{
		file << sprite->getSize().x << sprite->getSize().y;

		if (sprite->symbolMatrix != NULL)
		{
			for (int i = 0; i < sprite->getSize().x; i++)
			{
				for (int j = 0; j < sprite->getSize().y; j++)
				{
					file << sprite->symbolMatrix->at(i, j).symbol;
					file << sprite->symbolMatrix->at(i, j).color;
				}
			}
		}
	}
	else throw(std::exception("Warning! Can't load file"));//написать свои исключения
}
