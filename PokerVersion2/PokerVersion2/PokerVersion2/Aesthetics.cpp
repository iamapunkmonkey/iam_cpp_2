#include "Aesthetics.h"
#include "GamePlay.h"
#include "Checks.h"
#include "Poker.h"
#include "DrawCard.h"
#include "Hands.h"




HWND hwnd = GetConsoleWindow();

HANDLE con = GetStdHandle(STD_OUTPUT_HANDLE);

void Aesthetics::Start()
{
	debugBOOL = true;
	Machine m;
}
void Aesthetics::gotoxy(int x, int y)
{
	COORD Coord;
	Coord.X = x;
	Coord.Y = y;

	SetConsoleCursorPosition(con, Coord);
}

void Aesthetics::textattr(int color)
{
	SetConsoleTextAttribute(con, color);
}

void Aesthetics::setBoolToAlertPlayer()
{
	debugBOOL = true;
	test = true;
}

void Aesthetics::mainText()
{
	textattr(11);
	gotoxy(33, 38);
	printf("%s", "Your Cards");
	textattr(2);
	gotoxy(31, 50);
	printf("%s", "Your Money");

	gotoxy(75, 46);
	textattr(11);
	printf("%s", "Current Hand:");

	textattr(14);
	gotoxy(33, 1);
	printf("%s", "CPU Cards");
	textattr(14);
	gotoxy(75, 1);
	printf("%s", "CPU Hand");

	gotoxy(30, 13);
	textattr(2);
	printf("%s", "CPU Money");
	gotoxy(71, 30);
	textattr(15);
	Instructions = "Instructions:";

	//for some reason debugBOOL is always false or true whatever i state in this if loop i have no idea why need to fix, check gameplay setbooltoalert function, i made a new
	//function in aesthetics and check whatever make sure when you work on this tomorrow to follow what you did
	if (debugBOOL)
	{
		Instructions = "test";
		textattr(4);
		cout << Instructions;
		gotoxy(71, 33);
		textattr(15);
	}
	cout << Instructions;
	gotoxy(71, 33);
	textattr(15);

	cout << "[<-- --> arrow keys to move]";
	gotoxy(71, 36);
	textattr(15);
	cout << "[Hit Enter]";

	textattr(13);
	gotoxy(55, 28);
	//cout << PressEnterToContinue;
	gotoxy(35, 28);
	textattr(2);
	printf("%s", "Pot Total");

}

void Aesthetics::changingText(int playerMoney, string playerHand, string computerHand, int computerCash, string didFold, int thePot, string theResult)
{
	gotoxy(42, 50);
	textattr(10);
	cout << playerMoney; // displaying player cash


	gotoxy(75, 48);
	textattr(15);
	cout << playerHand; // displaying what you have in your hand

	gotoxy(75, 3);
	textattr(15);
	cout << computerHand;


	gotoxy(40, 13);
	textattr(10);
	cout << computerCash; // displaying cpu cash

	textattr(8);
	gotoxy(37, 33);
	cout << didFold;
	gotoxy(45, 28);
	textattr(10);
	cout << thePot; // displaying the pot total

	textattr(8);
	gotoxy(37, 30);
	cout << theResult; // displaying if you won or lost the hand
}

void Aesthetics::text1(string words)
{
	system("cls");
	gotoxy(1, 20);
	textattr(15);
	printf("%s", words.c_str());

}

void Aesthetics::header()
{
	randomHeaderCards();
	gotoxy(35, 20); textattr(15); cout << "C++ II Final : Console Poker" << endl;
	gotoxy(35, 21); cout << "By: Jordan Max & Neil Inglese" << endl;


}

void Aesthetics::MainMenu()
{

	char *menu_list[MaxNo_Menu1] = { "Start", "Credits", "Exit" };
	int i,
		xpos = 45,
		ypos[MaxNo_Menu1] = { 24, 27, 30 };

	for (i = 0; i< MaxNo_Menu1; ++i)
	{
		gotoxy(xpos, ypos[i]);
		textattr(3);
		printf("%s", menu_list[i]);
	}

	i = 0;
	while (1)
	{
		gotoxy(xpos, ypos[i]);
		textattr(11);
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
				gotoxy(xpos, ypos[i]);
				textattr(3);
				printf("%s", menu_list[i]);
				--i;
			}
			else
			{
				gotoxy(xpos, ypos[i]);
				textattr(3);
				printf("%s", menu_list[i]);
				i = 2;
			}
			//break;

			//down
		case 80:
			if (i< MaxNo_Menu1 - 1)
			{
				gotoxy(xpos, ypos[i]);
				textattr(3);
				printf("%s", menu_list[i]);
				++i;
			}
			else
			{
				gotoxy(xpos, ypos[i]);
				textattr(3);
				printf("%s", menu_list[i]);
				i = 0;
			}
			break;

			//enter
		case 13:
			if (i == 0) { GamePlay gp;  gp.Start(); }
			if (i == 1) { Credits(); }
			if (i == 2) { exit(0); }
			//break;
		}
	}

}

