#pragma once

class ICanBattle
{
public:
	virtual ~ICanBattle() {};

	virtual void ApplyAttack(ICanBattle* InTarget) = 0;
	virtual void TakeDamage(int InDamage) = 0;


};