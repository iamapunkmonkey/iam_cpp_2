#include "Aesthetics.h"
#include "GamePlay.h"
#include "Checks.h"
#include "Poker.h"


#define MaxNo_BetMenu 5
#define MaxNo_MainMenu 3
#define MaxNo_NewMenu 3
//
vector<string>playerhand;
vector<string>cards;
vector<string>deck;
vector<string>pHand;
vector<string>cHand;
vector<string>tablehand;
vector<string> computerhand;
//
vector<int> pvalues;
vector<char> psuits;
vector<int> cvalues;
vector<char> csuits;
vector<int> tempValues;
vector<char> tempSuits; //Tty to set up only 2 varliables for all players... 
//
bool foldCardsText; //if true fold text inits
bool foldv; //not sure what this does
bool newMenuInit = ::newMenuInit;
bool allin = ::allin; //asks program: did the player go all in?
bool duringhand = ::duringhand; //asks program: is this during the hand?
//
int pCash = ::pCash; //the variable that holds the cash value for player.
int cpucash = ::cpucash; //the variable that holds the cash value for cpu.
int pot; //the value of the current Pot.
int currentBet = ::currentBet; //the current Bet.
int cpubet = ::cpubet; //computer bet variable.
int pHand_GP; //playerHand (for) GamePlay class.
int cHand_GP; //computerHand (for) GamePlay class.
int GameProgression = ::GameProgression; //illustrates the stage you are at in game.
int AIBehavior = ::AIBehavior; //bluff or fold AI behavior variable. (is a random int).
//
string text_pHand;
string text_cHand;
string text_result;
string text_stupidMsg;
string text_fold;
string text_arrows;
string text_enter;

