#pragma once
#include "Enemy.h"
class Spider : public Enemy
{
public:
	Spider()
		:Enemy("거미 외계인", 40, 15) {}
	Spider(const char* InName)
		:Enemy(InName, 40, 15) {}

};

