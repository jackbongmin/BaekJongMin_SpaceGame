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
	void MeetEnemy_Communicate(Player& player, Enemy* pEnemy);
	void Explore_Discovery();
	void Explore_Accident();

private:
	Player player;

};

