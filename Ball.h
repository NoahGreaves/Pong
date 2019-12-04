#pragma once
#include "GameObject.h"
#include "Paddle.h"

class Ball : public GameObject
{
public:
	exColor c;
	exVector2 position;
	exVector2 velocity;
	// exVector2 direction;
	
	float deltaY;
	int radius;

	Ball(exEngineInterface* mEngine);
	~Ball();

	void Update(float fDeltaT, Paddle* playerPaddle, Paddle* enemyPaddle);
	void Draw() override;
	bool Collision(Paddle* paddle);
	void CollisionResponse(float deltaX, float delatY, Paddle* paddle);
};