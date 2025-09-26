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

// 탐사 및 강제이벤트에서 외계인 접촉시 발생
void Exploreclass::Explore_MeetEnemy(Player& player)
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

// 외계인 접촉 후 커뮤니케이션 실행
void Exploreclass::MeetEnemy_Communicate(Player& player, Enemy* pEnemy)
{
	printf("%s(과)와 대화를 시작합니다.\n", pEnemy->GetName().c_str());
	Sleep(500);

	for (int round = 1; round <= 3; round++)
	{
		printf("\n[%d번째 대화]\n", round);
		if (pEnemy->GetName() == "거미 외계인")
		{
			if (round == 1)
			{
				printf("거미 외계인 : Thrixel wev’no cresthun, spyr’eth glawnor.\n\n");
			}
			if (round == 2)
			{
				printf("거미 외계인 : Crr-sshh tanttt vorethin, arakn’dral sith.\n\n");
			}
			if (round == 3)
			{
				printf("거미 외계인 : Webrae ignor quessh, klith spun’dor.\n\n");
			}
			Sleep(1000);
		}
		else if (pEnemy->GetName() == "해파리 외계인")
		{
			if (round == 1)
			{
				printf("해파리 외계인 : Lu~me~a d~rif~sh~oon, qu~ori~elth i~n slos~~hine.\n\n");
			}
			if (round == 2)
			{
				printf("해파리 외계인 : Gly~~ssha ve’loo~n mar~qual, jell~ith ph~~oor.\n\n");
			}
			if (round == 3)
			{
				printf("해파리 외계인 : Zoo~~nq~uash th~allu~me, o~rbiq~u~eth syla~a.\n\n");
			}
			Sleep(1000);
		}
		else if (pEnemy->GetName() == "외계 로봇")
		{
			if (round == 1)
			{
				printf("외계 로봇 : SYS-404X: PROTOCOL_7Z INITIATED // 0110-EXA RUNMODE\n\n");
			}
			if (round == 2)
			{
				printf("외계 로봇 : CORE-99A:: VECTOR_OVERRIDE >> SIGNAL_001101 LOST\n\n");
			}
			if (round == 3)
			{
				printf("외계 로봇 : UNIT-77Z ENGAGE: ERROR-505 LOOP // REBOOT_12.3\n\n");
			}
			Sleep(1000);
		}
		printf("");
		printf("1. 평화롭게 이야기한다\n");
		printf("2. 교역을 제안한다\n");
		printf("3. 힘을 과시한다\n");

		int choice;
		while (true)
		{
			printf("\n당신의 선택은? >> ");
			if (!(std::cin >> choice))
			{
				std::cin.clear();
				std::cin.ignore(50, '\n');
				printf("잘못입력하셨습니다. 다시 입력하세요.\n");
				continue;
			}

			if (choice != 1 && choice != 2 && choice != 3 )
			{
				printf("잘못입력하셨습니다. 다시 입력하세요.\n");
				continue;
			}
			break;
		}

		switch (choice)
		{
		case 1: // 평화
			if (dynamic_cast<JellyFish*>(pEnemy))
			{
				printf("\n해파리 외계인 : Gly~~ssha\n");
				Sleep(1000);
				printf("(호감도 +15)\n");
				Sleep(1000);
				player.IncreaseEnemyAffinity(*pEnemy, +15);
			}
			else if (dynamic_cast<Spider*>(pEnemy))
			{
				printf("\n거미 외계인 : Crr-sshh..\n");
				Sleep(1000);
				printf("(호감도 -5)\n");
				Sleep(1000);
				player.IncreaseEnemyAffinity(*pEnemy, -5);
			}
			else if (dynamic_cast<Robot*>(pEnemy))
			{
				printf("\n외계로봇 : A!AA@AAA_XA\n");
				Sleep(1000);
				printf("(호감도 -11)\n");
				Sleep(1000);
				player.IncreaseEnemyAffinity(*pEnemy, -11);
			}
			break;

		case 2: // 협상
			if (dynamic_cast<JellyFish*>(pEnemy))
			{
				printf("\n해파리 외계인 : f~sh~oon\n");
				Sleep(1000);
				printf("(호감도 +5)\n");
				Sleep(1000);
				player.IncreaseEnemyAffinity(*pEnemy, +5);
			}
			else if (dynamic_cast<Spider*>(pEnemy))
			{
				printf("\n거미 외계인 : spyr’ettttt!!!\n");
				Sleep(1000);
				printf("(호감도 +10)\n");
				Sleep(1000);
				player.IncreaseEnemyAffinity(*pEnemy, +10);
			}
			else if (dynamic_cast<Robot*>(pEnemy))
			{
				printf("\n외계로봇 : 11101011 10000100 10010000 00100000 11101100 10100011 10111101 11101100 10011101 10110100 11101010 10110010 10100000 11101011 10001011 10100100\n");
				Sleep(1000);
				printf("(호감도 -15)\n");
				Sleep(1000);
				player.IncreaseEnemyAffinity(*pEnemy, -15);
			}
			break;
		case 3: // 전쟁 ㄱㄱ
			if (dynamic_cast<JellyFish*>(pEnemy))
			{
				printf("\n해파리 외계인 :th~allu~me\n");
				Sleep(1000);
				printf("(호감도 -15)\n");
				Sleep(1000);
				player.IncreaseEnemyAffinity(*pEnemy, -15);
			}
			else if (dynamic_cast<Spider*>(pEnemy))
			{
				printf("\n거미 외계인 : klith klith klith \n");
				Sleep(1000);
				printf("(호감도 -11)\n");
				Sleep(1000);
				player.IncreaseEnemyAffinity(*pEnemy, -11);
			}
			else if (dynamic_cast<Robot*>(pEnemy))
			{
				printf("\n외계로봇 : ERROR-404 LOOP\n");
				Sleep(1000);
				printf("(호감도 +10)\n");
				Sleep(1000);
				player.IncreaseEnemyAffinity(*pEnemy, +10);
			}
			break;
		}
		printf("\n현재 호감도: %d\n", pEnemy->GetAffinity());
		Sleep(700);
	}

	// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ 대화 끝남

	int FinalAffinity = pEnemy->GetAffinity();
	printf("\n최종 호감도: %d\n", FinalAffinity);

	if (FinalAffinity < 50)
	{
		Sleep(2000);
		printf("%s이 적대적으로 변했습니다! 전투 돌입!\n", pEnemy->GetName().c_str());
		Sleep(2000);
		MeetEnemy_BattleEvent(player, pEnemy);
	}
	else if (FinalAffinity < 60)
	{
		printf("%s는 경계하며 물러났습니다.\n", pEnemy->GetName().c_str());
		Sleep(1000);
		player.PlayerStat();
		Sleep(1000);
	}
	else
	{
		printf("%s이 호감을 보였습니다!\n", pEnemy->GetName().c_str());
		Sleep(1000);

		int i = rand() % 3;
		switch (i)
		{
		case 0:
			printf("%s이 돌아갔습니다.\n", pEnemy->GetName().c_str());
			break;
		case 1:
			printf("보급품을 줍니다!\n\n");
			player.AddFood(1);
			break;
		case 2:
			printf("보급품을 줍니다!\n\n");
			player.AddOxygen(20);
			break;
		}

		Sleep(1000);
		player.PlayerStat();
		Sleep(1000);
	}
}

