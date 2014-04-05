#ifndef STATE_H
#define STATE_H

#include "stdafx.h"
#include <iostream>

using namespace std;

class Machine
{
	class State *current;
public:
	Machine();
	void setCurrent(State *s)
	{
		current = s;
	}
	void shuffle_state();
	void deal_state();
	void flop_state();
};

class State
{
public:
	virtual void shuffle_state(Machine *m)
	{
		cout << " already SHUFFLE\n";
	}
	virtual void deal_state(Machine *m)
	{
		cout << " already DEAL\n";
	}
	virtual void flop_state(Machine *m)
	{
		cout << " already FLOP\n";
	}
};

class SHUFFLE_STATE : public State
{
public:
	SHUFFLE_STATE()
	{
		cout << " SHUFFLE_STATE-ctor ";
	};
	~SHUFFLE_STATE()
	{
		cout << " dtor-SHUFFLE_STATE\n";
	};
	void deal_state(Machine *m);
	void flop_state(Machine *m);
};

class DEAL_STATE : public State
{
public:
	DEAL_STATE()
	{
		cout << " DEAL_STATE-ctor ";
	};
	~DEAL_STATE()
	{
		cout << " dtor-DEAL_STATE\n";
	};
	void shuffle_state(Machine *m)
	{
		cout << " going from DEAL_STATE to SHUFFLE_STATE";
		m->setCurrent(new SHUFFLE_STATE()); //SWITCHES STATE TO SHUFFLE_STATE CREATES NEW INSTANCE
		delete this; //DELETES DEAL_STATE
	}

	void flop_state(Machine *m)
	{
		cout << " going from DEAL_STATE to FLOP_STATE";
		m->setCurrent(new SHUFFLE_STATE()); //SWITCHES STATE TO SHUFFLE_STATE CREATES NEW INSTANCE
		delete this; //DELETES DEAL_STATE
	}
};

class FLOP_STATE : public State
{
public:
	FLOP_STATE()
	{
		cout << " FLOP_STATE-ctor ";
	};
	~FLOP_STATE()
	{
		cout << " dtor-FLOP_STATE\n";
	};
	void shuffle_state(Machine *m)
	{
		cout << " going from FLOP_STATE to SHUFFLE_STATE";
		m->setCurrent(new SHUFFLE_STATE()); //SWITCHES STATE TO SHUFFLE_STATE CREATES NEW INSTANCE
		delete this; //DELETES FLOP_STATE
	}


	void deal_state(Machine *m)
	{
		cout << " going from FLOP_STATE to DEAL_STATE";
		m->setCurrent(new DEAL_STATE()); //SWITCHES STATE TO SHUFFLE_STATE CREATES NEW INSTANCE
		delete this; //DELETES FLOP_STATE
	}
};
#endif