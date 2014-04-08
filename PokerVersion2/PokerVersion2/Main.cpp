#include "Aesthetics.h"


//Entry Point

int main()
{
	Aesthetics aesthetics; // creating instance of Aesthetics

	aesthetics.SetWindow(100, 55); // Set windows size

	aesthetics.header(); // calling our game header
	aesthetics.MainMenu(); // calling our menu system
}