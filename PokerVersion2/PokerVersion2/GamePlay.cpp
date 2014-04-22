#include "Aesthetics.h"
#include "GamePlay.h"
#include "Checks.h"
#include "Deck.h"
#include "DrawCard.h"
#include "Hands.h"
#include "State.h"

#define MaxNo_Menu 5
#define MaxNo_Menu1 3
#define MaxNo_Menu2 3

vector<string>playerhand;
vector<string>cards;
vector<string>deck;
vector<string>hand;
vector<string>cpuhand;
vector<string>tablehand;
vector<string> computerhand;
vector<int> PlayerValues;
vector<char> psuits;
vector<int> cvalues;
vector<char> csuits;
bool foldc;
bool playerFold;
bool NewGameMenu;
bool allin;
bool duringhand;
int cash;
int cpucash;

int pot;
int bet;
int cpubet;
int PlayerHandValue;
int CpuHandValue;
int g;
int random;

string inhand;
string computerHandText;
string result;
string PressEnterToContinue;
string fold;
string arrows;
string enter;

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
	cards.clear();
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

void GamePlay::Start() //What user will see first, displays start money (Omoney)
{
	
	Clear();
	system("cls");
	cash = 200;
	cpucash = 200;
	pot = 0;
	
	Flop();

}

void GamePlay::Flop()
{
	Setup();
	computerHandText = "??????";
	hands.createdeck(deck);
	hands.tablecards(deck, 8);
	hands.playercard(deck);
	hands.cpucard(deck);
	Cards();//creating the hands  
	getValues();
	uiText();
	betSystem();
	Turn();
}

void GamePlay::Turn()
{
	Machine m;

	m.pregame_state();
	//Setup();
	//hands.tablecards(deck, 9);
	//Cards();
	//getValues();
	//uiText();
	//betSystem();
	//River();
}

void GamePlay::River()
{
	Setup();
	hands.tablecards(deck, 10);
	Cards();//creating the hands  
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
	hands.tablecards(deck, 10);
	Cards();
	getValues();
	
	if (playerFold == true)
	{
		PlayerHandValue = 0;
	}
	computerHandText = checks.handText(CpuHandValue);
	checks.determine(PlayerHandValue, CpuHandValue);

	uiText();
	drawcard.createhand(hand, 25, 40);
	drawcard.createhand(tablehand, 5, 17); 
	drawcard.createhand(cpuhand, 24, 3);

	cin.get();


	duringhand = true;
	if (!duringhand)
	{
		aesthetics.text1("You Ran Out of Money!");
		cin.get();
		system("cls");
		Clear();

		aesthetics.header(); // calling our game header
		aesthetics.MainMenu(); // calling our menu system
	}
	if (cash == 0)
	{
		Clear();
		system("cls");
		aesthetics.text1("You Ran Out of Money!");
		cin.get();
		system("cls");


		aesthetics.header(); // calling our game header
		aesthetics.MainMenu(); // calling our menu system
	}
	if (cpucash == 0)
	{
		system("cls");
		Aesthetics a;
		a.textattr(13);
		cout << " " << endl;
		cout << " " << endl;
		cout << "               /////////////////////////////////////////////////" << endl;
		cout << "               // "; a.textattr(3); cout << "*         *  *           *        *       * "; a.textattr(13); cout << "//" << endl;
		cout << "               //    "; a.textattr(3); cout << " * "; a.textattr(6); cout << "    CPU RAN OUT OF MONEY!         "; a.textattr(3); cout << "*   "; a.textattr(13); cout << "//" << endl;
		cout << "               // "; a.textattr(3); cout << "*                                     *     "; a.textattr(13); cout << "//" << endl;
		cout << "               //   "; a.textattr(3); cout << "*          "; a.textattr(6); cout << "You Win!                     "; a.textattr(3); cout << "* "; a.textattr(13); cout << "//" << endl;
		cout << "               //  "; a.textattr(3); cout << "*   "; a.textattr(3); cout << "*                             *    *   "; a.textattr(13); cout << "//" << endl;
		a.textattr(13); cout << "               //"; a.textattr(3); cout << "*********************************************"; a.textattr(13); cout << "//" << endl;
		a.textattr(13); cout << "               /////////////////////////////////////////////////" << endl;
		cout << " " << endl;
		cout << " " << endl;
		cout << " " << endl;
		cin.get();
		system("cls");
		aesthetics.header(); // calling our game header
		aesthetics.MainMenu(); // calling our menu system

	}
	Clear();
	system("cls");
	Flop();
}

