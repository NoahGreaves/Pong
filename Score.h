#pragma once
#include "Engine/Public/EngineInterface.h"
#include "Ball.h"

class Score
{
public:
	Score(exEngineInterface* pEngine ,int mFont);
	~Score();

	void Update(exEngineInterface* pEngine, int mFont, Ball* ball);

private:
	int playerScore;
	int enemyScore;
};

