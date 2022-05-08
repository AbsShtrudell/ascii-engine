#pragma once
#include <Math/Matrix.h>
#include <FileManagment/TextureReader.h>
#include <FileManagment/TextureWriter.h>

class Animation
{
public:
	Animation();
	~Animation();

	Texture* getCurrentFrame() const;
	int getTime() const;

	void setCurrentFrame(int index);
	void setFrameLength(int value);

	void Play();

	void ResizeAnimation(int newSize);

	void LoadFrame(std::string path, int frameIndex);
	void SaveFrame(std::string path, int frameIndex);

	void LoadAnimation(std::string pathes[], int framesAmount);
	void LoadAnimation(std::string pathes[], int begin, int end);

private:
	std::vector<Texture*> frames;
	int frameLength = 1;
	int time = 0;
};

