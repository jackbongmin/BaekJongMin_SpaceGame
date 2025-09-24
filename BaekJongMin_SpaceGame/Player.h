#pragma once
#include "Actor.h"
class Player : public Actor
{
public:
	Player() = default;
	Player(const char* InName, int InHealth, int InAttackPower)
		:Actor(InName, InHealth, InAttackPower) {}


};

