#ifndef GAMEPLAY_H
#define GAMEPLAY_H


extern vector<string>deck;
extern vector<string>cards;
extern vector<string>hand;
extern vector<string>cpuhand;
extern vector<string>tablehand;


extern bool playerFold;

extern int cash;
extern int cpucash;
extern int pot;
extern int bet;
extern int cpubet;
extern int PlayerHandValue;
extern int CpuHandValue;

extern string result;

class GamePlay
{


public:

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
	GamePlay();



};

#endif