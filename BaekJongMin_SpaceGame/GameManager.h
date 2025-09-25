#pragma once

#include"Actor.h"
#include"Player.h"
#include"Enemy.h"
#include"Exploreclass.h"
#include"Ending.h"
#include"IIIntro.h"




class GameManager
{
public:

	GameManager() = default;
	GameManager(const std::string& InPlayerName)
		:player(InPlayerName.c_str(), 100, 15) {}

	//void Intro();
	void Intro_2();
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
	IIIntro intro;

	int Day = 1;
	const int Day_End = 11;

	int ActionPoint = 2;
	const int MaxActionPoint = 2;

	bool DoExplore = false;
	bool DoRest = false;
	bool DoResearch = false;
};

