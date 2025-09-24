#include <iostream>
#include <fstream>
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

void GameManager::MainRoot()
{
	while (Day < Day_End)
	{
		printf("\n===== Day %d =====\n", Day);
		ActionPoint = MaxActionPoint;
		DoExplore = DoRest = DoResearch = false;

		DailyAction();

		Day++;
	}
	printf("���� ����! 10���� �������ϴ�.\n");
}

void GameManager::DailyAction()
{
	bool EndDay = false;

	while (ActionPoint > 0 && !EndDay)
	{

		printf("AP: %d\n", ActionPoint);
		printf("������ �Ͻðڽ��ϱ�?\n");
		printf("[1.Ž�� 2.�޽� 3.����]\n");

		int MaxChoice = 3;

		if (ActionPoint < MaxActionPoint)
		{
			MaxChoice = 4;
		}

		int Choice = 0;
		std::cin >> Choice;

		if (Choice < 1 || Choice > MaxChoice)
		{
			printf("�߸��Է��ϼ̽��ϴ�. �ٽ� �Է��Ͻÿ�.\n");
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
				printf("������ �̹� Ž���߽��ϴ�!\n");
			}
			break;
		case 2:
			if (!DoRest)
			{ 
				Rest(); ActionPoint--; DoRest = true; 
			}
			else
			{
				printf("������ �̹� �޽��߽��ϴ�!\n");
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
				printf("������ �̹� �����߽��ϴ�!\n");
			}
			break;
		case 4:
			printf("���� ���� �Ѿ�ϴ�.\n");
			return;
		}

		printf("�ൿ���� �� ���������ϴ�. �ڵ����� ���� ���� �Ѿ�ϴ�.\n");
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
	printf("������ �����մϴ�.\n");

	int i = rand() % 100;

	if (player.WeaponCount() == 3)
	{
		if (i < 20)
		{
			printf("�ƹ� �ϵ� �Ͼ�� �ʾҴ�.");
		}
		else
		{
			player.ObtainAlienBook();
		}
		return;
	}
	if (i < 20)
	{
		printf("�ƹ� �ϵ� �Ͼ�� �ʾҴ�.");
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
}

void GameManager::Explore_MeetEnemy()
{
	srand(time(0));
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
	if (dynamic_cast<Spider*>(pEnemy))
	{
		meet.MeetSpider();
	}
	else if (dynamic_cast<JellyFish*>(pEnemy))
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
				player.IncreaseEnemyAffinity(*pEnemy, +15);
			}
			else if (dynamic_cast<Spider*>(pEnemy))
			{
				player.IncreaseEnemyAffinity(*pEnemy, -5);
			}
			else
			{
				player.IncreaseEnemyAffinity(*pEnemy, -3);
			}
			break;

		case 2: // ����
			if (dynamic_cast<Robot*>(pEnemy))
			{
				player.IncreaseEnemyAffinity(*pEnemy, +15);
			}
			else player.IncreaseEnemyAffinity(*pEnemy, +2);
			break;

		case 3: // ���� ����
			if (dynamic_cast<Spider*>(pEnemy))
			{
				player.IncreaseEnemyAffinity(*pEnemy, +15);
			}
			else if (dynamic_cast<JellyFish*>(pEnemy))
			{
				player.IncreaseEnemyAffinity(*pEnemy, -10);
			}
			else
			{
				player.IncreaseEnemyAffinity(*pEnemy, +3);
			}
			break;
		}
		printf("���� ȣ����: %d\n", pEnemy->GetAffinity());
	}

	// �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ� ��ȭ ����

	int FinalAffinity = pEnemy->GetAffinity();
	printf("\n���� ȣ����: %d\n", FinalAffinity);

	if (FinalAffinity < 50) 
	{
		Sleep(2000);
		printf("%s�� ���������� ���߽��ϴ�! ���� ����!\n", pEnemy->GetName().c_str());
		Sleep(2000);
		MeetEnemy_BattleEvent(player, pEnemy);
	}
	else if (FinalAffinity < 60) 
	{
		printf("%s�� ����ϸ� ���������ϴ�.\n", pEnemy->GetName().c_str());
		Sleep(1000);
	}
	else 
	{
		printf("%s�� ȣ���� �������ϴ�! ����ǰ�� �ݴϴ�.\n", pEnemy->GetName().c_str());
		Sleep(1000);
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
		printf("�÷��̾� ���Դϴ�. ���ݹ���� �����ϼ���.\n");
		int Option = 1;
		printf("%d.�⺻����\n", Option++);

		std::vector<WeaponType> Choices;

		if (player.HasWeapon(WeaponType::Fire))
		{
			printf("%d. Fire ���� ����\n", Option++);
			Choices.push_back(WeaponType::Fire);
		}
		if (player.HasWeapon(WeaponType::EMP))
		{
			printf("%d. EMP ���� ����\n", Option++);
			Choices.push_back(WeaponType::EMP);
		}
		if (player.HasWeapon(WeaponType::Hit))
		{
			printf("%d. Hit ���� ����\n", Option++);
			Choices.push_back(WeaponType::Hit);
		}

		int Choice;
		std::cin >> Choice;

		int Damage = player.GetAttackPower();

		if (Choice == 1)
		{
			printf("�⺻ ����!\n");
		}
		else
		{
			int weaponIndex = Choice - 2; // 2������ �����
			if (weaponIndex >= 0 && weaponIndex < (int)Choices.size())
			{
				WeaponType selected = Choices[weaponIndex];

				switch (selected)
				{
				case WeaponType::Fire:
					printf("Fire ����� ����!\n");
					break;
				case WeaponType::EMP:
					printf("EMP ����� ����!\n");
					break;
				case WeaponType::Hit:
					printf("Hit ����� ����!\n");
					break;
				}
				Damage = CalculateWeaponDamage(player, *pEnemy, selected);
			}
			else
			{
				printf("�߸��� �����Դϴ�. �⺻ �������� �����մϴ�.\n");
			}
		}

		pEnemy->TakeDamage(Damage);

		if (!pEnemy->IsAlive())
		{
			printf("��븦 �����ƽ��ϴ�!\n");
			break;
		}

		// --- �� �� ---
		pEnemy->ApplyAttack(&player);
		if (!player.IsAlive())
		{
			printf("��뿡�� �й��Ͽ����ϴ�...\n");
		}
	}
}

int GameManager::CalculateWeaponDamage(Player& player, Enemy& enemy, WeaponType weapon)
{
	int BaseAttack = player.GetAttackPower();

	if (weapon == enemy.GetWeakType())
	{
		return BaseAttack * 2; // ���� ���� ���� �� ������ 2��
	}
	else if (weapon == enemy.GetStrongType())
	{
		return BaseAttack / 2; // ���� ���� ���� �� ������ ����
	}
	else
	{
		return BaseAttack;     // ���� �� �� �״��
	}
}


void GameManager::Explore_Discovery()
{
}

void GameManager::Explore_Accident()
{
}
