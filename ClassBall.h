#pragma once
class ClassBall
{
private:
	int x = 0;
	int y = 0;

public:
	ClassBall();
	~ClassBall();

	int mPositionx = x;
	int mPositiony = y;

	int GetPosition();

	void Update();
};

