#ifndef POKER_H
#define POKER_H



class Poker
{
public:
	void createdeck(vector<string>& deck);
	void shuffle(vector<string>& deck);
	void playercard(vector<string>& deck);
	void cpucard(vector<string>&deck);
	void tablecards(vector<string>& deck, int);
	vector<string> suits(vector<string>, string);
	void createhand(vector<string> hand, int, int);
	void createtable(vector<string>, int, int);
	void draw1card(string, vector<string>, int, int, int);
	void drawcpucard(vector<string>, int, int);
	void drawcpucard2(vector<string>, int, int);
	void drawdefaultcpu(vector<string>, int, int);
	void drawcpudefault(string, vector<string>, int, int, int);
	void playertest(vector<string>, vector<string>);
	void playersuit(vector<string>);
	void playerval(vector<string>);
	void computertest(vector<string>, vector<string>);
	void computersuit(vector<string>);
	void computerval(vector<string>);


};

#endif