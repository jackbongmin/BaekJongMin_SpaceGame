#include "Actor.h"
#include <Windows.h>

// ������ ����
void Actor::ApplyAttack(ICanBattle* InTarget)
{
	InTarget->TakeDamage(AttackPower);
}

// �ش簴ü���� ������ �Է�
void Actor::TakeDamage(int InDamage)
{
	SetHealth(Health - InDamage);

	printf("%s(��)�� %d�� ���ظ� �Ծ����ϴ�.\n", Name.c_str(), InDamage);
	printf("%s HP : (%d/%d)\n\n", Name.c_str(), Health, MaxHealth);
	Sleep(500);

	if (!IsAlive())
	{
		//��� ó��
		printf("%s(��)�� �׾����ϴ�.\n", Name.c_str());
	}
}

// �ش簴ü���� ü�� ȸ��
void Actor::Heal(int InHeal)
{
	SetHealth(Health + InHeal);

	printf("%s(��)�� %d�� ü���� ȸ���߽��ϴ�.\n", Name.c_str(), InHeal);
	printf("(%d/%d)\n", Health, MaxHealth);
	Sleep(500);

	if (Health >= MaxHealth)
	{
		printf("ü���� ������ ȸ���Ǿ����ϴ�.\n");
	}
	
}
