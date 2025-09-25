#include <iostream>
#include <random>
#include <Windows.h>
#include "Exploreclass.h"
#include "Actor.h"
#include "Player.h"
#include "Enemy.h"
#include "Spider.h"
#include "JellyFish.h"
#include "Robot.h"
#include "Meet.h"

void Exploreclass::Explore_MeetEnemy(Player& player)
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
	Sleep(1000);
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
	Sleep(1000);
	MeetEnemy_Communicate(player, pEnemy);
}

void Exploreclass::MeetEnemy_Communicate(Player& player, Enemy* pEnemy)
{
	printf("%s(��)�� ��ȭ�� �����մϴ�.\n", pEnemy->GetName().c_str());
	Sleep(500);

	for (int round = 1; round <= 3; round++)
	{
		printf("\n[%d��° ��ȭ]\n", round);
		if (pEnemy->GetName() == "�Ź� �ܰ���")
		{
			if (round == 1)
			{
				printf("�Ź� �ܰ��� : Thrixel wev��no cresthun, spyr��eth glawnor.\n\n");
			}
			if (round == 2)
			{
				printf("�Ź� �ܰ��� : Crr-sshh tanttt vorethin, arakn��dral sith.\n\n");
			}
			if (round == 3)
			{
				printf("�Ź� �ܰ��� : Webrae ignor quessh, klith spun��dor.\n\n");
			}
			Sleep(1000);
		}
		else if (pEnemy->GetName() == "���ĸ� �ܰ���")
		{
			if (round == 1)
			{
				printf("���ĸ� �ܰ��� : Lu~me~a d~rif~sh~oon, qu~ori~elth i~n slos~~hine.\n\n");
			}
			if (round == 2)
			{
				printf("���ĸ� �ܰ��� : Gly~~ssha ve��loo~n mar~qual, jell~ith ph~~oor.\n\n");
			}
			if (round == 3)
			{
				printf("���ĸ� �ܰ��� : Zoo~~nq~uash th~allu~me, o~rbiq~u~eth syla~a.\n\n");
			}
			Sleep(1000);
		}
		else if (pEnemy->GetName() == "�ܰ� �κ�")
		{
			if (round == 1)
			{
				printf("�ܰ� �κ� : SYS-404X: PROTOCOL_7Z INITIATED // 0110-EXA RUNMODE\n\n");
			}
			if (round == 2)
			{
				printf("�ܰ� �κ� : CORE-99A:: VECTOR_OVERRIDE >> SIGNAL_001101 LOST\n\n");
			}
			if (round == 3)
			{
				printf("�ܰ� �κ� : UNIT-77Z ENGAGE: ERROR-505 LOOP // REBOOT_12.3\n\n");
			}
			Sleep(1000);
		}
		printf("");
		printf("1. ��ȭ�Ӱ� �̾߱��Ѵ�\n");
		printf("2. ������ �����Ѵ�\n");
		printf("3. ���� �����Ѵ�\n");

		int choice;
		printf("\n����� ������? >> ");
		std::cin >> choice;

		switch (choice) {
		case 1: // ��ȭ
			if (dynamic_cast<JellyFish*>(pEnemy))
			{
				printf("\n���ĸ� �ܰ��� : Gly~~ssha\n");
				Sleep(1000);
				printf("(ȣ���� +15)\n\n");
				Sleep(1000);
				player.IncreaseEnemyAffinity(*pEnemy, +15);
			}
			else if (dynamic_cast<Spider*>(pEnemy))
			{
				printf("\n�Ź� �ܰ��� : Crr-sshh..\n");
				Sleep(1000);
				printf("(ȣ���� -5)\n\n");
				Sleep(1000);
				player.IncreaseEnemyAffinity(*pEnemy, -5);
			}
			else if (dynamic_cast<Robot*>(pEnemy))
			{
				printf("\n�ܰ�κ� : A!AA@AAA_XA\n");
				Sleep(1000);
				printf("(ȣ���� -11)\n\n");
				Sleep(1000);
				player.IncreaseEnemyAffinity(*pEnemy, -11);
			}
			break;

		case 2: // ����
			if (dynamic_cast<JellyFish*>(pEnemy))
			{
				printf("\n���ĸ� �ܰ��� : f~sh~oon\n");
				Sleep(1000);
				printf("(ȣ���� +5)\n\n");
				Sleep(1000);
				player.IncreaseEnemyAffinity(*pEnemy, +5);
			}
			else if (dynamic_cast<Spider*>(pEnemy))
			{
				printf("\n�Ź� �ܰ��� : spyr��ettttt!!!\n");
				Sleep(1000);
				printf("(ȣ���� +10)\n\n");
				Sleep(1000);
				player.IncreaseEnemyAffinity(*pEnemy, +10);
			}
			else if (dynamic_cast<Robot*>(pEnemy))
			{
				printf("\n�ܰ�κ� : 11101011 10000100 10010000 00100000 11101100 10100011 10111101 11101100 10011101 10110100 11101010 10110010 10100000 11101011 10001011 10100100\n");
				Sleep(1000);
				printf("(ȣ���� -15)\n\n");
				Sleep(1000);
				player.IncreaseEnemyAffinity(*pEnemy, -15);
			}
			break;
		case 3: // ���� ����
			if (dynamic_cast<JellyFish*>(pEnemy))
			{
				printf("\n���ĸ� �ܰ��� :th~allu~me\n");
				Sleep(1000);
				printf("(ȣ���� -15)\n\n");
				Sleep(1000);
				player.IncreaseEnemyAffinity(*pEnemy, -15);
			}
			else if (dynamic_cast<Spider*>(pEnemy))
			{
				printf("\n�Ź� �ܰ��� : klith klith klith \n");
				Sleep(1000);
				printf("(ȣ���� -11)\n\n");
				Sleep(1000);
				player.IncreaseEnemyAffinity(*pEnemy, -11);
			}
			else if (dynamic_cast<Robot*>(pEnemy))
			{
				printf("\n�ܰ�κ� : ERROR-404 LOOP\n");
				Sleep(1000);
				printf("(ȣ���� +10)\n\n");
				Sleep(1000);
				player.IncreaseEnemyAffinity(*pEnemy, +10);
			}
			break;
		}
		printf("���� ȣ����: %d\n", pEnemy->GetAffinity());
		Sleep(700);
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
		player.PlayerStat();
		Sleep(1000);
	}
	else
	{
		printf("%s�� ȣ���� �������ϴ�!\n", pEnemy->GetName().c_str());
		Sleep(1000);

		int i = rand() % 3;
		switch (i)
		{
		case 0:
			printf("%s�� ���ư����ϴ�.\n", pEnemy->GetName().c_str());
			break;
		case 1:
			printf("����ǰ�� �ݴϴ�!\n\n");
			player.AddFood(1);
			break;
		case 2:
			printf("����ǰ�� �ݴϴ�!\n\n");
			player.AddOxygen(20);
			break;
		}

		Sleep(1000);
		player.PlayerStat();
		Sleep(1000);
	}
}

