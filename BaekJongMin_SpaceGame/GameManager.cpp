/*
														 ███╗   ██╗███████╗██╗  ██╗██████╗  █████╗  ██████╗███████╗    ██╗   ██╗███████╗
														 ████╗  ██║██╔════╝ ██╗██╗ ██╔══██╗██╔══██╗██╔════╝██╔════╝    ██║   ██║██╔════╝
														 ██╔██╗ ██║█████╗    ███║  ██████╔╝███████║██║     █████╗      ██║   ██║███████╗
														 ██║╚██╗██║██╔══╝   ██═██║ ██╔═══╝ ██╔══██║██║     ██╔══╝      ██║   ██║ ╚═══██║
														 ██║ ╚████║███████╗██║  ██║██║     ██║  ██║╚██████╗███████╗     ╚████╔╝ ███████║
														 ╚═╝  ╚═══╝╚══════╝╚═╝  ╚═╝╚═╝     ╚═╝  ╚═╝ ╚═════╝╚══════╝      ╚═══╝  ╚══════╝
*/
#include <iostream>
//#include <fstream>
#include <random>
#include <Windows.h>
#include<vector>
#include<set>

#include "GameManager.h"
#include "Actor.h"
#include "Player.h"
#include "Enemy.h"
#include "Spider.h"
#include "JellyFish.h"
#include "Robot.h"
#include "Meet.h"
#include "Exploreclass.h"
#include "Ending.h"
#include "IIIntro.h"

// 게임 진행 방식(10일간 버티기)
void GameManager::MainRoot()
{
	while (Day < Day_End)
	{
		//printf("\n======= Day %d =======\n\n", Day);
		intro.ReportDay(Day);

		// 3,6,9 일차 강제 이벤트
		if (Day == 3 || Day == 6 || Day == 9)
		{
			Sleep(1000);
			printf("\n※ %d일차 강제 이벤트 ※\n\n", Day);
			Sleep(1000);


			int i = rand() % 100;
			if (i < 50)
			{
				printf("외계인이 찾아왔습니다.\n");
				explore.Explore_MeetEnemy(player);
			}
			else if (i < 75)
			{
				explore.Explore_Discovery(player);
			}
			else
			{
				explore.Explore_Accident(player);
			}
			DeadCheck();
		}

		ActionPoint = MaxActionPoint;
		
		DoExplore = DoRest = DoResearch = false;

		DailyAction();

		Day++;
		if (player.GetFood() <= 0)
		{
			printf("식량이 부족합니다! %s(이)가 굶주림에 몸부림칩니다.\n", player.GetName().c_str());
			player.TakeDamage(player.GetHungerPenalty());
		}

		Sleep(1000);
		player.ConsumeFood();
		Sleep(1000);
		player.ConsumeOxygen(10);

		Sleep(1000);
		player.PlayerStat();

		DeadCheck();

		if (Day < 11)
		{
		//printf("\n=====================\n");
		//printf("\n       다음날\n");
			intro.ReportNextDay();
		}
	}
	Sleep(2000);
	printf(" 10일이 지났습니다.\n");
	if (Day >= 10) 
	{
		ending.EndingCheck(player, Day);
	}
	Sleep(2000);
}

// 하루마다 실행할 행동(탐사, 휴식, 연구) 2회 가능, 중복 불가
void GameManager::DailyAction()
{
	DeadCheck();
	bool EndDay = false;

	while (ActionPoint > 0 && !EndDay)
	{

		printf("무엇을 하시겠습니까?(AP : %d)\n", ActionPoint);
		Sleep(500);
		printf("[1.탐사 2.휴식 3.연구]\n");

		std::string ExploreInput;
		std::cin >> ExploreInput;

		int Choice = 0;
		if ((player.GetFood() <= 1 || player.GetOxygen() <= 20)
			&& (ExploreInput == "iwanttosurvive" || ExploreInput == "Iwanttosurvive" || ExploreInput == "IWANTTOSURVIVE"))
		{
			Sleep(1000);
			printf("\n당신의 간절함이 느껴집니다..\n\n");
			Sleep(1000);
			player.AddFood(5);
			player.AddOxygen(100);
			player.PlayerStat();
			continue;
		}
		else if (ExploreInput == "iwanthappy" || ExploreInput == "IWANTHAPPY")
		{
			Sleep(1000);
			printf("\n행복한 꿈을 꿉니다..\n\n");
			Sleep(1000);
			player.IncreaseHighAffinityCount();
			player.IncreaseHighAffinityCount();
			player.IncreaseHighAffinityCount();
			for (int i = 0; i < 3; i++)
			{
				player.ObtainAlienBook();
			}
			continue;
		}
		else if (ExploreInput == "iwantunhappy" || ExploreInput == "IWANTUNHAPPY")
		{
			Sleep(1000);
			printf("\n불행한 꿈을 꿉니다..\n\n");
			Sleep(1000);
			player.IncreaseLowAffinityCount();
			player.IncreaseLowAffinityCount();
		}
		else if (ExploreInput == "gotolastday" || ExploreInput == "GOTOLASTDAY")
		{
			Sleep(1000);
			printf("\n시간이 빠르게 흐릅니다..\n\n");
			Sleep(1000);
			Day = 10;
			break;
		}
		else if (ExploreInput == "dead" || ExploreInput == "DEAD")
		{
			Sleep(1000);
			printf("\n숨이 막히기 시작합니다..\n\n");
			Sleep(1000);
			player.ConsumeOxygen(100);
			DeadCheck();
			break;
		}
		else if (ExploreInput == "1")
		{
			Choice = 1;
		}
		else if (ExploreInput == "2")
		{
			Choice = 2;
		}
		else if (ExploreInput == "3")
		{
			Choice = 3;
		}
		else
		{
			printf("잘못입력하셨습니다. 다시 입력하세요.\n");
			continue;
		}
		switch (Choice)
		{
		case 1:
			if (!DoExplore) 
			{ 
				Explore(); 
				ActionPoint--; 
				DoExplore = true; 
			}
			else
			{
				printf("오늘은 이미 탐험했습니다!\n");
			}
			break;
		case 2:
			if (!DoRest)
			{ 
				Rest(); ActionPoint--; DoRest = true; 
			}
			else
			{
				printf("오늘은 이미 휴식했습니다!\n");
			}
			break;
		case 3:
			if (!DoResearch) 
			{
				Research(); ActionPoint--; 
				DoResearch = true; 
			}
			else
			{
				printf("오늘은 이미 연구했습니다!\n");
			}
			break;
		//case 4:
		//	printf("다음 날로 넘어갑니다.\n");
		//	return;
		}
		Sleep(1000);
		const int End_ActionPoint = 0;
		if (ActionPoint == End_ActionPoint)
		{
			printf("AP가 다 떨어졌습니다. 다음 날로 넘어갑니다.\n\n");
			Sleep(1000);
		}
	}
}

