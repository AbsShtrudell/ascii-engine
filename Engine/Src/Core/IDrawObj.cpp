#include "IDrawObj.h"

IDrawObj::IDrawObj()
{
	AllDrawObjects.push_back(this);

	//ZSort();
}

IDrawObj::~IDrawObj()
{
	for (size_t i = 0; i < AllDrawObjects.size(); i++)
		if (this == AllDrawObjects[i])
		{
			AllDrawObjects.erase(AllDrawObjects.begin() + i);
			break;
		}

	IDrawObj::ZSort();
}

void IDrawObj::ZSort()
{
	if (AllDrawObjects.size() == 0) return;
	for (size_t i = 0; i < AllDrawObjects.size() - 1; i++)
		for (size_t j = 0; j < AllDrawObjects.size() - i - 1; j++)
		{
			if (AllDrawObjects[j]->getZOrder() > AllDrawObjects[j + 1]->getZOrder())
				std::swap(AllDrawObjects[j], AllDrawObjects[j + 1]);
		}
}

DrawObjects IDrawObj::getAllDrawObjects()
{
	return IDrawObj::AllDrawObjects;
}

DrawObjects IDrawObj::AllDrawObjects;
