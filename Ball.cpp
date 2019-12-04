#include "Ball.h"
#include <cmath>
#include "Game/Private/Game.h"
#include <iostream>
#include <string>

using namespace std;
Ball::Ball(exEngineInterface* pEngine) : GameObject(pEngine)
{
	// The ball colour
	c.mColor[0] = 25;
	c.mColor[1] = 255;
	c.mColor[2] = 0;
	c.mColor[3] = 255;

	// the ball spawn location
	position.x = 300.0f;
	position.y = 300.0f;

	// size of the ball
	radius = 15.0f;

	// velocity of the ball
	velocity = { -200.0f, 0 };
}

Ball::~Ball()
{
}

void Ball::Update(float fDeltaT, Paddle* playerPaddle, Paddle* enemyPaddle)
{	
	Collision(playerPaddle);
	Collision(enemyPaddle);
	position.x += velocity.x * fDeltaT;
	position.y += velocity.y * fDeltaT;

	// collision detection for the top of the game window
	if (position.y - radius < 0)
	{
		// the normal vector for the top of the window
		exVector2 normalTop = { 0, -1 };
		// the dot product of the balls velocity and the normal of the top of the game window
		float dotProduct = velocity.x * normalTop.x + velocity.y * normalTop.y;

		// calculates the new X velocity and the new Y velocity after the collision
		float velX = velocity.x - 2 * dotProduct * normalTop.x;
		float velY = velocity.y - 2 * dotProduct * normalTop.y;
		// the new velocity
		velocity = { velX , velY };
	}
	else if (position.y + radius > kViewportHeight)
	{
		// the normal vector for the top of the window
		exVector2 normalBottom = { 0, 1 };
		// the dot product of the balls velocity and the normal of the top of the game window
		float dotProduct = velocity.x * normalBottom.x + velocity.y * normalBottom.y;

		// calculates the new X velocity and the new Y velocity after the collision
		float velX = velocity.x - 2 * dotProduct * normalBottom.x;
		float velY = velocity.y - 2 * dotProduct * normalBottom.y;
		// the new velocity
		velocity = { velX , velY };
	}
}

// draw the ball
void Ball::Draw()
{
	pEngine->DrawCircle(position, radius, c, 0);
}


// checks if there was a collision and gives the normal
bool Ball::Collision(Paddle* paddle)
{
	// X normal 
	float deltaX = position.x - fmax(paddle->position.x - paddle->width_half, fmin(position.x, (paddle->position.x + paddle->width_half)));
	
	// Y normal
	float deltaY = position.y - fmax(paddle->position.y - paddle->height_half, fmin(position.y, (paddle->position.y + paddle->height_half)));

	// calculates the distance between the balls center and edge of the paddle
	float distance = ((deltaX * deltaX) + (deltaY * deltaY));

	exVector2 pos;
	pos.x = 300.0f;
	pos.y = 300.0f;

	exColor c;
	c.mColor[0] = 255;
	c.mColor[3] = 255;

	if (paddle->position.x < 300.0f)
	{
		pEngine->DrawText(0, pos, std::to_string(distance).c_str(), c, 0);
	}

	// calculates the normal of the ball
	if (distance < (radius * radius))
	{
		CollisionResponse(deltaX, deltaY, paddle);
		return true;
	}
	else 
	{
		return false;
	}
}


exVector2 Normalize(exVector2 v)
{
	float sqrLength, invLength;

	sqrLength = v.x * v.x + v.y * v.y;
	invLength = (1.0f / sqrt(sqrLength));
	v.x *= invLength;
	v.y *= invLength;
	return v;
}

float Dot(exVector2 a, exVector2 b)
{
	return ((a.x * b.x) + (a.y * b.y));
}


// the response for when the ball collides with the player or enemy paddle
void Ball::CollisionResponse(float deltaX, float deltaY, Paddle* paddle)
{
	extern MyGame gGame;

	// player and enemy paddle and ball position
	exVector2 paddlePos = paddle->position;
	exVector2 ballPos = position;
	exVector2 paddleToBall = { paddlePos.x - ballPos.x, paddlePos.y - ballPos.y };

	// distance between the ball and player paddle normalized
	exVector2 paddleToBallNormalized = Normalize(paddleToBall);

	float d = Dot(paddle->normal, paddleToBallNormalized);

	if (d > 0.0f)
	{
		return;
	}

	// the reflection vector (the angle the ball bounces off at)
	exVector2 r;
	r.x = paddleToBallNormalized.x - (2 * paddle->normal.x) * d;
	r.y = paddleToBallNormalized.y - (2 * paddle->normal.y) * d;

	velocity.x = r.x * 350.0f;
	velocity.y = r.y * 350.0f;
}

