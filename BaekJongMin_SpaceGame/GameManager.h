#pragma once

#include"Actor.h"
#include"Player.h"
#include"Enemy.h"



class GameManager
{
public:

	void MainRoot();
	void DailyAction();
	void Explore();
	void Rest();
	void Research();
	void Explore_MeetEnemy();
	void MeetEnemy_BattleEvent(Player& player, Enemy* pEnemy);
	int CalculateWeaponDamage(Player& player, Enemy& enemy, WeaponType weapon);
	void MeetEnemy_Communicate(Player& player, Enemy* pEnemy);
	void Explore_Discovery();
	void Explore_Accident();

private:
	Player player;
	int Day = 1;
	const int Day_End = 11;

	int ActionPoint = 2;
	const int MaxActionPoint = 2;

	bool DoExplore = false;
	bool DoRest = false;
	bool DoResearch = false;
};

