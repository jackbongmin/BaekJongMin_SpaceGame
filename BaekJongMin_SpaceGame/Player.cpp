#include "Player.h"

void Player::PlayerStat()
{
    printf("\n===�÷��̾�===\n");
    printf("ü�� : %d/%d\n", GetHealth(), GetMaxHealth());
    printf("��� : %d%%\n", GetOxygen(), GetMaxOxygen());
    printf("�ķ� : %d\n", GetFood());
    printf("==============\n\n");
}

void Player::ConsumeFood()
{
    if (Food > 0)
    {
        Food--;
        printf("%s�� �ķ��� 1 �Һ��߽��ϴ�.\n", GetName().c_str());
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
    AlienBook = true;
    printf("�ܰ��� ������ ȹ���߽��ϴ�! ������ ȣ������ 10%% �� ����ϴ�.\n");
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

