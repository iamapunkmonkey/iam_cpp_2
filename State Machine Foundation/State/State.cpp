// State.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "State.h"


void Machine::state1()
{
	current->state1(this);
}

void Machine::state2()
{
	current->state2(this);
}

void Machine::state3()
{
	current->state3(this);
}



void STATE1::state2(Machine *m)
{
	cout << "   going from STATE1 to STATE2";
	m->setCurrent(new STATE2()); //SWITCHES STATE TO STATE2 CREATES NEW INSTANCE
	delete this;//DELETES STATE1
}

void STATE1::state3(Machine *m)
{
	cout << "    going from STATE1 to STATE3";
	
	m->setCurrent(new STATE3());
	delete this;
}

Machine::Machine()
{
	current = new STATE2();
	cout << '\n';
}

int main()
{
	void(Machine:: *ptrs[])() =
	{
		&Machine::state1, &Machine::state2, &Machine::state3
	};
	Machine fsm;
	int num;
	while (1)
	{
		cout << "Enter STATE1(0)/STATE2(1)/STATE3(2): ";
		cin >> num;
		cout << "\n";
		(fsm.*ptrs[num])();
	}
}

