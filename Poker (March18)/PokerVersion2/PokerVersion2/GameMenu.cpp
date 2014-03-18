#include "GameMenu.h"

GamePlay gP;
#define MaxNo_Menu 5
GameMenu::GameMenu()
{
}

int GameMenu::Menu()
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
				gP.AltGame();

			}
			if (i == 4)  { gP.Fold(); return 0; }
			break;
		}
	}
}
GameMenu::~GameMenu()
{
}
