#include <Windows.h>
#include "Player.h"

void Player::PlayerStat()
{
    Sleep(1000);
    printf("\n==[%s]==========\n", GetName().c_str());
    printf("�� ü�� : %d/%d \n", GetHealth(), GetMaxHealth());
    printf("�� ��� : %d%%  \n", GetOxygen(), GetMaxOxygen());
    printf("�� �ķ� : %d    \n\n", GetFood());
    //printf("====================\n\n");
}

void Player::ConsumeFood()
{
    if (Food > 0)
    {
        Food--;
        printf("%s�� �ķ� 1���� �پ����ϴ�.\n", GetName().c_str());
    }
    else
    {
        printf("������ �ķ��� �����ϴ�.\n");
        //TakeDamage(HungerPenalty);
    }

}

void Player::ConsumeOxygen(int Amount)
{
    Oxygen -= Amount;
    if (Oxygen < 0) Oxygen = 0;
    printf("��Ұ� %d%% �����߽��ϴ�.\n", Amount);
}

void Player::AddFood(int Amount)
{
    Food += Amount;
    printf("�ķ� %d�� ȹ���߽��ϴ�!\n", Amount);
}

void Player::AddOxygen(int Amount)
{
    Oxygen += Amount;

    if (Oxygen > MaxOxygen)
    {
        Oxygen = MaxOxygen;
    }
    printf("��Ұ� %d%% ȸ���Ǿ����ϴ�.\n", Amount);
}

void Player::ObtainAlienBook()
{
    //AlienBook = true;
    AlienBook++;
    printf("�ܰ��� ������ ȹ���߽��ϴ�! ������ ȣ������ 6�� �� ����ϴ�.\n");
}

void Player::IncreaseEnemyAffinity(Enemy& enemy, int BaseValue)
{
    int FinalValue = BaseValue;

    
    if (BaseValue > 0 && AlienBook > 0)
    {
        int Bonus = 6 * AlienBook;
        FinalValue += Bonus;
        printf("(�ܰ��� ���� %d�� ����, �߰� ȣ���� +%d)\n", AlienBook, Bonus);
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
    //printf("%s�� ȣ������ %d ��ŭ �����߽��ϴ�. (����: %d)\n",enemy.GetName().c_str(), FinalValue, enemy.GetAffinity());
}

void Player::AddWeapon(WeaponType Weapon)
{
    if (!Weapons.contains(Weapon))
    {
        Weapons.insert(Weapon);
        printf("���ο� ���⸦ ȹ���߽��ϴ�! (���� ���� ��: %d)\n", (int)Weapons.size());
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

