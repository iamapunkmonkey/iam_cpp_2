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
using namespace std;
using std::string;

class Aesthetics
{
public:
	void gotoxy(int, int);
	void textattr(int);
	void mainText();
	void changingText(int, string, string,int,string,int,string);
	void text1(string);
	void text2(string);
	void text3(string);
	void text4(string, int);
    void SetWindow(int, int);
	
	void header();
	void MainMenu();
	void Credits();


	//

};


#endif