int Aesthetics::raiseMenu(int valueOfCPUBet)
{
	
	char *menu_list[RaiseMenu] = { "Call", "Fold" };
	int i,
		xpos[RaiseMenu] = { 30, 45 },
		ypos = 53;

	// list the menu
	for (i = 0; i< RaiseMenu; ++i)
	{

		gotoxy(xpos[i], ypos);
		textattr(3);
		printf("%s", menu_list[i]);
	}

	// make menu available to choose
	i = 0; // set i to 0 to start menu at the beginning
	while (1)
	{

		gotoxy(xpos[i], ypos);// set cursor position
		textattr(11); // this sets menu item to green text
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

				gotoxy(xpos[i], ypos);//set cursor position passing in i
				textattr(3); // set text color passing in color
				printf("%s", menu_list[i]); // print the menu item out in new color
				--i;//up key subtract from i
			}
			else
			{

				gotoxy(xpos[i], ypos);// set cursor position passing in i
				textattr(3); // reset text color
				printf("%s", menu_list[i]);//print the menu item out in new color
				i = 3;//set i to 2 to start menu from bottom
			}
			break;

			//left
		case 77:
			if (i< RaiseMenu - 1)
			{

				gotoxy(xpos[i], ypos);//set cursor position passing in i
				textattr(3);//set text color
				printf("%s", menu_list[i]);//print the menu item out in new color
				++i;// down key add to i
			}
			else
			{

				gotoxy(xpos[i], ypos);// set cursor position passing in i
				textattr(3); // reset text color
				printf("%s", menu_list[i]);//print the menu item out in new color
				i = 0;//set i to 0 to restart menu
			}
			break;

			//enter
		case 13:
			if (i == 0) { return valueOfCPUBet; } /*system("cls"); hand.push_back(deck[3]); choosecard(deck,hand);*/
			/*if i = 1*/
			/****return int pass by from CPU*/
			if (i == 1) { return 200; }
			break;
		}
	}
	test = false;
}

//moved gameplay menu here, makes more sense

//void Aesthetics::newMenuForCheckMenu(int xpos, int ypos, char[] menu_list)
//{
//	for (i = 0; i < MaxNo_Menu; ++i)
//	{
//
//		gotoxy(xpos[i], ypos);
//		test = true;
//		textattr(3);
//		if (!test)
//			textattr(2);
//		printf("%s", menu_list[i]);
//	}
//}
int Aesthetics::gameplayMenu()
{
	char *menu_list[MaxNo_Menu] = { "Check", "Bet 10", "Bet 50", "All In", "Fold" };

	int i,
		xpos[MaxNo_Menu] = { 15, 30, 45, 60, 75 },
		ypos = 53;

	// list the menu
	//call function for for-loop
	for (i = 0; i< MaxNo_Menu; ++i)
	{

		gotoxy(xpos[i], ypos);
		textattr(3);
		
		if (test)
		{
			textattr(0);
		}
			
			
		printf("%s", menu_list[i]);
	}

	// make menu available to choose
	i = 0; // set i to 0 to start menu at the begining
	while (1)
	{

		gotoxy(xpos[i], ypos);// set cursor position
		textattr(11); // this sets menu item to green text
		if (test)
		{
			textattr(0);
			test = false;
		}
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

				gotoxy(xpos[i], ypos);//set cursor position passing in i
				textattr(3); // set text color passing in color
				printf("%s", menu_list[i]); // print the menu item out in new color
				--i;//up key subtract from i
			}
			else
			{

				gotoxy(xpos[i], ypos);// set cursor position passing in i
				textattr(3); // reset text color
				printf("%s", menu_list[i]);//print the menu item out in new color
				i = 3;//set i to 2 to start menu from bottom
			}
			break;

			//left
		case 77:
			if (i< MaxNo_Menu - 1)
			{

				gotoxy(xpos[i], ypos);//set cursor position passing in i
				textattr(3);//set text color
				printf("%s", menu_list[i]);//print the menu item out in new color
				++i;// down key add to i
			}
			else
			{

				gotoxy(xpos[i], ypos);// set cursor position passing in i
				textattr(3); // reset text color
				printf("%s", menu_list[i]);//print the menu item out in new color
				i = 0;//set i to 0 to restart menu
			}
			break;

			//enter
		case 13:
			if (i == 0) { return 0; } /*system("cls"); hand.push_back(deck[3]); choosecard(deck,hand);*/
			if (i == 1) { return 10; }
			if (i == 2) { return 50; }
			if (i == 3) { return 100; }
			if (i == 4)  { return 200; }
			break;
		}
	}
}

