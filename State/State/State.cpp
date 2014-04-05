// State.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "State.h"


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



void SHUFFLE_STATE::deal_state(Machine *m)
{
	cout << " going from SHUFFLE_STATE to DEAL_STATE";
	m->setCurrent(new DEAL_STATE()); //SWITCHES STATE TO DEAL_STATE CREATES NEW INSTANCE
	delete this;//DELETES SHUFFLE_STATE
}

void SHUFFLE_STATE::flop_state(Machine *m)
{
	cout << " going from SHUFFLE_STATE to FLOP_STATE";

	m->setCurrent(new FLOP_STATE());
	delete this;
}

Machine::Machine()
{
	current = new DEAL_STATE();
	cout << '\n';
}

int main()
{
	void(Machine:: *ptrs[])() =
	{
		&Machine::shuffle_state, &Machine::deal_state, &Machine::flop_state
	};
	Machine fsm;
	int num;
	while (1)
	{
		cout << "Enter Shuffle(0)/Deal(1)/Flop(2): ";
		cin >> num;
		cout << "\n";
		(fsm.*ptrs[num])();
	}
}