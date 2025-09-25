/*
														 ███╗   ██╗███████╗██╗  ██╗██████╗  █████╗  ██████╗███████╗    ██╗   ██╗███████╗
														 ████╗  ██║██╔════╝ ██╗██╗ ██╔══██╗██╔══██╗██╔════╝██╔════╝    ██║   ██║██╔════╝
														 ██╔██╗ ██║█████╗    ███║  ██████╔╝███████║██║     █████╗      ██║   ██║███████╗
														 ██║╚██╗██║██╔══╝   ██═██║ ██╔═══╝ ██╔══██║██║     ██╔══╝      ██║   ██║ ╚═══██║
														 ██║ ╚████║███████╗██║  ██║██║     ██║  ██║╚██████╗███████╗     ╚████╔╝ ███████║
														 ╚═╝  ╚═══╝╚══════╝╚═╝  ╚═╝╚═╝     ╚═╝  ╚═╝ ╚═════╝╚══════╝      ╚═══╝  ╚══════╝
*/
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
void GameManager::Intro()
{
	printf("\n                                                            /^\\                      \n");
	printf("                                                           /   \\                     \n");
	printf("                                                          /  o  \\                    \n");
	printf("                                                         /   o   \\                   \n");
	printf("                                                        /    o    \\                  \n");
	printf("                                                       |-_________-|                  \n");
	printf("                                                       |           |                  \n");
	printf("                      __                               |   __      |                  \n");
	printf("                     (__)                             /|  [  ]     |\\                \n");
	printf("                      ||                             / |  [  ]     | \\               \n");
	printf("                   .------.                         /__|  [__]     |__\\              \n");
	printf("                .-'        `-.                          \\         /                  \n");
	printf("              .'_     _     _ `.                         \\       /                   \n");
	printf("             / [_]   [ ]   [_] \\                         /=======\\                   \n");
	printf("          __|  [_]   [_]   [_]  |__                     /=========\\                  \n");
	printf("        /    \\                 /     \\                 /===========\\                 \n");
	printf("       I      `. ._________. .'       I                  ||  ||  ||                   \n");
	printf("       \\                             /                   VV  VV  VV                   \n");
	printf("        '-'-----------------------'-'                   vvv  vv  vvv                  \n");
	printf("           I_I       I_I       I_I                     vvvv  vv  vvvv                 \n\n");

	printf(" _   _  ______  __   __  _____             _____  ______      _    _    _____        \n");
	printf("| \\ | ||  ____| \\ \\ / / |  __ \\    /\\     / ____||  ____|    | |  | |  / ____|  \n");
	printf("|  \\| || |__     \\ V /  | |__) |  /  \\   | |     | |__       | |  | | | (___      \n");
	printf("| . ` ||  __|     > <   | |___/  / /\\ \\  | |     |  __|      | |  | |  \\___ \\    \n");
	printf("| |\\  || |____   / . \\  | |     / ____ \\ | |___  | |____     | |__| |  ____) |    \n");
	printf("|_| \\_||______| /_/ \\_\\ |_|    /_/    \\_\\ \\_____||______|     \\____/  |_____/ \n\n");
	
	Meet meet;
	meet.aaaaa();

}

