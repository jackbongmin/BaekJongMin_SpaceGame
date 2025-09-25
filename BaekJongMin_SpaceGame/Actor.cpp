#include "Actor.h"
#include <Windows.h>

void Actor::ApplyAttack(ICanBattle* InTarget)
{
	InTarget->TakeDamage(AttackPower);
}

void Actor::TakeDamage(int InDamage)
{
	SetHealth(Health - InDamage);

	printf("%s(이)가 %d의 피해를 입었습니다.\n", Name.c_str(), InDamage);
	printf("(%d/%d)\n", Health, MaxHealth);
	Sleep(500);

	if (!IsAlive())
	{
		//사망 처리
		printf("%s(이)가 죽었습니다.\n", Name.c_str());
	}
}

void Actor::Heal(int InHeal)
{
	SetHealth(Health + InHeal);

	printf("%s(이)가 %d의 체력을 회복했습니다.\n", Name.c_str(), InHeal);
	printf("(%d/%d)\n", Health, MaxHealth);
	Sleep(500);

	if (Health >= MaxHealth)
	{
		printf("체력이 완전히 회복되었습니다.\n");
	}
	
}