// 하루 일과 中 탐사(외계인 조우, 자원발견, 사고발생)
void GameManager::Explore()
{
	printf("탐사를 시작합니다..\n");
	Sleep(500);
	printf(".");
	Sleep(500);
	printf(".");
	Sleep(500);
	printf(".");
	Sleep(500);
	printf(".\n\n");
	Sleep(500);


	int i = rand() % 3;
	switch (i)
	{
	case 0 :
		explore.Explore_MeetEnemy(player);
		break;
	case 1 :
		explore.Explore_Discovery(player);
		break;
	case 2 :
		explore.Explore_Accident(player);
		break;
	}

	DeadCheck();
}

// 하루 일과 中 휴식(체력 + 25, 산소 - 5)
void GameManager::Rest()
{
	printf("휴식을 합니다..\n");
	Sleep(500);
	printf(".");
	Sleep(500);
	printf(".");
	Sleep(500);
	printf(".");
	Sleep(500);
	printf(".\n\n");
	Sleep(500);

	player.Heal(25);
	player.ConsumeOxygen(5);
	Sleep(500);
	player.PlayerStat();
	DeadCheck();
}

// 하루 일과 中 연구(아무일 X, 무기발견, 도감발견), 산소 -5
void GameManager::Research()
{
	printf("연구를 시작합니다.\n");
	Sleep(500);
	printf(".");
	Sleep(500);
	printf(".");
	Sleep(500);
	printf(".");
	Sleep(500);
	printf(".\n\n");
	Sleep(500);

	int i = rand() % 100;

	if (player.WeaponCount() == 3)
	{
		if (i < 20)
		{
			printf("아무 일도 일어나지 않았다.\n");
		}
		else
		{
			player.ObtainAlienBook();
		}
		return;
	}
	if (i < 20)
	{
		printf("아무 일도 일어나지 않았다.\n");
	}
	else if (i < 60)
	{
		player.ObtainAlienBook();
	}
	else
	{
		std::vector<WeaponType> Available;

		if (!player.HasWeapon(WeaponType::Fire))
		{
			Available.push_back(WeaponType::Fire);
		}
		if (!player.HasWeapon(WeaponType::EMP))
		{
			Available.push_back(WeaponType::EMP);
		}
		if (!player.HasWeapon(WeaponType::Hit))
		{
			Available.push_back(WeaponType::Hit);
		}
		if (!Available.empty())
		{
			int i = rand() % Available.size();
			player.AddWeapon(Available[i]);
		}
	}
	Sleep(300);
	player.ConsumeOxygen(5);
	Sleep(500);
	player.PlayerStat();
	DeadCheck();
}

// 전투 및 이벤트로 인한 플레이어 사망 확인
void GameManager::DeadCheck()
{
	if (player.GetHealth() <= 0) 
	{
		printf("\nHP가 0입니다.\n");
		Sleep(1000);
		printf("당신은 생존하지 못했습니다.\n");
		Sleep(1000);
		printf("당신이 지금껏 연구한 자료들이 우주에 흩어집니다..\n");
		Sleep(1000);

		printf("\n※게임 오버※\n");
		exit(0);
	}

	if (player.GetOxygen() <= 0) 
	{
		printf("\n산소가 고갈되었습니다.\n");
		Sleep(1000);
		printf("당신은 생존하지 못했습니다.\n");
		Sleep(1000);
		printf("당신이 지금껏 연구한 자료들이 우주에 흩어집니다..\n");
		Sleep(1000);

		printf("\n※게임 오버※\n");
		exit(0);
	}
}
