#include "EnterMenu.h"
#include "GamePlay.h"
#include "Aesthetics.h"

#define MaxNo_Menu2 3

EnterMenu::EnterMenu()
{
}

void EnterMenu::Menu()
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

EnterMenu::~EnterMenu()
{
}
