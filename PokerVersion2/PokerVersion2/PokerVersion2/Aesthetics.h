#ifndef AESTETICS_H
#define AESTETICS_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <conio.h>
#include <windows.h>
#include <algorithm> 
#include <stdio.h>
#include <vector>
#include <ctime>
#include <winuser.h>
#include <windef.h>
#include <stdexcept>
#include <Windows.h>


using namespace std;
using std::string;


#define MaxNo_Menu 5
#define MaxNo_Menu1 3
#define MaxNo_Menu2 3
#define RaiseMenu 2
//if  player checks, and cpu bets needs menu for call/fold for player
#define CPUBet 2


class Aesthetics
{
public:
	void gotoxy(int, int);
	void textattr(int);
	void mainText();
	void changingText(int, string, string,int,string,int,string);
	void text1(string);
    void SetWindow(int, int);
	void Start();
	void setBoolToAlertPlayer();
	//void newMenuForCheckMenu(int, int, char[]);
	
	void header();
	void MainMenu();
	int raiseMenu(int valueOfCPUBet);
	void Credits();
	void OutOfMoney(string);
	void randomHeaderCards();
	int gameplayMenu();
	void ShowLastSystemError();
	int centerWindow();

	bool test;
	bool debugBOOL;
	string Instructions;
};


#endif