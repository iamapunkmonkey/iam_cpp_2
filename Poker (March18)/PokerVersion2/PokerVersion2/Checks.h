#ifndef CHECKS_H
#define CHECKS_H


class Checks
{
public:
	int ispair(vector<int> dvalues);
	int flush(vector<char> dsuits);
	int straight(vector<int> dvalues);
	int threeofakind(vector<int> dvalues);
	int fourofakind(vector<int> dvalues);
	int fullhouse(vector<int> dvalues);
	int FindHighCard();
	int DetermineHand(vector<int >values, vector<char>suits);
	//int determinecpuhand(vector<int> cvalues, vector<char>csuits);
	void determine(int PlayerHandValue, int CpuHandValue);
	void FoldValue();
	void FoldValueC();
	Checks();
};

#endif