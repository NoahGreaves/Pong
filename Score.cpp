#include "Score.h"
#include "Engine/Public/EngineInterface.h"
#include <iostream>
#include <string>

using namespace std;
Score::Score(exEngineInterface* pEngine, int mFont)
{
	playerScore = 0;
	enemyScore = 0;
}


Score::~Score()
{
}

void Score::Update(exEngineInterface* pEngine, int mFont, Ball* ball)
{
	pEngine->DrawText(mFont, { 300, 50 }, "PONG", { 1, 255, 52, 0 }, 1);

	// if the ball passes the player the enemy gains a point
	if (ball->position.x >= 800) 
	{
		playerScore++;
		// the ball spawn position after a the enemy scores
		ball->position.x = 360.0f;	
		ball->position.y = 360.0f;
		ball->velocity = { -200.0f, -50.0f };

	}
	// if the ball passes the enemy the palyer gains a point
	else if (ball->position.x <= 0) 
	{
		enemyScore++;
		// the ball spawn position after a the player scores
		ball->position.x = 360.0f;
		ball->position.y = 360.0f;
		ball->velocity = { 200.0f, -50.0f };
	}
	// draw player score
	pEngine->DrawText(mFont, { 450, 100 }, to_string(enemyScore).c_str(), { 1, 255, 52, 0 }, 1);
	// draw enemy score
	pEngine->DrawText(mFont, { 230, 100 }, to_string(playerScore).c_str(), { 1, 255, 52, 0 }, 1);
}