GamePlay::GamePlay() : Omoney(200)
{ //Constructor class, defines Omoney (original money)
}
//clears
void GamePlay::Clear()
{
	playerhand.clear();
	cards.clear();
	deck.clear();
	pHand.clear();
	cHand.clear();
	tablehand.clear();
	computerhand.clear();
	pvalues.clear();
	psuits.clear();
	cvalues.clear();
	csuits.clear();
	tempValues.clear();
	tempSuits.clear();
	pot = 0;
	text_result = "";
	text_pHand = "";
}
//resets all game stuff 
void GamePlay::Start() //What user will see first, displays start money (Omoney)
{
	Poker a;
	//call the Start method when you want to start a new game
	Clear();// clearing all stored variables
	system("cls"); // clearing the screen
	pCash = 200; // initializing player cash amount
	cpucash = 200; // initializing cpu cash amount
	pot = 0; // initializing pot value to 0
	a.createdeck(deck); // creating a deck of cards
	a.shuffle(deck); // shuffling the deck
	a.tablecards(deck, 8); // creating the table cards passing value for amount of cards
	// begins at 5, so 8 for 3 cards 9 for 4 cards and 10 for 5 cards, should be able to clear tablecards and pass in
	//new value as long as deck is not shuffled so starts at 8, bet 1 add card bet 2 add another, bet 3 determine winner
	a.playercard(deck);// creates the players hand with 2 cards
	a.cpucard(deck);//creates the players hand with 2 cards
	a.createhand(pHand, 25, 40); // draw player cards, passing in hand, 5 and 20 stay the same for location
	a.createtable(tablehand, 5, 17);// drawing the table cards passing in table hand, 5 and 7 stay for location
	Game(); // begins the game

}
void GamePlay::computerFold()
{
	text_result = "You Win!";
	Text();
	foldCardsText = false;
	thirdhand();
	NewHand();
}
void GamePlay::NewHand()
{
	Poker a;
	foldCardsText = false;
	//call the NewHand method to begin a new hand without changing the pot and cash values
	Clear();// clearing all stored variables
	pCash = pCash;
	cpucash = cpucash;
	system("cls"); // clearing the screen
	a.createdeck(deck); // creating a deck of cards
	a.shuffle(deck); // shuffling the deck
	a.tablecards(deck, 8); // creating the table cards passing value for amount of cards
	// begins at 5, so 8 for 3 cards 9 for 4 cards and 10 for 5 cards, should be able to clear tablecards and pass in
	//new value as long as deck is not shuffled so starts at 8, bet 1 add card bet 2 add another, bet 3 determine winner
	a.playercard(deck);// creates the players hand with 2 cards
	a.cpucard(deck);//creates the players hand with 2 cards
	Game(); // begins the game
}
//game menu
int GamePlay::gameMenu()//side menu
{
	char *menu_list[MaxNo_BetMenu] = { "Check", "Bet 10", "Bet 50", "All In", "Fold" };
	int i,
		xpos[MaxNo_BetMenu] = { 15, 30, 45, 60, 75 },
		ypos = 53;

	// list the menu
	for (i = 0; i< MaxNo_BetMenu; ++i)
	{
		Aesthetics a;
		a.gotoxy(xpos[i], ypos);
		a.textattr(3);
		printf("%s", menu_list[i]);
	}

	// make menu available to choose
	i = 0; // set i to 0 to start menu at the begining
	while (1)
	{
		Aesthetics a;
		a.gotoxy(xpos[i], ypos);// set cursor position
		a.textattr(11); // this sets menu item to green text
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
				Aesthetics a;
				a.gotoxy(xpos[i], ypos);//set cursor position passing in i
				a.textattr(3); // set text color passing in color
				printf("%s", menu_list[i]); // print the menu item out in new color
				--i;//up key subtract from i
			}
			else
			{
				Aesthetics a;
				a.gotoxy(xpos[i], ypos);// set cursor position passing in i
				a.textattr(3); // reset text color
				printf("%s", menu_list[i]);//print the menu item out in new color
				i = 3;//set i to 2 to start menu from bottom
			}
			break;

			//left
		case 77:
			if (i< MaxNo_BetMenu - 1)
			{
				Aesthetics a;
				a.gotoxy(xpos[i], ypos);//set cursor position passing in i
				a.textattr(3);//set text color
				printf("%s", menu_list[i]);//print the menu item out in new color
				++i;// down key add to i
			}
			else
			{
				Aesthetics a;
				a.gotoxy(xpos[i], ypos);// set cursor position passing in i
				a.textattr(3); // reset text color
				printf("%s", menu_list[i]);//print the menu item out in new color
				i = 0;//set i to 0 to restart menu
			}
			break;

			//enter
		case 13:
			//Poker cd;
			if (i == 0) { return 0; }
			if (i == 1) { return 10; }
			if (i == 2) { return 50; }
			if (i == 3) {

				//cd.tablecards(deck, 10); 
				return 100;
				AltGame();

			}
			if (i == 4)  { computerFold(); return 0; }
			break;
		}
	}
}
//return bet;

