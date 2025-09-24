#pragma once
#include<set>
#include "Actor.h"
#include "Enemy.h"
#include "Weapon.h"




class Player : public Actor
{
public:
	Player() = default;
	Player(const char* InName, int InHealth, int InAttackPower, int InFood = 5, int InOxygen = 100)
		:Actor(InName, InHealth, InAttackPower), Food(InFood), Oxygen(InOxygen) {}

	void ConsumeFood();
	void ConsumeOxygen(int Amount);
	void AddFood(int Amount);
	void AddOxygen(int Amount);

	int GetFood() const { return Food; }
	int GetOxygen() const { return Oxygen; }


	void ObtainAlienBook();
	void IncreaseEnemyAffinity(Enemy& enemy, int BaseValue);

	bool HasWeapon(WeaponType weapon) const
	{
		return Weapons.contains(weapon);
	}

	void AddWeapon(WeaponType Weapon);

	int WeaponCount() const { return (int)Weapons.size(); }

private:
	int Food = 5;
	int Oxygen = 100;
	const int HungerPenalty = 20; 

	int AlienBook = 0;

	std::set<WeaponType> Weapons;
};
