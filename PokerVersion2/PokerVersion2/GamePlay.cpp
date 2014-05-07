#include "Aesthetics.h"
#include "GamePlay.h"
#include "Checks.h"
#include "Deck.h"
#include "DrawCard.h"
#include "Hands.h"
#include "State.h"
#include <map>


Hands hands;
DrawCard drawcard;
Checks checks;
Aesthetics aesthetics;

GamePlay::GamePlay() 
{
	
}
void GamePlay::loadingPlayers(vector<ComputerPlayer> cp)
{
	listOfComputerPlayers = cp;
	Start();
}
//clears
void GamePlay::Clear()
{
	pot = 0;
	result = "";
	inhand = "";
	playerhand.clear();
	deck.clear();
	hand.clear();
	tablehand.clear();
	psuits.clear();
	PlayerValues.clear();

	for (size_t i = 0; i < listOfComputerPlayers.size(); i++)
	{

		listOfComputerPlayers[i].cpuhand.clear();
		listOfComputerPlayers[i].computerhand.clear();
		
		listOfComputerPlayers[i].cvalues.clear();
		listOfComputerPlayers[i].csuits.clear();
	}
}

void GamePlay::Clears()
{
	playerhand.clear();
	psuits.clear();
	PlayerValues.clear();

	for (size_t i = 0; i < listOfComputerPlayers.size(); i++)
	{
		listOfComputerPlayers[i].computerhand.clear();
		listOfComputerPlayers[i].csuits.clear();
		listOfComputerPlayers[i].cvalues.clear();
	}
}

void GamePlay::Cards()
{


	Clears();

	playerhand = hands.completeHand(tablehand, hand);
	psuits = hands.getSuit(playerhand);
	PlayerValues = hands.handValue(playerhand);
	for (size_t i = 0; i < listOfComputerPlayers.size(); i++)
	{
		listOfComputerPlayers[i].computerhand = hands.completeHand(tablehand, listOfComputerPlayers[i].cpuhand);
		listOfComputerPlayers[i].csuits = hands.getSuit(listOfComputerPlayers[i].computerhand);
		listOfComputerPlayers[i].cvalues = hands.handValue(listOfComputerPlayers[i].computerhand);

	}
}

void GamePlay::Setup()
{
	//JUST TESTING DYNAMIC WINDOW RESIZE, SERIOUSLY THIS SHOULDNT BE HERE
	//if numPlayers < 2
	//{
	//aesthetics.SetWindow(100, 55); // Set windows size
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
	//aesthetics.centerWindow();
	// end testing window resize

	PlayerHandValue = 0;
	for (size_t i = 0; i < listOfComputerPlayers.size(); i++)
	{
		listOfComputerPlayers[i].CpuHandValue = 0;
	}
	result = "";

}

