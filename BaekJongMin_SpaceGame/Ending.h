#pragma once
#include "Player.h"

class Ending
{
public:

	void EndingCheck(Player& Inplayer, int InDay);

private:
	void SurvivalEnding();
	void HappyEnding();
	void BadEnding();
};

