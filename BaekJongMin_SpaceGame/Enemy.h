#pragma once
#include "Actor.h"
#include"Player.h"
class Enemy : public Actor
{
public:
	Enemy()
		:Actor("Àû", 40, 15) {}
	Enemy(const char* InName)
		:Actor(InName, 40, 15) {}
	Enemy(const char* InName, int InHealth, int InAttackPower, WeaponType Strong, WeaponType Weak)
		: Actor(InName, InHealth, InAttackPower), StrongType(Strong), WeakType(Weak){}

	inline int GetDropItem() const { return DropItem; }
	inline int GetAffinity() const { return Affinity; }
	inline void AddAffinity(int value) { Affinity += value; }

	WeaponType GetStrongType() const { return StrongType; }
	WeaponType GetWeakType() const { return WeakType; }

protected:
	int DropItem = 0;
	int Affinity = 50;
	WeaponType StrongType;
	WeaponType WeakType;

};

