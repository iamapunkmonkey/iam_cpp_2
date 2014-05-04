#include "Aesthetics.h"
#include "GamePlay.h"
#include "Checks.h"
#include "Deck.h"
#include "DrawCard.h"
#include "Hands.h"
#include "State.h"


Hands hands;
DrawCard drawcard;
Checks checks;
Aesthetics aesthetics;

GamePlay::GamePlay() 
{
}
//clears
void GamePlay::Clear()
{
	playerhand.clear();
	deck.clear();
	hand.clear();
	cpuhand.clear();
	tablehand.clear();
	computerhand.clear();
	PlayerValues.clear();
	psuits.clear();
	cvalues.clear();
	csuits.clear();
	pot = 0;
	result = "";
	inhand = "";
}

void GamePlay::Clears()
{
	playerhand.clear();
	psuits.clear();
	PlayerValues.clear();

	computerhand.clear();
	csuits.clear();
	cvalues.clear();
}

void GamePlay::Cards()
{


	Clears();

	playerhand = hands.completeHand(tablehand, hand);
	psuits = hands.getSuit(playerhand);
	PlayerValues = hands.handValue(playerhand);

	computerhand = hands.completeHand(tablehand, cpuhand);
	csuits = hands.getSuit(computerhand);
	cvalues = hands.handValue(computerhand);


}

void GamePlay::Setup()
{
	//JUST TESTING DYNAMIC WINDOW RESIZE, SERIOUSLY THIS SHOULDNT BE HERE
	//if numPlayers < 2
	//{
	aesthetics.SetWindow(100, 55); // Set windows size
	//}
	/*************************************************/
	//if numPlayers < 2
	//{
	//aesthetics.SetWindow(200, 55); // Set windows size
	//also need to change layout as well here
	//}
	//if numPlayers < 2
	//{
	//aesthetics.SetWindow(250, 55); // Set windows size
	//also need to change layout as well here
	//}
	/*************************************************/
	aesthetics.centerWindow();
	// end testing window resize

	PlayerHandValue = 0;
	CpuHandValue = 0;
	result = "";

}

void GamePlay::uiText()
{
	system("cls");

	drawcard.createhand(hand, 25, 40);
	drawcard.createhand(tablehand, 5, 17);
	drawcard.drawCardBack(cpuhand, 24, 3);

	if (!showComputer)
	{
		computerHandText = "?????";
	}
	if (!shows)
	{
		PressEnterToContinue = " ";
	}
	if (!foldc)
	{
		fold = " ";
	}

	inhand = checks.handText(PlayerHandValue);

	aesthetics.mainText();
	aesthetics.changingText(cash, inhand, computerHandText, cpucash, fold, pot, result);
}

int GamePlay::transferCpuBetToAesthetics(int _cpubet)
{
	_cpubet = cpubet;

	return _cpubet;
}

void GamePlay::Start() //What user will see first, displays start money (Omoney)
{
	
	Clear();
	system("cls");
	cash = 200;
	cpucash = 200;
	pot = 0;
	
	Flop();

}

void GamePlay::makeHands()
{
	computerHandText = "??????";
	deck = hands.createdeck(deck);
	tablehand = hands.tablecards(deck,tablehand, 8);
	hand = hands.playercard(deck,hand);
	cpuhand = hands.cpucard(deck,cpuhand);
	Cards();//creating the hands  
}
void GamePlay::Flop()
{
	gameoverCheck();
	Setup();
	makeHands();
	getValues();
	uiText();
	betSystem();
	Turn();
}

void GamePlay::Turn()
{

	Setup();
	tablehand = hands.tablecards(deck, tablehand,  9);
	Cards();
	getValues();
	uiText();
	betSystem();
	River();
}

void GamePlay::River()
{
	Setup();
	tablehand = hands.tablecards(deck, tablehand, 10);
	Cards(); //creating the hands  
	getValues();
	uiText();
	betSystem();
	finalCards();
}

