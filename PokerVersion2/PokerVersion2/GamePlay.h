#ifndef GAMEPLAY_H
#define GAMEPLAY_H


extern vector<string>playerhand;
extern vector<string>cards;
extern vector<string>deck;
extern vector<string>hand;
extern vector<string>cpuhand;
extern vector<string>tablehand;
extern vector<string> computerhand;
extern vector<int> PlayerValues;
extern vector<char> psuits;
extern vector<int> cvalues;
extern vector<char> csuits;
extern vector<int> dvalues;
extern vector<char> dsuits;
extern bool foldc;
extern bool foldv;
extern bool NewGameMenu;
extern bool allin;
extern bool duringhand;
extern int cash;
extern int cpucash;

extern int pot;
extern int bet;
extern int cpubet;
extern int PlayerHandValue;
extern int CpuHandValue;
extern int g;
extern int random;

extern string inhand;
extern string chand;
extern string result;
extern string PressEnterToContinue;
extern string fold;
extern string arrows;
extern string enter;



class GamePlay
{


public:
	bool win;
	bool lose;
	bool showc;
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
	void thirdhand();
	void thirdhand2();
	void checkhands();
	void Fold();
	void CpuFold(int);
	void AltText();
	void AltGame();
	GamePlay();



};

#endif