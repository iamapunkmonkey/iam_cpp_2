#ifndef GAMEPLAY_H
#define GAMEPLAY_H


extern vector<string>playerhand;
extern vector<string>cards;
extern vector<string>deck;
extern vector<string>pHand;
extern vector<string>cHand;
extern vector<string>tablehand;
extern vector<string> computerhand;
extern vector<int> pvalues;
extern vector<char> psuits;
extern vector<int> cvalues;
extern vector<char> csuits;
extern vector<int> tempValues;
extern vector<char> tempSuits;
extern bool foldCardsText;
extern bool foldv;
extern bool newMenuInit;
extern bool allin;
extern bool duringhand;
extern int pCash;
extern int cpucash;

extern int pot;
extern int currentBet;
extern int cpubet;
//extern int v;
extern int pHand_GP;
extern int cHand_GP;
//extern int z;
extern int GameProgression;
extern int AIBehavior;
extern int AIBehav_BOF;

extern string text_pHand;
extern string text_cHand;
extern string text_result;
extern string text_stupidMsg;
extern string text_fold;
extern string text_arrows;
extern string text_enter;

/*extern string inhand;
//extern string chand;
extern string result;
extern string stpidppl;
extern string fold;
extern string arrows;
extern string enter;*/


class GamePlay
{


public:
	//bool win;
	bool lose;
	bool showc;
	bool shows;
	//int loseM;

	int earn;
	int money;
	int Tmoney;
	int Omoney;
	void Start();
	void Flow();
	void Game();
	int gameMenu();
	void Text();
	void Betting(int bet);
	void Cards();
	void Clear();
	void CpuBetting(int x);
	void NewHand();
	void NGameMenu();
	void NGameMenu2();
	void thirdhand();
	void thirdhand2();
	void checkhands();
	void computerFold();
	void CpuFold(int);
	void AltText();
	void AltGame();
	GamePlay();



};

#endif