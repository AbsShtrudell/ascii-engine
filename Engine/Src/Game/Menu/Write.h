#pragma once
#include <Core/Text.h>
#include <Core/Pawn.h>
#include <System/Delegate.h>

class Write : public Pawn
{
public:
	Write();
	~Write();

	virtual void OnKeyUp(int key) override;

	void Clear();
	void setWriteState(bool value);
	bool getWriteState();
private:
	Text* text;
	bool end = true;
public:
	Delegate<std::wstring> onEndWrite;
};

