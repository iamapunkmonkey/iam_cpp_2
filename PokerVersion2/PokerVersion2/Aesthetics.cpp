#include "Aesthetics.h"
#include "GamePlay.h"
#include "Checks.h"
#include "Poker.h"
#include "DrawCard.h"




HANDLE con = GetStdHandle(STD_OUTPUT_HANDLE);
#define MaxNo_Menu 5
#define MaxNo_Menu1 3
#define MaxNo_Menu2 3



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
	printf("%s", "Instructions:");
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
	printf("%i", playerMoney); // displaying player cash


	gotoxy(75, 48);
	textattr(15);
	cout << playerHand; // displaying what you have in your hand

	gotoxy(75, 3);
	textattr(15);
	cout << computerHand;


	gotoxy(40, 13);
	textattr(10);
	printf("%i", computerCash); // displaying cpu cash

	textattr(8);
	gotoxy(37, 33);
	cout << didFold;
	gotoxy(45, 28);
	textattr(10);
	printf("%i", thePot); // displaying the pot total

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

void Aesthetics::text2(string words)
{
	gotoxy(30, 20);
	textattr(15);
	printf("%s", words.c_str());
}

void Aesthetics::text3(string words)

{


	//system("cls");
	gotoxy(50, 28);
	textattr(3);
	printf("%s", words.c_str());
	/*gotoxy(50, 20);
	textattr(15);
	*///printf("%i", value);


}

void Aesthetics::text4(string words, int value)

{


	system("cls");
	gotoxy(10, 19);
	textattr(15);
	printf("%s", words.c_str());
	/*gotoxy(50, 20);
	textattr(15);
	*///printf("%i", value);


}

void Aesthetics::header()
{

	vector<string> headercards;
	headercards.push_back("AH");
	headercards.push_back("AC");
	headercards.push_back("AD");
	headercards.push_back("AS");

	DrawCard dc;
	dc.createhand(headercards, 20, 10);
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
			break;

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
			break;
		}
	}

}

void Aesthetics::Credits()
{
	system("cls");
	textattr(8);cout << "		 _________ ";textattr(12);cout << "  _________   ";textattr(8);cout << "_________   ";textattr(12);cout << "__________" << endl;
	textattr(8);cout << "	        /         \\";textattr(12);cout << " /         \\ ";textattr(8);cout << "/         \\ ";textattr(12);cout << "/          \\" << endl;
	textattr(8);cout << "                 Jordan Max ";textattr(12);cout << " A          ";textattr(8);cout << " K          ";textattr(12);cout << "Neil Inglese" << endl;
	textattr(8);cout << "                     ,      ";textattr(12);cout << "    _ _     ";textattr(8);cout << "     _      ";textattr(12);cout << "            " << endl;
	textattr(8);cout << "                    / \\     ";textattr(12);cout << "   / ^ \\   ";textattr(8);cout << "     (_)    ";textattr(12);cout << "      /\\     " << endl;
	textattr(8);cout << "                   (_ _)    ";textattr(12);cout << "   \\   /   ";textattr(8);cout << "    (_)_)   ";textattr(12);cout << "     <  >    " << endl;
	textattr(8);cout << "                    /_\\     ";textattr(12);cout << "    \\ /    ";textattr(8);cout << "     /_\\    ";textattr(12);cout << "      \\/     " << endl;
	textattr(8);cout << "                            ";textattr(12);cout << "     `     ";textattr(8);cout << "            ";textattr(12);cout << "             " << endl;
	textattr(8);cout << "                 jdmdev.net  ";textattr(12);cout << "         A ";textattr(8);cout << "          K";textattr(12);cout << " neildev.net " << endl;
	textattr(8);cout << "		\\_________/ ";textattr(12);cout << "\\_________/ ";textattr(8);cout << "\\_________/";textattr(12);cout << " \\__________/" << endl;cout << "" << endl;
}

void Aesthetics::SetWindow(int Width, int Height)
{
	_COORD coord;
	coord.X = Width;
	coord.Y = Height;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height - 1;
	Rect.Right = Width - 1;

	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle
	SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size
	SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size


	HANDLE hConsoleOutput;
	CONSOLE_CURSOR_INFO structCursorInfo;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleCursorInfo(hConsoleOutput, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hConsoleOutput, &structCursorInfo);

}