#pragma once
#include "Enemy.h"
class Robot : public Enemy
{
public:
	Robot()
		:Enemy("�ܰ� �κ�", 50, 10) {}
	Robot(const char* InName)
		:Enemy(InName, 50, 10) {}

};

