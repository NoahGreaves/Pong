#include "Paddle.h"



Paddle::Paddle(exEngineInterface* mEngine, exVector2 mPlacement) : GameObject(mEngine)
{
	// colour of the paddles
	c = { 255, 233, 25, 255 };

	// where the paddles are on the screen
	position = mPlacement;

	// width and height of the paddle
	width = 20;
	height = 70;

	// half the width and half the height of the player and enemy paddles
	width_half = width * 0.5f;
	height_half = height * 0.5f;

	// the direction the paddle is traveling in 
	direction = 1;
}

Paddle::~Paddle()
{
}

void Paddle::Update()
{
	// keeps the paddles in the game window
	if ((position.y) < 0)
	{
		position.y += 10;
	}
	if ((position.y + height) > 650)
	{
		position.y -= 10;
	}
}

void Paddle::Draw()
{
	// draws the paddles in specific position
	exVector2 p1 = { position.x - (width * 0.5f), position.y - (height * 0.5f) };
	exVector2 p2 = { position.x + (width * 0.5f), position.y + (height * 0.5f) };
	pEngine->DrawBox(p1, p2, c, 0);
}

void Paddle::ChangePosition(bool up, bool down)
{
	// speed of player paddle movement up
	if (up)
	{
		position.y -= 10.0f;
	}
	// speed of player paddle movement down
	else if (down)
	{
		position.y += 10.0f;
	}
}

