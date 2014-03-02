#include "Aesthetics.h"
#include "GamePlay.h"
#include "Checks.h"
#include "Poker.h"


// create and shuffle the deck


void Poker::createdeck(vector<string>& deck)
{
	const int suits = 5;
	const int values = 13;
	string cardValue[] = { "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K", "A" };
	string cardSuit[] = { "H", "D", "S", "C" };
	string card;
	deck.clear();

	for (int i = 0; i < suits; ++i)
	{
		for (int j = 0; j < values; ++j)
		{
			if (deck.size() < 52)
			{
				card = cardValue[j] + cardSuit[i];
				deck.push_back(card);
			}
			else
				return;
		}
	}


}
void Poker::shuffle(vector<string>& deck)
{
	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(deck.begin(), deck.end());
}
//

//pushback to hands
void Poker::playercard(vector<string>& deck)
{

	pHand.clear();

	int j = 0;

	for (j = 0; j < 2; j++)
	{
		pHand.push_back(deck[j]);
	}

	//hand.push_back("QH");
	//hand.push_back("JD");


}
void Poker::cpucard(vector<string>&deck)
{
	cHand.clear();
	int z;

	for (z = 2; z < 4; z++)
	{
		cHand.push_back(deck[z]);
	}
}
void Poker::tablecards(vector<string>& deck, int x)
{
	tablehand.clear();

	for (int j = 5; j < x; j++)
	{
		tablehand.push_back(deck[j]);
	}

	//tablehand.push_back("3S");
	//tablehand.push_back("KD");
	//tablehand.push_back("6C");
	//tablehand.push_back("TD");
	//tablehand.push_back("AC");


}
//

//set up and draw cards
vector<string> Poker::suits(vector<string> cards, string suit)
{
	cards.empty();

	vector<string> spade;
	spade.push_back("    ,    ");
	spade.push_back("   / \\   ");
	spade.push_back("  (_ _)  ");
	spade.push_back("   /_\\   ");
	spade.push_back("         ");

	vector<string> clover;
	clover.push_back("    _    ");
	clover.push_back("   (_)   ");
	clover.push_back("  (_)_)  ");
	clover.push_back("   /_\\   ");
	clover.push_back("         ");

	vector<string> diamond;
	diamond.push_back("         ");
	diamond.push_back("    /\\   ");
	diamond.push_back("   <  >  ");
	diamond.push_back("    \\/   ");
	diamond.push_back("         ");

	vector<string> heart;
	heart.push_back("   _ _   ");
	heart.push_back("  / ^ \\  ");
	heart.push_back("  \\   /  ");
	heart.push_back("   \\ /   ");
	heart.push_back("    `    ");

	vector<string> cpudefault;
	cpudefault.push_back("    __   ");
	cpudefault.push_back("   /  |  ");
	cpudefault.push_back("      |  ");
	cpudefault.push_back("     _/  ");
	cpudefault.push_back("    |    ");
	cpudefault.push_back("          ");
	cpudefault.push_back("    *    ");



	if (suit == "spade")
	{
		cards = spade;
	}
	else if (suit == "heart")
	{
		cards = heart;
	}
	else if (suit == "clover")
	{
		cards = clover;
	}
	else if (suit == "diamond")
	{
		cards = diamond;
	}
	else if (suit == "cpudefault")
	{
		cards = cpudefault;
	}

	return cards;
}
void Poker::createhand(vector<string> hand, int x, int y)
{

	//testhand(hand, cpuhand);


	int color;
	string val;



	for (string item : hand)
	{


		if (item.at(1) == *"H")
		{
			cards = suits(cards, "heart");
			color = 252;
			val = item.at(0);
		}
		else if (item.at(1) == *"S")
		{
			cards = suits(cards, "spade");
			color = 240;
			val = item.at(0);
		}
		else if (item.at(1) == *"D")
		{
			cards = suits(cards, "diamond");
			color = 252;
			val = item.at(0);
		}
		else if (item.at(1) == *"C")
		{
			cards = suits(cards, "clover");
			color = 240;
			val = item.at(0);
		}


		draw1card(val, cards, color, x, y);
		x = x + 15;


	}

}

