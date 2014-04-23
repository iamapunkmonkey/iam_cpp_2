#ifndef STATE_H
#define STATE_H

#include <iostream>
#include "Aesthetics.h"
#include "GamePlay.h"
#include "Checks.h"
#include "Poker.h"
#include "Deck.h"
#include "DrawCard.h"
#include "Hands.h"

using namespace std;

class Machine
{
	class State *current;
public:
	Machine();
	void setCurrent(State *s);
	void pregame_state();
	void shuffle_state();
	void deal_state();
	void flop_state();
};

class State
{
public:
	Aesthetics aesthetics;
	GamePlay gp;
	virtual void pregame_state(Machine *m)
	{
		//cout << " already PREGAME\n";
	}

	virtual void shuffle_state(Machine *m)
	{
		//cout << " already SHUFFLE\n";
	}
	virtual void deal_state(Machine *m)
	{
		//cout << " already DEAL\n";
	}
	virtual void flop_state(Machine *m)
	{
		//cout << " already FLOP\n";
	}


};

class PREGAME_STATE : public State
{
public:
	PREGAME_STATE()
	{
		system("cls");
		cout << " PREGAME_STATE-ctor ";
		aesthetics.SetWindow(200, 55);
		aesthetics.SetWindow(100, 55); // Set windows size
		aesthetics.header(); // calling our game header
		aesthetics.MainMenu(); // calling our menu system
	}

	~PREGAME_STATE()
	{
		cout << " dtor-PREGAME_STATE\n";
	}

	void shuffle_state(Machine *m);
	void deal_state(Machine *m);
	void flop_state(Machine *m);
};

class SHUFFLE_STATE : public State
{
public:
	vector<string> deck;
	Deck<string> dk;

	 SHUFFLE_STATE()
	{
		setDeck(deck);
	};
	~SHUFFLE_STATE()
	{
		cout << " dtor-SHUFFLE_STATE\n";
	};

	void pregame_state(Machine *m);
	void deal_state(Machine *m);
	void flop_state(Machine *m);

	void setDeck(vector<string>& temp);
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

	void pregame_state(Machine *m);
	void shuffle_state(Machine *m);
	void flop_state(Machine *m);
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

	void pregame_state(Machine *m);
	void shuffle_state(Machine *m);
	void deal_state(Machine *m);
};
#endif