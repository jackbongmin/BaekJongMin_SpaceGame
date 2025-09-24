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
	printf("게임 종료! 10일이 지났습니다.\n");
}

void GameManager::DailyAction()
{
	bool EndDay = false;

	while (ActionPoint > 0 && !EndDay)
	{

		printf("AP: %d\n", ActionPoint);
		printf("무엇을 하시겠습니까?\n");
		printf("[1.탐험 2.휴식 3.연구]\n");

		int MaxChoice = 3;

		if (ActionPoint < MaxActionPoint)
		{
			MaxChoice = 4;
		}

		int Choice = 0;
		std::cin >> Choice;

		if (Choice < 1 || Choice > MaxChoice)
		{
			printf("잘못입력하셨습니다. 다시 입력하시오.\n");
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
		case 4:
			printf("다음 날로 넘어갑니다.\n");
			return;
		}

		printf("행동력이 다 떨어졌습니다. 자동으로 다음 날로 넘어갑니다.\n");
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
	printf("연구를 시작합니다.\n");

	int i = rand() % 100;

	if (player.WeaponCount() == 3)
	{
		if (i < 20)
		{
			printf("아무 일도 일어나지 않았다.");
		}
		else
		{
			player.ObtainAlienBook();
		}
		return;
	}
	if (i < 20)
	{
		printf("아무 일도 일어나지 않았다.");
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

		case 2: // 협상
			if (dynamic_cast<Robot*>(pEnemy))
			{
				player.IncreaseEnemyAffinity(*pEnemy, +15);
			}
			else player.IncreaseEnemyAffinity(*pEnemy, +2);
			break;

		case 3: // 전쟁 ㄱㄱ
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
		printf("현재 호감도: %d\n", pEnemy->GetAffinity());
	}

	// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ 대화 끝남

	int FinalAffinity = pEnemy->GetAffinity();
	printf("\n최종 호감도: %d\n", FinalAffinity);

	if (FinalAffinity < 50) 
	{
		Sleep(2000);
		printf("%s가 적대적으로 변했습니다! 전투 돌입!\n", pEnemy->GetName().c_str());
		Sleep(2000);
		MeetEnemy_BattleEvent(player, pEnemy);
	}
	else if (FinalAffinity < 60) 
	{
		printf("%s는 경계하며 물러났습니다.\n", pEnemy->GetName().c_str());
		Sleep(1000);
	}
	else 
	{
		printf("%s가 호감을 보였습니다! 보급품을 줍니다.\n", pEnemy->GetName().c_str());
		Sleep(1000);
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
		printf("플레이어 턴입니다. 공격방식을 선택하세요.\n");
		int Option = 1;
		printf("%d.기본공격\n", Option++);

		std::vector<WeaponType> Choices;

		if (player.HasWeapon(WeaponType::Fire))
		{
			printf("%d. Fire 무기 공격\n", Option++);
			Choices.push_back(WeaponType::Fire);
		}
		if (player.HasWeapon(WeaponType::EMP))
		{
			printf("%d. EMP 무기 공격\n", Option++);
			Choices.push_back(WeaponType::EMP);
		}
		if (player.HasWeapon(WeaponType::Hit))
		{
			printf("%d. Hit 무기 공격\n", Option++);
			Choices.push_back(WeaponType::Hit);
		}

		int Choice;
		std::cin >> Choice;

		int Damage = player.GetAttackPower();

		if (Choice == 1)
		{
			printf("기본 공격!\n");
		}
		else
		{
			int weaponIndex = Choice - 2; // 2번부터 무기들
			if (weaponIndex >= 0 && weaponIndex < (int)Choices.size())
			{
				WeaponType selected = Choices[weaponIndex];

				switch (selected)
				{
				case WeaponType::Fire:
					printf("Fire 무기로 공격!\n");
					break;
				case WeaponType::EMP:
					printf("EMP 무기로 공격!\n");
					break;
				case WeaponType::Hit:
					printf("Hit 무기로 공격!\n");
					break;
				}
				Damage = CalculateWeaponDamage(player, *pEnemy, selected);
			}
			else
			{
				printf("잘못된 선택입니다. 기본 공격으로 진행합니다.\n");
			}
		}

		pEnemy->TakeDamage(Damage);

		if (!pEnemy->IsAlive())
		{
			printf("상대를 물리쳤습니다!\n");
			break;
		}

		// --- 적 턴 ---
		pEnemy->ApplyAttack(&player);
		if (!player.IsAlive())
		{
			printf("상대에게 패배하였습니다...\n");
		}
	}
}

int GameManager::CalculateWeaponDamage(Player& player, Enemy& enemy, WeaponType weapon)
{
	int BaseAttack = player.GetAttackPower();

	if (weapon == enemy.GetWeakType())
	{
		return BaseAttack * 2; // 적이 약한 무기 → 데미지 2배
	}
	else if (weapon == enemy.GetStrongType())
	{
		return BaseAttack / 2; // 적이 강한 무기 → 데미지 절반
	}
	else
	{
		return BaseAttack;     // 보통 상성 → 그대로
	}
}


void GameManager::Explore_Discovery()
{
}

void GameManager::Explore_Accident()
{
}
