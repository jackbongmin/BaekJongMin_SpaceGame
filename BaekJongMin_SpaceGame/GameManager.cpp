#include <iostream>
#include <fstream>
#include <random>

#include "GameManager.h"
#include "Actor.h"
#include "Player.h"
#include "Enemy.h"
#include "Spider.h"
#include "JellyFish.h"
#include "Robot.h"
#include "Meet.h"

void GameManager::MainRoot()
{
	int Day = 1;
	const int Day_End = 11;

	while (Day != Day_End)
	{

	}
}

void GameManager::DailyAction()
{
	int ActionPoint = 2;
	const int MaxActionPoint = 2;
	if (ActionPoint > MaxActionPoint)
	{
		ActionPoint == MaxActionPoint;
	}

}

void GameManager::Explore()
{

}

void GameManager::Rest()
{
}

void GameManager::Research()
{
}

void GameManager::Explore_MeetEnemy()
{
	Enemy* pEnemy = nullptr;
	int i = rand() % 3;
	switch (i)
	{
	case 0:
		pEnemy = new Spider();
		printf("거미 외계인이 나타났습니다.\n");
		break;
	case 1:
		pEnemy = new JellyFish();
		printf("해파리 외계인이 나타났습니다.\n");
		break;
	case 2:
		pEnemy = new Robot();
		printf("외계 로봇이 나타났습니다.\n");
		break;
	default:
		break;
	}
	Meet meet;
	if (pEnemy == new Spider)
	{
		meet.MeetSpider();
	}
	else if (pEnemy == new JellyFish)
	{
		meet.MeetJellyFish();
	}
	else
	{
		meet.MeetRobot();
	}
	MeetEnemy_Communicate(player, pEnemy);
}

void GameManager::MeetEnemy_Communicate(Player& player, Enemy* pEnemy)
{
	printf("%s와 대화를 시작합니다.\n", pEnemy->GetName().c_str());

	for (int round = 1; round <= 3; round++) 
	{
		printf("\n[%d번째 대화]\n", round);
		printf("1. 평화롭게 이야기한다\n");
		printf("2. 교역을 제안한다\n");
		printf("3. 힘을 과시한다\n");

		int choice;
		std::cin >> choice;

		switch (choice) {
		case 1: // 평화
			if (dynamic_cast<JellyFish*>(pEnemy))
			{
				pEnemy->AddAffinity(+15);
			}
			else if (dynamic_cast<Spider*>(pEnemy))
			{
				pEnemy->AddAffinity(-5);
			}
			else 
			{ 
				pEnemy->AddAffinity(-3);
			}
			break;
		case 2: // 협상
			if (dynamic_cast<Robot*>(pEnemy))
			{
				pEnemy->AddAffinity(+15);
			}
			else pEnemy->AddAffinity(+2);
			break;
		case 3: // 전쟁 ㄱㄱ
			if (dynamic_cast<Spider*>(pEnemy))
			{
				pEnemy->AddAffinity(+15);
			}
			else if (dynamic_cast<JellyFish*>(pEnemy))
			{
				pEnemy->AddAffinity(-10);
			}
			else
			{
				pEnemy->AddAffinity(+3);
			}
			break;
		}
		printf("현재 호감도: %d\n", pEnemy->GetAffinity());
	}

	// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ 대화 끝남

	int FinalAffinity = pEnemy->GetAffinity();
	printf("\n최종 호감도: %d\n", FinalAffinity);

	if (FinalAffinity < 50) 
	{
		printf("%s가 적대적으로 변했습니다! 전투 돌입!\n", pEnemy->GetName().c_str());
		MeetEnemy_BattleEvent(player, pEnemy);
	}
	else if (FinalAffinity < 60) 
	{
		printf("%s는 경계하며 물러났습니다.\n", pEnemy->GetName().c_str());
	}
	else 
	{
		printf("%s가 호감을 보였습니다! 보급품을 줍니다.\n", pEnemy->GetName().c_str());
		// 보급품 추가해야함 player에 자원 보급
		// player.AddFood(1);
		// player.AddOxygen(10);
	}
}

void GameManager::MeetEnemy_BattleEvent(Player& player, Enemy* pEnemy)
{

	printf("전투를 시작합니다.\n");

	while (player.IsAlive() && pEnemy->IsAlive())
	{
		player.ApplyAttack(pEnemy);
		if (!pEnemy->IsAlive())
		{
			printf("상대를 물리쳤습니다.\n");
			break;
		}
		pEnemy->ApplyAttack(&player);
		if (!player.IsAlive())
		{
			printf("상대에게 패배하였습니다.\n");
		}
	}

}


void GameManager::Explore_Discovery()
{
}

void GameManager::Explore_Accident()
{
}
