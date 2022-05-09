#include "EnemyAnimator.h"

EnemyAnimator::EnemyAnimator(Object* owner)
{
	if (owner != NULL)
		Attach(owner, this);

	std::string pathes[3] = { "Resources\\MarioBrosSprites\\gumbo.spr", "Resources\\MarioBrosSprites\\gumbo.spr" };
	moveAnimation = new Animation();
	moveAnimation->LoadAnimation(pathes, 2);
	moveAnimation->getCurrentFrame()->Invert();
	moveAnimation->setFrameLength(6);

	deathAnimation = new Animation();
	deathAnimation->ResizeAnimation(1);
	deathAnimation->LoadFrame("Resources\\MarioBrosSprites\\mario\\mario_death.spr", 0);
	
	setCurrentAnimation(moveAnimation, false);
}

EnemyAnimator::~EnemyAnimator()
{
	delete moveAnimation;
	delete deathAnimation;
}

void EnemyAnimator::CheckAnimatorState()
{
	if (dead)
	{
		setCurrentAnimation(deathAnimation, false);
		return;
	}
	
	if (getCurrentAnimation() != moveAnimation || (getCurrentAnimation() == moveAnimation && isRotated() != (moving < 0)))
		setCurrentAnimation(moveAnimation, (moving < 0));
}

void EnemyAnimator::setDeathState(bool value)
{
	dead = value;
}

void EnemyAnimator::setMovingState(int value)
{
	moving = value;
}
