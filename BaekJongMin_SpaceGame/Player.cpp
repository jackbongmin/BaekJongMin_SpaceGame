#include "Player.h"

void Player::PlayerStat()
{
    printf("\n===플레이어===\n");
    printf("체력 : %d/%d\n", GetHealth(), GetMaxHealth());
    printf("산소 : %d%%\n", GetOxygen(), GetMaxOxygen());
    printf("식량 : %d\n", GetFood());
    printf("==============\n\n");
}

void Player::ConsumeFood()
{
    if (Food > 0)
    {
        Food--;
        printf("%s가 식량을 1 소비했습니다.\n", GetName().c_str());
    }
    else
    {
        printf("차감될 식량이 없습니다.\n");
        //TakeDamage(HungerPenalty);
    }

}

void Player::ConsumeOxygen(int Amount)
{
    Oxygen -= Amount;
    if (Oxygen < 0) Oxygen = 0;
    printf("산소가 %d%% 감소했습니다.\n", Amount);
}

void Player::AddFood(int Amount)
{
    Food += Amount;
    printf("식량 %d를 획득했습니다!\n", Amount);
}

void Player::AddOxygen(int Amount)
{
    Oxygen += Amount;

    if (Oxygen > MaxOxygen)
    {
        Oxygen = MaxOxygen;
    }
    printf("산소가 %d%% 회복되었습니다.\n", Amount);
}

void Player::ObtainAlienBook()
{
    AlienBook = true;
    printf("외계인 도감을 획득했습니다! 앞으로 호감도를 10%% 더 얻습니다.\n");
}

void Player::IncreaseEnemyAffinity(Enemy& enemy, int BaseValue)
{
    int FinalValue = BaseValue;

    
    if (BaseValue > 0 && AlienBook > 0)
    {
        int Bonus = 10 * AlienBook;
        FinalValue += Bonus;
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

void Player::AddWeapon(WeaponType Weapon)
{
    if (!Weapons.contains(Weapon))
    {
        Weapons.insert(Weapon);
        printf("새로운 무기를 획득했습니다! (현재 무기 수: %d)\n", (int)Weapons.size());
    }
}

void Player::IncreaseHighAffinityCount()
{
    HighAffinityCount++;
}

void Player::IncreaseLowAffinityCount()
{
    LowAffinityCount++;
}