void GamePlay::getValues()
{

	PlayerHandValue = 0;
	CpuHandValue = 0;
	PlayerHandValue = checks.DetermineHand(PlayerValues, psuits);
	CpuHandValue = checks.DetermineHand(cvalues, csuits);
	inhand = checks.handText(PlayerHandValue);
}


//game menu
int GamePlay::menu()//side menu
{
	char *menu_list[MaxNo_Menu] = { "Check", "Bet 10", "Bet 50", "All In", "Fold" };
	int i,
		xpos[MaxNo_Menu] = { 15, 30, 45, 60, 75 },
		ypos = 53;

	// list the menu
	for (i = 0; i< MaxNo_Menu; ++i)
	{
		
		aesthetics.gotoxy(xpos[i], ypos);
		aesthetics.textattr(3);
		printf("%s", menu_list[i]);
	}

	// make menu available to choose
	i = 0; // set i to 0 to start menu at the begining
	while (1)
	{
		
		aesthetics.gotoxy(xpos[i], ypos);// set cursor position
		aesthetics.textattr(11); // this sets menu item to green text
		printf("%s", menu_list[i]); // print out highlighted item in new color

		/* note : 72 -> UP button
		75 -> RIGHT button
		77 -> LEFT button
		80 -> DOWN button
		*/
		//getting key information switch
		switch (_getch())
		{
			//right
		case 75:
			if (i>0)
			{
				
				aesthetics.gotoxy(xpos[i], ypos);//set cursor position passing in i
				aesthetics.textattr(3); // set text color passing in color
				printf("%s", menu_list[i]); // print the menu item out in new color
				--i;//up key subtract from i
			}
			else
			{
				
				aesthetics.gotoxy(xpos[i], ypos);// set cursor position passing in i
				aesthetics.textattr(3); // reset text color
				printf("%s", menu_list[i]);//print the menu item out in new color
				i = 3;//set i to 2 to start menu from bottom
			}
			break;

			//left
		case 77:
			if (i< MaxNo_Menu - 1)
			{
				
				aesthetics.gotoxy(xpos[i], ypos);//set cursor position passing in i
				aesthetics.textattr(3);//set text color
				printf("%s", menu_list[i]);//print the menu item out in new color
				++i;// down key add to i
			}
			else
			{
				
				aesthetics.gotoxy(xpos[i], ypos);// set cursor position passing in i
				aesthetics.textattr(3); // reset text color
				printf("%s", menu_list[i]);//print the menu item out in new color
				i = 0;//set i to 0 to restart menu
			}
			break;

			//enter
		case 13:
			
			if (i == 0) { return 0; } /*system("cls"); hand.push_back(deck[3]); choosecard(deck,hand);*/
			if (i == 1) { return 10; }
			if (i == 2) { return 50; }
			if (i == 3) { return 100;}
			if (i == 4)  {return 200; }
			break;
		}
	}
}


//bet system stuff in here
void GamePlay::betSystem()
{

	random = rand() % 10;
	if (random < 3)
	{
		CpuFold(CpuHandValue);
	}


	// method for cpu betting logic, passing in CpuHandValue to determine what it does
	bet = menu(); // storing the variable returned from menu class to bet
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
			cash = cash - bet;
			pot = pot + bet;
		}

	}
}
void GamePlay::CpuBetting(int CpuHandValue)
{
	if (cpucash > 0)
	{
		if (CpuHandValue >= 90)
		{

			cpubet = cpucash;
			cpucash = cpucash - cpubet;
			pot = pot + cpubet;

		}
		else if (CpuHandValue < 90 && CpuHandValue >= 50)
		{
			cpubet = 50;
			cpucash = cpucash - cpubet;
			pot = pot + cpubet;

		}
		else if (CpuHandValue < 50 && CpuHandValue >= 6)
		{
			cpubet = 10;
			cpucash = cpucash - cpubet;
			pot = pot + cpubet;


		}
		else if (CpuHandValue < 5)
		{

			cpubet = 0;
			cpucash = cpucash - cpubet;
			pot = pot + cpubet;
			//thirdhand();
		}
	}
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