void Aesthetics::Credits()
{
	system("cls");
	textattr(8); cout << "		 _________ "; textattr(12); cout << "  _________   "; textattr(8); cout << "_________   "; textattr(12); cout << "__________" << endl;
	textattr(8); cout << "	        /         \\"; textattr(12); cout << " /         \\ "; textattr(8); cout << "/         \\ "; textattr(12); cout << "/          \\" << endl;
	textattr(8); cout << "                 Jordan Max "; textattr(12); cout << " A          "; textattr(8); cout << " K          "; textattr(12); cout << "Neil Inglese" << endl;
	textattr(8); cout << "                     ,      "; textattr(12); cout << "    _ _     "; textattr(8); cout << "     _      "; textattr(12); cout << "            " << endl;
	textattr(8); cout << "                    / \\     "; textattr(12); cout << "   / ^ \\   "; textattr(8); cout << "     (_)    "; textattr(12); cout << "      /\\     " << endl;
	textattr(8); cout << "                   (_ _)    "; textattr(12); cout << "   \\   /   "; textattr(8); cout << "    (_)_)   "; textattr(12); cout << "     <  >    " << endl;
	textattr(8); cout << "                    /_\\     "; textattr(12); cout << "    \\ /    "; textattr(8); cout << "     /_\\    "; textattr(12); cout << "      \\/     " << endl;
	textattr(8); cout << "                            "; textattr(12); cout << "     `     "; textattr(8); cout << "            "; textattr(12); cout << "             " << endl;
	textattr(8); cout << "                 jdmdev.net  "; textattr(12); cout << "         A "; textattr(8); cout << "          K"; textattr(12); cout << " neildev.net " << endl;
	textattr(8); cout << "		\\_________/ "; textattr(12); cout << "\\_________/ "; textattr(8); cout << "\\_________/"; textattr(12); cout << " \\__________/" << endl; cout << "" << endl;

	MainMenu();
}

//game over function
void Aesthetics::OutOfMoney(string who)
{
	SetWindow(100, 55);
	centerWindow();
	system("cls");
	randomHeaderCards();
	gotoxy(40, 20); textattr(15); cout << who + " ran out of money" << endl;
	gotoxy(45, 21); cout << "Game Over" << endl;

	cin.get();
	system("cls");
	header(); // calling our game header
	MainMenu(); // calling our menu system
}

//random card generator for game over and start screen cards
void Aesthetics::randomHeaderCards()
{
	Hands hnds;
	DrawCard dc;

	vector<string>enddeck;
	vector<string> headercards;
	enddeck = hnds.createdeck(enddeck);
	headercards.push_back(enddeck[1]);
	headercards.push_back(enddeck[2]);
	headercards.push_back(enddeck[3]);
	headercards.push_back(enddeck[4]);


	dc.createhand(headercards, 20, 10);
}


//seting console size and centering, leave width at 55, if over 80 it throws an exception
//example call both functions, change the x to length of window we want, like i said id leave y 55
// SetWindow(100, 55);
//centerWindow();
void Aesthetics::SetWindow(int x, int y)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	if (h == INVALID_HANDLE_VALUE)
		throw std::runtime_error("Unable to get stdout handle.");

	{
		COORD largestSize = GetLargestConsoleWindowSize(h);
		if (x > largestSize.X)
			throw std::invalid_argument("The x dimension is too large.");
		if (y > largestSize.Y)
			throw std::invalid_argument("The y dimension is too large.");
	}


	CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
	if (!GetConsoleScreenBufferInfo(h, &bufferInfo))
		throw std::runtime_error("Unable to retrieve screen buffer info.");

	SMALL_RECT& winInfo = bufferInfo.srWindow;
	COORD windowSize = { winInfo.Right - winInfo.Left + 1, winInfo.Bottom - winInfo.Top + 1 };

	if (windowSize.X > x || windowSize.Y > y)
	{
		SMALL_RECT info =
		{
			0,
			0,
			x < windowSize.X ? x - 1 : windowSize.X - 1,
			y < windowSize.Y ? y - 1 : windowSize.Y - 1
		};

		if (!SetConsoleWindowInfo(h, TRUE, &info))
			throw std::runtime_error("Unable to resize window before resizing buffer.");
	}

	COORD size = { x, y };
	if (!SetConsoleScreenBufferSize(h, size))
		throw std::runtime_error("Unable to resize screen buffer.");


	SMALL_RECT info = { 0, 0, x - 1, y - 1 };
	if (!SetConsoleWindowInfo(h, TRUE, &info))
		throw std::runtime_error("Unable to resize window after resizing buffer.");


	//hiding the cursor
	HANDLE hConsoleOutput;
	CONSOLE_CURSOR_INFO structCursorInfo;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleCursorInfo(hConsoleOutput, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hConsoleOutput, &structCursorInfo);
}
int Aesthetics::centerWindow()
{
	HWND hwndScreen = GetDesktopWindow(),conwd = GetConsoleWindow();

	RECT rectScreen,rectcon;

	int ConsolePosX,ConsolePosY;

	if (!GetWindowRect(hwndScreen, &rectScreen)) return (GetLastError());
	if (!GetWindowRect(conwd, &rectcon)) return (GetLastError());

	ConsolePosX = (rectScreen.right - rectScreen.left - (rectcon.right - rectcon.left)) >> 1;
	ConsolePosY = (rectScreen.bottom - rectScreen.top - (rectcon.bottom - rectcon.top)) >> 1;
	if (!SetWindowPos(conwd, HWND_NOTOPMOST, ConsolePosX, ConsolePosY, 0, 0, SWP_NOOWNERZORDER | SWP_NOSIZE)) return (GetLastError());

	return (0);
}
