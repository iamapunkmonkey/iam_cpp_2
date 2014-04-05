// State.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "State.h"

void Machine::pregame_state()
{
	current->pregame_state(this);
}

void Machine::shuffle_state()
{
	current->shuffle_state(this);
}

void Machine::deal_state()
{
	current->deal_state(this);
}

void Machine::flop_state()
{
	current->flop_state(this);
}

void Machine::river_state()
{
	current->river_state(this);
}

void Machine::turn_state()
{
	current->turn_state(this);
}

void Machine::idle_state()
{
	current->idle_state(this);
}

void Machine::setCurrent(State *s)
{
	current = s;
}

Machine::Machine()
{
	current = new DEAL_STATE();
	cout << '\n';
}

//***************************************************************// //LATER DELETE EXTRA FUNCTIONS THAT DON'T BELONG. For instance state machine = goes from state to state
//****************************Pregame****************************// //we wont need these functions late only the one in front of the current state we will need. (pregame->shuffle)
//***************************************************************// //however IDLE will also need to be here, so we can always go to IDLE if need be.

void PREGAME_STATE::shuffle_state(Machine *m)
{
	cout << " going from PREGAME_STATE to SHUFFLE_STATE";
	cout << "\n";
	m->setCurrent(new SHUFFLE_STATE()); 
}

void PREGAME_STATE::deal_state(Machine *m)
{
	cout << " going from PREGAME_STATE to DEAL_STATE";
	cout << "\n";
	m->setCurrent(new DEAL_STATE()); 
}

void PREGAME_STATE::flop_state(Machine *m)
{
	cout << " going from PREGAME_STATE to FLOP_STATE";
	cout << "\n";
	m->setCurrent(new FLOP_STATE()); 
}

void PREGAME_STATE::river_state(Machine *m)
{
	cout << " going from PREGAME_STATE to RIVER_STATE";
	cout << "\n";
	m->setCurrent(new RIVER_STATE()); 
}

void PREGAME_STATE::turn_state(Machine *m)
{
	cout << " going from PREGAME_STATE to TURN_STATE";
	cout << "\n";
	m->setCurrent(new TURN_STATE()); 
}


//***************************************************************//
//****************************Shuffle****************************//
//***************************************************************//

void SHUFFLE_STATE::pregame_state(Machine *m)
{
	cout << " going from SHUFFLE_STATE to PREGAME_STATE";
	cout << "\n";
	m->setCurrent(new PREGAME_STATE()); 
}

void SHUFFLE_STATE::deal_state(Machine *m)
{
	cout << " going from SHUFFLE_STATE to DEAL_STATE";
	cout << "\n";
	m->setCurrent(new DEAL_STATE()); 
}

void SHUFFLE_STATE::flop_state(Machine *m)
{
	cout << " going from SHUFFLE_STATE to FLOP_STATE";
	cout << "\n";
	m->setCurrent(new FLOP_STATE());
	delete this;
}

void SHUFFLE_STATE::river_state(Machine *m)
{
	cout << " going from SHUFFLE_STATE to RIVER_STATE";
	cout << "\n";
	m->setCurrent(new RIVER_STATE()); 
}

void SHUFFLE_STATE::turn_state(Machine *m)
{
	cout << " going from SHUFFLE_STATE to TURN_STATE";
	cout << "\n";
	m->setCurrent(new TURN_STATE()); 
}
//***************************************************************//
//*****************************DEAL*****************************//
//***************************************************************//

void DEAL_STATE::pregame_state(Machine *m)
{
	cout << " going from DEAL_STATE to PREGAME_STATE";
	cout << "\n";
	m->setCurrent(new PREGAME_STATE()); 
}

void DEAL_STATE::shuffle_state(Machine *m)
{
	cout << " going from DEAL_STATE to SHUFFLE_STATE";
	cout << "\n";
	m->setCurrent(new SHUFFLE_STATE()); 
}

void DEAL_STATE::flop_state(Machine *m)
{
	cout << " going from DEAL_STATE to FLOP_STATE";
	cout << "\n";
	m->setCurrent(new FLOP_STATE()); 
}

void DEAL_STATE::river_state(Machine *m)
{
	cout << " going from DEAL_STATE to RIVER_STATE";
	cout << "\n";
	m->setCurrent(new RIVER_STATE());
}

