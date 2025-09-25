#pragma once
#include"Player.h"
#include"Enemy.h"

class Exploreclass
{
public:

	void Explore_MeetEnemy(Player& player);
	void MeetEnemy_BattleEvent(Player& player, Enemy* pEnemy);
	int CalculateWeaponDamage(Player& player, Enemy& enemy, WeaponType weapon);
	void MeetEnemy_Communicate(Player& player, Enemy* pEnemy);
	void Explore_Discovery(Player& player);
	void Explore_Accident(Player& player);

private:


};