void GamePlay::finalCards()
{
	PlayerHandValue = 0;
	CpuHandValue = 0;
	showComputer = true;
	shows = true;

	system("cls");
	tablehand = hands.tablecards(deck, tablehand, 10);
	Cards();
	getValues();
	
	if (playerFold == true)
	{
		PlayerHandValue = 0;
	}
	computerHandText = checks.handText(CpuHandValue);

	determine();

	uiText();

	drawcard.createhand(hand, 25, 40);
	drawcard.createhand(tablehand, 5, 17); 
	drawcard.createhand(cpuhand, 24, 3);

	cin.get();


	gameoverCheck();

	Clear();
	system("cls");
	Flop();
}


//extracted and created a function so i can check if player or cpu had no money at the start of flop
void GamePlay::gameoverCheck()
{
	if (cash == 0)
	{
		aesthetics.OutOfMoney("You");
	}
	if (cpucash == 0)
	{
		aesthetics.OutOfMoney("The Computer Player");
	}
	else
	{
		return;
	}
}

void GamePlay::getValues()
{

	PlayerHandValue = 0;
	CpuHandValue = 0;
	PlayerHandValue = checks.DetermineHand(PlayerValues, psuits);
	CpuHandValue = checks.DetermineHand(cvalues, csuits);
	inhand = checks.handText(PlayerHandValue);
}


//THIS NEEDS ALOT WORK
//bet system stuff in here
void GamePlay::betSystem()
{

	random = rand() % 10;
	if (random < 3 && !aesthetics.ifTrueChangeOrigMenuToBlack)
	{
		CpuFold(CpuHandValue);
	}


	// method for cpu betting logic, passing in CpuHandValue to determine what it does
	
	bet = aesthetics.gameplayMenu(); // storing the variable returned from menu class to bet
	
	
	
	if (bet == 100)
	{
		allin = true;
		bet = 100;
		getValues();
		Betting(bet); 
		CpuBetting(CpuHandValue);
		finalCards();
	}
	if (bet == 200)
	{
		playerFold = true;
		finalCards();
	}
		getValues();
		Betting(bet); // player betting method passing in the value stored at bet
		CpuBetting(CpuHandValue);
	
}
void GamePlay::Betting(int bet)
{
	if (cash > 0)
	{
		if (bet == 100)
		{

			bet = cash;
			cash = cash - bet;
			pot = pot + bet;
		}
		else if (bet == 50)
		{
			bet = 50;
			cash = cash - bet;
			pot = pot + bet;
		}
		else if (bet == 10)
		{
			bet = 10;
			cash = cash - bet;
			pot = pot + bet;
		}
		else if (bet == 0)
		{
			bet = 0;
			playerCheck = true;
			cash = cash - bet;
			pot = pot + bet;
		}
		else
		{
			bet = 66;
			cash = cash - bet;
			pot = pot + bet;
		}

	}
}

void GamePlay::raiseMenu(int cpube2t)
{
	bet = aesthetics.raiseMenu(cpubet);
}

