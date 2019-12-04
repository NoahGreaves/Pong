#pragma once
#include "Engine/Public/EngineInterface.h"
#include "Engine/Public/SDL.h"

class GameObject
{
public:
	GameObject(exEngineInterface* mEngine);
	~GameObject();

	virtual void Draw();

	exEngineInterface* pEngine;
};

