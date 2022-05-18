#pragma once
#include <Core/Pawn.h>
#include <System/Delegate.h>

class SelectMenuController : public Pawn
{
public:

	SelectMenuController(){}
	~SelectMenuController(){}

	virtual void OnKeyUp(int key) override;

	bool IsActive()
	{
		return active;
	}

	void setActive(bool value)
	{
		active = value;
	}

private:
	bool active = true;

public:
	Delegate<int> onAuthorization;
	Delegate<int> onRegistration;
	Delegate<int> onExit;
};

