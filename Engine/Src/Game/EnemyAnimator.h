#pragma once
#include <Core/Animator.h>

class EnemyAnimator : public Animator
{
public:
	EnemyAnimator(Object* owner);
	~EnemyAnimator();

	void CheckAnimatorState() override;

	void setDeathState(bool value);
	void setMovingState(int value);

private:
	Animation* moveAnimation;
	Animation* deathAnimation;

	bool dead;
	int moving = 0;
};