//game screen text
void GamePlay::AltGame()
{
	allin = true;

	if (allin)
	{
		allin = false;
		Text();
		thirdhand2();
		duringhand = false;
		Start();
	}
}
void GamePlay::NGameMenu()
{
	Aesthetics a;
	a.textattr(8);
	cout << "		 _________ ";
	a.textattr(12);
	cout << "  _________   ";
	a.textattr(8);
	cout << "_________   ";
	a.textattr(12);
	cout << "__________" << endl;
	a.textattr(8);
	cout << "	        /         \\";
	a.textattr(12);
	cout << " /         \\ ";
	a.textattr(8);
	cout << "/         \\ ";
	a.textattr(12);
	cout << "/          \\" << endl;
	a.textattr(8);
	cout << "                 Game Over  ";
	a.textattr(12);
	cout << " Game Over ";
	a.textattr(8);
	cout << "  Game Over ";
	a.textattr(12);
	cout << "  Game Over   " << endl;
	a.textattr(8);
	cout << "                     ,      ";
	a.textattr(12);
	cout << "    _ _     ";
	a.textattr(8);
	cout << "     _      ";
	a.textattr(12);
	cout << "            " << endl;
	a.textattr(8);
	cout << "                    / \\     ";
	a.textattr(12);
	cout << "   / ^ \\   ";
	a.textattr(8);
	cout << "     (_)    ";
	a.textattr(12);
	cout << "      /\\     " << endl;
	a.textattr(8);
	cout << "                   (_ _)    ";
	a.textattr(12);
	cout << "   \\   /   ";
	a.textattr(8);
	cout << "    (_)_)   ";
	a.textattr(12);
	cout << "     <  >    " << endl;
	a.textattr(8);
	cout << "                    /_\\     ";
	a.textattr(12);
	cout << "    \\ /    ";
	a.textattr(8);
	cout << "     /_\\    ";
	a.textattr(12);
	cout << "      \\/     " << endl;
	a.textattr(8);
	cout << "                            ";
	a.textattr(12);
	cout << "     `     ";
	a.textattr(8);
	cout << "            ";
	a.textattr(12);
	cout << "             " << endl;
	a.textattr(8);
	cout << "                 Game Over   ";
	a.textattr(12);
	cout << "Game Over";
	a.textattr(8);
	cout << "   Game Over";
	a.textattr(12);
	cout << "   Game Over   " << endl;
	a.textattr(8);
	cout << "		\\_________/ ";
	a.textattr(12);
	cout << "\\_________/ ";
	a.textattr(8);
	cout << "\\_________/";
	a.textattr(12);
	cout << " \\__________/" << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	char *menu_list[MaxNo_NewMenu] = { "New Game", "Main Menu", "Exit" };
	int i,
		xpos = 36,
		ypos[MaxNo_NewMenu] = { 15, 18, 21 };
	//Aesthetics a;

	for (i = 0; i< MaxNo_NewMenu; ++i)
	{
		a.gotoxy(xpos, ypos[i]);
		a.textattr(3);
		printf("%s", menu_list[i]);
	}

	i = 0;
	while (1)
	{
		a.gotoxy(xpos, ypos[i]);
		a.textattr(11);
		printf("%s", menu_list[i]);

		/* note : 72 -> UP button
		75 -> RIGHT button
		77 -> LEFT button
		80 -> DOWN button
		*/

		switch (_getch())
		{
			//up
		case 72:
			if (i>0)
			{
				a.gotoxy(xpos, ypos[i]);
				a.textattr(3);
				printf("%s", menu_list[i]);
				--i;
			}
			else
			{
				a.gotoxy(xpos, ypos[i]);
				a.textattr(3);
				printf("%s", menu_list[i]);
				i = 2;
			}
			break;

			//down
		case 80:
			if (i< MaxNo_NewMenu - 1)
			{
				a.gotoxy(xpos, ypos[i]);
				a.textattr(3);
				printf("%s", menu_list[i]);
				++i;
			}
			else
			{
				a.gotoxy(xpos, ypos[i]);
				a.textattr(3);
				printf("%s", menu_list[i]);
				i = 0;
			}
			break;

			//enter
		case 13:
			GamePlay g;
			if (i == 0) { g.Start(); }
			if (i == 1) {
				Aesthetics a;
				g.Clear();
				system("cls");
				a.header();
				a.MainMenu();
			};
			if (i == 2) { exit(0); }
			break;
		}
	}
}
void GamePlay::NGameMenu2()

