#include <Windows.h>
#include "Player.h"

// 플레이어 상황 인터페이스
void Player::PlayerStat()
{
    Sleep(1000);
    printf("\n==[%s]==========\n", GetName().c_str());
    printf("└ 체력 : %d/%d \n", GetHealth(), GetMaxHealth());
    printf("└ 산소 : %d%%  \n", GetOxygen(), GetMaxOxygen());
    printf("└ 식량 : %d    \n\n", GetFood());
    //printf("====================\n\n");
}

// 식량 손실
void Player::ConsumeFood()
{
    if (Food > 0)
    {
        Food--;
        printf("%s의 식량 1개가 줄었습니다.\n", GetName().c_str());
    }
    else
    {
        printf("차감될 식량이 없습니다.\n");
        //TakeDamage(HungerPenalty);
    }

}

// 산소 손실
void Player::ConsumeOxygen(int Amount)
{
    Oxygen -= Amount;
    if (Oxygen < 0) Oxygen = 0;
    printf("산소가 %d%% 감소했습니다.\n", Amount);
}

// 식량 획득
void Player::AddFood(int Amount)
{
    Food += Amount;
    printf("식량 %d개를 획득했습니다!\n", Amount);
}

// 산소 획득
void Player::AddOxygen(int Amount)
{
    Oxygen += Amount;

    if (Oxygen > MaxOxygen)
    {
        Oxygen = MaxOxygen;
    }
    printf("산소가 %d%% 회복되었습니다.\n", Amount);
}

// 외계인도감 획득
void Player::ObtainAlienBook()
{
    //AlienBook = true;
    AlienBook++;
    printf("외계인 도감을 획득했습니다! 앞으로 호감도를 3을 더 얻습니다.\n");
}

// 외계인 도감으로 인한 외계인 커뮤니케이션 시 호감도 중첩
void Player::IncreaseEnemyAffinity(Enemy& enemy, int BaseValue)
{
    int FinalValue = BaseValue;

    
    if (BaseValue > 0 && AlienBook > 0)
    {
        int Bonus = 3 * AlienBook;
        FinalValue += Bonus;
        printf("(외계인 도감 %d개 보유, 추가 호감도 +%d)\n", AlienBook, Bonus);
    }

    enemy.AddAffinity(FinalValue);

    if (enemy.GetAffinity() >= 70)
    {
        HighAffinityCount++;
    }
    else if (enemy.GetAffinity() <= 20)
    {
        LowAffinityCount++;
    }
    //printf("%s의 호감도가 %d 만큼 증가했습니다. (현재: %d)\n",enemy.GetName().c_str(), FinalValue, enemy.GetAffinity());
}

// 연구로 인한 무기 획득
void Player::AddWeapon(WeaponType Weapon)
{
    if (!Weapons.contains(Weapon))
    {
        Weapons.insert(Weapon);
        printf("새로운 무기를 획득했습니다! (현재 무기 수: %d)\n", (int)Weapons.size());
    }
}

// 엔딩조건_특정 호감도 달성시 카운트
void Player::IncreaseHighAffinityCount()
{
    HighAffinityCount++;
}

void Player::IncreaseLowAffinityCount()
{
    LowAffinityCount++;
}

