#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#define MaxNo_Menu 5
#define MaxNo_Menu1 3
#define MaxNo_Menu2 3

class GamePlay
{
public:
	vector<string>playerhand;
	vector<string>cards;
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
	bool NewGameMenu;
	bool allin;
	bool duringhand;
	bool playerCheck;
	int cash;
	int cpucash;

	int pot;
	int bet;
	int cpubet;
	int PlayerHandValue;
	int CpuHandValue;
	int g;
	int random;

	string inhand;
	string computerHandText;
	string result;
	string PressEnterToContinue;
	string fold;
	string arrows;
	string enter;


	bool win;
	bool lose;
	bool showComputer;
	bool shows;
	int loseM;

	int earn;
	int money;
	int Tmoney;
	int Omoney;
	void Start();
	void Flow();
	void Game();
	int menu();
	void Text();
	void Betting(int bet);
	void Cards();
	void Clear();
	void CpuBetting(int x);
	void NewHand();
	void NGameMenu();
	void NGameMenu2();
	void finalCards();
	void thirdhand2();
	void checkhands();
	void Fold();
	void CpuFold(int);
	void AltText();
	void allNGame();



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
	GamePlay();



};

#endif