{
	char *menu_list[MaxNo_NewMenu] = { "New Game", "Main Menu", "Exit" };
	int i,
		xpos = 36,
		ypos[MaxNo_NewMenu] = { 15, 18, 21 };
	Aesthetics a;

	for (i = 0; i< MaxNo_NewMenu; ++i)
	{
		a.gotoxy(xpos, ypos[i]);
		a.textattr(3);
		printf("%s", menu_list[i]);
	}

	i = 0;
	while (1)
	{
		a.gotoxy(xpos, ypos[i]);
		a.textattr(11);
		printf("%s", menu_list[i]);

		/* note : 72 -> UP button
		75 -> RIGHT button
		77 -> LEFT button
		80 -> DOWN button
		*/

		switch (_getch())
		{
			//up
		case 72:
			if (i>0)
			{
				a.gotoxy(xpos, ypos[i]);
				a.textattr(3);
				printf("%s", menu_list[i]);
				--i;
			}
			else
			{
				a.gotoxy(xpos, ypos[i]);
				a.textattr(3);
				printf("%s", menu_list[i]);
				i = 2;
			}
			break;

			//down
		case 80:
			if (i< MaxNo_NewMenu - 1)
			{
				a.gotoxy(xpos, ypos[i]);
				a.textattr(3);
				printf("%s", menu_list[i]);
				++i;
			}
			else
			{
				a.gotoxy(xpos, ypos[i]);
				a.textattr(3);
				printf("%s", menu_list[i]);
				i = 0;
			}
			break;

			//enter
		case 13:
			GamePlay g;
			if (i == 0) { g.Start(); }
			if (i == 1) {
				Aesthetics a;
				g.Clear();
				system("cls");
				a.header();
				a.MainMenu();
			};
			if (i == 2) { exit(0); }
			break;
		}
	}
}
void GamePlay::Text()
{
	Aesthetics a;
	text_arrows = "[<-- --> arrow keys to move]";
	text_enter = "[Hit Enter]";
	a.textattr(11);
	a.gotoxy(33, 38);
	printf("%s", "Your Cards");
	a.textattr(2);
	a.gotoxy(31, 50);
	printf("%s", "Your Money");
	a.gotoxy(42, 50);
	a.textattr(10);
	printf("%i", pCash); // displaying player cash


	a.gotoxy(75, 46);
	a.textattr(11);
	printf("%s", "Current Hand:");
	a.gotoxy(75, 48);
	a.textattr(15);
	cout << text_pHand; //displays the TEXT of what you have in your hand
	a.textattr(14);
	a.gotoxy(33, 1);
	printf("%s", "CPU Cards");
	a.textattr(14);
	a.gotoxy(75, 1);
	printf("%s", "CPU Hand");
	a.gotoxy(75, 3);
	a.textattr(15);
	cout << text_cHand;
	a.gotoxy(30, 13);
	a.textattr(2);
	printf("%s", "CPU Money");
	a.gotoxy(71, 30);
	a.textattr(15);
	printf("%s", "Instructions:");
	a.gotoxy(71, 33);
	a.textattr(15);
	cout << text_arrows;
	a.gotoxy(71, 36);
	a.textattr(15);
	cout << text_enter;
	a.gotoxy(40, 13);
	a.textattr(10);
	printf("%i", cpucash); // displaying cpu cash
	a.textattr(13);
	a.gotoxy(55, 28);
	cout << text_stupidMsg;
	a.gotoxy(35, 28);
	a.textattr(2);
	printf("%s", "Pot Total");
	a.textattr(8);
	a.gotoxy(37, 33);
	cout << text_fold;
	a.gotoxy(45, 28);
	a.textattr(10);
	printf("%i", pot); // displaying the pot total

	a.textattr(8);
	a.gotoxy(37, 30);
	cout << text_result; // displaying if you won or lost the hand
}
// main game logic goes in here 
void GamePlay::Game()
{
	Checks ck1;
	Checks ck2;
	Checks ck3;
	Poker p;

	int x = 24;
	int y = 3;

	duringhand = true;

	if (GameProgression == 0)
	{
		pHand_GP = 0;
		cHand_GP = 0;
		text_result = "";

		system("cls");
		showc = false;
		shows = false;
		foldCardsText = false;
		text_fold = " ";

		p.createhand(pHand, 25, 40);
		p.createtable(tablehand, 5, 17);  // this will create the table, passing in the table hand, always pass in 5 and 7 for location
		Cards();//creating the hands  
		p.drawdefaultcpu(cHand, x, y);

		pHand_GP = ck1.determinehand(pvalues, psuits);// determine the player hand storing value in v
		cHand_GP = ck1.determinecpuhand(cvalues, csuits);// determine the cpu hand storing value in z

		if (!showc)
		{
			text_cHand = "?????";
		}
		if (!shows)
		{
			text_stupidMsg = " ";
		}
		if (!foldCardsText)
		{
			text_fold = " ";
		}
		AIBehavior = rand() % 10;
		if (AIBehavior < 3)
		{
			CpuFold(cHand_GP);
		}
		Text(); // method to display the text on screen
		//
		//betting logic

		// method for cpu betting logic, passing in z to determine what it does
		currentBet = gameMenu(); // storing the variable returned from menu class to bet
		Betting(currentBet); // player betting method passing in the value stored at bet
		CpuBetting(currentBet);


		GameProgression++;
		Game();
	}
	if (GameProgression == 1)
	{
		pHand_GP = 0;
		cHand_GP = 0;
		text_result = "";
		system("cls");
		p.createhand(pHand, 25, 40);
		if (!allin)
		{
			p.tablecards(deck, 9);
		}
		p.createtable(tablehand, 5, 17);
		p.createtable(tablehand, 5, 17);// this will create the table, passing in the table hand, always pass in 5 and 7 for location
		Cards();//creating the hands  
		p.drawdefaultcpu(cHand, x, y);
		
		pHand_GP = ck1.determinehand(pvalues, psuits);// determine the player hand storing value in v
		cHand_GP = ck1.determinecpuhand(cvalues, csuits);// determine the cpu hand storing value in z

		if (!showc)
		{
			text_cHand = "?????";
		}
		if (!shows)
		{
			text_stupidMsg = " ";
		}
		if (!foldCardsText)
		{
			text_fold = " ";
		}

		AIBehavior = rand() % 10;
		if (AIBehavior < 3)
		{
			CpuFold(cHand_GP);
		}

		Text(); // method to display the text on screen
		//
		currentBet = gameMenu(); // storing the variable returned from menu class to bet
		Betting(currentBet); // player betting method passing in the value stored at bet
		CpuBetting(currentBet);

		GameProgression = 2;
	}
	if (GameProgression == 2)
	{
		pHand_GP = 0;
		cHand_GP = 0;
		text_result = " ";

		system("cls");
		p.createhand(pHand, 25, 40);

		if (!allin)
		{
			p.tablecards(deck, 10);
		}

		p.createtable(tablehand, 5, 17);  // this will create the table, passing in the table hand, always pass in 5 and 7 for location
		Cards();//creating the hands  
		p.drawdefaultcpu(cHand, x, y);

		pHand_GP = ck1.determinehand(pvalues, psuits);// determine the player hand storing value in v
		cHand_GP = ck1.determinecpuhand(cvalues, csuits);// determine the cpu hand storing value in z

		if (!showc)
		{
			text_cHand = "?????";
		}
		if (!shows)
		{
			text_stupidMsg = " ";
		}
		if (!foldCardsText)
		{
			text_fold = " ";
		}

		AIBehavior = rand() % 10;
		if (AIBehavior < 3)
		{
			CpuFold(cHand_GP);
		}

		Text(); // method to display the text on screen
		//
		currentBet = gameMenu(); // storing the variable returned from menu class to bet
		Betting(currentBet); // player betting method passing in the value stored at bet
		CpuBetting(currentBet);

		GameProgression = 3;
	}

	if (GameProgression == 3)
	{
		thirdhand();
	}
}
void GamePlay::thirdhand()
{
	Checks ck2;

	pHand_GP = 0;
	cHand_GP = 0;
	text_result = " ";
	int x = 24;
	int y = 3;
	showc = true;
	shows = true;
	text_stupidMsg = "Press Enter To Continue...";

	Poker p;
	Aesthetics a;
	system("cls");
	p.createhand(pHand, 25, 40);
	p.createtable(tablehand, 5, 17);  // this will create the table, passing in the table hand, always pass in 5 and 7 for location
	Cards();
	p.drawcpucard(cHand, x, y);//creating the hands  
	pHand_GP = ck2.determinehand(pvalues, psuits);// determine the player hand storing value in v
	cHand_GP = ck2.determinehand(pvalues, psuits);// determine the player hand storing value in v

	if (foldv)
	{
		pHand_GP = 0;
	}

	ck2.awardWinner(pHand_GP, cHand_GP);
	if (showc)
	{
		text_cHand = text_cHand;
	}

	if (shows)
	{
		text_stupidMsg = text_stupidMsg;
	}

	if (!foldCardsText)
	{
		text_fold = " ";
	}

	if (foldCardsText == true)
	{
		text_fold = "YOU LOSE!";
	}
	Text(); // method to display the text on screen
	cin.get();
	cout << text_cHand;
	GameProgression = 0;
	duringhand = true;
	if (!duringhand)
	{
		a.text1("You Ran Out of Money!");
		cin.get();
		system("cls");
		Clear();
		NGameMenu();
	}
	if (pCash == 0)
	{
		Clear();
		system("cls");
		NGameMenu();
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
		NGameMenu2();
	}
	NewHand();

}
void GamePlay::thirdhand2()
{
	Checks ck2;

	pHand_GP = 0;
	cHand_GP = 0;
	text_result = "You Win";
	int x = 24;
	int y = 3;
	showc = true;
	shows = true;
	text_stupidMsg = "Press Enter To Continue...";

	Poker p;

	system("cls");
	p.tablecards(deck, 10);
	p.createhand(pHand, 25, 40);
	p.createtable(tablehand, 5, 17);  // this will create the table, passing in the table hand, always pass in 5 and 7 for location
	Cards();
	p.drawcpucard(cHand, x, y);//creating the hands 

	pHand_GP = ck2.determinehand(pvalues, psuits);// determine the player hand storing value in v
	cHand_GP = ck2.determinehand(pvalues, psuits);// determine the player hand storing value in v

	if (foldv)
	{
		pHand_GP = 0;
	}

	ck2.awardWinner(pHand_GP, cHand_GP);

	if (showc)
	{
		text_cHand = text_cHand;
	}

	if (shows)
	{
		text_stupidMsg = text_stupidMsg;
	}

	if (!foldCardsText)
	{
		text_fold = " ";
	}

	if (foldCardsText == true)
	{
		text_fold = "YOU LOSE!";
	}

	Text(); // method to display the text on screen

	cout << text_cHand;
	cin.get();
	GameProgression = 0;
	pCash = 0;
	if (pCash == 0)
	{
		Clear();
		system("cls");
		NGameMenu();
	}
	NewHand();

}


