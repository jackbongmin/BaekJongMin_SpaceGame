#include "Actor.h"
#include <Windows.h>

// 전투시 공격
void Actor::ApplyAttack(ICanBattle* InTarget)
{
	InTarget->TakeDamage(AttackPower);
}

// 해당객체에게 데미지 입력
void Actor::TakeDamage(int InDamage)
{
	SetHealth(Health - InDamage);

	printf("%s(이)가 %d의 피해를 입었습니다.\n", Name.c_str(), InDamage);
	printf("%s HP : (%d/%d)\n\n", Name.c_str(), Health, MaxHealth);
	Sleep(500);

	if (!IsAlive())
	{
		//사망 처리
		printf("%s(이)가 죽었습니다.\n", Name.c_str());
	}
}

// 해당객체에게 체력 회복
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
