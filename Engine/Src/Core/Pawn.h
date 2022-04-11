#pragma once
#include "Object.h"
#include "InputSystem/InputSystem.h"

class Pawn : public Object, public InputListener
{
public:
	Pawn();
	~Pawn();

	virtual void OnKeyDown(int key) override;
	virtual void OnKeyUp(int key) override;
private:

};

