#include "PlayerAnimator.h"

PlayerAnimator::PlayerAnimator(Object* owner)
{
	if (owner != NULL)
		Attach(owner, this);

	std::string pathes[3] = {"Resources\\MarioBrosSprites\\mario\\mario_run1.spr", "Resources\\MarioBrosSprites\\mario\\mario_run2.spr", "Resources\\MarioBrosSprites\\mario\\mario_run3.spr"};
	runAnimation = new Animation();
	runAnimation->LoadAnimation(pathes, 3);
	runAnimation->setFrameLength(3);
	jumAnimation = new Animation();
	jumAnimation->ResizeAnimation(1);
	jumAnimation->LoadFrame("Resources\\MarioBrosSprites\\mario\\mario_jump.spr", 0);
	deathAnimation = new Animation();
	deathAnimation->ResizeAnimation(1);
	deathAnimation->LoadFrame("Resources\\MarioBrosSprites\\mario\\mario_death.spr", 0);
	idleAnimation = new Animation();
	idleAnimation->ResizeAnimation(1);
	idleAnimation->LoadFrame("Resources\\MarioBrosSprites\\mario\\mario_idle.spr", 0);

	setCurrentAnimation(idleAnimation, false);
}

PlayerAnimator::~PlayerAnimator()
{
	delete runAnimation;
	delete jumAnimation;
	delete deathAnimation;
	delete idleAnimation;
}

void PlayerAnimator::CheckAnimatorState()
{
	if (dead)
	{
		setCurrentAnimation(deathAnimation, false);
		return;
	}
	if (!onGround)
	{
		setCurrentAnimation(jumAnimation, (moving < 0));
		return;
	}
	if (onGround)
	{
		if (moving == 0)
		{
			setCurrentAnimation(idleAnimation, false);
			return;
		}
		else
		{
			if(getCurrentAnimation() != runAnimation ||(getCurrentAnimation() == runAnimation && isRotated() != (moving < 0)))
				setCurrentAnimation(runAnimation, (moving < 0));
		}
	}
}

void PlayerAnimator::setOnGroundState(bool value)
{
	onGround = value;
}

void PlayerAnimator::setDeathState(bool value)
{
	dead = value;
}

void PlayerAnimator::setMovingState(int value)
{
	moving = value;
}
