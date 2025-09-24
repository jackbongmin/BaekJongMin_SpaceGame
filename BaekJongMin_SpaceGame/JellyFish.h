#pragma once
#include "Enemy.h"
class JellyFish : public Enemy
{
public :
	JellyFish()
		: Enemy("해파리 외계인", 30, 20, WeaponType::Fire, WeaponType::EMP) {}
	JellyFish(const char* InName)
		: Enemy("해파리 외계인", 30, 20, WeaponType::Fire, WeaponType::EMP) {}
};