//creating the cards in hand
void GamePlay::Cards()
{
	Poker p;
	p.playertest(tablehand, pHand);
	p.playerval(playerhand);
	p.playersuit(playerhand);
	/*printf("%s", pHand[0].c_str()); //Get player cards here, this is the first card, need to send to highCard_forPair
	printf("%s", pHand[1].c_str()); //second card*/

	p.computertest(tablehand, cHand);
	p.computerval(computerhand);
	p.computersuit(computerhand);
	/*printf("%s", cHand[0].c_str()); //Get CPU cards here, this is the first card, need to send to highCard_forPair
	printf("%s", cHand[1].c_str()); //second card
	printf("%s", cHand._Myfirst[1].c_str());*/
}
//bet system stuff in here
void GamePlay::Betting(int bet)
{
	if (pCash > 0)
	{
		if (bet == 100)
		{
			bet = pCash;
			pCash = pCash - bet;
			pot = pot + bet;
		}
		else if (bet == 50)
		{
			bet = 50;
			pCash = pCash - bet;
			pot = pot + bet;
		}
		else if (bet == 10)
		{
			bet = 10;
			pCash = pCash - bet;
			pot = pot + bet;
		}
		else if (bet == 0)
		{
			bet = 0;
			pCash = pCash - bet;
			pot = pot + bet;
		}
	}
	else
	{
		system("cls");
	}

}
void GamePlay::CpuBetting(int z)
{
	if (cpucash > 0)
	{
		if (z >= 90)
		{

			cpubet = cpucash;
			cpucash = cpucash - cpubet;
			pot = pot + cpubet;

		}
		else if (z < 90 && z >= 50)
		{
			cpubet = 50;
			cpucash = cpucash - cpubet;
			pot = pot + cpubet;

		}
		else if (z < 50 && z >= 6)
		{
			cpubet = 10;
			cpucash = cpucash - cpubet;
			pot = pot + cpubet;


		}
		else if (z < 5)
		{

			cpubet = 0;
			cpucash = cpucash - cpubet;
			pot = pot + cpubet;
		}
	}
}
void GamePlay::CpuFold(int z)
{
	Poker p;
	if (cpucash > 0)
	{
		if (z < 5)
		{
			cpubet = 0;
			cpucash = cpucash - cpubet;
			pot = pot + cpubet;
			p.tablecards(deck, 10);
			computerFold();
		}
	}

}
//
