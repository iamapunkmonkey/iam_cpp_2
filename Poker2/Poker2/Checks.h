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
	int determinehand(vector<int >pvalues, vector<char>psuits);
	int determinecpuhand(vector<int> cvalues, vector<char>csuits);
	//void determine(int v, int z);
	void awardWinner(int, int);
	void FoldValue();
	void FoldValueC();
	int FindHighCard(int, int);
	Checks();
};

#endif