void Poker::drawdefaultcpu(vector<string> cpuhand, int x, int y)
{
	for (string item : cpuhand)
	{
		int color;
		string val;

		//if (item.at(1) == *"H")
		//	{
		//		cards = suits(cards, "heart");
		//		color = 252;
		//		val = item.at(0);
		//	}
		//	else if (item.at(1) == *"S")
		//	{
		//		cards = suits(cards, "spade");
		//		color = 240;
		//		val = item.at(0);
		//	}
		//	else if (item.at(1) == *"D")
		//	{
		//		cards = suits(cards, "diamond");
		//		color = 252;
		//		val = item.at(0);
		//	}
		//	else if (item.at(1) == *"C")
		//	{
		//		cards = suits(cards, "clover");
		//		color = 240;
		//		val = item.at(0);
		//	}
		item.at(1) = *"CP";
		cards = suits(cards, "cpudefault");
		color = 240;
		val = item.at(0);
		drawcpudefault(val, cards, color, x, y);
		x = x + 15;
	}
}
void Poker::drawcpucard(vector<string> cpuhand, int x, int y)
{
	for (string item : cpuhand)
	{
		int color;
		string val;

		if (item.at(1) == *"H")
		{
			cards = suits(cards, "heart");
			color = 252;
			val = item.at(0);
		}
		else if (item.at(1) == *"S")
		{
			cards = suits(cards, "spade");
			color = 240;
			val = item.at(0);
		}
		else if (item.at(1) == *"D")
		{
			cards = suits(cards, "diamond");
			color = 252;
			val = item.at(0);
		}
		else if (item.at(1) == *"C")
		{
			cards = suits(cards, "clover");
			color = 240;
			val = item.at(0);
		}
		draw1card(val, cards, color, x, y);
		x = x + 15;
	}
}
//void Pokerdrawcpucard2(vector<string> cpuhand, int x, int y)
//{
//	for (string item : cpuhand)
//	{
//		int color;
//		string val;
//
//	if (item.at(1) == *"H")
//		{
//			cards = suits(cards, "heart");
//			color = 252;
//			val = item.at(0);
//		}
//		else if (item.at(1) == *"S")
//		{
//			cards = suits(cards, "spade");
//			color = 240;
//			val = item.at(0);
//		}
//		else if (item.at(1) == *"D")
//		{
//			cards = suits(cards, "diamond");
//			color = 252;
//			val = item.at(0);
//		}
//		else if (item.at(1) == *"C")
//		{
//			cards = suits(cards, "clover");
//			color = 240;
//			val = item.at(0);
//		}
//		drawcpudefault(val, cards, color, x, y);
//		x = x + 15;
//	}
//}
void Poker::createtable(vector<string> tablehand, int x, int y)
{

	//testhand(hand, cpuhand);


	int color;
	string val;



	for (string item : tablehand)
	{


		if (item.at(1) == *"H")
		{
			cards = suits(cards, "heart");
			color = 252;
			val = item.at(0);
		}
		else if (item.at(1) == *"S")
		{
			cards = suits(cards, "spade");
			color = 240;
			val = item.at(0);
		}
		else if (item.at(1) == *"D")
		{
			cards = suits(cards, "diamond");
			color = 252;
			val = item.at(0);
		}
		else if (item.at(1) == *"C")
		{
			cards = suits(cards, "clover");
			color = 240;
			val = item.at(0);
		}


		draw1card(val, cards, color, x, y);
		x = x + 15;


	}

}

void Poker::draw1card(string value, vector<string> card, int col, int x, int y)
{

	Aesthetics a;
	{ a.gotoxy(x, y);	 a.textattr(15); printf("  "); a.textattr(col); printf("         "); a.textattr(15); printf(" "); }
	{
		a.gotoxy(x, y + 1);  a.textattr(15); printf("  "); a.textattr(col); printf("%s", value.c_str()); a.textattr(240); printf("        "); a.textattr(15); printf(" ");
	}
	{a.gotoxy(x, y + 2); a.textattr(15); printf("  "); a.textattr(col); printf("%s", card[0].c_str()); a.textattr(15); printf(" "); }
	{a.gotoxy(x, y + 3); a.textattr(15); printf("  "); a.textattr(col); printf("%s", card[1].c_str()); a.textattr(15); printf(" "); }
	{a.gotoxy(x, y + 4); a.textattr(15); printf("  "); a.textattr(col); printf("%s", card[2].c_str()); a.textattr(15); printf(" "); }
	{a.gotoxy(x, y + 5); a.textattr(15); printf("  "); a.textattr(col); printf("%s", card[3].c_str()); a.textattr(15); printf(" "); }
	{a.gotoxy(x, y + 6); a.textattr(15); printf("  "); a.textattr(col); printf("%s", card[4].c_str()); a.textattr(15); printf(" "); }
	{a.gotoxy(x, y + 7); a.textattr(15); printf("  "); a.textattr(col); printf("        "); a.textattr(col); printf("%s", value.c_str()); a.textattr(15); printf(" "); }
	{a.gotoxy(x, y + 8); a.textattr(15); printf("  "); a.textattr(col); printf("         "); a.textattr(15); printf(" "); }


}
//
void Poker::drawcpudefault(string value, vector<string> card, int col, int x, int y)
{

	Aesthetics a;
	int temp = 15;
	int temp2 = 31;
	{a.gotoxy(x, y);	 a.textattr(temp); printf(" "); a.textattr(31); printf("%s", card[0].c_str()); a.textattr(temp2); printf(" "); }/*a.textattr(31); printf("         "); a.textattr(temp2); printf(" "); }*/
	{a.gotoxy(x, y + 1);  a.textattr(temp); printf(" "); a.textattr(31); printf("%s", card[1].c_str()); a.textattr(temp2); printf(" "); }/*a.textattr(temp2); printf(" "); a.textattr(temp2); printf("%s", "?"); a.textattr(31); printf("        "); a.textattr(temp2); printf("");}*/
	{a.gotoxy(x, y + 2); a.textattr(temp); printf(" "); a.textattr(31); printf("%s", card[2].c_str()); a.textattr(temp2); printf(" "); }
	{a.gotoxy(x, y + 3); a.textattr(temp); printf(" "); a.textattr(31); printf("%s", card[3].c_str()); a.textattr(temp2); printf(" "); }
	{a.gotoxy(x, y + 4); a.textattr(temp); printf(" "); a.textattr(31); printf("%s", card[4].c_str()); a.textattr(temp2); printf(" "); }
	{a.gotoxy(x, y + 5); a.textattr(temp); printf(" "); a.textattr(31); printf("%s", card[5].c_str()); a.textattr(temp2); printf(""); }
	{a.gotoxy(x, y + 6); a.textattr(temp); printf(" "); a.textattr(31); printf("%s", card[6].c_str()); a.textattr(temp2); printf(" "); }
	{a.gotoxy(x, y + 7); a.textattr(temp); printf(" "); a.textattr(temp2); printf(" "); a.textattr(temp2); printf("        "); a.textattr(31); printf("%s", " "); a.textattr(temp2); printf(""); }
	{a.gotoxy(x, y + 8); a.textattr(temp); printf(" "); a.textattr(31); printf("        "); a.textattr(31); printf("  "); }


}

