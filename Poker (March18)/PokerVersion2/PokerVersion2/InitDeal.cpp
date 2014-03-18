#include "InitDeal.h"


InitDeal::InitDeal()
{
	
}

void InitDeal::InitialDeal(int cash, int cpucash)
{
	Poker a;
	GamePlay g;
	//call the Start method when you want to start a new game
	g.Clear();// clearing all stored variables
	//GamePlay();
	system("cls"); // clearing the screen
	cash = cash; // initializing player cash amount
	cpucash = cpucash; // initializing cpu cash amount
	pot = 0; // initializing pot value to 0
	a.createdeck(deck); // creating a deck of cards
	//a.shuffle(deck); // shuffling the deck
	a.tablecards(deck, 8); // creating the table cards passing value for amount of cards
	// begins at 5, so 8 for 3 cards 9 for 4 cards and 10 for 5 cards, should be able to clear tablecards and pass in
	//new value as long as deck is not shuffled so starts at 8, bet 1 add card bet 2 add another, bet 3 determine winner
	a.playercard(deck);// creates the players hand with 2 cards
	a.cpucard(deck);//creates the players hand with 2 cards
	a.createhand(hand, 25, 40); // draw player cards, passing in hand, 5 and 20 stay the same for location
	a.createtable(tablehand, 5, 17);// drawing the table cards passing in table hand, 5 and 7 stay for location
	g.Game(); // begins the game
}


InitDeal::~InitDeal()
{
}
