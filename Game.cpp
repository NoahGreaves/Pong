//
// * ENGINE-X
// * SAMPLE GAME
//
// + Game.cpp
// implementation of MyGame, an implementation of exGameInterface
//

#include "Game/Private/Game.h"

#include "Engine/Public/EngineInterface.h"
#include "Engine/Public/SDL.h"


//-----------------------------------------------------------------
//-----------------------------------------------------------------

const char* gWindowName = "Sample EngineX Game";

//-----------------------------------------------------------------
//-----------------------------------------------------------------

MyGame::MyGame()
	: mEngine( nullptr )
	, mFontID( -1 )
	, mPlayerUp( false )
	, mPlayerDown( false )
	, mEnemyUp ( false )
	, mEnemyDown ( false )
{
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

MyGame::~MyGame()
{
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::Initialize( exEngineInterface* pEngine )
{
	mEngine = pEngine;

	mFontID = mEngine->LoadFont( "Mario-Kart-DS.ttf", 32 );

	aBall = new Ball(pEngine);
	
	score = new Score(pEngine, mFontID);

	// player paddle position
	exVector2 playerPosition;
	playerPosition.x = 50;
	playerPosition.y = 50;

	// creates a new player paddle
	playerPaddle = new Paddle(pEngine, playerPosition);
	playerPaddle->normal.x = 1.0f;
	playerPaddle->normal.y = 0.0f;

	// enemy paddle position
	exVector2 enemyPosition;
	enemyPosition.x = 700;
	enemyPosition.y = 520;

	// creates a new enemy paddle
	enemyPaddle = new Paddle(pEngine, enemyPosition);

	enemyPaddle->normal.x = -1.0f;
	enemyPaddle->normal.y = 0.0f;
	
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

const char* MyGame::GetWindowName() const
{
	return gWindowName;
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::GetClearColor( exColor& color ) const
{
	color.mColor[0] = 60;
	color.mColor[1] = 0;
	color.mColor[2] = 255;
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::OnEvent( SDL_Event* pEvent )
{
	
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::OnEventsConsumed()
{
	int nKeys = 0;
	const Uint8 *pState = SDL_GetKeyboardState( &nKeys );

	// player paddle controls
	mPlayerUp = pState[SDL_SCANCODE_W];
	mPlayerDown = pState[SDL_SCANCODE_S];

	// enemy paddle controls	
	mEnemyUp = pState[SDL_SCANCODE_UP];
	mEnemyDown = pState[SDL_SCANCODE_DOWN];
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------


void MyGame::Run( float fDeltaT )
{
	// exVector2 playerSize;
	// exVector2 enemySize;

	// size of player paddle
	// playerSize.x = mPlayerPaddle.x + 20.0f;
	// playerSize.y = mPlayerPaddle.y + 70.0f;

	// size of enemy paddle
	// enemySize.x = mEnemyPaddle.x + 20.0f;
	// enemySize.y = mEnemyPaddle.y + 70.0f;

	// the ball
	aBall->Collision(playerPaddle);
	//aBall->Collision(enemyPaddle);
	aBall->Update(fDeltaT, playerPaddle, enemyPaddle);
	aBall->Draw();

	// player paddle
	playerPaddle->ChangePosition(mPlayerUp, mPlayerDown);
	playerPaddle->Update();
	playerPaddle->Draw();

	// enemy paddle
	enemyPaddle->ChangePosition(mEnemyUp, mEnemyDown);
	enemyPaddle->Update();
	enemyPaddle->Draw();

	score->Update(mEngine, mFontID, aBall);

	//mEngine->DrawBox( mPlayerPaddle, playerSize, c, 1 );

	//mEngine->DrawBox( mEnemyPaddle, enemySize, c, 1 );
}