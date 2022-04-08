#pragma once
#include "Object.h"
#include "IDrawObj.h"
#include "../Matrix.h"
#include "../FileManagment/TextureReader.h"
#include "../FileManagment/TextureWriter.h"

class FlipBook : protected IDrawObj, public Object
{
public:
	FlipBook();
	~FlipBook();

	virtual void OnDrawn() override;

	virtual const Vec2 getSize() override;
	virtual const int getZOrder() override;
	virtual Texture* getTexture() override;
	const int getCurrentFrame() const;
	virtual const Vec2 getDrawLoacation() override;
	virtual const bool isVisible() override;

	virtual void setZOrder(int newValue) override;
	virtual void setSize(Vec2 sz) override;
	virtual void setSize(int x, int y) override;
	virtual void setVisibility(bool visibility) override;
	void setCurrentFrame(int newFrame);

	void NextFrame();

	void ResizeFlipBook(int newSize);

	void LoadFrame(std::string path, int frameIndex);
	void SaveFrame(std::string path, int frameIndex);

	void LoadFlipbook(std::string pathes[], int framesAmount);
	void LoadFlipBook(std::string pathes[], int begin, int end);

private:
	std::vector<Texture*> frames;
	int currentFrame = 0;
};