void Exploreclass::MeetEnemy_BattleEvent(Player& player, Enemy* pEnemy)
{

	printf("������ �����մϴ�.\n\n");

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
		printf("\n");


		int Damage = player.GetAttackPower();

		if (Choice == 1)
		{
			printf("�⺻ ����!\n");
		}
		else
		{
			int weaponIndex = Choice - 2;
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
				printf("\n");
			}
			else
			{
				printf("�߸��� �����Դϴ�. �⺻ �������� �����մϴ�.\n");
			}
		}

		pEnemy->TakeDamage(Damage);

		if (!pEnemy->IsAlive())
		{
			
			int i = rand() % 3;
			switch (i)
			{
			case 0:
				break;
			case 1:
				printf("����ǰ�� �ݴϴ�!\n");
				player.AddFood(1);
				break;
			case 2:
				printf("����ǰ�� �ݴϴ�!\n");
				player.AddOxygen(20);
				break;
			}
			break;
		}


		pEnemy->ApplyAttack(&player);
		if (!player.IsAlive())
		{
			printf("��뿡�� �й��Ͽ����ϴ�...\n");
		}
		
	}
}

int Exploreclass::CalculateWeaponDamage(Player& player, Enemy& enemy, WeaponType weapon)
{
	int BaseAttack = player.GetAttackPower();

	if (weapon == enemy.GetWeakType())
	{
		printf("ȿ���� ����ߴ�!\n");
		return BaseAttack * 2;
	}
	else if (weapon == enemy.GetStrongType())
	{
		printf("ȿ���� ���� ������..\n");
		return BaseAttack / 2;
	}
	else
	{
		return BaseAttack;
	}
}


void Exploreclass::Explore_Discovery(Player& player)
{
	Meet meet;
	meet.MeetDiscovery();
	printf("�ڿ��� �߰��߽��ϴ�.\n\n");
	Sleep(1000);
	int i = rand() % 100;

	if (i < 20)
	{
		printf("�ķ��� 1�� �߰��߽��ϴ�.\n");
		player.AddFood(1);
	}
	else if (i < 70)
	{
		printf("������� 1�� �߰��߽��ϴ�.\n");
		player.AddOxygen(50);
	}
	else if (i < 90)
	{
		printf("�ķ��� 2�� �߰��߽��ϴ�.\n");
		player.AddFood(2);
	}
	else
	{
		printf("�ܰ��� ������ �߰��߽��ϴ�.\n");
		player.ObtainAlienBook();
	}
	
	Sleep(1000);
	player.PlayerStat();
	Sleep(1000);
}

void Exploreclass::Explore_Accident(Player& player)
{
	Meet meet;
	meet.MeetAccident();
	printf("��� ���߽��ϴ�.\n\n");
	Sleep(1000);

	int i = rand() % 100;

	if (i < 34)
	{
		printf("�ķ��� �Ҿ����ϴ�.\n");
		player.ConsumeFood();
	}
	else if (i < 67)
	{
		printf("��Ҹ� �Ҿ����ϴ�.\n");
		player.ConsumeOxygen(10);
	}
	else
	{
		printf("�������� �Ծ����ϴ�.\n");
		player.TakeDamage(20);
	}
	
	Sleep(1000);
	player.PlayerStat();
	Sleep(1000);
}

