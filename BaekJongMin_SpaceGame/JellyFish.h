#pragma once
#include "Enemy.h"
class JellyFish : public Enemy
{
public :
	JellyFish()
		: Enemy("���ĸ� �ܰ���", 30, 20) {}
	JellyFish(const char* InName)
		: Enemy("���ĸ� �ܰ���", 30, 20) {}
};

