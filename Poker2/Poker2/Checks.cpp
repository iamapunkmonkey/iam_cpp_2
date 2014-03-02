#include "Aesthetics.h"
#include "GamePlay.h"
#include "Checks.h"
#include "Poker.h"

int _playerHigh;
int _cpuHigh;

Checks::Checks()
{

}

int Checks::ispair(vector<int> dvalues)
{
	vector<int> test;
	int z;
	sort(dvalues.begin(), dvalues.end());
	int test2 = 0;
	int test3 = 0;

	FindHighCard(test2, test3);

	for (z = 0; z < dvalues.size(); z++)
	{
		for (int j = 0; j < dvalues.size(); j++)
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
	int z;
	sort(dsuits.begin(), dsuits.end());

	for (z = 0; z < dsuits.size(); z++)
	{
		for (int j = 1; j < dsuits.size(); j++)
		{
			if (j != z)
			{
				if (dsuits[z] == dsuits[j])
				{
					test.push_back(tempValues[j]);

				}
			}
		}
	}
	if (test.size() >= 20 && test.size() <= 35)
	{
		return 1;
	}
	else
	{
		return 0;
	}
		
	return 0;

}

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
} 

int Checks::threeofakind(vector<int> dvalues)
{

	vector<int> test;
	test.clear();
	int z;
	sort(dvalues.begin(), dvalues.end());

	for (z = 0; z < dvalues.size(); z++)
	{
		for (int j = 1; j < dvalues.size(); j++)
		{
			if (j != z)
			{
				if (dvalues[z] == dvalues[j])
				{
					test.push_back(dvalues[z]);
				}
			}
		}
	}
	if (test.size() >= 6 && test.size() <= 9)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int Checks::fourofakind(vector<int> dvalues)
{
	vector<int> test;
	test.clear();
	int z;
	sort(dvalues.begin(), dvalues.end());

	for (z = 0; z < dvalues.size(); z++)
	{
		for (int j = 1; j < dvalues.size(); j++)
		{
			if (j != z)
			{
				if (dvalues[z] == dvalues[j])
				{
					test.push_back(dvalues[j]);

				}
			}
		}
	} 
	if (test.size() >= 12 && test.size() <= 22)
	{
		return 1;
	}
	else
		return 0;

}

int Checks::fullhouse(vector<int> dvalues)
{
	vector<int> test;
	test.clear();
	int z;
	sort(dvalues.begin(), dvalues.end());

	for (z = 0; z < dvalues.size(); z++)
	{
		for (int j = 0; j < dvalues.size(); j++)
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
	{
		return 0;
	}
		

	return 0;
}
//

// determing hand checks
int Checks::determinehand(vector<int >pvalues, vector<char>psuits)
{
	tempValues.empty();
	tempSuits.empty();
	tempValues = pvalues;
	tempSuits = psuits;
	if (foldCardsText == true)
	{
		text_pHand = "FOLD!";
	}

	sort(tempValues.begin(), tempValues.end());
	if ((flush(tempSuits)) && (straight(tempValues)))
	{


		if (tempValues[7] == 14)
		{
			text_pHand = "ROAYL FLUSH!!";
			return 100;
		}
		else
		{
			text_pHand = "STRAIGHT FLUSH!!";
			return 90;
		}
	}

	else if (flush(tempSuits) == 1)
	{
		text_pHand = "FLUSH!!";
		return 80;

	}
	else if (straight(tempValues) == 1)
	{
		text_pHand = "STRAIGHT!!";
		return 70;

	}

	else if (fourofakind(tempValues) == 1)
	{
		text_pHand = "FOUR OF A KIND!!";
		return 60;

	}
	else if (fullhouse(tempValues) == 1)
	{
		text_pHand = "FULL HOUSE!!";
		return 50;

	}

	else if (threeofakind(tempValues) == 1)
	{
		text_pHand = "THREE OF A KIND!!";
		return 40;

	}
	else if (ispair(tempValues) == 2)
	{
		text_pHand = "TWO PAIR!!";
		return 30;
	}
	else if (ispair(tempValues) == 1)
	{
		text_pHand = "PAIR!!";
		
		FindHighCard(_playerHigh, _cpuHigh);
		//if(whoHasHighCard == 0)
		//call split pot
		//if(whOhasHighCard == 1)
		//player wins 
		//if(whoHasHighCard == 2)
		//cpu wins
		return 20;
	}

	else 
	{
		text_pHand = "Nothing!!";
		return tempValues.back();
	}
}
int Checks::determinecpuhand(vector<int> cvalues, vector<char>csuits)
{
	tempValues.empty();
	tempSuits.empty();

	tempValues = cvalues;
	tempSuits = csuits;

	sort(tempValues.begin(), tempValues.end());
	if ((flush(tempSuits)) && (straight(tempValues)))
	{
		if (tempValues[4] == 14)
		{
			text_cHand = "ROYAL FLUSH!!";
			return 100;
		}
		else
		{
			text_cHand = "STRAIGHT FLUSH!";
			return 90;
		}
	}

	else if (flush(tempSuits) == 1)
	{
		text_cHand = "Flush!";
		return 80;

	}
	else if (straight(tempValues) == 1)
	{
		text_cHand = "Straight!";
		return 70;

	}

	else if (fourofakind(tempValues) == 1)
	{
		text_cHand = "Four of a Kind!";
		return 60;

	}
	else if (fullhouse(tempValues) == 1)
	{
		text_cHand = "Full House!";
		return 50;

	}

	else if (threeofakind(tempValues) == 1)
	{
		text_cHand = "Three of a Kind!";
		return 40;

	}
	else if (ispair(tempValues) == 2)
	{
		text_cHand = "Two Pair";
		return 30;
	}
	else if (ispair(tempValues) == 1)
	{
		text_cHand = "Pair!";

		FindHighCard(_playerHigh, _cpuHigh);
		cout << _playerHigh + _cpuHigh << endl;
		return 20;

	}

	else if (ispair(tempValues) == 0)
	{

		text_cHand = "Absolutely nothing!";
		return 4;

	}
	return tempValues.back();
}
//

//determine the winner
void Checks::awardWinner(int pHand_checks, int cHand_checks)
{
	if (pHand_checks == cHand_checks)
	{
		text_result = "Split Pot";
		int pot1 = pot / 2;
		int pot2 = pot;
		pCash = pCash + pot1;
		cpucash = cpucash + pot1;
	}
	if (pHand_checks > cHand_checks)
	{
		text_result = "You Win";
		pCash = pCash + pot;
	}
	if (pHand_checks < cHand_checks)
	{
		text_result = "You Lose";
		cpucash = cpucash + pot;
	}

}
void Checks::FoldValue() //Combine last 2 
{
	if (foldv)
	{
		cpucash = cpucash + pot;
		pCash = pCash - currentBet;
	}
}
void Checks::FoldValueC()
{
	if (foldv)
	{
		pCash = pCash + pot;
		cpucash = cpucash - currentBet;
	}
}

int Checks::FindHighCard(int pHighCard, int cHighCard)
{
	printf("%s", pHand[0].c_str());

	// 2 P
	if (pHand[0] == "2H" || pHand[1] == "2H")
	{
		pHighCard = 2;
	}

	if (pHand[0] == "2C" || pHand[1] == "2C")
	{
		pHighCard = 2;
	}

	if (pHand[0] == "2D" || pHand[1] == "2D")
	{
		pHighCard = 2;
	}

	if (pHand[0] == "2S" || pHand[1] == "2S")
	{
		pHighCard = 2;
	}
	// 2 C
	if (cHand[0] == "2H" || cHand[1] == "2H")
	{
		cHighCard = 2;
	}

	if (cHand[0] == "2C" || cHand[1] == "2C")
	{
		cHighCard = 2;
	}

	if (cHand[0] == "2D" || cHand[1] == "2D")
	{
		cHighCard = 2;
	}

	if (cHand[0] == "2S" || cHand[1] == "2S")
	{
		cHighCard = 2;
	}

	//3 P
	if (pHand[0] == "3H" || pHand[1] == "3H")
	{
		pHighCard = 3;
	}

	if (pHand[0] == "3C" || pHand[1] == "3C")
	{
		pHighCard = 3;
	}

	if (pHand[0] == "3D" || pHand[1] == "3D")
	{
		pHighCard = 3;
	}

	if (pHand[0] == "3S" || pHand[1] == "3S")
	{
		pHighCard = 3;
	}
	//3 C
	if (cHand[0] == "3H" || cHand[1] == "3H")
	{
		cHighCard = 3;
	}

	if (cHand[0] == "3C" || cHand[1] == "3C")
	{
		cHighCard = 3;
	}

	if (cHand[0] == "3D" || cHand[1] == "3D")
	{
		cHighCard = 3;
	}

	if (cHand[0] == "3S" || cHand[1] == "3S")
	{
		cHighCard = 3;
	}

	//4 P
	if (pHand[0] == "4H" || pHand[1] == "4H")
	{
		pHighCard = 4;
	}

	if (pHand[0] == "4C" || pHand[1] == "4C")
	{
		pHighCard = 4;
	}

	if (pHand[0] == "4D" || pHand[1] == "4D")
	{
		pHighCard = 4;
	}

	if (pHand[0] == "4S" || pHand[1] == "4S")
	{
		pHighCard = 4;
	}
	//4 C
	if (cHand[0] == "4H" || cHand[1] == "4H")
	{
		cHighCard = 4;
	}

	if (cHand[0] == "4C" || cHand[1] == "4C")
	{
		cHighCard = 4;
	}

	if (cHand[0] == "4D" || cHand[1] == "4D")
	{
		cHighCard = 4;
	}

	if (cHand[0] == "4S" || cHand[1] == "4S")
	{
		cHighCard = 4;
	}
	//5 P
	if (pHand[0] == "5H" || pHand[1] == "5H")
	{
		pHighCard = 5;
	}

	if (pHand[0] == "5C" || pHand[1] == "5C")
	{
		pHighCard = 5;
	}

	if (pHand[0] == "5D" || pHand[1] == "5D")
	{
		pHighCard = 5;
	}

	if (pHand[0] == "5S" || pHand[1] == "5S")
	{
		pHighCard = 5;
	}
	//5 C
	if (cHand[0] == "5H" || cHand[1] == "5H")
	{
		cHighCard = 5;
	}

	if (cHand[0] == "5C" || cHand[1] == "5C")
	{
		cHighCard = 5;
	}

	if (cHand[0] == "5D" || cHand[1] == "5D")
	{
		cHighCard = 5;
	}

	if (cHand[0] == "5S" || cHand[1] == "5S")
	{
		cHighCard = 5;
	}
	//6 P
	if (pHand[0] == "6H" || pHand[1] == "6H")
	{
		pHighCard = 6;
	}

	if (pHand[0] == "6C" || pHand[1] == "6C")
	{
		pHighCard = 6;
	}

	if (pHand[0] == "6D" || pHand[1] == "6D")
	{
		pHighCard = 6;
	}

	if (pHand[0] == "6S" || pHand[1] == "6S")
	{
		pHighCard = 6;
	}
	//6 C
	if (cHand[0] == "6H" || cHand[1] == "6H")
	{
		cHighCard = 6;
	}

	if (cHand[0] == "6C" || cHand[1] == "6C")
	{
		cHighCard = 6;
	}

	if (cHand[0] == "6D" || cHand[1] == "6D")
	{
		cHighCard = 6;
	}

	if (cHand[0] == "6S" || cHand[1] == "6S")
	{
		cHighCard = 6;
	}
	//7 P
	if (pHand[0] == "7H" || pHand[1] == "7H")
	{
		pHighCard = 7;
	}

	if (pHand[0] == "7C" || pHand[1] == "7C")
	{
		pHighCard = 7;
	}

	if (pHand[0] == "7D" || pHand[1] == "7D")
	{
		pHighCard = 7;
	}

	if (pHand[0] == "7S" || pHand[1] == "7S")
	{
		pHighCard = 7;
	}
	//7 C
	if (cHand[0] == "7H" || cHand[1] == "7H")
	{
		cHighCard = 7;
	}

	if (cHand[0] == "7C" || cHand[1] == "7C")
	{
		cHighCard = 7;
	}

	if (cHand[0] == "7D" || cHand[1] == "7D")
	{
		cHighCard = 7;
	}

	if (cHand[0] == "7S" || cHand[1] == "7S")
	{
		cHighCard = 7;
	}
	//8 P
	if (pHand[0] == "8H" || pHand[1] == "8H")
	{
		pHighCard = 8;
	}

	if (pHand[0] == "8C" || pHand[1] == "8C")
	{
		pHighCard = 8;
	}

	if (pHand[0] == "8D" || pHand[1] == "8D")
	{
		pHighCard = 8;
	}

	if (pHand[0] == "8S" || pHand[1] == "8S")
	{
		pHighCard = 8;
	}
	//8C
	if (cHand[0] == "8H" || cHand[1] == "8H")
	{
		cHighCard = 8;
	}

	if (cHand[0] == "8C" || cHand[1] == "8C")
	{
		cHighCard = 8;
	}

	if (cHand[0] == "8D" || cHand[1] == "8D")
	{
		cHighCard = 8;
	}

	if (cHand[0] == "8S" || cHand[1] == "8S")
	{
		cHighCard = 8;
	}
	//9P
	if (pHand[0] == "9H" || pHand[1] == "9H")
	{
		pHighCard = 9;
	}

	if (pHand[0] == "9C" || pHand[1] == "9C")
	{
		pHighCard = 9;
	}

	if (pHand[0] == "9D" || pHand[1] == "9D")
	{
		pHighCard = 9;
	}

	if (pHand[0] == "9S" || pHand[1] == "9S")
	{
		pHighCard = 9;
	}
	//9C
	if (cHand[0] == "9H" || cHand[1] == "9H")
	{
		cHighCard = 9;
	}

	if (cHand[0] == "9C" || cHand[1] == "9C")
	{
		cHighCard = 9;
	}

	if (cHand[0] == "9D" || cHand[1] == "9D")
	{
		cHighCard = 9;
	}

	if (cHand[0] == "9S" || cHand[1] == "9S")
	{
		cHighCard = 9;
	}
	//10 P
	if (pHand[0] == "TH" || pHand[1] == "TH")
	{
		pHighCard = 10;
	}

	if (pHand[0] == "TC" || pHand[1] == "TC")
	{
		pHighCard = 10;
	}

	if (pHand[0] == "TD" || pHand[1] == "TD")
	{
		pHighCard = 10;
	}

	if (pHand[0] == "TS" || pHand[1] == "TS")
	{
		pHighCard = 10;
	}
	//10 C
	if (cHand[0] == "TH" || cHand[1] == "TH")
	{
		cHighCard = 10;
	}

	if (cHand[0] == "TC" || cHand[1] == "TC")
	{
		cHighCard = 10;
	}

	if (cHand[0] == "TD" || cHand[1] == "TD")
	{
		cHighCard = 10;
	}

	if (cHand[0] == "TS" || cHand[1] == "TS")
	{
		cHighCard = 10;
	}
	//J P
	if (pHand[0] == "JH" || pHand[1] == "JH")
	{
		pHighCard = 11;
	}

	if (pHand[0] == "JC" || pHand[1] == "JC")
	{
		pHighCard = 11;
	}

	if (pHand[0] == "JD" || pHand[1] == "JD")
	{
		pHighCard = 11;
	}

	if (pHand[0] == "JS" || pHand[1] == "JS")
	{
		pHighCard = 11;
	}
	//J C
	if (cHand[0] == "JH" || cHand[1] == "JH")
	{
		cHighCard = 11;
	}

	if (cHand[0] == "JC" || cHand[1] == "JC")
	{
		cHighCard = 11;
	}

	if (cHand[0] == "JD" || cHand[1] == "JD")
	{
		cHighCard = 11;
	}

	if (cHand[0] == "JS" || cHand[1] == "JS")
	{
		cHighCard = 11;
	}
	//Q P
	if (pHand[0] == "QH" || pHand[1] == "QH")
	{
		pHighCard = 12;
	}

	if (pHand[0] == "QC" || pHand[1] == "QC")
	{
		pHighCard = 12;
	}

	if (pHand[0] == "QD" || pHand[1] == "QD")
	{
		pHighCard = 12;
	}

	if (pHand[0] == "QS" || pHand[1] == "QS")
	{
		pHighCard = 12;
	}
	//Q C
	if (cHand[0] == "QH" || cHand[1] == "QH")
	{
		cHighCard = 12;
	}

	if (cHand[0] == "QC" || cHand[1] == "QC")
	{
		cHighCard = 12;
	}

	if (cHand[0] == "QD" || cHand[1] == "QD")
	{
		cHighCard = 12;
	}

	if (cHand[0] == "QS" || cHand[1] == "QS")
	{
		cHighCard = 12;
	}
	//K P
	if (pHand[0] == "KH" || pHand[1] == "KH")
	{
		pHighCard = 13;
	}

	if (pHand[0] == "KC" || pHand[1] == "KC")
	{
		pHighCard = 13;
	}

	if (pHand[0] == "KD" || pHand[1] == "KD")
	{
		pHighCard = 13;
	}

	if (pHand[0] == "KS" || pHand[1] == "KS")
	{
		pHighCard = 13;
	}
	//K C
	if (cHand[0] == "KH" || cHand[1] == "KH")
	{
		cHighCard = 13;
	}

	if (cHand[0] == "KC" || cHand[1] == "KC")
	{
		cHighCard = 13;
	}

	if (cHand[0] == "KD" || cHand[1] == "KD")
	{
		cHighCard = 13;
	}

	if (cHand[0] == "KS" || cHand[1] == "KS")
	{
		cHighCard = 13;
	}
	//A P
	if (pHand[0] == "AH" || pHand[1] == "AH")
	{
		pHighCard = 14;
	}

	if (pHand[0] == "AC" || pHand[1] == "AC")
	{
		pHighCard = 14;
	}

	if (pHand[0] == "AD" || pHand[1] == "AD")
	{
		pHighCard = 14;
	}

	if (pHand[0] == "AS" || pHand[1] == "AS")
	{
		pHighCard = 14;
	}
	//A C
	if (cHand[0] == "AH" || cHand[1] == "AH")
	{
		cHighCard = 14;
	}

	if (cHand[0] == "AC" || cHand[1] == "AC")
	{
		cHighCard = 14;
	}

	if (cHand[0] == "AD" || cHand[1] == "AD")
	{
		cHighCard = 14;
	}

	if (cHand[0] == "AS" || cHand[1] == "AS")
	{
		cHighCard = 14;
	}
	return pHighCard, cHighCard;
}
