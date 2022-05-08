#pragma once
#include <Core/Animator.h>

class PlayerAnimator : public Animator
{
public:
	PlayerAnimator(Object* owner);
	~PlayerAnimator();

	void CheckAnimatorState() override;

	void setOnGroundState(bool value);
	void setDeathState(bool value);
	void setMovingState(int value);

private:
	Animation* runAnimation;
	Animation* jumAnimation;
	Animation* deathAnimation;
	Animation* idleAnimation;

	bool onGround;
	bool dead;
	int moving = 0;
};

