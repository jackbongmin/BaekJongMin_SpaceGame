#pragma once
#include "Enemy.h"
class JellyFish : public Enemy
{
public :
	JellyFish()
		: Enemy("���ĸ� �ܰ���", 30, 20, WeaponType::Fire, WeaponType::EMP) {}
	JellyFish(const char* InName)
		: Enemy("���ĸ� �ܰ���", 30, 20, WeaponType::Fire, WeaponType::EMP) {}
};