void GameManager::MainRoot()
{
	while (Day < Day_End)
	{
		//printf("\n======= Day %d =======\n\n", Day);
		Sleep(500);
		printf("=");
		Sleep(25);
		printf("=");
		Sleep(25);
		printf("=");
		Sleep(25);
		printf("=");
		Sleep(25);
		printf("=");
		Sleep(25);
		printf("=");
		Sleep(25);
		printf("=");
		Sleep(25);
		printf(" ");
		Sleep(25);
		printf("D");
		Sleep(25);
		printf("a");
		Sleep(25);
		printf("y");
		Sleep(25);
		printf(" ");
		Sleep(25);
		printf("%d", Day);
		Sleep(25);
		printf(" ");
		Sleep(25);
		printf("=");
		Sleep(25);
		printf("=");
		Sleep(25);
		printf("=");
		Sleep(25);
		printf("=");
		Sleep(25);
		printf("=");
		Sleep(25);
		printf("=");
		Sleep(25);
		printf("=\n\n");
		Sleep(25);

		if (Day == 3 || Day == 6 || Day == 9)
		{
			Sleep(1000);
			printf("\n※ %d일차 강제 이벤트 ※\n\n", Day);
			Sleep(1000);

			int i = rand() % 100;
			if (i < 50)
			{
				printf("외계인이 찾아왔습니다.\n");
				Explore_MeetEnemy();
			}
			else if (i < 75)
			{
				Explore_Discovery();
			}
			else
			{
				Explore_Accident();
			}
		}


		ActionPoint = MaxActionPoint;

		DoExplore = DoRest = DoResearch = false;

		DailyAction();

		Day++;
		Sleep(500);
		player.ConsumeFood();
		Sleep(500);
		player.ConsumeOxygen(15);
		Sleep(500);
		player.PlayerStat();

		printf("=");
		Sleep(25);
		printf("=");
		Sleep(25);
		printf("=");
		Sleep(25);
		printf("=");
		Sleep(25);
		printf("=");
		Sleep(25);
		printf("=");
		Sleep(25);
		printf("=");
		Sleep(25);
		printf("=");
		Sleep(25);
		printf("=");
		Sleep(25);
		printf("=");
		Sleep(25);
		printf("=");
		Sleep(25);
		printf("=");
		Sleep(25);
		printf("=");
		Sleep(25);
		printf("=");
		Sleep(25);
		printf("=");
		Sleep(25);
		printf("=");
		Sleep(25);
		printf("=");
		Sleep(25);
		printf("=");
		Sleep(25);
		printf("=");
		Sleep(25);
		printf("=");
		Sleep(25);
		printf("=\n\n");
		Sleep(25);
		printf("       ");
		Sleep(25);
		printf("다");
		Sleep(50);
		printf("음");
		Sleep(50);
		printf("날\n\n");
		Sleep(500);
		//printf("\n=====================\n");
		//printf("\n       다음날\n");

	}
	Sleep(2000);
	printf("10일이 지났습니다.\n");
	Sleep(2000);
}