void GamePlay::uiText()
{
	system("cls");
	
	if (listOfComputerPlayers.size() == 1)
	{
		drawcard.createhand(hand, 25, 40);
		drawcard.createhand(tablehand, 5, 20);
		drawcard.drawCardBack(listOfComputerPlayers[0].cpuhand, 24, 3);
	}
	if (listOfComputerPlayers.size() == 2)
	{
		drawcard.createhand(hand, 25, 40);
		drawcard.createhand(tablehand, 5, 20);
		drawcard.drawCardBack(listOfComputerPlayers[0].cpuhand, 1, 3);
		drawcard.drawCardBack(listOfComputerPlayers[1].cpuhand, 60, 3);
	}
	if (listOfComputerPlayers.size() == 3)
	{
		drawcard.createhand(hand, 1, 40);
		drawcard.createhand(tablehand, 5, 20);
		drawcard.drawCardBack(listOfComputerPlayers[0].cpuhand, 1, 3);
		drawcard.drawCardBack(listOfComputerPlayers[1].cpuhand, 60, 3);
		drawcard.drawCardBack(listOfComputerPlayers[2].cpuhand, 60, 40);
	}
	//drawcard.drawCardBack(listOfComputerPlayers[0].cpuhand, 24, 3);

	if (!showComputer)
	{
		for (size_t i = 0; i < listOfComputerPlayers.size(); i++)
		{
			listOfComputerPlayers[i].computerHandText = "?????";
		}
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

	aesthetics.mainText("1");

	//CHANGE ME
	aesthetics.changingText(cash, inhand, listOfComputerPlayers, fold, pot, result);
}

int GamePlay::transferCpuBetToAesthetics(int _cpubet)
{
	//CHANGE ME
	_cpubet = listOfComputerPlayers[0].cpubet;

	return _cpubet;
}

void GamePlay::Start() //What user will see first, displays start money (Omoney)
{
	
	Clear();
	system("cls");
	pot = 0;
	cash = 200;
	for (size_t i = 0; i < listOfComputerPlayers.size(); i++)
	{
		listOfComputerPlayers[i].cpucash = 200;
	}
	
	Flop();

}

void GamePlay::makeHands()
{
	
	deck = hands.createdeck(deck);
	tablehand = hands.dealCards(deck,tablehand, 3);
	hand = hands.dealCards(deck,hand,2);
	for (size_t i = 0; i < listOfComputerPlayers.size(); i++)
	{
		listOfComputerPlayers[i].cpuhand = hands.dealCards(deck, listOfComputerPlayers[i].cpuhand, 2);
		listOfComputerPlayers[i].computerHandText = "??????";
	}
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
	tablehand = hands.dealCards(deck, tablehand,  1);
	Cards();
	getValues();
	uiText();
	betSystem();
	River();
}

void GamePlay::River()
{
	Setup();
	tablehand = hands.dealCards(deck, tablehand, 1);
	Cards(); //creating the hands  
	getValues();
	uiText();
	betSystem();
	finalCards();
}

void GamePlay::finalCards()
{
	//CHANGE ME
	PlayerHandValue = 0;
	listOfComputerPlayers[0].CpuHandValue = 0;
	showComputer = true;
	shows = true;

	system("cls");
	if (tablehand.size() < 4)
	{

		tablehand = hands.dealCards(deck, tablehand, 2);
	}
	if (tablehand.size() < 5)
	{

		tablehand = hands.dealCards(deck, tablehand, 1);
	}
	Cards();
	getValues();
	
	if (playerFold == true)
	{
		PlayerHandValue = 0;
	}
	for (size_t i = 0; i < listOfComputerPlayers.size(); i++)
	{
		listOfComputerPlayers[i].computerHandText = checks.handText(listOfComputerPlayers[i].CpuHandValue);

	}

	determine();

	uiText();

	if (listOfComputerPlayers.size() == 1)
	{
		drawcard.createhand(hand, 25, 40);
		drawcard.createhand(tablehand, 5, 20);
		drawcard.createhand(listOfComputerPlayers[0].cpuhand, 24, 3);
	}
	if (listOfComputerPlayers.size() == 2)
	{
		drawcard.createhand(hand, 25, 40);
		drawcard.createhand(tablehand, 5, 20);
		drawcard.createhand(listOfComputerPlayers[0].cpuhand, 1, 3);
		drawcard.createhand(listOfComputerPlayers[1].cpuhand, 60, 3);
	}
	if (listOfComputerPlayers.size() == 3)
	{
		drawcard.createhand(hand, 1, 40);
		drawcard.createhand(tablehand, 5, 20);
		drawcard.createhand(listOfComputerPlayers[0].cpuhand, 1, 3);
		drawcard.createhand(listOfComputerPlayers[1].cpuhand, 60, 3);
		drawcard.createhand(listOfComputerPlayers[2].cpuhand, 60, 40);
	}


	cin.get();


	gameoverCheck();

	Clear();
	system("cls");
	Flop();
}


//extracted and created a function so i can check if player or cpu had no money at the start of flop
void GamePlay::gameoverCheck()
{
	//CHANGE ME


	for (size_t i = 0; i < listOfComputerPlayers.size(); i++)
	{
		if (listOfComputerPlayers[i].cpucash == 0)
		{
			aesthetics.OutOfMoney(listOfComputerPlayers[i].name);
		}
	}
	if (cash == 0)
	{
		aesthetics.OutOfMoney("You");
	}
	else
	{
		return;
	}

}

void GamePlay::getValues()
{

	PlayerHandValue = 0;
	PlayerHandValue = checks.DetermineHand(PlayerValues, psuits);
	inhand = checks.handText(PlayerHandValue);
	for (size_t i = 0; i < listOfComputerPlayers.size(); i++)
	{
		listOfComputerPlayers[i].CpuHandValue = 0;
		listOfComputerPlayers[i].CpuHandValue = checks.DetermineHand(listOfComputerPlayers[i].cvalues, listOfComputerPlayers[i].csuits);
	}
}


//THIS NEEDS ALOT WORK
//bet system stuff in here
void GamePlay::betSystem()
{




		// method for cpu betting logic, passing in CpuHandValue to determine what it does

		bet = aesthetics.gameplayMenu(); // storing the variable returned from menu class to bet

		for (size_t i = 0; i < listOfComputerPlayers.size(); i++)
		{

		if (bet == 100)
		{
			allin = true;
			bet = 100;
			getValues();
			Betting(bet);
			CpuBetting(listOfComputerPlayers[i].CpuHandValue, listOfComputerPlayers[i].name, listOfComputerPlayers[i].cpubet, listOfComputerPlayers[i].cpucash);
			finalCards();
		}
		if (bet == 200)
		{
			playerFold = true;
			finalCards();
		}
		getValues();
		Betting(bet); // player betting method passing in the value stored at bet
		CpuBetting(listOfComputerPlayers[i].CpuHandValue, listOfComputerPlayers[i].name, listOfComputerPlayers[i].cpubet, listOfComputerPlayers[i].cpucash);
	}
	
	
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
	bet = aesthetics.raiseMenu(listOfComputerPlayers[0].cpubet);
}

void GamePlay::CpuBetting(int CpuHandValue,string name,int cpubet,int cpucash)
{
	if (playerCheck)
	{
		if (CpuHandValue < 50 && CpuHandValue >= 6)
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

		else if (CpuHandValue < 90 && CpuHandValue >= 50)
		{
			//so we should be having CPU raise a little more than he would check if his value is above 50.
			//57% of the time CPU should be raising by 10 or 50, 15% of the time raise 100, 2% of the time all in, and 26% of the time check

			//random = rand()% 100
			random = rand() % 100;

			if (random < 58)
			{
				int findBetForCpu = rand() % 100;
				if (findBetForCpu < 76)
				{
					//cpu bet = 10 (raise)
					//call aesthetics class to send cpu bet
					cpubet = 10;
					aesthetics.receiveCpuBetFromGamePlay(cpubet);
				}

				else if (findBetForCpu >= 76)
				{
					//cpu bet = 50 (raise)
					//call aesthetics class to send cpu bet
					cpubet = 50;
					aesthetics.receiveCpuBetFromGamePlay(cpubet);
				}
			}

			else if (random >= 58 && random < 74)
			{
				//cpu bet = 100 (raise)
				//call aesthetics class to send cpu bet
				cpubet = 10;
				aesthetics.receiveCpuBetFromGamePlay(cpubet);
			}

			else if (random >= 74 && random < 77)
			{
				//raise all in
				//call aesthetics class to send cpu bet
				cpubet = cpucash;
				aesthetics.receiveCpuBetFromGamePlay(cpubet);
			}

			else if (random >= 77)
			{
				//check
				cpubet = 0;
			}
		}
		//else if (CpuHandValue < 50 && CpuHandValue >= 6)
		//{
		//	//so we should be having CPU raise a little more than he would check if his value is above 50.
		//	//57% of the time CPU should be checking, 17% of the time raise 50, and 26% of the time raise by 10

		//	random = rand() % 100;

		//	if(random < 58)
		//	{
		//		//check
		//	}

		//	else if (random > 57 && random < 75)
		//	{
		//		//raise by 50
		//		//call aesthetics class to send cpu bet
		//	}

		//	else if (random > 74)
		//	{
		//		//raise by 10
		//		//call aesthetics class to send cpu bet
		//	}


		//}
		else if (CpuHandValue < 5)
		{

			//10% chance of a bet from CPU, otherwise check
			random = rand() % 10;

			if (random < 2)
			{
				//raise 10
				//call aesthetics class to send cpu bet
				cpubet = 10;
				aesthetics.receiveCpuBetFromGamePlay(cpubet);

			}

			else
				//check
				cpubet = 0;
		}
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
	aesthetics.mainText(name);

	bet = aesthetics.gameplayMenu(); // storing the variable returned from menu class to bet
	//change Instructions to "ALERT: CPU raised [hit enter to call or fold]"
	raiseMenu(cpubet);
	playerCheck = false;
}
void GamePlay::CpuFold(int CpuHandValue)
{
	for (size_t i = 0; i < listOfComputerPlayers.size(); i++)
	{
		if (listOfComputerPlayers[i].cpucash > 0)
		{
			if (listOfComputerPlayers[i].CpuHandValue < 5)
			{
				listOfComputerPlayers[i].cpubet = 0;
				listOfComputerPlayers[i].cpucash = listOfComputerPlayers[i].cpucash - listOfComputerPlayers[i].cpubet;
				pot = pot + listOfComputerPlayers[i].cpubet;
				finalCards();
			}
		}
	}
	
}
//
void GamePlay::dummyCPU()
{
	ComputerPlayer dummy;

	dummy.computerhand = playerhand;
	dummy.csuits = psuits;
	dummy.cvalues = PlayerValues;
	dummy.cpuhand = playerhand;
	dummy.CpuHandValue = PlayerHandValue;
	dummy.cpucash = cash;
	dummy.name = "You";

	listOfComputerPlayers.push_back(dummy);
}
//hand to extract this from checks, we have to much going on in it to break the function up
//will need a rework once we add more players though
void GamePlay::determine()
{
	//dummyCPU();
	vector<pair<int, string> > cpuList;
	for (size_t i = 0; i < listOfComputerPlayers.size(); i++)
	{
		cpuList.push_back(pair<int, string>(listOfComputerPlayers[i].CpuHandValue, listOfComputerPlayers[i].name));
	}
	cpuList.push_back(pair<int, string>(PlayerHandValue, "You"));
	sort(cpuList.begin(), cpuList.end());



	if (cpuList.back().second == "You")
	{
		result = "You Win";
		cash = cash + pot;
	}
	if (cpuList.back().second == "Jim")
	{
		//int test = checks.FindHighCard(hand, listOfComputerPlayers[0].cpuhand);
		result = cpuList.back().second + " Wins!!";
		listOfComputerPlayers[0].cpucash = listOfComputerPlayers[0].cpucash + pot;
	}
	if (cpuList.back().second == "Tom")
	{
		//int test = checks.FindHighCard(hand, listOfComputerPlayers[1].cpuhand);
		result = cpuList.back().second + " Wins!!";
		listOfComputerPlayers[1].cpucash = listOfComputerPlayers[1].cpucash + pot;
	}
	if (cpuList.back().second == "John")
	{
		//int test = checks.FindHighCard(hand, listOfComputerPlayers[2].cpuhand);
		result = cpuList.back().second + " Wins!!";
		listOfComputerPlayers[2].cpucash = listOfComputerPlayers[2].cpucash + pot;
	}
			





	
}











