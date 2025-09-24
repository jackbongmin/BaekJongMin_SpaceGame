#include "Player.h"

void Player::ConsumeFood()
{
    if (Food > 0)
    {
        Food--;
        printf("%s�� �ķ��� 1 �Һ��߽��ϴ�. (���� �ķ�: %d)\n", GetName().c_str(), Food);
    }
    else
    {
        printf("�ķ��� �����մϴ�! �Ϸ簡 ������ ü���� 20 �����մϴ�.\n");
        TakeDamage(HungerPenalty);
    }
}

void Player::ConsumeOxygen(int Amount)
{
    Oxygen -= Amount;
    if (Oxygen < 0) Oxygen = 0;
    printf("��Ұ� %d%% �����߽��ϴ�. ���� ���: %d%%\n", Amount, Oxygen);
}

void Player::AddFood(int Amount)
{
    Food += Amount;
    printf("�ķ� %d�� ȹ���߽��ϴ�! (���� �ķ�: %d)\n", Amount, Food);
}

void Player::AddOxygen(int Amount)
{
    Oxygen += Amount;
    if (Oxygen > 100) Oxygen = 100;
    printf("��Ұ� %d%% ȸ���Ǿ����ϴ�. (���� ���: %d%%)\n", Amount, Oxygen);
}

void Player::ObtainAlienBook()
{
    AlienBook = true;
    printf("�ܰ��� ������ ȹ���߽��ϴ�! ������ ȣ������ 10%% �� ����ϴ�.\n");
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

    printf("%s�� ȣ������ %d ��ŭ �����߽��ϴ�. (����: %d)\n",
        enemy.GetName().c_str(), finalValue, enemy.GetAffinity());
}

void Player::AddWeapon(WeaponType Weapon)
{
    if (!Weapons.contains(Weapon))
    {
        Weapons.insert(Weapon);
        printf("���ο� ���⸦ ȹ���߽��ϴ�! (���� ���� ��: %d)\n", (int)Weapons.size());
    }
}

