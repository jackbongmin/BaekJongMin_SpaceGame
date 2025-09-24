#include "Actor.h"

void Actor::ApplyAttack(ICanBattle* InTarget)
{
	InTarget->TakeDamage(AttackPower);
}

void Actor::TakeDamage(int InDamage)
{
	SetHealth(Health - InDamage);

	printf("%s�� %d�� ���ظ� �Ծ����ϴ�.\n", Name.c_str(), InDamage);
	printf("(%d/%d)\n", Health, MaxHealth);

	if (!IsAlive())
	{
		//��� ó��
		printf("%s�� �׾����ϴ�.\n", Name.c_str());
	}
}
