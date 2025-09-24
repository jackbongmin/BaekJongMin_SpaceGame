#include "Player.h"

void Player::ConsumeFood()
{
    if (Food > 0)
    {
        Food--;
        printf("%s가 식량을 1 소비했습니다. (남은 식량: %d)\n", GetName().c_str(), Food);
    }
    else
    {
        printf("식량이 부족합니다! 하루가 지나며 체력이 20 감소합니다.\n");
        TakeDamage(HungerPenalty);
    }
}

void Player::ConsumeOxygen(int Amount)
{
    Oxygen -= Amount;
    if (Oxygen < 0) Oxygen = 0;
    printf("산소가 %d%% 감소했습니다. 현재 산소: %d%%\n", Amount, Oxygen);
}

void Player::AddFood(int Amount)
{
    Food += Amount;
    printf("식량 %d를 획득했습니다! (현재 식량: %d)\n", Amount, Food);
}

void Player::AddOxygen(int Amount)
{
    Oxygen += Amount;
    if (Oxygen > 100) Oxygen = 100;
    printf("산소가 %d%% 회복되었습니다. (현재 산소: %d%%)\n", Amount, Oxygen);
}

void Player::ObtainAlienBook()
{
    AlienBook = true;
    printf("외계인 도감을 획득했습니다! 앞으로 호감도를 10%% 더 얻습니다.\n");
}

void Player::IncreaseEnemyAffinity(Enemy& enemy, int BaseValue)
{
    int finalValue = BaseValue;

    
    if (BaseValue > 0 && AlienBook > 0)
    {
        int bonus = 10 * AlienBook;
        finalValue += bonus;
    }

    enemy.AddAffinity(finalValue);

    printf("%s의 호감도가 %d 만큼 증가했습니다. (현재: %d)\n",
        enemy.GetName().c_str(), finalValue, enemy.GetAffinity());
}

void Player::AddWeapon(WeaponType Weapon)
{
    if (!Weapons.contains(Weapon))
    {
        Weapons.insert(Weapon);
        printf("새로운 무기를 획득했습니다! (현재 무기 수: %d)\n", (int)Weapons.size());
    }
}

