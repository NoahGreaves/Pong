#include "ClassBall.h"



ClassBall::ClassBall()
{
}


ClassBall::~ClassBall()
{
}

int ClassBall::GetPosition() 
{
	return { mPositionx };
	return { mPositiony };	
}

void ClassBall::Update() 
{
	float mVelocityx = mPositionx + 5;
	float mVelocityy = mPositiony + 5;
}