// 커뮤니케이션 이후 호감도 부족으로 인한 전투 발생
void Exploreclass::MeetEnemy_BattleEvent(Player& player, Enemy* pEnemy)
{

	printf("전투를 시작합니다.\n\n");

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
		printf("\n");


		int Damage = player.GetAttackPower();

		if (Choice == 1)
		{
			printf("기본 공격!\n");
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
				printf("\n");
			}
			else
			{
				printf("잘못된 선택입니다. 기본 공격으로 진행합니다.\n");
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
				Sleep(1000);
				printf("\n보급품을 줍니다!\n\n");
				Sleep(1000);
				player.AddFood(1);
				break;
			case 2:
				Sleep(1000);
				printf("\n보급품을 줍니다!\n\n");
				Sleep(1000);
				player.AddOxygen(20);
				break;
			}
			Sleep(1000);
			player.PlayerStat();
			Sleep(1000);
			break;
		}


		pEnemy->ApplyAttack(&player);
		if (!player.IsAlive())
		{
			printf("상대에게 패배하였습니다...\n");
		}
		
	}
}

// 전투이벤트 내 상성무기 포함 데미지 계산
int Exploreclass::CalculateWeaponDamage(Player& player, Enemy& enemy, WeaponType weapon)
{
	int BaseAttack = player.GetAttackPower();

	if (weapon == enemy.GetWeakType())
	{
		printf("효과가 대단했다!\n");
		return BaseAttack * 2;
	}
	else if (weapon == enemy.GetStrongType())
	{
		printf("효과가 별로 없었다..\n");
		return BaseAttack / 2;
	}
	else
	{
		return BaseAttack;
	}
}

// 탐사 중 자원 발견
void Exploreclass::Explore_Discovery(Player& player)
{
	Meet meet;
	meet.MeetDiscovery();
	printf("자원을 발견했습니다.\n\n");
	Sleep(1000);
	int i = rand() % 100;

	if (i < 20)
	{
		printf("식량을 1개 발견했습니다.\n");
		player.AddFood(1);
	}
	else if (i < 70)
	{
		printf("산소통을 1개 발견했습니다.\n");
		player.AddOxygen(50);
	}
	else if (i < 90)
	{
		printf("식량을 2개 발견했습니다.\n");
		player.AddFood(2);
	}
	else
	{
		printf("외계인 도감을 발견했습니다.\n");
		player.ObtainAlienBook();
	}
	
	Sleep(1000);
	player.PlayerStat();
	Sleep(1000);
}

// 탐사 중 사고 발생
void Exploreclass::Explore_Accident(Player& player)
{
	Meet meet;
	meet.MeetAccident();
	printf("사고를 당했습니다.\n\n");
	Sleep(1000);

	int i = rand() % 100;

	if (i < 34)
	{
		printf("식량을 잃었습니다.\n");
		player.ConsumeFood();
	}
	else if (i < 67)
	{
		printf("산소를 잃었습니다.\n");
		player.ConsumeOxygen(10);
	}
	else
	{
		printf("데미지를 입었습니다.\n");
		player.TakeDamage(20);
	}
	
	Sleep(1000);
	player.PlayerStat();
	Sleep(1000);
}

