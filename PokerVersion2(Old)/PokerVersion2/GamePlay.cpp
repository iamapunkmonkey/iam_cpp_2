#include "Aesthetics.h"
#include "GamePlay.h"
#include "Checks.h"
#include "Poker.h"


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
vector<int> PlayerValues = ::PlayerValues;
vector<char> psuits = ::psuits;
vector<int> cvalues = ::cvalues;
vector<char> csuits = ::csuits;
vector<int> dvalues = ::dvalues;
vector<char> dsuits = ::dsuits;
bool foldc = ::foldc;
bool foldv = ::foldv;
bool NewGameMenu = ::NewGameMenu;
bool allin = ::allin;
bool duringhand = ::duringhand;
int cash = ::cash;
int cpucash = ::cpucash;

int pot = ::pot;
int bet = ::bet;
int cpubet = ::cpubet;
int PlayerHandValue = ::PlayerHandValue;
int CpuHandValue = ::CpuHandValue;
int g = ::g;
int random = ::random;

string inhand = ::inhand;
string chand = ::chand;
string result = ::result;
string PressEnterToContinue = ::PressEnterToContinue;
string fold = ::fold;
string arrows = ::arrows;
string enter = ::enter;


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
	dvalues.clear();
	dsuits.clear();
	pot = 0;
	result = "";
	inhand = "";
}
//resets all game stuff 
void GamePlay::Start() //What user will see first, displays start money (Omoney)
{
	Poker a;
	//call the Start method when you want to start a new game
	Clear();// clearing all stored variables
	//GamePlay();
	system("cls"); // clearing the screen
	cash = 200; // initializing player cash amount
	cpucash = 200; // initializing cpu cash amount
	pot = 0; // initializing pot value to 0
	a.createdeck(deck); // creating a deck of cards
	a.shuffle(deck); // shuffling the deck
	a.tablecards(deck, 8); // creating the table cards passing value for amount of cards
	// begins at 5, so 8 for 3 cards 9 for 4 cards and 10 for 5 cards, should be able to clear tablecards and pass in
	//new value as long as deck is not shuffled so starts at 8, bet 1 add card bet 2 add another, bet 3 determine winner
	a.playercard(deck);// creates the players hand with 2 cards
	a.cpucard(deck);//creates the players hand with 2 cards
	a.createhand(hand, 25, 40); // draw player cards, passing in hand, 5 and 20 stay the same for location
	a.createtable(tablehand, 5, 17);// drawing the table cards passing in table hand, 5 and 7 stay for location
	Game(); // begins the game

}
void GamePlay::Fold()
{
	result = "You Win!";
	Text();
	foldc = false;
	thirdhand();
	NewHand();
}
void GamePlay::NewHand()
{
	Poker a;
	
	foldc = false;
	//call the NewHand method to begin a new hand without changing the pot and cash values
	Clear();// clearing all stored variables
	cash = cash;
	cpucash = cpucash;
	system("cls"); // clearing the screen
	a.createdeck(deck); // creating a deck of cards
	a.shuffle(deck); // shuffling the deck
	a.tablecards(deck, 8); // creating the table cards passing value for amount of cards
	// begins at 5, so 8 for 3 cards 9 for 4 cards and 10 for 5 cards, should be able to clear tablecards and pass in
	//new value as long as deck is not shuffled so starts at 8, bet 1 add card bet 2 add another, bet 3 determine winner
	a.playercard(deck);// creates the players hand with 2 cards
	a.cpucard(deck);//creates the players hand with 2 cards
	//createhand(hand, 5, 20); // draw player cards, passing in hand, 5 and 20 stay the same for location
	//createtable(tablehand, 5, 7);// drawing the table cards passing in table hand, 5 and 7 stay for location
	Game(); // begins the game



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
			if (i< MaxNo_Menu - 1)
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
			
			if (i == 0) { return 0; } /*system("cls"); hand.push_back(deck[3]); choosecard(deck,hand);*/
			if (i == 1) { return 10; }
			if (i == 2) { return 50; }
			if (i == 3) {

				//cd.tablecards(deck, 10); 
				return 100;
				AltGame();

			}
			if (i == 4)  { Fold(); return 0; }
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
		//a.tablecards(deck, 10);
		allin = false;
		Text();
		thirdhand2();
		duringhand = false;
		Start();

	}


}
void GamePlay::NGameMenu()
{
	Aesthetics cd;
	cd.textattr(8);
	cout << "		 _________ ";
	cd.textattr(12);
	cout << "  _________   ";
	cd.textattr(8);
	cout << "_________   ";
	cd.textattr(12);
	cout << "__________" << endl;
	cd.textattr(8);
	cout << "	        /         \\";
	cd.textattr(12);
	cout << " /         \\ ";
	cd.textattr(8);
	cout << "/         \\ ";
	cd.textattr(12);
	cout << "/          \\" << endl;
	cd.textattr(8);
	cout << "                 Game Over  ";
	cd.textattr(12);
	cout << " Game Over ";
	cd.textattr(8);
	cout << "  Game Over ";
	cd.textattr(12);
	cout << "  Game Over   " << endl;
	cd.textattr(8);
	cout << "                     ,      ";
	cd.textattr(12);
	cout << "    _ _     ";
	cd.textattr(8);
	cout << "     _      ";
	cd.textattr(12);
	cout << "            " << endl;
	cd.textattr(8);
	cout << "                    / \\     ";
	cd.textattr(12);
	cout << "   / ^ \\   ";
	cd.textattr(8);
	cout << "     (_)    ";
	cd.textattr(12);
	cout << "      /\\     " << endl;
	cd.textattr(8);
	cout << "                   (_ _)    ";
	cd.textattr(12);
	cout << "   \\   /   ";
	cd.textattr(8);
	cout << "    (_)_)   ";
	cd.textattr(12);
	cout << "     <  >    " << endl;
	cd.textattr(8);
	cout << "                    /_\\     ";
	cd.textattr(12);
	cout << "    \\ /    ";
	cd.textattr(8);
	cout << "     /_\\    ";
	cd.textattr(12);
	cout << "      \\/     " << endl;
	cd.textattr(8);
	cout << "                            ";
	cd.textattr(12);
	cout << "     `     ";
	cd.textattr(8);
	cout << "            ";
	cd.textattr(12);
	cout << "             " << endl;
	cd.textattr(8);
	cout << "                 Game Over   ";
	cd.textattr(12);
	cout << "Game Over";
	cd.textattr(8);
	cout << "   Game Over";
	cd.textattr(12);
	cout << "   Game Over   " << endl;
	cd.textattr(8);
	cout << "		\\_________/ ";
	cd.textattr(12);
	cout << "\\_________/ ";
	cd.textattr(8);
	cout << "\\_________/";
	cd.textattr(12);
	cout << " \\__________/" << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	char *menu_list[MaxNo_Menu2] = { "New Game", "Main Menu", "Exit" };
	int i,
		xpos = 36,
		ypos[MaxNo_Menu2] = { 15, 18, 21 };
	Aesthetics cb;

	for (i = 0; i< MaxNo_Menu2; ++i)
	{
		cb.gotoxy(xpos, ypos[i]);
		cb.textattr(3);
		printf("%s", menu_list[i]);
	}

	i = 0;
	while (1)
	{
		cb.gotoxy(xpos, ypos[i]);
		cb.textattr(11);
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
				cb.gotoxy(xpos, ypos[i]);
				cb.textattr(3);
				printf("%s", menu_list[i]);
				--i;
			}
			else
			{
				cb.gotoxy(xpos, ypos[i]);
				cb.textattr(3);
				printf("%s", menu_list[i]);
				i = 2;
			}
			break;

			//down
		case 80:
			if (i< MaxNo_Menu2 - 1)
			{
				cb.gotoxy(xpos, ypos[i]);
				cb.textattr(3);
				printf("%s", menu_list[i]);
				++i;
			}
			else
			{
				cb.gotoxy(xpos, ypos[i]);
				cb.textattr(3);
				printf("%s", menu_list[i]);
				i = 0;
			}
			break;

			//enter
		case 13:
			if (i == 0) { GamePlay gp; gp.Start(); }
			if (i == 1) {
				GamePlay gp;
				Aesthetics a;
				gp.Clear();
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
	char *menu_list[MaxNo_Menu2] = { "New Game", "Main Menu", "Exit" };
	int i,
		xpos = 36,
		ypos[MaxNo_Menu2] = { 15, 18, 21 };
	Aesthetics cb;

	for (i = 0; i< MaxNo_Menu2; ++i)
	{
		cb.gotoxy(xpos, ypos[i]);
		cb.textattr(3);
		printf("%s", menu_list[i]);
	}

	i = 0;
	while (1)
	{
		cb.gotoxy(xpos, ypos[i]);
		cb.textattr(11);
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
				cb.gotoxy(xpos, ypos[i]);
				cb.textattr(3);
				printf("%s", menu_list[i]);
				--i;
			}
			else
			{
				cb.gotoxy(xpos, ypos[i]);
				cb.textattr(3);
				printf("%s", menu_list[i]);
				i = 2;
			}
			break;

			//down
		case 80:
			if (i< MaxNo_Menu2 - 1)
			{
				cb.gotoxy(xpos, ypos[i]);
				cb.textattr(3);
				printf("%s", menu_list[i]);
				++i;
			}
			else
			{
				cb.gotoxy(xpos, ypos[i]);
				cb.textattr(3);
				printf("%s", menu_list[i]);
				i = 0;
			}
			break;

			//enter
		case 13:
			if (i == 0) { GamePlay gp; gp.Start(); }
			if (i == 1) {
				GamePlay gp;
				Aesthetics a;
				gp.Clear();
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
	arrows = "[<-- --> arrow keys to move]";
	enter = "[Hit Enter]";
	a.textattr(11);
	a.gotoxy(33, 38);
	printf("%s", "Your Cards");
	a.textattr(2);
	a.gotoxy(31, 50);
	printf("%s", "Your Money");
	a.gotoxy(42, 50);
	a.textattr(10);
	printf("%i", cash); // displaying player cash


	a.gotoxy(75, 46);
	a.textattr(11);
	printf("%s", "Current Hand:");
	a.gotoxy(75, 48);
	a.textattr(15);
	cout << inhand; // displaying what you have in your hand
	a.textattr(14);
	a.gotoxy(33, 1);
	printf("%s", "CPU Cards");
	a.textattr(14);
	a.gotoxy(75, 1);
	printf("%s", "CPU Hand");
	a.gotoxy(75, 3);
	a.textattr(15);
	cout << chand;
	a.gotoxy(30, 13);
	a.textattr(2);
	printf("%s", "CPU Money");
	a.gotoxy(71, 30);
	a.textattr(15);
	printf("%s", "Instructions:");
	a.gotoxy(71, 33);
	a.textattr(15);
	cout << arrows;
	a.gotoxy(71, 36);
	a.textattr(15);
	cout << enter;
	a.gotoxy(40, 13);
	a.textattr(10);
	printf("%i", cpucash); // displaying cpu cash
	a.textattr(13);
	a.gotoxy(55, 28);
	cout << PressEnterToContinue;
	a.gotoxy(35, 28);
	a.textattr(2);
	printf("%s", "Pot Total");
	a.textattr(8);
	a.gotoxy(37, 33);
	cout << fold;
	a.gotoxy(45, 28);
	a.textattr(10);
	printf("%i", pot); // displaying the pot total

	a.textattr(8);
	a.gotoxy(37, 30);
	cout << result; // displaying if you won or lost the hand






}
// main game logic goes in here 
void GamePlay::Game()
{

	//// need these to redraw the table and split cards once new one is added
	//createtable(tablehand, 5, 7);  // this will create the table, passing in the table hand, always pass in 5 and 7 for location
	//Cards();//creating the hands  
	////

	////determine the hand values
	//PlayerHandValue = DetermineHand(PlayerValues, psuits);// determine the player hand storing value in PlayerHandValue
	//CpuHandValue = determinecpuhand(cvalues, csuits);// determine the cpu hand storing value in CpuHandValue
	////
	////determine the winner do not call this here it should be placed after the 3rd bet
	//determine(); // this method will compare PlayerHandValue and CpuHandValue to determine the winner call this at end of game -
	//             // calling here for testing , do not leave in main logic
	////

	////draw text on console, needs to be after the determine hand logic to display
	//Text(); // method to display the text on screen
	////
	////betting logic
	//CpuBetting(CpuHandValue); // method for cpu betting logic, passing in CpuHandValue to determine what it does

	//bet = menu(); // storing the variable returned from menu class to bet
	//Betting(bet); // player betting method passing in the value stored at bet
	////

	Checks ck1;
	Checks ck2;
	Checks ck3;
	Poker a;
	

	int x = 24;
	int y = 3;

	duringhand = true;



	if (g == 0)
	{
		PlayerHandValue = 0;
		CpuHandValue = 0;
		result = "";

		system("cls");
		showc = false;
		shows = false;
		foldc = false;
		fold = " ";
		a.createhand(hand, 25, 40);
		a.createtable(tablehand, 5, 17);  // this will create the table, passing in the table hand, always pass in 5 and 7 for location
		Cards();//creating the hands  
		a.drawdefaultcpu(cpuhand, x, y);
		PlayerHandValue = ck1.DetermineHand(PlayerValues, psuits);// determine the player hand storing value in PlayerHandValue
		CpuHandValue = ck1.determinecpuhand(cvalues, csuits);// determine the cpu hand storing value in CpuHandValue
		if (!showc)
		{
			chand = "?????";
		}
		if (!shows)
		{
			PressEnterToContinue = " ";
		}
		if (!foldc)
		{
			fold = " ";
		}
		random = rand() % 10;
		if (random < 3)
		{
			CpuFold(CpuHandValue);
		}
		Text(); // method to display the text on screen
		//
		//betting logic

		// method for cpu betting logic, passing in CpuHandValue to determine what it does
		bet = menu(); // storing the variable returned from menu class to bet
		Betting(bet); // player betting method passing in the value stored at bet
		CpuBetting(bet);


		g++;
		Game();
	}
	if (g == 1)
	{
		PlayerHandValue = 0;
		CpuHandValue = 0;
		result = "";
		system("cls");
		a.createhand(hand, 25, 40);
		if (!allin)
		{
			a.tablecards(deck, 9);
		}
		a.createtable(tablehand, 5, 17);
		a.createtable(tablehand, 5, 17);// this will create the table, passing in the table hand, always pass in 5 and 7 for location
		Cards();//creating the hands  
		a.drawdefaultcpu(cpuhand, x, y);
		PlayerHandValue = ck2.DetermineHand(PlayerValues, psuits);// determine the player hand storing value in PlayerHandValue
		CpuHandValue = ck2.determinecpuhand(cvalues, csuits);// determine the cpu hand storing value in CpuHandValue
		if (!showc)
		{
			chand = "?????";
		}
		if (!shows)
		{
			PressEnterToContinue = " ";
		}
		if (!foldc)
		{
			fold = " ";
		}
		random = rand() % 10;
		if (random < 3)
		{
			CpuFold(CpuHandValue);
		}
		Text(); // method to display the text on screen
		//
		bet = menu(); // storing the variable returned from menu class to bet
		Betting(bet); // player betting method passing in the value stored at bet
		CpuBetting(bet);

		g = 2;
		//Game();
	}
	if (g == 2)
	{
		PlayerHandValue = 0;
		CpuHandValue = 0;
		result = "";

		system("cls");
		a.createhand(hand, 25, 40);
		if (!allin)
		{
			a.tablecards(deck, 10);
		}
		a.createtable(tablehand, 5, 17);  // this will create the table, passing in the table hand, always pass in 5 and 7 for location
		Cards();//creating the hands  
		a.drawdefaultcpu(cpuhand, x, y);
		PlayerHandValue = ck3.DetermineHand(PlayerValues, psuits);// determine the player hand storing value in PlayerHandValue
		CpuHandValue = ck3.determinecpuhand(cvalues, csuits);// determine the cpu hand storing value in CpuHandValue
		if (!showc)
		{
			chand = "?????";
		}
		if (!shows)
		{
			PressEnterToContinue = " ";
		}
		if (!foldc)
		{
			fold = " ";
		}

		random = rand() % 10;
		if (random < 3)
		{
			CpuFold(CpuHandValue);
		}
		Text(); // method to display the text on screen
		//
		bet = menu(); // storing the variable returned from menu class to bet
		Betting(bet); // player betting method passing in the value stored at bet
		CpuBetting(bet);

		g = 3;
		//Game();
	}
	if (g == 3)
	{
		thirdhand();
	}
}
void GamePlay::thirdhand()
{
	Checks b;
	PlayerHandValue = 0;
	CpuHandValue = 0;
	result = "";
	int x = 24;
	int y = 3;
	showc = true;
	shows = true;
	PressEnterToContinue = "Press Enter To Continue...";

	Checks ck;
	Poker a;
	Aesthetics cb;
	system("cls");
	a.createhand(hand, 25, 40);
	a.createtable(tablehand, 5, 17);  // this will create the table, passing in the table hand, always pass in 5 and 7 for location
	Cards();
	a.drawcpucard(cpuhand, x, y);//creating the hands  
	PlayerHandValue = ck.DetermineHand(PlayerValues, psuits);// determine the player hand storing value in PlayerHandValue
	CpuHandValue = ck.determinecpuhand(cvalues, csuits);// determine the cpu hand storing value in CpuHandValue

	if (foldv)
	{
		PlayerHandValue = 0;
	}
	ck.determine(PlayerHandValue, CpuHandValue);
	if (showc)
	{
		chand = chand;
	}
	if (shows)
	{
		PressEnterToContinue = PressEnterToContinue;
	}
	if (!foldc)
	{
		fold = " ";
	}
	if (foldc == true)
	{
		//fold = "YOU LOSE!";
	}
	Text(); // method to display the text on screen
	cin.get();
	cout << chand;
	g = 0;
	duringhand = true;
	if (!duringhand)
	{
		cb.text1("You Ran Out of Money!");
		cin.get();
		system("cls");
		Clear();
		NGameMenu();
	}
	if (cash == 0)
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
	Checks b;
	PlayerHandValue = 0;
	CpuHandValue = 0;
	result = "";
	int x = 24;
	int y = 3;
	showc = true;
	shows = true;
	PressEnterToContinue = "Press Enter To Continue...";

	Checks ck;
	Poker a;
	
	system("cls");
	a.tablecards(deck, 10);
	a.createhand(hand, 25, 40);
	a.createtable(tablehand, 5, 17);  // this will create the table, passing in the table hand, always pass in 5 and 7 for location
	Cards();
	a.drawcpucard(cpuhand, x, y);//creating the hands  
	PlayerHandValue = ck.DetermineHand(PlayerValues, psuits);// determine the player hand storing value in PlayerHandValue
	CpuHandValue = ck.determinecpuhand(cvalues, csuits);// determine the cpu hand storing value in CpuHandValue

	if (foldv)
	{
		PlayerHandValue = 0;
	}
	ck.determine(PlayerHandValue, CpuHandValue);
	if (showc)
	{
		chand = chand;
	}
	if (shows)
	{
		PressEnterToContinue = PressEnterToContinue;
	}
	if (!foldc)
	{
		fold = " ";
	}
	if (foldc == true)
	{
		//fold = "YOU LOSE!";
	}
	Text(); // method to display the text on screen
	cout << chand;
	cin.get();
	g = 0;
	cash = 0;
	if (cash == 0)
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
	Poker a;
	a.playertest(tablehand, hand);
	a.playerval(playerhand);
	a.playersuit(playerhand);

	a.computertest(tablehand, cpuhand);
	a.computerval(computerhand);
	a.computersuit(computerhand);


}
//bet system stuff in here
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
			//need to turn on for actual game
			bet = 10;
			cash = cash - bet;
			pot = pot + bet;

			////DO NOT LEAVE THIS IN
			//Start();
		}
		else if (bet == 0)
		{

			bet = 0;
			cash = cash - bet;
			pot = pot + bet;
		}

	}
	else
	{
		
		system("cls");

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
	Poker a;
	if (cpucash > 0)
	{
		if (CpuHandValue < 5)
		{
			cpubet = 0;
			cpucash = cpucash - cpubet;
			pot = pot + cpubet;
			a.tablecards(deck, 10);

			//thirdhand();
			Fold();
		}
	}

}
//