void DEAL_STATE::turn_state(Machine *m)
{
	cout << " going from DEAL_STATE to TURN_STATE";
	cout << "\n";
	m->setCurrent(new TURN_STATE()); 
}
//***************************************************************//
//*****************************FLOP******************************//
//***************************************************************//

void FLOP_STATE::pregame_state(Machine *m)
{
	cout << "\n";
	cout << " going from FLOP_STATE to PREGAME_STATE";
	cout << "\n";
	m->setCurrent(new PREGAME_STATE()); 
}

void FLOP_STATE::shuffle_state(Machine *m)
{
	cout << "\n";
	cout << " going from FLOP_STATE to SHUFFLE_STATE";
	cout << "\n";
	m->setCurrent(new SHUFFLE_STATE()); 
}


void FLOP_STATE::deal_state(Machine *m)
{
	cout << "\n";
	cout << " going from FLOP_STATE to DEAL_STATE";
	cout << "\n";
	m->setCurrent(new DEAL_STATE()); 
}


void FLOP_STATE::turn_state(Machine *m)
{
	cout << " going from FLOP_STATE to TURN_STATE";
	cout << "\n";
	m->setCurrent(new TURN_STATE()); 
}

void FLOP_STATE::river_state(Machine *m)
{
	cout << " going from FLOP_STATE to RIVER_STATE";
	cout << "\n";
	m->setCurrent(new RIVER_STATE()); 
}


//***************************************************************//
//*****************************RIVER*****************************//
//***************************************************************//

void RIVER_STATE::pregame_state(Machine *m)
{
	cout << " going from RIVER_STATE to PREGAME_STATE";
	cout << "\n";
	m->setCurrent(new PREGAME_STATE());
}
void RIVER_STATE::shuffle_state(Machine *m)
{
	cout << " going from RIVER_STATE to SHUFFLE_STATE";
	cout << "\n";
	m->setCurrent(new SHUFFLE_STATE()); 
}

void RIVER_STATE::deal_state(Machine *m)
{
	cout << " going from RIVER_STATE to DEAL_STATE";
	cout << "\n";
	m->setCurrent(new DEAL_STATE()); 
}

void RIVER_STATE::flop_state(Machine *m)
{
	cout << " going from RIVER_STATE to FLOP_STATE";
	cout << "\n";
	m->setCurrent(new FLOP_STATE()); 
}

void RIVER_STATE::turn_state(Machine *m)
{
	cout << " going from RIVER_STATE to TURN_STATE";
	cout << "\n";
	m->setCurrent(new TURN_STATE()); 
}

//***************************************************************//
//*****************************TURN******************************//
//***************************************************************//

void TURN_STATE::pregame_state(Machine *m)
{
	cout << " going from TURN_STATE to PREGAME_STATE";
	cout << "\n";
	m->setCurrent(new PREGAME_STATE());
}
void TURN_STATE::shuffle_state(Machine *m)
{
	cout << " going from TURN_STATE to SHUFFLE_STATE";
	cout << "\n";
	m->setCurrent(new SHUFFLE_STATE());
}

void TURN_STATE::deal_state(Machine *m)
{
	cout << " going from TURN_STATE to DEAL_STATE";
	cout << "\n";
	m->setCurrent(new DEAL_STATE());
}

void TURN_STATE::flop_state(Machine *m)
{
	cout << " going from TURN_STATE to FLOP_STATE";
	cout << "\n";
	m->setCurrent(new FLOP_STATE());
}

void TURN_STATE::river_state(Machine *m)
{
	cout << " going from TURN_STATE to RIVER_STATE";
	cout << "\n";
	m->setCurrent(new RIVER_STATE());
}

//***************************************************************//
//*****************************IDLE******************************//
//***************************************************************//
int main()
{
	void(Machine:: *ptrs[])() =
	{
		&Machine::pregame_state, &Machine::shuffle_state, &Machine::deal_state, &Machine::flop_state, &Machine::turn_state, &Machine::river_state
	};
	Machine fsm;
	int num;
	while (1)
	{
		cout << "Enter Pregame(0)/Shuffle(1)/Deal(2)/Flop(3)/Turn(4)/River(5): ";
		cin >> num;
		cout << "\n";
		(fsm.*ptrs[num])();
	}
}