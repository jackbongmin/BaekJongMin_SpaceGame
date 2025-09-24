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
		printf("�Ź� �ܰ����� ��Ÿ�����ϴ�.\n");
		break;
	case 1:
		pEnemy = new JellyFish();
		printf("���ĸ� �ܰ����� ��Ÿ�����ϴ�.\n");
		break;
	case 2:
		pEnemy = new Robot();
		printf("�ܰ� �κ��� ��Ÿ�����ϴ�.\n");
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
	printf("%s�� ��ȭ�� �����մϴ�.\n", pEnemy->GetName().c_str());

	for (int round = 1; round <= 3; round++) 
	{
		printf("\n[%d��° ��ȭ]\n", round);
		printf("1. ��ȭ�Ӱ� �̾߱��Ѵ�\n");
		printf("2. ������ �����Ѵ�\n");
		printf("3. ���� �����Ѵ�\n");

		int choice;
		std::cin >> choice;

		switch (choice) {
		case 1: // ��ȭ
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
		case 2: // ����
			if (dynamic_cast<Robot*>(pEnemy))
			{
				pEnemy->AddAffinity(+15);
			}
			else pEnemy->AddAffinity(+2);
			break;
		case 3: // ���� ����
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
		printf("���� ȣ����: %d\n", pEnemy->GetAffinity());
	}

	// �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ� ��ȭ ����

	int FinalAffinity = pEnemy->GetAffinity();
	printf("\n���� ȣ����: %d\n", FinalAffinity);

	if (FinalAffinity < 50) 
	{
		printf("%s�� ���������� ���߽��ϴ�! ���� ����!\n", pEnemy->GetName().c_str());
		MeetEnemy_BattleEvent(player, pEnemy);
	}
	else if (FinalAffinity < 60) 
	{
		printf("%s�� ����ϸ� ���������ϴ�.\n", pEnemy->GetName().c_str());
	}
	else 
	{
		printf("%s�� ȣ���� �������ϴ�! ����ǰ�� �ݴϴ�.\n", pEnemy->GetName().c_str());
		// ����ǰ �߰��ؾ��� player�� �ڿ� ����
		// player.AddFood(1);
		// player.AddOxygen(10);
	}
}

void GameManager::MeetEnemy_BattleEvent(Player& player, Enemy* pEnemy)
{

	printf("������ �����մϴ�.\n");

	while (player.IsAlive() && pEnemy->IsAlive())
	{
		player.ApplyAttack(pEnemy);
		if (!pEnemy->IsAlive())
		{
			printf("��븦 �����ƽ��ϴ�.\n");
			break;
		}
		pEnemy->ApplyAttack(&player);
		if (!player.IsAlive())
		{
			printf("��뿡�� �й��Ͽ����ϴ�.\n");
		}
	}

}


void GameManager::Explore_Discovery()
{
}

void GameManager::Explore_Accident()
{
}
