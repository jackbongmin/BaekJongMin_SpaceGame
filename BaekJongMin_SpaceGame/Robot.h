#pragma once
#include "Enemy.h"
class Robot : public Enemy
{
public:
	Robot()
		:Enemy("�ܰ� �κ�", 50, 15, WeaponType::Hit, WeaponType::EMP) {}
	Robot(const char* InName)
		:Enemy(InName, 50, 15, WeaponType::Hit, WeaponType::EMP) {}

};

