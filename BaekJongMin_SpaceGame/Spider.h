#pragma once
#include "Enemy.h"
#include "Player.h"

class Spider : public Enemy
{
public:
	Spider()
		:Enemy("�Ź� �ܰ���", 40, 15, WeaponType::EMP, WeaponType::Fire) {}
	Spider(const char* InName)
		:Enemy(InName, 40, 15, WeaponType::EMP, WeaponType::Fire) {}

};

