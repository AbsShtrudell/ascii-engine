#include "Sprite.h"

Sprite::Sprite(int w, int h, std::string path)
{
	SetSize(w, h);
	LoadFrame(path, 0);

	
	AllSprites.push_back(this);
	ZSort();
}

Sprite::Sprite()
{
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
	for(int i = 0; i < (int)frames.size(); i++) 
		delete[]frames[i];
	frames.clear();
}

const Vec2 Sprite::GetSize()
{
	return size;
}

const int Sprite::GetZOrder()
{
	return Z;
}

const int Sprite::GetCurrentFrame()
{
	return currentFrame;
}

void Sprite::ClearFrame(int frame)
{
	delete[]frames[frame];
	frames.erase(std::next(frames.begin(),frame));
}

void Sprite::LoadFrame(std::string path, int frame)
{
	wchar_t** fr;
	
	std::wifstream textureFile(path, std::ios::in);
	fr = new wchar_t* [size.y];
	for (int i = 0; i < size.y; i++)
	{
		fr[i] = new wchar_t[size.x];
		for (int j = 0; j < size.x; j++)
		{
			textureFile >> fr[i][j];
			if (fr[i][j] == L'·') fr[i][j] = L' ';
		}
	}
	textureFile.close();

	if ((frame <= frames.size() - 1) && frames.size() != 0)
	{
		ClearFrame(frame);
		frames[frame] = fr;
	}
	else frames.push_back(fr);

	
}

int Sprite::SetZOrder(int newValue)
{
	Z = newValue;
	return Z;
}

void Sprite::SetSize(Vec2 sz)
{
	size = sz;
}

void Sprite::SetSize(int x, int y)
{
	size = Vec2(x, y);
}

void Sprite::SetFrame(int frame)
{
	if (frame > frames.size() - 1)
		currentFrame = frames.size() - 1;
	else currentFrame = frame;
}

int Sprite::NextFrame()
{
	if (currentFrame + 1 > frames.size() - 1)
		currentFrame = 0;
	else currentFrame++;
	return currentFrame;
}

void Sprite::ZSort()
{
	if (AllSprites.size() == 0) return;
	for (size_t i = 0; i < AllSprites.size() - 1; i++)
		for (size_t j = 0; j < AllSprites.size() - i - 1; j++)
		{
			if (AllSprites[j]->GetZOrder() > AllSprites[j + 1]->GetZOrder())
				std::swap(AllSprites[j], AllSprites[j + 1]);
		}
}

std::vector<Sprite*> Sprite::GetAllSprites()
{
	return AllSprites;
}