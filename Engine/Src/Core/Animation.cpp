#include "Animation.h"

Animation::Animation()
{
}

Animation::~Animation()
{
	for (auto frame : frames)
	{
		delete frame;
	}
}

Texture* Animation::getCurrentFrame() const
{
	return frames.at(time/ frameLength);
}


int Animation::getTime() const
{
	return time;
}

void Animation::setCurrentFrame(int index)
{
	if (index >= 0 && index < frames.size())
		time = index * frameLength;
}

void Animation::setFrameLength(int value)
{
	if (value >= 1)
		frameLength = value;
}

void Animation::Play()
{
	if (time >= (frames.size()) * frameLength - 1)time = 0;
	else time++;
}

void Animation::ResizeAnimation(int newSize)
{
	if (newSize > 0)
	{
		frames.resize(newSize, NULL);
		if (time >= (frames.size() - 1) * frameLength) time = (frames.size() - 1) * frameLength;
	}
}

void Animation::LoadFrame(std::string path, int frameIndex)
{
	if (frameIndex >= 0 && frameIndex < frames.size())
	{
		TextureReader::ReadFile(path, frames.at(frameIndex));
	}
}

void Animation::SaveFrame(std::string path, int frameIndex)
{
	if (frameIndex >= 0 && frameIndex < frames.size() && frames.at(frameIndex) != NULL)
	{
		TextureWriter::WriteFile(path, frames.at(frameIndex));
	}
}

void Animation::LoadAnimation(std::string pathes[], int framesAmount)
{
	if (framesAmount >= 0)
	{
		frames.resize(framesAmount, nullptr);
		for (int i = 0; i < framesAmount; i++)
		{
			LoadFrame(pathes[i], i);
		}
	}
}

void Animation::LoadAnimation(std::string pathes[], int begin, int end)
{
	if (begin >= 0 && end > begin)
	{
		if (frames.size() - 1 < end) ResizeAnimation(end + 1);
		for (int i = begin; i < end; i++)
		{
			LoadFrame(pathes[i], i);
		}
	}
}