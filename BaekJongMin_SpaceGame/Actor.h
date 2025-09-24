#pragma once
#include<string>
#include "ICanBattle.h"

class Actor : public ICanBattle
{
public:
	Actor() = default;
	Actor(const char* InName, int InHealth, int InAttackPower)
		: Name(InName), Health(InHealth), MaxHealth(InHealth), AttackPower(InAttackPower)
	{
	}

	virtual void ApplyAttack(ICanBattle* InTarget) override;
	virtual void TakeDamage(int InDamage) override;

	inline bool IsAlive() { return Health > 0; }

	inline const std::string& GetName() const { return Name; }
	const int GetHealth() const { return Health; }
	const int GetMaxHealth() const { return MaxHealth; }
	const int GetAttackPower() const { return AttackPower; }

private:

	inline void SetHealth(int InHealth)
	{
		if (InHealth > MaxHealth)
		{
			Health = MaxHealth;
		}
		else
		{
			Health = InHealth;
		}
	}

	std::string Name = "ø¢≈Õ";
	int Health = 100;
	int MaxHealth = 100;
	int AttackPower = 15;
};

