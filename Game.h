//
// * ENGINE-X
// * SAMPLE GAME
//
// + Game.h
// definition of MyGame, an implementation of exGameInterface
//

#include "Game/Public/GameInterface.h"
#include "Engine/Public/EngineTypes.h"
#include "Ball.h"
#include "Paddle.h"
#include "Score.h"

//-----------------------------------------------------------------
//-----------------------------------------------------------------

class MyGame : public exGameInterface
{
public:

								MyGame();
	virtual						~MyGame();

	virtual void				Initialize( exEngineInterface* pEngine );

	virtual const char*			GetWindowName() const;
	virtual void				GetClearColor( exColor& color ) const;

	virtual void				OnEvent( SDL_Event* pEvent );
	virtual void				OnEventsConsumed();

	virtual void				Run( float fDeltaT );

	Paddle*						GetPlayerPaddle() { return playerPaddle; }
	Paddle*						GetEnemyPaddle() { return enemyPaddle; }

private:

	exEngineInterface*			mEngine;

	int							mFontID;

	// paddle movement
	bool						mPlayerUp;
	bool						mPlayerDown;
	bool						mEnemyUp;
	bool						mEnemyDown;

	// MY STUFF
	exVector2					mTextPosition, mPlayerPaddle, mEnemyPaddle, mBall;

	Ball *aBall;

	Paddle *playerPaddle, *enemyPaddle;

	Score *score;
};
