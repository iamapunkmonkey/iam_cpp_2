#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#define MaxNo_Menu 5
#define MaxNo_Menu1 3
#define MaxNo_Menu2 3

class GamePlay
{
public:
	vector<string>playerhand;
	vector<string>deck;
	vector<string>hand;
	vector<string>cpuhand;
	vector<string>tablehand;
	vector<string> computerhand;
	vector<int> PlayerValues;
	vector<char> psuits;
	vector<int> cvalues;
	vector<char> csuits;
	bool foldc;
	bool playerFold;
	bool allin;
	bool playerCheck;
	int cash;
	int cpucash;

	int pot;
	int bet;
	int cpubet;
	int PlayerHandValue;
	int CpuHandValue;

	int random;
	int newrandom;
	int a;
	int b;
	int c;
	int transferCpuBetToAesthetics(int);
	vector<int> betVector;

	string inhand;
	string computerHandText;
	string result;
	string PressEnterToContinue;
	string fold;

	bool showComputer;
	bool shows;

	void Start();
	int menu();
	void Betting(int bet);
	void Cards();
	void CpuBetting(int x);
	void finalCards();
	void Fold();
	void CpuFold(int);
	void Clear();
	void Flop();
	void Turn();
	void River();
	void newHand();
	void Bet();
	void Setup();
	void uiText();
	void betSystem();
	void Clears();
	void getValues();
	void makeHands();
	void determine();
	void gameoverCheck();
	void raiseMenu(int);
	GamePlay();
};

#endif