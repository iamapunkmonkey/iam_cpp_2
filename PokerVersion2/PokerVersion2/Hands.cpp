#include "Hands.h"


Machine *m;
Deck<string> dk;
SHUFFLE_STATE ss;

vector<string> Hands::createdeck(vector<string>& deck)
{
	//Deck<string> dk;
	//deck = dk.createdeck(deck);
	//deck = dk.shuffle(deck);
	deck = dk.createdeck(deck);
	deck = dk.shuffle(deck);
	//m->setCurrent(new SHUFFLE_STATE());
	//ss.setDeck(deck);
	return deck;
}


//pushback to hands
vector<string> Hands::playercard(vector<string>& deck,vector<string> hand)
{

	hand.clear();

	size_t  j = 0;

	for (j = 0; j < 2; j++)
	{
		hand.push_back(deck[j]);
	}

	return hand;
}
vector<string> Hands::cpucard(vector<string>&deck,vector<string> cpuhand)
{
	cpuhand.clear();
	size_t  z;

	for (z = 2; z < 4; z++)
	{
		cpuhand.push_back(deck[z]);
	}
	return cpuhand;
}
vector<string> Hands::tablecards(vector<string>& deck,vector<string>tablehand, int x)
{
	tablehand.clear();

	for (int j = 5; j < x; j++)
	{
		tablehand.push_back(deck[j]);
	}
	return tablehand;
}

vector<string> Hands::completeHand(vector<string> tablehand, vector<string> passedHand)
{
	vector<string>completeHand;

	completeHand.clear();

	for (string item : tablehand)
	{
		completeHand.push_back(item);
	}
	for (string item : passedHand)
	{
		completeHand.push_back(item);
	}

	return completeHand;

}

vector<char> Hands::getSuit(vector<string>passedHand)
{
	vector<char> passedSuits;
	passedSuits.clear();
	for (string item : passedHand)
	{
		passedSuits.push_back(item.at(1));
	}
	return passedSuits;
}
vector<int> Hands::handValue(vector<string>passedhand)
{
	int n;
	vector<int> passedValues;
	passedValues.clear();
	for (string item : passedhand)
	{
		if (item.at(0) == *"2")
		{
			n = 2;
		}
		if (item.at(0) == *"3")
		{
			n = 3;
		}
		if (item.at(0) == *"4")
		{
			n = 4;
		}
		if (item.at(0) == *"5")
		{
			n = 5;
		}
		if (item.at(0) == *"6")
		{
			n = 6;
		}
		if (item.at(0) == *"7")
		{
			n = 7;
		}
		if (item.at(0) == *"8")
		{
			n = 8;
		}

		if (item.at(0) == *"9")
		{
			n = 9;
		}

		if (item.at(0) == *"T")
		{
			n = 10;
		}
		if (item.at(0) == *"J")
		{
			n = 11;
		}
		if (item.at(0) == *"Q")
		{
			n = 12;
		}
		if (item.at(0) == *"K")
		{
			n = 13;
		}
		if (item.at(0) == *"A")
		{
			n = 14;
		}
		passedValues.push_back(n);
	}
	return passedValues;
}