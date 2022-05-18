#pragma once
#include <map>


enum class CollideType { IGNORE_THIS, BLOCK, OVELAP };
enum class CollideObj { STATIC, DYNAMIC, PAWN };

typedef std::map<CollideObj, CollideType> CollideTable;
typedef std::pair<CollideObj, CollideType> CollideState;

class CollisionSet
{
public:
	CollisionSet();
	CollisionSet(CollideTable table);
	~CollisionSet();

	const CollideTable get();
	const CollideType getCollideType(CollideObj key);
	void set(CollideTable table);
	void setCollideState(CollideState state);

	static const CollideTable collisionSet_OverlapAll;
	static const CollideTable collisionSet_BlockAll;
	static const CollideTable collisionSet_IgnoreAll;
	static const CollideTable collisionSet_OverlapOnlyPawn;
	static const CollideTable collisionSet_BlockOnlyStatic;
private:
	CollideTable collisionSet = collisionSet_BlockAll;
};