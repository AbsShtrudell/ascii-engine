#include "CollisionSet.h"

CollisionSet::CollisionSet()
{
}

CollisionSet::CollisionSet(CollideTable table)
{
	collisionSet = table;
}

CollisionSet::~CollisionSet()
{
}

void CollisionSet::set(CollideTable table)
{
	collisionSet = table;
}

const CollideTable CollisionSet::get()
{
	return collisionSet;
}

const CollideType CollisionSet::getCollideType(CollideObj key)
{
	return collisionSet.at(key);
}

void CollisionSet::setCollideState(CollideState state)
{
	collisionSet.at(state.first) = state.second;
}

const CollideTable CollisionSet::collisionSet_OverlapAll =
{CollideState(CollideObj::DYNAMIC,CollideType::OVELAP),
 CollideState(CollideObj::STATIC, CollideType::BLOCK),
 CollideState(CollideObj::PAWN,   CollideType::OVELAP)};

const CollideTable CollisionSet::collisionSet_BlockAll =
{CollideState(CollideObj::DYNAMIC,CollideType::BLOCK),
 CollideState(CollideObj::STATIC, CollideType::IGNORE_THIS),
 CollideState(CollideObj::PAWN,   CollideType::BLOCK)};

const CollideTable CollisionSet::collisionSet_IgnoreAll =
{CollideState(CollideObj::DYNAMIC,CollideType::IGNORE_THIS),
 CollideState(CollideObj::STATIC, CollideType::IGNORE_THIS),
 CollideState(CollideObj::PAWN,   CollideType::IGNORE_THIS)};

const CollideTable CollisionSet::collisionSet_OverlapOnlyPawn =
{CollideState(CollideObj::DYNAMIC,CollideType::IGNORE_THIS),
 CollideState(CollideObj::STATIC, CollideType::IGNORE_THIS),
 CollideState(CollideObj::PAWN,   CollideType::OVELAP)};

const CollideTable CollisionSet::collisionSet_BlockOnlyStatic =
{CollideState(CollideObj::DYNAMIC,CollideType::IGNORE_THIS),
 CollideState(CollideObj::STATIC, CollideType::BLOCK),
 CollideState(CollideObj::PAWN,   CollideType::IGNORE_THIS)};
