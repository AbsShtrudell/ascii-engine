#include "Animator.h"

Animator::Animator()
{
}

Animator::~Animator()
{
}

void Animator::OnDrawn()
{
    currentAnimation->Play();
}

void Animator::OnUpdate()
{
    CheckAnimatorState();
}

void Animator::setCurrentAnimation(Animation* animation, bool rotated)
{
    animation->setCurrentFrame(0);
    currentAnimation = animation;
    this->rotated = rotated;
}

bool Animator::isRotated()
{
    return rotated;
}

const Animation* Animator::getCurrentAnimation()
{
    return currentAnimation;
}

const Vec2 Animator::getSize()
{
    return currentAnimation->getCurrentFrame()->getSize();
}

const int Animator::getZOrder()
{
    return Z;
}

Texture Animator::getTexture()
{
    if(rotated)
        return *currentAnimation->getCurrentFrame()->getInverted().get();
    else
        return *currentAnimation->getCurrentFrame();
}

const Vec2 Animator::getDrawLoacation()
{
    return getWorldLocation();
}

const bool Animator::isVisible()
{
    return visible;
}

void Animator::setZOrder(int newValue)
{
    Z = newValue;
}

void Animator::setVisibility(bool visibility)
{
    visible = visibility;
}
