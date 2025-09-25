#pragma once

#include"Actor.h"
#include"Player.h"
#include"Enemy.h"
#include"Exploreclass.h"
#include"Ending.h"




class GameManager
{
public:

	void Intro();
	void MainRoot();
	void DailyAction();
	void Explore();
	void Rest();
	void Research();
	void DeadCheck();

private:
	Player player;
	Exploreclass explore;
	Ending ending;

	int Day = 1;
	const int Day_End = 11;

	int ActionPoint = 2;
	const int MaxActionPoint = 2;

	bool DoExplore = false;
	bool DoRest = false;
	bool DoResearch = false;
};

