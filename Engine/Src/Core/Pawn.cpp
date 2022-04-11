#include "Pawn.h"

Pawn::Pawn()
{
	InputSystem::Get()->AddListener(this);
}

Pawn::~Pawn()
{
	InputSystem::Get()->RemoveListener(this);
}

void Pawn::OnKeyDown(int key)
{
}

void Pawn::OnKeyUp(int key)
{
}