void GameManager::DailyAction()
{
	bool EndDay = false;

	while (ActionPoint > 0 && !EndDay)
	{

		printf("무엇을 하시겠습니까?(AP : %d)\n", ActionPoint);
		Sleep(500);
		printf("[1.탐험 2.휴식 3.연구]\n");

		int MaxChoice = 3;

		if (ActionPoint < MaxActionPoint)
		{
			MaxChoice = 4;
		}

		int Choice = 0;
		std::cin >> Choice;
		printf("\n");

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

		const int End_ActionPoint = 0;
		if (ActionPoint == End_ActionPoint)
		{
			printf("행동력이 다 떨어졌습니다. 자동으로 다음 날로 넘어갑니다.\n");
		}
	}
}

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
	printf(".\n");
	Sleep(500);

	int i = rand() % 3;
	switch (i)
	{
	case 0 :
		Explore_MeetEnemy();
		break;
	case 1 :
		Explore_Discovery();
		break;
	case 2 :
		Explore_Accident();
		break;
	}

	
}

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
	printf(".\n");
	Sleep(500);

	player.Heal(30);
	player.ConsumeOxygen(5);
	Sleep(500);
	player.PlayerStat();

}

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
	printf(".\n");
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
			Sleep(500);
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
			Sleep(500);
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
			Sleep(500);
		}
		printf("");
		printf("1. 평화롭게 이야기한다\n");
		printf("2. 교역을 제안한다\n");
		printf("3. 힘을 과시한다\n");

		int choice;
		printf("\n당신의 선택은? >> ");
		std::cin >> choice;

		switch (choice) {
		case 1: // 평화
			if (dynamic_cast<JellyFish*>(pEnemy))
			{
				printf("\n해파리 외계인 : Gly~~ssha\n");
				Sleep(800);
				printf("(호감도 +15)\n\n");
				Sleep(800);
				player.IncreaseEnemyAffinity(*pEnemy, +15);
			}
			else if (dynamic_cast<Spider*>(pEnemy))
			{
				printf("\n거미 외계인 : Crr-sshh..\n");
				Sleep(800);
				printf("(호감도 -5)\n\n");
				Sleep(800);
				player.IncreaseEnemyAffinity(*pEnemy, -5);
			}
			else if (dynamic_cast<Robot*>(pEnemy))
			{
				printf("\n외계로봇 : A!AA@AAA_XA\n");
				Sleep(800);
				printf("(호감도 -7)\n\n");
				Sleep(800);
				player.IncreaseEnemyAffinity(*pEnemy, -7);
			}
			break;

		case 2: // 협상
			if (dynamic_cast<JellyFish*>(pEnemy))
			{
				printf("\n해파리 외계인 : f~sh~oon\n");
				Sleep(800);
				printf("(호감도 +5)\n\n");
				Sleep(800);
				player.IncreaseEnemyAffinity(*pEnemy, +5);
			}
			else if (dynamic_cast<Spider*>(pEnemy))
			{
				printf("\n거미 외계인 : spyr’ettttt!!!\n");
				Sleep(800);
				printf("(호감도 10)\n\n");
				Sleep(800);
				player.IncreaseEnemyAffinity(*pEnemy, +10);
			}
			else if (dynamic_cast<Robot*>(pEnemy))
			{
				printf("\n외계로봇 : 11101011 10000100 10010000 00100000 11101100 10100011 10111101 11101100 10011101 10110100 11101010 10110010 10100000 11101011 10001011 10100100\n");
				Sleep(800);
				printf("(호감도 -15)\n\n");
				Sleep(800);
				player.IncreaseEnemyAffinity(*pEnemy, -15);
			}
			break;
		case 3: // 전쟁 ㄱㄱ
			if (dynamic_cast<JellyFish*>(pEnemy))
			{
				printf("\n해파리 외계인 :th~allu~me\n");
				Sleep(800);
				printf("(호감도 -15)\n\n");
				Sleep(800);
				player.IncreaseEnemyAffinity(*pEnemy, -15);
			}
			else if (dynamic_cast<Spider*>(pEnemy))
			{
				printf("\n거미 외계인 : klith klith klith \n");
				Sleep(800);
				printf("(호감도 -10)\n\n");
				Sleep(800);
				player.IncreaseEnemyAffinity(*pEnemy, -10);
			}
			else if (dynamic_cast<Robot*>(pEnemy))
			{
				printf("\n외계로봇 : ERROR-404 LOOP\n");
				Sleep(800);
				printf("(호감도 +5)\n\n");
				Sleep(800);
				player.IncreaseEnemyAffinity(*pEnemy, +5);
			}
			break;
		}
		printf("현재 호감도: %d\n", pEnemy->GetAffinity());
		Sleep(700);
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
		Sleep(500);
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

void GameManager::MeetEnemy_BattleEvent(Player& player, Enemy* pEnemy)
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
		return BaseAttack * 2;
	}
	else if (weapon == enemy.GetStrongType())
	{
		return BaseAttack / 2;
	}
	else
	{
		return BaseAttack;
	}
}


void GameManager::Explore_Discovery()
{
	Meet meet;
	meet.MeetDiscovery();
	printf("자원을 발견했습니다.\n\n");
	Sleep(1000);
	int i = rand() % 100;
	
	if (i < 30)
	{
		printf("식량을 1개 발견했습니다.\n");
		player.AddFood(1);
	}
	else if (i < 60)
	{
		printf("산소통을 1개 발견했습니다. 산소가 50% 상승됩니다.\n");
		player.AddOxygen(50);
	}
	else if (i < 80)
	{
		printf("식량을 2개 발견했습니다.\n");
		player.AddFood(2);
	}
	else
	{
		printf("외계인 도감을 발견했습니다.\n");
		player.ObtainAlienBook();
	}
	Sleep(500);
	player.PlayerStat();
	Sleep(500);
}

void GameManager::Explore_Accident()
{
	Meet meet;
	meet.MeetAccident();
	printf("사고를 당했습니다.\n");
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
		player.ConsumeOxygen(20);
	}
	else
	{
		printf("데미지를 입었습니다.\n");
		player.TakeDamage(20);
	}
	Sleep(500);
	player.PlayerStat();
	Sleep(500);
}
