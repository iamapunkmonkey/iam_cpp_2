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
	void state1();
	void state2();
	void state3();
};

class State
{
public:
	virtual void state1(Machine *m)
	{
		cout << "   already STATE1\n";
	}
	virtual void state2(Machine *m)
	{
		cout << "   already STATE2\n";
	}
	virtual void state3(Machine *m)
	{
		cout << "   already STATE3\n";
	}
};

class STATE1 : public State
{
public:
	STATE1()
	{
		cout << "   STATE1-ctor ";
	};
	~STATE1()
	{
		cout << "   dtor-STATE1\n";
	};
	void state2(Machine *m);
	void state3(Machine *m);
};

class STATE2 : public State
{
public:
	STATE2()
	{
		cout << "   STATE2-ctor ";
	};
	~STATE2()
	{
		cout << "   dtor-STATE2\n";
	};
	void state1(Machine *m)
	{
		cout << "   going from STATE2 to STATE1";
		m->setCurrent(new STATE1()); //SWITCHES STATE TO STATE1 CREATES NEW INSTANCE
		delete this; //DELETES STATE2
	}

	void state3(Machine *m)
	{
		cout << "   going from STATE2 to STATE3";
		m->setCurrent(new STATE1()); //SWITCHES STATE TO STATE1 CREATES NEW INSTANCE
		delete this; //DELETES STATE2
	}
};

class STATE3 : public State
{
public:
	STATE3()
	{
		cout << "   STATE3-ctor ";
	};
	~STATE3()
	{
		cout << "   dtor-STATE3\n";
	};
	void state1(Machine *m)
	{
		cout << "   going from STATE3 to STATE1";
		m->setCurrent(new STATE1()); //SWITCHES STATE TO STATE1 CREATES NEW INSTANCE
		delete this; //DELETES STATE3
	}


	void state2(Machine *m)
	{
		cout << "   going from STATE3 to STATE2";
		m->setCurrent(new STATE2()); //SWITCHES STATE TO STATE1 CREATES NEW INSTANCE
		delete this; //DELETES STATE3
	}
};
#endif