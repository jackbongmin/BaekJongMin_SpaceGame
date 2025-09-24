#include "Actor.h"

void Actor::ApplyAttack(ICanBattle* InTarget)
{
	InTarget->TakeDamage(AttackPower);
}

void Actor::TakeDamage(int InDamage)
{
	SetHealth(Health - InDamage);

	printf("%s가 %d의 피해를 입었습니다.\n", Name.c_str(), InDamage);
	printf("(%d/%d)\n", Health, MaxHealth);

	if (!IsAlive())
	{
		//사망 처리
		printf("%s가 죽었습니다.\n", Name.c_str());
	}
}
