#ifndef GAMESTATEMANAGER_H
#define GAMESTATEMANAGER_H


struct gp_State
{
	GameState current_state;
	GameState next_state;
	GameState previous_state;
};

enum GameState
{
	GS_Shuffle = -1,
	GS_Deal = 0,
	GS_Idle = 1,
	GS_Flop = 2,
	GS_River = 3,
	GS_Turn = 4
	//IDLE will be called when game is waiting for user to input
};

class GameStateManager
{
public:
	void StateMachine();
	GameStateManager();
	~GameStateManager();

private:
	gp_State temp;
};





#endif