//

//breaking up cards
void Poker::playertest(vector<string> tablehand, vector<string> hand)
{

	playerhand.clear();

	for (string item : tablehand)
	{
		playerhand.push_back(item);
	}
	for (string item : hand)
	{
		playerhand.push_back(item);
	}



}
void Poker::playersuit(vector<string>playerhand)
{
	psuits.clear();
	for (string item : playerhand)
	{
		psuits.push_back(item.at(1));
	}
}
void Poker::playerval(vector<string>playerhand)
{
	int n;
	//playerval().clear();
	pvalues.clear();

	for (string item : playerhand)
	{
		if (item.at(0) == *"2")
		{
			n = 2;
		}
		if (item.at(0) == *"3")
		{
			n = 3;
		}
		if (item.at(0) == *"4")
		{
			n = 4;
		}
		if (item.at(0) == *"5")
		{
			n = 5;
		}
		if (item.at(0) == *"6")
		{
			n = 6;
		}
		if (item.at(0) == *"7")
		{
			n = 7;
		}
		if (item.at(0) == *"8")
		{
			n = 8;
		}

		if (item.at(0) == *"9")
		{
			n = 9;
		}

		if (item.at(0) == *"T")
		{
			n = 10;
		}
		if (item.at(0) == *"J")
		{
			n = 11;
		}
		if (item.at(0) == *"Q")
		{
			n = 12;
		}
		if (item.at(0) == *"K")
		{
			n = 13;
		}
		if (item.at(0) == *"A")
		{
			n = 14;
		}
		pvalues.push_back(n);
	}
}


void Poker::computertest(vector<string> tablehand, vector<string> cpuhand)
{

	computerhand.clear();

	for (string item : tablehand)
	{
		computerhand.push_back(item);
	}
	for (string item : cpuhand)
	{
		computerhand.push_back(item);
	}



}
void Poker::computersuit(vector<string>computerhand)
{
	csuits.clear();
	for (string item : computerhand)
	{
		csuits.push_back(item.at(1));
	}
}
void Poker::computerval(vector<string>computerhand)
{
	int n;
	//playerval().clear();
	cvalues.clear();

	for (string item : computerhand)
	{
		if (item.at(0) == *"2")
		{
			n = 2;
		}
		if (item.at(0) == *"3")
		{
			n = 3;
		}
		if (item.at(0) == *"4")
		{
			n = 4;
		}
		if (item.at(0) == *"5")
		{
			n = 5;
		}
		if (item.at(0) == *"6")
		{
			n = 6;
		}
		if (item.at(0) == *"7")
		{
			n = 7;
		}
		if (item.at(0) == *"8")
		{
			n = 8;
		}

		if (item.at(0) == *"9")
		{
			n = 9;
		}

		if (item.at(0) == *"T")
		{
			n = 10;
		}
		if (item.at(0) == *"J")
		{
			n = 11;
		}
		if (item.at(0) == *"Q")
		{
			n = 12;
		}
		if (item.at(0) == *"K")
		{
			n = 13;
		}
		if (item.at(0) == *"A")
		{
			n = 14;
		}
		cvalues.push_back(n);
	}
}
//
