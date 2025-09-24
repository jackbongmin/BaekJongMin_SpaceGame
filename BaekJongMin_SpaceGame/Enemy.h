#pragma once
#include "Actor.h"
class Enemy : public Actor
{
public:
	Enemy()
		:Actor("Àû", 40, 15) {}
	Enemy(const char* InName)
		:Actor(InName, 40, 15) {}
	Enemy(const char* InName, int InHealth, int InAttackPower)
		: Actor(InName, InHealth, InAttackPower){}

	inline int GetDropItem() const { return DropItem; }
	inline int GetAffinity() const { return Affinity; }
	inline void AddAffinity(int value) { Affinity += value; }

protected:
	int DropItem = 0;
	int Affinity = 50;
};

