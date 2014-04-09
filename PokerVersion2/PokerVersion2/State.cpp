// State.cpp : Defines the entry point for the console application.
//
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

void Machine::setCurrent(State *s)
{
	current = s;
}

Machine::Machine()
{
	current = new PREGAME_STATE();
	cout << '\n';
}

//***************************************************************//
//****************************Pregame****************************//
//***************************************************************//

void PREGAME_STATE::shuffle_state(Machine *m)
{
	//cout << " going from PREGAME_STATE to SHUFFLE_STATE";
	//cout << "\n";
	
	m->setCurrent(new SHUFFLE_STATE()); //SWITCHES STATE TO SHUFFLE_STATE CREATES NEW INSTANCE
	delete this;//DELETES PREGAME_STATE
}

void PREGAME_STATE::deal_state(Machine *m)
{
	cout << " going from PREGAME_STATE to DEAL_STATE";
	cout << "\n";
	m->setCurrent(new DEAL_STATE()); //SWITCHES STATE TO DEAL_STATE CREATES NEW INSTANCE
	delete this;//DELETES PREGAME_STATE
}

void PREGAME_STATE::flop_state(Machine *m)
{
	cout << " going from PREGAME_STATE to FLOP_STATE";
	cout << "\n";
	m->setCurrent(new FLOP_STATE()); //SWITCHES STATE TO FLOP_STATE CREATES NEW INSTANCE
	delete this;//DELETES PREGAME_STATE
}

//***************************************************************//
//****************************Shuffle****************************//
//***************************************************************//

void SHUFFLE_STATE::pregame_state(Machine *m)
{
	cout << " going from SHUFFLE_STATE to DEAL_STATE";
	cout << "\n";
	m->setCurrent(new PREGAME_STATE()); //SWITCHES STATE TO DEAL_STATE CREATES NEW INSTANCE
	delete this;//DELETES SHUFFLE_STATE
}

void SHUFFLE_STATE::deal_state(Machine *m)
{
	cout << " going from SHUFFLE_STATE to DEAL_STATE";
	cout << "\n";
	m->setCurrent(new DEAL_STATE()); //SWITCHES STATE TO DEAL_STATE CREATES NEW INSTANCE
	delete this;//DELETES SHUFFLE_STATE
}

void SHUFFLE_STATE::flop_state(Machine *m)
{
	cout << " going from SHUFFLE_STATE to FLOP_STATE";
	cout << "\n";
	m->setCurrent(new FLOP_STATE());
	delete this;
}

//***************************************************************//
//*****************************DEAL*****************************//
//***************************************************************//

void DEAL_STATE::pregame_state(Machine *m)
{
	cout << " going from SHUFFLE_STATE to PREGAME_STATE";
	cout << "\n";
	m->setCurrent(new PREGAME_STATE()); //SWITCHES STATE TO DEAL_STATE CREATES NEW INSTANCE
	delete this;//DELETES DEAL_STATE
}

void DEAL_STATE::shuffle_state(Machine *m)
{
	cout << " going from DEAL_STATE to SHUFFLE_STATE";
	cout << "\n";
	m->setCurrent(new SHUFFLE_STATE()); //SWITCHES STATE TO SHUFFLE_STATE CREATES NEW INSTANCE
	delete this; //DELETES DEAL_STATE
}

void DEAL_STATE::flop_state(Machine *m)
{
	cout << " going from DEAL_STATE to FLOP_STATE";
	cout << "\n";
	m->setCurrent(new SHUFFLE_STATE()); //SWITCHES STATE TO SHUFFLE_STATE CREATES NEW INSTANCE
	delete this; //DELETES DEAL_STATE
}

//***************************************************************//
//*****************************FLOP******************************//
//***************************************************************//

void FLOP_STATE::pregame_state(Machine *m)
{
	cout << "\n";
	cout << " going from SHUFFLE_STATE to DEAL_STATE";
	cout << "\n";
	m->setCurrent(new PREGAME_STATE()); //SWITCHES STATE TO DEAL_STATE CREATES NEW INSTANCE
	delete this;//DELETES FLOP_STATE
}

void FLOP_STATE::shuffle_state(Machine *m)
{
	cout << "\n";
	cout << " going from FLOP_STATE to SHUFFLE_STATE";
	cout << "\n";
	m->setCurrent(new SHUFFLE_STATE()); //SWITCHES STATE TO SHUFFLE_STATE CREATES NEW INSTANCE
	delete this; //DELETES FLOP_STATE
}


void FLOP_STATE::deal_state(Machine *m)
{
	cout << "\n";
	cout << " going from FLOP_STATE to DEAL_STATE";
	cout << "\n";
	m->setCurrent(new DEAL_STATE()); //SWITCHES STATE TO SHUFFLE_STATE CREATES NEW INSTANCE
	delete this; //DELETES FLOP_STATE
}

//int main()
//{
//	void(Machine:: *ptrs[])() =
//	{
//		&Machine::pregame_state, &Machine::shuffle_state, &Machine::deal_state, &Machine::flop_state
//	};
//	Machine fsm;
//	int num;
//	while (1)
//	{
//		cout << "Enter Pregame(0)/Shuffle(1)/Deal(2)/Flop(3): ";
//		cin >> num;
//		cout << "\n";
//		(fsm.*ptrs[num])();
//	}
//}