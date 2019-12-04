#pragma once
#include "GameObject.h"

class Paddle : public GameObject
{
public:
	exColor c;
	exVector2 position;
	exVector2 normal;
	float width;
	float height;
	float width_half;
	float height_half;
	float direction;

	Paddle(exEngineInterface* mEngine, exVector2 mPlacement);
	~Paddle();

	void Update();
	void Draw() override;
	void ChangePosition(bool up, bool down);
};