void GamePlay::CpuBetting(int CpuHandValue)
{
	if (playerCheck)
	{
		if (CpuHandValue > 0) //0 for testing
		{
			
			//*****pseudo code for this behavior:*****//
			//*****random int between 1 and 100*****//
			random = rand() % 100;
			//*****if random int is between 1 and 34 *****//
			//*****cpu check*****//
			if (random < 35)
			{
				cpubet = 0;
				aesthetics.receiveCpuBetFromGamePlay(cpubet);
			}
			//*****else if random int is between 35 and 60*****//
			//**********random int between 1 and 10*****//
			//**********if random int is between 1 and 3*****//
			else if (random >= 35 && random < 61)
			{
				newrandom = rand() % 10;
				if (newrandom < 4)
				{
					//**************check*****//
					cpubet = 0;
					aesthetics.receiveCpuBetFromGamePlay(cpubet);
				}
				//**********else*****//
				//**************bet array 10, 50, all in*****//
				//**************randomly select one element*****//
				//**************cpuBet = randomlySelectedBetArrayElement*****//
				else
				{
					a = 10;
					b = 50;
					c = 100;
					betVector.push_back(a);
					betVector.push_back(b);
					betVector.push_back(c);
					int randomlySelectedFromBetVector;

					int selectWhichElementToPick = rand() % 3;

					if (selectWhichElementToPick == 1)
					{
						randomlySelectedFromBetVector = a;
					}
					else if (selectWhichElementToPick == 2)
					{
						randomlySelectedFromBetVector = b;
					}
					else
					{
						randomlySelectedFromBetVector = c;
					}

					cpubet = randomlySelectedFromBetVector;
					cpucash = cpucash - cpubet;
					pot = pot + cpubet;
					aesthetics.receiveCpuBetFromGamePlay(cpubet);
					//need to have player now have new menu for raise
					//bet = aesthetics.raiseMenu(cpubet);
				}
			}

			
			

			//*****else if random int is between 61 and 99*****//
			//**********cpu raise 50*****//
			else if (random >= 61 && random <= 99)
			{
				cpubet = 50;
				cpucash = cpucash - cpubet;
				pot = pot + cpubet;
				aesthetics.receiveCpuBetFromGamePlay(cpubet);
				//need to have player now have new menu for raise
			}
			//*****else if random int is 100*****//
			//**********cpu raise all in*****//
			else //basically saying if random = 100
			{
				cpubet = cpucash;
				cpucash = cpucash - cpubet;
				pot = pot + cpubet;
				aesthetics.receiveCpuBetFromGamePlay(cpubet);
				//need to have player now have new menu for raise
			}

			//need to make raise menu for player.

		}

		/*else if (CpuHandValue < 90 && CpuHandValue >= 50)
		{
			cpubet = 0;
		}
		else if (CpuHandValue < 50 && CpuHandValue >= 6)
		{
			cpubet = 0;
		}
		else if (CpuHandValue < 5)
		{
			cpubet = 0;
		}*/
	}

	if (cpucash > 0 && !playerCheck)
	{

		
		if (CpuHandValue >= 90)
		{

			cpubet = cpucash;
			cpucash = cpucash - cpubet;
			pot = pot + cpubet;
			aesthetics.receiveCpuBetFromGamePlay(cpubet);

		}
		else if (CpuHandValue < 90 && CpuHandValue >= 50)
		{
			cpubet = 50;
			cpucash = cpucash - cpubet;
			pot = pot + cpubet;
			aesthetics.receiveCpuBetFromGamePlay(cpubet);

		}
		else if (CpuHandValue < 50 && CpuHandValue >= 6)
		{

			cpubet = 10;
			cpucash = cpucash - cpubet;
			pot = pot + cpubet;
			aesthetics.receiveCpuBetFromGamePlay(cpubet);


		}
		else if (CpuHandValue < 5)
		{

			cpubet = 0;
			cpucash = cpucash - cpubet;
			pot = pot + cpubet;
			aesthetics.receiveCpuBetFromGamePlay(cpubet);

		}
	}
	aesthetics.ifTrueChangeOrigMenuToBlack = false;
	aesthetics.setBoolToAlertPlayer();
	aesthetics.mainText();

	bet = aesthetics.gameplayMenu(); // storing the variable returned from menu class to bet
	//change Instructions to "ALERT: CPU raised [hit enter to call or fold]"
	raiseMenu(cpubet);
	playerCheck = false;
}
void GamePlay::CpuFold(int CpuHandValue)
{
	
	if (cpucash > 0)
	{
		if (CpuHandValue < 5)
		{
			cpubet = 0;
			cpucash = cpucash - cpubet;
			pot = pot + cpubet;
			finalCards();
		}
	}

}
//

//hand to extract this from checks, we have to much going on in it to break the function up
//will need a rework once we add more players though
void GamePlay::determine()
{
	if (PlayerHandValue == CpuHandValue)
	{
		int test = checks.FindHighCard(hand, cpuhand);

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










