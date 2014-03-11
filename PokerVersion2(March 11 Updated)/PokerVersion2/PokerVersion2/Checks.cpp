#include "Aesthetics.h"
#include "GamePlay.h"
#include "Checks.h"
#include "Poker.h"


Checks::Checks()
{

}
int Checks::ispair(vector<int> dvalues)
{
	vector<int> test;

	sort(dvalues.begin(), dvalues.end());

	for (size_t z = 0; z < dvalues.size(); z++)
	{
		for (size_t j = 0; j < dvalues.size(); j++)
		{
			if (j != z)
			{
				if (dvalues[z] == dvalues[j])
				{
					test.push_back(dvalues[z]);

				}
			}
		}
	} // end loop.
	if (test.size() >= 2 && test.size() < 4)
	{
		return 1;
	}

	if (test.size() >= 4 && test.size() <= 6)
	{
		return 2;
	}

	else
		return 0;
}

int Checks::flush(vector<char> dsuits)
{
	vector<int> test;
	test.clear();
	
	sort(dsuits.begin(), dsuits.end());

	for (size_t z = 0; z < dsuits.size(); z++)
	{
		for (size_t j = 1; j < dsuits.size(); j++)
		{
			if (j != z)
			{
				if (dsuits[z] == dsuits[j])
				{
					test.push_back(dvalues[j]);

				}
			}
		}
	} // end loop.
	if (test.size() >= 20 && test.size() <= 35)
	{
		return 1;
	}
	else
		return 0;

	return 0;


}
//working
int Checks::straight(vector<int>dvalues)
{
	sort(dvalues.begin(), dvalues.end());

	if (dvalues.size() == 5)
	{
		if ((dvalues[4] - dvalues[3] == 1) && (dvalues[3] - dvalues[2] == 1) && (dvalues[2] - dvalues[1] == 1) && (dvalues[1] - dvalues[0] == 1))
			return 1;
		else
			return 0;
	}
	if (dvalues.size() == 6)
	{
		if ((dvalues[4] - dvalues[3] == 1) && (dvalues[3] - dvalues[2] == 1) && (dvalues[2] - dvalues[1] == 1) && (dvalues[1] - dvalues[0] == 1))
			return 1;
		else if ((dvalues[5] - dvalues[4] == 1) && (dvalues[4] - dvalues[3] == 1) && (dvalues[3] - dvalues[2] == 1) && (dvalues[2] - dvalues[1] == 1))
			return 1;
		else
			return 0;
	}
	if (dvalues.size() == 7)
	{
		if ((dvalues[4] - dvalues[3] == 1) && (dvalues[3] - dvalues[2] == 1) && (dvalues[2] - dvalues[1] == 1) && (dvalues[1] - dvalues[0] == 1))
			return 1;
		else if ((dvalues[5] - dvalues[4] == 1) && (dvalues[4] - dvalues[3] == 1) && (dvalues[3] - dvalues[2] == 1) && (dvalues[2] - dvalues[1] == 1))
			return 1;
		else if ((dvalues[6] - dvalues[5] == 1) && (dvalues[5] - dvalues[4] == 1) && (dvalues[4] - dvalues[3] == 1) && (dvalues[3] - dvalues[2] == 1))
			return 1;
		else
			return 0;
	}
	else
		return 0;
} // end straight.
//working
int Checks::threeofakind(vector<int> dvalues)
{

	vector<int> test;
	test.clear();

	sort(dvalues.begin(), dvalues.end());

	for (size_t z = 0; z < dvalues.size(); z++)
	{
		for (size_t j = 1; j < dvalues.size(); j++)
		{
			if (j != z)
			{
				if (dvalues[z] == dvalues[j])
				{
					test.push_back(dvalues[z]);

				}
			}
		}
	} // end loop.
	if (test.size() >= 6 && test.size() <= 9)
	{
		return 1;
	}

	else
		return 0;

}//working
//working 
int Checks::fourofakind(vector<int> dvalues)
{
	vector<int> test;
	test.clear();
	//int z;
	sort(dvalues.begin(), dvalues.end());

	for (size_t z = 0; z < dvalues.size(); z++)
	{
		for (size_t j = 1; j < dvalues.size(); j++)
		{
			if (j != z)
			{
				if (dvalues[z] == dvalues[j])
				{
					test.push_back(dvalues[j]);

				}
			}
		}
	} // end loop.
	if (test.size() >= 12 && test.size() <= 22)
	{
		return 1;
	}
	else
		return 0;

}
//working
int Checks::fullhouse(vector<int> dvalues)
{
	vector<int> test;
	test.clear();
	
	sort(dvalues.begin(), dvalues.end());

	for (size_t z = 0; z < dvalues.size(); z++)
	{
		for (size_t j = 0; j < dvalues.size(); j++)
		{
			if (j != z)
			{
				if (dvalues[z] == dvalues[j])
				{
					test.push_back(dvalues[j]);

				}
			}
		}
	} // end loop.
	if (test.size() >= 8 && test.size() <= 12)
	{
		return 1;
	}
	else
		return 0;

	return 0;
}
//
int Checks::FindHighCard()
{
	vector<int> testhand;
	vector<int> cputesthand;
	int val;
	for (string item : hand)
	{
		if (item.at(0) == *"A")
		{
			val = 14;
		}
		if (item.at(0) == *"K")
		{
			val = 13;
		}
		if (item.at(0) == *"Q")
		{
			val = 12;
		}
		if (item.at(0) == *"J")
		{
			val = 11;
		}
		if (item.at(0) == *"T")
		{
			val = 10;
		}
		if (item.at(0) == *"9")
		{
			val = 9;
		}
		if (item.at(0) == *"8")
		{
			val = 8;
		}
		if (item.at(0) == *"7")
		{
			val = 7;
		}
		if (item.at(0) == *"6")
		{
			val = 6;
		}
		if (item.at(0) == *"5")
		{
			val = 5;
		}
		if (item.at(0) == *"4")
		{
			val = 4;
		}
		if (item.at(0) == *"3")
		{
			val = 3;
		}
		if (item.at(0) == *"2")
		{
			val = 2;
		}


		testhand.push_back(val);
	}
	for (string item : cpuhand)
	{
		if (item.at(0) == *"A")
		{
			val = 14;
		}
		if (item.at(0) == *"K")
		{
			val = 13;
		}
		if (item.at(0) == *"Q")
		{
			val = 12;
		}
		if (item.at(0) == *"J")
		{
			val = 11;
		}
		if (item.at(0) == *"T")
		{
			val = 10;
		}
		if (item.at(0) == *"9")
		{
			val = 9;
		}
		if (item.at(0) == *"8")
		{
			val = 8;
		}
		if (item.at(0) == *"7")
		{
			val = 7;
		}
		if (item.at(0) == *"6")
		{
			val = 6;
		}
		if (item.at(0) == *"5")
		{
			val = 5;
		}
		if (item.at(0) == *"4")
		{
			val = 4;
		}
		if (item.at(0) == *"3")
		{
			val = 3;
		}
		if (item.at(0) == *"2")
		{
			val = 2;
		}



		cputesthand.push_back(val);
	}
	sort(testhand.begin(), testhand.end());
	sort(cputesthand.begin(), cputesthand.end());

	if (testhand[0] > cputesthand[0])
		return 1;
	if (testhand[0] < cputesthand[0])
		return 2;
	if (testhand[0] == cputesthand[0])
		return 3;

		

}
// determing hand checks
int Checks::DetermineHand(vector<int >values, vector<char>suits)
{
	dvalues.empty();
	dsuits.empty();
	dvalues = values;
	dsuits = suits;
	if (foldc == true)
	{
		inhand = "FOLD!";
	}

	//gotoxy(30, 20);          // checking the hands starting with the highest possible hand and going down from there.
	sort(dvalues.begin(), dvalues.end());
	if ((flush(dsuits)) && (straight(dvalues)))
	{


		if (dvalues[7] == 14)
		{
			inhand = "Royal Flush!!";
			return 100;
		}
		else
		{
			inhand = "Straight Flush!!";
			return 90;
		}
	}

	else if (flush(dsuits) == 1)
	{
		inhand = "Flush!!";
		return 80;

	}
	else if (straight(dvalues) == 1)
	{
		inhand = "Straight!!";
		return 70;

	}

	else if (fourofakind(dvalues) == 1)
	{
		inhand = "Four of a Kind!!";
		return 60;

	}
	else if (fullhouse(dvalues) == 1)
	{
		inhand = "Fullhouse!!";
		return 50;

	}

	else if (threeofakind(dvalues) == 1)
	{
		inhand = "Three of a Kind!!";
		return 40;

	}
	else if (ispair(dvalues) == 2)
	{
		inhand = "Two Pair!!";
		return 30;
	}
	else if (ispair(dvalues) == 1)
	{
		inhand = "Pair!!";
		return 20;

	}





	else {

		inhand = "Absolutely Nothing!!";


		return dvalues.back();
	}
}

//determine the winner
void Checks::determine(int PlayerHandValue, int CpuHandValue)
{
	if (PlayerHandValue == CpuHandValue)
	{
		int test = FindHighCard();

		if (test == 1)
		{
			result = "You Win";
			cash = cash + pot;
		}
		if (test == 2)
		{
			result = "You Lose";
			cpucash = cpucash + pot;
		}
		if (test == 3)
		{

			result = "Split Pot";
			int pot1 = pot / 2;
			int pot2 = pot;
			cash = cash + pot1;
			cpucash = cpucash + pot1;
		}
	}
	if (PlayerHandValue > CpuHandValue)
	{
		result = "You Win";
		cash = cash + pot;
	}
	if (PlayerHandValue < CpuHandValue)
	{
		result = "You Lose";
		cpucash = cpucash + pot;
	}

}
void Checks::FoldValue()
{
	if (foldv)
	{
		cpucash = cpucash + pot;
		cash = cash - bet;
	}
}
void Checks::FoldValueC()
{
	if (foldv)
	{
		cash = cash + pot;
		cpucash = cpucash - bet;
	}
}
