#include "GameStateManager.h"


GameStateManager::GameStateManager()
{

}

GameStateManager::~GameStateManager()
{


}

void GameStateManager::StateMachine()
{
	switch (temp.current_state)
	{
	case GS_Idle:

		break;
	case GS_Shuffle:

		break;
	case GS_Deal:

		break;
	case GS_Flop:

		break;

	case GS_River:

		break;
	case GS_Turn:

		break;

	case GS_Post:

		break;

	case GS_Checks:

		break;

	case GS_Kill:

		break;
	}
}
